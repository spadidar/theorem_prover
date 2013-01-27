#include "TreeBuilderTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION (TreeBuilderTest);

void TreeBuilderTest::setUp()
{
  e = "(../d/d1 and ../d/d2) and (../d/d3 or ../d/d4)";
}

void TreeBuilderTest::tearDown()
{

}

void TreeBuilderTest::treeBuilderTest()
{

  cout << "\nStarting Tree Builder..."  << endl;
  TreeBuilder builder(e);
  builder.build();
  cout <<"Building Ended..." << endl;
  CompoundTree tree = builder.getTree();

  CompoundNode *root = tree.getRoot();

  cout << "Root  Node:  " << root->getType() << endl;
  
  CPPUNIT_ASSERT(root->getType().size() > 0);
  CPPUNIT_ASSERT(tree.getNodes().size() > 0);
}
