/*
** DiagramHolder.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Nov  2 08:54:51 2008 Sasan Padidar
** Last update Sun Nov  2 08:54:51 2008 Sasan Padidar
*/

#ifndef   	DIAGRAMHOLDER_H_
# define   	DIAGRAMHOLDER_H_

#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

#include "Diagram.h"

class DiagramHolder
{
 public:
  
  void addDiagram(Diagram);
  vector<Diagram> getAllDiagrams();
  Diagram getDiagram(string);
  Diagram getLastDiagram();

  string printDiagram(Diagram);

  void updateDiagram(Diagram);
  void displayLabels();
  void displayAllDiagrams();
  void clear(); 
 private:
  
  vector<Diagram> diagrams;
 
};
#endif 	    /* !DIAGRAMHOLDER_H_ */
