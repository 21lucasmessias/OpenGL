#include "hotkeys.hpp"
#include "states.hpp"
#include "objects.hpp"

void processInput(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_SPACE: {
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

		case GLFW_KEY_S: {
			objects_transformations[0].translation[2] = 3.0f;

			break;
		}

		case GLFW_KEY_P: {
			states.transformationType = 'm';

			break;
		}

		case GLFW_KEY_O: {
			states.transformationType = 'r';

			break;
		}

		case GLFW_KEY_I: {
			states.transformationType = 'd';

			break;
		}

		case GLFW_KEY_LEFT: {
			states.offset_h -= 1;

			break;
		}

		case GLFW_KEY_UP: {
			states.offset_v += 1;

			break;
		}

		case GLFW_KEY_DOWN: {
			states.offset_v -= 1;

			break;
		}

		case GLFW_KEY_RIGHT: {
			states.offset_h += 1;

			break;
		}

		default:
			break;

		}
	}
}