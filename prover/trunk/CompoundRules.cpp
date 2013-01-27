#include "CompoundRules.h"

CompoundRules::CompoundRules()
{


}


CompoundRules::CompoundRules(CompoundTree tree) 
{

}

CompoundRules::~CompoundRules()
{


}

/*
 * law Not(d1 or d2) after applying should be
 * NOT d1 OR NOT d2
 */
bool CompoundRules::deMorganOr(vector<string> postfix)
{
  
  vector<string> pattern;
  bool match = false;
  int index = 0;
  vector<string> afterRule;

  pattern.push_back("NOT");
  pattern.push_back("OR");

  for (int i = postfix.size() - 1; i >= 0 ; i--)
    {
      //if the first match
      if(postfix[i] == pattern[0] && i > 0 )
	{
	  
	  if(postfix[i-1] == pattern[1])
	    {
	      //mathced 
	      match = true;
	      index = i-1; //set the index to location of AND
	    }
	} 
    }


  if(match)//pattern matched
    {
      for(int i = 0; i < postfix.size(); i++)
	{
	  if(i == index)
	    {
	      i += 2; //i has to go forward by 2
	      //add the operators for after the rule is applied
	      afterRule.push_back("NOT");
	      afterRule.push_back("NOT");
	      afterRule.push_back("AND");
	    }
	  else if (i < postfix.size())
	    {
	      afterRule.push_back(postfix[i]);
	    }
	}
       result = afterRule; //set the result to the new vec
    }

  else //not matched
    return false;


  return true;
}


/*
 * law Not(d1 AND d2) after applying should be
 * NOT d1 AND NOT d2
 */
bool CompoundRules::deMorganAnd(vector<string> postfix)
{
  
  vector<string> pattern;
  bool match = false;
  int index = 0;
  vector<string> afterRule;

  pattern.push_back("NOT");
  pattern.push_back("AND");

  for (int i = postfix.size() - 1; i >= 0 ; i--)
    {
      //if the first match
      if(postfix[i] == pattern[0] && i > 0 )
	{
	  
	  if(postfix[i-1] == pattern[1])
	    {
	      //mathced 
	      match = true;
	      index = i-1; //set the index to location of AND
	    }
	} 
    }


  if(match)//pattern matched
    {
      for(int i = 0; i < postfix.size(); i++)
	{
	  if(i == index)
	    {
	      i += 2; //i has to go forward by 2
	      //add the operators for after the rule is applied
	      afterRule.push_back("NOT");
	      afterRule.push_back("NOT");
	      afterRule.push_back("OR");
	    }
	  else if (i < postfix.size())
	    {
	      afterRule.push_back(postfix[i]);
	    }
	}
       result = afterRule; //set the result to the new vec
    }

  else //not matched
    return false;


  return true;
}

vector<string> CompoundRules::getResult()
{
  return result;
}

void CompoundRules::displayResult()
{
  cout<<" Displaying rule application result: " << endl;
  for (int i =0; i < result.size(); i++)
    {
      cout<<  result[i] << "   " ;
    }
  cout << "\n" <<endl;
}
