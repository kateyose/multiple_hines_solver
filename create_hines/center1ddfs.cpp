#include<cmath>
#include<set>
#include<cstdint>
#include<climits>
#include<tuple>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#define long long long
using namespace std;

int main(int argc, char* argv[]){
	int n;
	cin >> n;
	cout << n << endl;
    char *ptr;
    int b = strtol(argv[1], &ptr, 10);
    int s = 1;
    int c = 0;
    for(int i = 0; i < n; i++){
        if (i == s){
            cout << 0 << endl;
            s += (n-1)/b;
            if (c < ( n -1) % b){
                s++;
                c++;
            }
        } else {
            cout << i - 1 << endl;
        }
    }
}

