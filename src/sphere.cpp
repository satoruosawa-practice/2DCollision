//
//  sphere.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#include "./sphere.h"

Sphere::Sphere(const AppTime &app_time,
               const ofVec2f &velocity,
               const ofVec2f &position,
               const float &radius,
               const float &mass) {
  app_time_ = &app_time;
  radius_ = radius;
  mass_ = mass;
  damping_ = 0.05;
  resetForce();
  velocity_ = velocity;
  position_ = position;
  color_ = ofColor(10, 10, 10, 255);
}

void Sphere::update(){
  updateForce();
  updatePos();
}

void Sphere::updateForce() {
  resetForce();
//  force_ += ofVec2f(0.0, kGravity) * mass_;
  force_ += -velocity_ * damping_;
}

void Sphere::resetForce() {
  force_ = ofVec2f(0.0, 0.0);
  acceleration_ = ofVec2f(0.0, 0.0);
}

void Sphere::updatePos() {
  acceleration_ = force_ / mass_;
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();
}

void Sphere::draw() {
  ofFill();
  ofSetColor(color_);
  ofDrawCircle(position_ * kPxPerMeter, radius_ * kPxPerMeter);
}

