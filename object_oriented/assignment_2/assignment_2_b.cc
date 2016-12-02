#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

class planet {
  public:
  string name;
  float mass;
  float distance;
};

int main(){
  int i,j,position;
  planet planet_list;
  int order[8],letter;
  char* upper1;
  char* upper2;
  vector<planet> all_planets;
  
  ifstream planets_file;

  planets_file.open("input.txt");
  
  for(i=0;i<8;i++){
    planets_file >> planet_list.name >> planet_list.mass >> planet_list.distance;
    all_planets.push_back(planet_list);
  }

  map<string,double> map;
    
  sort(all_planets.begin(),all_planets.end());
  
  planets_file.close();
  
  cout << endl;

}
