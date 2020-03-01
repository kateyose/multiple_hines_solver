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

int main(){
	int n;
	cin >> n;
	cout << n << endl;
	cout << -1 << endl;
	srand (time(NULL));
	for(int i = 1; i<n; i++){
		cout << (i - 1)/2 << endl;
	}
}

