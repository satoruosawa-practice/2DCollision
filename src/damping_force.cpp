//
//  damping_force.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./damping_force.h"

DampingForce::DampingForce(const float &damping) {
  damping_ = damping;
}

void DampingForce::updateForce(AbstractObject * object) {
  object->addForce(-object->velocity() * damping_);
}
