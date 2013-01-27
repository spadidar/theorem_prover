#include "ExpressionTokenizerTest.h"

         
CPPUNIT_TEST_SUITE_REGISTRATION (ExpressionTokenizerTest);

void ExpressionTokenizerTest::setUp()
{
  e = "(d1 and d2) and not d3";
}

void ExpressionTokenizerTest::tearDown()
{

}

void ExpressionTokenizerTest::expressionTokenizerTest()
{
  ExpressionTokenizer *tokenizer = new ExpressionTokenizer (e);
  tokens =   tokenizer->tokenize();

  cout<< "\n Displaying tokens" << endl;  
  tokenizer->displayTokens();

  CPPUNIT_ASSERT(tokens.size() > 0);
}
