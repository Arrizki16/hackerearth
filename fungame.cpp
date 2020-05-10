#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <queue>

void getSolve(stack <int> s, queue <int> q){
    while (!q.empty() && !s.empty()){
        if (s.top() > q.front()){
            cout << "2" << " ";
            q.pop();
        }
        else if (s.top() < q.front()){
            cout << "1" << " ";
            s.pop();
        }
        else{
            cout << "0" << " ";
            q.pop();
            s.pop();
        }
    }    
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int value;
    cin >> n;
    stack <int> s;
    queue <int> q;
    for (int i=0 ; i<n ; i++){
        cin >> value;
        s.push(value);
        q.push(value);
    }
    getSolve(s,q);
}