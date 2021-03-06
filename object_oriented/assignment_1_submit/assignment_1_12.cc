#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

float ABSOLUTE_VALUE(float x,float y){
  // find absolute value of 2D vector
  float abs_val;

  abs_val=sqrt(pow(x,2)+pow(y,2));

  return abs_val;
    
}

float ABSOLUTE_VALUE(float x, float y, float z){
  // find absolute value of 3D vector
  float abs_val;

  abs_val=sqrt(pow(x,2)+pow(y,2)+pow(z,2));

  return abs_val;
    
}

int main(){
  float x,y,z,abs_val;
  int line=0;

  // Question 1. Reading 2D floats, finding absolute value, then writing to new file
  
  ifstream two_d_float_in;
  ofstream two_d_float_out;

  two_d_float_in.open("input2D_float.txt");
  two_d_float_out.open("output2D_float.txt");

  while (!two_d_float_in.eof()){
    two_d_float_in >> x >> y;
    if (!two_d_float_in.eof()){
      line++;
      abs_val = ABSOLUTE_VALUE(x,y);
      cout << x << " " << y << " " << abs_val << endl;
      two_d_float_out << x << " " << y << " " << abs_val << endl;
    }
  }
  
  two_d_float_in.close();
  two_d_float_out.close();

  cout << " "  << endl;

  // Question 2. Same as 1 but with 3D data
  
  ifstream three_d_float_in;
  ofstream three_d_float_out;

  three_d_float_in.open("input3D_float.txt");
  three_d_float_out.open("output3D_float.txt");

  while (!three_d_float_in.eof()){
    three_d_float_in >> x >> y >> z;
    if (!three_d_float_in.eof()){
      line++;
      abs_val = ABSOLUTE_VALUE(x,y,z);
      cout << x << " " << y << " " << z << " " << abs_val << endl;
      three_d_float_out << x << " " << y << " " << z << " " << abs_val << endl;
    }
  }

  three_d_float_in.close();
  three_d_float_out.close();

  // Question 3. In seperate file

  // Question 4. In seperate file
  
  return 0;

}
