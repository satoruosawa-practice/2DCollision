//
//  sphere.h
//  2DCollision
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"

class Sphere {
 public:
  Sphere() = default;
  explicit Sphere(const AppTime &app_time);
  void reset();
  void update();
  void draw();
  void drawParameters();
  void resetForce();

  void addForce(const ofVec2f &f) {force_ += f; }

 private:
  void updateForce();
  void updatePos();
  void bounceOfWalls(const float &radius,
                     ofVec2f * position, ofVec2f * velocity);
  const AppTime * app_time_;

  ofVec2f position_;
  ofVec2f velocity_;  // m/s
  ofVec2f acceleration_;  // m/s2
  ofVec2f force_;  // N
  float radius_;  // m
  float mass_;  // kg
  float cor_;  // coefficient of restitution
};
