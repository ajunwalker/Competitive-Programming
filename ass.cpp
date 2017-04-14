#include <vector>
#include <iostream>
using namespace std;
#define N 112345

struct Node {
	int left, right, count;
};

int num;
int brawls;
vector<int> arr;
vector<int> side_right;
vector<int> side_left;
Node tree[4*N];

void construct(int left, int right, int ind){

	if (left > right) return;
	tree[ind].left = left;
	tree[ind].right = right;

	if(left == right){
		tree[ind].count = 1;
		return;
	}

	construct(left, (left+right)/2, ind*2);
	construct( (left+right)/2 + 1 , right, ind*2 + 1);

	tree[ind].count = tree[2*ind].count + tree[2*ind + 1].count;
}

void change(int val, int left, int right, int ind){

	if (val < left || val > right) return;

	if (left == right){
		tree[ind].count = 0;
		return;
	}

	change(val, left, (left+right)/2, ind*2);
	change(val, (left+right)/2 + 1, right, ind*2 + 1);

	tree[ind].count = tree[2*ind].count + tree[2*ind + 1].count;
}

int find(int x, int left, int right, int ind){

	if(left == right) return left;

	if(x>tree[2*ind].count){
		return find(x - tree[2*ind].count, (left+right)/2 + 1, right, 2*ind + 1);
	}
	else {
		return find(x, left, (left+right)/2, 2*ind);
	}
}

int main(){
	int start;
	int end;

	cin >> num >> brawls;

	for(int i = 0; i < num; i++){

		cin >> start;
		arr.push_back(start);
		side_right.push_back(i+1);
		side_left.push_back(i-1);

	}

	construct(0, num-1, 1);
	for(int i = 0; i < brawls; i++){

		cin >> start>> end;
		start= find(start+1, 0, num-1, 1);
		end = find(end+1, 0, num-1, 1);
		int curr = start;
		int ind = curr;

		while (curr <= end){
			if(arr[curr]>arr[ind]) ind = curr;
			curr = side_right[curr];
		}

		curr = start;
		while (curr <= end){

			if (curr == ind){
				curr = side_right[ind];
				if(side_left[start] >= 0){
					side_right[side_left[start]] = ind;
				}
				side_left[ind] = side_left[start];

				//if(side_right[end] < num){
				side_left[side_right[end]] = ind;
				//}

				side_right[ind] = side_right[end];
			}
			else {
				change(curr, 0, num-1, 1);
				cout << curr << " ";
				curr = side_right[curr];
			}
		}
		cout << endl;

	}

}
