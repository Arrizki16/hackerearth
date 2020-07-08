#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int main(){
    int n, e;
    cin >> n >> e;
    vector<int> vct[n+5];
    queue<int> q;
    bool visited[n + 5];
    pair<int, int> memo[n + 5];


    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        vct[u].pb(v);
        vct[v].pb(u);
    }
    for (int i = 1; i <= n; i++){
        sort(vct[i].begin(), vct[i].end());
    }

    int r;
    cin >> r;
    for (int i = 1; i <= r; i++){
        memset(visited, false, sizeof(visited));
        memset(memo, 0 , sizeof (memo));
        int asal, jarak;
        cin >> asal >> jarak;

        q.push(asal);
        visited[asal] = true;

        // first = step
        // second = parent

        memo[asal].first = 0;
        memo[asal].second = 0;
        int flag = 0;
        while (!q.empty()){
            int standing = q.front();
            q.pop();

            int index = vct[standing].size();
            for (int i = 0; i < index; i++){
                int tujuan = vct[standing][i];
                if (visited[tujuan] == false){
                    visited[tujuan] = true;
                    q.push(tujuan);
                    memo[tujuan].first = memo[standing].first + 1;
                    memo[tujuan].second = standing;
                    if (memo[tujuan].first == jarak){
                        flag++;
                    }
                }
            }
        }
        cout << flag << "\n";
    }
}