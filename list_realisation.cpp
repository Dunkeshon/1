#include "pch.h"
#include "list_realisation.h"


template <class T>list_realisation<T>::list_realisation(T FirstEl)
{
	begin = new mylist<T>(FirstEl);//������ ������� ������-����� ������ mylist, ���������� �����������
	end = begin;
}


template <class T>list_realisation<T>::~list_realisation()
{
}

template<typename T>
void list_realisation<T>::printFuncList()
{
	begin->printList();
}

