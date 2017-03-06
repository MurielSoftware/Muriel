#version 330

in vec3 worldPosOut;
in vec3 normalOut;

out vec4 outputColor;

struct BaseLight
{
    vec3 color;
    float intensity;
};

struct DirectionalLight
{
    BaseLight base;
    vec3 direction;
};

uniform DirectionalLight directionalLight;
uniform vec3 cameraPosition;

vec4 CalcDirectionalLight(BaseLight base, vec3 direction)
{
  float specularPower = 50.0;
  float specularIntensity = 0.5;
  float diffuseFactor = dot(normalOut, -direction);
  vec4 diffuseColor = vec4(0,0,0,0);
  vec4 specularColor = vec4(0,0,0,0);
  vec4 ambientColor = vec4(0.05, 0.05, 0.05, 1.0);
   
  if(diffuseFactor > 0.0)
  {
    diffuseColor = vec4(base.color, 1.0) * base.intensity * diffuseFactor;
    vec3 directionToEye = normalize(cameraPosition - worldPosOut);
    vec3 halfDirection = normalize(directionToEye - direction);
    float specularFactor = dot(halfDirection, normalOut);
    specularFactor = pow(specularFactor, specularPower);
    if(specularFactor > 0.0)
    {
      specularColor = vec4(base.color, 1.0) * specularIntensity * specularFactor;
    }
  }
  
  return ambientColor + diffuseColor + specularColor; 
}

void main()
{
  outputColor = CalcDirectionalLight(directionalLight.base, -directionalLight.direction);
}