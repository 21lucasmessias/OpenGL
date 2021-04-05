#ifndef PROJECT_H
#define PROJECT_H

#include "main.hpp"

typedef struct States {
	GLuint exercise;
	glm::mat4 projection;

	GLboolean wireframe;
	GLboolean showBody;
	GLboolean showRoof;
	GLboolean showDoor;
	GLboolean showWindows;

	GLuint transformationMode;

	GLfloat offset_x_1;
	GLfloat offset_y_1;
	GLfloat offset_x_2;
	GLfloat offset_y_2;

	GLuint player_1_points;
	GLuint player_2_points;
} States;

extern States states;

#endif