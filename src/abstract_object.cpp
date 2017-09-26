//
//  abstract_object.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./abstract_object.h"

AbstractObject::AbstractObject(const AppTime &app_time) {
  app_time_ = &app_time;
}

void AbstractObject::resetForce() {
  force_ = ofVec2f(0.0, 0.0);
}

