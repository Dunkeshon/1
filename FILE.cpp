#include "pch.h"
#include "FILE.h"



file::file()//������� ����� ����, ������ ������ � ���������� 
{
	//����� ����������� ������������ ��������� ������ 
	string temp_name, temp_time, temp_changed_time, temp_file_type;
	int temp_size;
	cout << "enter name : ";
	cin >> temp_name;
	cout << "enter size : ";
	cin >> temp_size;
	cout << "enter the time of creation : ";
	cin >> temp_time;
	cout << "enter the time of the last change : ";
	cin >> temp_changed_time;
	cout << "enter the file type : ";
	cin >> temp_file_type;
	_name = temp_name;
	_size = temp_size;
	_time = temp_time;
	_changed_time = temp_changed_time;
	_file_type = temp_file_type;
}


file::~file()
{
	//����� ����������� ������������ �������� ������ 
}

void file::print_info()//����� ���������� � ����� 
{
	cout <<'\t'<< "File info: "<<'\n';
	cout << "File _name: " << _name<< '\n';
	cout << "File _size: " << _size << '\n';
	cout << "Time of creation: " << _time << '\n';
	cout << "Time of the last change: " << _changed_time << '\n';
	cout << "File type: " << _file_type << '\n';

}
