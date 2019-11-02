#include "TreeNode.h"
#pragma once



TreeNode::TreeNode()
{
	info=Catalog();
}


 TreeNode::~TreeNode()
{
}
 
 
 void TreeNode::create_file_children()
{
	 file new_node;
	 new_node.set_info(&info);//	�������� ������ �� ����
	 file_children.push_back(new_node);//	�������� � ������
	 cout << "file has been created inside catalog " << info.Get_name()<<endl;
}

 void TreeNode::create_catalog_children()
 {
	 TreeNode new_node;//	create new tree node
	 new_node.info.set_info(&info);//	create catalog
	 catalog_children.push_back(new_node);//	push to vector
	 cout << "catalog has been created inside catalog" << info.Get_name() << endl;
 }

file * TreeNode::search_child_file_by_name(string file_name)
{
	for (std::vector<file>::iterator it = file_children.begin(); it != file_children.end(); ++it) {
		if (it._Ptr->Get_name() == file_name)
		{
			return it._Ptr;
		}
	}
	cout << "there is no such file with this name" << endl;
	return nullptr;
	
}

TreeNode * TreeNode::search_child_catalog_by_name(string catalog_name)
{
	 for (std::vector<TreeNode>::iterator it = catalog_children.begin(); it != catalog_children.end(); ++it) {
		 if (it._Ptr->info.Get_name() == catalog_name)
		 {
			 return it._Ptr;
		 }
	 }
	 cout << "there is no such catalog with this name" << endl;
	 return nullptr;
}

void TreeNode::print_catalog_child_names()
{
	for(vector<TreeNode>::size_type i = 0; i != catalog_children.size; i++) 
	{
		cout << catalog_children[i].info.Get_name() << endl;
	}
}

  void TreeNode::print_file_child_names()
  {
	  for(vector<file>::size_type i = 0;i!=file_children.size();i++)
	  {
		  cout << file_children[i].Get_name() << endl;
	  }
  }
