#include<bits/stdc++.h>
using namespace std;

int req[10000];
bool vis[10000];
int n, head;
int min_index(){
  int mn = INT_MAX;
  int mi = -1;
  for (int i = 0; i < n; i++){
    if (vis[i] == true){
      continue;
    }
    if (abs(head - req[i]) < mn){
      mn = abs(head - req[i]);
      mi = i;
    }
  }
  vis[mi] = true;
  return mi;    
}

int main(){
  cout << "Enter the number of req: ";
  cin >> n;
  cout << "Enter the reqs: ";
  for (int i = 0; i < n; i++){
    cin >> req[i];
  }

  cout << "Enter the head position: ";
  cin >> head;
  cout << "seq: " << head << " ";
  int total = 0;  
  for (int i = 0; i < n; i++){
    int temp = min_index();
    total += abs(head - req[temp]);
    head = req[temp];
    cout << head << " ";    
  }
  cout << "\n";
  cout << "totaol mov: " << total << "\n";
  return 0;
}