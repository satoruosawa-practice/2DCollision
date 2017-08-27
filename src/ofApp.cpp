#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
//  ofSetVerticalSync(false);
//  ofSetFrameRate(0);
  ofBackground(220);
  
  scene_.setup();
  app_time_.setup();
  for (int i = 0; i < 1000; i++) {
    ofVec2f velocity = 3.0 * ofVec2f(0.0, 0.0);
    ofVec2f position = ofVec2f(ofRandom(ofGetWidth() /
                                        static_cast<float>(PX_PER_METER)),
                               ofRandom(ofGetHeight() /
                                        static_cast<float>(PX_PER_METER)));
    float radius = ofRandom(0.05, 0.1);  // m
//    float radius = 0.2;  // m
//    float mass = ofRandom(1.0, 10.0);
    float mass = radius * radius * 10000.0;  // kg
    Sphere s = Sphere(app_time_, velocity, position, radius, mass);
    spheres_.push_back(s);
  }
  
  // super
  float angle = ofRandom(0.0, 2 * PI);
  ofVec2f velocity = 10.0 * ofVec2f(1.0 * cos(angle), 1.0 * sin(angle));
  ofVec2f position = ofVec2f(ofRandom(ofGetWidth() /
                                      static_cast<float>(PX_PER_METER)),
                             ofRandom(ofGetHeight() /
                                      static_cast<float>(PX_PER_METER)));
  float radius = 0.2;  //m
  float mass = radius * radius * 100000000.0;  // kg
  Sphere s = Sphere(app_time_, velocity, position, radius, mass);
  spheres_.push_back(s);
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
