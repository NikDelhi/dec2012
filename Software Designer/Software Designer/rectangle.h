
/*this file describes a ractangle element in a graphical application
this rectangle is a basic drawing figure which can be used for various purposes
*/

#include "data_structures.h"
#include "element.h"

#define DEFAULT_WIDTH 10
#define DEFAULT_HEIGHT 10

using namespace std;

class Rectangle : public Element
{

private:

public:
	double width,height;
	
	Rectangle();
	Rectangle(double , double );
	
};
