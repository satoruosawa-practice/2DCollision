//
//  abstract_object.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"

class AbstractObject {
 public:
  explicit AbstractObject(const AppTime &app_time);
  virtual void update();
  virtual void draw() = 0;

 protected:
  virtual void updateForce() = 0;
  virtual void updatePos() = 0;
  const AppTime * app_time_;
};
