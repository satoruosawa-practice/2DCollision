//
//  abstract_field_force.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef ABSTRACT_FIELD_FORCE_H_
#define ABSTRACT_FIELD_FORCE_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"
#include "./abstract_object.h"

class AbstractFieldForce {
 public:
  AbstractFieldForce() = default;
  virtual void updateForce(AbstractObject * object) = 0;
};

#endif  // ABSTRACT_FIELD_FORCE_H_
