//
//  wall_behavior.h
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"

class WallBehavior {
 public:
  static void bounce(const float &radius,
                     ofVec2f * position, ofVec2f * velocity);
  static void passing(const float &radius,
                      ofVec2f * position, ofVec2f * velocity);
 private:
  WallBehavior();
  static float cor_;  // coefficient of restitution
};
