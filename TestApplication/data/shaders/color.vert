#version 330

layout (location = 0) in vec3 position;

uniform mat4 worldMatrix;
uniform mat4 projectionViewMatrix;

void main()
{
    gl_Position = projectionViewMatrix * worldMatrix * vec4(position, 1.0);
}