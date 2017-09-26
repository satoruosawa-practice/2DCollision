//
//  radial_force.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./radial_force.h"

RadialForce::RadialForce(const ofVec2f &center_pos, const float &intensity) {
  center_pos_ = center_pos;
  intensity_ = intensity;
}

void RadialForce::updateForce(AbstractObject * object) {
  ofVec2f diff = center_pos_ - object->position();
  float dist = diff.length();
  ofVec2f direction = diff.normalize();
  if (dist > object->radius()) {
    object->addForce(direction * intensity_ * object->mass() /
                     (dist * dist));
  } else if (dist > 0) {
    object->addForce(direction * intensity_ * object->mass() /
                     (object->radius() * object->radius()));
  }
}
