/*
** Parser.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sat Nov  1 10:23:45 2008 Sasan Padidar
** Last update Sat Nov  1 10:23:45 2008 Sasan Padidar
*/

#ifndef   	PARSER_H_
# define   	PARSER_H_

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>

#include <string>

using namespace std;

#include "Zone.h"
#include "Contour.h"

class Parser
{
 public:
  Parser(vector<string>);
  void parse();
  void nextToken();

  string getLabel();
  vector<Contour> getContours();
  vector<Zone> getZones();
  vector<Zone> getShadedZones();

  void labelHandler();
  void contourHandler();
  void zoneHandler();
  void shadedZHandler();

 private:
  string tok;
  vector<Contour> c;
  vector<Zone> z;
  vector<Zone> sz;

};
#endif 	    /* !PARSER_H_ */
