#include "Segment3D.h"
#include <math.h>
Segment3D::Segment3D() {
	this->from = Vector3D();
	this->to = Vector3D();
}

Segment3D::Segment3D(Vector3D from, Vector3D to) {
	try {
		if (from.equals(to)) throw ("Segment can not be a point!");
		this->from = from;
		this->to = to;
	}
	catch (const char* S) {
		cout << S << endl;
	}
}

void Segment3D::setFrom(Vector3D from)
{
	this->from = from;
}

void Segment3D::setTo(Vector3D to)
{
	this->to = to;
}

Vector3D Segment3D::getTo()
{
	return this->to;
}

Vector3D Segment3D::getFrom()
{
	return this->from;
}

void Segment3D::printEndCoordinates()
{
	cout << "Start:" << endl;
	from.printCoordinates();
	cout << "End:" << endl;
	to.printCoordinates();
}

bool Segment3D::equals(Segment3D second)
{
	if ((this->from.equals(second.getFrom())) && (this->to.equals(second.getTo()))) return true;
	else return false;
}

Vector3D Segment3D::getDirectionVector()
{
	return Vector3D(this->to.getX() - this->from.getX(), this->to.getY() - this->from.getY(), this->to.getZ() - this->from.getZ());
}

double Segment3D::getLength()
{
	return this->from.distanse(this->to);
}




