#include "pch.h"
#include "list_realisation.h"


template <class T>list_realisation<T>::list_realisation(T FirstEl)
{
	head = new mylist<T>(FirstEl);//������ ������� ������-����� ������ mylist, ���������� �����������
	tail = head;
}


template <class T>list_realisation<T>::~list_realisation()
{
}

template<typename T>
void list_realisation<T>::printFuncList()
{
	head->printList();
}

template<typename T>
void list_realisation<T>::addEl(T val)
{
	mylist<T> *temp = new mylist<T>(val);
	if (head == nullptr) {
		head = temp;
		tail = temp;
		temp = nullptr; // �� ������ ����� �� ������ �����
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

