//
//  app_time.cpp
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
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
