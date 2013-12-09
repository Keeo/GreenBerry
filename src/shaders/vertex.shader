#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec2 vertex_uv;

layout(location = 2) uniform mat4 model;
layout(location = 3) uniform mat4 view;
layout(location = 4) uniform mat4 projection;

out vec2 uv;

void main()
{
    gl_Position = projection * view * model * vec4(vertex_position, 1);
    uv = vertex_uv;
}

