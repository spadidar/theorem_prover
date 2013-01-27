#include "DiagramCreator.h"

DiagramCreator::DiagramCreator(string l, vector<Contour> cs, vector<Zone> zs, vector<Zone> szs)
{
  label = l;
  c = cs;
  z = zs;
  sz =szs;

}

Diagram DiagramCreator::createDiagram()
{
  SyntaxChecker *sc = new SyntaxChecker(z, sz);

  bool check = sc->check(); // check the syntax Prnts error if there
			    // is an error
  Diagram d (label, c, z, sz);

 // d = sc->purify(d);

  return d;
}

