#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectionViewMatrix;

out vec2 texCoordOut;

void main()
{
    gl_Position = projectionViewMatrix * worldMatrix * vec4(position, 1.0);
    texCoordOut = texCoord;
}