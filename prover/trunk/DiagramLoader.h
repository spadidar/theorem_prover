/*
** DiagramLoader.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-ubuntu64>
** 
** Started on  Fri Feb 20 15:17:14 2009 Sasan Padidar
** Last update Fri Feb 20 15:17:14 2009 Sasan Padidar
*/

#ifndef   	DIAGRAMLOADER_H_
# define   	DIAGRAMLOADER_H_

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

#include "Parser.h"
#include "SyntaxChecker.h"
#include "Diagram.h"
#include "DiagramCreator.h"
#include "LexicalAnalyzer.h"
#include "Diagram.h"

class DiagramLoader
{

 public:
  DiagramLoader();
  DiagramLoader(string);
  ~DiagramLoader();
  void load();
  Diagram getDiagram();
  void setURL(string);


 private:
  Diagram diagram;
  string url;

};

#endif 	    /* !DIAGRAMLOADER_H_ */
