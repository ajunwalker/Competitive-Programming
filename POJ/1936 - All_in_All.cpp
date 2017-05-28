#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1, str2;
    while(cin >> str1){
        cin >> str2;
        int j = 0;
        for(int i = 0; i < str2.length() && j < str1.length(); ++i){
            if (str2[i] == str1[j]) j++;
        }
        if (j == str1.length()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
