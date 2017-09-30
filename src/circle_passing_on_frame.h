//
//  circle_passing_on_frame.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef CIRCLE_PASSING_ON_FRAME_H_
#define CIRCLE_PASSING_ON_FRAME_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./abstract_field_collision.h"
#include "./circle.h"

class CirclePassingOnFrame : public AbstractFieldCollision {
 public:
  CirclePassingOnFrame(float cor = 1.0);
  void update(AbstractObject * object);

 private:
  float cor_;
};

#endif  // CIRCLE_PASSING_ON_FRAME_H_
