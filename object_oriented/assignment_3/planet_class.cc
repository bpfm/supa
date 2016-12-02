// class declared without seperate header file, everything included here

class planet {
  
  private:
  
  std::string name;
  double mass,distance;
  
  public:
  
  std::string getname(){
    return name;
  }
  bool setname(std::string planetname){
    name=planetname;
    return true;
  }
  double getmass(){
    return mass;
  }
  bool setmass(double planetmass){
    mass=planetmass;
    return true;
  }
  double getdistance(){
    return distance;
  }
  bool setdistance(double planetdistance){
    distance=planetdistance;
    return distance;
  }
  bool mass_order (const planet& a, const planet& b) {
    return a.mass < b.mass;
  }
  friend bool alpha_order(const planet& a, const planet& b);
  friend bool mass_order(const planet& a, const planet& b);
  friend bool distance_order(const planet& a, const planet& b);
  
};
