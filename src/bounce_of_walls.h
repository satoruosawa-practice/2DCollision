//
//  bounce_of_walls.h
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"

class BounceOfWalls {
 public:
  BounceOfWalls();
  void bounce(const float &radius,
              ofVec2f * position, ofVec2f * velocity) const;

 private:
  float cor_;  // coefficient of restitution
};
