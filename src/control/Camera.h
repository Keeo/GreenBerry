/* 
 * File:   Camera.h
 * Author: Keo
 *
 * Created on 25. listopad 2013, 16:52
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include <gl/glew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "../observer/IEventMessagingSystem.h"
#include "../model/Chunk.h"
#include "../Helper.h"

class Camera : IEventMessagingSystem
{
    
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    
    void init();
    void update(const sf::Time&);
    void draw();
    
private:
    glm::mat4 _projection;
    glm::mat4 _view;
    
    glm::vec3 _position;
    glm::vec3 _position_last;
    
    glm::vec3 _direction;
    glm::vec3 _right;
    glm::vec3 _up;
    
    float _horizontalAngle = 0;
    float _verticalAngle = 0;
    
    void rotate(float&);
    void updateDirection();
};

#endif	/* CAMERA_H */

