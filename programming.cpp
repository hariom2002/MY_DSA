#include <bits/stdc++.h>
using namespace std;

int nums[8] = {10,9,2,5,3,7,101,18};

int solve(int n, int prev){
	
	if( n < 0)return 0;

	int notTake = 0 + solve(n-1, prev);
	int take = 0;
	if(prev == -1 || nums[n] > nums[prev]){
		take = 1 + solve(n-1, n);
	}
	return max(take, notTake);
	
}

class student{
	int marks;

public:
	student(){
		cout<<"inside student-defualt const."<<endl;
	}

	student(int x){
		marks = x;
	}

};




int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writint output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	student s1(100);
	student s2();
	student s3 = 100;
	
	
    return 0;	
}
