#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int flag;
    stack <char> stk;
    string s;
    cin >> n;
    for (int j=0 ; j< n ; j++){
      flag = 0;
        cin >> s;
        for (int i=0 ; i<s.size() ; i++){
          if (s[i]=='{' || s[i]=='(' || s[i]=='['){
              stk.push(s[i]);
              continue;
          }
          if (!stk.empty()){
            if (s[i]=='}' && stk.top()=='{'){
                stk.pop();
            }
            else if (s[i]==')' && stk.top()=='('){
                stk.pop();
            }
            else if (s[i]==']' && stk.top()=='['){
                stk.pop();
            }
          }
        }
      if (stk.empty()) cout << "YES" << "\n";
      else cout << "NO" << "\n";
      while (!stk.empty()){
        stk.pop();
      }
    }
    return 0;
}