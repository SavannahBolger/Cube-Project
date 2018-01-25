/// <summary>
/// @author: Savannah Bolger
/// @student number: C00215747
/// @date: 24-4-2017
/// Known Bugs:
/// points of the cube are always shown
/// </summary>

#include "Game.h"
#include <iostream>



Game::Game()
	: m_window{ sf::VideoMode{ 400, 440 }, "Lab 8 Cube" },	
	m_background(sf::Vector2f(400, 440)),
	//multicoloured faces of the cube
	m_faces{ sf::Quads },
	//the edges of the faces of the cube
	m_edges{ sf::Lines },
	//the circles to show the points of the cube
	m_points{},
	//the position of the cube
	m_position{

				  { -1.06337,-3.57453,-86.5222 },
				  { -27.9024,75.6183,-31.6754 } ,
				  { 53.1393,63.4013,25.6219 } ,
				  { 79.9784,-15.7915,-29.2249 } ,
				  { -53.1393,-63.4013,-25.6219 } ,
				  { -79.9784,15.7915,29.2249 } ,
				  { 1.06337,3.57453,86.5222 } ,
				  { 27.9024,-75.6183,31.6754 } },
	//colours for the faces of the cube
	m_colors{
				  { BLUE },
				  { PINK },
				  { RED },
				  { ORANGE },
				  { GREEN },
				  { YELLOW } },
    //the corners of the cube
	corners{
					  { 0,1,2,3 },
					  { 4,5,1,0 } ,
					  { 4,0,3,7 } ,
					  { 3,2,6,7 } ,
					  { 7,6,5,4 } ,
					  { 1,5,6,2 } }

{
	//setting the background 
	m_background.setFillColor(WHITE);
	m_background.setPosition(sf::Vector2f(0, 0));
	//setting the font
	/*if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	//text for corner numbers	
	sf::String text[] = { "0","1","2", "3","4","5", "6", "7" };*/
	//setting the points for corners and text for corner numbers
	for (int i = 0; i < 8; i++)
	{
		m_points[i].setRadius(5);
		m_points[i].setFillColor(sf::Color::Black);
		m_points[i].setOrigin(5,5);
		m_points[i].setPosition(m_position[i]);
		/*m_pointsMessage[i].setFont(m_font);  // set the font for the text
		m_pointsMessage[i].setCharacterSize(11); // set the text size
		m_pointsMessage[i].setString(text[i]);
		//m_pointsMessage[i].setColor(WHITE); // set the text colour
		m_pointsMessage[i].setPosition(m_position[i] - sf::Vector2f{2.5,5.5});  // its position on the screen*/
	}
	//setting the text to decribe what the program does
	/*m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(20); // set the text size
	m_message.setString("Press X,Y,Z to rotate the cube clockwise\n Press LShift to rotate anticlockwise\n Press 'P' to print coordinates");
	//m_message.setColor(sf::Color::Black); // set the text colour
	m_message.setPosition(10,350);  // its position on the screen*/

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time)
{
	//setting that if the x key is pressed and not the left shift key as well
	//the cube will rotate on the x axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
	{
		xRotation = MyMatrix3::rotationX(0.0349066);//angle set to 2 degrees
		for (size_t i = 0; i < 8; i++)
		{
			m_position[i] = xRotation * m_position[i];
		}
	}
	//setting that if the y key is pressed and not the left shift key as well
	//the cube will rotate on the y axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
	{
		yRotation = MyMatrix3::rotationY(0.0349066);//angle set to 2 degrees
		for (size_t i = 0; i < 8; i++)
		{
			m_position[i] = yRotation * m_position[i];
		}
	}
	//setting that if the z key is pressed and not the left shift key as well
	//the cube will rotate on the z axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
	{
		zRotation = MyMatrix3::rotationZ(0.0349066); //angle set to 2 degrees
		for (size_t i = 0; i < 8; i++)
		{
			m_position[i] = zRotation * m_position[i];
		}
	}
	//setting that if the x key is pressed as well as the left shift key 
	//the cube will rotate on the x axis
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::X) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		xRotation = MyMatrix3::rotationX(-0.0349066);//angle set to 2 degrees
		for (size_t i = 0; i < 8; i++)
		{
			m_position[i] = xRotation * m_position[i];
		}
	}
	//setting that if the y key is pressed as well as the left shift key 
	//the cube will rotate on the y axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		yRotation = MyMatrix3::rotationY(-0.0349066);//angle set to 2 degrees
		for (size_t i = 0; i < 8; i++)
		{
			m_position[i] = yRotation * m_position[i];
		}
	}
	//setting that if the z key is pressed as well as the left shift key 
	//the cube will rotate on the z axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		zRotation = MyMatrix3::rotationZ(-0.0349066);//angle set to 2 degrees
		for (size_t i = 0; i < 8; i++)
		{
			m_position[i] = zRotation * m_position[i];
			//position = position * zRotation;
		}
	}
	//setting that if the p key is pressed  
	//the coordinates of the corners will be printed to the screen
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		std::cout << "Cube Coordinates:\n {{ " << m_position[0].toString()
			<< "}\n {" << m_position[1].toString()
			<< "}\n {" << m_position[2].toString()
			<< "}\n {" << m_position[3].toString()
			<< "}\n {" << m_position[4].toString()
			<< "}\n {" << m_position[5].toString()
			<< "}\n {" << m_position[6].toString()
			<< "}\n {" << m_position[7].toString()
			<< "}}\n ";
	}
	//cross product check for face active
	for (int i = 0; i < 6; i++)
	{
		if (((m_position[corners[i][1]] - m_position[corners[i][0]]).crossProduct(m_position[corners[i][2]] - m_position[corners[i][0]])).Z() < 0)
		{
			m_faceActive[i] = true;
		}
		else 
		{
			m_faceActive[i] = false;
		}
	}
	//clear the faces array
	m_faces.clear();
	//append active face elements  into the faces array
	for (int index = 0; index < 6; index++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_faceActive[index])
			{
				m_faces.append(sf::Vertex(m_position[corners[index][i]], m_colors[index]));
			}
		}
	}
	//clear the edges array
	m_edges.clear();
	//append active edges 
	for (int index = 0; index < 6; index++)
	{
		if (m_faceActive[index])
		{
			m_edges.append(sf::Vertex(m_position[corners[index][0]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][1]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][1]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][2]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][2]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][3]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][3]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][0]], sf::Color::Black));
		}

	}
}

void Game::render()
{
	//draw

	m_window.clear();
	m_window.draw(m_background);
	//m_window.draw(m_message);
	//move all positions in the array to the centre of the screen using a vector
	for (int i = 0; i < m_faces.getVertexCount(); i++)
	{
		m_faces[i].position += sf::Vector2f{200,220};
	}
	m_window.draw(m_faces);
	//move positions back to the origin
	for (int i = 0; i < m_faces.getVertexCount(); i++)
	{
		m_faces[i].position -= sf::Vector2f{ 200,220 };
	}
	//move all positions in the array to the centre of the screen using a vector
	for (int i = 0; i < m_edges.getVertexCount(); i++)
	{
		m_edges[i].position += sf::Vector2f{ 200,220 };
	}
	m_window.draw(m_edges);
	//move positions back to the origin
	for (int i = 0; i < m_edges.getVertexCount(); i++)
	{
		m_edges[i].position -= sf::Vector2f{ 200,220 };
	}
	
	//draw corner points
	drawCircles();
	
	for (int index = 0; index < 6; index++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (m_faceActive[index])
			{
				//m_window.draw(m_pointsMessage[i]);
			}
		}
	}
	m_window.display();
}

void Game::drawCircles()
{
	for (int i = 0; i < 6; i++)
	{
		for (int index = 0; index < 8; index++)
		{
			//move all positions in the array to the centre of the screen using a vector
			for (int i = 0; i < 8; i++)
			{
				m_points[i].setPosition(m_position[i] + sf::Vector2f{ 200,220 });
				//m_pointsMessage[i].setPosition(m_position[i] - sf::Vector2f{ 2.5,5.5 } + sf::Vector2f{ 200,220 });  // its position on the screen
			}
			
			if (m_faceActive[i])
			{
				m_window.draw(m_points[index]);
				//m_window.draw(m_pointsMessage[index]);
			}
			//move positions back to the origin
			for (int i = 0; i < 8; i++)
			{
				m_points[i].setPosition(m_position[i] - sf::Vector2f{ 200,220 });
				//m_pointsMessage[i].setPosition(m_position[i] - sf::Vector2f{ 2.5,5.5 } - sf::Vector2f{ 200,220 });  // its position on the screen
			}
			
		}
	}
}
