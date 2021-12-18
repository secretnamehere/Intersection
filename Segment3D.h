#pragma once
#include "Vector3D.h"
class Segment3D
{
private:
	Vector3D from;
	Vector3D to;
public:
	Segment3D();
	Segment3D(Vector3D from, Vector3D to);
	void setFrom(Vector3D from);
	void setTo(Vector3D to);
	Vector3D getTo();
	Vector3D getFrom();
	void printEndCoordinates();//�������� ���������� �������
	bool equals(Segment3D second);
	Vector3D getDirectionVector();//���������� ������������ ������ �������
	double getLength();//���������� ����� �������
};

