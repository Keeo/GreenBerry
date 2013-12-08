#version 330 core
#extension GL_ARB_explicit_attrib_location : require
#extension GL_ARB_explicit_uniform_location : require

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;

layout(location = 2) uniform mat4 model;
layout(location = 3) uniform mat4 view;
layout(location = 4) uniform mat4 projection;

out vec3 fragmentColor;

void main()
{
    gl_Position = projection * view * model * vec4(vertexPosition_modelspace,1);
    //gl_Position =  vec4(vertexPosition_modelspace, 1);
    fragmentColor = vertexColor;
}

