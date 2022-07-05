#include<iostream>
using namespace std;
int lis(int input1,int input2[]){
	if(input1==1){
		return 1;
	}
	int dp[input1];
	dp[0]=1;
	for(int i=1;i<input1;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(input2[i]>input2[j]&&dp[i]<1+dp[j]){
				dp[i]=1+dp[j];
			}
		}
	}
	int res=1;
	for(int i=0;i<input1;i++){
		if(dp[i]>res){
			res=dp[i];
		}
	}
	return res;
}
int main(){
	int n=3;
	int arr[5]={1,2,3,4,5,0,-1};
	int res=lis(n,arr);
	cout<<res;
}