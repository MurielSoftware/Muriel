#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectionViewMatrix;
uniform mat3 normalMatrix;
uniform mat4 modelViewMatrix;

out vec3 worldPosOut;
out vec3 normalOut;

void main()
{
    mat3 nm = mat3(modelViewMatrix);
    nm = transpose(inverse(nm));
    //mat3 nm = mat3(transpose(inverse(modelViewMatrix)));	
    normalOut = normalize(normalMatrix * normal);
    worldPosOut = (modelViewMatrix * vec4(position, 1.0)).xyz;
    gl_Position = projectionViewMatrix * worldMatrix * vec4(position, 1.0);
}