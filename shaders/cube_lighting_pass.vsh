#version 450

layout(location = 0, std140) uniform MVP {
    mat4 gbufferProjection;
    mat4 gbufferModelView;
}