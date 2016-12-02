#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "planet_class.h"

using namespace std;

bool alpha_order (const planet& a, const planet& b) {
  return a.name < b.name;
}

bool mass_order (const planet& a, const planet& b) {
  return a.mass < b.mass;
}

bool distance_order (const planet& a, const planet& b) {
  return a.distance < b.distance;
}

int main(){
  int i,j,position;
  planet planet_data;
  string name;
  double mass,distance;
  vector<planet> all_planets;
  double sum_md,sum_m;
  
  ifstream planets_file;

  planets_file.open("input.txt");
  
  for(i=0;i<8;i++){
    planets_file >> name >> mass >> distance;
    planet_data.setname(name); // create object
    planet_data.setmass(mass);
    planet_data.setdistance(distance);
    all_planets.push_back(planet_data); // add object to vector
  }
  
  planets_file.close();

  //sort names alphabetically
  
  sort(all_planets.begin(),all_planets.end(),alpha_order);

  for(i=0;i<8;i++){
    name=all_planets[i].getname();
    cout << name << endl;
  }

  cout << endl;
  
  //sort masses into increaing order
  
  sort(all_planets.begin(),all_planets.end(),mass_order);

  for(i=0;i<8;i++){
    name=all_planets[i].getname();
    mass=all_planets[i].getmass();
    cout << name << "\t\t" << mass << endl;
  }

  cout << endl;
  
  cout << "largest mass planet is " << name << endl;
  name=all_planets[0].getname();
  cout << "smallest mass planet is " << name << endl;
  
  cout << endl;
  
  //sort distances into incresing order
  
  sort(all_planets.begin(),all_planets.end(),distance_order);

  for(i=0;i<8;i++){
    name = all_planets[i].getname();
    distance = all_planets[i].getdistance();
    cout << name << "\t\t" << distance << endl;
  }

  cout << endl;
  
  cout << "furthest planet from the sun is " << name << endl;
  name = all_planets[0].getname();
  cout << "closest planet to the sun is " << name << endl;
  
  cout << endl;

  //calculate mass weighted average distance

  for(i=0;i<8;i++){
    mass=all_planets[i].getmass();
    distance=all_planets[i].getdistance();
    sum_md = sum_md + mass*distance;
    sum_m = sum_m + mass;
  }

  cout << "mass weighted average distance = " << sum_md/sum_m << endl;
  
}
