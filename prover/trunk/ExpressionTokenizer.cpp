#include "ExpressionTokenizer.h"

ExpressionTokenizer::ExpressionTokenizer()
{

}

ExpressionTokenizer::ExpressionTokenizer(string ex)
{
  index = 0;
  peek = ' ';
  setExpression( ex);
}

vector<string> ExpressionTokenizer::tokenize()
{
  bool read = true;
  
  while(index < expression.size() )
    {
      if(read)
	readch();
      
      if(peek == '(')
	{
	  addChar(peek);
	}

      else if(peek == ')')
	{
	  addChar(peek);
	}

      else if(peek == 'o' || peek == 'O' )
	{
	  readch();

	  buffer.push_back(peek);

	  if(peek =='R' || peek =='r' )
	    {
	      buffer.push_back(peek);
	      tokens.push_back("OR");
	      buffer.clear();
	    }
	  else
	    read == false;
	  
	}

      else if(peek == 'A' || peek == 'a' )
	{
	  buffer.push_back(peek);

	  readch();

	  if(peek =='N' || peek =='n' )
	    {
	      buffer.push_back(peek);
	      readch();

	      if(peek =='D' || peek =='d' )
		{
		  buffer.push_back(peek);
		  tokens.push_back("AND");
		  buffer.clear();
		}
	      else
		read = false;
	    }
	  else
	    read == false;
	  
	}

      else if(peek == 'N' || peek == 'n' )
	{
	  buffer.push_back(peek);
	  readch();

	  if(peek =='O' || peek =='o' )
	    {
	      buffer.push_back(peek);
	      readch();

	      if(peek =='T' || peek =='t' )
		{
		  buffer.push_back(peek);
		  tokens.push_back("NOT");
		  buffer.clear();
		}
	      else
		read = false;
	    }
	  else
	    read == false;
	  
	}

      else if(peek == ' ')
	{
	  if( buffer.size() > 0)
	    {
	      tokens.push_back(buffer);
	      buffer.clear();
	    }
	}

      else
	{
	  buffer.push_back(peek);
	}
    }

  if(buffer.size() > 0)
    {
      tokens.push_back(buffer);
      buffer.clear();
    }
  return tokens;
}

void ExpressionTokenizer::addChar(char p)
{
  
  if(buffer.size() > 0)
    {
      tokens.push_back(buffer);
      buffer.clear();
    }
  buffer.push_back(p);
  tokens.push_back(buffer);
  buffer.clear();

}
void ExpressionTokenizer::setExpression(string exp)
{
  expression = exp;
}

vector<string> ExpressionTokenizer::getTokens()
{
  return tokens;
}

void ExpressionTokenizer::readch()
{
  if(index < expression.size())
    {
      peek = expression[index];
      index++;  
    }
}

void ExpressionTokenizer::displayTokens()
{
   for(int i =0; i<tokens.size() ; i++)
    {
      cout << tokens[i] << "---- " << i <<endl;
    }
}

