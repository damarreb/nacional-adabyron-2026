#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    while (N){
        vector<char> v(N); for (auto &vi : v) cin >> vi;
        int lastR, lastC, lastH;
        lastR = lastC = lastH = -1;
        int res = N+1;

        for (int i = 0; i < N; i++){
            if (v[i] == 'R') lastR = i;
            else if (v[i] == 'C') lastC = i;
            else lastH = i;
            if (lastR != -1 && lastC != -1 && lastH != -1)
                res = min(res,i-min(min(lastR,lastC),lastH)+1);
        }
        if (res != N+1) cout << res << '\n';
        else cout << "NO SE PUEDE\n";
        cin >> N;
    }
    return 0;
}