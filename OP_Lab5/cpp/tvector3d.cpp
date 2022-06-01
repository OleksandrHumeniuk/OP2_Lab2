#include "tvector3d.h"


double TVector3D::getCoordinate(char c)
{
	switch (c)
	{
	case 'x':
		return x;
		break;
	case 'y':
		return y;
		break;
	case 'z':
		return z;
		break;
	}
}

double TVector3D::getScalar(TVector& vector) {
	return x * vector.getCoordinate('x') + y * vector.getCoordinate('y') + z * vector.getCoordinate('z');
}

double TVector3D::getLength() {
	return sqrt(x * x + y * y + z * z);
}

void TVector3D::print(string s) {
	cout << s<< "TVector3D: " << " x = " << setw(4) << x << " y = " << setw(4) << y << " z = " << setw(4) << z << endl;
}

