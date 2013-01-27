#include <iostream>

using namespace std;

#include "Diagram.h"


Diagram::Diagram(string l, vector<Contour> c, vector<Zone> z, vector<Zone> sz )
{
  setLabel(l);
  setContours(c);
  setSelectedZones(z);
  setAllZones(z);
  setShadedZones(sz);
}

Diagram::Diagram(string l)
{
  setLabel(l);
}

Diagram::Diagram()
{
}

Diagram::~Diagram()
{

}

void Diagram::setLabel(string label)
{
  diagramLabel = label;
}

void Diagram::setContours(vector<Contour> c)
{
  contours.clear();
  contours = c;
}

void Diagram::setSelectedZones(vector<Zone> z)
{
  zones.clear();
  zones = z;
}

void Diagram::setAllZones(vector<Zone> z)
{
  allZones.clear();
  allZones = z;
}

void Diagram::setShadedZones(vector<Zone> sz)
{
  shadedZones.clear();
  shadedZones = sz;
}

void Diagram::setAll(string l, vector<Contour> c, vector<Zone> z, vector<Zone> sz, vector<Zone> allZ )
{
  setLabel(l);
  setContours(c);
  setSelectedZones(z);
  setAllZones(allZ);
  setShadedZones(sz);
}


string Diagram::getLabel()
{
  return diagramLabel;
}
vector<Contour> Diagram::getContours()
{
  return contours;
}

vector<Zone> Diagram::getAllZones()
{
  return allZones;
}

vector<Zone> Diagram::getSelectedZones()
{
  return zones;
}

vector<Zone> Diagram::getShadedZones()
{
  return shadedZones;
}

void Diagram::displayLabel()
{
  cout << diagramLabel << endl;
}

void Diagram::displayContours()
{
  for(int i=0 ;i< contours.size(); i++)
	cout<< contours[i].getLabel() << " -- " ;

  cout <<  endl;
}

void Diagram::displaySelectedZones()
{
  for(int i=0 ;i< zones.size(); i++)
    {
      string p = createPair(zones[i].getZoneIn(), zones[i].getZoneOut());
      cout<< p << endl;
    }

}
void Diagram::displayAllZones()
{
  for(int i=0 ;i< allZones.size(); i++)
    {
      string p = createPair(allZones[i].getZoneIn(), allZones[i].getZoneOut());
      cout<< p << endl;
    }
  
}

void Diagram::displayShadedZones()
{
  for(int i=0 ;i< shadedZones.size(); i++)
    {
      string p = createPair(shadedZones[i].getZoneIn(), shadedZones[i].getZoneOut());
      cout<< p << endl;
    }
}

string Diagram::printLabel()
{
  string str = "Label: ";

  str.append(diagramLabel + "\n");
  
  return str;
}

string Diagram::printContours()
{
  string str = "Contours: { ";
  
  for(int i=0 ;i< contours.size(); i++)
    {
      string p = contours[i].getLabel();
      str.append( p );
      
      if(i < contours.size() - 1 )
	str.append( " , " );
    }

  str.append( " } \n" );

  return str;
}

string Diagram::printSelectedZones()
{
  string str = "Selected Zones: { ";
  for(int i=0 ;i< zones.size(); i++)
    {
      string p = createPair(zones[i].getZoneIn(), zones[i].getZoneOut());
      str.append( p  ); 

      if(i < zones.size() - 1 )
	str.append( " , " );

    }

  str.append( " }  \n" );

  return str;
}
string Diagram::printAllZones()
{
  string str = "All Zones: { ";
  for(int i=0 ;i< allZones.size(); i++)
    {
      string p = createPair(allZones[i].getZoneIn(), allZones[i].getZoneOut());
      str.append( p );

      if(i < allZones.size() - 1 )
	str.append( " , " );

    }
  str.append( " } \n" );
  return str;
}

string Diagram::printShadedZones()
{
  string str = "ShadedZones: { ";

  for(int i=0 ;i< shadedZones.size(); i++)
    {
      string p = createPair(shadedZones[i].getZoneIn(), shadedZones[i].getZoneOut());

      str.append( p );

      if(i < shadedZones.size() - 1 )
	str.append( " , " );

    }
  str.append( " } \n" );
  return str;
}

string Diagram::printDiagram()
{
  string str = "";
  
  str.append( printLabel() + "\n" );
  str.append( printContours() + "\n" );
  str.append( printSelectedZones() + "\n" );
  str.append( printShadedZones() + "\n" );
//   str.append( printAllZones() + "\n" );

  return str;
}
// Creates the pair 
string Diagram::createPair(string inc, string ex)
{
  string pair = "";
  pair = "(" + inc + " , " + ex + ")";  
  
  return pair;
}
