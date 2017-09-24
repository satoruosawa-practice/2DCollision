//
//  abstract_object.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#pragma once

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
  void position(const ofVec2f &p) { position_ = p; }
  void velocity(const ofVec2f &v) { velocity_ = v; }
  void color(const ofColor &c) { color_ = c; }

 protected:
  virtual void updateForce() = 0;
  virtual void updatePos() = 0;
  const AppTime * app_time_;
  ofVec2f position_;  // m
  ofVec2f velocity_;  // m/s
  ofColor color_;
};
