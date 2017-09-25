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
  virtual void update();
  virtual void draw() = 0;
  ofVec2f* pPosition() { return &position_; }
  ofVec2f* pVelocity() { return &velocity_; }
  ofVec2f position() const { return position_; }
  ofVec2f velocity() const { return velocity_; }
  float mass() const { return mass_; }
  void position(const ofVec2f &p) { position_ = p; }
  void velocity(const ofVec2f &v) { velocity_ = v; }
  void color(const ofColor &c) { color_ = c; }

 protected:
  void resetForce();
  virtual void updateForce() = 0;
  virtual void updatePos() = 0;
  const AppTime * app_time_;
  ofVec2f force_;  // N
  ofVec2f position_;  // m
  ofVec2f velocity_;  // m/s
  float mass_;  // kg
  ofColor color_;
};

#endif  // ABSTRACT_OBJECT_H_
