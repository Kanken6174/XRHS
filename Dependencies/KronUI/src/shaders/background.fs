#version 330 core

uniform sampler2D videoTexture;

in vec2 TexCoord;
out vec4 FragColor;

void main()
{
    FragColor = texture(videoTexture, TexCoord);
}