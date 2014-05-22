/* 
 * File:   Model.cpp
 * Author: Keo
 * 
 * Created on 13. duben 2014, 17:28
 */

#include "Model.h"

Model::Model(std::string file, int nFrames, float animLength, int nFrameFileStep) : animLength_(animLength), nFrames_(nFrames)
{
    std::cout<<"Generating "<< nFrames <<" frame steps"<<std::endl;
    drawStruct_ = new DrawStruct[nFrames];
    
    for (int i = 0; i < nFrames; ++i) {
        DrawStruct& drawStruct = drawStruct_[i];
        std::string filename = boost::str(boost::format(file) % (i * nFrameFileStep));
        std::cout<<filename<<std::endl;
        Assimp::Importer importer;
        importer.SetPropertyInteger(AI_CONFIG_PP_PTV_NORMALIZE, 1);
        scene_ = importer.ReadFile(filename, aiProcess_GenSmoothNormals | aiProcess_TransformUVCoords );

        drawStruct.m_nVertices = scene_->mMeshes[0]->mNumVertices;

        float* data = new float[scene_->mMeshes[0]->mNumVertices * 8];
        memcpy(data, scene_->mMeshes[0]->mVertices, scene_->mMeshes[0]->mNumVertices * sizeof(float) * 3);
        memcpy(data + scene_->mMeshes[0]->mNumVertices * 3, scene_->mMeshes[0]->mNormals, scene_->mMeshes[0]->mNumVertices * sizeof(float) * 3);

        for (int i = 0; i<scene_->mMeshes[0]->mNumVertices*2; i+=2)
        {
            (data + scene_->mMeshes[0]->mNumVertices * 6)[i] = scene_->mMeshes[0]->mTextureCoords[0][i/2].x;
            (data + scene_->mMeshes[0]->mNumVertices * 6)[i+1] = scene_->mMeshes[0]->mTextureCoords[0][i/2].y;
        }

        glGenBuffers(1, &drawStruct.m_vertexBufferObject);
        glBindBuffer(GL_ARRAY_BUFFER, drawStruct.m_vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, scene_->mMeshes[0]->mNumVertices * sizeof(float) * 8, data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenVertexArrays(1, &drawStruct.m_vertexArrayObject);
        glBindVertexArray(drawStruct.m_vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER, drawStruct.m_vertexBufferObject);

        glEnableVertexAttribArray(0); // position
        glEnableVertexAttribArray(5); // normals
        glEnableVertexAttribArray(1); // uv

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 0, (void*)(3 * sizeof(float) * drawStruct.m_nVertices));
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(6 * sizeof(float) * drawStruct.m_nVertices));

        glBindVertexArray(0);

        delete[](data);
    }
    translate_ = glm::translate(translate_, glm::vec3(0, 1, 0));
}

void Model::update(const GameTime& time)
{
    float secs = time.getTotalElapsedTime();
    float window = fmod(secs, animLength_);
    float oneStepTime = animLength_ / nFrames_;
    framePosition_ = fmod(window, oneStepTime) * nFrames_;
    floor_ = ((int)floor(window * nFrames_)) % nFrames_;
    ceil_ =  ((int)ceil(window * nFrames_)) % nFrames_;
}

Model::Model(const Model& orig)
{
}

Model::~Model()
{
    delete[](drawStruct_);
}

void Model::draw(const glm::mat4& transform)
{
    glBindVertexArray(drawStruct_[1].m_vertexArrayObject);
    glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(transform));
    glDrawArrays(GL_TRIANGLES, 0, drawStruct_[2].m_nVertices);
    glBindVertexArray( 0 );
}

void Model::drawAnim(const glm::mat4& transform)
{
    glBindBuffer(GL_ARRAY_BUFFER, drawStruct_[floor_].m_vertexBufferObject);

    glEnableVertexAttribArray(0); // position
    glEnableVertexAttribArray(5); // normals
    glEnableVertexAttribArray(1); // uv

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 0, (void*)(3 * sizeof(float) * drawStruct_[floor_].m_nVertices));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(6 * sizeof(float) * drawStruct_[floor_].m_nVertices));

    glBindBuffer(GL_ARRAY_BUFFER, drawStruct_[ceil_].m_vertexBufferObject);
    glEnableVertexAttribArray(8); // position_2
    glVertexAttribPointer(8, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glUniformMatrix4fv(2, 1, GL_FALSE, glm::value_ptr(transform));
    glUniform1f(9, framePosition_);

    glDrawArrays(GL_TRIANGLES, 0, drawStruct_[floor_].m_nVertices);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    Helper::gl("Entity drawanim");
}
