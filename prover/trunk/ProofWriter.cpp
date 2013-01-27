#include "ProofWriter.h"


ProofWriter::ProofWriter()
{

}

bool ProofWriter::writeProof(DiagramHolder dh)
{
  ofstream file ("proof.txt");
  
  vector<Diagram> diags = dh.getAllDiagrams();

  if(file.is_open())
    {
      
      vector<Diagram> premise;
      vector<Diagram> conclusion;
      bool reached = false;

      for(int i = 0; diags.size() > i; i++)
	{
	
	  if(diags[i].getLabel() == "EMPTY")
	    {
	      reached = true;
	    }

	  if(!reached)
	    {
	      premise.push_back(diags[i]);
	    }
	  else
	      conclusion.push_back(diags[i]);

	}

      
	file << "------------------------------------------------------" << endl;

        file << premise[0].printDiagram() << endl;
      
      for(int i = premise.size()-1; i >= 1; i--)
	{
	  file << "------------------------------------------------------" << endl;

	  file << diags[i].printDiagram() << endl;  
	}

      
      for(int i = conclusion.size()-2; i >= 1; i--)
	{
	  file << "------------------------------------------------------" << endl;

	  file << conclusion[i].printDiagram() << endl;  
	}

      
	file << "------------------------------------------------------" << endl;

        file << conclusion[conclusion.size()-1].printDiagram() << endl;
      

      file.close();
    }
  else
    cout << "Unable To Create the Proof file!";

}

