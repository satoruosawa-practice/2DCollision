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

class Scene {
public:
  void update(const float &radius,
                ofVec2f * position,
                ofVec2f * velocity) const;
private:
  BounceOfWalls bounce_of_walls_;
};
