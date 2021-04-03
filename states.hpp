#ifndef PROJECT_H
#define PROJECT_H

#include "main.hpp"

typedef struct States {
	GLboolean wireframe;
	GLboolean showBody;
	GLboolean showRoof;
	GLboolean showDoor;
	GLboolean showWindows;

	GLuint transformationMode;
} States;

extern States states;

#endif