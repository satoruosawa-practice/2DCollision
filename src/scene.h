//
//  scene.h
//  2DCollision
//
//  Created by OSAWASatoru on 2017/09/10.
//
//

#pragma once

#include "ofMain.h"
#include "./global_definition.h"
#include "./app_time.h"
#include "./circle.h"
#include "./circle_bounce_on_frame.h"
#include "./circle_passing_on_frame.h"


class Scene {
 public:
  void setup(const AppTime &app_time);
  void update();
  void draw();

 private:
  const AppTime * app_time_;
  vector<AbstractObject*> object_container_;
};

