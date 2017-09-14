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

class AbstractFieldCollision {
 public:
  virtual void update(AbstractObject * object) = 0;
};
