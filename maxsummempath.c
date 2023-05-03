#include "header.h"

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int S(int n, int m, int **a, int **s, int i, int j){
	if(s[i][j]>=0) return s[i][j];
	if(i==1) s[1][j]=a[1][j];
	else if(j==1) s[i][1]=a[i][1]+max(S(n,m,a,s,i-1,m),max(S(n,m,a,s,i-1,1),S(n,m,a,s,i-1,2)));
	else if(j<m) s[i][j]=a[i][j]+max(S(n,m,a,s,i-1,j-1),max(S(n,m,a,s,i-1,j),S(n,m,a,s,i-1,j+1)));
	else s[i][m]=a[i][m]+max(S(n,m,a,s,i-1,m-1),max(S(n,m,a,s,i-1,m),S(n,m,a,s,i-1,1)));
	return s[i][j];
}

void solve(int n, int m, int **board){
	int sol=-1, j, i, **s, *p;
	s=(int **)malloc(sizeof(int *)*(n+1));
	for(i=1; i<=n; i++){
		s[i]=(int *)malloc(sizeof(int)*(m+1));
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			s[i][j]=-1;
		}
	}
	printf("Running maxsummem\n");
	for(j=1; j<=m; j++){
		sol=max(sol,S(n,m,board,s,n,j));
	}
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

