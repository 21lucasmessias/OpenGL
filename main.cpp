#include <Windows.h>
#include <iostream>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "states.hpp"
#include "objects.hpp"

#include "myproject.hpp"

using namespace std;
using namespace glm;

const char* TITLE = "Teste";
const int WIDTH = 800;
const int HEIGHT = 800;
GLFWwindow* window = NULL;
const GLfloat color[] = { 0.0f, 0.8f, 0.8f, 1.0f };

States states;

GLuint program;
GLuint vertex_array_object;
GLuint vertex_buffer_object;
GLuint vertex_buffer_object_index;
GLuint vertex_buffer_object_colors;

mat4 valueptr;
GLuint matrix;
GLint modelLoc;
mat4 projection = ortho(-50.0f, 50.0f, -50.0f, 50.0f, -5.0f, 5.0f);

int initalization() {
	if (!glfwInit()) {
		cerr << "GLFW inicialization failed" << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

	if (window == NULL) {
		cerr << "Error" << endl;
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		cerr << "Error" << endl;
		glfwTerminate();
		return 1;
	}

	return 0;
}

void verifyError(GLuint who, int type, const char* msg) {
	GLint success;
	GLchar info_log[512];

	glGetShaderiv(who, type, &success);

	if (!success) {
		glGetShaderInfoLog(who, 512, NULL, info_log);
		cout << msg << endl;
	}
}

void compileShaders() {
	GLuint vertex_shader;
	GLuint fragment_shader;

	static const char* vertex_shader_source[] = {
		"#version 450 core																	\n"
		"layout (location = 0) in vec3 pos;													\n"
		"layout (location = 1) in vec3 color; 												\n"
		"																					\n"
		"uniform mat4 projection; 															\n"
		"uniform mat4 translate;															\n"
		"uniform mat4 rotation;																\n"
		"uniform mat4 scaling;																\n"
		"																					\n"
		"out vec3 vs_color;  																\n"
		"																					\n"
		"void main(void) {					 												\n"
		"	gl_Position = projection * translate * scaling * vec4(pos, 1.0);		\n"
		"	vs_color = color;																\n"
		"}																					\n"
	};

	static const char* fragment_shader_source[] = {
		"#version 450 core					\n"
		"									\n"
		"in vec3 vs_color;					\n"
		"out vec4 color;					\n"
		"									\n"
		"void main(void) {					\n"
		"	color = vec4(vs_color, 1.0);	\n"
		"}									\n"
	};

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	verifyError(vertex_shader, GL_COMPILE_STATUS, "vertexShader");

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	verifyError(fragment_shader, GL_COMPILE_STATUS, "fragmentShader");

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	verifyError(program, GL_LINK_STATUS, "program");

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
}

void draw(vector<GLfloat> vertices, GLsizeiptr size_vertices, GLuint vbo_vertices,
		  vector<GLfloat> colors,   GLsizeiptr size_colors,   GLuint vbo_colors,
		  vector<GLushort> index,	GLsizeiptr size_index,    GLuint vbo_vertices_index,
		  GLenum type, GLsizei count) {
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, size_vertices, vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_colors);
	glBufferData(GL_ARRAY_BUFFER, size_colors, colors.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_vertices_index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_index, index.data(), GL_STATIC_DRAW);

	
	glDrawElements(type, count, GL_UNSIGNED_SHORT, 0);
}

void render() {
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, value_ptr(projection));

	GLuint j;

	for (GLuint i = 0; i < objects_transformations.size(); i++) {
		valueptr = mat4(1.0f);

		j = objects_transformations[i].index;

		matrix = glGetUniformLocation(program, "scaling");
		valueptr = scale(valueptr, objects_transformations[i].scaling);
		glUniformMatrix4fv(matrix, 1, GL_FALSE, value_ptr(valueptr));

		matrix = glGetUniformLocation(program, "translate");
		valueptr = translate(valueptr, objects_transformations[i].translation * objects_transformations[i].scaling);
		glUniformMatrix4fv(matrix, 1, GL_FALSE, value_ptr(valueptr));

		matrix = glGetUniformLocation(program, "rotation");
		valueptr = rotate(valueptr, radians(objects_transformations[i].rotation.radians), objects_transformations[i].rotation.vec);
		glUniformMatrix4fv(matrix, 1, GL_FALSE, value_ptr(valueptr));

		draw(objects[j].vertices, sizeof(objects[j].vertices) * 4, vertex_buffer_object,
			objects[j].colors, sizeof(objects[j].colors) * 4, vertex_buffer_object_colors,
			objects[j].indexs, sizeof(objects[j].indexs), vertex_buffer_object_index,
			GL_TRIANGLES, objects[j].indexs.size());

	
	}
}

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_TAB: {
			if (states.wireframe)
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			else
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

			states.wireframe = !states.wireframe;

			break;
		}

		case GLFW_KEY_ESCAPE: {
			glfwSetWindowShouldClose(window, true);

			break;
		}

		case GLFW_KEY_B: {
			//states.showBody = !states.showBody;

			for (GLuint i = 0; i < objects_transformations.size(); i++) {
				if (objects_transformations[i].index == INDEX_BODY) {
					objects_transformations.erase(objects_transformations.begin() + i);
					i--;
				}
			}

			break;
		}

		case GLFW_KEY_R: {
			//states.showRoof = !states.showRoof;

			for (GLuint i = 0; i < objects_transformations.size(); i++) {
				if (objects_transformations[i].index == INDEX_ROOF) {
					objects_transformations.erase(objects_transformations.begin() + i);
					i--;
				}
			}

			break;
		}

		case GLFW_KEY_W: {
			//states.showWindows = !states.showWindows;

			for (GLuint i = 0; i < objects_transformations.size(); i++) {
				if (objects_transformations[i].index == INDEX_WINDOW) {
					objects_transformations.erase(objects_transformations.begin() + i);
					i--;
				}
			}

			break;
		}

		case GLFW_KEY_D: {
			//states.showDoor = !states.showDoor;

			for (GLuint i = 0; i < objects_transformations.size(); i++) {
				if (objects_transformations[i].index == INDEX_DOOR) {
					objects_transformations.erase(objects_transformations.begin() + i);
					i--;
				}
			}

			break;
		}
		default:
			break;

		}
	}
}

void startup() {
	compileShaders();

	glfwSetKeyCallback(window, processInput);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glGenVertexArrays(1, &vertex_array_object);
	glBindVertexArray(vertex_array_object);

	glGenBuffers(1, &vertex_buffer_object);
	glGenBuffers(1, &vertex_buffer_object_colors);
	glGenBuffers(1, &vertex_buffer_object_index);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	modelLoc = glGetUniformLocation(program, "projection");
	glUseProgram(program);
}

void shutdown() {
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glDeleteProgram(program);
	glDeleteVertexArrays(1, &vertex_array_object);
	glfwTerminate();
}

int main() {
	if (initalization()) {
		return -1;
	}

	startup();

	processProject(states);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearBufferfv(GL_COLOR, 0, color);

		render();

		glfwSwapBuffers(window);
	}

	shutdown();

	return 0;
}