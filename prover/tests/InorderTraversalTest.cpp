#include "InorderTraversalTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION (InorderTraversalTest);

void InorderTraversalTest::setUp()
{
  e = "(../d/d1 and ../d/d2) and (../d/d3 or ../d/d4)";
  TreeBuilder builder(e);
  builder.build();
  
  tree = builder.getTree();

  root  = tree.getRoot();
  
}

void InorderTraversalTest::tearDown()
{
  delete root;
}

void InorderTraversalTest::inorderTraversalTest()
{
  i = new InorderTraversal();
  i->traverse(root);
  cout<< "Traversal finished" <<endl;
  //currently not implemented
  //string s =  i->getExpression();
  
  //CPPUNIT_ASSERT(s == "(d1 AND d2) AND (d3 OR d3)" );
}
