//
//  radial_force.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef RADIAL_FORCE_H_
#define RADIAL_FORCE_H_

#include "ofMain.h"
#include "./global_definition.h"
#include "./abstract_field_force.h"
#include "./abstract_object.h"

class RadialForce : public AbstractFieldForce {
 public:
  RadialForce() = default;
  RadialForce(const ofVec2f &center_pos, const float &intensity,
              const float &action_radius);
  virtual void updateForce(AbstractObject * object);
  void updateCenterPos(const ofVec2f &center_pos);

 private:
  ofVec2f center_pos_;
  float intensity_;
  float action_radius_;
};

#endif  // RADIAL_FORCE_H_
