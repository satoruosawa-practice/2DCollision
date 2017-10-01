//
//  radial_force.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./radial_force.h"

RadialForce::RadialForce(const ofVec2f &center_pos, const float &intensity,
                         const float &action_radius) {
  center_pos_ = center_pos;
  intensity_ = intensity;
  action_radius_ = action_radius;
}

void RadialForce::updateForce(AbstractObject * object) {
  ofVec2f diff = center_pos_ - object->position();
  float dist = diff.length();
  ofVec2f direction = diff.getNormalized();

//  float threshold = object->radius();
//  if (dist > threshold) {
//    object->addForce(direction * intensity_ * object->mass() /
//                     (dist));
//  }

  if (dist < action_radius_) {
    float pct = 1 - (dist / action_radius_);
    object->addForce(direction * object->mass() * intensity_ * pct);
  }
}

void RadialForce::updateCenterPos(const ofVec2f &center_pos) {
  std::cout<< 0<<std::endl;
  center_pos_ = center_pos;
}
