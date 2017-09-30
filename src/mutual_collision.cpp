//
//  mutual_collision.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include <string>
#include "./mutual_collision.h"

const string MutualCollision::circle_type_ = typeid(*new Circle()).name();

float MutualCollision::cor_ = 0.9;

void MutualCollision::collision(AbstractObject * object_a,
                                AbstractObject * object_b) {
  if (typeid(*object_a).name() == circle_type_&&
      typeid(*object_b).name() == circle_type_) {
  circles(dynamic_cast<Circle*>(object_a), dynamic_cast<Circle*>(object_b));
  }
}

void MutualCollision::circles(Circle * circle_a, Circle * circle_b) {
  ofVec2f velocity_a = circle_a->velocity();
  ofVec2f pos_a = circle_a->position();
  float radius_a = circle_a->radius();
  float mass_a = circle_a->mass();
  ofVec2f velocity_b = circle_b->velocity();
  ofVec2f pos_b = circle_b->position();
  float radius_b = circle_b->radius();
  float mass_b = circle_b->mass();

  ofVec2f pos_a_to_b = pos_b - pos_a;
  if (pos_a_to_b.length() < radius_a + radius_b) {
    ofVec2f N_a_to_b = pos_a_to_b.getNormalized();
    float velo_diff = velocity_b.dot(N_a_to_b) - velocity_a.dot(N_a_to_b);
    ofVec2f momentum = (mass_a * velocity_a.dot(N_a_to_b) + mass_b *
                        velocity_b.dot(N_a_to_b)) * N_a_to_b;
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

    circle_a->position(pos_a);
    circle_b->position(pos_b);
    circle_a->velocity(velocity_a);
    circle_b->velocity(velocity_b);
  }
}
