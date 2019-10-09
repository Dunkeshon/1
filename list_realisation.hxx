#include "pch.h"



template <class T>list_realisation<T>::list_realisation()//�������� ������� ��������
{
	head = tail=nullptr;//������ ������� ������ 
	
}


template <class T>list_realisation<T>::~list_realisation()// ������� ������
{
	mylist *current = head;
	mylist *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

template<class T>
void list_realisation<T>::printFuncList()// ����� ������
{
	auto tmp = head;
	if (head != tail) {
		while (tmp){
			 tmp->info.print_info() ;
			cout << "######################" << endl;
			tmp = tmp->next;
		} 
		
	}
		else
		{
			tmp->info.print_info();
		}
	
}

template<class T>
void list_realisation<T>::addEl()// ���������� ��������
{
	mylist *temp = new mylist();
	temp->info.set_info();
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

template<class T>
void list_realisation<T>::deletion()// �������� ������
{
	auto current = head;
	auto temp = head;
	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

template<class T>
void list_realisation<T>::insertion(mylist *previous) // ������� ��������� ����� ��������,������� �� �������� � �������
{
	// ����� ������� ����������� ������ �������� � ��������� ��� �������- done
	mylist *p;//p-storring pointer to the next el
	mylist  * new_node = new mylist;
	new_node->info.set_info();
	p = previous->next;
	previous->next = new_node;
	new_node->next = p;
	new_node->prev = previous;
	if (p != nullptr) {
		p->prev = new_node;
	}
}
