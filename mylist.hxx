#include "pch.h"



template <class T> mylist <T>::mylist(T val)
{
	next = nullptr;//����� ��� ���������� ������ � �� ������
	prev = nullptr;
	key = val;
}

template <class T> mylist <T>::mylist()
{
	next = nullptr;//����� ��� ���������� ������ � �� ������
	prev = nullptr;
	key = T();
}


template <class T> mylist <T>::~mylist()
{

}
