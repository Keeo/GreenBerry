#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

uniform sampler2D sampler;

in vec2 uv;

out vec3 color;

void main()
{
    color =  texture(sampler, uv).rgb;// + vec3(uv.x, uv.y, 0.3);
}