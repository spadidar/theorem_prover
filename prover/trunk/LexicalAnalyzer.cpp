#include "LexicalAnalyzer.h"

string fn;

vector<string> tokens;
int ind = 0;
char peek;
string buffer;
string line;

LexicalAnalyzer::LexicalAnalyzer(string fileN)
{
  fn = fileN;
}

bool LexicalAnalyzer::scan()
{
  int counter = 1;

  ifstream diagramFile(fn.c_str());

  if (diagramFile.is_open())
    {
      while (! diagramFile.eof() )
	{
	  getline (diagramFile ,line);
      
	  tokenize();
      
	  ind = 0;
	  line.clear();
      
	  counter++;
	}

      diagramFile.close();
      return true;
    }

  else 
    {
      cout << "Unable to open file" <<endl; 
      return false;
    }

}

void LexicalAnalyzer::tokenize()
{
  while(ind < line.size())
    {
      readch();

      if(peek == ' ')
	{

	}
      else if(peek == '\t')
	{

	}
      else if(peek == '=')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }
	  tokens.push_back("=");
	  
	}
      else if(peek == '{')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }
	  tokens.push_back("{");
	}
      else if(peek == '}')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }
	  tokens.push_back("}");

	}
      else if(peek == ',')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }
	  tokens.push_back(",");
	}
      else if(peek == '(')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }

	  buffer.push_back(peek);

	      tokens.push_back(buffer);
	      buffer.clear();
	}
      else if(peek == ')')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }

	  buffer.push_back(peek);

	}
     
      else if(peek == ';')
	{
	  if(buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }
	  tokens.push_back(";");
	  
	}
      else 
	{
	  buffer.push_back(peek);
	}
    }
  
}

vector<string> LexicalAnalyzer::getTokens()
{
  return tokens;
}

void LexicalAnalyzer::readch()
{
  peek = line[ind];
  ind++;  
}

void LexicalAnalyzer::displayTokens()
{
  for(int i =0; i<tokens.size() ; i++)
    {
      cout << tokens[i] << "---- " << i <<endl;
    }
  
  cout << "END of TOkens" <<endl;

}
