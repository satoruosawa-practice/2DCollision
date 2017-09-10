#pragma once

#include "ofMain.h"
//#include "./global_definition.h"
#include "./app_time.h"
//#include "./scene.h"
//#include "./sphere.h"

#include "./scene.h"


class ofApp : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  AppTime app_time_;
//  Scene scene_;
//  vector<Sphere> spheres_;
  
  Scene scene_;
};
