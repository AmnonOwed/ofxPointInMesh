ofxPointInMesh
==============

Introduction
------------
A straightforward C++ openFrameworks addon to check if a 3D point ([ofVec3f](http://www.openframeworks.cc/documentation/math/ofVec3f.html)) is inside a closed 3D [ofMesh](http://openframeworks.cc/documentation/3d/ofMesh.html).
To determine this, it uses the [Möller–Trumbore ray-triangle intersection algorithm](http://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm).

Usage
-----
Use ofxPointInMesh's static method by passing a point and a mesh as arguments:

```cpp
bool isInside = ofxPointInMesh::isInside(thePoint, theMesh);
```

Also see the examples. Project files for Windows Code::Blocks are included.
You can use openFrameworks' ProjectGenerator to generate project files for other IDE's.

Author
------
Created by [Amnon Owed](http://vimeo.com/amnon) / [@AmnonOwed](https://twitter.com/AmnonOwed)

License
-------
Distributed under the [MIT License](https://en.wikipedia.org/wiki/MIT_License).

Installation
------------
Download/clone the addon into the `openFrameworks/addons/` folder.

Dependencies
------------
None.

Compatibility
------------
Developed under OF 0.8.4.

Known issues
------------
The ofMesh mode must be OF_PRIMITIVE_TRIANGLES to use this addon.
Assumes, but doesn't check, it is a closed 3D mesh.
For bugs, please use [this repository's issue tracker](https://github.com/AmnonOwed/ofxPointInMesh/issues).

Version history
------------

### Version 0.1.0 (17.04.2015):
- Initial version
- Supports a single point-in-mesh method
- Includes two examples (pointsInBox and pointsInSphere)
