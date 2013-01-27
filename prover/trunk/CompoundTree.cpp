#include "CompoundTree.h"

CompoundTree::CompoundTree()
{
  setInfix("");
  setPostfix("");
  setRoot(0);

}

CompoundTree::~CompoundTree()
{
  cout << "Deleting Root in Compound" << endl;
  //  delete root;
}

CompoundTree::CompoundTree(CompoundNode *r)
{
  setRoot(r);
}

CompoundTree::CompoundTree(vector<CompoundNode*> n)
{
  setNodes(n);
}


void CompoundTree::setNodes(vector<CompoundNode*> n)
{
  nodes = n;
}

void CompoundTree::setRoot(CompoundNode *r)
{
  root = r;
}

void CompoundTree::setInfix(string exp)
{
  infixExp = exp;
}
void CompoundTree::setPostfix(string exp)
{
  postfixExp = exp;
}


vector<CompoundNode*> CompoundTree::getNodes()
{
  return nodes;
}

CompoundNode* CompoundTree::getRoot()
{
  return root;
}

string CompoundTree::getInfix()
{
  return infixExp;
}

string CompoundTree::getPostfix()
{
  return postfixExp;
}
