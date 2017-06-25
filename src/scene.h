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
#include "./sphere.h"

class Scene {
 public:
  void update(Sphere * s);
 private:
  BounceOfWalls bounce_of_walls_;
};
