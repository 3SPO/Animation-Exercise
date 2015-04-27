//
//  Bubble.h
//  learning_Bubbles
//
//  Created by Alex C Esposito on 4/15/15.
//
//

#ifndef __learning_Bubbles__Bubble__
#define __learning_Bubbles__Bubble__

#include <ofMain.h>

#pragma once

#include "ofMain.h"

class Bubble {
    
public:
    Bubble() ;
    
    void setup(float _x, float _y);
    void update();
    void drawCircle();
    void drawRect() ;
    
    ofVec2f pos ;
    ofVec2f vel ;
    float rad;
    float rad2;
    ofColor color ;
    
    

    
    
};

#endif /* defined(__learning_Bubbles__Bubble__) */
