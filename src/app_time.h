//
//  app_time.h
//  2DCollision
//
//  Copyright (C) 2017 satoru osawa
//

#pragma once
#ifndef APP_TIME_H_
#define APP_TIME_H_

#include "ofMain.h"

class AppTime {
 public:
  AppTime() = default;
  void setup();
  void update();
  // getter
  float getElapsedTimeS() const {
    return static_cast<float>(elapsed_time_) * 0.001;
  }
  uint64_t getDeltaTimeMS() const {
    return elapsed_time_ - last_elapsed_time_;
  }
  float getDeltaTimeS() const {
    return static_cast<float>(elapsed_time_ - last_elapsed_time_) * 0.001;
  }

 private:
  uint64_t elapsed_time_;
  uint64_t last_elapsed_time_;
};

#endif  // APP_TIME_H_
