#version 300 es
precision mediump float;

out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{    
    vec4 sampled = texture(texture_diffuse1, TexCoords);
    FragColor = vec4(sampled.rgb, 1.0);
}