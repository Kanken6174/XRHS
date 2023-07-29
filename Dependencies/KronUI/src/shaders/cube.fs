#version 330 core
in vec3 Position;  
in vec2 TexCoords;
in vec3 Normal;    

out vec4 FragColor;

struct Material {
    sampler2D texture_diffuse1; 
    sampler2D texture_bump1;  
};

struct Light {
    vec3 position;
    vec3 color;
};

uniform Material material;
uniform Light lights[8];
uniform int numLights = 0;

uniform int useDefault = 1;
uniform int useColor = 0;
uniform int useTexture = 0;
uniform int useBump = 0;
uniform int usePhong = 1;

uniform vec3 viewPos = vec3(0.0, 0.0, 0.0);

vec3 calculateAmbient(vec3 color) {
    return 0.1 * color;
}

vec3 calculateDiffuse(vec3 lightDir, vec3 normal, vec3 color) {
    float diff = max(dot(normal, lightDir), 0.0);
    return diff * color;
}

vec3 calculateSpecular(vec3 lightDir, vec3 viewDir, vec3 normal) {
    float specularStrength = 0.5;
    float shininess = 32.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), shininess);
    return specularStrength * spec * vec3(1.0);
}

void main()
{
    if (useDefault == 1) {
        FragColor = vec4(abs(Position), 1.0);
    }
    else {
        vec3 color = vec3(0.1);
        if (useColor == 1) {
            color = abs(Position);
        }
        if (useTexture == 1) {
            color = vec3(0.2);
            color += texture(material.texture_diffuse1, TexCoords).rgb;
        }
        if (useBump == 1) {
            vec3 texNormal = normalize(texture(material.texture_bump1, TexCoords).rgb * 2.0 - 1.0);
            vec3 lightDir = normalize(lights[0].position - Position);
            float diff = max(dot(texNormal, lightDir), 0.0);
            vec3 diffuse = diff * color;
            color = diffuse;
        }
        if (usePhong == 1) {
            for(int i = 0; i < numLights; i++) {
                vec3 lightDir = normalize(lights[i].position - Position);
                vec3 viewDir = normalize(viewPos - Position);
                vec3 normal = normalize(Normal);
/*
        if (any(isnan(lightDir))) {
            FragColor = vec4(1.0, 0.0, 0.0, 1.0);  // Red for lightDir
            return;
        }
        if (any(isnan(viewDir))) {
            FragColor = vec4(0.0, 1.0, 0.0, 1.0);  // Green for viewDir
            return;
        }
        if (any(isnan(normal))) {
            FragColor = vec4(0.0, 0.0, 1.0, 1.0);  // Blue for normal
            return;
        }
*/

                vec3 ambient = calculateAmbient(color);
                vec3 diffuse = calculateDiffuse(lightDir, normal, color);
                vec3 specular = calculateSpecular(lightDir, viewDir, normal);
                vec3 finalColor = ambient + diffuse + specular;

                color += lights[i].color * finalColor;
            }
        }
        FragColor = vec4(color, 1.0);
    }
}