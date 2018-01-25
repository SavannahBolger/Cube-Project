#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3D.h"
#include "Matrix3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	Clock clock;
	Time elapsed;
	bool translate = false;
	bool scale = false;

	float rotationAngle = 0.0f;
	Vector3D position[24];

};