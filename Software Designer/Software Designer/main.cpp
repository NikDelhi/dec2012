

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "globals.h"

static void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

}

static void initialise_camera()
{
    //gluLookAt(0,0,-2, 0,0,0, 0,1,0);

}

static void reshape(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(dimensions == 2) 
    {
	glOrtho(-1,1,-1,1,-1,1);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    initialise_camera();

	glColor3f(0.0, 0.0, 0.0);
	glutSolidCube(1);

	glutSwapBuffers();

}

static void mouse(int button, int state, int x, int y)
{
}

static void keyboard(unsigned char key, int x, int y) 
{
}

static void specialKeyboard(int key, int x, int y)
{
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutCreateWindow("Software Designer - By Nikhil Gupta");

	//glut listener functions
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);


	glutMainLoop();
	return 0;
}
