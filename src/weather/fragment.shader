#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

// Interpolated values from the vertex shaders
//in vec2 UV;
in vec4 particlecolor;
layout(location = 7) uniform vec3 ambientLight;

// Ouput data
out vec4 color;

//uniform sampler2D myTextureSampler;

void main(){
    // Output color = color of the texture at the specified UV
    //color = texture2D( myTextureSampler, UV ) * particlecolor;
    color = particlecolor * vec4(ambientLight, 1);
}