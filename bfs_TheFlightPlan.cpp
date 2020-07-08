#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

queue <int> q;
stack <int> s;

int main(){
    int n, m, t, c;
    cin >> n >> m >> t >> c;
    vector<int> vct[n+1];
    pair<int, int> memo[n+1];
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    memset(memo , 0 ,sizeof(memo));

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        vct[u].pb(v);
        vct[v].pb(u);
    }
    for (int i=0 ; i<=n ; i++){
        sort (vct[i].begin(), vct[i].end());
    }
    int x, y;
    cin >> x >> y;
    q.push(x);

    // memo first = step
    // memo second = tujuan

    visited[x] = true;
    memo[x].first = 1;
    memo[x].second = 0;
    
    int tujuan;
    while (!q.empty()){
        int standing = q.front();
        q.pop();
        // visited[standing] = true;

        int index = vct[standing].size();
        for (int i = 0; i < index; i++){
            tujuan = vct[standing][i];
            if (visited[tujuan] == false){
                visited[tujuan] = true;
                q.push(tujuan);
                memo[tujuan].first = memo[standing].first + 1;
                memo[tujuan].second = standing;
            }
        }
        if (memo[y].second != 0){
            break;
        }
    }
    int temp = y;
    if (memo[temp].second == 0){
        cout << '0' << "\n";
    }
    else {
        cout << memo[temp].first << "\n";
        s.push(y);
        while (memo[temp].second > 0){
            s.push(memo[temp].second);
            temp = memo[temp].second;       
        }
        while (!s.empty()){ 
            cout << s.top() << " ";
            s.pop();
        }
    }
}