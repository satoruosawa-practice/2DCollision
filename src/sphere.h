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
#include "./scene.h"

class Sphere {
 public:
  Sphere() = default;
  explicit Sphere(const AppTime &app_time,
                  const Scene &scene,
                  const ofVec2f &velocity,
                  const ofVec2f &position,
                  const float &radius,
                  const float &mass);
  void reset(const ofVec2f &velocity,
             const ofVec2f &position);
  void update();
  void draw();
  void resetForce();

  void addForce(const ofVec2f &f) {force_ += f; }

 private:
  void updateForce();
  void updatePos();
  void bounceOfWalls(const float &radius,
                     ofVec2f * position, ofVec2f * velocity);
  const AppTime * app_time_;
  const Scene * scene_;

  ofVec2f position_;  // m
  ofVec2f velocity_;  // m/s
  ofVec2f acceleration_;  // m/s2
  ofVec2f force_;  // N
  float radius_;  // m
  float mass_;  // kg
  float damping_;
};
