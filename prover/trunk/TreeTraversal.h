/*
** TreeTraversal.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Thu Feb 12 08:47:58 2009 Sasan Padidar
** Last update Thu Feb 12 08:47:58 2009 Sasan Padidar
*/

#ifndef   	TREETRAVERSAL_H_
# define   	TREETRAVERSAL_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

#include "Diagram.h"
#include "CompoundNode.h"

class TreeTraversal 
{
 
 public:
  
  TreeTraversal(vector<CompoundNode>);
  void traverse();
  void setNodes(vector<CompoundNode>);
  vector<CompoundNode> getNodes();
  
 private:
  vector<CompoundNode> nodes;

};
#endif 	    /* !TREETRAVERSAL_H_ */
