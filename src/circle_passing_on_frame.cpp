//
//  circle_passing_on_frame.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./circle_passing_on_frame.h"

CirclePassingOnFrame::CirclePassingOnFrame(float cor) {
  cor_ = cor;
}

void CirclePassingOnFrame::update(AbstractObject * object) {
  float radius = dynamic_cast<Circle*>(object)->radius();
  float xmin = radius;
  float xmax = ofGetWidth() / static_cast<float>(kPxPerMeter) - radius;
  float ymin = radius;
  float ymax = ofGetHeight() / static_cast<float>(kPxPerMeter) - radius;

  ofVec2f * p_velocity = object->pVelocity();
  ofVec2f * p_position = object->pPosition();
  if (p_position->x < xmin) {
    p_velocity->x *= cor_;
    p_position->x = xmax - (xmin - p_position->x);
  } else if (p_position->x > xmax) {
    p_velocity->x *= cor_;
    p_position->x = xmin + (p_position->x - xmax);
  }
  if (p_position->y < ymin) {
    p_velocity->y *= cor_;
    p_position->y = ymax - (ymin - p_position->y);
  } else if (p_position->y > ymax) {
    p_velocity->y *= cor_;
    p_position->y = ymin + (p_position->y - ymax);
  }
}
