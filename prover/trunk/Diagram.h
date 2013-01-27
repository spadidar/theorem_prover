/*
** Diagram.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Oct 12 08:34:05 2008 Sasan Padidar
** Last update Sun Oct 12 08:34:05 2008 Sasan Padidar
*/

#ifndef   	DIAGRAM_H_
# define   	DIAGRAM_H_
#include <vector>
#include <string>
#include <set>

using namespace std;

#include "Zone.h"
#include "Contour.h"

class Diagram
{
 public:
  Diagram();
  Diagram(string, vector<Contour>, vector<Zone>, vector<Zone>); //constructor
  Diagram(string);
  ~Diagram(); //destructor

  void setLabel(string);
  void setContours(vector<Contour>);
  void setSelectedZones(vector<Zone>);
  void setShadedZones(vector<Zone>);
  void setAllZones(vector<Zone>);
  void setAll (string, vector<Contour>, vector<Zone>, vector<Zone>, vector<Zone>);

  string getLabel();
  vector<Contour> getContours();
  vector<Zone> getSelectedZones();
  vector<Zone> getShadedZones();
  vector<Zone> getAllZones();

  string createPair(string, string);
  void displayLabel();
  void displayContours();
  void displaySelectedZones();
  void displayAllZones();
  void displayShadedZones();

  string printLabel();
  string printContours();
  string printSelectedZones();
  string printAllZones();
  string printShadedZones();

  string printDiagram();

 private:
  string diagramLabel;
  vector<Contour> contours;
  vector<Zone> zones;
  vector<Zone> shadedZones;
  vector<Zone> allZones;

};

#endif 	    /* !DIAGRAM_H_ */
