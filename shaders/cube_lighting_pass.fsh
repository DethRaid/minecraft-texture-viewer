#version 450

layout(binding = 0)  uniform sampler2D main;
layout(binding = 1)  uniform sampler2D enviorment;
layout(binding = 2)  uniform sampler2D depthtex;
layout(binding = 3)  uniform sampler2D albedo;
layout(binding = 4)  uniform sampler2D opacity;
layout(binding = 5)  uniform sampler2D normal;
layout(binding = 6)  uniform sampler2D height;
layout(binding = 7)  uniform sampler2D emission;
layout(binding = 8)  uniform sampler2D transmission;
layout(binding = 9)  uniform sampler2D smoothness;
layout(binding = 10) uniform sampler2D porosity;
layout(binding = 11) uniform sampler2D f0;
layout(binding = 12) uniform sampler2D AO;

in vec2 texcoord;
in vec3 normal;

layout(location = 0) out vec4 diffuseColor;
layout(location = 1) out vec4 diffuse;
layout(location = 2) out vec4 specular;
layout(location = 3) out vec3 normal;

struct matData {
    vec3 albedo;
    float opacity;
    vec3 normal;
    float height;
    float emission;
    float transmission;
    float smoothness;
    float porosity;
    float f0;
    float AO;
} mat;

matData fillMatData() {
    matData mat;

    mat.albedo       = texture(albedoSample, texcoord).rgb;
    mat.opacity      = texture(opacitySample, texcoord).r;
    mat.normal       = texture(normalSample, texcoord).xyz;
    mat.height       = texture(heightSample, texcoord).r;
    mat.emission     = texture(emissionSample, texcoord).r;
    mat.transmission = texture(transmissionSample, texcoord).r;
    mat.smoothness   = texture(smoothnessSample, texcoord).r;
    mat.porosity     = texture(porositySample, texcoord).r;
    mat.f0           = texture(f0Sample, texcoord).r;
    mat.AO           = texture(AOSample, texcoord).r;

    return mat;
}

void main() {
}