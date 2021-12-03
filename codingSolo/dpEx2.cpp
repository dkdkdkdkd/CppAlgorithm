//  my
#include<stdio.h>
#include<algorithm>

using namespace std;


typedef struct N
{
	int w;
	int p;

}N;


int main()
{
	int n;
	int k;
	int tmp;
	int** dp;

	N nArray[1001] = { 0 };
	int dp[1001][10001] = { 0 };

	scanf("%d %d", &n, &k);

	for (int i = 1; i < n; i++) {
		scanf("%d %d", &(nArray[i].w), &(nArray[i].p));
	}
	 

	N narray[5] = { {0, 0}, {2, 40}, {5, 110}, {10, 200}, {3, 50}};
	int dp[5][15] = { 0 };

	printf("%d %d\n", narray[1].w, narray[1].p);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 14; j++) {
			if (j >= narray[i].w) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - narray[i].w] + narray[i].p);
			}
			else
				dp[i][j] = dp[i][j - 1];
		}
	}

	
	printf("%d", dp[4][14]);


	return 0;
}

// learn

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101];
int V[101];
int dp[101][100010];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &W[i], &V[i]);
	//scanf("%d%d", W + i, V + i);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i] > j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			// 만약 같은 물건을 2개 이상 고를 수 있다면,
			//dp[i][j] = max(dp[i - 1][j], dp[i][j - W[i]] + V[i]);
		}
	}
	printf("%d", dp[N][K]);
}
