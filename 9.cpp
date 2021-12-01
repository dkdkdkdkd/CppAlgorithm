#include<stdio.h>
using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin);

	int n, cnt = 0;
	int tmp;

	scanf("%d", &n);


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % j == 0) {
				tmp = i / j;

				if (j > tmp) {
				
					break;
				}
				else if (j == tmp) {
					cnt++;
					break;
				}
				else
				{
					cnt += 2;
				}
			}
		}
		printf("%d ", cnt);

		cnt = 0;
	}


	return 0;
}


#include<stdio.h>
using namespace std;
int cnt[50001];
int main() {
	//freopen("input.txt", "rt", stdin);
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j = j + i) {
			cnt[j]++;
		}
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
}
