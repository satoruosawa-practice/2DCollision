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
  explicit Sphere(const AppTime &app_time,
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
  // setter
  void setVelocity(const ofVec2f &v) { velocity_ = v; }
  void setPosition(const ofVec2f &p) { position_ = p; }
  void setSuperBall(bool f) { super_ball_flag_ = f; }
  // getter
  ofVec2f getVelocity() const { return velocity_; }
  ofVec2f getPosition() const { return position_; }
  float getRadius() const { return radius_; }
  float getMass() const {return mass_; }

 private:
  void updateForce();
  void updatePos();
  const AppTime * app_time_;

  ofVec2f position_;  // m
  ofVec2f velocity_;  // m/s
  ofVec2f acceleration_;  // m/s2
  ofVec2f force_;  // N
  float radius_;  // m
  float mass_;  // kg
  float damping_;
  
  bool super_ball_flag_;
};
