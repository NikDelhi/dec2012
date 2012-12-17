

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
    glClearColor(1.0, 1.0, 1.0);

}

static void initialise_camera()
{
    gluLookAt(0,0,-2, 0,0,0, 0,1,0);

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
    glClear();
    glLoadIdentity();
    initialise_camera();
}

static void mouse()
{
}

static void keyboard()
{
}

static void specialKeyboard()
{
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT) - glutGet(GLUT_SCREEN_HEIGHT_MM));
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
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
