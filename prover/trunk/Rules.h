/*
** Rules.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Wed Oct 15 18:30:00 2008 Sasan Padidar
** Last update Wed Oct 15 18:30:00 2008 Sasan Padidar
*/

#ifndef   	RULES_H_
# define   	RULES_H_

#include <vector>
#include <string>
#include <set>

#include <iostream>

using namespace std;

#include "Diagram.h"
#include "Zone.h"
#include "Contour.h"
#include "SyntaxChecker.h"

class Rules
{
 public:

  Rules(Diagram);
  ~Rules();
  
  //did not change this code becuase of the generate zones function
  vector<Contour> cLabels;//contour labels
  
  vector<Zone> allZones;//all zones
  
  vector<Zone> shadedZ;//shaded zones

  //Diagrm sets
  vector<Zone> selectedZones;//all zones
  
  vector<Zone> sz;//shaded zones

  Diagram addContour(Contour); //rule 1 add contour
  Diagram removeContour(Contour);//rule 2 remove contour
  vector<Zone> generateZones(); //generate zone combination
  Diagram addShadedZone(Zone);//rule 3 add shaded zone
  Diagram removeShadedZone(Zone);//rule 4 remove shaded zone
  
  vector<Zone> updateShadedZones(Contour); //Correct Shaded zones
 
  vector<Zone> updateSelectedZones(Contour);
  Diagram returnCurrentDiagram();
  void addPair(string , string );
  string createPair(string, string);

  
 private:
  Diagram diag;
};

#endif 	    /* !RULES_H_ */
