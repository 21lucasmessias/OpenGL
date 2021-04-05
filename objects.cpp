#include "objects.hpp"

vector<GLfloat> body{
	0.0f,  0.0f,  1.0f,
	20.0f, 0.0f,  1.0f,
	20.0f, 20.0f, 1.0f,
	0.0f,  20.0f, 1.0f,
};

vector<GLushort> body_index{
	0, 1, 2,
	0, 2, 3,
	4, 5, 6,
};

vector<GLfloat> body_color{
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
	1.0f,  0.0f,  0.0f,
};

vector<GLfloat> roof{
	0.0f,  0.0f,  1.0f,
	20.0f, 0.0f,  1.0f,
	10.0f, 10.0f, 1.0f
};

vector<GLushort> roof_index{
	0, 1, 2,
};

vector<GLfloat> roof_color{
	0.0f,  0.0f,  1.0f,
	0.0f,  0.0f,  1.0f,
	0.0f,  0.0f,  1.0f,
};

vector<GLfloat> door{
	0.0f,  0.0f,  -1.0f,
	5.0f,  0.0f,  -1.0f,
	5.0f,  10.0f, -1.0f,
	0.0f,  10.0f, -1.0f,
};

vector<GLushort> door_index{
	0, 1, 2,
	0, 2, 3
};

vector<GLfloat> door_color{
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
	0.0f,  1.0f,  0.0f,
};

vector<GLfloat> window_house{
	0.0f,  0.0f, 2.0f,
	5.0f,  0.0f, 2.0f,
	5.0f,  5.0f, 2.0f,
	0.0f,  5.0f, 2.0f,
};				 

vector<GLushort> window_house_index{
	0, 1, 2,
	0, 2, 3
};

vector<GLfloat> window_house_color{
	0.0f,  0.5f,  0.5f,
	0.0f,  0.5f,  0.5f,
	0.0f,  0.5f,  0.5f,
	0.0f,  0.5f,  0.5f,
};

vector<GLfloat> racket{
	0.0f, 0.0f, 1.0f,
	5.0f, 0.0f, 1.0f,
	5.0f, 10.0f, 1.0f,
	0.0f, 10.0f, 1.0f
};

vector<GLushort> racket_index{
	0, 1, 2,
	0, 2, 3
};

vector<GLfloat> racket_color{
	1.0f,  0.5f,  0.5f,
	1.0f,  0.5f,  0.5f,
	1.0f,  0.5f,  0.5f,
	1.0f,  0.5f,  0.5f,
};

vector<GLfloat> wall{
	0.0f, 0.0f, 1.0f,
	100.0f, 0.0f, 1.0f,
	100.0f, 10.0f, 1.0f,
	0.0f, 10.0f, 1.0f
};

vector<GLushort> wall_index{
	0, 1, 2,
	0, 2, 3
};

vector<GLfloat> wall_color{
	0.0f,  0.0f,  0.0f,
	0.0f,  0.0f,  0.0f,
	0.0f,  0.0f,  0.0f,
	0.0f,  0.0f,  0.0f,
};

vector<GLfloat> sun;
vector<GLushort> sun_index;
vector<GLfloat> sun_color;

vector<ObjectProperties> objects {
	{body, body_index, body_color},
	{roof, roof_index, roof_color},
	{door, door_index, door_color},
	{window_house, window_house_index, window_house_color},
	{sun, sun_index, sun_color},
	{racket, racket_index, racket_color},
	{wall, wall_index, wall_color}
};

vector<ObjectTransformations> objects_transformations;