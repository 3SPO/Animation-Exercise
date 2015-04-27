#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50) ;
    ofSetFrameRate(60) ;
    drawing = false ;
    image.loadImage("lightbike.png") ;
    image.resize(150,100) ;
    vel = 10 ;
    posX = 900 ;
    trailColor.setHsb(ofRandom(255),255,255) ;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255) ;
    Bubble tempBubble2 ;
    tempBubble2.color.setHsb(255,255,255) ;
    tempBubble2.pos = ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2) ;
    bubbles2.push_back(tempBubble2) ;
    for(int i=0;i<bubbles2.size();i++) {
        float distance = ofDist(512, 384, bubbles2[i].pos.x, bubbles2[i].pos.y) ;
        bubbles2[i].color.setHue(ofMap(distance, 0, 450, 0, 255)) ;
        bubbles2[i].color.setSaturation(ofMap(distance, 0, 450, 0, 255)) ;
        bubbles2[i].rad2 = (ofMap(distance, 0, 650, 1, 50)) ;
        if (distance >= 650) bubbles2.erase(bubbles2.begin() + i) ;
        bubbles2[i].update() ;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<bubbles2.size();i++) {
        bubbles2[i].drawRect() ;
    }
    if(drawing == true) {
        posX = posX - vel ;
        ofPoint point = ofPoint(posX, posY) ;
        image.draw(point) ;
        ofSetColor(trailColor) ;
        ofRect(point.x + 136, point.y +45, 10000,30) ;
    }
}

void ofApp::keyPressed(int key){
    if(key == 'd') {
        drawing = true ;
    }
}

void ofApp::keyReleased(int key) {
    if(key == 'd') {
        trailColor.setHsb(ofRandom(255),255,255) ;
        posX = 1000 ;
        posY = ofRandom(30, 720) ;
        drawing = false ;
    }
}
