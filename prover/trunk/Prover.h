/*
** Prover.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Nov  2 08:55:53 2008 Sasan Padidar
** Last update Sun Nov  2 08:55:53 2008 Sasan Padidar
*/

#ifndef   	PROVER_H_
# define   	PROVER_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

#include "Diagram.h"
#include "Rules.h"
#include "DiagramHolder.h"
#include "Zone.h"
#include "Contour.h"
#include "SetMaker.h"

class Prover 
{
 public:

  void getDiagramHolder(vector<Diagram>);
  Diagram addMissingZones(Diagram);
  Diagram addMissingContours(Diagram, Diagram);
  Diagram addShadedZones(Diagram);

  DiagramHolder getHolder();
  bool prove(Diagram, Diagram);
  bool compareZones(string, string);
  void clear();
 private:
  DiagramHolder holder;


};

#endif 	    /* !PROVER_H_ */
