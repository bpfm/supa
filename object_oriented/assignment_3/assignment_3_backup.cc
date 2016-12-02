#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include "planet_class.cc"

using namespace std;

bool mass_order (const planet& a, const planet& b) {
  return a.mass < b.mass;
}

int main(){
  int i,j,position;
  planet planet_data;
  string name;
  double mass,distance;
  vector<planet> all_planets;
  vector<string> all_names;
  vector<double> all_masses,all_distances;
  
  ifstream planets_file;

  planets_file.open("input.txt");
  
  for(i=0;i<8;i++){
    planets_file >> name >> mass >> distance;
    planet_data.setname(name);
    planet_data.setmass(mass);
    planet_data.setdistance(distance);
    all_planets.push_back(planet_data);
    all_names.push_back(name);
    all_masses.push_back(mass);
    all_distances.push_back(distance);
  }
  
  planets_file.close();

  sort(all_planets.begin(),all_planets.end(),mass_order);

  for(i=0;i<8;i++){
    name=all_planets[i].getname();
    mass=all_planets[i].getmass();
    cout << name << "\t\t" << mass << endl;
  }

  sort(all_planets.begin(),all_planets.end(),mass_order);

  for(i=0;i<8;i++){
    name=all_planets[i].getname();
    mass=all_planets[i].getmass();
    cout << name << "\t\t" << mass << endl;
  }

  /*sort(all_names.begin(),all_names.end());
  sort(all_masses.begin(),all_masses.end());
  sort(all_distances.begin(),all_distances.end());
  
  
  for(i=0;i<8;i++){
    cout << all_names[i] << endl;
  }
  for(i=0;i<8;i++){
    cout << all_masses[i] << endl;
  }
  for(i=0;i<8;i++){
    cout << all_distances[i] << endl;
  }
  
  /*map<string,double> map1;

   for(i=0;i<8;i++){
    name=planet_data[i].getname();
    map1[name]=i;
  }
  
  for(std::map<string,double>::iterator iter=map1.begin(); iter!=map1.end(); ++iter){
    cout << iter->first << endl;
  }
  */
  
  /*map<double,double> map2;
  
  for(i=0;i<8;i++){
    mass=planet_data[i].getmass();
    map2[mass]=i;
  }
  
  for(std::map<double,double>::iterator iter=map2.begin(); iter!=map2.end(); ++iter){
    name=planet_data[int(iter->second)].getname();
    cout << name << "\t" << iter->first << endl;
  }

  map<double,double> map3;
  
  for(i=0;i<8;i++){
    distance=planet_data[i].getdistance();
    map3[distance]=i;
  }
  
  for(std::map<double,double>::iterator iter=map3.begin(); iter!=map3.end(); ++iter){
    name=planet_data[int(iter->second)].getname();
    cout << name << "\t" << iter->first << endl;
  }
  
  cout << endl;
  */

}
