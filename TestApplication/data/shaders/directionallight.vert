#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectionViewMatrix;

out vec3 worldPosOut;
out vec3 normalOut;

void main()
{
    normalOut = normalize((projectionViewMatrix * worldMatrix * vec4(normal, 1.0)).xyz);
    vec4 worldPos = vec4(position, 1.0);    
    worldPosOut = worldPos.xyz;
    gl_Position = projectionViewMatrix * worldMatrix * worldPos;
}