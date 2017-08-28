#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
//  ofSetVerticalSync(false);
//  ofSetFrameRate(0);
  ofBackground(220);
  ofEnableSmoothing();
  
  scene_.setup();
  app_time_.setup();
  for (int i = 0; i < 800; i++) {
    float amp = 0.0;
    float angle = ofRandom(0.0, 2 * PI);
    ofVec2f velocity = amp * ofVec2f(cos(angle), sin(angle));
    ofVec2f position = ofVec2f(ofRandom(ofGetWidth() /
                                        static_cast<float>(PX_PER_METER)),
                               ofRandom(ofGetHeight() /
                                        static_cast<float>(PX_PER_METER)));
    float radius = ofRandom(0.02, 0.05);  // m
//    float radius = 0.2;  // m
//    float mass = ofRandom(1.0, 10.0);
    float mass = radius * radius * 10000.0;  // kg
    Sphere s = Sphere(app_time_, velocity, position, radius, mass);
    spheres_.push_back(s);
  }
  
//   super
  {
  float amp = 20.0;
  float angle = ofRandom(0.0, 2 * PI);
  ofVec2f velocity = amp * ofVec2f(cos(angle), sin(angle));
  ofVec2f position = ofVec2f(ofRandom(ofGetWidth() /
                                      static_cast<float>(PX_PER_METER)),
                             ofRandom(ofGetHeight() /
                                      static_cast<float>(PX_PER_METER)));
  float radius = 0.3;  //m
  float mass = radius * radius * 1000000.0;  // kg
  Sphere s = Sphere(app_time_, velocity, position, radius, mass);
  s.setSuperBall(true);
  spheres_.push_back(s);
  }

  // super (heavy)
  int array = 10;
  for (int i = 0; i < array; i++) {
      float amp = 0.0;
      float angle = ofRandom(0.0, 2 * PI);
      ofVec2f velocity = amp * ofVec2f(cos(angle), sin(angle));
      float rad = ofGetWidth() / static_cast<float>(PX_PER_METER) * 0.2;
      ofVec2f position = ofVec2f(ofGetWidth() /
                                 static_cast<float>(PX_PER_METER) * 0.5
                                 + rad * cos(2.0 * PI *
                                             static_cast<float>(i) /
                                             static_cast<float>(array)),
                                 ofGetWidth() /
                                 static_cast<float>(PX_PER_METER) * 0.5
                                 + rad * sin(2.0 * PI *
                                             static_cast<float>(i) /
                                             static_cast<float>(array)));
      float radius = 0.4;  //m
      float mass = radius * radius * 10000000000.0;  // kg
      Sphere s = Sphere(app_time_, velocity, position, radius, mass);
      s.setSuperBall(true);
      spheres_.push_back(s);
    
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  app_time_.update();
  for (Sphere &s : spheres_) {
    s.resetForce();
    s.update();
  }
  for (Sphere &s : spheres_) {
    scene_.updateSingle(&s);
  }
  for (int i = 0; i < spheres_.size(); i++) {
    for (int j = 0; j < i; j++) {
      scene_.updateMutual(&spheres_[i], &spheres_[j]);
    }
  }

}

//--------------------------------------------------------------
void ofApp::draw() {
//  ofDrawGrid(PX_PER_METER, 11, false, false, false, true);
  for (Sphere &s : spheres_){
    s.draw();
  }
  ofSetColor(10, 10, 10, 255);
  ofDrawBitmapString("frameRate: " + ofToString(ofGetFrameRate(), 1) + " fps",
                     10, 20);
  ofDrawBitmapString("time: " + ofToString(app_time_.getElapsedTimeS(), 1) +
                     " s", 200, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
