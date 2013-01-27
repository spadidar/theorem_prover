/*
** ExpressionTokenizerTest.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Tue Feb 17 15:33:52 2009 Sasan Padidar
** Last update Tue Feb 17 15:33:52 2009 Sasan Padidar
*/

#ifndef   	EXPRESSIONTOKENIZERTEST_H_
# define   	EXPRESSIONTOKENIZERTEST_H_

#include <string>
#include <iostream>
#include <vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../trunk/ExpressionTokenizer.h"

using namespace std;

class ExpressionTokenizerTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (ExpressionTokenizerTest);
    CPPUNIT_TEST (expressionTokenizerTest);
   
    CPPUNIT_TEST_SUITE_END ();

 public:
  void setUp (void);
  void tearDown (void);
  
 protected: 
  void expressionTokenizerTest();
 
 private:
  string e;
  vector<string> tokens;
  
};

#endif 	    /* !EXPRESSIONTOKENIZERTEST_H_ */
