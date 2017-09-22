//
//  mutual_collision.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/14.
//
//

#pragma once

#include <typeinfo>

#include "ofMain.h"
#include "./global_definition.h"
#include "./circle.h"

class MutualCollision {
 public:
  static void collision(AbstractObject * object_a, AbstractObject * object_b);

 private:
  static void circles(Circle * circle_a, Circle * circle_b);
  static const string circle_type_;
  static float cor_;
};
