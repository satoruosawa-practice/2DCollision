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
#include "./abstract_field_collision.h"
#include "./circle.h"

class CirclePassingOnFrame : public AbstractFieldCollision {
 public:
  void update(AbstractObject * object);
};