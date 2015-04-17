#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest(); // enable correct display of 3D geometry

	ofSetFrameRate(60); // cap frameRate to regular speed

	cam.setVFlip(true); // adhere ofEasyCam view to openFrameworks coordinate system

	ofBackground(255); // set background color (repeated each draw cycle)

	reset = true;

	dim = 200;

	numPoints = 250;
	while(points.size() < numPoints){
		points.push_back(ofVec3f(ofRandom(-dim, dim), ofRandom(-dim, dim), ofRandom(-dim, dim)));
	}

	// mesh mode must be OF_PRIMITIVE_TRIANGLES to use the ofxPointInMesh addon
	mesh = ofMesh::sphere(dim, 12, OF_PRIMITIVE_TRIANGLES);

	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update(){
	if(reset){
		for(int i = 0; i < numPoints; i++){
			points[i].set(ofRandom(-dim, dim), ofRandom(-dim, dim), ofRandom(-dim, dim));
		}
		reset = false;
	}
	ofSetWindowTitle("numPoints: " + ofToString(points.size()) + " | fps: " + ofToString((int)ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofPushMatrix();

	for(int i = 0; i < points.size(); i++){
		bool isInside = ofxPointInMesh::isInside(points[i], mesh);
		if(isInside){
			ofSetColor(0, 255, 0);
		}
		else{
			ofSetColor(255, 0, 0);
		}
		ofSphere(points[i], 5);
	}

	ofSetColor(0);
	mesh.drawWireframe();

	ofPopMatrix();
	cam.end();

	ofSetColor(0);
	ofDrawBitmapString("Press space to reset points", 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == ' '){
		reset = true; // set the variable to true to reset the point
	}
}
