//
//  circle_bounce_on_frame.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"
#include "./abstract_field_collision.h"
#include "circle.h"

class CircleBounceOnFrame : public AbstractFieldCollision {
 public:
  explicit CircleBounceOnFrame(const AppTime &app_time,
                  Circle &object);
  virtual void update();
};
