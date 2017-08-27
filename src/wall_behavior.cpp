//
//  wall_behavior.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "./wall_behavior.h"

float WallBehavior::cor_ = 1.0;

void WallBehavior::bounce(const float &radius,
                           ofVec2f * position,
                           ofVec2f * velocity) {
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

void WallBehavior::passing(const float &radius,
                          ofVec2f * position,
                          ofVec2f * velocity) {
  float xmin = radius;
  float xmax = ofGetWidth() - radius;
  float ymin = radius;
  float ymax = ofGetHeight() - radius;
  
  if (position->x < xmin) {
    velocity->x *= cor_;
    position->x = xmax - (xmin - position->x);
  } else if (position->x > xmax) {
    velocity->x *= cor_;
    position->x = xmin + (position->x - xmax);
  }
  if (position->y < ymin) {
    velocity->y *= cor_;
    position->y = ymax - (ymin - position->y);
  } else if (position->y > ymax) {
    velocity->y *= cor_;
    position->y = ymin + (position->y - ymax);
  }
}


