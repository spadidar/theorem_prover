/*
** InfixPostfixTest.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Thu Feb 19 12:15:01 2009 Sasan Padidar
** Last update Thu Feb 19 12:15:01 2009 Sasan Padidar
*/

#ifndef   	INFIXPOSTFIXTEST_H_
# define   	INFIXPOSTFIXTEST_H_

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../trunk/ExpressionTokenizer.h"
#include "../trunk/InfixToPostfix.h"


using namespace std;

class InfixPostfixTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (InfixPostfixTest);
    CPPUNIT_TEST (infixPostfixTest);
   
    CPPUNIT_TEST_SUITE_END ();

 public:
  void setUp (void);
  void tearDown (void);
  
 protected: 
  void infixPostfixTest();
 
 private:
  string e;
  vector<string> tokens;
  
  
};


#endif 	    /* !INFIXPOSTFIXTEST_H_ */
