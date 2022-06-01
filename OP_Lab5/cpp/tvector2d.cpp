#include "tvector2d.h"

double TVector2D::getCoordinate(char c)
{
	switch (c)
	{
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	}
}

double TVector2D::getScalar(TVector& vector) {
	return x * vector.getCoordinate('x') + y * vector.getCoordinate('y');
}

double TVector2D::getLength() {
	return sqrt(x * x + y * y);
}

void TVector2D::print(string s) {
	cout << s << "TVector2D: " << " x = " << setw(4) << x << " y = " << setw(4) << y << endl;
}

