#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 projectionViewMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

out vec3 PositionOut;
out vec3 NormalOut;

void main()
{
   NormalOut = normalize(normalMatrix * normal);
   PositionOut = (modelViewMatrix * vec4(position, 1.0)).xyz;
   gl_Position = projectionViewMatrix * vec4(position, 1.0);
}