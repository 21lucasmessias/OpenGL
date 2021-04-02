#include <iostream>
#include "objects.hpp"

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

void processProject() {
	bufferSun();

	objects_transformations.push_back({ INDEX_SUN,		vec3(0.0f, 50.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.0f,1.0f,1.0f) });

	objects_transformations.push_back({ INDEX_BODY,		vec3(5.0f,  0.0f,  1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
	objects_transformations.push_back({ INDEX_ROOF,		vec3(5.0f,  20.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
	objects_transformations.push_back({ INDEX_DOOR,		vec3(17.0f, 0.0f,  1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
	objects_transformations.push_back({ INDEX_WINDOW,	vec3(17.0f, 12.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });
	objects_transformations.push_back({ INDEX_WINDOW,	vec3(8.0f,  12.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(0.75f,0.75f,0.75f) });

	objects_transformations.push_back({ INDEX_BODY,		vec3(30.0f,  0.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.0f,1.0f,1.0f) });
	objects_transformations.push_back({ INDEX_ROOF,		vec3(30.0f, 20.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.0f,1.0f,1.0f) });
	objects_transformations.push_back({ INDEX_DOOR,		vec3(42.0f,  0.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.0f,1.0f,1.0f) });
	objects_transformations.push_back({ INDEX_WINDOW,	vec3(42.0f, 12.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.0f,1.0f,1.0f) });
	objects_transformations.push_back({ INDEX_WINDOW,	vec3(33.0f, 12.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.0f,1.0f,1.0f) });

	objects_transformations.push_back({ INDEX_BODY,		vec3(40.0f,  0.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.25f,1.25f,1.25f) });
	objects_transformations.push_back({ INDEX_ROOF,		vec3(40.0f, 20.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.25f,1.25f,1.25f) });
	objects_transformations.push_back({ INDEX_DOOR,		vec3(52.0f,  0.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.25f,1.25f,1.25f) });
	objects_transformations.push_back({ INDEX_WINDOW,	vec3(52.0f, 12.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.25f,1.25f,1.25f) });
	objects_transformations.push_back({ INDEX_WINDOW,	vec3(43.0f, 12.0f, 1.0f),	{vec3(0.0f,0.0f,1.0f), 0.0f},	vec3(1.25f,1.25f,1.25f) });
}

