//
//  collision.h
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#pragma once

#include "ofMain.h"
#include "./sphere.h"

class Collision {
 public:
  static void circles(Sphere * sphere_a, Sphere * sphere_b);

 private:
  Collision();
};
