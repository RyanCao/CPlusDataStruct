/// 排序算法 程序编写 测试

/// 快速排序

#include "stdio.h"

/// <summary>
/// 快排
/// </summary>
/// <param name="">数组指针</param>
/// <param name="">快排数组起始下标</param>
/// <param name="">快排数组结束下标</param>
void QuickSort(int*, int, int);

/// <summary>
/// 快排查找首节点应该在那个位置上
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
int FindPos(int*, int, int);

void QuickSort(int* pBase, int low, int high)
{
	if (low >= high)
		return;

	//找到第一个点的位置
	int val = pBase[low];
	int pos = FindPos(pBase, low, high);
	pBase[pos] = val;

	//前面位置快排
	QuickSort(pBase, low, pos - 1);
	//后面部分进行快排
	QuickSort(pBase, pos + 1, high);
}

int FindPos(int* pBase, int low, int high)
{
	int val = pBase[low];
	while (low < high)
	{
		while (pBase[high] >= val && low < high)
		{
			high--;
		}
		pBase[low] = pBase[high];

		while (pBase[low] <= val && low < high)
		{
			low++;
		}
		pBase[high] = pBase[low];
	}
	return low;
}






int main()
{

	//等待输入，让Main程序暂停
	int a[8] = { -30,1,2,10,7,4,25,22 };
	QuickSort(a, 0, 7);

	for (size_t i = 0, length = 8; i < length; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	getchar();

	return 0;
}