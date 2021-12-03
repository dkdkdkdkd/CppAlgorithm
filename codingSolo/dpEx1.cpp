
//my,not dp

#include<stdio.h>


int main() {

	int n; 
	int flag = 1; 
	int tmp[5000];
	int idx = 0;
	int min = 5000;


	scanf("%d", &n);


	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 5000; j++) {
			if (3 * i + 5 * j == n) {
				tmp[idx] = i + j;
				idx++;
			}
		}
	}
	if (idx != 0) {
		for (int i = 0; i < idx; i++) {
			if (min > tmp[i]) {
				min = tmp[i];
			}
		}

		printf("%d", min);

	}
	else
	{
		printf("-1");
	}



	return 0;
}
//my, dp

#include<stdio.h>

int main() {

	int n; 
	int dp[5001];
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;


	scanf("%d", &n);

	for (int i = 6; i <= n; i++) {

		if (dp[i - 3] != -1) {
			dp[i] = dp[i - 3] + 1;
			if (dp[i - 5] != -1) {
				if (dp[i] > dp[i - 5]) {
					dp[i] = dp[i - 5] + 1;
				}
			}
		}
		else {
			if (dp[i - 5] != -1) {
				dp[i] = dp[i - 5] + 1;
			}
			else {
				dp[i] = -1;
			}
		}
	}
	printf("%d", dp[n]);




	return 0;
}

//learn, dp

#include <iostream>
#include <algorithm>
using namespace std;

#define X 5000

int dp[5010] = { 0, X, X, 1, X, 1 };
int N;

int main() {
	scanf("%d", &N);
	for (int i = 6; i <= N; i++)
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);

	if (dp[N] >= X) {
		printf("-1");
		return 0;
	}

	printf("%d", dp[N]);
}
