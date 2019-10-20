//���� ����� ��������� ���������� �������� ������.
//����� ������� ���: �������� ������� ��������,�������� ������,������ ������ �� �����, ���������� ���������, ������� �������� ����� �����������
//������ �� �������,��� �������� �������� ������� ��������, �� ��������� head=tail=nullptr;
#pragma once
#include "list_node.h"


template <class T>
class list_realisation
{
private:
	list_node * head;
	list_node * tail;
public:
	list_realisation();// initialisation with nullptr
	~list_realisation();// deleting list
	void printFuncList();// print list
	void addEl(T *file);// i need to add already existing element to the list
	void deletion();// deleting the list
	void insertion(list_node *previous,T *adress_of_el); // inserting element that already exist after the one we put in function
	list_node* search_name(string key);// searching by name, returns adress of an element with such name
	list_node* Get_head();//getter
	list_node* Get_tail();//getter
	void delete_element(list_node *el_to_delete);// deleting an element
};

#include "list_realisation.hxx"