/*
** ExpressionTokenizer.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Tue Feb 17 08:57:21 2009 Sasan Padidar
** Last update Tue Feb 17 08:57:21 2009 Sasan Padidar
*/

#ifndef   	EXPRESSIONTOKENIZER_H_
# define   	EXPRESSIONTOKENIZER_H_

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class ExpressionTokenizer
{

 public:

  ExpressionTokenizer();
  ExpressionTokenizer(string);
  vector<string> tokenize();
  vector<string> parse();
  vector<string> getTokens();

  string getNext();
  bool hasNext();
  void displayTokens();
  void readch();
  void addChar(char);
  void setExpression(string);
  
 private:
  string expression;
  vector<string> tokens;
  char peek;
  string buffer;
  int index;

};

#endif 	    /* !EXPRESSIONTOKENIZER_H_ */
