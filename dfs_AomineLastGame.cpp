#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

int main(){
    int n,q;
    cin >> n >> q;
    stack <int> s;
    int ans = 0;
    int memo[n+1];
    for (int i=1 ; i<=n ; i++){
        cin >> memo[i];
    }
    for (int i=1 ; i<=q ; i++){
        int flag;
        cin >> flag;
        if (flag == 1){
            int bit;
            cin >> bit;
            if(memo[bit] == 0){
                memo[bit] = 1;
            }
            else memo[bit] = 0;
        }
        else if (flag==0){
            int left,right;
            cin >> left >> right;
            if (memo[right] == 1){
                cout << "ODD" << "\n";
            }
            else cout << "EVEN" << "\n";
        }       
    }
}