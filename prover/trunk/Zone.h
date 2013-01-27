/*
** Zone.h
** 
** Made by Sasan Padidar
** Login   <sasan@sasan-Linux>
** 
** Started on  Sun Nov  9 22:34:10 2008 Sasan Padidar
** Last update Sun Nov  9 22:34:10 2008 Sasan Padidar
*/

#ifndef   	ZONE_H_
# define   	ZONE_H_

#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

 
class Zone
{
 public:
  
  string in;
  string out;
  
  Zone();
  Zone(string, string);
  
  void setZoneIn(string);
  void setZoneOut(string);
  string getZoneIn();
  string getZoneOut();

  bool inEquals(string);
  bool outEquals(string);
  bool inEquals(string, string);
  bool outEquals(string, string);
  bool isShaded(Zone);//Zone is the shaded zone
  bool equals(Zone);
  string getPair();
};

#endif 	    /* !ZONE_H_ */
