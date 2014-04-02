/* 
 * File:   DayNightControl.h
 * Author: Keo
 *
 * Created on 2. duben 2014, 19:56
 */

#ifndef DAYNIGHTCONTROL_H
#define	DAYNIGHTCONTROL_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../abstract/ADrawable.h"
#include "../observer/IEventMessagingSystem.h"
#include "../observer/EventMessagingSystem.h"
#include "../util/Helper.h"
#include "../util/Log.h"
enum DayPhase : unsigned char {
    DAWN,
    DAY,
    DUSK,
    NIGHT
};

class DayNightControl : IEventMessagingSystem {
public:
    DayNightControl();
    DayNightControl(const DayNightControl& orig);
    
    void update(const sf::Time&);
    
    
    
    virtual ~DayNightControl();
private:
    void updateDaylight();
    void updateWorldTime();
    
    glm::vec3 ambientLight;
    void getDirectionalLight(void* data);
    
    DayPhase dayPhase_;
    
    float currentCycleTime_ = 0;  
    float lightIntensity_;
    
    float hoursPerDay_;  
    int worldTimeHour_;  
    int minutes_;  
    
    float timePerHour_ ;  
    
    float dawnTime_;
    float dayTime_;
    float duskTime_;
    float nightTime_;
    
    float quarterDay_;  
    float halfquarterDay_;

    static const glm::vec3 fullLight_;
    static const glm::vec3 fullDark_;
    static const glm::vec3 dawnDuskFog_;
    static const glm::vec3 dayFog_;
    static const glm::vec3 nightFog_;

    
    static const float dayCycleLength_;
};

#endif	/* DAYNIGHTCONTROL_H */

