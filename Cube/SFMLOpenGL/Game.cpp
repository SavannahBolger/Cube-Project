#include "Game.h"

bool updatable = false;

Game::Game() 
	: window(VideoMode(800, 600), "OpenGL Cube"),
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
	//index = glGenLists(1);
	for (int i = 0; i < 8; i++)
	{
		m_points[i].setRadius(5);
		m_points[i].setFillColor(sf::Color::Black);
		m_points[i].setOrigin(5, 5);
		m_points[i].setPosition(m_position[i].X(), m_position[i].Y());
	}
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	/*glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -5.0f);
		glVertex3f(-1.0f, 1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glVertex3f(1.0f, -1.0f, -5.0f);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -15.0f);
		glVertex3f(-1.0f, 1.0f, -15.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);
		glVertex3f(1.0f, -1.0f, -15.0f);

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();*/
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
	{
		xRotation = Matrix3::rotationX(0.0349066);//angle set to 2 degrees
		for (int i = 0; i < 8; i++)
		{
			m_position[i] = xRotation * m_position[i];
		}
	}
	//setting that if the y key is pressed and not the left shift key as well
	//the cube will rotate on the y axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
	{
		yRotation = Matrix3::rotationY(0.0349066);//angle set to 2 degrees
		for (int i = 0; i < 8; i++)
		{
			m_position[i] = yRotation * m_position[i];
		}
	}
	//setting that if the z key is pressed and not the left shift key as well
	//the cube will rotate on the z axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
	{
		zRotation = Matrix3::rotationZ(0.0349066); //angle set to 2 degrees
		for (int i = 0; i < 8; i++)
		{
			m_position[i] = zRotation * m_position[i];
		}
	}
	//setting that if the x key is pressed as well as the left shift key 
	//the cube will rotate on the x axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		xRotation = Matrix3::rotationX(-0.0349066);//angle set to 2 degrees
		for (int i = 0; i < 8; i++)
		{
			m_position[i] = xRotation * m_position[i];
		}
	}
	//setting that if the y key is pressed as well as the left shift key 
	//the cube will rotate on the y axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		yRotation = Matrix3::rotationY(-0.0349066);//angle set to 2 degrees
		for (int i = 0; i < 8; i++)
		{
			m_position[i] = yRotation * m_position[i];
		}
	}
	//setting that if the z key is pressed as well as the left shift key 
	//the cube will rotate on the z axis
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		zRotation = Matrix3::rotationZ(-0.0349066);//angle set to 2 degrees
		for (int i = 0; i < 8; i++)
		{
			m_position[i] = zRotation * m_position[i];
			//position = position * zRotation;
		}
	}

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
				m_faces.append(sf::Vertex(sf::Vector2f(m_position[corners[index][i]].X(), m_position[corners[index][i]].Y()), m_colors[index]));
			}
		}
	}
	//clear the edges array
	/*m_edges.clear();
	//append active edges 
	for (int index = 0; index < 6; index++)
	{
		if (m_faceActive[index])
		{
			m_edges.append(sf::Vertex(sf::Vector2f(m_position[corners[index][0]].X(), m_position[corners[index][0]].X()), sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][1]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][1]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][2]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][2]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][3]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][3]], sf::Color::Black));
			m_edges.append(sf::Vertex(m_position[corners[index][0]], sf::Color::Black));
		}

	}*/
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis

	glCallList(1);*/
	for (int i = 0; i < m_faces.getVertexCount(); i++)
	{
		m_faces[i].position += sf::Vector2f{ 200,220 };
	}
	window.create(m_faces);
	//move positions back to the origin
	for (int i = 0; i < m_faces.getVertexCount(); i++)
	{
		m_faces[i].position -= sf::Vector2f{ 200,220 };
	}
	
	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

