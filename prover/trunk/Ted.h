/*
** Ted.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Nov  2 08:47:42 2008 Sasan Padidar
** Last update Sun Nov  2 08:47:42 2008 Sasan Padidar
*/

#ifndef   	TED_H_
# define   	TED_H_

#include <string>
#include <vector>
#include <set>
#include <iostream>

#include <string>
#include <string>

using namespace std;

#include "Parser.h"
#include "SyntaxChecker.h"
#include "DiagramHolder.h"
#include "Diagram.h"
#include "Prover.h"
#include "DiagramCreator.h"
#include "Rules.h"
#include "LexicalAnalyzer.h"
#include "Zone.h"
#include "ProofWriter.h"
#include "Contour.h"
#include "InfixToPostfix.h"
#include "ExpressionTokenizer.h"
#include "CompoundRules.h"

class Ted
{
 public:
  
  int main();
  Diagram getDiagram(string);
  void generateProof(DiagramHolder);
  
};
#endif 	    /* !TED_H_ */
