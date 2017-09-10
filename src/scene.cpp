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
  AbstractObject * c = new Circle(app_time, velocity, position, radius, mass);
  object_container_.push_back(c);

}
void Scene::update() {
  for (auto &o : object_container_) {
    o->update();
  }
  object_container_.front()->update();
}
void Scene::draw() {
  for (auto &o : object_container_){
    o->draw();
  }
}
