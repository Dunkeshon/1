#include "pch.h"
#include "list_node.h"
/*��� "node" �����. ������� ����������� �� ��������� � �����������, ������� ������ �������� � ���� ������*/




 list_node ::list_node()
{
	next = nullptr;
	prev = nullptr;
	info = file();
}


 list_node ::~list_node()
{

}
