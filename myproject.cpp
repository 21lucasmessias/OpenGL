#include "myproject.hpp"

using namespace std;

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

	for (int i = 0; i < objects.size(); i++) {
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

	updateOriginToCenter();

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

