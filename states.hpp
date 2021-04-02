#ifndef PROJECT_H
#define PROJECT_H

typedef struct States {
	bool wireframe;
	bool showBody;
	bool showRoof;
	bool showDoor;
	bool showWindows;
	char transformationType;

	float offset_h;
	float offset_v;
} States;

States states;

#endif