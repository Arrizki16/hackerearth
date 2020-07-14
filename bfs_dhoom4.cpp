#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define mod 100000

queue <int> q;
int visited[100005];

int main(){
    int key, target;
    cin >> key >> target;
    int n;
    cin >> n;
    int arr[n+1];
    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    memset (visited , -1 , sizeof(visited));
    
    q.push(key);
    visited[key] = 0;
    long long int cost;
    long long int temp;

    while (!q.empty()){
        cost = q.front();
        q.pop();

        if (cost == target){
            break;
        }
        for (int i=0 ; i<n ; i++){
            temp = arr[i];
            temp = temp*cost;
            temp = temp % 100000;
            if (visited[temp] == -1){
                visited[temp] = visited[cost]+1;
                q.push(temp);
            }
        }
    }
    cout << visited[target] << "\n";
}