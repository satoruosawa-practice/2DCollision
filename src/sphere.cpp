//
//  sphere.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#include "./sphere.h"
Sphere::Sphere(const AppTime &app_time) {
  app_time_ = &app_time;
  radius_ = 0.1;
  mass_ = 1.0;
  reset();
}

void Sphere::reset() {
  acceleration_ = ofVec2f(0.0, 0.0);
  force_ = ofVec2f(0.0, 0.0);
  acceleration_ += ofVec2f(0.0, 0.0);
  velocity_ = ofVec2f(0.0, 0.0);
  position_ = ofVec2f(2.0, 2.0);
}


void Sphere::update(){
  updateForce();
  updatePos();
}

void Sphere::resetForce() {
  force_ = ofVec2f(0.0, 0.0);
}

void Sphere::updateForce() {
//  force_ += ofVec2f(0.0, GRAVITY) * mass_;
}

void Sphere::updatePos() {
  acceleration_ = force_ / mass_;
  velocity_ += acceleration_ * app_time_->getDeltaTimeS();
  position_ += velocity_ * app_time_->getDeltaTimeS();

  ofVec2f p = position_ * PX_PER_METER;
  ofVec2f v = velocity_ * PX_PER_METER;
  bounceOfWalls(radius_, &p, &v);
  velocity_ = v / static_cast<float>(PX_PER_METER);
  position_ = p / static_cast<float>(PX_PER_METER);
}

void Sphere::draw() {
  ofDrawCircle(position_ * PX_PER_METER, radius_ * PX_PER_METER);
}

void Sphere::drawParameters() {
  ofDrawBitmapString("coefficient of restitution = " + ofToString(cor_) +
                     " mass = " + ofToString(mass_) + " kg", 10, 60);
  ofDrawBitmapString("acceleration = " +
    ofToString(acceleration_, 2) +
    " m/s2", 10, 80);
  ofDrawBitmapString("speed = " +
    ofToString(velocity_, 2) +
    " m/s", 10, 100);
  ofDrawBitmapString("position = " +
                     ofToString(position_, 2) +
                     " m", 10, 120);
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


