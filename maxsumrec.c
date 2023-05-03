#include "header.h"

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int S(int n, int m, int **a, int i, int j){
	if(i==1) return a[1][j];
	if(j==1) return a[i][1]+max(S(n,m,a,i-1,m),max(S(n,m,a,i-1,1),S(n,m,a,i-1,2)));
	if(j<m) return a[i][j]+max(S(n,m,a,i-1,j-1),max(S(n,m,a,i-1,j),S(n,m,a,i-1,j+1)));
	return a[i][m]+max(S(n,m,a,i-1,m-1),max(S(n,m,a,i-1,m),S(n,m,a,i-1,1)));
}

void solve(int n, int m, int **board){
	int sol=-1, j;
	printf("Running maxsumrec\n");
	for(j=1; j<=m; j++){
		sol=max(sol,S(n,m,board,n,j));
	}
	printf("Max sum is %d\n", sol);
}
