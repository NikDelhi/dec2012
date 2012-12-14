

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
}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT) - glutGet(GLUT_SCREEN_HEIGHT_MM));
    glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("Software Designer - By Nikhil Gupta");

	//glut listener functions

	glutMainLoop();
	return 0;
}