#include "Contour.h"

Contour::Contour(string l)
{
  setLabel (l);
}

string Contour::getLabel()
{
  return label;
}

void Contour::setLabel(string l)
{
  label = l;
}

bool Contour::equals(Contour c)
{
  if(c.getLabel() == label)
    return true;

  return false;
}
