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
  color[u] = GRAY;//johon node ta dhukche jtokhon gray korchi
  for (int v: ar[u]){ //node tay dhuklam sob adjacent e check korche
    if (color[v] == GRAY){
      //cycle found
      cycle_found = true;
      int temp = u;// u ta chalalam jate u ta na haray tai store kore rakhlam
      cycle_path.push_back(v); //shurutejeta pacchilam track rakhar jonno purtata print korar jonno
      while (temp != v){ //track rakhchi je jototuku gelam jate print hoy vector e push koro ager ta ke porrer tar patrent hisen\bse push koro
        cycle_path.push_back(temp);
        temp = par[temp];
      }
      //cycle_path.push_back(v);
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
    cout<<"enter the no of node and edges:";

  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    ar[x].push_back(y);
  }
  for (int i = 1; i <= n; i++){
    if (color[i] == WHITE){
      DFS(i);
    }
  }
  if (cycle_found){
    cout << "Deadlock detected\n";
    for (int i=cycle_path.size()-1; i >= 0; i--){
      cout << cycle_path[i] << " ";
    }
    cout << "\n";
  }
  else {
    cout << "No deadlock detected\n";
  }
  return 0;
}


