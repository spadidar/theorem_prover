#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker(vector<Zone> zones, vector<Zone> shz)
{
  z = zones;
  sz = shz;
}

SyntaxChecker::SyntaxChecker()
{

}
bool SyntaxChecker::check()
{
  bool zCheck = isSet(z);
  bool szCheck =  checkShadedZ();
  bool szSet =  isSet(sz);

  if(zCheck == false)
    {
      cout << "There exists duplicate Zones in Zones set !" << endl;
      return false;
    }

  if(szSet == false)
    {
      cout << "There exists duplicate Zones in Shaded Zones set !" << endl;
      return false;
    }

  return true;
}

bool SyntaxChecker::checkZones()
{

}

bool SyntaxChecker::checkShadedZ()
{
  
  for (int i=0; i<sz.size();i++)
    {
      bool isSubset = false;

      for(int j = 0; j < z.size(); j++)
	{
	  if(sz[i].equals(z[j]))
	    {
	      isSubset = true;
	    }
	}

      if(isSubset == false)
	{
	  cout << "Syntax Error: -> " << sz[i].getPair(); 
	  cout << "  is Not a subset of the Zones set!" <<endl;  
	  return false;
	}
    }

  return true;

}

bool SyntaxChecker::isSet(vector<Zone> zVec)
{
  for (int i=0; i < zVec.size(); i++)
    {
      for(int j = 0; j < zVec.size(); j++)
	{
	  if(zVec[i].equals(zVec[j]) && i != j)
	    {
	      cout << "There exists duplicate Zone(s) in set! ** " ;
	      cout << zVec[i].getPair()<< " ** is equal: ";
	      cout << zVec[j].getPair() << endl;
	      return false;
	    }
	}
    }

  return true;
}

bool SyntaxChecker::isSet(vector<Contour> c)
{
  for (int i=0; i < c.size(); i++)
    {
      for(int j = 0; j < c.size(); j++)
	{
	  if(c[i].equals(c[j]) && i != j)
	    {
	      cout << "There exists duplicate Contour(s) in Contour's set! ** " ;
	      cout << c[i].getLabel()<< " ** is equal: ";
	      cout << c[j].getLabel() << endl;
	      return false;
	    }
	}
    }

  return true;
}

bool SyntaxChecker::isSet(vector<Contour> c, Contour n)
{
  c.push_back(n);

  if(!isSet(c))
    {
      return false;
    }

  return true;
}

Diagram SyntaxChecker::purify(Diagram d)
{
  vector<Zone> selectedZones = d.getSelectedZones();
  vector<Zone> allZones = d.getAllZones();
  vector<Zone> shz = d.getShadedZones();

  //Remove Shaded Zones from selected Zones if there is any
  for (int i= 0; i < shz.size() ; i++)
    {
      for (int j= 0; j < selectedZones.size() ; j++)
	{
      	  if(shz[i].equals(selectedZones[j]))
	    {
	      cout<< "Zone : " << selectedZones[j].getPair() << " is shaded." << endl;
	      selectedZones.erase(selectedZones.begin() + j);
	      
	    }
	}
    }


  d.setAll(d.getLabel(), d.getContours(), selectedZones,shz, allZones);

  return d;
}
