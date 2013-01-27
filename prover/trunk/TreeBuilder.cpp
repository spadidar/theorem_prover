#include "TreeBuilder.h"


TreeBuilder::TreeBuilder()
{

}

TreeBuilder::~TreeBuilder()
{
  delete tokenizer;

  for(int i = 0; i < nodes.size() ; i++)
    {
      cout << "Deleting nodes in TreeBuilder" << endl;
      //      delete nodes[i];
    }
}

TreeBuilder::TreeBuilder(string ex)
{
  setExpression(ex);
}

void TreeBuilder::build()
{
  tokenizer = new ExpressionTokenizer(expression);

  tokens = tokenizer->tokenize(); 

  cout  <<"\nExpression In Tree Builder SIZE::: " << expression.size() << endl;
  cout  <<"\nTokenizing ended SIZE::: " << tokens.size() << endl;

  postfixer.makePostfix(tokens); // create the postfix vec
  vector<string> postfix = postfixer.getPostfix(); // holder of the
						   // post fix array

  stack<CompoundNode*> nodeStack; //stack of pointers to hold nodes
				  //temp

  CompoundNode *root; //root holder

  //make tree
  for(int i = 0; i < postfix.size(); i++)
    {
      if(isBinaryOperator(postfix[i]))
	{
	  if(i == postfix.size() - 1) //if root
	    {
	      CompoundNode *node = new CompoundNode(postfix[i], true);

	      nodeStack.top()->setParent(node);
	      node->setRight(nodeStack.top());
	      nodeStack.pop();//pop from the stack

	      nodeStack.top()->setParent(node);
	      node->setLeft(nodeStack.top());
	      nodeStack.pop();//pop from the stack

	      nodeStack.push(node);
	      root = node;
	      cout<< "Root set: " <<node->getType() << endl;
	      cout<< "Root Right: " <<node->getRight()->getType() << endl;
	      cout<< "Root Left: " <<node->getLeft()->getType() << endl;
	    }
	  else
	    {
	      CompoundNode *node = new CompoundNode(postfix[i]);
	   
	      nodeStack.top()->setParent(node);//set parent
	      node->setRight(nodeStack.top());//setRight
	      nodeStack.pop();//pop from the stack

	      nodeStack.top()->setParent(node);//set parent
	      node->setLeft(nodeStack.top());//set left
	      nodeStack.pop();//pop from the stack

	      nodeStack.push(node);
	      cout<< "Binary set: " <<node->getType() << endl;
	      cout<< "Binary Right: " <<node->getRight()->getType() << endl;
	      cout<< "Binary Left: " <<node->getLeft()->getType() << endl;

	      nodes.push_back(node); // save node in the vec of pointers

	    }
	}
      else if(isUnaryOperator(postfix[i]))
	{
	  if(i == postfix.size() - 1) //if root
	    {
	      CompoundNode *node = new CompoundNode(postfix[i], true);

	      nodeStack.top()->setParent(node);
	      node->setRight(nodeStack.top());
	      nodeStack.pop();//pop from the stack
	      
	      node->setIsNotNode(true);
	      nodeStack.push(node);
	      
	      root = node; // make it the root

	      cout<< "Unary set: " <<node->getType() << endl;
	      cout<< "Unary Right: " <<node->getRight()->getType() << endl;
	      cout<< "Unary Left: " <<node->getLeft()->getType() << endl;

	    }
	  else
	    {
	      CompoundNode *node = new CompoundNode(postfix[i]);

	      nodeStack.top()->setParent(node);
	      node->setRight(nodeStack.top());
	      nodeStack.pop();//pop from the stack
	      node->setIsNotNode(true); // set its a not node
	      nodeStack.push(node);
	      
	      cout<< "Unaryy set: " <<node->getType() << endl;
	      cout<< "Unaryy Right: " <<node->getRight()->getType() << endl;
	      cout<< "Unary Left: " <<node->getLeft()->getType() << endl;

	      nodes.push_back(node); // save node in the vec of pointers
	    }
	}
      else if(isOperand(postfix[i]))
	{
	  DiagramLoader loader(postfix[i]);
	  loader.load();
	  Diagram dNode = loader.getDiagram();
	  
	  CompoundNode *node = new CompoundNode(dNode, "LEAF");
	  node->setIsLeaf(true);

	  nodeStack.push(node);
	  cout<< "LEAF: " <<node->getType() << endl;

	  nodes.push_back(node); // save node in the vec of pointers
	}
	
    }//end of for

  nodes.push_back(root); // save root at the end of vec of pointers
  tree.setRoot(root); // set tree's root
  tree.setNodes(nodes);
}

bool TreeBuilder::isBinaryOperator(string s)
{
  if(s == "AND")
    return true;

  else if(s == "OR")
    return true;

  return false;

}

bool TreeBuilder::isUnaryOperator(string s)
{
  if(s == "NOT")
    return true;
}

bool TreeBuilder::isOperand(string s)
{
  if(isBinaryOperator(s) || isUnaryOperator(s))
    return false;
 
  return true;
}


CompoundTree TreeBuilder::getTree()
{
  return tree;
}

void TreeBuilder::setExpression(string e)
{
  expression = e;
  tree.setInfix(e);
}
