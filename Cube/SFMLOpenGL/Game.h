#include <iostream>
//#include <SFML/Window.hpp>
#include "Matrix3.h"
#include "Vector3D.h"
#include <SFML\Graphics.hpp>

/*#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>*/

using namespace std;
using namespace sf;

const sf::Color BLUE{ 0, 131, 255, 255 };
const sf::Color PINK{ 219, 151, 206, 255 };
const sf::Color RED{ 255, 0, 0, 255 };
const sf::Color ORANGE{ 255, 115, 22, 255 };
const sf::Color GREEN{ 0, 242, 12, 255 };
const sf::Color YELLOW{ 218, 242, 0, 255 };

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::RenderWindow window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	//GLuint index;
	Clock clock;
	Time elapsed;
	int corners[6][4];		//cube colours
	sf::Color m_colors[6];	//cube face colours
	sf::CircleShape m_points[8]; //corner points
	sf::VertexArray m_faces;	 // cube faces
	sf::VertexArray m_edges; // only used to initialise the array
	bool m_faceActive[6];//is face active
	Vector3D m_position[8]; //corner positions
	Matrix3 xRotation;//x axis rotation
	Matrix3 yRotation;//y axis rotation
	Matrix3 zRotation;//z axis rotation
	float rotationAngle = 0.0f;
};