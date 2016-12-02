#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class planet {
  public:
  string name;
  float mass;
  float distance;
};

int main(){
  int i,j,position;
  planet planet_list[8];
  int order[8],order_mass[8],order_dist[8],letter;
  char* word1;
  char* word2;
  
  ifstream planets_file;

  planets_file.open("input.txt");
  
  for(i=0;i<8;i++){
    planets_file >> planet_list[i].name >> planet_list[i].mass >> planet_list[i].distance;
  }

  planets_file.close();
  
  cout << endl;

  // Sort into alphabetical order
  
  for(i=0;i<8;i++){
    position=0;
    for(j=0;j<8;j++){
      if(i!=j){                              // skip comparison to self
	word1=&planet_list[i].name[0];       // convert std::string type to char*
	word2=&planet_list[j].name[0];
	if((int)word1[0] == (int)word2[0]){  // check if names start with same letter
	  letter=1;
        } else{
	  letter=0;
	}
	if((int)word1[letter] > (int)word2[letter]){   // convert letter to corresponding int and compare
	  position++;                                  // add 1 to position if ith name lower down alphabet than jth word
	}
      }
    }  
    order[position]=i; // record planet index for this position
  }

  for(i=0;i<8;i++){
    cout << planet_list[order[i]].name << endl;
  }

  cout << endl;
  
  // Sort by increasing mass
  
  for(i=0;i<8;i++){
    position=0;
    for(j=0;j<8;j++){
      if(i!=j){
	if(planet_list[i].mass > planet_list[j].mass){
	  position++;
	}
      }
    }
    order_mass[position]=i; // record planet index for this position
  }

  for(i=0;i<8;i++){
    cout << planet_list[order[i]].name << "\t" << planet_list[order[i]].mass << endl;
  }

  cout << endl;
  
  // Sort by increasing distance from Sun
  
  for(i=0;i<8;i++){
    position=0;
    for(j=0;j<8;j++){
      if(i!=j){
	if(planet_list[i].distance > planet_list[j].distance){
	  position++;
	}
      }
    }
    order_dist[position]=i; // record planet index for this position
  }

  for(i=0;i<8;i++){
    cout << planet_list[order[i]].name << "\t" << planet_list[order[i]].distance << endl;
  }

  cout << endl;

  // largest and smallest masses (found using ordering from before)

  cout << "largest mass = "  << planet_list[order_mass[7]].name  << endl;
  cout << "smallest mass = "  << planet_list[order_mass[0]].name  << endl;

  cout << endl;
  
  // largest and smallest distances (found using ordering from before)

  cout << "largest distance = "  << planet_list[order_dist[7]].name  << endl;
  cout << "smallest distance = "  << planet_list[order_dist[0]].name  << endl;

  cout << endl;
  
  // calculate weighted average distance from sun

  float sum_md;
  float sum_m;

  sum_md=0.0;
  sum_m=0.0;
  
  for(i=0;i<8;i++){
    sum_md=sum_md+planet_list[i].mass*planet_list[i].distance;
    sum_m=sum_m+planet_list[i].mass;
  }

  cout << "mass weighted average distance from sun =" << "\t" << sum_md/sum_m << endl;
  
}
