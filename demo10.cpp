#include <bits/stdc++.h>
using namespace std;

class nonConst{
	public:
	const int T;

	nonConst(int t): T(t){

	}
	nonConst operator+(nonConst &a){
		
	}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

	void print(){
		cout<<val<<endl;
	}
};

vector<pair<int,int>> movements = {{1,0},{0,1},{-1,0},{0,-1}};

bool isValid(int x,int y,int n,int m){
	return x>=0 && y>=0 && x<n && y<m;
}

int minimumElements(vector<int> &num, int x)
{
    int n = nums.size();
	
}
int main()
{
}