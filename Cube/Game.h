#ifndef GAME
#define GAME

#include "MyVector3D.h"
#include "MyMatrix3.h"
#include <SFML/Graphics.hpp>

//colours
const sf::Color WHITE{ 255, 255, 255, 255 };
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
	void run();
private:
	void             processEvents();
	void             update(sf::Time);
	void             render();
	void             drawCircles();

private:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Text m_pointsMessage[8];  // text for corner point numbers
	sf::RectangleShape m_background; 
	sf::RenderWindow m_window; //program window
	int corners[6][4];		//cube colours
	sf::Color m_colors[6];	//cube face colours
	sf::CircleShape m_points[8]; //corner points
	sf::VertexArray m_faces;	 // cube faces
	sf::VertexArray m_edges; // only used to initialise the array
	bool m_faceActive[6];//is face active
	MyVector3D m_position[8]; //corner positions
	MyMatrix3 xRotation;//x axis rotation
	MyMatrix3 yRotation;//y axis rotation
	MyMatrix3 zRotation;//z axis rotation
};

#endif // !GAME


