//
//  circle_bounce_on_frame.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/12.
//
//

#include "./circle_bounce_on_frame.h"

CircleBounceOnFrame::CircleBounceOnFrame(const AppTime &app_time,
               Circle &object)
: AbstractFieldCollision(app_time, object) {
}


void CircleBounceOnFrame::update() {
  float cor_ = 1.0;
  float radius = dynamic_cast<Circle*>(object_)->radius();
  float xmin = radius;
  float xmax = ofGetWidth() / static_cast<float>(kPxPerMeter) - radius;
  float ymin = radius;
  float ymax = ofGetHeight() / static_cast<float>(kPxPerMeter) - radius;

  ofVec2f * velocity = object_->pVelocity();
  ofVec2f * position = object_->pPosition();
 
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
