/* 
 * File:   DayNightControl.cpp
 * Author: Keo
 * 
 * Created on 2. duben 2014, 19:56
 */

#include "DayNightControl.h"

const glm::vec3 DayNightControl::fullLight_(253.0f / 255.0f, 248.0f / 255.0f, 223.0f / 255.0f);
const glm::vec3 DayNightControl::fullDark_(32.0f / 255.0f, 28.0f / 255.0f, 46.0f / 255.0f);
const glm::vec3 DayNightControl::dawnDuskFog_(133.0f / 255.0f, 124.0f / 255.0f, 102.0f / 255.0f);
const glm::vec3 DayNightControl::dayFog_(180.0f / 255.0f, 208.0f / 255.0f, 209.0f / 255.0f);
const glm::vec3 DayNightControl::nightFog_(12.0f / 255.0f, 15.0f / 255.0f, 91.0f / 255.0f);
const float DayNightControl::dayCycleLength_ = 1440;

DayNightControl::DayNightControl()
{
    quarterDay_ = dayCycleLength_ * 0.25f;
    halfquarterDay_ = dayCycleLength_ * 0.125f;
    dawnTime_ = 0.0f;
    dayTime_ = dawnTime_ + halfquarterDay_;
    duskTime_ = dayTime_ + quarterDay_ + halfquarterDay_;
    nightTime_ = duskTime_ + halfquarterDay_;
    timePerHour_ = dayCycleLength_ / hoursPerDay_;
    
    EventMessagingSystem::getInstance().Register(Events::getDirectionalLight, this, (Callback) & DayNightControl::getDirectionalLight);
}

void DayNightControl::getDirectionalLight(void* data)
{
    glm::vec3* p = (glm::vec3*)data;
    *p = ambientLight;
}


DayNightControl::DayNightControl(const DayNightControl& orig)
{
}

DayNightControl::~DayNightControl()
{
}

void DayNightControl::update(const GameTime& time)
{
    currentCycleTime_ += time.asSeconds()*100;

    if (currentCycleTime_ > nightTime_ && dayPhase_ == DayPhase::DUSK) {
        dayPhase_ = DayPhase::NIGHT;
    } else if (currentCycleTime_ > duskTime_ && dayPhase_ == DayPhase::DAY) {
        dayPhase_ = DayPhase::DUSK;
    } else if (currentCycleTime_ > dayTime_ && dayPhase_ == DayPhase::DAWN) {
        dayPhase_ = DayPhase::DAY;
    } else if (currentCycleTime_ > dawnTime_ && currentCycleTime_ < dayTime_ && dayPhase_ == DayPhase::NIGHT) {
        dayPhase_ = DayPhase::DAWN;
    }

    if (currentCycleTime_ > dayCycleLength_) {
        currentCycleTime_ = 0;
    }

    updateWorldTime();
    updateDaylight();


}

void DayNightControl::updateWorldTime()
{
    worldTimeHour_ = (int) (fmod(ceil((currentCycleTime_ / dayCycleLength_) * hoursPerDay_)/* + dawnTimeOffset_*/, hoursPerDay_)) + 1;
    minutes_ = (int) (ceil(fmod(currentCycleTime_ * (60 / timePerHour_), 60)));
}

void DayNightControl::updateDaylight()
{
    float relativeTime;
    switch (dayPhase_) {
        case DAWN:
            relativeTime = currentCycleTime_ - dawnTime_;
            ambientLight = glm::lerp(fullDark_, fullLight_, relativeTime / halfquarterDay_);
            /*if (light != null){ 
                light.intensity = lightIntensity * (relativeTime / halfquarterDay);
            }*/
            break;
        case DUSK:
            relativeTime = currentCycleTime_ - duskTime_;
            ambientLight = glm::lerp(fullLight_, fullDark_, relativeTime / halfquarterDay_);
            /*if (light != null) {
                light.intensity = lightIntensity * ((halfquarterDay - relativeTime) / halfquarterDay);
            }*/
            break;
        case DAY:
            ambientLight = fullLight_;
            break;
        case NIGHT:
            ambientLight = fullDark_;
            break;
    }
    
    //transform.Rotate(Vector3.up * ((Time.deltaTime / dayCycleLength) * 360.0f), Space.Self);
    //transform.RotateAround (rotation.position, Vector3.forward, ((Time.deltaTime / dayCycleLength) * 360.0f));
} 