#include "DiagramLoader.h"

DiagramLoader::DiagramLoader()
{

}
DiagramLoader::DiagramLoader(string s)
{
  setURL(s);
}
DiagramLoader::~DiagramLoader()
{

}

void DiagramLoader::setURL(string s)
{
  url = s;
}

void DiagramLoader::load()
{
  LexicalAnalyzer la(url);
  la.scan();

  Parser parser (la.getTokens());
  parser.parse();
  string l =parser.getLabel();
  
  vector<Contour> c = parser.getContours();
  vector<Zone> z = parser.getZones();
  vector<Zone> sz = parser.getShadedZones();

  DiagramCreator dc (l, c,z,sz);
  
  diagram = dc.createDiagram();
}

Diagram DiagramLoader::getDiagram()
{
  return diagram;
}
