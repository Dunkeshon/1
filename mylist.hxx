#include "pch.h"
#include "mylist.h"
/*��� "node" �����. ������� ����������� �� ��������� � �����������, ������� ������ �������� � ���� ������*/


template <class T> mylist <T>::mylist(T val)
{
	next = nullptr;
	prev = nullptr;
	key = val;
}

template <class T> mylist <T>::mylist()
{
	next = nullptr;
	prev = nullptr;
	key = T();
}


template <class T> mylist <T>::~mylist()
{

}
