/*
** SyntaxChecker.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sat Nov 15 01:24:38 2008 Sasan Padidar
** Last update Sat Nov 15 01:24:38 2008 Sasan Padidar
*/

#ifndef   	SYNTAXCHECKER_H_
# define   	SYNTAXCHECKER_H_

#include <string>
#include <vector>
#include <set>
#include <iostream>

#include <string>
#include <string>

using namespace std;

#include "Zone.h"
#include "Contour.h"
#include "Rules.h"

class SyntaxChecker
{
 public:
  
  SyntaxChecker(vector<Zone>, vector<Zone>);
  SyntaxChecker();

  bool checkZones();
  bool checkShadedZ();
  bool isSet(vector<Zone>);
  bool isSet(vector<Contour>);
  bool isSet(vector<Contour>, Contour);
  bool check();
  Diagram purify(Diagram);

 private:
  vector<Zone> z;
  vector<Zone> sz;
  vector<string> c;
  
};

#endif 	    /* !SYNTAXCHECKER_H_ */
