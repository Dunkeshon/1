//���� ����� ��������� ���������� �������� ������.
//����� ������� ���: �������� ������� ��������,�������� ������,������ ������ �� �����, ���������� ���������, ������� �������� ����� �����������
//������ �� �������,��� �������� �������� ������� ��������, �� ��������� head=tail=nullptr;
#pragma once
#include "mylist.h"


template <class T>
class list_realisation
{
private:
	mylist * head;
	mylist * tail;
public:
	list_realisation();// initialisation with nullptr
	~list_realisation();// ������� ������
	void printFuncList();// ����� ������
	void addEl();// ���������� �������� 
	void deletion();// �������� ������
	void insertion(mylist *previous); // ������� ��������� ����� ��������,������� �� �������� � �������
	mylist* search_name(string key);// ����� �� �����, ���������� ����� �������� � ���� ���������
	mylist* Get_head();//getter
	mylist* Get_tail();//getter
	void delete_element(mylist *el_to_delete);// �������� ��������
};

#include "list_realisation.hxx"