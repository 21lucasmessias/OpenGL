#include "hotkeys.hpp"

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
			if (states.exercise == EXERCISE_1) {
				//states.showRoof = !states.showRoof;

				for (GLuint i = 0; i < objects_transformations.size(); i++) {
					if (objects_transformations[i].index == INDEX_ROOF) {
						objects_transformations.erase(objects_transformations.begin() + i);
						i--;
					}
				}
			}
			else if (states.exercise == EXERCISE_7) {
				states.player_1_points = 0;
				states.player_2_points = 0;

				objects_transformations.clear();
				processProject();
			}
						
			break;
		}

		case GLFW_KEY_W: {
			if (states.exercise == EXERCISE_1) {
				//states.showWindows = !states.showWindows;

				for (GLuint i = 0; i < objects_transformations.size(); i++) {
					if (objects_transformations[i].index == INDEX_WINDOW) {
						objects_transformations.erase(objects_transformations.begin() + i);
						i--;
					}
				}
			}
			else if (states.exercise == EXERCISE_7) {
				objects_transformations[3].translation[1] += SPEED_PLAYER;
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
			if (states.exercise == EXERCISE_1) {
				objects_transformations[0].translation[2] = 3.0f;
			}
			else if (states.exercise == EXERCISE_7) {
				objects_transformations[3].translation[1] -= SPEED_PLAYER;
			}

			break;
		}

		case GLFW_KEY_P: {
			states.transformationMode = 0;

			break;
		}

		case GLFW_KEY_O: {
			states.transformationMode = 1;

			break;
		}

		case GLFW_KEY_I: {
			states.transformationMode = 2;

			break;
		}

		case GLFW_KEY_LEFT: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[0] -= 1;
						}
					}
				}
			}
			else {
				objects_transformations[0].translation[0] -= 1;
			}

			break;
		}

		case GLFW_KEY_RIGHT: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[0] += 1;
						}
					}
				}
			}
			else {
				objects_transformations[0].translation[0] += 1;
			}

			break;
		}

		case GLFW_KEY_UP: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] += 1;
						}
					}
				}

				else if (states.transformationMode == 1) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].rotation.radians += 1;
						}
					}
				}

				else if (states.transformationMode == 2) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] += 1;
							objects_transformations[i].rotation.radians += 1;
						}
					}
				}
			}
			else if (states.exercise == EXERCISE_2) {
				objects_transformations[0].translation[1] += 1.0;
			}
			else if (states.exercise == EXERCISE_7) {
				objects_transformations[2].translation[1] += SPEED_PLAYER;
			}

			break;
		}

		case GLFW_KEY_DOWN: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] -= 1;
						}
					}
				}

				else if (states.transformationMode == 1) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].rotation.radians -= 1;
						}
					}
				}

				else if (states.transformationMode == 2) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] -= 1;
							objects_transformations[i].rotation.radians -= 1;
						}
					}
				}
			}
			else if (states.exercise == EXERCISE_2) {
				objects_transformations[0].translation[1] -= 1;
			}
			else if (states.exercise == EXERCISE_7) {
				objects_transformations[2].translation[1] -= SPEED_PLAYER;
			}
			break;
		}

		case GLFW_KEY_1: {
			states.exercise = EXERCISE_1;

			states.projection = ortho(0.0f, 100.0f, 0.0f, 100.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();

			break;
		}

		case GLFW_KEY_2: {
			states.exercise = EXERCISE_2;

			states.projection = ortho(0.0f, 40.0f, 0.0f, 30.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();

			break;
		}

		case GLFW_KEY_3: {
			states.exercise = EXERCISE_3;

			states.projection = ortho(0.0f, 80.0f, 0.0f, 60.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();

			break;
		}

		case GLFW_KEY_4: {
			states.exercise = EXERCISE_4;

			states.projection = ortho(0.0f, 80.0f, 0.0f, 60.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();

			break;
		}

		case GLFW_KEY_5: {
			states.exercise = EXERCISE_5;

			states.projection = ortho(0.0f, 80.0f, 0.0f, 60.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();

			break;
		}

		case GLFW_KEY_6: {
			states.exercise = EXERCISE_6;

			states.projection = ortho(0.0f, 100.0f, 0.0f, 100.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();

			break;
		}

		case GLFW_KEY_7: {
			states.exercise = EXERCISE_7;

			states.player_1_points = 0;
			states.player_2_points = 0;

			states.projection = ortho(0.0f, 100.0f, 0.0f, 100.0f, -5.0f, 5.0f);
			objects_transformations.clear();
			processProject();


			break;
		}


		default:
			break;

		}
	}

	if (action == GLFW_REPEAT) {
		switch (key) {
		case GLFW_KEY_UP: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] += 1;
						}
					}
				}

				else if (states.transformationMode == 1) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].rotation.radians += 1;
						}
					}
				}

				else if (states.transformationMode == 2) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] += 1;
							objects_transformations[i].rotation.radians += 1;
						}
					}
				}
			}
			else if (states.exercise == EXERCISE_2) {
				objects_transformations[0].translation[1] += 1;
			}
			else if (states.exercise == EXERCISE_7) {
				objects_transformations[2].translation[1] += SPEED_PLAYER;
			}

			break;
		}

		case GLFW_KEY_DOWN: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] -= 1;
						}
					}
				}

				else if (states.transformationMode == 1) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].rotation.radians -= 1;
						}
					}
				}

				else if (states.transformationMode == 2) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[1] -= 1;
							objects_transformations[i].rotation.radians -= 1;
						}
					}
				}
			}

			else if (states.exercise == EXERCISE_2) {
				objects_transformations[0].translation[1] -= 1;
			}
			else if (states.exercise == EXERCISE_7) {
				objects_transformations[2].translation[1] -= SPEED_PLAYER;
			}

			break;
		}

		case GLFW_KEY_LEFT: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[0] -= 1;
						}
					}
				}
			}

			else {
				objects_transformations[0].translation[0] -= 1;
			}

			break;
		}

		case GLFW_KEY_RIGHT: {
			if (states.exercise == EXERCISE_1) {
				if (states.transformationMode == 0) {
					for (GLuint i = 0; i < objects_transformations.size(); i++) {
						if (objects_transformations[i].index != INDEX_SUN && objects_transformations[i].index != INDEX_BODY) {
							objects_transformations[i].translation[0] += 1;
						}
					}
				}
			}

			else {
				objects_transformations[0].translation[0] += 1;
			}

			break;
		}


		case GLFW_KEY_W: {
			if (states.exercise == EXERCISE_7) {
				objects_transformations[3].translation[1] += SPEED_PLAYER;
			}

			break;
		}

		case GLFW_KEY_S: {
			if (states.exercise == EXERCISE_7) {
				objects_transformations[3].translation[1] -= SPEED_PLAYER;
				}

				break;
			}

		}
	}
}