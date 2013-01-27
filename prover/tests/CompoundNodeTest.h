/*
** CompoundNodeTest.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Tue Feb 10 08:15:12 2009 Sasan Padidar
** Last update Tue Feb 10 08:15:12 2009 Sasan Padidar
*/

#ifndef   	COMPOUNDNODETEST_H_
# define   	COMPOUNDNODETEST_H_

#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../trunk/CompoundNode.h"
#include "../trunk/Diagram.h"

using namespace std;

class CompoundNodeTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (CompoundNodeTest);
    CPPUNIT_TEST (compoundNodeTest);
    CPPUNIT_TEST (hasTest);
    CPPUNIT_TEST (setLeftTest);
    CPPUNIT_TEST (setRightTest);
    CPPUNIT_TEST (getLeftTest);
    CPPUNIT_TEST (getRightTest);
    CPPUNIT_TEST_SUITE_END ();

 public:
  void setUp (void);
  void tearDown (void);
  
 protected:
  void compoundNodeTest();
  void hasTest();
  void setLeftTest();
  void setRightTest();
  void getLeftTest();
  void getRightTest();

 private:
  Diagram d1;
  Diagram d2;
  Diagram d3;
  Diagram d4;
  Diagram dEmpty;
  CompoundNode *p, *n1, *n2, *a, *b, *c, *d;

};

#endif 	    /* !COMPOUNDNODETEST_H_ */
