//
//  abstract_field_collision.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/12.
//
//

#include "abstract_field_collision.h"

AbstractFieldCollision::AbstractFieldCollision(const AppTime &app_time,
                                               AbstractObject &object) {
  app_time_ = &app_time;
  object_ = &object;
}
