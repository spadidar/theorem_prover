#include <iostream>

using namespace std;

#include "Ted.h"

int main()
{
  cout << "* Euler Diagram Theorem Prover *\n" << endl;
  
  Ted ted;
  DiagramHolder holder;

  string command = "";
  
  while( command != "exit") 
    {
      cout << "Enter Command (help for help): " ;
      cin >> command;

      //Help-------------------------------
      if (command == "help")
	{
	  cout << "Commands are: \n" << endl;
	  
	  cout << " -l   = Load Diagram \n" << endl;
	  cout << " -p   = Prove Diagrams \n" << endl;
	  cout << " -c   = Clear Prover \n" << endl;
	  cout << " -dor = Apply Demorgan Or \n" <<endl;
	  cout << " -dand = Apply Demorgan And \n" <<endl;
	  cout << "\n" ;

	  cout << " exit = Quits the program \n" << endl;
	}
      
      //Load Diagram
	  
      else if(command == "-l")
	{
	  string dName = "";
	  cout << "Diagram File  Name: " ;

	  cin >> dName;

	  if (dName != "")
	    {
	      Diagram d = ted.getDiagram( dName);//load diagram
	      if(d.getLabel() == "EMPT")
		cout << "Error! Loading Diagram Failed" << endl;
	      else
		{
		  Rules rules(d);
		  d = rules.returnCurrentDiagram();
	      
		  holder.addDiagram(d);//save it
		}
	    }
	  else
	    cout << "File name error!" << endl;

	}

      //Prover--------------------------------
      else if( command == "-p")
	{
	  string dl = ""; //diagram label
	  string cl = "";


	  cout << "Available Diagrams: " << endl;
	  holder.displayLabels();

	  cout << "Select First Diagram: " ;
	  cin >> dl;

	  cout << "Select Second Diagram: " ;
	  cin >> cl;

	  Diagram d1(dl);
	  Diagram d2(cl);	  
	 
	  d1 = holder.getDiagram(dl); //get the diagram from its label
	  d2 = holder.getDiagram(cl); //get the diagram from its label

	  Prover prover;

	  bool b = prover.prove(d1, d2);

	  if (b)
	    {
	      cout << "**Proof Exists**" << endl;
	      ted.generateProof(prover.getHolder()); 
	    }
	  else
	    cout << "No Proof Exists!" << endl;

	  prover.clear();
	}
      
      //demorgan or law
      else if( command == "-dor")
	{
  	  string expression = ""; //compoun diagram
	  string e;
	  
	  cout << "Enter Compound Diagram Expression (Enter END at the end of the expression) : " << endl;
	   cin >> e; //read expresion
	  while( e != "" && e != "END")
	    {
	      expression += e + " ";
	      cin >> e; //read expresion
	    }
	  cout << expression << endl;
	  ExpressionTokenizer *tokenizer = new ExpressionTokenizer(expression);
	  
	  vector<string>  tokens = tokenizer->tokenize();

	  InfixToPostfix *infix2post = new InfixToPostfix (tokens);

	  vector<string> postfix =  infix2post->getPostfix();
  
	  CompoundRules r;

	  bool b = r.deMorganOr(postfix);
	  if(b)
	    r.displayResult();
	  else
	    cout<< "Cannot apply Demorgan Law (OR) to this diagram" <<endl;

	}
      
      //demorgan and law
      else if( command == "-dand")
	{
  	  string expression = ""; //compoun diagram

	  string e;
	  
	  cout << "Enter Compound Diagram Expression (Enter END at the end of the expression): " << endl;
	   cin >> e; //read expresion
	  while( e != "" && e != "END")
	    {
	      expression += e + " ";
	      cin >> e; //read expresion
	    }

	  ExpressionTokenizer *tokenizer = new ExpressionTokenizer(expression);
	  
	  vector<string>  tokens = tokenizer->tokenize();

	  InfixToPostfix *infix2post = new InfixToPostfix (tokens);

	  vector<string> postfix =  infix2post->getPostfix();
  
	  CompoundRules r;

	  bool b = r.deMorganAnd(postfix);
	  if(b)
	    r.displayResult();
	  else
	    cout<< "Cannot apply Demorgan Law (AND) to this diagram" <<endl;

	}

    }//end wile

}//end main

Diagram Ted::getDiagram(string fileN)
{
  Diagram d("EMPT");
  LexicalAnalyzer la(fileN);
  bool scaned = la.scan();
  
  if(!scaned)
    return d;

  Parser parser (la.getTokens());
  parser.parse();
  string l =parser.getLabel();
  
  vector<Contour> c = parser.getContours();
  vector<Zone> z = parser.getZones();
  vector<Zone> sz = parser.getShadedZones();



  DiagramCreator dc (l, c,z,sz);
    
  return dc.createDiagram();
    
}

void Ted::generateProof(DiagramHolder h)
{
  ProofWriter pw;
  pw.writeProof(h);
  
}
