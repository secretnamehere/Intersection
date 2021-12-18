#include "Intersector.h"

Intersector::Intersector(){

	this->first = Segment3D();
	this->second = Segment3D();
	this->areCollinear = false;
	this->areSuperimposed = false;
	this->areIntersected = false;
	this->areInTheSamePlane = false;
	this->intersection = Vector3D();
}

Intersector::Intersector(Segment3D first, Segment3D second) {

	this->first = first;
	this->second = second;
	this->intersection = Vector3D();
	this->areCollinear = checkIfCollinear();
	this->areSuperimposed = checkIfSuperimposed();
	this->areInTheSamePlane = checkIfInTheSamePlane();
	this->areIntersected = checkIfIntersected();
}

Intersector::Intersector(Vector3D a, Vector3D b, Vector3D c, Vector3D d) {

	this->first = Segment3D(a,b);
	this->second = Segment3D(c, d);
	this->intersection = Vector3D();
	this->areCollinear = checkIfCollinear();
	this->areSuperimposed = checkIfSuperimposed();
	this->areInTheSamePlane = checkIfInTheSamePlane();
	this->areIntersected = checkIfIntersected();
}


//Решение системы методом крамера
vector<double> Intersector::kramer(vector<double> a, vector<double> b, vector<double> c, vector<double> d, int var1, int var2)
{
	vector<double> exit = { -1, -1 };
	double det1 = ((d[var1] - b[var1]) * (d[var2] - c[var2])) - ((d[var2] - b[var2]) * (d[var1] - c[var1]));
	double det2 = ((a[var1] - b[var1]) * (d[var2] - c[var2])) - ((a[var2] - b[var2]) * (d[var1] - c[var1]));
	double det3 = ((a[var1] - b[var1]) * (d[var2] - b[var2])) - ((a[var2] - b[var2]) * (d[var1] - b[var1]));
	double det4 = ((a[var1] - b[var1]) * (d[var2] - c[var2])) - ((a[var2] - b[var2]) * (d[var1] - c[var1]));

	if (((abs(det2) < eps) || (abs(det4) < eps))&&(var1==1)&&(var2==2)) return kramer(a,b,c,d,0,2);
	if (((abs(det2) < eps) || (abs(det4) < eps)) && (var1 == 0) && (var2 == 2)) return kramer(a, b, c, d, 0, 1);
	exit[0] = det1 / det2;
	exit[1] = det3 / det4;

	return exit;
}

bool Intersector::checkIfInTheSamePlane()
{
	if (first.equals(second)) return true;
	vector<double> firstFrom = first.getFrom().getCoordinates();
	vector<double> firstTo = first.getTo().getCoordinates();
	vector<double> secondFrom = second.getFrom().getCoordinates();
	vector<double> secondTo = second.getTo().getCoordinates();

	for (int i = 0; i < 3; i++) {
		firstTo[i] -= firstFrom[i];
		secondFrom[i] -= firstFrom[i];
		secondTo[i] -= firstFrom[i];
	}

	double delta1 = (firstTo[0] * secondFrom[1] * secondTo[2]) + (secondFrom[0] * secondTo[1] * firstTo[2]) + (secondTo[0] * firstTo[1] * secondFrom[2]);
	double delta2 = (secondTo[0] * secondFrom[1] * firstTo[2]) + (secondFrom[0] * firstTo[1] * secondTo[2]) + (firstTo[0] * secondTo[1] * secondFrom[2]);
	if (abs(delta1 - delta2) < eps) return true; else return false;
}

bool Intersector::checkIfIntersected()
{
	if (!areInTheSamePlane) return false;
	if (first.equals(second)) {
		this->intersection = first.getFrom();
		return true;
	} 

	if (areSuperimposed) {
		double a = first.getTo().distanse(second.getFrom());
		double b = first.getTo().distanse(second.getTo());
		double c = first.getFrom().distanse(second.getFrom());
		double d = first.getFrom().distanse(second.getTo());
		if ((abs(a + b - second.getLength()) < eps)) this->intersection = first.getTo(); else this->intersection = first.getFrom();
		return true;
	}

	vector<double> firstFrom = first.getFrom().getCoordinates();
	vector<double> firstTo = first.getTo().getCoordinates();
	vector<double> secondFrom = second.getFrom().getCoordinates();
	vector<double> secondTo = second.getTo().getCoordinates();

	vector<double> values = kramer(firstFrom, firstTo, secondFrom, secondTo, 1, 2);
	if (((values[0] >= -eps) && (values[0] <= 1 + eps)) && ((values[1] >= -eps) && (values[1] <= 1 + eps))) {
		this->intersection = Vector3D(values[0] * (firstFrom[0] - firstTo[0]) + firstTo[0], values[0] * (firstFrom[1] - firstTo[1]) + firstTo[1], values[0] * (firstFrom[2] - firstTo[2]) + firstTo[2]);
		return true;
	}
	else return false;
	
	
	return false;
}

bool Intersector::checkIfCollinear()
{
	Vector3D a = first.getDirectionVector();
	Vector3D b = second.getDirectionVector();
	double delta1 = a.getY() * b.getZ() - b.getY() * a.getZ();
	double delta2 = a.getX() * b.getZ() - b.getX() * a.getZ();
	double delta3 = a.getX() * b.getY() - b.getX() * a.getY();
	
	if ((abs(delta1) < eps) && (abs(delta2)<eps) && (abs(delta3)<eps))return true; else return false;
}

bool Intersector::checkIfSuperimposed()
{
	if (!areCollinear) return false; else {
		double a = first.getTo().distanse(second.getFrom());
		double b = first.getTo().distanse(second.getTo());
		double c = first.getFrom().distanse(second.getFrom());
		double d = first.getFrom().distanse(second.getTo());
		if ((abs(a + b - second.getLength()) < eps) || (abs(c + d - second.getLength()) < eps)) return true; else return false;
	}
}

Vector3D Intersector::getIntersection()
{
	return this->intersection;
}

void Intersector::printInfo()
{
	if (!(this->areInTheSamePlane)) {
		cout << "The segments are not even in the same plane. No intersections." << endl;
		return;
	}

	if (this->areSuperimposed) {
		cout << "The segments are superimposed. Infinitely many intersection points. For example:" << endl;
		this->intersection.printCoordinates();
		return;
	}

	if (this->areIntersected) {
		cout << "The segments are intersected. Point of intersection:" << endl;
		this->getIntersection().printCoordinates();
		return;
	}

	if (this->areCollinear) {
		cout << "The segments collinear, no points of intersection" << endl;
		return;
	}

	if ((this->areInTheSamePlane) && (!(this->areIntersected))) {
		cout << "The segments lie in the same plane, but not intersected" << endl;
		return;
	}

	return;
}
