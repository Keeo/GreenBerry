#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

// Interpolated values from the vertex shaders
//in vec2 UV;
in vec4 particlecolor;
layout(location = 7) uniform vec3 ambientLight;

in vec3 particlePosition;

// Ouput data
out vec4 color;

//uniform sampler2D myTextureSampler;

layout(location = 8) uniform vec3 cameraPosition;

void main(){
    // Output color = color of the texture at the specified UV
    //color = texture2D( myTextureSampler, UV ) * particlecolor;
    color = particlecolor * vec4(ambientLight, 1);


    /// calculate fog vactor
    float distance = length(cameraPosition - particlePosition);
    float fog = exp2( -0.02 * 0.02 * distance * distance * 1.442695 );
    fog = clamp(fog, 0.1, 1.0);
    
    color = vec4( mix(vec3(0.1,0.1,0.1), vec3(color), fog), color.w);
}