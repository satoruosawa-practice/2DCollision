//
//  circle.hpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"
#include "./abstract_object.h"

class Circle : public AbstractObject {
 public:
  Circle(const AppTime &app_time,
         const ofVec2f &velocity,
         const ofVec2f &position,
         const float &radius,
         const float &mass);
  void draw();
  float radius() const { return radius_; }

 protected:
  void resetForce();
  void updateForce();
  void updatePos();
  ofVec2f force_;  // N
  float radius_;  // m
  float mass_;  // kg
//  float damping_;
  ofColor color_;
};
