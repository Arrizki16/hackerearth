#include <bits/stdc++.h>
using namespace std;

#define pb push_back

bool visited[10005];
vector <int> v[10005];
int step[10005];
queue <int> q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        for (int i=1 ; i<=n ; i++){
            v[i].clear();
            visited[i] = false;
        }
        for (int i=1 ; i<=m ; i++){
            int x,y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        q.push(1);
        step[1] = 0;
        visited[1] = true;
        while (!q.empty()){
            int standing = q.front();

            q.pop();
            for (auto index : v[standing]){
                if (visited[index] == false){
                    q.push(index);
                    step[index] = step[standing]+1;
                    visited[index] = true;
                }
            }
        }
        cout << step[n] << "\n";
    }
}