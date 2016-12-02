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

int main(){
  float x,y,z,abs_val;
  int line=0;
  int line_max;

  // Question 4. Requesting number of lines and checking response

  cout << "How many lines?" << endl;
  cin >> line_max;

  if (line_max < 0){
    cout << "Error: Line number < 0"<< endl;
    exit(1);
  }
  
  ifstream two_d_float_in;
  ofstream two_d_float_out;

  two_d_float_in.open("input2D_float.txt");
  two_d_float_out.open("output2D_float.txt");

  while (line < line_max){
    two_d_float_in >> x >> y;
    if (!two_d_float_in.eof()){
      line++;
      abs_val = ABSOLUTE_VALUE(x,y);
      cout << x << " " << y << " " << abs_val << endl;
      two_d_float_out << x << " " << y << " " << abs_val << endl;
    }else{
	cout << "Warning: Line number exceeds length of file" << endl;
      break;
    }
  }
  
  two_d_float_in.close();
  two_d_float_out.close();

  cout << " "  << endl;

  return 0;

}
