/*
** SetMaker.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasanlin>
** 
** Started on  Tue Dec 30 09:05:35 2008 Sasan Padidar
** Last update Tue Dec 30 09:05:35 2008 Sasan Padidar
*/

#ifndef   	SETMAKER_H_
# define   	SETMAKER_H_

#include <vector>
#include <string>
#include <iostream>
#include <set>

using namespace std;

#include "Diagram.h"
#include "Zone.h"
#include "Contour.h"

class SetMaker
{
 public :
  SetMaker();
  vector<Contour> makeSet(vector<Contour>);
  bool exists(vector<Zone>, Zone );

};

#endif 	    /* !SETMAKER_H_ */
