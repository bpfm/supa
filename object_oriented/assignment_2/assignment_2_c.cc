#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include "planet_class.cc"

using namespace std;

int main(){
  int i,j,position;
  planet planet_data[8];
  string name;
  double mass,distance;
  vector<planet> all_planets;
  
  ifstream planets_file;

  planets_file.open("input.txt");
  
  for(i=0;i<8;i++){
    planets_file >> name >> mass >> distance;
    planet_data[i].setname(name);
    planet_data[i].setmass(mass);
    planet_data[i].setdistance(distance);
  }
  
  planets_file.close();

  map<string,double> map1;

  for(i=0;i<8;i++){
    name=planet_data[i].getname();
    map1[name]=i;
  }
  
  for(std::map<string,double>::iterator iter=map1.begin(); iter!=map1.end(); ++iter){
    cout << iter->first << endl;
  }

  map<double,double> map2;
  
  for(i=0;i<8;i++){
    mass=planet_data[i].getmass();
    map2[mass]=i;
  }
  
  for(std::map<double,double>::iterator iter=map2.begin(); iter!=map2.end(); ++iter){
    cout << iter->first << endl;
  }

  map<double,double> map3;
  
  for(i=0;i<8;i++){
    distance=planet_data[i].getdistance();
    map3[distance]=i;
  }
  
  for(std::map<double,double>::iterator iter=map3.begin(); iter!=map3.end(); ++iter){
    cout << iter->first << endl;
  }
  
  cout << endl;

}
