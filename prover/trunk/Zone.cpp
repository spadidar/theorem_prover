#include "Zone.h"

Zone::Zone()
{

}
Zone::Zone(string i, string o)
{
  setZoneIn(i);
  setZoneOut(o);
}

void Zone::setZoneIn(string i)
{
  in = i;
}

void Zone::setZoneOut(string o)
{
  out = o;
}

string Zone::getZoneIn()
{
  return in;
}

string Zone::getZoneOut()
{
  return out;
}

bool Zone::equals(Zone zone)
{
  int result =0;
  string i = zone.getZoneIn();
  string o = zone.getZoneOut();

  bool inE = inEquals(i);
  bool oE =  outEquals(o);

  if(inE && oE )
    return true;

  return false;
}
 
//Return false if not equal return true if equal in any order
bool Zone::inEquals(string str)
{
  vector<int> check;

  if(str.size() != in.size())
    return false;

  for (int x =0; x < in.size() ; x++)
    {
      for(int j =0; j <str.size(); j++)
	{
	  if(in[x] == str[j])
	    {
	      check.push_back(1);
	    }
	}
    }
  
  if(check.size() != in.size())
    return false;
   
  return true;
}
//Return false if not equal return true if equal in any order

bool Zone::outEquals(string str)
{
  vector<int> check;

  if(str.size() != out.size())
    return false;

  for (int x =0; x < out.size() ; x++)
    {
      for(int j =0; j <str.size(); j++)
	{
	  if(out[x] == str[j])
	    {
	      check.push_back(1);
	    }
	}
    }
  
  if(check.size() != out.size())
    return false;
   
  return true;
}
//Return false if not equal return true if equal in any order

bool Zone::inEquals(string str, string ex)
{
  string buffer;
  vector<int> inds;
  vector<int> check;

  for (int x = 0; x < ex.size() ; x++)
    {
      for (int j = 0; j < str.size() ; j++)
	{
	  if(ex[x] == str[j])
	    inds.push_back(j);
	}
    }

  for (int i =0; i< str.size() ; i++)
    {
      bool add = true;

      for(int x =0; x< inds.size() ; x++)
	{
	  if(inds[x] == i)
	    {
	      add = false;
	    }
	}

      if(add == true)
	buffer = buffer + str[i];
    }

  return inEquals(buffer);
}

bool Zone::isShaded(Zone sz)
{
  vector<int> inds; // holds indeces

  //loop through all the characters of the sz in 
  //if its all in the zone's in then the zone is shaded
  for(int i = 0; i< sz.getZoneIn().size(); i++)
    {
      for(int j = 0; j< getZoneIn().size(); j++)
	{
	  if(sz.getZoneIn()[i] == getZoneIn()[j])	
	    inds.push_back(i);
	}
    }
  //the equality of the size of inds and sz means sz is in the zone
  if(inds.size() == sz.getZoneIn().size())
    return true;

  return false;

}

bool Zone::outEquals(string str, string ex)
{
  string buffer;
  vector<int> inds;
 
  for (int x = 0; x < ex.size() ; x++)
    {
      for (int j = 0; j < str.size() ; j++)
	{
	  if(ex[x] == str[j])
	    inds.push_back(j);
	}
    }

  for (int i =0; i< str.size() ; i++)
    {
      bool add = true;

      for(int x =0; x< inds.size() ; x++)
	{
	  if(inds[x] == i)
	    {
	      add = false;
	    }
	}

      if(add == true)
	buffer = buffer + str[i];
    }
  
  
  
  return outEquals(buffer);
}

string Zone::getPair()
{
  string pair ;
  pair = "(" + in + " , " + out + ")";  
  return pair;
}
