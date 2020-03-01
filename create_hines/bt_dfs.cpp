#include<string.h>
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
	vector<int> child[n];
	int par[n];

	for(int i = 1; i<n; i++){
		par[i] = (i-1)/2;
		child[(i - 1)/2].push_back(i);
	}

	int flag[n];
	int btod[n];
	int dtob[n];
    memset( flag, 0, n*sizeof(int) );
    memset( btod, 0, n*sizeof(int) );
    memset( dtob, 0, n*sizeof(int) );
	int cur = 0;
	int count = 0;
	stack<int> s;
	s.push(cur);
	while(!s.empty()){
		if(flag[cur] != 0){
			cur = s.top();
			s.pop();
		}
		dtob[count] = cur;
		btod[cur] = count;
		flag[cur] = 1;
		while(!child[cur].empty()){
			s.push(child[cur].back());
			child[cur].pop_back();
		}
		count++;
		cur = s.top();
		s.pop();
	}

	cout << -1 << endl;
	for(int i = 1; i<n; i++){
		cout << btod[par[dtob[i]]] << endl;
	}

}

