#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectionViewMatrix;

out vec2 texCoordOut;
out vec4 worldPosOut;
out vec3 normalOut;

void main()
{
    vec4 worldPos = worldMatrix * vec4(position, 1.0);
    texCoordOut = texCoord;
    normalOut = normal;
    worldPosOut = worldPos;
    gl_Position = projectionViewMatrix * worldPos;
}