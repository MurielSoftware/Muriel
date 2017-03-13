#version 330

uniform vec4 ambientColor;
uniform vec4 diffuseColor;
uniform vec4 specularColor;

in vec2 varyingTexCoord;
in vec3 varyingNormal;
in vec3 varyingLightDir;

uniform sampler2D diffuseTexture;
uniform sampler2D normalTexture;

out vec4 outputColor;

void main()
{
    const float maxVariance = 2.0;
    const float minVariance = maxVariance / 2.0f;
    vec3 normalAdjusted = normalize(varyingNormal + normalize(texture2D(normalTexture, varyingTexCoord).rgb * maxVariance - minVariance));
    float diffuseIntensity = max(0.0, dot(normalAdjusted, varyingLightDir));
    vec3 color = (diffuseIntensity * diffuseColor.rgb) * texture2D(diffuseTexture, varyingTexCoord).rgb + ambientColor.rgb;
    outputColor = vec4(color, 1.0);
    vec3 reflection = normalize(reflect(-normalAdjusted, varyingLightDir));
    float specularIntensity = max(0.0, dot(normalAdjusted, reflection));
    if(diffuseIntensity > 0.98)
    {
        float spec = pow(specularIntensity, 64.0);
        outputColor.rgb += spec * specularColor.rgb;
    }
}