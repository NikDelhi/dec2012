
/*this file describes a ractangle element in a graphical application
this rectangle is a basic drawing figure which can be used for various purposes
*/

#include "data_structures.h"
#include "element.h"

using namespace std;

class Rectangle : public Element
{

private:
	const double DEFAULT_WIDTH = 10;
	const double DEFAULT_HEIGHT = 10;

public:
	double width,height;
	
	Rectangle();
	Rectangle(double , double );
	
};