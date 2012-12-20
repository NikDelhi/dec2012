
/*this file describes a ractangle element in a graphical application
this rectangle is a basic drawing figure which can be used for various purposes
*/

#include "rectangle.h"

Rectangle :: Rectangle()
{
	classname = "Rectangle";
	width = DEFAULT_WIDTH;
	height = DEFAULT_HEIGHT;
}

Rectangle :: Rectangle(double w, double h)
{
	Rectangle();
	width = w;
	height = h;
}