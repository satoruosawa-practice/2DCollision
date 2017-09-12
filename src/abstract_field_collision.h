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
#include "./app_time.h"
#include "abstract_object.h"

class AbstractObject;

class AbstractFieldCollision {
public:
  explicit AbstractFieldCollision(const AppTime &app_time,
                                  AbstractObject &object);
  virtual void update() = 0;
  
protected:
  const AppTime * app_time_;
  AbstractObject * object_;
};
