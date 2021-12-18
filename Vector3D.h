#pragma once
#include<vector>
#include <iostream>
#include <math.h>
using namespace std;
class Vector3D{
private:
	double X;
	double Y;
	double Z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	double getX();
	double getY();
	double getZ();
	double distanse(Vector3D second);//возвращает расстояние до другой точки
	void printCoordinates();//печатает координаты точки
	vector<double> getCoordinates();
	bool equals(Vector3D second);
	void setX(double x);
	void setY(double y);
	void setZ(double z);
};

