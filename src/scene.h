//
//  scene.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef SCENE_H_
#define SCENE_H_

#include <vector>
#include <typeinfo>
#include <string>
#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"
#include "./circle.h"
#include "./circle_bounce_on_frame.h"
#include "./circle_passing_on_frame.h"
#include "./mutual_collision.h"
#include "./damping_force.h"
#include "./directional_force.h"
#include "./radial_force.h"

class Scene {
 public:
  Scene();
  void setup(const AppTime &app_time);
  void update();
  void draw();
  void mouseMoved(int x, int y);

 private:
  const AppTime * app_time_;
  vector<AbstractObject*> object_container_;
  vector<AbstractFieldForce*> field_force_container_;
  vector<AbstractFieldCollision*> field_collision_container_;

  string radial_force_nema_;
};

#endif  // SCENE_H_
