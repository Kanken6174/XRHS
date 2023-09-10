#version 300 es
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec3 aNormal;

out vec3 Position;  
out vec2 TexCoords;
out vec3 Normal;
out mat4 modelT;
out mat4 viewT;
out mat4 projectionT;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    Position = vec3(model * vec4(aPos, 1.0));
    TexCoords = aTex;
    Normal = mat3(transpose(inverse(model))) * aNormal; 
    modelT = model;
    viewT = view;
    projectionT = projection;
}