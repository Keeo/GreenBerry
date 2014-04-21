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
#include "../observer/EventMessagingSystem.h"
#include "../control/GameTime.h"
#include "../model/Chunk.h"
#include "../util/Helper.h"

#define chunkilize(x) (int)( ((float)x / 32) > 0 ? ceil((float)x / 32) :  floor((float)x / 32) )

class Camera : IEventMessagingSystem
{
    
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    
    void init();
    void update(const GameTime&);
    void draw(void* data);
    void drawWeather(void* data);
    
private:
    glm::mat4 projection_;
    glm::mat4 view_;
    
    glm::vec3 position_;
    glm::vec3 positionLast_;
    
    glm::vec3 direction_;
    glm::vec3 right_;
    glm::vec3 up_;
    
    float horizontalAngle_ = 0;
    float verticalAngle_ = 0;
    
    void rotate(float&);
    void move(float&);
    void updateDirection();
    
    void getPositionPointer(void* data);
};

#endif	/* CAMERA_H */

