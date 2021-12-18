#pragma once
#include "Vector3D.h"
#include "Segment3D.h"
class Intersector
{
private:
	const double eps = 0.00000001;//используется из соображений избежания ошибки машинного округления
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
	bool checkIfInTheSamePlane();//Проверка на то, что отрезки лежат в одной плоскости
	bool checkIfIntersected();//Проверка, имеют ли отрезки пересечение
	bool checkIfCollinear();//Проверка отрезков на коллинеарность
	bool checkIfSuperimposed();//Проверка накладываются ли отрезки(если коллинеарны)
	Vector3D getIntersection();//Возвращает точку пересечения(если она есть, если много, то одну из всего континуума) - требуемая функция из ТЗ
	void printInfo();//Печатает информацию о том, как расположены отрезки, выводит точку пересечения, если она есть
};

