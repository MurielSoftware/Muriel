#version 330

in vec3 PositionOut;
in vec3 NormalOut;
in vec3 CameraOut;

out vec4 outputColor;

vec4 CalcDirectionalLight(vec3 color, float intensity, vec3 direction)
{
  float specularPower = 50.0;
  float specularIntensity = 0.5;
  float diffuseFactor = dot(NormalOut, -direction);
  vec4 diffuseColor = vec4(0, 0, 0, 0);
  vec4 specularColor = vec4(0, 0, 0, 0);
  vec4 ambientColor = vec4(0.1, 0.1, 0.1, 1.0);
  if(diffuseFactor > 0.0)
  {
    diffuseColor = vec4(color, 1.0) * intensity * diffuseFactor;
    vec3 directionToEye = normalize(CameraOut - PositionOut);
    vec3 halfDirection = normalize(directionToEye - direction);
    float specularFactor = dot(halfDirection, NormalOut);
    specularFactor = pow(specularFactor, specularPower);
    if(specularFactor > 0.0)
    {
      specularColor = vec4(color, 1.0) * specularIntensity * specularFactor;
    }
  }
  
  return ambientColor + specularColor + diffuseColor; 
}

void main( void )
{
  outputColor = CalcDirectionalLight(vec3(1.0, 1.0, 1.0), 0.7, -vec3(1.0, 0.0, 0.0));       
}