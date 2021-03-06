#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
int n, m;
vector<int>ar[1000];
vector<int>cycle_path;
int color[1000];
int par[1000];
bool cycle_found = false;


void DFS(int u){
  color[u] = GRAY;
  for (int v: ar[u]){
    if (color[v] == GRAY){
      //cycle found
      cycle_found = true;
      int temp = u;
      cycle_path.push_back(v);

      while (temp != v){
        cycle_path.push_back(temp);
        temp = par[temp];
      }
      return ;
    }
    if (color[v] == WHITE){
      par[v] = u;
      DFS(v);
    }
  }
  color[u] = BLACK;
}



int main(){
  cin >> n;
  m = n;
  for (int i = 0; i < m; i++){
    char x, y;
    cin >> x >> y;
    ar[(char)x].push_back((char)y);
  }
  for (int i = 0; i <= 200; i++){
    if (color[i] == WHITE){
      DFS(i);
    }
  }
  if (cycle_found){
    cout << "Deadlock detected\n";
    for (int i = 0; i < cycle_path.size(); i++){
      cout << (char)cycle_path[i] << " ";
    }
    cout << "\n";
  }
  else {
    cout << "No deadlock detected\n";
  }
  return 0;
}

/*
4
A B
B C
C D
D A
*/

