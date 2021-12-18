#include "Intersector.h"
using namespace std;

int main() {
	Vector3D a(0, 0, 0);
	Vector3D b(1, 1, 1);
	Vector3D c(0.5, -0.5, 0.5);
	Vector3D d(0.5, 14, 0.5);
	
	Segment3D segment1(a, b);
	Segment3D segment2(c, d);
	Intersector inter(a,b,c,d);
	inter.printInfo();
	return 0;
}