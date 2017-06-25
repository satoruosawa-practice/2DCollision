//
//  scene.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "./scene.h"

void Scene::update(const float &radius,
              ofVec2f * position,
              ofVec2f * velocity) const {
  bounce_of_walls_.bounce(radius, position, velocity);
}
