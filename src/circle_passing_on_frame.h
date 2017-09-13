//
//  circle_passing_on_frame.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/14.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./circle.h"

class CirclePassingOnFrame : public AbstractFieldCollision {
 public:
  explicit CirclePassingOnFrame(Circle &object);
  virtual void update();
};
