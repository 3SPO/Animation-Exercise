//
//  Bubble.cpp
//  learning_Bubbles
//
//  Created by Alex C Esposito on 4/15/15.
//
//

#include "Bubble.h"

Bubble::Bubble() {
    //creates the variables used in the bubble class
    pos = ofVec2f(ofGetMouseX(), ofGetMouseY()) ;
    vel = ofVec2f(ofRandom(-3,3),ofRandom(-4,4)) ;
    rad = 15 ;
    rad2 = 1 ;
    ofColor(255,255,255) ;
}

//actually creates a vector point for the bubble
void Bubble::setup(float _x, float _y) {
    pos = ofVec2f(_x, _y) ;
}

//animates the bubble
void Bubble::update() {
    pos += vel ;
}


//There are two draw functions for both circles and squares
void Bubble::drawCircle() {
    //circles
    ofSetColor(color) ;
    ofCircle(pos, rad) ;
}

void Bubble::drawRect() {
    //squares
    ofSetColor(color) ;
    ofRect(pos, rad2, rad2) ;
}

