#include "pch.h"
#include "FILE.h"




file::file()//������� ����� ����, ������ ������ � ���������� 
{
	parent = nullptr;
	_file_type = string();
	_name = string();
	_size = 0;
	_time = Taime();
	_changed_time = Taime();
}


file::~file()
{
	
}

 void file::set_info(Catalog *father)
{	set_common_info();// basic class function 
	string temp_file_type;
	cout << "enter the file type : ";
	cin >> temp_file_type;
	_file_type = temp_file_type;
	
}

void file::print_info()//����� ���������� � ����� 
{
	print_common_info();
	cout << "File type: " << _file_type << '\n';

}
/**
������ ��� ��������� ���������� �� private ����
*/


 string file::Get_type() const
{
	return _file_type;
}
