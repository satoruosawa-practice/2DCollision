//
//  sphere.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#include "./sphere.h"

Sphere::Sphere(const AppTime &app_time,
               const ofVec2f &position,
               const ofVec2f &velocity,
               const float &radius,
               const float &mass) {
  app_time_ = &app_time;
  radius_ = radius;
  mass_ = mass;
  damping_ = 0.05;
  reset(position, velocity);
  color_ = ofColor(10, 10, 10, 255);
}

void Sphere::reset(const ofVec2f &velocity, const ofVec2f &position) {
  resetForce();
  velocity_ = velocity;
  position_ = position;
}

void Sphere::update(){
  updateForce();
  updatePos();
}

void Sphere::resetForce() {
  force_ = ofVec2f(0.0, 0.0);
  acceleration_ = ofVec2f(0.0, 0.0);
}

void Sphere::updateForce() {
//  force_ += ofVec2f(0.0, GRAVITY) * mass_;
  force_ += -velocity_ * damping_;
}

void Sphere::updatePos() {
  acceleration_ = force_ / mass_;
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();
}

void Sphere::draw() {
  ofFill();
  ofSetColor(color_);
  ofDrawCircle(position_ * PX_PER_METER, radius_ * PX_PER_METER);
}

