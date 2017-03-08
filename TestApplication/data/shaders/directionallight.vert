#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

uniform mat4 projectionViewMatrix;
uniform mat4 modelViewMatrix;
uniform vec3 cameraPosition;

out vec3 PositionOut;
out vec3 NormalOut;
out vec3 CameraOut;

void main()
{
   mat3 nm = transpose(inverse(mat3(modelViewMatrix)));
   NormalOut = nm * normal;
   //NormalOut = normalize(modelViewMatrix * vec4(normal, 0.0)).xyz;
   CameraOut = (modelViewMatrix * vec4(cameraPosition, 1.0)).xyz;
   PositionOut = (modelViewMatrix * vec4(position, 1.0)).xyz;
   gl_Position = projectionViewMatrix * vec4(position, 1.0);
}