#include <string>
#include <iostream>

class planet {
 public:
  planet();
  planet(std::string name, double mass, double distance);
  
  std::string t_name();
  double t_mass();
  double t_distance();
  
  std::string getname();
  bool setname(std::string t_name);
  
  double getmass();
  bool setmass(double t_mass);
  
  double detdistance();
  bool setdistance(double t_distance);

  friend bool alpha_order(const planet& a, const planet& b);
  friend bool mass_order(const planet& a, const planet& b);
  friend bool distance_order(const planet& a, const planet& b);
 
 private:
  std::string name;
  double mass,distance;
};

