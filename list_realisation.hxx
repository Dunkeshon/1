#include "pch.h"
#include "list_realisation.h"



list_realisation::list_realisation()//�������� ������� ��������
{
	head = tail=nullptr;//������ ������� ������ 
	
}


list_realisation::~list_realisation()// ������� ������
{
	list_node<Catalog> *current = head;
	list_node<Catalog> *temp;

	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

void list_realisation::printFuncList()// ����� ������
{
	auto tmp = head;
	if (head != tail) {
		while (tmp){
			 tmp->info.print_info() ;
			cout << "######################" << endl;
			tmp = tmp->next;
		} 
	}
	else if ((head == tail)&&(head!=nullptr))
	{
		tmp->info.print_info();
	}
	else
	{
		cout << "list is empty" << endl;
	}
}


void list_realisation::addEl_Catalog( Catalog *Element)// ���������� ��������
{
	list_node<Catalog> *temp = new list_node<Catalog>();

	temp->info=Element;// OVERLOAD 

	// change set_info to seting info 
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
void list_realisation::addEl_File(file *Element)// ���������� ��������
{
	list_node<file> *temp = new list_node<file>();

	temp->info = Element;// OVERLOAD 

	
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
	
}

void list_realisation::deletion()// �������� ������
{
	auto current = head;
	auto temp = head;
	while (current)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
	tail = nullptr;
}

void list_realisation::insertion(list_node<Catalog> *previous, Catalog *element) // ������� ��������� ����� ��������,������� �� �������� � �������
{
	 if (previous->next == nullptr)
	{
		addEl(element);
		return;
	}
	else {
		// ����� ������� ����������� ������ �������� � ��������� ��� �������- done
		list_node<T> *p;//p-storring pointer to the next el
		list_node<T>  * new_node = new list_node<T>;
		//new_node->info = element , need to overload "=" 
		p = previous->next;
		previous->next = new_node;
		new_node->next = p;
		new_node->prev = previous;
		if (p != nullptr) {
			p->prev = new_node;
		}
	}
}

list_node<Catalog>* list_realisation::search_name(string key)
{
	list_node<Catalog> *temp = new list_node<Catalog>;
	temp = head;
	while (temp) {
		if (temp->info.Get_name() == key)
		{
			return temp;
		}
		else {
			temp = temp->next;
		}
	}
	cout << "file with this name doesn't exist" << endl;
	// ����� ������ �� ������ � ������� ������
	return nullptr;
}

 list_node<Catalog> * list_realisation::Get_head()
{

	return head;
}

 list_node<Catalog> * list_realisation::Get_tail()
 {
	 return tail;
 }

 void list_realisation::delete_element(list_node<Catalog> * el_to_delete)
 {	 if ((el_to_delete == head) && (el_to_delete == tail))
	 {
		 delete el_to_delete;
		 head = nullptr;
		 tail = nullptr;
		 cout << "element has been deleted" << endl;
		 return;
	 }
	 else if (el_to_delete==head) {
		 el_to_delete->next->prev = nullptr;
		 head = el_to_delete->next;
		 delete el_to_delete;
	 }
	 else if(el_to_delete==tail){
		 el_to_delete->prev->next = nullptr;
		 tail = el_to_delete->prev;
		 delete el_to_delete;
	 }
	 
	 else {
		 el_to_delete->prev->next = el_to_delete->next;
		 el_to_delete->next->prev = el_to_delete->prev;
		 delete el_to_delete;
	 }
	 cout << "element has been deleted" << endl;
 }
