#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

template<class T> float ABSOLUTE_VALUE(T x,T y){
  // find absolute value of 2D vector
  float abs_val;

  abs_val=sqrt(pow(x,2)+pow(y,2));

  return abs_val;
    
}

template<class T> float ABSOLUTE_VALUE(T x, T y, T z){
  // find absolute value of 3D vector 
  float abs_val;

  abs_val=sqrt(pow(x,2)+pow(y,2)+pow(z,2));

  return abs_val;
    
}


int main(){
  int x,y,z;
  float abs_val;
  int line=0;

  // Question 3. Reading integers and finding absolute values
  //             Converted functions to template functions so they could take int or float
  
  ifstream two_d_int_in;
  ofstream two_d_int_out;

  two_d_int_in.open("input2D_int.txt");
  two_d_int_out.open("output2D_int.txt");

  while (!two_d_int_in.eof()){
    two_d_int_in >> x >> y;
    if (!two_d_int_in.eof()){
      line++;
      abs_val = ABSOLUTE_VALUE<int>(x,y); 
      cout << x << " " << y << " " << abs_val << endl;
      two_d_int_out << x << " " << y << " " << abs_val << endl;
    }
  }
  
  two_d_int_in.close();
  two_d_int_out.close();

  cout << " "  << endl;

  // 3D data
  
  ifstream three_d_int_in;
  ofstream three_d_int_out;

  three_d_int_in.open("input3D_int.txt");
  three_d_int_out.open("output3D_int.txt");

  while (!three_d_int_in.eof()){
    three_d_int_in >> x >> y >> z;
    if (!three_d_int_in.eof()){
      line++;
      abs_val = ABSOLUTE_VALUE<int>(x,y,z);
      cout << x << " " << y << " " << z << " " << abs_val << endl;
      three_d_int_out << x << " " << y << " " << z << " " << abs_val << endl;
    }
  }

  three_d_int_in.close();
  three_d_int_out.close();
  
  return 0;

}
