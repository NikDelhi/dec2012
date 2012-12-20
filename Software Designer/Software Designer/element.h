
/*
An Element is the root/parent of all graphical figures or objects
all objects inherit the properties of an element object and are themselves elements
An element is a parent/root to all objects - drawing figures, window, entities etc 
So a window is also an element. But an element may not be a window thereby allowing all elements (not only windows) to have parent and children thus giving rise to a relative hiererchical layout
The user may choose to use this window class for creating a window or using the basic drawing figures and other elements to define one's own window
*/

#include "data_structures.h"

using namespace std;

class Element
{

private:

protected:
	string classname;

public:	
	Element** children;
	Element* parent;

	Element();
	Element(Element* );

};