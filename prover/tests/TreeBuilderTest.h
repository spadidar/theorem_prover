/*
** TreeBuilderTest.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Sat Feb 21 08:51:45 2009 Sasan Padidar
** Last update Sat Feb 21 08:51:45 2009 Sasan Padidar
*/

#ifndef   	TREEBUILDERTEST_H_
# define   	TREEBUILDERTEST_H_

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../trunk/TreeBuilder.h"
#include "../trunk/CompoundTree.h"
#include "../trunk/CompoundNode.h"
#include "../trunk/InorderTraversal.h"

using namespace std;

class TreeBuilderTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (TreeBuilderTest);
    CPPUNIT_TEST (treeBuilderTest);
   
    CPPUNIT_TEST_SUITE_END ();

 public:
  void setUp (void);
  void tearDown (void);
  
 protected: 
  void treeBuilderTest();
 
 private:
  string e;

  
  
};



#endif 	    /* !TREEBUILDERTEST_H_ */
