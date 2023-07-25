#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec3 aNormal;

out vec3 Position;  
out vec2 TexCoords;
out vec3 Normal;

uniform mat4 model = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 projection = mat4(1.0);

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    Position = vec3(model * vec4(aPos, 1.0));
    TexCoords = aTex;
    Normal = mat3(transpose(inverse(model))) * aNormal; 
}