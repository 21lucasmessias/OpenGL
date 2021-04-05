#include "myproject.hpp"

using namespace std;

void handleRenderProject() {
	if (states.exercise == EXERCISE_1) {
		const GLfloat radius = 55.0f;

		GLfloat camX = ((GLfloat)sin(glfwGetTime())) * 1.2f * radius + 50.0f;
		GLfloat camY = ((GLfloat)cos(glfwGetTime())) * radius;

		objects_transformations[0].translation[0] = camX;
		objects_transformations[0].translation[1] = camY;
	}
	
	else if (states.exercise == EXERCISE_3) {
		if (objects_transformations[0].translation[0] == 70.0f || objects_transformations[0].translation[0] == 10.0f) {
			states.offset_x_1 = states.offset_x_1 * -1;
		}

		if (objects_transformations[0].translation[1] == 50.0f || objects_transformations[0].translation[1] == 10.0f) {
			states.offset_y_1 = states.offset_y_1 * -1;
		}

		if (objects_transformations[1].translation[0] == 70.0f || objects_transformations[1].translation[0] == 10.0f) {
			states.offset_x_2 = states.offset_x_2 * -1;
		}

		if (objects_transformations[1].translation[1] == 50.0f || objects_transformations[1].translation[1] == 10.0f) {
			states.offset_y_2 = states.offset_y_2 * -1;
		}

		objects_transformations[0].translation[0] = objects_transformations[0].translation[0] + 1.0f * states.offset_x_1;
		objects_transformations[0].translation[1] = objects_transformations[0].translation[1] + 1.0f * states.offset_y_1;

		objects_transformations[1].translation[0] = objects_transformations[1].translation[0] + 1.0f * states.offset_x_2;
		objects_transformations[1].translation[1] = objects_transformations[1].translation[1] + 1.0f * states.offset_y_2;
	}

	else if (states.exercise == EXERCISE_4) {
		GLfloat offsetX = abs((GLfloat)cos((float)objects_transformations[0].rotation.radians / 10 - 9.0)) * (GLfloat)sqrt(200) / 10.0f;
		GLfloat offsetY = abs((GLfloat)sin((float)objects_transformations[0].rotation.radians / 10 - 9.0)) * (GLfloat)sqrt(200) / 10.0f;

		if ((offsetX + objects_transformations[0].translation[0]) > 70.0f || (objects_transformations[0].translation[0] - offsetX) < 10.0f) {
			states.offset_x_1 = states.offset_x_1 * -1;
		}

		if ((offsetY + objects_transformations[0].translation[1]) > 50.0f || (objects_transformations[0].translation[1] - offsetY) < 10.0f) {
			states.offset_y_1 = states.offset_y_1 * -1;
		}

		objects_transformations[0].translation[0] = objects_transformations[0].translation[0] + 1.0f * states.offset_x_1;
		objects_transformations[0].translation[1] = objects_transformations[0].translation[1] + 1.0f * states.offset_y_1;
		objects_transformations[0].rotation.radians = objects_transformations[0].rotation.radians + 2.5f;

		if (objects_transformations[0].rotation.radians == 360.0f) {
			objects_transformations[0].rotation.radians = 0.0f;
		}

	}

	else if (states.exercise == EXERCISE_5) {
		if (objects_transformations[0].translation[0] == 65.0f || objects_transformations[0].translation[0] == 15.0f) {
			states.offset_x_1 = states.offset_x_1 * -1;
		}

		if (objects_transformations[0].translation[1] == 45.0f || objects_transformations[0].translation[1] == 15.0f) {
			states.offset_y_1 = states.offset_y_1 * -1;
		}

		objects_transformations[0].translation[0] = objects_transformations[0].translation[0] + 1.0f * states.offset_x_1;
		objects_transformations[0].translation[1] = objects_transformations[0].translation[1] + 1.0f * states.offset_y_1;
	}

	else if (states.exercise == EXERCISE_6) {
		if (objects_transformations[0].translation[0] == 85.0f || objects_transformations[0].translation[0] == 15.0f) {
			states.offset_x_1 = states.offset_x_1 * -1;
		}

		objects_transformations[0].translation[0] = objects_transformations[0].translation[0] + 1.0f * states.offset_x_1;
	}

	else if (states.exercise == EXERCISE_7) {
		if (objects_transformations[2].translation[1] == 90.0f + SPEED_PLAYER) {
			objects_transformations[2].translation[1] = 90.0f;
		}
		else if (objects_transformations[2].translation[1] == 10.0f - SPEED_PLAYER) {
			objects_transformations[2].translation[1] = 10.0f;
		}

		if (objects_transformations[3].translation[1] == 90.0f + SPEED_PLAYER) {
			objects_transformations[3].translation[1] = 90.0f;
		}
		else if (objects_transformations[3].translation[1] == 10.0f - SPEED_PLAYER) {
			objects_transformations[3].translation[1] = 10.0f;
		}


		//colision with wall
		if (objects_transformations[4].translation[1] == 365.0f || objects_transformations[4].translation[1] == 35.0f) {
			states.offset_y_1 = states.offset_y_1 * -1;
		}

		//colision with rackets 
		if (objects_transformations[2].translation[0] == objects_transformations[4].translation[0] - 40.0f &&
			objects_transformations[4].translation[1] + 10.0f >= (objects_transformations[2].translation[1] - 5.0f) * 4 &&
			objects_transformations[4].translation[1] - 10.0f <= (objects_transformations[2].translation[1] + 5.0f) * 4 ) {
			states.offset_x_1 = states.offset_x_1 * -1;
		}

		else if (objects_transformations[3].translation[0] == objects_transformations[4].translation[0] - 260.0f &&
			objects_transformations[4].translation[1] + 10.0f >= (objects_transformations[3].translation[1] - 5.0f) * 4 &&
			objects_transformations[4].translation[1] - 10.0f <= (objects_transformations[3].translation[1] + 5.0f) * 4) {
			states.offset_x_1 = states.offset_x_1 * -1;
		}

		//points
		if (objects_transformations[4].translation[0] == 0.0f) {
			states.player_2_points = states.player_2_points + 1;
			cout << "Player 2 did it!" << endl;

			objects_transformations[4].translation[0] = 200.0f;
			objects_transformations[4].translation[1] = 200.0f;

			states.offset_x_1 = states.offset_x_1 * -1;
		}
		else if (objects_transformations[4].translation[0] == 400.0f) {
			states.player_1_points = states.player_1_points + 1;
			cout << "Player 1 did it!" << endl;

			objects_transformations[4].translation[0] = 200.0f;
			objects_transformations[4].translation[1] = 200.0f;

			states.offset_x_1 = states.offset_x_1 * -1;
		}

		objects_transformations[4].translation[0] = objects_transformations[4].translation[0] + 1.0f * states.offset_x_1;
		objects_transformations[4].translation[1] = objects_transformations[4].translation[1] + 1.0f * states.offset_y_1;
	}
}

void bufferSun() {
	GLint PRECISION_CIRCLE = 32, i;
	GLfloat raio = 15.0f;
	GLfloat x, y, z, r, g, b;

	r = 1.0f;
	g = 1.0f;
	b = 0.0f;

	for (i = 0; i < PRECISION_CIRCLE; i++) {

		x = (GLfloat)((GLint)(cos((3.1415926 * 2 / PRECISION_CIRCLE) * i) * raio * 100) / 100.0);
		y = (GLfloat)((GLint)(sin((3.1415926 * 2 / PRECISION_CIRCLE) * i) * raio * 100) / 100.0);
		z = -1.0f;

		objects[INDEX_SUN].vertices.push_back(x);
		objects[INDEX_SUN].vertices.push_back(y);
		objects[INDEX_SUN].vertices.push_back(z);

		objects[INDEX_SUN].colors.push_back(r);
		objects[INDEX_SUN].colors.push_back(g);
		objects[INDEX_SUN].colors.push_back(b);
	};

	for (i = 1; i < PRECISION_CIRCLE-1; i++) {
		objects[INDEX_SUN].indexs.push_back(0);
		objects[INDEX_SUN].indexs.push_back(i);
		objects[INDEX_SUN].indexs.push_back(i+1);
	}
}

void updateOriginToCenter() {
	GLfloat middle_horizontal = 0;
	GLfloat middle_vertical = 0;
	GLuint v;

	for (GLuint i = 0; i < objects.size(); i++) {
		middle_horizontal = 0;
		middle_vertical = 0;

		for (v = 0; v < objects[i].vertices.size(); v++) {
			if ((v + 1) % 3 == 1) {
				if (objects[i].vertices[v] > middle_horizontal) {
					middle_horizontal = objects[i].vertices[v];
				}
			}
			if ((v + 1) % 3 == 2) {
				if (objects[i].vertices[v] > middle_vertical) {
					middle_vertical = objects[i].vertices[v];
				}
			}
		}

		middle_horizontal = middle_horizontal/2;
		middle_vertical = middle_vertical/2;

		for (v = 0; v < objects[i].vertices.size(); v++) {
			if ((v + 1) % 3 == 1) {
				objects[i].vertices[v] = objects[i].vertices[v] - middle_horizontal;
			}
			else if ((v + 1) % 3 == 2) {
				objects[i].vertices[v] = objects[i].vertices[v] - middle_vertical;
			}
		}
	}
}

void processProject() {
	bufferSun();

	if (states.exercise == EXERCISE_1) {
		objects_transformations.push_back({ INDEX_SUN,		vec3(0.0f, 50.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });

		objects_transformations.push_back({ INDEX_BODY,		vec3(15.0f, 10.0f, 1.0f),	{vec3( 0.0f, 0.0f, 1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
		objects_transformations.push_back({ INDEX_ROOF,		vec3(15.0f,	25.0f, 1.0f),	{vec3( 0.0f, 0.0f, 1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
		objects_transformations.push_back({ INDEX_DOOR,		vec3(20.0f, 5.0f, 1.0f),	{vec3( 0.0f, 0.0f, 1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(10.0f, 14.5f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(0.75f,0.75f,0.75f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(20.0f,	14.5f, 1.0f),	{vec3( 0.0f, 0.0f, 1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
																	
		objects_transformations.push_back({ INDEX_BODY,		vec3(40.0f, 10.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_ROOF,		vec3(40.0f, 25.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_DOOR,		vec3(45.0f, 5.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(45.0f, 14.5f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(35.0f, 14.5f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });

		objects_transformations.push_back({ INDEX_BODY,		vec3(50.0f, 10.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f },	vec3(1.25f,1.25f,1.25f) });
		objects_transformations.push_back({ INDEX_ROOF,		vec3(50.0f, 25.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.25f,1.25f,1.25f) });
		objects_transformations.push_back({ INDEX_DOOR,		vec3(55.0f, 5.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.25f,1.25f,1.25f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(55.0f, 14.5f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.25f,1.25f,1.25f) });
		objects_transformations.push_back({ INDEX_WINDOW,	vec3(45.0f, 14.5f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.25f,1.25f,1.25f) });
	}

	else if (states.exercise == EXERCISE_2) {
		objects_transformations.push_back({ INDEX_BODY,		vec3(10.0f, 10.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
	}

	else if (states.exercise == EXERCISE_3) {
		objects_transformations.push_back({ INDEX_BODY,		vec3(11.0f, 11.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_BODY,		vec3(69.0f, 11.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
	}

	else if (states.exercise == EXERCISE_4) {
		objects_transformations.push_back({ INDEX_BODY,		vec3(11.0f, 11.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
	}

	else if (states.exercise == EXERCISE_5) {
		objects_transformations.push_back({ INDEX_SUN,		vec3(16.0f, 16.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
	}

	else if (states.exercise == EXERCISE_6) {
		objects_transformations.push_back({ INDEX_SUN,		vec3(16.0f, 15.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
	}

	else if (states.exercise == EXERCISE_7) {
		objects_transformations.push_back({ INDEX_WALL,		vec3(50.0f, 0.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_WALL,		vec3(50.0f, 100.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_RACKET,	vec3(5.0f,  50.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });
		objects_transformations.push_back({ INDEX_RACKET,	vec3(95.0f, 50.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(1.0f,1.0f,1.0f) });

		objects_transformations.push_back({ INDEX_SUN,		vec3(200.0f, 200.0f, 1.0f),	{vec3(0.0f, 0.0f, 1.0f), 0.0f},		vec3(0.5f,0.5f,1.0f) });
	}

}																  

