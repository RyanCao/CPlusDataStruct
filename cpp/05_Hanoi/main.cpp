/// 汉诺塔 程序编写 测试

/// ABC 三个盘， 要将 A 上的所有盘移动到C上， 问题 即将A上的所有盘借助B 移动到C上

/// 简化为 
///		1. 先将 A盘上 n-1 层移动到借助盘B上，
///		2. 将最终层 N 移动到 目标盘C上 
///		3. 将借助盘上的N-1 移动到C上
///
/// 其中最简化的问题为 n == 1 就不需要借助盘直接移动到 目标盘上
/// 如何表示 汉诺塔的 N 层 称为N盘,A,B,C 称为柱

/// 表达方式  移动A柱 1-2到 汉诺塔 C柱


#include <stdio.h>

void Move(int N, char src, char help, char target)
{
	if (N == 1) {
		printf("移动 %c 柱上的 %d 到%c柱\n", src, N, target);
	}
	else {
		Move(N - 1, src, target, help);
		printf("移动 %c 柱上的 %d 到%c柱\n", src, N, target);
		Move(N - 1, help, src, target);
	}
}

int main()
{
	while (true) {
		int n;
		printf("请输入 汉诺塔层数:");
		scanf("%d", &n);
		Move(n, 'A', 'B', 'C');
	}

	//等待输入，让Main程序暂停
	int val;
	scanf("%d", &val);
	getchar();

	return 0;
}