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
  damping_ = 24;
  reset(position, velocity);
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
  force_ += ofVec2f(0.0, GRAVITY) * mass_;
  force_ += -velocity_ * damping_;
}

void Sphere::updatePos() {
  acceleration_ = force_ / mass_;
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();

  ofVec2f p = position_ * PX_PER_METER;
  ofVec2f v = velocity_ * PX_PER_METER;
  float r = radius_ * PX_PER_METER;
  bounceOfWalls(r, &p, &v);
  velocity_ = v / static_cast<float>(PX_PER_METER);
  position_ = p / static_cast<float>(PX_PER_METER);
}

void Sphere::draw() {
  ofDrawCircle(position_ * PX_PER_METER, radius_ * PX_PER_METER);
}

void Sphere::bounceOfWalls(const float &radius,
                           ofVec2f * position,
                           ofVec2f * velocity) {
  cor_ = 1.0;
  float xmin = radius;
  float xmax = ofGetWidth() - radius;
  float ymin = radius;
  float ymax = ofGetHeight() - radius;
  
  if (position->x < xmin) {
    velocity->x *= -cor_;
    position->x = xmin + (xmin - position->x);
  } else if (position->x > xmax) {
    velocity->x *= -cor_;
    position->x = xmax - (position->x - xmax);
  }
  if (position->y < ymin) {
    velocity->y *= -cor_;
    position->y = ymin + (ymin - position->y);
  } else if (position->y > ymax) {
    velocity->y *= -cor_;
    position->y = ymax - (position->y - ymax);
  }
}


