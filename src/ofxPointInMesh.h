#pragma once

#include "ofMain.h"

class ofxPointInMesh {

	public:
		static bool isInside(const ofVec3f & point, const ofMesh & mesh);

	private:
		static bool triangleIntersection(const ofMeshFace & face, const ofVec3f & O, const ofVec3f & D, ofVec3f & R);
};
