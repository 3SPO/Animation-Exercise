#pragma once

#include "ofMain.h"
#include "Bubble.h"
#define number 100

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        void keyReleased(int key);

        ofImage image ;
        vector <Bubble> bubbles2 ;
    
        bool drawing ;
        float posX ;
        float posY ;
        float vel ;
        ofColor trailColor ;
    
        
		
};
