#include "CompoundNodeTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION (CompoundNodeTest);

void CompoundNodeTest::setUp()
{
  p = new CompoundNode("AND", true);
  n1 = new CompoundNode(p, "and");
  n2 = new CompoundNode(p, "and");
  a = new CompoundNode(d1,"leaf d1");
  b = new CompoundNode(d2,"leaf d2");
  c = new CompoundNode(d3,"leaf d3");
  d = new CompoundNode(d4,"leaf d4");
  
  dEmpty.setLabel("empty");
  d1.setLabel("d1");
  d2.setLabel("d2");
  d3.setLabel("d3");
  d4.setLabel("d4");
}

void CompoundNodeTest::tearDown()
{

}

void CompoundNodeTest::compoundNodeTest()
{
   
  p->setLeft(n1);
  p->setRight(n2);
  n1->setLeft(a);
  n1->setRight(b);
  n2->setLeft(c);
  n2->setRight(d);
  
  cout << "\n" << p->getType() << p->isRoot() << endl;

  cout << "Roots Left: " << p->getLeft()->getType() << endl;
  cout << "Roots Right: " << p->getRight()->getType() << endl;

  cout << "R->Left->Left: " << p->getLeft()->getLeft()->getType() << endl;
  cout << "R->Left->Left: " << p->getLeft()->getRight()->getType() << endl;
  cout << "R->Right->Left  : " << p->getRight()->getLeft()->getType() << endl;
  cout << "R->Right->Right : " << p->getRight()->getRight()->getType() << endl;
  cout << n1->getType() << endl;
  cout << n2->getType() << endl;
  cout << a->getType() << endl;
  cout << b->getType() << endl;
  cout << c->getType() << endl;
  cout << d->getType() << endl;
  
  cout << "Has Left: " << p->hasLeft() << endl;
  cout << "Has right: " << p->hasRight() << endl;


  CPPUNIT_ASSERT (p->hasLeft() == true);
  CPPUNIT_ASSERT (p->hasRight() == true);
}

void CompoundNodeTest::hasTest()
{
  
}

void CompoundNodeTest::setLeftTest()
{
  Diagram d1("d1");
  Diagram d2("d2");
  Diagram d("empty");

  CompoundNode *p = new CompoundNode("root");
  CompoundNode *a = new CompoundNode(d1,"leaf");
  CompoundNode *b = new CompoundNode(d2,"leaf");
  
  Diagram dd = a->getPayload();
  cout << "Diagram is : " << dd.getLabel() << endl;
}

void CompoundNodeTest::setRightTest()
{

}

void CompoundNodeTest::getLeftTest()
{

}

void CompoundNodeTest::getRightTest()
{

}
