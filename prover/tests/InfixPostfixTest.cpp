#include "InfixPostfixTest.h"

         
CPPUNIT_TEST_SUITE_REGISTRATION (InfixPostfixTest);

void InfixPostfixTest::setUp()
{
//   e = "(d1 and d2) and (not d3)";
//   e = "(d1 and d2) and (d3 or d4)";
  e = "not( (d1 and d2) and (not d3))";

  ExpressionTokenizer *tokenizer = new ExpressionTokenizer(e);

  tokens = tokenizer->tokenize();

}

void InfixPostfixTest::tearDown()
{
  
}

void InfixPostfixTest::infixPostfixTest()
{
  InfixToPostfix *infix2post = new InfixToPostfix (tokens);

  cout << "Displaying  Postfix" << endl;

  infix2post->displayPostfix();
  vector<string> infix =  infix2post->getPostfix();
  

  CPPUNIT_ASSERT(infix.size() > 0);

  //the last node is a NOT node for this expression, check it
  CPPUNIT_ASSERT(infix[infix.size() -1] == "NOT" );


}
