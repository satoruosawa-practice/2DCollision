//
//  directional_force.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef DIRECTIONAL_FORCE_H_
#define DIRECTIONAL_FORCE_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./abstract_field_force.h"
#include "./abstract_object.h"

class DirectionalForce : public AbstractFieldForce {
 public:
  explicit DirectionalForce(const ofVec2f &force);
  virtual void updateForce(AbstractObject * object);

 private:
  ofVec2f force_;
};

#endif  // DIRECTIONAL_FORCE_H_
