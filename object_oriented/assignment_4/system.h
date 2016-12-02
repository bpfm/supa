#include "body.h"
#include <math.h>
#include <iostream>
#include <exception>

class system {

 public:

  std::vector<body> solar_system;
  std::vector<body> old_system;

  std::string name;
  int i,j;
  double ax,ay,mass2,x_diff,y_diff,G;
  
  void evolve(double dt){
    
    old_system = solar_system;
    G=6.67e-11;

    for(i=0;i<10;i++){
      ax=0.0;
      ay=0.0;
      for(j=0;j<10;j++){
	if(i!=j){
	  mass2=old_system[j].getmass();
	  x_diff=old_system[j].getx()-old_system[i].getx();
	  y_diff=old_system[j].gety()-old_system[i].gety();
	  ax=ax+G*mass2*x_diff/pow((sqrt(x_diff*x_diff+y_diff*y_diff)),3);
	  ay=ay+G*mass2*y_diff/pow((sqrt(x_diff*x_diff+y_diff*y_diff)),3);
	  //std::cout << i << " " << j << " " << ax << " " << ay << " " << x_diff << " " << y_diff << " "<< acc << std::endl;
	  //throw std::exception();
	}
      }
      //throw std::exception();
      solar_system[i].evolve(dt,ax,ay);
      
    }
    
    return ;
    
  }   
};
