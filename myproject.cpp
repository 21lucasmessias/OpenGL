#include "objects.hpp"
#include "states.hpp"

void processProject(States states) {
	objects_transformations.clear();

	if (states.exercise == 1) {
		objects_transformations.push_back({ INDEX_BODY,		vec3(0.0f, 0.0f, 0.0f),		vec3(0.0f,0.0f,0.0f),	vec3(0.0f,0.0f,0.0f) });
		objects_transformations.push_back({ INDEX_ROOF,		vec3(0.0f, 20.0f, 0.0f),	vec3(0.0f,0.0f,0.0f),	vec3(0.0f,0.0f,0.0f) });
		objects_transformations.push_back({ INDEX_DOOR,		vec3(12.0f, 0.0f, 0.0f),	vec3(0.0f,0.0f,0.0f),	vec3(0.0f,0.0f,0.0f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(12.0f, 12.0f, 0.0f),	vec3(0.0f,0.0f,0.0f),	vec3(0.0f,0.0f,0.0f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(3.0f, 12.0f, 0.0f),	vec3(0.0f,0.0f,0.0f),	vec3(0.0f,0.0f,0.0f) });
	}



}