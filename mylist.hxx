#include "pch.h"
#include "mylist.h"
/*��� "node" �����. ������� ����������� �� ��������� � �����������, ������� ������ �������� � ���� ������*/


 mylist ::mylist(file* val)// ����� �������� ����� �� ���������
{
	next = nullptr;
	prev = nullptr;
	info = val;
}

 mylist ::mylist()
{
	next = nullptr;
	prev = nullptr;
	info = file();// �� ���� ����� ��
}


 mylist ::~mylist()
{

}
