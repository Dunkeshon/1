#include "pch.h"
#include "list_node.h"
/*��� "node" �����. ������� ����������� �� ��������� � �����������, ������� ������ �������� � ���� ������*/




 template <class T> list_node <T> ::list_node()
{
	next = nullptr;
	prev = nullptr;
	info = T();
}


 template <class T> list_node <T> ::~list_node()
{

}
