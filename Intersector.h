#pragma once
#include "Vector3D.h"
#include "Segment3D.h"
class Intersector
{
private:
	const double eps = 0.00000001;//введено для того, чтобы избежать ошибок при машинном округлении
	Segment3D first;
	Segment3D second;
	Vector3D intersection;
public:
	Intersector(Segment3D first, Segment3D second);
	Intersector(Vector3D a, Vector3D b, Vector3D c, Vector3D d);
	Intersector();
	bool areInTheSamePlane;
	bool areIntersected;
	bool areCollinear;
	bool areSuperimposed;
	vector<double> kramer(vector<double> a, vector<double> b, vector<double> c, vector<double> d, int var1, int var2);
	bool checkIfInTheSamePlane();//проверка на то, что отрезки в одной плоскости
	bool checkIfIntersected();//проверка на то, что отрезки пересекаются
	bool checkIfCollinear();//проверка на коллинеарность двух отрезков
	bool checkIfSuperimposed();//проверка на то, что прямые накладываются
	Vector3D getIntersection();//возвращает точку пересечения(если она есть, если их континуум, то возвращается одна) - то, что требовалось в ТЗ
	void printInfo();//Печатает информацию о расположении отрезков, выводит точку пересечения, если она есть

