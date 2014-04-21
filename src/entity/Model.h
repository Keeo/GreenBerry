/* 
 * File:   Model.h
 * Author: Keo
 *
 * Created on 13. duben 2014, 17:28
 */

#ifndef MODEL_H
#define	MODEL_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "glm/ext.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <math.h> 

#include "../abstract/ADrawable.h"
#include "../observer/IEventMessagingSystem.h"
#include "../observer/EventMessagingSystem.h"
#include "../control/GameTime.h"
#include "../util/Helper.h"
#include "../util/Log.h"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <boost/format.hpp>

struct DrawStruct {
    GLuint m_vertexBufferObject;
    GLuint m_vertexArrayObject;
    GLuint m_nVertices;
};

class Model {
public:
    Model(std::string file, int nFrames, float animLength, int nFrameStep = 1);
    Model(const Model& orig);
    void draw(const glm::mat4&);
    void drawAnim(const glm::mat4&);
    void update(const GameTime&);
    virtual ~Model();
private:
    const struct aiScene* scene_;
    
    DrawStruct* drawStruct_;
    int nFrames_;
    float animLength_;
    
    int floor_ = 0;
    int ceil_ = 0;
    float framePosition_=0;
    
    
    glm::mat4 translate_;
};

#endif	/* MODEL_H */

