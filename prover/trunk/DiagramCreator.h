/*
** DiagramCreator.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Nov  2 08:54:32 2008 Sasan Padidar
** Last update Sun Nov  2 08:54:32 2008 Sasan Padidar
*/

#ifndef   	DIAGRAMCREATOR_H_
# define   	DIAGRAMCREATOR_H_

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

#include "Diagram.h"
#include "Contour.h"
#include "SyntaxChecker.h"

class DiagramCreator
{
 public:

  DiagramCreator(string,vector<Contour>,vector<Zone>,vector<Zone>);
  Diagram createDiagram();
 
 private:

  string label ;
  vector<Contour> c;
  vector<Zone> z;
  vector<Zone> sz;

};

#endif 	    /* !DIAGRAMCREATOR_H_ */
