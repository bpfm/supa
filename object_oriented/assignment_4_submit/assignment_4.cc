#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "system.h"

using namespace std;

int main(){
  int i,step;
  body planet_data;
  system sol;
  string name;
  double mass,x,y,vx,vy,dt,t,t_curr;

  ifstream planets_file;

  planets_file.open("input.txt");

  // set up sun parameters
  
  name = "Sun";
  mass = 1.989e30;
  x=0.0;
  y=0.0;
  vx=0.0;
  vy=0.0;
  planet_data.setname(name); // create sun object
  planet_data.setmass(mass);
  planet_data.setx(x);
  planet_data.sety(y);
  planet_data.setvx(vx);
  planet_data.setvy(vy);
  sol.solar_system.push_back(planet_data); // add sun to vector
  
  for(i=0;i<9;i++){
    planets_file >> name >> mass >> x >> y >> vx >> vy;
    planet_data.setname(name); // create object
    planet_data.setmass(mass);
    planet_data.setx(x);
    planet_data.sety(y);
    planet_data.setvx(vx);
    planet_data.setvy(vy);
    sol.solar_system.push_back(planet_data); // add object to vector
  }
  
  planets_file.close();

  ofstream sun;       // open seperate output files for all objects
  ofstream mercury;
  ofstream venus;
  ofstream earth;
  ofstream moon;
  ofstream mars;
  ofstream jupiter;
  ofstream saturn;
  ofstream uranus;
  ofstream neptune;

  sun.open("sun.txt");
  mercury.open("mercury.txt");
  venus.open("venus.txt");
  earth.open("earth.txt");
  moon.open("moon.txt");
  mars.open("mars.txt");
  jupiter.open("jupiter.txt");
  saturn.open("saturn.txt");
  uranus.open("uranus.txt");
  neptune.open("neptune.txt");

  // request desired parameters from user

  cout << "Timestep (in seconds)?" << endl;
  cin >> dt;

  cout << "Total time (in seconds)?" << endl;
  cin >> t;

  step = 0;
  t_curr=0.0;
    
  while(t_curr<t){
    step=step+1;
    sol.evolve(dt);    // evolve solar system
    t_curr=t_curr+dt;  // update current time
    for(i=0;i<10;i++){ // output positions to relevant files
      if(sol.solar_system[i].getname()=="Sun"){
	sun << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Mercury"){
	mercury << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Venus"){
	venus << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Earth"){
	earth << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Mars"){
	mars << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Moon"){
	moon << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Jupiter"){
	jupiter << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Saturn"){
	saturn << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Uranus"){
	uranus << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }else if(sol.solar_system[i].getname()=="Neptune"){
	neptune << step << "\t" << sol.solar_system[i].getx() << "\t" << sol.solar_system[i].gety() << endl;
      }
    }
  }

  sun.close();     // close all files
  mercury.close();
  venus.close();
  earth.close();
  moon.close();
  mars.close();
  jupiter.close();
  saturn.close();
  uranus.close();
  neptune.close();
  
}
