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
    cout << -1 << endl;
	for(int i = 0; i<b; i++){
		cout << 0 << endl;
	}
	for(int i = b; i<n; i++){
		cout << i + 1- b << endl;
	}
}

