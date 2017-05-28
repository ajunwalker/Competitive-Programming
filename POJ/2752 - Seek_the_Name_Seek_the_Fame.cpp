#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 400000

int ind[MAX];
vector<int> ans;

void prefix(string s){
	for(int i = 1, j = 0; i < s.length(); ++i){
		while(j >= 0 && s[j] != s[i]){
			if (j-1 >= 0) j = ind[j];
			else j = -1;
		}
		ind[i+1] = ++j;
	}
}

int main(){
	string s;
	while(cin >> s){
		ans.clear();
		prefix(s);
		for(int x = s.length(); x > 0; x = ind[x]) ans.push_back(x);
		for(int i = ans.size()-1; i >= 0; --i) cout << ans[i] << " ";
		cout << endl;
	}
}
