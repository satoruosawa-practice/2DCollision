//
//  scene.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "./scenea.h"

void Scenea::setup() {
  
}

void Scenea::updateSingle(Sphere * sphere) {
  // bounce of walls
  float r = sphere->getRadius() * kPxPerMeter;
  ofVec2f p = sphere->getPosition() * kPxPerMeter;
  ofVec2f v = sphere->getVelocity() * kPxPerMeter;
  WallBehavior::bounce(r, &p, &v);
  sphere->setVelocity(v / static_cast<float>(kPxPerMeter));
  sphere->setPosition(p / static_cast<float>(kPxPerMeter));
}

void Scenea::updateMutual(Sphere * sphere_a, Sphere * sphere_b) {
  Collision::circles(sphere_a, sphere_b);
}
