//
//  circle_bounce_on_frame.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/12.
//
//

#include "./circle_bounce_on_frame.h"

void CircleBounceOnFrame::update(AbstractObject * object) {
  float cor = 1.0;
  float radius = dynamic_cast<Circle*>(object)->radius();
  float xmin = radius;
  float xmax = ofGetWidth() / static_cast<float>(kPxPerMeter) - radius;
  float ymin = radius;
  float ymax = ofGetHeight() / static_cast<float>(kPxPerMeter) - radius;

  ofVec2f * p_velocity = object->pVelocity();
  ofVec2f * p_position = object->pPosition();
  if (p_position->x < xmin) {
    p_velocity->x *= -cor;
    p_position->x = xmin + (xmin - p_position->x);
  } else if (p_position->x > xmax) {
    p_velocity->x *= -cor;
    p_position->x = xmax - (p_position->x - xmax);
  }
  if (p_position->y < ymin) {
    p_velocity->y *= -cor;
    p_position->y = ymin + (ymin - p_position->y);
  } else if (p_position->y > ymax) {
    p_velocity->y *= -cor;
    p_position->y = ymax - (p_position->y - ymax);
  }
}