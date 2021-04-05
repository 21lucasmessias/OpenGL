#ifndef OBJECTS_H
#define OBJECTS_H

#include "main.hpp"

#define INDEX_BODY 0
#define INDEX_ROOF 1
#define INDEX_DOOR 2
#define INDEX_WINDOW 3
#define INDEX_SUN 4
#define INDEX_RACKET 5
#define INDEX_WALL 6

using namespace std;
using namespace glm;

struct ObjectProperties {
	vector<GLfloat> vertices;
	vector<GLushort> indexs;
	vector<GLfloat> colors;
};

struct RotationObject {
	vec3 vec;
	GLfloat radians;
};

struct ObjectTransformations {
	GLushort index;
	vec3 translation;
	RotationObject rotation;
	vec3 scaling;
};

extern vector<ObjectProperties> objects;
extern vector<ObjectTransformations> objects_transformations;

#endif