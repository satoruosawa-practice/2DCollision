//
//  scene.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "./scene.h"

void Scene::update(Sphere * sphere) {
  // bounce of walls
  float r = sphere->getRadius() * PX_PER_METER;
  ofVec2f p = sphere->getPosition() * PX_PER_METER;
  ofVec2f v = sphere->getVelocity() * PX_PER_METER;
  bounce_of_walls_.bounce(r, &p, &v);
  sphere->setVelocity(v / static_cast<float>(PX_PER_METER));
  sphere->setPosition(p / static_cast<float>(PX_PER_METER));
}
