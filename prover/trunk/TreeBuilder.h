/*
** TreeBuilder.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Tue Feb 17 08:33:34 2009 Sasan Padidar
** Last update Tue Feb 17 08:33:34 2009 Sasan Padidar
*/

#ifndef   	TREEBUILDER_H_
# define   	TREEBUILDER_H_

#include <vector>
#include <string>
#include <stack>

using namespace std;

#include "Diagram.h"
#include "InfixToPostfix.h"
#include "CompoundNode.h"
#include "ExpressionTokenizer.h"
#include "CompoundTree.h"
#include "DiagramLoader.h" 

class TreeBuilder
{

 public:
  
  TreeBuilder();
  TreeBuilder(string);
  ~TreeBuilder();
  void build();
  void setExpression(string);
  
  CompoundTree getTree();
  vector<CompoundNode*> getTreeNodes();
  
  bool isBinaryOperator(string);
  bool isUnaryOperator(string);
  bool isOperand(string);

 private:
  
  ExpressionTokenizer *tokenizer;
  vector<string> tokens;
  InfixToPostfix postfixer;
  
  string expression;
  CompoundTree tree;
  vector<CompoundNode*> nodes;

};



#endif 	    /* !TREEBUILDER_H_ */
