//
//  app_time.h
//  2DCollision
//
//  Created by OSAWASatoru on 6/17/17.
//
//

#pragma once
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
