#include "CompoundRulesTest.h"

         
CPPUNIT_TEST_SUITE_REGISTRATION (CompoundRulesTest);

void CompoundRulesTest::setUp()
{
  e1 = "not ((d1 or d2) or (d3 and d4)) ";
  e2 = "not ((d1 or d2) and (d3 and d4)) ";

  ExpressionTokenizer *tokenizer = new ExpressionTokenizer(e2);

  tokens = tokenizer->tokenize();

}

void CompoundRulesTest::tearDown()
{
  
}

void CompoundRulesTest::compoundRulesTest()
{
  InfixToPostfix *infix2post = new InfixToPostfix (tokens);

  cout << "Displaying  Postfix" << endl;

  infix2post->displayPostfix();
  
  vector<string> postfix =  infix2post->getPostfix();
  
  CompoundRules r;

  bool b = r.deMorganAnd(postfix);
  if(b)
    r.displayResult();

  CPPUNIT_ASSERT(postfix.size() > 0);

  //the last node is a NOT node for this expression, check it
  CPPUNIT_ASSERT(postfix[postfix.size() -1] == "NOT" );

  CPPUNIT_ASSERT( r.getResult().size() > 0); //rule is applied

}
