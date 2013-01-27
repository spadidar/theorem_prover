#include "DiagramHolder.h"

void DiagramHolder::addDiagram(Diagram d)
{
  diagrams.push_back(d);
}

vector<Diagram> DiagramHolder::getAllDiagrams()
{
  return diagrams;
}

Diagram DiagramHolder::getDiagram(string l)
{
  Diagram d ("empty");
  
  for (int i =0; i <diagrams.size(); i++)
    {
      if ( diagrams[i].getLabel() == l)
	{
	    d = diagrams[i];
        }
    }
  if( d.getLabel().size() <= 0 )
    cout << "The Diagram does not Exist (Check Label)!" <<endl;
  
  return d;
  
}

Diagram DiagramHolder::getLastDiagram()
{
  Diagram d("EMPTY");

  if(diagrams.size() == 0)
    return d;

  return diagrams.back();
}

void DiagramHolder::updateDiagram(Diagram d)
{
  for (int i =0; i <diagrams.size(); i++)
    {
      if(diagrams[i].getLabel() == d.getLabel())
	{
	  diagrams[i] = d;
	}
    }
}

void DiagramHolder::displayLabels()
{
  for (int i =0; i <diagrams.size(); i++)
    {
      cout << diagrams[i].getLabel() << " | ";
    }
  cout <<endl;
}

/* displays all diagrams  in the vector*/

void DiagramHolder::displayAllDiagrams()
{
  cout << "Displaying All Diagrams..."<<endl;
  for (int i = 0; i < diagrams.size(); i++)
    {
      if(diagrams[i].getLabel() == "EMPTY")
	{
	      cout << "*************************************************************************************************" << endl;
	}
	else
	{		
      	     cout << "Diagram Description-----------------------------------" << endl;
      	     cout << diagrams[i].printDiagram() << endl;
    	}
    }	  
   cout << endl;
}

string DiagramHolder::printDiagram(Diagram d)
{
  string dp = "";
  
  dp = "Label: " + d.getLabel()+ "\n";
  dp = dp +  "Contours: " + d.getLabel()+ "\n";  
}

void DiagramHolder::clear()
{
  diagrams.clear();
}
