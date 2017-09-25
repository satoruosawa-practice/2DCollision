//
//  abstract_field_collision.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef ABSTRACT_FIELD_COLLISION_H_
#define ABSTRACT_FIELD_COLLISION_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./abstract_object.h"

class AbstractFieldCollision {
 public:
  virtual void update(AbstractObject * object) = 0;
};

#endif  // ABSTRACT_FIELD_COLLISION_H_
