class body {
  
  private:
  
  std::string name;
  double mass,x,y,vx,vy;
  
  public:
  
  std::string getname(){
    return name;
  }
  void setname(std::string planetname){
    name=planetname;
    return ;
  }
  double getmass(){
    return mass;
  }
  void setmass(double planetmass){
    mass=planetmass;
    return ;
  }
  double getx(){
    return x;
  }
  void setx(double planetx){
    x=planetx;
    return ;
  }
  double gety(){
    return y;
  }
  void sety(double planety){
    y=planety;
    return ;
  }
  double getvx(){
    return vx;
  }
  void setvx(double planetvx){
    vx=planetvx;
    return ;
  }
  double getvy(){
    return vy;
  }
  void setvy(double planetvy){
    vy=planetvy;
    return ;
  }

  void evolve(double dt, double ax, double ay){
    x=x+vx*dt+0.5*ax*dt*dt;
    y=y+vy*dt+0.5*ay*dt*dt;
    vx=vx+ax*dt;
    vy=vy+ay*dt;

    return ;
  }
  
};
