#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
//  ofSetVerticalSync(false);
//  ofSetFrameRate(0);
  ofBackground(255);
  ofEnableSmoothing();
  
  app_time_.setup();
  scene_.setup(app_time_);
  
//  scene_.setup();
//  app_time_.setup();
//  int array = 15;
//  for (int i = 0; i < array; i++) {
//    for (int j = 0; j < array; j++) {
//      float radius = 0.01;  // m
//      ofVec2f velocity = ofVec2f(0.0, 0.0);
//      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.0,
//                                 radius * 2.0 * static_cast<float>(j) + 1.0);
//      float mass = radius * radius * radius * 10000.0;  // kg
//      Sphere s = Sphere(app_time_, velocity, position, radius, mass);
//      s.setColor(ofColor(229, 57, 53, 255));
//      spheres_.push_back(s);
//    }
//  }
//  for (int i = 0; i < array; i++) {
//    for (int j = 0; j < array; j++) {
//      float radius = 0.01;  // m
//      ofVec2f velocity = ofVec2f(0.0, 0.0);
//      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.3,
//                                 radius * 2.0 * static_cast<float>(j) + 1.0);
//      float mass = radius * radius * radius * 10000.0;  // kg
//      Sphere s = Sphere(app_time_, velocity, position, radius, mass);
//      s.setColor(ofColor(30, 136, 229, 255));
//      spheres_.push_back(s);
//    }
//  }
//  for (int i = 0; i < array; i++) {
//    for (int j = 0; j < array; j++) {
//      float radius = 0.01;  // m
//      ofVec2f velocity = ofVec2f(0.0, 0.0);
//      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.0,
//                                 radius * 2.0 * static_cast<float>(j) + 1.3);
//      float mass = radius * radius * radius * 10000.0;  // kg
//      Sphere s = Sphere(app_time_, velocity, position, radius, mass);
//      s.setColor(ofColor(124, 179, 66, 255));
//      spheres_.push_back(s);
//    }
//  }
//  for (int i = 0; i < array; i++) {
//    for (int j = 0; j < array; j++) {
//      float radius = 0.01;  // m
//      ofVec2f velocity = ofVec2f(0.0, 0.0);
//      ofVec2f position = ofVec2f(radius * 2.0 * static_cast<float>(i) + 1.3,
//                                 radius * 2.0 * static_cast<float>(j) + 1.3);
//      float mass = radius * radius * radius * 10000.0;  // kg
//      Sphere s = Sphere(app_time_, velocity, position, radius, mass);
//      s.setColor(ofColor(253, 216, 53, 255));
//      spheres_.push_back(s);
//    }
//  }
//  float radius = 0.3;  // m
//  ofVec2f velocity = ofVec2f(1.0, 1.0);
//  ofVec2f position = ofVec2f(5.0, 5.0);
//  float mass = radius * radius * radius * 300.0;  // kg
//  Sphere s = Sphere(app_time_, velocity, position, radius, mass);
//  spheres_.push_back(s);
}

//--------------------------------------------------------------
void ofApp::update() {
  app_time_.update();
//  for (Sphere &s : spheres_) {
//    s.update();
//  }
//  for (Sphere &s : spheres_) {
//    scene_.updateSingle(&s);
//  }
//  for (int i = 0; i < spheres_.size(); i++) {
//    for (int j = 0; j < i; j++) {
//      scene_.updateMutual(&spheres_[i], &spheres_[j]);
//    }
//  }
  scene_.update();

}

//--------------------------------------------------------------
void ofApp::draw() {
////  ofDrawGrid(kPxPerMeter, 11, false, false, false, true);
//  for (Sphere &s : spheres_){
//    s.draw();
//  }
  scene_.draw();
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
