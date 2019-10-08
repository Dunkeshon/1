//���� ����� ��������� ���������� �������� ������.
//����� ������� ���: �������� ������� ��������,�������� ������,������ ������ �� �����, ���������� ���������, ������� �������� ����� �����������
#pragma once
#include "mylist.h"


template <typename T>
class list_realisation
{
private:
	mylist<T> * head;
	mylist<T> * tail;
public:
	list_realisation(T FirstEl);//�������� ������� ��������
	~list_realisation();// ������� ������
	void printFuncList();// ����� ������
	void addEl(T val);// ���������� ��������
	void deletion();// �������� ������
	void insertion(mylist<T> *previous,T val); // ������� ��������� ����� ��������,������� �� �������� � �������
};

#include "list_realisation.hxx"