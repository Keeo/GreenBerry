/* 
 * File:   Mesh.h
 * Author: Keo
 *
 * Created on 21. březen 2014, 19:53
 */

#ifndef MESH_H
#define	MESH_H

#include <map>
#include <vector>

#include <gl/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>

#include <assert.h>
#include <assimp/Importer.hpp>
#include <assimp/cimport.h>
#include <assimp/scene.h>       // Output data structure
#include <assimp/postprocess.h>

struct Vertex
{
    
    glm::vec3 m_pos;
    glm::vec2 m_tex;
    glm::vec3 m_normal;

    Vertex() {}

    Vertex(const glm::vec3& pos, const glm::vec2& tex, const glm::vec3& normal)
    {
        m_pos    = pos;
        m_tex    = tex;
        m_normal = normal;
    }
};

class Mesh {
public:
    Mesh();
    
    Mesh(const Mesh& orig);
    
    bool loadMesh(const std::string& Filename);
    
    void render();
    
    virtual ~Mesh();
private:

    bool initFromScene(const aiScene* pScene, const std::string& filename);
    void initMesh(unsigned int index, const aiMesh* paiMesh);
    bool initMaterials(const aiScene* pScene, const std::string& filename);
    void clear();
    
     struct MeshEntry {
        MeshEntry();

        ~MeshEntry();

        void init(const std::vector<Vertex>& Vertices,
                  const std::vector<unsigned int>& Indices);

        GLuint VB;
        GLuint IB;
        unsigned int numIndices;
        unsigned int materialIndex;
    };
    
    std::vector<MeshEntry> m_Entries;
    //std::vector<Texture*> m_Textures;
};

#endif	/* MESH_H */

