//
//  scene.h
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#pragma once

#include "ofMain.h"
#include "./bounce_of_walls.h"
#include "collision.h"
#include "./sphere.h"

class Scene {
 public:
  void setup();
  void updateSingle(Sphere * s);
  void updateMutual(Sphere * sphere_a, Sphere * sphere_b);

 private:
//  BounceOfWalls bounce_of_walls_;
//  Collision collision_;
};
