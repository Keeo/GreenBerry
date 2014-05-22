#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 squareVertices;
layout(location = 1) in vec4 xyzs; // Position of the center of the particule and size of the square
layout(location = 2) in vec4 color; // Position of the center of the particule and size of the square

// Output data ; will be interpolated for each fragment.
//out vec2 UV;
out vec4 particlecolor;
out vec3 particlePosition;

// Values that stay constant for the whole mesh.
layout(location = 3) uniform vec3 CameraRight_worldspace;
layout(location = 4) uniform vec3 CameraUp_worldspace;
layout(location = 5) uniform mat4 VP; // Model-View-Projection matrix, but without the Model (the position is in BillboardPos; the orientation depends on the camera)

void main()
{
	float particleSize = xyzs.w; // because we encoded it this way.
	vec3 particleCenter_wordspace = xyzs.xyz;
	
	vec3 vertexPosition_worldspace = 
		particleCenter_wordspace
		+ CameraRight_worldspace * squareVertices.x * particleSize
		+ CameraUp_worldspace * squareVertices.y * particleSize;

	// Output position of the vertex
        gl_Position = VP * vec4(vertexPosition_worldspace, 1.0f);
        particlePosition = vec3(vertexPosition_worldspace);

	// UV of the vertex. No special space for this one.
	//UV = squareVertices.xy + vec2(0.5, 0.5);
	particlecolor = color;
}

