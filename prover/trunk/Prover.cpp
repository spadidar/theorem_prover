#include "Prover.h"


void Prover::getDiagramHolder(vector<Diagram> dh)
{

}

bool Prover::prove(Diagram d1, Diagram d2)
{
  Diagram premise("p");
  Diagram conclusion("c");
  Diagram marker("EMPTY"); //marker for printing	
  Diagram localConc("c");
  Diagram localPre("p");

  premise =  d1;
  localPre = d1;

  conclusion = d2;
  localConc = d2; //holding conc for adding later
	
  holder.addDiagram(premise);
  
  //**************************************************

  Diagram afterPSZ = addMissingZones(premise);
  premise = afterPSZ; //update premise to new premise 
  
  Diagram afterPMC = addMissingContours(premise, conclusion);

  holder.addDiagram(marker);	

  Diagram afterCMZ = addMissingZones(conclusion);
  conclusion = afterCMZ; //update conclusion to new conclusion

  Diagram afterCMC = addMissingContours(conclusion, premise );

  //***************************************************

  holder.addDiagram(localConc);
  

  holder.displayAllDiagrams();

  vector<Zone> finalPSZ = afterPMC.getShadedZones(); // get shaded z of
  // last premise and
  // last conclusion
  vector<Zone> finalCSZ = afterCMC.getShadedZones();


//   for (int i =0; i< finalCSZ.size() ; i++)
//     {
//       cout << "zone in Conclusion :" << finalCSZ[i].getPair()<< endl;
//     }
//  for(int j =0; j< finalPSZ.size() ; j++)
//    {
//      cout << "zone in premise :" << finalPSZ[j].getPair()<< endl;
//    }
  vector<int> inds; // index holder

  //if final shaded zs of conclusion is a subset of the zones there is
  //a proof
  for (int i =0; i< finalCSZ.size() ; i++)
    {
      for(int j =0; j< finalPSZ.size() ; j++)
	{
	  if( finalCSZ[i].equals(finalPSZ[j]) )
	    {
	      inds.push_back(i);
	    }
	}
    }
  
  if(inds.size() == finalCSZ.size())
    return true;
  
  return false;
}
/*
 *compare all zones with selected zones
 *get the missings
 *add them as shaded zone
 *reset selected zones to all zones
 */
Diagram Prover::addMissingZones(Diagram d)
{
  Rules rules(d);

  vector<Zone> selectedZones = d.getSelectedZones();
  vector<Zone> allZones = d.getAllZones();
  vector<Zone> shz = d.getShadedZones();
  vector<Zone> missings;
  vector<Zone> newSelectedZ;
  vector<Zone> newSZ;

 
  for (int i =0; i< allZones.size() ; i++)
    {
      bool found = false;

      for (int j= 0; j < selectedZones.size() ; j++)
	{
	  if(allZones[i].equals(selectedZones[j]))
	    {
	      found = true;
	    }  
	}

      //copy to missings vec
      if( found == false)
	missings.push_back(allZones[i]);

    }

  //add missing shaded zones using the rule

  for(int i = 0; i< missings.size(); i ++)
    holder.addDiagram(rules.addShadedZone(missings[i]));     

  //returning the final diagram that has all the correct zones/sz
  if(missings.size() > 0)
    {

      Diagram final = holder.getLastDiagram();

      return final;
 
    }
 
//   cout<<"Nothing changed REturned:" <<d.printDiagram()<<endl;
  return d;

}


Diagram Prover::addMissingContours(Diagram d1, Diagram d2)
{
  vector<Contour> preC = d1.getContours();
  vector<Contour> conC = d2.getContours();
  vector<Contour> missing;
  SetMaker setMaker;

  //find the same contours and remove from conculsion
  for(int i =0; i < preC.size() ; i++)
    {
      for (int j =0; j < conC.size() ; j++)
	{
	  if (conC[j].getLabel() == preC[i].getLabel())
	    conC.erase(conC.begin() + j);
	}
    }

  //the remaining contours are not in preC add them all
  for(int i =0 ; i < conC.size(); i++)
    missing.push_back(conC[i]);

  missing = setMaker.makeSet(missing);
  
  //add Missing contours
  
  if(missing.size() > 0)
    {
      Rules rules(d1);
      for(int i = 0; i < missing.size(); i++)
	{
	  holder.addDiagram(rules.addContour(missing[i]));
	}
      return holder.getLastDiagram();
    }

  return d1; 
}

DiagramHolder Prover::getHolder()
{
  return holder;
}

void Prover::clear()
{
  holder.clear();
}
