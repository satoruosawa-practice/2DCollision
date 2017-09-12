//
//  abstract_object.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#include "abstract_object.h"

AbstractObject::AbstractObject(const AppTime &app_time) {
  app_time_ = &app_time;
}

void AbstractObject::setFieldCollision(AbstractFieldCollision * c) {
  field_collision_container_.push_back(c);
}

void AbstractObject::update(){
  updateForce();
  updatePos();
  FieldCollision();
}

void AbstractObject::FieldCollision() {
  for (auto &c : field_collision_container_) {
    c->update();
  }
}
