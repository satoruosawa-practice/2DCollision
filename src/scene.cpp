//
//  scene.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#include "scene.h"

void Scene::setup(const AppTime &app_time) {
  app_time_ = &app_time;
  float radius = 0.3;  // m
  ofVec2f velocity = ofVec2f(1.0, 1.0);
  ofVec2f position = ofVec2f(5.0, 5.0);
  float mass = radius * radius * radius * 300.0;  // kg
  Circle * c = new Circle(app_time, velocity, position, radius, mass);
  object_container_.push_back(c);
  Circle * c2 = new Circle(app_time, velocity * 0.1, position, radius, mass);
  object_container_.push_back(c2);
  
//  CircleBounceOnFrame * b = new CircleBounceOnFrame();
  CirclePassingOnFrame * b = new CirclePassingOnFrame();
  field_collision_container_.push_back(b);
}

void Scene::update() {
  for (auto &o : object_container_) {
    o->update();
    for (auto &c : field_collision_container_) {
      c->update(o);
    }
  }
  for (int i = 0; i < object_container_.size(); i++) {
    for (int j = 0; j < i; j++) {
      MutualCollision::collision(object_container_[i], object_container_[j]);
    }
  }

}

void Scene::draw() {
  for (auto &o : object_container_){
    o->draw();
  }
}
