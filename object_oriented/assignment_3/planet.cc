#include "planet.h"

planet::planet(){
  name = "none";
  mass = 0.0;
  distance = 0.0;
}

planet::planet(std::string t_name, double t_mass, double t_distance){
  name = t_name;
  mass = t_mass;
  distance = t_distance;
}

std::string planet::getname(){
    return name;
}
void planet::setname(std::string t_name){
    name=t_name;
}
double planet::getmass(){
    return mass;
}
void planet::setmass(double t_mass){
    mass=t_mass;
}
double planet::getdistance(){
    return distance;
}
void planet::setdistance(double t_distance){
    distance=t_distance;
}
