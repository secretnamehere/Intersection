#pragma once
#include "Vector3D.h"
#include "Segment3D.h"
class Intersector
{
private:
	const double eps = 0.00000001;//������������ �� ����������� ��������� ������ ��������� ����������
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
	bool checkIfInTheSamePlane();//�������� �� ��, ��� ������� ����� � ����� ���������
	bool checkIfIntersected();//��������, ����� �� ������� �����������
	bool checkIfCollinear();//�������� �������� �� ��������������
	bool checkIfSuperimposed();//�������� ������������� �� �������(���� �����������)
	Vector3D getIntersection();//���������� ����� �����������(���� ��� ����, ���� �����, �� ���� �� ����� ����������) - ��������� ������� �� ��
	void printInfo();//�������� ���������� � ���, ��� ����������� �������, ������� ����� �����������, ���� ��� ����
};

