#include "pch.h"
#include "list_node.h"
/*��� "node" �����. ������� ����������� �� ��������� � �����������, ������� ������ �������� � ���� ������*/

list_node::list_node()
{
	next = nullptr;
	prev = nullptr;
	Catalog_info=Catalog();
	File_info = file();
	_type_of_element = not_setted;
}


  list_node::~list_node()
{

}


 void list_node::Set_type_of_el(type this_type)
{
	 _type_of_element = this_type;
}

 type list_node::Get_type()
{
	return _type_of_element;
}
