#pragma once
#include "list_node.h"
class Quicksort
{
	/**
	@param [in] head A pointer to head of the list
	@param [in] end A pointer to tail of the list
	@param [in] newHead A pointer to newHead of the list that will be assigned to head after the sort
	@param [in] newTail A pointer to newTail of the list that will be assigned to tail after the sort
	*brief Partitions the list taking the last element as the pivot and compare based on time of creation
	@return The pivot node 
	*/
	list_node* Q_Sort_partition_time(list_node *head, list_node *end,list_node **newHead, list_node **newTail);
	/**
	@param [in] head A pointer to head of the list
	@param [in] end A pointer to tail of the list
	@param [in] newHead A pointer to newHead of the list that will be assigned to head after the sort
	@param [in] newTail A pointer to newTail of the list that will be assigned to tail after the sort
	*brief Partitions the list taking the last element as the pivot and compare based on changed_time
	@return The pivot node 
	*/
	list_node* Q_Sort_partition_changed_time(list_node *head, list_node *end, list_node **newHead, list_node **newTail);
	/**
	@param [in] head A pointer to head of the list
	@param [in] end A pointer to tail of the list
	@param [in] newHead A pointer to newHead of the list that will be assigned to head after the sort
	@param [in] newTail A pointer to newTail of the list that will be assigned to tail after the sort
	*brief Partitions the list taking the last element as the pivot and compare based on name 
	@return The pivot node 
	*/
	list_node* Q_Sort_partition_name(list_node *head, list_node *end, list_node **newHead, list_node **newTail);
	/**
	@param [in] head A pointer to head of the list
	@param [in] end A pointer to tail of the list
	@param [in] newHead A pointer to newHead of the list that will be assigned to head after the sort
	@param [in] newTail A pointer to newTail of the list that will be assigned to tail after the sort
	*brief Partitions the list taking the last element as the pivot and compare based on size
	@return The pivot node 
	*/
	list_node* Q_Sort_partition_size(list_node *head, list_node *end, list_node **newHead, list_node **newTail);
	/**
	@param [in] head A pointer to head of the list
	@param [in] end A pointer to tail of the list
	*brief Sort list using recur quicksort based on time of creation
	@return new head of the list
	*/
	list_node* _quickSort_time_recur(list_node *head, list_node *end);
	/**
	* brief gets pointer to tail
	@return pointer to tail
	*/
	list_node* getTail(list_node *cur);
public:
	/**
	@param [in] headRef pointer to head reference 
	*brief set new head and new tail to the list, in result of sorting by time of creation
	*/
	void quickSort_time(list_node **headRef);
	Quicksort();
	~Quicksort();
};
#include "Quicksort.hxx"
