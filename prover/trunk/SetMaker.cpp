#include "SetMaker.h"

SetMaker::SetMaker()
{

}

vector<Contour> SetMaker::makeSet(vector<Contour> vec)
{
  vector<Contour> midvec = vec;
  for (int i =0; i< vec.size(); i++)
    {
      for( int j =0; j< midvec.size(); j++)
	{
	  if(i != j && vec[i].getLabel() == midvec[j].getLabel())
	    {
	      midvec.erase(midvec.begin() + j);
	      
	    }
	}
    }
  
  return midvec; 
}

bool SetMaker::exists(vector<Zone> vec, Zone z )
{
  for (int i = 0; i<vec.size(); i++)
    {
      if(z.equals(vec[i]))
	return true;
    }

  return false;
}
