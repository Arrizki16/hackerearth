#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

int row[] = {1 , 1 , 0 , -1 , -1 , -1 , 0 , 1};
int col[] = {0 , 1 , 1 ,  1 ,  0 , -1, -1, -1};

queue <pair<int,int> > q;

int main(){
    int baris, kolom, x,y;
    cin >> baris >> kolom >> y >> x;
    
    int arr[baris+2][kolom+2];
    bool visited[baris+2][kolom+2];
    memset (visited, false, sizeof(visited));
    memset (arr, -1 , sizeof(arr));

    // for (int i=0 ; i<baris ; i++){
    //     for (int j=0 ; j<kolom ; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    arr[y][x] = 0;
    q.push(mp(y ,x));
    visited[y][x] = true;

    while (!q.empty()){
        int b = q.front().first;
        int k = q.front().second;
        q.pop();

        // visited[b][k] = true;
        for (int i=0 ; i<8 ; i++){         
            int c = b+row[i];
            int d = k+col[i];
            if (visited[c][d]==false && arr[c][d]==-1 && c>=0 && c<baris && d>=0 && d<kolom){
                arr[c][d] = arr[b][k] + 1;
                visited[c][d] = true;
                q.push(mp(c,d));
            }
        }
    }
    for (int i=0 ; i<baris ; i++){
        for (int j=0 ; j<kolom ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}