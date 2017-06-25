//
//  app_time.cpp
//  2DCollision
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#include "./app_time.h"

void AppTime::setup() {
  elapsed_time_ = ofGetElapsedTimeMillis();
  last_elapsed_time_ = elapsed_time_;
}

void AppTime::update() {
  last_elapsed_time_ = elapsed_time_;
  elapsed_time_ = ofGetElapsedTimeMillis();
}
