//
//  damping_force.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//


#pragma once
#ifndef DAMPING_FORCE_H_
#define DAMPING_FORCE_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./abstract_field_force.h"
#include "./abstract_object.h"

class DampingForce : public AbstractFieldForce {
 public:
  explicit DampingForce(const float &damping);
  virtual void updateForce(AbstractObject * object);

 private:
  float damping_;
};

#endif  // DAMPING_FORCE_H_
