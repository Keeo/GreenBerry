/* 
 * File:   Model.cpp
 * Author: Keo
 * 
 * Created on 13. duben 2014, 17:28
 */

#include "Model.h"

Model::Model(std::string file)
{
    Assimp::Importer importer;
    importer.SetPropertyInteger(AI_CONFIG_PP_PTV_NORMALIZE, 1);
    scene_ = importer.ReadFile(file, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_TransformUVCoords );

    m_nVertices = scene_->mMeshes[0]->mNumVertices;


    float* data = new float[scene_->mMeshes[0]->mNumVertices * 8];
    memcpy(data, scene_->mMeshes[0]->mVertices, scene_->mMeshes[0]->mNumVertices * sizeof(float) * 3);
    memcpy(data + scene_->mMeshes[0]->mNumVertices * 3, scene_->mMeshes[0]->mNormals, scene_->mMeshes[0]->mNumVertices * sizeof(float) * 3);

    for (int i = 0; i<scene_->mMeshes[0]->mNumVertices*2;i+=2)
    {
        (data + scene_->mMeshes[0]->mNumVertices * 6)[i] = scene_->mMeshes[0]->mTextureCoords[0][i/2].x;
        (data + scene_->mMeshes[0]->mNumVertices * 6)[i+1] = scene_->mMeshes[0]->mTextureCoords[0][i/2].y;
    }

    glGenBuffers(1,&m_vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, scene_->mMeshes[0]->mNumVertices * sizeof(float) * 8, data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    //CHECK_GL_ERROR();

    glGenVertexArrays(1,&m_vertexArrayObject);
    glBindVertexArray( m_vertexArrayObject );
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
    //CHECK_GL_ERROR();
    
    glEnableVertexAttribArray(0); //position
    glEnableVertexAttribArray(5); // normals
    glEnableVertexAttribArray(1); // uv
    //CHECK_GL_ERROR();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 0, (void*)(3 * sizeof(float) * m_nVertices));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(6 * sizeof(float) * m_nVertices));
    
    glBindVertexArray(0);
    
    delete[](data);
    
    translate_ = glm::translate(translate_, glm::vec3(0, 1, 0));
    //CHECK_GL_ERROR();
}

Model::Model(const Model& orig)
{
}

Model::~Model()
{
}

void Model::draw(const glm::mat4& transform)
{
    glBindVertexArray(m_vertexArrayObject);
    glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(transform));
    glDrawArrays(GL_TRIANGLES, 0, m_nVertices);
    glBindVertexArray( 0 );
}

