#version 300 es
precision mediump float;

uniform sampler2D videoTexture;

in vec2 TexCoord;
out vec4 FragColor;

void main()
{
    FragColor = texture(videoTexture, TexCoord);
}