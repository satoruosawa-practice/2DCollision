//
//  circle.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"
#include "./abstract_object.h"

class Circle : public AbstractObject {
 public:
  Circle() = default;
  Circle(const AppTime &app_time,
         const ofVec2f &velocity,
         const ofVec2f &position,
         const float &radius,
         const float &mass);
  void updatePos();
  void draw();
};

#endif  // CIRCLE_H_
