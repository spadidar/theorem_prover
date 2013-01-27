/*
** CompoundNode.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-linux>
** 
** Started on  Sun Jan 11 20:58:52 2009 Sasan Padidar
** Last update Sun Jan 11 20:58:52 2009 Sasan Padidar
*/

#ifndef   	COMPOUNDNODE_H_
# define   	COMPOUNDNODE_H_

#include <string>
#include <iostream>

using namespace std;

#include "Diagram.h"

class CompoundNode 
{
 public:
 
  CompoundNode();
  CompoundNode(string);
  CompoundNode(Diagram, string);
  CompoundNode(string, bool); //for root
  CompoundNode(CompoundNode*, string); 
  CompoundNode(CompoundNode*, Diagram, string);
  CompoundNode(CompoundNode*, CompoundNode*, CompoundNode*, string);
  CompoundNode(CompoundNode*, CompoundNode*, CompoundNode*, Diagram, string);
  ~CompoundNode();

  virtual bool isLeaf();
  virtual bool isRoot();
  virtual bool isNotNode();
  virtual bool hasLeft();
  virtual bool hasRight();
  
  //--------------------------------gets
  virtual Diagram getPayload();
  virtual CompoundNode* getParent();
  virtual CompoundNode* getLeft();
  virtual CompoundNode* getRight();
  virtual string getType();

  //---------------------------------sets
  virtual void setLeft(CompoundNode*);
  virtual void setRight(CompoundNode*);
  virtual void setParent(CompoundNode *);  
  virtual void setPayload(Diagram);
  virtual void setType(string);
  virtual void setIsLeaf(bool);
  virtual void setIsRoot(bool);
  virtual void setIsNotNode(bool);
 private:

  Diagram payload;
  CompoundNode *left;
  CompoundNode *right;
  CompoundNode *parent;
  string type;
  bool leaf;
  bool root;  
  bool notNode;

};

#endif 	    /* !COMPOUNDNODE_H_ */
