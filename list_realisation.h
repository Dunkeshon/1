//���� ����� ��������� ���������� �������� ������.
//����� ������� ���: �������� ������� ��������,�������� ������,������ ������ �� �����, ���������� ���������, ������� �������� ����� �����������
#pragma once
#include "mylist.h"


template <class T>
class list_realisation
{
private:
	mylist * head;
	mylist * tail;
public:
	list_realisation(file *FirstEl);//�������� ������� ��������
	~list_realisation();// ������� ������
	void printFuncList();// ����� ������
	void addEl();// ���������� �������� ����� �������� ����� �� ���������
	void deletion();// �������� ������
	void insertion(mylist *previous); // ������� ��������� ����� ��������,������� �� �������� � �������
};

#include "list_realisation.hxx"