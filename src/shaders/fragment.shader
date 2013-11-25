#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

//layout (location = 10) uniform vec3 incol;
// Ouput data
out vec3 color;

void main()
{

	// Output color = red 
	color = vec3(0,1,0);

}