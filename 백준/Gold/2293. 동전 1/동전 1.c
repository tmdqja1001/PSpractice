#include <stdio.h>

int n, coin, k, dp[10001];
int main()
{
	int j;
	dp[0] = 1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin);
		for (j = 0; j <= k; j++) {
			if (j >= coin) {
				dp[j] = dp[j] + dp[j - coin];
			}
		}
	}
	printf("%d\n", dp[k]);
}
