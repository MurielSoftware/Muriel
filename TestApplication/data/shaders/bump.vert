#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 worldMatrix;
uniform mat4 projectionViewMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec3 lightPosition;

out vec2 varyingTexCoord;
out vec3 varyingNormal;
out vec3 varyingLightDir;

vec3 GetLightDir()
{
    vec4 tempPosition4 = modelViewMatrix * vec4(position, 1.0);
    vec3 tempPosition3 = tempPosition4.xyz / tempPosition4.w;
    return normalize(lightPosition - tempPosition3);
}

void main()
{
    varyingNormal = normalMatrix * normal;
    varyingTexCoord = texCoord;
    varyingLightDir = GetLightDir();
    gl_Position = projectionViewMatrix * worldMatrix * vec4(position, 1.0);  
}

