#include "Parser.h"

vector<string> tokensVec;

int i =0;
string label ="";


Parser::Parser(vector<string> tok)
{
  tokensVec = tok;
}

void Parser::parse()
{
  c.clear();
  z.clear();
  sz.clear();
 
  while(i < tokensVec.size())
    {
      nextToken();
      if(tok == "label")
	{
	  labelHandler();
	}
      else if( tok == "contours")
	{
	  contourHandler();
	}
      else if( tok == "zones")
	{
	  zoneHandler();
	}
      else if( tok == "shaded-zones")
	{
	  shadedZHandler();

	}//end shaded if

    }//end main while
}//end func

void Parser::nextToken()
{
  tok = tokensVec[i];
  i++;
}

string Parser::getLabel()
{
  return label;
}
vector<Contour> Parser::getContours()
{
  return c;
}

vector<Zone> Parser::getZones()
{
  return z;
}

vector<Zone> Parser::getShadedZones()
{
  return sz;
}

void Parser::labelHandler()
{
  nextToken(); //read =
  nextToken(); // readthe name
  label = tok;

}
void Parser::contourHandler()
{
  string buffer;

  while(tok != ";")
    {
      nextToken();

      if(tok == "=" || tok == "{")
	{
	  //ignore
	}

      else if(tok == "}")
	{
	  Contour co(buffer);
	  c.push_back(co);
	  buffer.clear();
	}
		  
      else if(tok == ",")
	{
	  Contour co(buffer);
	  c.push_back(co);
	  buffer.clear();
	}
      else
	buffer.append(tok);
		
    }

}
void Parser::zoneHandler()
{
  string buffer;

  while(tok != ";")
    {
      nextToken();

      if(tok == "=" || tok == "{")
	{
	  //ignore
	}

      else if(tok == "}")
	{
		 
	  buffer.clear();
	}
		  
      else if( tok == "(")
	{
	  Zone zo;		

	  while(tok != ",")
	    {
	      nextToken();
	      if( tok != ",")
		buffer.append(tok);
	    }
		  
	  zo.setZoneIn(buffer);
	  buffer.clear();
		  
	  while(tok != ")")
	    {
	      nextToken();
	      if( tok != ")")
		buffer.append(tok);
	    }
		  
	  zo.setZoneOut(buffer);
	  buffer.clear();
		  
	  z.push_back(zo);
	}
		
    }

}
void Parser::shadedZHandler()
{
  string buffer;

  while(tok != ";")
    {
      nextToken();

      if(tok == "=" || tok == "{")
	{
	  //ignore
	}

      else if(tok == "}")
	{
		 
	  buffer.clear();
	}
		  
      else if( tok == "(")
	{
	  Zone zo;		

	  while(tok != ",")
	    {
	      nextToken();
	      if( tok != ",")
		buffer.append(tok);
	    }

	  zo.setZoneIn(buffer);
	  buffer.clear();
		  
	  while(tok != ")")
	    {
	      nextToken();
	      if( tok != ")")
		buffer.append(tok);
	    }

	  zo.setZoneOut(buffer);
	  buffer.clear();
		  
	  sz.push_back(zo);
	}
		
    }//end while

}
