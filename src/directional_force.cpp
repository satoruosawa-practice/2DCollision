//
//  directional_force.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./directional_force.h"

DirectionalForce::DirectionalForce(const ofVec2f &force) {
  force_ = force;
}

void DirectionalForce::updateForce(AbstractObject * object) {
  object->addForce(force_ * object->mass());
}
