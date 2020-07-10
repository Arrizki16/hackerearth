#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

vector <int> v[1005];
stack <int> s;
bool visited[1005];
pair <int,int> memo[1005];

int main(){
    int n;
    cin >> n;
    for (int i=1 ; i<n ; i++){
        int a,b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    int r;
    cin >> r;
    int path =  9999;
    int id = 9999;

    for (int j=1 ; j<=r ; j++){
        memset(visited,false,sizeof(visited));
        memset(memo, 0, sizeof(memo));
        int y;
        cin >> y;

        s.push(1);
        memo[1].first = 0;
        memo[1].second = 0;

        while (!s.empty()){
            int standing = s.top();
            s.pop();
            visited[standing] = true;
            int index = v[standing].size();

            for(int i=0 ; i<index ; i++){
                int tujuan = v[standing][i];
                if (visited[tujuan] == false){
                    s.push(tujuan);
                    memo[tujuan].first = memo[standing].first + 1;
                    memo[tujuan].second = standing;
                }
            }
            if (memo[y].second  != 0){
                if (path > memo[y].second){
                    path = memo[y].second;
                    if (id > y){
                        id = y;
                    }

                }
                break;
            }
        }      
    }
    cout << id << "\n";
}