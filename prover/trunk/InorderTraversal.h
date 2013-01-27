/*
** InorderTraversal.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Thu Feb 12 08:48:25 2009 Sasan Padidar
** Last update Thu Feb 12 08:48:25 2009 Sasan Padidar
*/

#ifndef   	INORDERTRAVERSAL_H_
# define   	INORDERTRAVERSAL_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

#include "Diagram.h"
#include "CompoundNode.h"

class InorderTraversal 
{
 
 public:
  InorderTraversal();
  ~InorderTraversal();
  InorderTraversal(vector<CompoundNode*>);
  void traverse(CompoundNode*);
  void setNodes(vector<CompoundNode*>);
  vector<CompoundNode*> getNodes();

  string getExpression();

 private:
  vector<CompoundNode*> nodes;
  string exp;
};



#endif 	    /* !INORDERTRAVERSAL_H_ */
