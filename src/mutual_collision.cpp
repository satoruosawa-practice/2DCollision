//
//  mutual_collision.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/14.
//
//

#include "mutual_collision.h"

void MutualCollision::collision(AbstractObject * object_a,
                                AbstractObject * object_b) {
  std::cout<< typeid(*object_a).name() << std::endl;
  std::cout<< typeid(Circle()).name() << std::endl;
//  if (typeid(object_a) == typeid(Circle())&&
//      typeid(object_b) == typeid(Circle())) {
//  if (typeid(object_a) == typeid(object_b)) {
//  circles(dynamic_cast<Circle*>(object_a), dynamic_cast<Circle*>(object_b));
//  }
}

void MutualCollision::circles(Circle * object_a, Circle * object_b) {
  std::cout<< 2 << std::endl;
}
