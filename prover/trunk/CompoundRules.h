/*
** CompoundRules.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Sun Feb 22 09:26:48 2009 Sasan Padidar
** Last update Sun Feb 22 09:26:48 2009 Sasan Padidar
*/

#ifndef   	COMPOUNDRULES_H_
# define   	COMPOUNDRULES_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

#include "Diagram.h"
#include "CompoundNode.h"
#include "CompoundTree.h"
#include "InorderTraversal.h"

class CompoundRules 
{
 
 public:
  CompoundRules();
  ~CompoundRules();
  CompoundRules(CompoundTree);
  
  bool identityLaw();
  bool complementLawFirst();
  bool complementLawSecond();
  bool deMorganOr(vector<string>);
  bool deMorganOrReverse();
  bool deMorganAnd(vector<string>);
  bool deMorganAndReverse();
  
  vector<string> getResult();

  void displayResult();
 private:
  vector<CompoundNode*> nodes;
  CompoundTree tree;
  vector<string> result;
  
};


#endif 	    /* !COMPOUNDRULES_H_ */
