/*
** Contour.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasanlin>
** 
** Started on  Sun Nov 23 22:54:24 2008 Sasan Padidar
** Last update Sun Nov 23 22:54:24 2008 Sasan Padidar
*/

#ifndef   	CONTOUR_H_
# define   	CONTOUR_H_


#include <string>
#include <iostream>

using namespace std;


class Contour
{
 public:

  Contour(string);
  void setLabel(string);
  string getLabel();
  bool equals(Contour);

 private:

  string label;
};

#endif 	    /* !CONTOUR_H_ */
