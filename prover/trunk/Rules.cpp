#include "Rules.h"

Rules::Rules(Diagram d)
{
  diag = d;
  cLabels = diag.getContours();
  selectedZones = diag.getSelectedZones();
  sz = diag.getShadedZones();
  allZones = generateZones();


  diag.setAll(diag.getLabel(),
	      cLabels,
	      selectedZones,
	      sz,
	      allZones);
}

Rules::~Rules()
{

}
  
vector<Zone> Rules::generateZones()
{
  string zinc = "";
  string zexl = "";
  int fp =0;
  int sp = 0;

  int totalRounds = cLabels.size();
  int round = 1;
  int size = cLabels.size();
  int index = 0;

  //Handle the first bit (empty all
  if( fp == 0)
    {
      zinc = ""; //set the first pair
   
      while (index < cLabels.size())
  	{
  	  zexl = zexl + cLabels[index].getLabel();
  	  index++;
  	}
      addPair(zinc, zexl);
    }

  zinc = ""; //clean up
  zexl = "";

  fp = 0;
  sp = fp + 1;

  while(round <= totalRounds)
    {
      fp = 0; //at the start of each round fp = 0
      sp = fp +1; //second ppointer is set
      int numReq = round - 1; // number required
      string zincFirst = "";
      string zincSec = "";

      
      //special case for the first round
      if ( round == 1 )
	{
	  for (int i = 0; i <=size-1 ; i++)
	    {
	      zinc =  cLabels[i].getLabel();
	      for (int j =  0; j < size; j++)
		{
		  if( i != j )
		    zexl = zexl + cLabels[j].getLabel();
		}
	      addPair(zinc, zexl);
	      zinc.clear();
	      zexl.clear();
	    }
	}
      else
	{
	  while(numReq <= (size-1) - fp)
	    {
	      vector<int> indexes;

	      zincFirst = cLabels[fp].getLabel(); //add the starting elemet of the combination
	      indexes.push_back(fp); //add to the indexes vector
	     
	      //special case for round = 2
	      if (round == 2)
		{
		  while ( 0 <= (size -1) - sp)
		    {
		      zincSec = cLabels[sp].getLabel(); //set second  part of zinc
		      zinc = zincFirst + zincSec;// concatinate all
		      for ( int i = 0; i < size; i++)
			{
			  if(i != fp && i != sp) //getting zexl
			    zexl = zexl + cLabels[i].getLabel();
			}
		      addPair(zinc , zexl);//add to the list
		      sp++; //increase the second point (it acts as mover here)
		   
		      zexl.clear(); //clear zexl
		      zinc.clear();

		    }
		  sp = fp + 1;

		}
	      else //rounds >= 3
		{

		  int zincSecSize = zincSec.size(); //is here because
						    //of c++ STL Bug
		  zincSec.clear();
		  if(zincSec.empty())
		    zincSecSize = 0;

		  while( sp <= size -1 )
		    {
		      
		      zincSec = zincSec + cLabels[sp].getLabel(); //set the
		      //second
		      indexes.push_back(sp); //add to the indexes
					     //vector
		      zincSecSize = zincSec.size();
		      
		      int c = sp+1 ;

		      while( (zincSecSize -1) < round-3 && c < size -1)
			{
			  zincSec = zincSec + cLabels[c].getLabel(); //set the
			  indexes.push_back(c); //add to the indexes vector
			  zincSecSize = zincSec.size();
			  c++;				   //second
			  
			}

		      //the part to get the last element of the combination
		      if( zincSec.size() == round-2 )
			{
			  int mover = indexes[indexes.size()-1] +1;

			  while( mover <= size - 1 )
			    {
			      zinc = zincFirst + zincSec + cLabels[mover].getLabel(); //create zinc
 			      
			      indexes.push_back(mover); //add to
							//indexes vect
			    
			      //Finding ZEXL
			      for (int i = 0; i< size; i++)
				{
				  int exists = 0; //Bug bool does not work
				  
				  for (int j =0; j < indexes.size(); j++)
				    {
				      			      
				      if( indexes[j] == i)
					exists = 1;
				   
				    }//end for
								  
				  if ( exists == 0)
				    zexl = zexl + cLabels[i].getLabel();

				}//end for

			      addPair(zinc, zexl);
			      
			      zinc = "";//clear up
			      zexl.clear();
			      indexes.pop_back();
			      mover++;
			    }//end while
		    
			}//end if
		      zincSec = "";
		      zincSec.clear();	
		      indexes.clear();
		      indexes.push_back(fp);
		      sp++;

		    }//end while

		  zincSec = ""; //clear up
		  zincSec.clear();
	  
		}//end else

	      fp++;
	      sp = fp +1;
	      zincFirst = ""; //clear
	    }//end while

	}//end else

      //clear up
      fp = 0;
      sp = fp + 1;
      zinc = "";
      zincFirst ="";
      zincSec ="";
      
      round++;
    }

  return allZones; 
}

// Creates the pair to be added
void Rules::addPair(string inc, string ex)
{
  Zone zo(inc, ex);
  allZones.push_back(zo);
}

// Creates the pair 
string Rules::createPair(string inc, string ex)
{
  string pair = "";
  pair = "(" + inc + " , " + ex + ")";  
  
  return pair;
}

//add contour
Diagram Rules::addContour(Contour newLabel)
{
  SyntaxChecker sc;
 
 if(sc.isSet(cLabels, newLabel))
    {
      Contour con(newLabel); 
  
      cLabels.push_back(con);//add to diagram contours set
      allZones.clear(); //clear zone vector
      allZones =  generateZones();// re-generate all zones
  
      selectedZones = updateSelectedZones(newLabel); //regenerate zones
      sz = updateShadedZones(newLabel);//regenerate shadeds
    }
 else
   cout << "AddContour Rule: Contour's set has duplicate contour names!" << endl;

  diag.setAll(diag.getLabel() + "-AC",
	      cLabels,
	      selectedZones,
	      sz,
	      allZones);

  return diag;
}

Diagram Rules::removeContour(Contour label)
{
  for (int i = 0; i < cLabels.size(); i++)
    {
      if( cLabels[i].getLabel() == label.getLabel())
	{
	  cLabels.erase(cLabels.begin()+i); // remove from clabels
	  allZones.clear(); //clear zones
	  allZones = generateZones();

	  selectedZones = updateSelectedZones(label); //regenerate zones
	  sz = updateShadedZones(label);//regenerate shadeds
	}
    }

  diag.setAll(diag.getLabel() + "-RC",
	      cLabels,
	      selectedZones,
	      sz,
	      allZones);

  return diag;

}

//Add shaded zone, Remove it from the zones

Diagram Rules::addShadedZone(Zone zz)
{
  sz.push_back(zz); //add to shaded zone
  selectedZones.push_back(zz);

  diag.setAll(diag.getLabel() + "-ASZ",
	      cLabels,
	      selectedZones,
	      sz,
	      allZones);

  return diag;
}

Diagram Rules::removeShadedZone(Zone zz)
{
  for (int i =0; i < sz.size() ; i++)
    {
      if(sz[i].equals(zz) )
	{
	  sz.erase(sz.begin() + i);
	}
    }

  diag.setAll(diag.getLabel() + "-RSZ",
	      cLabels,
	      selectedZones,
	      sz,
	      allZones);

  return diag;
}

vector<Zone> Rules::updateSelectedZones(Contour label)
{
  vector<Zone> newSelectedZones;

  for(int i =0; i < selectedZones.size(); i++)
    {
      for(int x =0; x< allZones.size(); x++)
	{
	  if(selectedZones[i].inEquals(allZones[x].getZoneIn()) )
	    {
	      newSelectedZones.push_back(allZones[x]);
	    }
	  else if(selectedZones[i].inEquals(allZones[x].getZoneIn(), label.getLabel()) )
	    {
	      newSelectedZones.push_back(allZones[x]);
	    }
	}
    }

  return newSelectedZones;
}

vector<Zone> Rules::updateShadedZones(Contour label)
{
  vector<Zone> newsz;

  for(int i =0; i < sz.size(); i++)
    {
      for(int x =0; x< allZones.size(); x++)
	{
	  if(sz[i].inEquals(allZones[x].getZoneIn())  )
	    {
	      newsz.push_back(allZones[x]);
	    }
	  else if(sz[i].inEquals(allZones[x].getZoneIn(), label.getLabel()) )
	    {
	      newsz.push_back(allZones[x]);
	    }
	}
    }

  return newsz;
}

Diagram Rules::returnCurrentDiagram()
{
  return diag;
}
