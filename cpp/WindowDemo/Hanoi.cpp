/// ��ŵ�� �����д ����

/// ABC �����̣� Ҫ�� A �ϵ��������ƶ���C�ϣ� ���� ����A�ϵ������̽���B �ƶ���C��

/// ��Ϊ 
///		1. �Ƚ� A���� n-1 ���ƶ���������B�ϣ�
///		2. �����ղ� N �ƶ��� Ŀ����C�� 
///		3. ���������ϵ�N-1 �ƶ���C��
///
/// ������򻯵�����Ϊ n == 1 �Ͳ���Ҫ������ֱ���ƶ��� Ŀ������
/// ��α�ʾ ��ŵ���� N �� ��ΪN��,A,B,C ��Ϊ��

/// ��﷽ʽ  �ƶ�A�� 1-2�� ��ŵ�� C��


#include <stdio.h>

void Move(int N, char src, char help, char target)
{
	if (N == 1) {
		printf("�ƶ� %c ���ϵ� %d ��%c��\n", src, N, target);
	}
	else {
		Move(N - 1, src, target, help);
		printf("�ƶ� %c ���ϵ� %d ��%c��\n", src, N, target);
		Move(N - 1, help, src, target);
	}
}

int main()
{
	while (true) {
		int n;
		printf("������ ��ŵ������:");
		scanf_s("%d", &n);
		Move(n, 'A', 'B', 'C');
	}

	//�ȴ����룬��Main������ͣ
	int val;
	scanf_s("%d", &val);
	getchar();

	return 0;
}