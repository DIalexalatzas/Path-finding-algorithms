#include "header.h"

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int S(int n, int m, int **a, int **s){
	int sol=-1, i, j;
	for(j=1; j<=m; j++) s[1][j]=a[1][j];
	for(i=2; i<=n; i++){
		s[i][1]=a[i][1]+max(s[i-1][m],max(s[i-1][1],s[i-1][2]));
		for(j=2; j<=m-1; j++){
			s[i][j]=a[i][j]+max(s[i-1][j-1],max(s[i-1][j],s[i-1][j+1]));
		}
		s[i][m]=a[i][m]+max(s[i-1][m-1],max(s[i-1][m],s[i-1][1]));
	}
	for(j=1; j<=m; j++){
		sol=max(sol,s[n][j]);
	}
	return sol;
}

void solve(int n, int m, int **board){
	int j, i, **s, sol, *p;
	s=(int **)malloc(sizeof(int *)*(n+1));
	for(i=1; i<=n; i++){
		s[i]=(int *)malloc(sizeof(int)*(m+1));
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			s[i][j]=-1;
		}
	}
	printf("Running maxsumdp\n");
	sol=S(n,m,board,s);
	printf("Max sum is %d\n", sol);
#ifdef PATH
	p=(int *)malloc(sizeof(int)*(n+1));
	for(j=1; j<=m; j++){
		if(s[n][j]==sol){
			p[n]=board[n][j];
		}
	}
	for(i=n-1; i>=1; i--){
		for(j=1; j<=m; j++){
			if(s[i][j]+p[i+1]==sol){
				p[i]=board[i][j];
				sol=s[i][j];
			}
		}
	}
	for(i=1; i<n; i++){
		printf("%d -> ", p[i]);
	}
	printf("%d\n", p[n]);
#endif
}
