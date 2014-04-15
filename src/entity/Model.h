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

#include "../abstract/ADrawable.h"
#include "../observer/IEventMessagingSystem.h"
#include "../observer/EventMessagingSystem.h"
#include "../util/Helper.h"
#include "../util/Log.h"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

class Model {
public:
    Model(std::string file);
    Model(const Model& orig);
    void draw(const glm::mat4&);
    virtual ~Model();
private:
    const struct aiScene* scene_;
    
    GLuint m_vertexBufferObject, m_vertexArrayObject;
    GLuint texture_loc_day;
    GLuint texture_loc_night;
    GLuint m_nVertices;

    GLuint m_nVertices_moon;
    GLuint m_vertexBufferObject_moon, m_vertexArrayObject_moon;
    GLuint texture_moon_loc;
    
    glm::mat4 translate_;
};

#endif	/* MODEL_H */

