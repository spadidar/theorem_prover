/*
** CompoundRulesTest.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Wed Apr 22 08:28:56 2009 Sasan Padidar
** Last update Wed Apr 22 08:28:56 2009 Sasan Padidar
*/

#ifndef   	COMPOUNDRULESTEST_H_
# define   	COMPOUNDRULESTEST_H_

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../trunk/ExpressionTokenizer.h"
#include "../trunk/InfixToPostfix.h"
#include "../trunk/CompoundRules.h"


using namespace std;

class CompoundRulesTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (CompoundRulesTest);
    CPPUNIT_TEST (compoundRulesTest);
   
    CPPUNIT_TEST_SUITE_END ();

 public:
  void setUp (void);
  void tearDown (void);
  
 protected: 
 void  compoundRulesTest();
 
 private:
  string e1;
  string e2;
  vector<string> tokens;
  
  
};

#endif 	    /* !COMPOUNDRULESTEST_H_ */
