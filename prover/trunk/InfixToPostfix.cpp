#include "InfixToPostfix.h"

InfixToPostfix::InfixToPostfix()
{

}

InfixToPostfix::InfixToPostfix(vector<string> tokens)
{
  makePostfix(tokens);
}
/*
 *Shunting yard algorithm - modified 
 * makes the postfix expression
 */
void InfixToPostfix::makePostfix(vector<string> tokens)
{
  int i = 0;
  string token;

  while(i < tokens.size())
    {
      token = tokens[i];
      
      if(token == "(")
	{
	  infixS.push(token); //push on infix stack
	}
      else if(token == ")")
	{
	  while(infixS.top() != "(")
	  {
	    postfixQ.push_back(infixS.top());//record in post fix stack
	    infixS.pop();//empty stack by one
	  }

	  if(infixS.top() == "(") //if the start of infix is (
	    infixS.pop();// pop infix

	}
      else if(isOperator(token)) //if its an operator
	{
	  //while the scak has elements in it and the top of is not a bracket
	  while(!infixS.empty() && infixS.top() != "(" )
	    {
	      postfixQ.push_back(infixS.top()); //push the top of it
						//to postfix
	      infixS.pop();//pop from it
	    }
	  infixS.push(token);//push the token down to the stack
	}

      else if(isOperand(token))
	{
	  postfixQ.push_back(token);
	}
      
      i++; //increase the index
    }

  while(!infixS.empty())
    {
      postfixQ.push_back(infixS.top());
      infixS.pop();
    }
}
bool InfixToPostfix::isOperand(string t)
{
  if(isOperator(t))
    return false;

  else if( t == "(" || t == ")")
    return false;

  return true;
}
/*
 *checking if the node is an operator
 */
bool InfixToPostfix::isOperator(string t)
{
  if(t == "AND")
    return true;

  else if(t == "OR")
    return true;

  else if(t == "NOT")
    return true;

  return false;
}

vector<string> InfixToPostfix::getPostfix()
{
  return postfixQ;
}
/*
 *display the postfix expression
 */
void InfixToPostfix::displayPostfix()
{
  for(int i = 0; i< postfixQ.size(); i++)
    {
      cout << "QUEUE: " << postfixQ[i] << endl;
    }
}
