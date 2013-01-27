/*
** InfixToPostfix.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Tue Feb 17 08:38:28 2009 Sasan Padidar
** Last update Tue Feb 17 08:38:28 2009 Sasan Padidar
*/

#ifndef   	INFIXTOPOSTFIX_H_
# define   	INFIXTOPOSTFIX_H_

#include <vector>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class InfixToPostfix
{

 public:
  InfixToPostfix();
  InfixToPostfix(vector<string>);
  void makePostfix(vector<string>);
  vector<string> getPostfix();
  bool isOperator(string);
  bool isOperand(string);
  void displayPostfix();

 private:
  stack<string> infixS;
/*   queue<string> postfixQ; */
  vector<string> postfixQ;

};

#endif 	    /* !INFIXTOPOSTFIX_H_ */
