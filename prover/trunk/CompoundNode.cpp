#include "CompoundNode.h"

CompoundNode::CompoundNode()
{
  setType("EmptyNode");
  setIsLeaf(false);  
  setIsRoot(false);
  setIsNotNode(false);
  
  payload.setLabel("Empty");
  setPayload(payload);
}

CompoundNode::CompoundNode(string t)
{
  setType(t);
  setIsRoot(false);
  setIsLeaf(false);
  setIsNotNode(false);
  payload.setLabel("Empty");
  setPayload(payload);

}

CompoundNode::CompoundNode(Diagram d, string t)
{
  setPayload(d);
  setType(t);
  setIsRoot(false);
  setIsLeaf(true);
  setLeft(0);
  setRight(0);
  setIsNotNode(false);
}

CompoundNode::CompoundNode(CompoundNode *p, string t)
{
  setParent(p);
  setType(t);
  setIsRoot(false);
  setIsLeaf(false);
  setIsNotNode(false);

  payload.setLabel("Empty");
  setPayload(payload);

} 

CompoundNode::CompoundNode(string t, bool r)
{
  setType(t);
  setIsRoot(r);
  setIsLeaf(false);
  setIsNotNode(false);

  payload.setLabel("Empty");
  setPayload(payload);

} 

CompoundNode::CompoundNode(CompoundNode *p, Diagram d, string t)
{
  setParent(p);
  setPayload(d);
  setType(t);
  setIsRoot(false);
  setIsLeaf(true);
  setLeft(0);
  setRight(0);
  setIsNotNode(false);
} 

CompoundNode::CompoundNode(CompoundNode *l, CompoundNode *r, CompoundNode *p, string t)
{
  setParent(p);
  setLeft(l);
  setRight(r);
  setType(t);
  setIsRoot(false);
  setIsLeaf(false);
  setIsNotNode(false);

  payload.setLabel("Empty");
  setPayload(payload);

} 

CompoundNode::CompoundNode(CompoundNode *l, CompoundNode *r, CompoundNode *p, Diagram value, string t)
{
  setParent(p);
  setLeft(l);
  setRight(r);
  setPayload(value);
  setType(t);
  setIsRoot(false);
  setIsLeaf(false);
  setIsNotNode(false);
} 
 

CompoundNode::~CompoundNode() {
}

void CompoundNode::setParent(CompoundNode *p)
{
  parent = p;
}

void CompoundNode::setLeft(CompoundNode *l)
{
  left = l;
}

void CompoundNode::setRight(CompoundNode *r)
{
  right = r;
}

void CompoundNode::setPayload(Diagram d)
{
  payload = d;
}

void CompoundNode::setType(string t)
{
  type = t;
}

CompoundNode* CompoundNode::getParent()
{
  return parent;
}
 
CompoundNode* CompoundNode::getLeft()
{
  if(isLeaf())
    {
      cout << "Getting Left of a Leaf is Null! " <<endl; 
      return 0;
    }
  return left;
}
 
CompoundNode* CompoundNode::getRight()
{
  if(isLeaf())
    {
      cout << "Getting Right of a Leaf is Null! " <<endl; 
      return 0;
    }

  return right;
} 

Diagram CompoundNode::getPayload()
{
  return payload;
} 

string CompoundNode::getType()
{
  return type;
}

bool CompoundNode::isLeaf()
{
  return leaf;
} 

void CompoundNode::setIsLeaf(bool l)
{
  leaf = l;
} 

bool CompoundNode::isRoot()
{
  return root;
} 

bool CompoundNode::isNotNode()
{
  return notNode;
} 

void CompoundNode::setIsRoot(bool l)
{
  root = l;
} 

void CompoundNode::setIsNotNode(bool l)
{
  notNode = l;
} 

bool CompoundNode::hasLeft()
{
  if(this->getLeft() != 0)
    return true;

  return false;
}

bool CompoundNode::hasRight()
{
  if(this->getRight() != 0)
    return true;

  return false;
}
