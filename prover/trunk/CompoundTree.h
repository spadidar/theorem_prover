/*
** CompoundTree.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Thu Feb 12 13:30:30 2009 Sasan Padidar
** Last update Thu Feb 12 13:30:30 2009 Sasan Padidar
*/

#ifndef   	COMPOUNDTREE_H_
# define   	COMPOUNDTREE_H_


#include <vector>
#include <string>
#include <set>

using namespace std;

#include "Diagram.h"
#include "CompoundNode.h"

class CompoundTree
{

 public:

  CompoundTree();
  ~CompoundTree();
  CompoundTree(vector<CompoundNode*>);
  CompoundTree(CompoundNode*);
  
  CompoundNode* getRoot();
  vector<CompoundNode*> getNodes();
  string getInfix();
  string getPostfix();

  void setNodes(vector<CompoundNode*>);
  void setRoot(CompoundNode*);
  void setInfix(string);
  void setPostfix(string);
  
 private:
  CompoundNode *root;
  vector<CompoundNode*> nodes;
  string infixExp;
  string postfixExp;

};
#endif 	    /* !COMPOUNDTREE_H_ */
