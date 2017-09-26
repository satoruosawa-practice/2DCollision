//
//  abstract_object.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef ABSTRACT_OBJECT_H_
#define ABSTRACT_OBJECT_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"

class AbstractObject {
 public:
  AbstractObject() = default;
  explicit AbstractObject(const AppTime &app_time);
  virtual void updatePos() = 0;
  virtual void draw() = 0;
  void resetForce();
  ofVec2f* pPosition() { return &position_; }
  ofVec2f* pVelocity() { return &velocity_; }
  ofVec2f position() const { return position_; }
  ofVec2f velocity() const { return velocity_; }
  float mass() const { return mass_; }
  float radius() const { return radius_; }
  void addForce(const ofVec2f &f) { force_ += f; }
  void position(const ofVec2f &p) { position_ = p; }
  void velocity(const ofVec2f &v) { velocity_ = v; }
  void color(const ofColor &c) { color_ = c; }

 protected:
  const AppTime * app_time_;
  ofVec2f force_;  // N
  ofVec2f position_;  // m
  ofVec2f velocity_;  // m/s
  float mass_;  // kg
  float radius_;  // m
  ofColor color_;
};

#endif  // ABSTRACT_OBJECT_H_
