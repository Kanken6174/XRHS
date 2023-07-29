#version 300 es
precision mediump float;

out vec4 FragColor;

in vec2 TexCoord;
in vec3 pos;

uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1, TexCoord);
}