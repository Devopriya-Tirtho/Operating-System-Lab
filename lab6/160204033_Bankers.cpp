 #include<bits/stdc++.h>

using namespace std;
int number_of_process, number_of_resources;
int max_need[100][100];
int allocation[100][100];
int need[100][100];
int available[100];
int total_resource[100];

bool visited[100];
int cnt = 0;
vector<int>safe_seq;
bool run_process(){
  int curr = -1;
  for (int i = 1; i <= number_of_process; i++){
    bool all = true;
    if (visited[i] == true){
      continue;
    }
    for (int j = 1; j <= number_of_resources; j++){
      if (need[i][j] > available[j]){
        all = false;
      }
    }
    if (all){
      curr = i;
      visited[i] = true;
      safe_seq.push_back(i);
      for (int r = 1; r <= number_of_resources; r++){
        available[r] += allocation[curr][r];
      }
      return true;
    }
  }
  return false;
}

int main(){
  cout << "Enter the number of process: ";
  cin >> number_of_process;
  cout << "Enter the number of resourses: ";
  cin >> number_of_resources;

  for (int i = 1; i <= number_of_process; i++){
    for (int j = 1; j <= number_of_resources; j++){
      cin >> max_need[i][j];
    }
    for (int j = 1; j <= number_of_resources; j++){
      cin >> allocation[i][j];
    }
  }
  for (int i = 1; i <= number_of_resources; i++){
    cin >> total_resource[i];
  }
  for (int i = 1; i <= number_of_resources; i++){
    int sum = 0;
    for (int j = 1; j <= number_of_process; j++){
      sum += allocation[j][i];
    }
    available[i] = total_resource[i] - sum;
  }
  cout<<endl<<endl;
  cout<<"Avliable: "<<endl;
    for(int i=1;i<=number_of_resources;i++){
        cout<<available[i] <<" ";
  }
cout<<endl<<endl<<endl;
cout<<"Need Matrix: "<<endl;
  for (int i = 1; i <= number_of_process; i++){
    for (int j = 1; j <= number_of_resources; j++){
      cout <<max_need[i][j]-allocation[i][j]<<" ";
      need[i][j] = max_need[i][j] - allocation[i][j];
    }
    cout<<endl;
  }

  while (cnt < number_of_process){
    if (run_process()){
      cnt++;
    }
    else {
      cout << "The system is not it safe state"<<endl;
      cout<<endl;
      cout<<endl;
      return 0;
    }
  }
  cout << "The system is in safe sate"<<endl;
  for (int i = 0; i < safe_seq.size(); i++){
    cout << "P" << safe_seq[i] << " ";
  }

  return 0;
}

/*


7 3
7 5 6
1 1 1
5 8 5
2 3 3
9 2 8
3 0 5
8 8 6
2 2 0
14 4 5
3 1 0
4 6 3
1 2 1
2 9 2
1 1 1
20 19 16

4
3
3 2 2
1 0 0
6 1 3
5 1 1
3 1 4
2 1 1
4 2 2
0 0 2
9 3 6


*/
