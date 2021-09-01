#include<bits/stdc++.h>
using namespace std;
int ar[1000];
int main(){
  int p;
  cout << "Number of pages:\n";
  cin >> p;
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
  int memory[F + 5];
  for (int i = 0; i < F; i++){
    memory[i] = -1;
  }               
  int hit = 0;
  int fault = 0;
  for (int i = 0; i < n; i++){
    bool flag = false;
    for (int j = 0; j < F; j++){
      if (memory[j] == ar[i]){
        flag = true;
        break;     
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
        int mi = -1;
        int mx = -1;
        for (int j = 0; j < F; j++){
          int dis = n;
          for (int k = i + 1; k < n; k++){
            if (memory[j] == ar[k]){
              dis = k;              
              break;
            }
          }
          if (dis - i > mx){
            mx = dis - i;
            mi = j;
          }
        }
        memory[mi] = ar[i];
      }
    } 
  }  
  cout << "Number of page fault using FIFO Page replacement Algorithm: " << fault << "\n";
  cout << "Page Fault Rate: " << (double) fault / (double) n * 100.00 << "%\n";
  return 0;
}