#include "InorderTraversal.h"

InorderTraversal::InorderTraversal()
{

}

InorderTraversal::~InorderTraversal()
{
  cout << "Destroying the Traversal" <<endl;
}

InorderTraversal::InorderTraversal(vector<CompoundNode*> n)
{
  cout << "Started The Traversal Object" << endl;
  setNodes(n);
}

void InorderTraversal::setNodes(vector<CompoundNode*> n)
{
  nodes = n;
}

vector<CompoundNode*> InorderTraversal::getNodes()
{
  return nodes; //returns all nodes 
}

void InorderTraversal::traverse(CompoundNode *node)
{
  cout << "\nAT Start: \n" << node->getType() << endl;
  cout << "PayLoad: " <<node->getPayload().getLabel()<<endl;

  if (node->isLeaf())
    exp.append(node->getPayload().getLabel() + " ");

  if (node->hasLeft())
    {
      cout << "Left Before Traverse Node Type: " << node->getType() << endl;


      if(node->isLeaf())
	{
	  cout << "Left Part Node is Leaf" << endl;
	  cout << "Traverse Node Payload: " << node->getPayload().getLabel() << endl;
	}

      else if ( !node->isLeaf())
	{
	  cout << "Getting the Left node: " << node->getType() << endl;
	  traverse(node->getLeft());
	  cout << "Traverse Node Type: " << node->getType() << endl;
	  nodes.push_back(node);

	  exp.append( node->getType() + " ");
	}
    }

  if(node->hasRight())
    {
      cout << "Right Before Traverse Node Type: " << node->getType() << endl;

      if(node->isRoot())
	cout <<"ROOT --"  << endl;

      if(node->isLeaf())
	{
	  cout << "Right Part Node is Leaf" << endl;
	  cout << "Traverse Node Payload: " << node->getPayload().getLabel() << endl;
	}

      else if ( !node->isLeaf())
	{
	  cout << "Getting the Right node: " << node->getType() << endl;
	  traverse(node->getRight());
	  cout << "Traverse Node Type: " << node->getType() << endl;
// 	  exp.append( node->getType() + " ");
	}
    }

//   return str;
}

string InorderTraversal::getExpression()
{
  return exp;
}
