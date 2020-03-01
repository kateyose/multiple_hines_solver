#include<cmath>
#include<set>
#include<cstring>
#include<climits>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include <fstream>
#define long long long
using namespace std;

int main(){
    std::ifstream infile("0012.swc");
    int a, t, c;
    float x,y,z,r;
    vector<int> v, b, bp;
    int branch_count = 0;
    while (infile >> a>> t >> x>> y>> z>> r>> c)
    {
        v.push_back(c-1);
        if(t == 5){
            b.push_back(1);
            bp.push_back(1);
            branch_count++;
        } else {
            b.push_back(0);
            bp.push_back(0);
        }
    }

    int n = v.size() + branch_count -1 ;
    cout << n << endl;
    //cout << branch_count << endl;
    int *temp = new int[v.size()];

    int *p = new int(n);
    for(int i = 1; i < v.size()-1; i++){
        b[i+1] += b[i];
    }
    for(int i = 1; i < v.size(); i++){
        cout  <<  v[i] + b[v[i]] - 1 << endl;
        if (bp[i] == 1){
            cout  << i -1 + b[i-1]  << endl;
        }
    }
	for(int i = 0; i<3*n; i++){
		cout << ((double) rand() / (RAND_MAX)) << endl;
	}
    
}
