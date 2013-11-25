/* 
 * File:   Camera.h
 * Author: Keo
 *
 * Created on 25. listopad 2013, 16:52
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

class Camera
{
    
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    
    void init();
    void update();
    glm::mat4 getVP();
    
private:
    glm::mat4 _projection;
    glm::mat4 _view;
    
    glm::vec3 _position;
    glm::vec3 _direction;
    glm::vec3 _right;
    glm::vec3 _up;
    
    float _horizontalAngle, _verticalAngle;
    
    void rotate();
    void updateDirection();
};

#endif	/* CAMERA_H */

