#pragma once

#include "ofMain.h"
#include "ofxPointInMesh.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		bool reset;
		float dim;
		ofEasyCam cam;
		int numPoints;
		vector <ofVec3f> points;
		ofMesh mesh;
};
