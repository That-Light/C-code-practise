#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };   //��Ҫ���ҵ�����
//
//	int k = 7;   //��Ҫ���ҵ�ֵ
//
//	int left = 0;   //���±�
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //����������ж��ٸ���
//	int right = sz - 1;   //���±�
//
//	   //���ֲ��ҷ�
//	while (left <= right)   //���Ҳ���kʱ����Ϊ right-1 �� left + 1 ������ left �� right �ύ��
//	{
//		int mid = (left + right) / 2;   //�м��±�
//
//		if (arr[mid] > k)   //�� arr[mid] �� k ��ʱ��֤�� k �� arr[mid] ��� ��Ӧ�޸� right
//		{
//			right = mid - 1;   //Ϊʲô -1 ����Ϊ arr[mid] �Ѿ��� k ���� ��ֻ��� arr[mid-1] ��ʼ�Ƚ�
//		}
//		else if (arr[mid] < k)   //�� arr[mid] �� k Сʱ��֤�� k �� arr[mid] �ұ� ��Ӧ�޸� left
//		{
//			left = mid + 1;   //Ϊʲô +1 ����Ϊ arr[mid] �Ѿ��� k С�� ��ֻ��� arr[mid+1] ��ʼ�Ƚ�
//		}
//		else   //���д�� else (arr[mid] == k); �ǵ���һ����;��
//		{
//			printf("�ҵ��ˣ��±�Ϊ %d", mid);
//			break;   //�ҵ���Ҫ����ѭ�����������ѭ����Ӱ�������жϡ������û���ҵ���
//		}
//	}
//
//	if (left > right)   //���Ҳ���kʱ����Ϊ right-1 �� left + 1 ������ left �� right �ύ��
//	{
//		printf("û���ҵ�");
//	}
//
//	return 0;
//}