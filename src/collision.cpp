//
//  collision.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/25/17.
//
//

#include "collision.h"

float Collision::cor_ = 1.0;

void Collision::circles(Sphere * sphere_a, Sphere * sphere_b) {
  ofVec2f velocity_a = sphere_a->getVelocity();
  ofVec2f pos_a = sphere_a->getPosition();
  float radius_a = sphere_a->getRadius();
  float mass_a = sphere_a->getMass();
  ofVec2f velocity_b = sphere_b->getVelocity();
  ofVec2f pos_b = sphere_b->getPosition();
  float radius_b = sphere_b->getRadius();
  float mass_b = sphere_b->getMass();

  ofVec2f pos_a_to_b = pos_b - pos_a;
  if (pos_a_to_b.length() < radius_a + radius_b) {
    ofVec2f N_a_to_b = pos_a_to_b.getNormalized();
    float velo_diff = velocity_b.dot(N_a_to_b) - velocity_a.dot(N_a_to_b);
    ofVec2f momentum = (mass_a * velocity_a.dot(N_a_to_b) + mass_b * velocity_b.dot(N_a_to_b)) * N_a_to_b;
    velocity_a -= velocity_a.dot(N_a_to_b) * N_a_to_b;  // reset normal velo
    velocity_a += (momentum +
                  cor_ * mass_b * velo_diff * N_a_to_b) /
                  (mass_a + mass_b);
    velocity_b -= velocity_b.dot(N_a_to_b) * N_a_to_b;  // reset normal velo
    velocity_b += (momentum -
                  cor_ * mass_a * velo_diff * N_a_to_b) /
                  (mass_a + mass_b);
    float buried_amount = radius_a + radius_b - pos_a_to_b.length();
    pos_a += -N_a_to_b * buried_amount * mass_b / (mass_a + mass_b);
    pos_b += N_a_to_b * buried_amount * mass_a / (mass_a + mass_b);
    
    sphere_a->setPosition(pos_a);
    sphere_b->setPosition(pos_b);
    sphere_a->setVelocity(velocity_a);
    sphere_b->setVelocity(velocity_b);
  }
}
