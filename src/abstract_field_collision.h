//
//  abstract_field_collision.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./abstract_object.h"

class AbstractObject;

class AbstractFieldCollision {
 public:
  explicit AbstractFieldCollision(AbstractObject &object);
  virtual void update() = 0;

 protected:
  AbstractObject * object_;
};
