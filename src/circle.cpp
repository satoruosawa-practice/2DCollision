//
//  circle.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./circle.h"

Circle::Circle(const AppTime &app_time,
               const ofVec2f &velocity,
               const ofVec2f &position,
               const float &radius,
               const float &mass)
: AbstractObject(app_time) {
  radius_ = radius;
  mass_ = mass;
//  damping_ = 0.05;
  velocity_ = velocity;
  position_ = position;
  color_ = ofColor(10, 10, 10, 255);
  resetForce();
}

void Circle::updateForce() {
  resetForce();
//  force_ += ofVec2f(0.0, kGravity) * mass_;
//  force_ += -velocity_ * damping_;
}

void Circle::updatePos() {
  ofVec2f acceleration_ = force_ / mass_;  // m/s2
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();
}

void Circle::draw() {
  ofFill();
  ofSetColor(color_);
  ofDrawCircle(position_ * kPxPerMeter, radius_ * kPxPerMeter);
}
