//this is a node class
// i think i should make it template because i have to make the list of catalogs also
#pragma once
#include "Catalog.h"
#include "File.h"
enum type
{
	not_setted , is_catalog , is_file
};
class list_node
{
	type _type_of_element;
public:
	void set_type_of_el(type this_type);
	list_node *next;
	list_node *prev;
	Catalog Catalog_info;
	file File_info;
	type Get_type();
	
	list_node();// ����� ����������� ������� ���������� � �������� �����
	~list_node();

};

#include "list_node.hxx"