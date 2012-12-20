
/*
An Element is the root/parent of all graphical figures or objects
all objects inherit the properties of an element object and are themselves elements
An element is a parent/root to all objects - drawing figures, window, entities etc 
So a window is also an element. But an element may not be a window thereby allowing all elements (not only windows) to have parent and children thus giving rise to a relative hiererchical layout
The user may choose to use this window class for creating a window or using the basic drawing figures and other elements to define one's own window
*/

#include "element.h"

Element :: Element()
{
	parent = NULL;
	children = NULL;
	classname = "Element";
}

Element :: Element(Element* p)
{
	Element();
	parent = p;
}