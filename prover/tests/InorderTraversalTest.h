/*
** InorderTraversalTest.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Thu Feb 12 10:14:18 2009 Sasan Padidar
** Last update Thu Feb 12 10:14:18 2009 Sasan Padidar
*/

#ifndef   	INORDERTRAVERSALTEST_H_
# define   	INORDERTRAVERSALTEST_H_


#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../trunk/CompoundNode.h"
#include "../trunk/Diagram.h"
#include "../trunk/InorderTraversal.h"
#include "../trunk/TreeTraversal.h"
#include "../trunk/TreeBuilder.h"
#include "../trunk/CompoundTree.h"

using namespace std;

class InorderTraversalTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (InorderTraversalTest);
    CPPUNIT_TEST (inorderTraversalTest);
   
    CPPUNIT_TEST_SUITE_END ();

 public:
  void setUp (void);
  void tearDown (void);
  
 protected:
  void inorderTraversalTest();
 
 private:
  InorderTraversal *i;
  CompoundTree tree;
  string e;
  CompoundNode *root;
};

#endif 	    /* !INORDERTRAVERSALTEST_H_ */
