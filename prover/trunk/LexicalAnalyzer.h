/*
** LexicalAnalyzer.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Nov  2 10:41:21 2008 Sasan Padidar
** Last update Sun Nov  2 10:41:21 2008 Sasan Padidar
*/

#ifndef   	LEXICALANALYZER_H_
# define   	LEXICALANALYZER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class LexicalAnalyzer 
{
 public:
  LexicalAnalyzer(string);
  bool scan();
  void tokenize();
  vector<string> getTokens();
  void readch();
  void displayTokens();

};
#endif 	    /* !LEXICALANALYZER_H_ */
