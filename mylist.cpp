#include "pch.h"
#include "mylist.h"


 template <class T> mylist <T>::mylist(T val)
{
	 next = nullptr;//����� ��� ���������� ������ � �� ������
	 prev = nullptr;
	 key = val;
}


 template <class T> mylist <T>::~mylist()
{

}
 /*template<class T>
 void mylist<T>::print_list()
 {
	 mylist<T> * tmp = this;
	 while (tmp) {
		 cout << tmp->key << "->";
		 tmp = tmp->next;
	 }
	 cout << tail ;//����� ����������� � ���������� � �� ���
 }*/