#include "Vector3D.h"

	Vector3D::Vector3D()
	{
		this->X = 0;
		this->Y = 0;
		this->Z = 0;
	}

	Vector3D::Vector3D(double x, double y, double z)
	{
		this->X = x;
		this->Y = y;
		this->Z = z;
	}

	double Vector3D::getX()
	{
		return this->X;
	}

	double Vector3D::getY()
	{
		return this->Y;
	}

	double Vector3D::getZ()
	{
		return this->Z;
	}

	double Vector3D::distanse(Vector3D second)
	{
		return sqrt((pow(this->getX() - (second.getX()), 2) + pow(this->getY() - (second.getY()), 2) + pow(this->getZ() - (second.getZ()), 2)));
	}

	void Vector3D::printCoordinates()
	{
		cout << "Coordinates: X = " << this->getX() << " Y = " << this->getY() << " Z = " << this->getZ() << endl;
	}

	vector<double> Vector3D::getCoordinates()
	{
		vector<double> exit{ this->X, this->Y, this->Z };
		return exit;
	}

	bool Vector3D::equals(Vector3D second)
	{
		if ((this->X == second.getX()) && (this->Y == second.getY()) && (this->Z == second.getZ())) return true;
		else return false;
	}

	void Vector3D::setX(double x)
	{
		this->X = x;
	}

	void Vector3D::setY(double y)
	{
		this->Y = y;
	}

	void Vector3D::setZ(double z)
	{
		this->Z = z;
	}


