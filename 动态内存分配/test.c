#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <malloc.h>
struct S
{
	int* arr;
	int i;
};

int main()
{
	// struct S* ps = (struct S*)malloc(sizeof(struct S));
	// ps->arr = (int*)malloc(5 * sizeof(int));
	//
	// ��ʵ����ʹ�� �ṹ���Ա �е� ָ������ ָ��һ�� ���ٵĶ�̬�ڴ�ռ� �ķ�ʽ��
	// ���Բ��� ���������ڴ棬
	// 
	// ������� ����һ����̬�ڴ� ���������ṹ�壨����ڶ����� �Ƕ���ģ�
	// ����ֱ�Ӵ���һ�� �ṹ����� �������ջ������
	// Ȼ��ֻ�ÿ���һ���ڴ棬�� �ṹ���Ա �е� ָ������ ���� ��������ڴ�ռ�ĵ�ַ ���ɡ�

	struct S s = { NULL,100 };

	s.arr= (int*)malloc(5 * sizeof(int));

	if (s.arr == NULL)
		return 0;

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		s.arr[i] = i;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", s.arr[i] = i); // ��ӡ 0 1 2 3 4
	}

	free(s.arr);
	s.arr = NULL;

	return 0;
}

//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int* arr;
//	int i;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//
//	ps->arr = (int*)malloc(5 * sizeof(int));
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// �����ڴ�
//	int* ptr = realloc(ps->arr, 10 * sizeof(int));
//
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// �ͷ��ڴ�
//	free(ps->arr); // ���ͷ�
//	ps->arr = NULL;
//
//	free(ps); // ���ͷ�
//	ps = NULL;
//
//	// ע���ͷ��ڴ�� �Ⱥ����⣬
//	// ��Ϊ �����ͷ� ps ���Ͳ�����ͨ�� ps �ҵ� �ڶ�̬�ڴ��д�ŵ� �ṹ�壬
//	// Ҳ�� �޷����ʽṹ���Ա arr ��
//	// ���� �޷����ͷ� arr ���ٵ��ڴ档
//
//	ptr = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int* arr;
//	int i;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	// �� �ṹ���Ա �е� arr(Ϊ int*���� ���� ָ�� ) ��ָ��һ�� ��̬���ٵ��ڴ棬
//	// 
//	// ���� ��̬�����ڴ��С Ϊ 5 �� int���� �Ĵ�С��
//	// ����Ϊ arr Ϊ int*���� ��ֻ�ܽ��� int*���� ��ָ�룬
//	// ���� malloc() �ķ������� Ҫ ǿ������ת�� �� (int*)���� ��
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	return 0;
//}



//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int* arr; // ���ַ�ʽ���ٶ�̬�ڴ棬������ �������� ��������������
//	int i;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	// �� ��̬�ڴ濪�ٵķ�ʽ ����������ʹ�� �ýṹ��ָ�� �����ա�
//	// 
//	// ʹ�� ��̬�ڴ濪�ٵķ�ʽ ������������
//	// ��̬�ڴ�Ĵ�С sizeof(struct S) ������ int*���� �� int���� �Ĵ�С��
//	// 
//	// ��Ϊ malloc ���������� void*���� ����������Ҫ�� �ṹ��ָ����� ��������Ҫ ǿ������ת�� �� (struct S*) ��
//	// 
//	// ע�⣺���ַ�ʽ ���ٵĿռ� ����� ���� ��
//
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	// �� �ṹ���Ա �е� arr(Ϊ int*���� ���� ָ�� ) ��ָ��һ�� ��̬���ٵ��ڴ棬
//	// 
//	// ���� ��̬�����ڴ��С Ϊ 5 �� int���� �Ĵ�С��
//	// ����Ϊ arr Ϊ int*���� ��ֻ�ܽ��� int*���� ��ָ�룬
//	// ���� malloc() �ķ������� Ҫ ǿ������ת�� �� (int*)���� ��
//
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int i;
//	int arr[];
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	ps->i = 100;
//
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// �����ڴ�
//	struct S* ptr = realloc(ps, 44);
//	// realloc()�⺯�� ���Բ��� ǿ������ת�� �����Զ��� ���صĵ�ַ ǿ������ת�� �� ����Ҫ�����ڴ��ָ�� ��ͬ�����ͣ�
//	// ���Զ�ת������ ps ��ͬ�����͡�
//	// 
//	// ���� 44 ������ �ṹ���� int���ͳ�Ա 4 ���ֽڵĴ�С��
//	//         ���� (44 �����ڴ��С - 4 ��int���ͳ�Ա��С) / 4 ���������Ա���� = 10 �� ���������Ա�Ĵ�С�� 
//
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//
//	// �ͷ��ڴ�
//	free(ps);
//	ps = NULL;
//
//	ptr = NULL;
//	// ��Ϊ ps �� ptr ��ָ�� ͬһ�鶯̬�ڴ�ռ䣬
//	// ���� free(ps); �Ѿ��� �ö�̬�ڴ�ռ��ͷţ��Ͳ�����ʹ�� ptr �ͷš�
//	// 
//	// ����Ϊ ptr ͬ�����ҵ� �ö�̬�ڴ�ռ䣬
//	// �����ͷ� �ö�̬�ڴ�ռ� �󣬲��� ps Ҫ��Ϊ NULL��ָ�� ��ͬ�� ptr ҲҪ��Ϊ NULL��ָ�� ��
//
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int i;
//	int arr[];
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	ps->i = 100;
//
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i]=i;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int i; 
//	int arr[];
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	// ���� ���������Ա�Ľṹ�� Ҫ�� ��̬�ڴ濪�ٵķ�ʽ ��������
//	// ��ʹ�� �ýṹ��ָ�� �����ա�
//	// 
//	// ʹ�� ��̬�ڴ濪�ٵķ�ʽ ������������
//	// sizeof(struct S) ��Ϊ �ṹ��Ĵ�С ������ ���������Ա�Ĵ�С��
//	//                  ���� ���￪�ٿռ� �൱���Ǹ� ���� ���������Ա ����ĳ�Ա ���ٿռ䣻
//	// 5 * sizeof(char) ������Ǹ� ���� ���������Ա ���ٿռ䣬
//	//                   ���С����� ������������� ȷ���������ǿ��� 5 �� int���� ��С�Ŀռ䣬�� 50 ���ֽڡ�
//	// 
//	// ��Ϊ malloc ���������� void*���� ����������Ҫ�� �ṹ��ָ����� ��������Ҫ ǿ������ת�� �� (struct S*) ��
//	// 
//	// ע�⣺���ַ�ʽ ���ٵĿռ� ����� ���� ��
//
//	return 0;
//}


//#include <stdio.h>
//struct S
//{
//	int i; // int���� ռ 4 ���ֽ�
//	int arr[];
//};
//
//int main()
//{
//	struct S s;
//
//	printf("%d\n", sizeof(s)); // ��ӡ 4
//	// ˵�� ���������Ա�Ĵ�С ����� �ṹ��Ĵ�С �У�
//	// ���԰��� ���������Ա �� �ṹ�� ����ֻ�� �������� ��һ����Ա��
//
//	return 0;
//}


//struct S1
//{
//	int i;
//	int arr[]; // ���������Ա(λ�ô�С)
//};
//
//struct S2
//{
//	int i;
//	int arr[0]; // ���������Ա(λ�ô�С)
//};
//
//int main()
//{
//
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//
//	if (str != NULL) // ע���ж��Ƿ�ɹ����ٿռ�
//	{
//		strcpy(str, "hello");
//	}
//
//	free(str);
//	str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//
//		printf(str); // (��ִ��)
//	}
//
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//
//	strcpy(str, "hello");
//
//	free(str);
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//
//		printf(str); // ��ӡ world
//	}
//
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}



//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(&str, 100);
//
//	if (str != NULL) // �ж� GetMemory���� �Ƿ�ɹ����ٿռ� �� ���ظ�str
//	{
//		strcpy(str, "hello");
//
//		printf(str); // ��ӡ hello
//	}
//
//	// �ͷ��ڴ�
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}



//int* test()
//{
//	int* ptr;
//
//	*ptr = 10;
//	// ����Ҳ���� �Ƿ������ڴ� �����⣬
//	// ��Ϊ���� int* ptr; δ��ʼ�� ����һ�� ����ĵ�ַ��
//	// ��һ�� ����ĵ�ַ ���� �����ò��� �� �Ƿ������ڴ档
//	//
//	// �޷�����
//
//	return ptr;
//}
//
//int main()
//{
//	int* p = test();
//
//	return 0;
//}

//#include <stdio.h>
//char* GetMemory(void)
//{
//	static char p[] = "hello world";
//
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	str = GetMemory();
//
//	printf(str); // ��� hello world
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//char* GetMemory(char* p) // ע�� �������� ��Ϊ char*
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	str = GetMemory(str);
//
//	if (str != NULL) // �ж� GetMemory()���� �Ƿ񷵻� ���ٶ�̬�ڴ�ĵ�ַ
//	{
//		strcpy(str, "hello world");
//
//		printf(str);// ��ӡ hello world
//	}
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//void GetMemory(char** p) // ������ ָ��ĵ�ַ ��������Ҫ ����ָ�� ����
//{
//	char* ptr = (char*)malloc(100);
//
//	if (ptr != NULL) // �ж��Ƿ�ɹ����ٶ�̬�ڴ�
//	{
//		*p = ptr; // *p ���������ҵ� Test()���� �е� str
//	}
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(&str); // ��ַ���� ���������ı� str ��ֵ
//
//	if (str != NULL) // �ж� GetMemory()���� �Ƿ������ı� str ��ֵ
//	{
//		strcpy(str, "hello world");
//
//		printf(str); // ��ӡ hello world
//	}
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(str);
//
//	strcpy(str, "hello world");
//
//	printf(str);
//
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//
//	printf(arr);
//
//	printf("abcdef");
//
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(str);
//
//	strcpy(str, "hello world");
//
//	printf(str);
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	while (1)
//	{
//		malloc(1);
//	}
//	// �൱�� ���޿����ڴ� ���� �������ͷ�
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(100);
//
//	if (p != NULL)
//	{
//		return 0;
//	}
//
//	free(p);
//
//	p = NULL;
//	free(p);
//	// �� p ��Ϊ NULL��ָ�� ��
//	// ����� free() ���� NULL��ָ������ͷţ��൱��ʲôҲû������
//	// �Ӷ��������ͷ�ͬһ���ڴ����ɳ��������
//
//	return 0;
//}

//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(40);
//
//	p++; // p ����ָ�� ��̬�ڴ� �� ��ʼλ��
//
//	free(p);
//	// �� free() ֻ�ܴ� ��̬�����ڴ� �� ��ʼλ�� ��ʼ�ͷţ�
//	// �����Ǵ� ��̬�����ڴ� �� ��ʼλ�� ��ʼ�ͷţ��ᵼ�³��������
//
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//
//	free(p);
//	// �� �Ƕ�̬���ٵ��ڴ� ʹ�� free()�⺯�� �ͷţ�
//	// ����ɳ������
//
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//
//	if (p != NULL)
//	{
//		return 0; // �൱��ֱ�ӽ��� main()������
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		// malloc()�⺯�� ������ 5 �� int���� �Ŀռ䣬
//		// �� forѭ�� ������ ȴҪ���� 10  �� int���� �Ŀռ䡣
//		//
//		// Խ����� ����� �����������ѭ�����߿���
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(_CRT_INT_MAX);
//
//	if (p != NULL)
//	{
//		*p = 0;
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//
//	int* ptr = (int*)realloc(p, 40);
//
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//
//	int j = 0;
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", *(p + j));
//		// ��ӡ 0 1 2 3 4 -842150451(���ֵ) -842150451(���ֵ) -842150451(���ֵ) -842150451(���ֵ) -842150451(���ֵ)
//	}
//
//	return 0;
//}

//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//	// �� 20 ���ֽ�
//
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	// ���ϴ��� ����ʹ�� malloc()�⺯�� ���ٵĿռ�
//	// 
//	// ���赽�ˣ� 20 ���ֽ��Ѿ��޷�����Ҫ������ϣ���� 40 ���ֽڵĿռ䣬
//	// ��Ҫʹ�� realloc()�⺯�� �� ������̬�����ڴ�Ŀռ䡣
//	int* p1 = (int*)realloc(p, 40);
//
//	int j = 0;
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", *(p1 + j));
//		// ��ӡ 0 1 2 3 4 -842150451(���ֵ) -842150451(���ֵ) -842150451(���ֵ) -842150451(���ֵ) -842150451(���ֵ)
//	}
//	// �ɼ� realloc()�⺯�� �ɹ��� ��̬�����ڴ�Ŀռ� ����Ϊ 40 ���ֽڣ�
//	// 
//	// ��ԭ�������ݱ��ֲ��䣬������Ϊ��������ʧ( �� ���ڴ� ����Ϊ С�ڴ� ���� )��
//
//	return 0;
//}



//#include <malloc.h>
//int main()
//{
//	// �� �ڴ� ���� 10 �� int���� �Ŀռ�
//	int* p = (int*)calloc(10, sizeof(int));
//
//	return 0;
//}



//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}



//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p == NULL)
//	{
//		// ��ӡ����ԭ��
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			// �����ٵ��ڴ渳ֵ
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i)); // ��ӡ 0 1 2 3 4 5 6 7 8 9
//		}
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}



//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	// �� 32λƽ̨ ���ܳɹ��� 64λƽ̨ �ɿ��ٵĶ�̬�ռ�̫���Բ�����
//
//	int* p = (int*)malloc(_CRT_INT_MAX);
//	// _CRT_INT_MAX����int���� �� ֵ Ϊ 2147483647
//
//	if (p == NULL)
//	{
//		// ��ӡ����ԭ��
//		printf("%s\n", strerror(errno)); //��ӡ Not enough space
//		// ���� strerror()�⺯�� ������ <string.h>ͷ�ļ� ��
//		//      errnoȫ�ִ������ ������ <errno.h>ͷ�ļ� ��
//
//		printf("%p\n", p); // ��ӡ 00000000 ���� NULL��ָ��
//	}
//
//	return 0;
//}

//#include <malloc.h>
//int main()
//{
//	// �� �ڴ� ���� 10 �� int���� �Ŀռ�
//	int* p = (int*)malloc(10 * sizeof(int));
//	// �������� int���� �Ŀռ䣬��ϣ���� int���� ά����
//	// �� malloc()�⺯�� ���� void*���ͣ�������Ҫ ǿ������ת�� �� int*���� ��
//	// ��ʹ�� int*���� �� ָ�� ���ա�
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//
//	scanf("%d", &n);
//
//	int arr[n];
//	// ����д���� VS�������� �ǲ��Ϸ��ģ�
//	// ���� �ڴ���ʱ ����Ԫ�ظ��� ҪΪ ������
//
//	return 0;
//}