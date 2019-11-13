#include "insertionSort.h"

#pragma once
/*
 ���� �� ������ ���������� � ���������� - ������ ������ ������ ������ �� ������ �������. 
 ���� ������ ������ ������ ������ ��� ����� ������ �������� - ������ ����� ������� ����� ������� ������ ������, ����� ������� ������ �� ���� �������
 � ��������� ������ ������� ��������� ���������� current , ������� ����������� �������� ������ ������ ������ � ��������� ������ �� ������ , ���� �� ������ 
 ������� ������� ����� ������ ������� . ��� �������� ���������� � ��������� ����, ����� ��� ������ ����� � list_node � � ����������� �� ����� ����� ������ ��� 
 ��������� ������ �� ���� ���� ������, ������� ��� �����, ��������� ���� � list_node ������������ ���� - �� � ������ catalog ������� list_node ����� ���� 
 ��������� ���������� �� ������� ��������
 */
void insertionSort::sortedInsert_time(list_node** head_ref, list_node* new_node)
{
	list_node* current;
	if (*head_ref == nullptr )
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_time() >= new_node->Catalog_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_time() >= new_node->File_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_time() >= new_node->Catalog_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_time() >= new_node->File_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		/* Locate the node before the point of insertion */
		current = *head_ref;
		Taime current_next_data;
		Taime new_node_data;
		if ((current->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
			current_next_data = current->next->Catalog_info.Get_time();
			new_node_data = new_node->Catalog_info.Get_time();
		}
		else if ((current->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
			current_next_data = current->next->File_info.Get_time();
			new_node_data = new_node->Catalog_info.Get_time();
		}
		else if ((current->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
			current_next_data = current->next->Catalog_info.Get_time();
			new_node_data = new_node->File_info.Get_time();
		}
		else if ((current->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
			current_next_data = current->next->File_info.Get_time();
			new_node_data = new_node->File_info.Get_time();
		}
		while (current->next != nullptr &&
			current_next_data < new_node_data)
		{
			// change data that we will compare next
			if ((current->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->Catalog_info.Get_time();
				new_node_data = new_node->Catalog_info.Get_time();
			}
			else if ((current->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
				current_next_data = current->next->File_info.Get_time();
				new_node_data = new_node->Catalog_info.Get_time();
			}
			else if ((current->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->Catalog_info.Get_time();
				new_node_data = new_node->File_info.Get_time();
			}
			else if ((current->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
				current_next_data = current->next->File_info.Get_time();
				new_node_data = new_node->File_info.Get_time();
			}
			// changing pointers 
			list_node * temp = current; 
			current = current->next;
			current->prev = temp; 
			
		}
		new_node->next = current->next;
		if (new_node->next != nullptr) {
			new_node->next->prev = new_node; // last update
		}
		current->next = new_node;
		new_node->prev = current;
	}
}
/*
void insertionSort::sortedInsert_time(list_node** head_ref, list_node* new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_time() >= new_node->Catalog_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_time() >= new_node->File_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_time() >= new_node->Catalog_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_time() >= new_node->File_info.Get_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
			// Locate the node before the point of insertion 
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_time() < new_node->Catalog_info.Get_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			if (new_node->next != nullptr) {
				new_node->next->prev = new_node; // last update
			}
			current->next = new_node;
			new_node->prev = current;
		}
		// other casses
		else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
			// Locate the node before the point of insertion 
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_time() < new_node->File_info.Get_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			if (new_node->next != nullptr) {
				new_node->next->prev = new_node; // last update
			}
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
			// Locate the node before the point of insertion 
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_time() < new_node->Catalog_info.Get_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			if (new_node->next != nullptr) {
				new_node->next->prev = new_node; // last update
			}
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
			// Locate the node before the point of insertion 
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_time() < new_node->File_info.Get_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			if (new_node->next != nullptr) {
				new_node->next->prev = new_node; // last update
			}
			current->next = new_node;
			new_node->prev = current;
		}
	}
}
*/





void insertionSort::sortedInsert_changed_time(list_node ** head_ref, list_node * new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_changed_time() >= new_node->Catalog_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_changed_time() >= new_node->File_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_changed_time() >= new_node->Catalog_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_changed_time() >= new_node->File_info.Get_changed_time()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_changed_time() < new_node->Catalog_info.Get_changed_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		// other casses
		else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_changed_time() < new_node->File_info.Get_changed_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_changed_time() < new_node->Catalog_info.Get_changed_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_changed_time() < new_node->File_info.Get_changed_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}

void insertionSort::sortedInsert_name(list_node ** head_ref, list_node * new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_name() >= new_node->Catalog_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_name() >= new_node->File_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_name() >= new_node->Catalog_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_name() >= new_node->File_info.Get_name()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_name() < new_node->Catalog_info.Get_name())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		// other casses
		else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_name() < new_node->File_info.Get_name())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_name() < new_node->Catalog_info.Get_name())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_name() < new_node->File_info.Get_name())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}

void insertionSort::sortedInsert_size(list_node ** head_ref, list_node * new_node)
{
	list_node* current;
	if (*head_ref == nullptr)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog) && ((*head_ref)->Catalog_info.Get_size() >= new_node->Catalog_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file) && ((*head_ref)->Catalog_info.Get_size() >= new_node->File_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog) && ((*head_ref)->File_info.Get_size() >= new_node->Catalog_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file) && ((*head_ref)->File_info.Get_size() >= new_node->File_info.Get_size()))
	{
		new_node->next = *head_ref;
		(*head_ref)->prev = new_node; //ADDED 
		*head_ref = new_node;
	}
	// other casses
	else
	{
		if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_size() < new_node->Catalog_info.Get_size())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		// other casses
		else if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_file)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_size() < new_node->File_info.Get_size())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_catalog)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_size() < new_node->Catalog_info.Get_size())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
		else if (((*head_ref)->Get_type() == is_file) && (new_node->Get_type() == is_file)) {
			/* Locate the node before the point of insertion */
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->File_info.Get_size() < new_node->File_info.Get_size())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}

/*
void insertionSort::sortedInsert_time(list_node** head_ref, list_node* new_node) 
{
	if (((*head_ref)->Get_type() == is_catalog) && (new_node->Get_type() == is_catalog))
	{
		list_node* current;
		//Special case for the head end 
		if (*head_ref == nullptr || (*head_ref)->Catalog_info.Get_time() >= new_node->Catalog_info.Get_time())
		{
			new_node->next = *head_ref;
			(*head_ref)->prev = new_node; //ADDED 
			*head_ref = new_node;
		}
		else
		{
			// Locate the node before the point of insertion 
			current = *head_ref;
			while (current->next != nullptr &&
				current->next->Catalog_info.Get_time()< new_node->Catalog_info.Get_time())
			{
				list_node * temp = current; // add
				current = current->next;
				current->prev = temp; // add
			}
			new_node->next = current->next;
			current->next = new_node;
			new_node->prev = current;
		}
	}
}
*/
void insertionSort::insertionSort_time(list_node **head_ref) {
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_time(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
void insertionSort::insertionSort_changed_time(list_node ** head_ref)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_changed_time(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
void insertionSort::insertionSort_name(list_node ** head_ref)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_name(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
void insertionSort::insertionSort_size(list_node ** head_ref)
{
	// Initialize sorted linked list 
	list_node *sorted = nullptr;

	// Traverse the given linked list and insert every 
	// node to sorted 
	list_node *current = *head_ref;
	while (current != nullptr)
	{
		// Store next for next iteration 
		list_node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert_size(&sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	*head_ref = sorted;
}
insertionSort::insertionSort()
{
}


insertionSort::~insertionSort()
{
}
