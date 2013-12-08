#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

in vec3 fragmentColor;

out vec3 color;

void main()
{
	color = vec3(1, 0, 0);
}