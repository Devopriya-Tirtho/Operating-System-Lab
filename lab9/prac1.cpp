#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int main(){

  int n;
  cout << "Number of pages:\n";
  cin >> n;
  cout << "Reference String:\n";
  for (int i = 0; i < n; i++){
    cin >> ar[i];
  }
  cout << "Number of Memory Page Frame:\n";
  int F;
  cin >> F;
  int memory[F ];
  for (int i = 0; i < F; i++){
    memory[i] = -1;
  }
  int first = 0;
  int hit = 0;
  int fault = 0;
  for (int i = 0; i < n; i++){
    bool flag = false;
    for (int j = 0; j < F; j++){
      if (memory[j] == ar[i]){
        flag = true;
      }
    }
    if (flag){
      hit++;
    } else {
      fault++;
      bool done = false;
      for (int j = 0; j < F; j++){
        if (memory[j] == -1){
          memory[j] = ar[i];
          done = true;
          break;
        }
      }
      if (!done){
        memory[first] = ar[i];
        first++;
        first %= F;
      }
    }
  }
  cout << "Number of page fault using FIFO Page replacement Algorithm: " << fault << "\n";
  cout << "Page Fault Rate: " << (double) fault / (double) n * 100.00 << "%\n";

  return 0;
}

