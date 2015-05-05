#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //set up all if the necessary variables for the code
    ofSetCircleResolution(50) ;
    ofSetFrameRate(60) ;
    drawing = false ;
    //load the image and size it properly
    image.loadImage("lightbike.png") ;
    image.resize(150,100) ;
    vel = 10 ;
    posX = 900 ;
    trailColor.setHsb(ofRandom(255),255,255) ;
}

//--------------------------------------------------------------
void ofApp::update(){
    //creates the squares and animates them to come out from the center and move to the edges of the screen
    ofBackground(255) ;
    Bubble tempBubble2 ;
    tempBubble2.color.setHsb(255,255,255) ;
    tempBubble2.pos = ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2) ;
    bubbles2.push_back(tempBubble2) ;
    for(int i=0;i<bubbles2.size();i++) {
        //calculates distance from the center
        float distance = ofDist(512, 384, bubbles2[i].pos.x, bubbles2[i].pos.y) ;
        bubbles2[i].color.setHue(ofMap(distance, 0, 450, 0, 255)) ;
        bubbles2[i].color.setSaturation(ofMap(distance, 0, 450, 0, 255)) ;
        bubbles2[i].rad2 = (ofMap(distance, 0, 650, 1, 50)) ;
        //deletes the bubbles once they leave the screen
        if (distance >= 650) bubbles2.erase(bubbles2.begin() + i) ;
        bubbles2[i].update() ;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Draws the bubbles
    for(int i=0;i<bubbles2.size();i++) {
        bubbles2[i].drawRect() ;
    }
    //draws the lightbike if the 'd' key is pressed
    if(drawing == true) {
        posX = posX - vel ;
        ofPoint point = ofPoint(posX, posY) ;
        image.draw(point) ;
        ofSetColor(trailColor) ;
        ofRect(point.x + 136, point.y +45, 10000,30) ;
    }
}

//creates the 'd' keypressed function
void ofApp::keyPressed(int key){
    if(key == 'd') {
        drawing = true ;
    }
}

//allows the lightbike to go away when not pressed
void ofApp::keyReleased(int key) {
    if(key == 'd') {
        //changes the color of the trail and position of the bike with every new press
        trailColor.setHsb(ofRandom(255),255,255) ;
        posX = 1000 ;
        posY = ofRandom(30, 720) ;
        drawing = false ;
    }
}
