#version 300 es
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 pos;
out mat4 modelT;
out mat4 viewT;
out mat4 projectionT;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
    pos = vec3(model * vec4(aPos, 1.0));
    modelT = model;
    viewT = view;
    projectionT = projection;
}