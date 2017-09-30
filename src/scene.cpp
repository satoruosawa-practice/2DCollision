//
//  scene.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#include "./scene.h"

void Scene::setup(const AppTime &app_time) {
  app_time_ = &app_time;
  int array = 10;
  for (int i = 0; i < array; i++) {
    for (int j = 0; j < array; j++) {
      float radius = 0.02;  // m
      ofVec2f velocity = ofVec2f(0.0, 0.0);
      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.0,
                                 radius * 2.0 * static_cast<float>(j) + 1.0);
      float mass = radius * radius * 10000.0;  // kg
      Circle * c = new Circle(app_time, velocity, position, radius, mass);
      c->color(ofColor(229, 57, 53, 255));
      object_container_.push_back(c);
    }
  }
  for (int i = 0; i < array; i++) {
    for (int j = 0; j < array; j++) {
      float radius = 0.02;  // m
      ofVec2f velocity = ofVec2f(0.0, 0.0);
      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.3,
                                 radius * 2.0 * static_cast<float>(j) + 1.0);
      float mass = radius * radius * 10000.0;  // kg
      Circle * c = new Circle(app_time, velocity, position, radius, mass);
      c->color(ofColor(30, 136, 229, 255));
      object_container_.push_back(c);
    }
  }
  for (int i = 0; i < array; i++) {
    for (int j = 0; j < array; j++) {
      float radius = 0.02;  // m
      ofVec2f velocity = ofVec2f(0.0, 0.0);
      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.0,
                                 radius * 2.0 * static_cast<float>(j) + 1.3);
      float mass = radius * radius * 10000.0;  // kg
      Circle * c = new Circle(app_time, velocity, position, radius, mass);
      c->color(ofColor(124, 179, 66, 255));
      object_container_.push_back(c);
    }
  }
  for (int i = 0; i < array; i++) {
    for (int j = 0; j < array; j++) {
      float radius = 0.02;  // m
      ofVec2f velocity = ofVec2f(0.0, 0.0);
      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.3,
                                 radius * 2.0 * static_cast<float>(j) + 1.3);
      float mass = radius * radius * 10000.0;  // kg
      Circle * c = new Circle(app_time, velocity, position, radius, mass);
      c->color(ofColor(253, 216, 53, 255));
      object_container_.push_back(c);
    }
  }

  float radius = 0.3;  // m
  ofVec2f velocity = ofVec2f(4.0, 2.0);
  ofVec2f position = ofVec2f(5.0, 5.0);
  float mass = radius * radius * 10000.0;  // kg
  Circle * c = new Circle(app_time, velocity, position, radius, mass);
//  c->color(ofColor(229, 57, 53, 255));
  object_container_.push_back(c);

  DampingForce * damping = new DampingForce(2);
  field_force_container_.push_back(damping);
//  DirectionalForce * gravity = new DirectionalForce(ofVec2f(0.0, kGravity));
//  field_force_container_.push_back(gravity);
  RadialForce * gravitation = new RadialForce(ofVec2f(ofGetWidth() / 2,
                                                      ofGetHeight() / 2) /
                                              kPxPerMeter, 2, 5);
  field_force_container_.push_back(gravitation);

  CircleBounceOnFrame * b = new CircleBounceOnFrame();
//  CirclePassingOnFrame * b = new CirclePassingOnFrame();
  field_collision_container_.push_back(b);
}

void Scene::update() {
  for (auto &o : object_container_) {
    o->resetForce();
    for (auto &f : field_force_container_) {
      f->updateForce(o);
    }
    o->updatePos();
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
  for (auto &o : object_container_) {
    o->draw();
  }
}
