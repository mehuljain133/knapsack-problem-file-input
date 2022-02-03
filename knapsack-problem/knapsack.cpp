//demo code by mehul jain
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){

ifstream arq(argv[1]);

int n, M, i, x, a, b, *v, *p, *V;

// Checks if the file was sucessfully opened
if(arq == NULL){
  cout << "Error reading the input file" << endl;
  exit(EXIT_FAILURE);
}

arq >> M; // Reads the capacity of the knapsack from the file
arq >> n; // Reads the number of items from the file

v = new int[n]; // Dynamically allocates an array for the values
p = new int[n]; // Dynamically allocates an array for the weights

V = new int[(n+1) * (M+1)]; // Allocate the matrix as an array

for(i = 0; i < n; i++){
  arq >> v[i];
  arq >> p[i];
}

for(i = 1; i < n+1; i++){
  for(x = 1 ; x < p[i];x++){
    V[i * (M+1) + x] = V[(i-1) * (M+1) + x];
  }
  for(x = p[i]; x < M+1;x++){
      a = V[(i-1) * (M+1) + x];
      if ((x - p[i]) >= 0){
        b = v[i] + V[(i-1) * (M+1) + (x - p[i])];
        if(a < b){
          a = b;
        }
      }
      V[i * (M+1) + x] = a;
  }
}

cout << "Result: " << V[n * (M+1) + M] << endl;
delete(v, p, V);
}
