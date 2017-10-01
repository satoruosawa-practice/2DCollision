//
//  mutual_collision.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef MUTUAL_COLLISION_H_
#define MUTUAL_COLLISION_H_

#include <typeinfo>
#include <string>
#include "ofMain.h"
#include "./global_definition.h"
#include "./circle.h"

class MutualCollision {
 public:
  static void collision(AbstractObject * object_a, AbstractObject * object_b);
  static float cor_;

 private:
  static void circles(Circle * circle_a, Circle * circle_b);
  static const string circle_type_;
};

#endif  // MUTUAL_COLLISION_H_
