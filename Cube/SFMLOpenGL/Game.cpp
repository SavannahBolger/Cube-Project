#include "Game.h"

bool updatable = false;

Game::Game() 
	: window(VideoMode(800, 600), "OpenGL Cube"),
	position{
		{0.5f, 0.5f, -5.0f },
		{-0.5f, 0.5f, -5.0f},
		{-0.5f, -0.5f, -5.0f},
		{0.5f, -0.5f, -5.0f},

		{0.5f, 0.5f, -6.0f},
		{-0.5f, 0.5f, -6.0f},
		{-0.5f, -0.5f, -6.0f},
		{0.5f, -0.5f, -6.0f},

		{0.5f, 0.5f, -6.0f},
		{0.5f, 0.5f, -5.0f},
		{0.5f, -0.5f, -5.0f},
		{0.5f, -0.5f, -6.0f},

		{-0.5f, 0.5f, -5.0f},
		{-0.5f, 0.5f, -6.0f},
		{-0.5f, -0.5f, -6.0f},
		{-0.5f, -0.5f, -5.0f},

		{0.5f, -0.5f, -5.0f},
		{-0.5f, -0.5f, -5.0f},
		{-0.5f, -0.5f, -6.0f},
		{0.5f, -0.5f, -6.0f},

		{0.5f, 0.5f, -6.0f} ,
		{-0.5f, 0.5f, -6.0f},
		{-0.5f, 0.5f, -5.0f},
		{0.5f, 0.5f, -5.0f} }

{
	index = glGenLists(1);
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

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
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
		/*for (int i = 0; i < 24; i++)
		{
			glVertex3f(position[i].X(), position[i].Y(), position[i].Z());
		}*/
		glVertex3f(0.5f, 0.5f, -5.0f ),
		glVertex3f(-0.5f, 0.5f, -5.0f);
		glVertex3f(-0.5f, -0.5f, -5.0f);
		glVertex3f(0.5f, -0.5f, -5.0f);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, -6.0f);
		glVertex3f(-0.5f, 0.5f, -6.0f);
		glVertex3f(-0.5f, -0.5f, -6.0f);
		glVertex3f(0.5f, -0.5f, -6.0f);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.5f, -6.0f);
		glVertex3f(0.5f, 0.5f, -5.0f);
		glVertex3f(0.5f, -0.5f, -5.0f);
		glVertex3f(0.5f, -0.5f, -6.0f);
		
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-0.5f, 0.5f, -5.0f);
		glVertex3f(-0.5f, 0.5f, -6.0f);
		glVertex3f(-0.5f, -0.5f, -6.0f);
		glVertex3f(-0.5f, -0.5f, -5.0f);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.5f, -0.5f, -5.0f);
		glVertex3f(-0.5f, -0.5f, -5.0f);
		glVertex3f(-0.5f, -0.5f, -6.0f);
		glVertex3f(0.5f, -0.5f, -6.0f);
		
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.5f, 0.5f, -6.0f);
		glVertex3f(-0.5f, 0.5f, -6.0f);
		glVertex3f(-0.5f, 0.5f, -5.0f);
		glVertex3f(0.5f, 0.5f, -5.0f);
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
		for (int i = 0; i > 24; i++)
		{
			//osition[i] = position[i] * Matrix3::rotationZ(rotationAngle);
		}
		glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on z Axis
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
		glTranslatef(-5.0f, -5.0f, -15.0f);
		glRotatef(rotationAngle, 1, 0, 0); // Rotates the camera on Y Axis
		glTranslatef(5.0f, 5.0f, 15.0f);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
		glTranslatef(-4.0f, -3.0f, -4.0f);
		glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis
		glTranslatef(4.0f, 3.0f, 4.0f);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		scale = true;
	}
	else
	{
		scale = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		translate = true;
	}
	else
	{
		translate = false;
	}
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	if (translate)
	{
		glTranslatef(0.5f, 0.0f, 0.0f);
	}
	if (scale)
	{
		glScalef(5.0f, 5.0f, 5.0f);
	}
	update();
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

