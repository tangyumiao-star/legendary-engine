#include <stdio.h>
unsigned long long derangement(int n) {
        if (n == 0) return 1; // 边界情况：0个信封时有1种排列方式
        if (n == 1) return 0; // 1个信封无法错位排列
	unsigned long long d0 = 1; // D(0)
	unsigned long long d1 = 0; // D(1)
	unsigned long long result = 0;
	for (int i = 2; i <= n; ++i) {
	result = (i - 1) * (d1 + d0); // 递推公式 D(n) = (n-1)*(D(n-1) + D(n-2))
	d0 = d1;
	d1 = result;
	}
	return result;
}

int main() {
	int n;
	printf("请输入信封数量n：");
        scanf("%d", &n);
	if (n < 0) {
	printf("错误：n必须为非负整数！\n");
	return 1;
	}
	printf("错位排列的数量为：%llu\n", derangement(n));
	return 0;
}
