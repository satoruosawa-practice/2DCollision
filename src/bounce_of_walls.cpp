//
//  bounce_of_walls.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "./bounce_of_walls.h"

BounceOfWalls::BounceOfWalls() {
  cor_ = 1.0;
}

void BounceOfWalls::bounce(const float &radius,
                           ofVec2f * position,
                           ofVec2f * velocity) const {
  ofVec2f p = *position * PX_PER_METER;
  ofVec2f v = *velocity * PX_PER_METER;
  float r = radius * PX_PER_METER;

  float xmin = r;
  float xmax = ofGetWidth() - r;
  float ymin = r;
  float ymax = ofGetHeight() - r;

  if (p.x < xmin) {
    v.x *= -cor_;
    p.x = xmin + (xmin - p.x);
  } else if (p.x > xmax) {
    v.x *= -cor_;
    p.x = xmax - (p.x - xmax);
  }
  if (p.y < ymin) {
    v.y *= -cor_;
    p.y = ymin + (ymin - p.y);
  } else if (p.y > ymax) {
    v.y *= -cor_;
    p.y = ymax - (p.y - ymax);
  }

  *velocity = v / static_cast<float>(PX_PER_METER);
  *position = p / static_cast<float>(PX_PER_METER);
}


