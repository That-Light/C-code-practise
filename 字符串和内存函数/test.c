#define _CRT_SECURE_NO_WARNINGS



#include <memory.h>
int main()
{
	int arr[10] = { 0 };

	memset(arr, 1, 10);

	return 0;
}


//#include <memory.h>
//int main()
//{
//	char arr[5] = "";
//
//	memset(arr, 'w', 5);
//
//	return 0;
//}


//#include <stdio.h>
//#include <memory.h>
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	int arr2[] = { 1,2,4 };
//
//	int ret1 = memcmp(arr1, arr2, 8);
//	printf("%d\n", ret1); // ��ӡ 0
//
//	int ret2 = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret2); // ��ӡ -1
//
//	return 0;
//}


//#include <assert.h>
//#include <stdio.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if (dest < src || dest>(void*)((char*)src + num))
//		// ���� (void*)((char*)src + num) ��
//		// src ԭ���� void*���� Ҫ ǿ������ת���� (char*) ���� +num ��
//		// ��� ((char*)src + num) ����Ϊ char*���� ��Ҫ�� ǿ������ת���� (void*) �ٽ��бȽϣ�
//		// ����ᱨ ���Ͳ����� ���档
//	{
//		// ��ǰ���� ����
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		// �Ӻ���ǰ ����
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	// ��ӡ 1 2 1 2 3 4 5 8 9 10
//
//	return 0;
//}



//#include <assert.h>
//#include <stdio.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if (dest < src) // ��ַ ���� ���Ͳ�ͬ Ҳ���� ֱ�� �Ƚϴ�С ��ֻ���� ���Ͳ�ͬ ʱ�ᱨ ���Ͳ����� �ľ��棬
//		            // �ߵ�ַ ��󣬵͵�ַ ��С��
//					// ���� dest �� void*���� ����Ȼ src �� const void*���� ����Ҳ�� void*���� �����ᱨ ���Ͳ����� �ľ��棬
//					// 
//					// ֻ���� ������ ���� �Ӽ����� ʱ���� ���� �й�ϵ��
//	{
//		// ��ǰ���� ����
//		while (num--) // num-- �����ü��� ����ʹ�� �ټ�����
//			          // �� �� �ж� �ܷ��������� ���� while()ѭ�� ��
//					  // Ȼ�� ִ���Լ����� ��
//					  // �Լ���ɺ����ܽ��� while()ѭ�� ���ٴ��� �Լ��� num �� ֵ ���� while()ѭ�� ��
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		// �Ӻ���ǰ ����
//		while (num--) // ͬ�� num-- �����ü��� ����ʹ�� �ټ���
//			// �������õú����� ��
//			// ��Ϊ �Ӻ���ǰ ��������Ҫ�ҵ� dest �� src �� ���һ���ֽ� ��
//			// �� dest �� src �� ���һ���ֽ� ������ (dest + num) �� (src + num) ��
//			// ���� (dest + num - 1) �� (src + num - 1)
//			// 
//			// ���� while (num--) ��Ϊ num �Լ��� �ٽ��� while()ѭ�� �պ������� (num - 1) ,
//			// ���ѭ����
//			// �� (num == 1) ʱ �����ж� �ܽ��� while()ѭ�� ��Ȼ���Լ��� (num == 0) �ٽ��� while()ѭ�� ��
//			// �պ����� �Ӻ���ǰ ������Ҫ��
//		{
//			*((char*)dest + num) = *((char*)src + num); // num �� while(num--) ���Ѿ� ��1 �������� ��1
//		}
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	// ��ӡ 1 2 1 2 3 4 5 8 9 10
//
//	return 0;
//}


//#include <assert.h>
//#include <stdio.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if ((char*)dest - (char*)src > 0)
//	{
//		(char*)dest = (char*)dest + num-1;
//		(char*)src = (char*)src + num-1;
//		while (num--)
//		{
//
//			*(char*)dest = *(char*)src;
//			--(char*)dest;
//			--(char*)src;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <assert.h>
//#include <stdio.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//
//	void* ret = dest;
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	memcpy(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <assert.h>
//#include <stdio.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//
//	void* ret = dest;
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memcpy(arr + 2, arr, 20);
//	// (arr + 2) �� Դͷ �� ��ַ
//	// arr �� Ŀ�ĵ� �� ��ַ
//	// 20 �ǿ��� 5 * 4(int����) = 20 ���ֽ�
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//// void*���� ȷ���ܽ����κ����͵� ָ��
//{
//	assert(dest && src);
//
//	void* ret = dest; // ����һ�� dest �� ��ʼ��ַ���Ա���󷵻�
//
//	while (num--) // num-- �����ü��� ����ʹ�� �ټ������� �Ƚ��� while()ѭ�� ����ѭ������һ�� ��ִ���Լ�����
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest; // ǰ�üӼ� ����ʹ�� �ټӼӣ��� �� ǿ������ת�� �� (char*)���� ����ִ����������
//		++(char*)src; // ǰ�üӼ� ����ʹ�� �ټӼӣ��� �� ǿ������ת�� �� (char*)���� ����ִ����������
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = {1,2,3};
//	int arr2[3] = { 0 };
//
//	my_memcpy(arr2, arr1, sizeof(arr1));
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	int arr1[] = {1,2,3};
//	int arr2[3] = { 0 };
//
//	strcpy(arr2, arr1);
//
//	return 0;
//}


//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	char arr[] = "I Am A Student";
//
//	int i = 0;
//
//	for (arr[i]; arr[i]; i++)
//		// ��Ϊ��ʼʱ i Ϊ 0 ��
//		// 
//		// ��ʼ����Ϊ arr[i] ���� arr[0] ���൱�ڴ� �ַ�����arr �� ��һ���ַ� ��ʼ��
//		// 
//		// ���ŵ������� i++ ������ ȡ�� �ַ�����arr ��ÿһ���ַ� ��Ϊ �ж�������
//		// �� �ַ� ��Ϊ �ж����� ���жϵ��� ���ַ���Ӧ��ASCII��ֵ ��
//		// ���� '\0' �� ASCII��ֵ Ϊ 0 ��
//		// �����ַ� �� ASCII��ֵ ����Ϊ 0 ����Ϊ �� ������ѭ��ִ����䣬
//		// 
//		// ֱ�� ȡ�� �ַ�����arr ���һ���ַ� ���� '\0' ,
//		// �� '\0' �� ASCII��ֵ Ϊ 0 ����ʱ �ж����� arr[i] == 0 Ϊ �� ������ѭ��
//	{
//		if (islower(arr[i]))
//			// �ж��Ƿ�ΪСд��ĸ
//			// ��Сд��ĸ���� islower() ���� ����ֵ����Ϊ �� ������ ifִ�����
//		{
//			arr[i] = toupper(arr[i]); // Сд��ĸת��д
//		}
//		else // ���� Сд��ĸ(�����ո�' ')���� islower() ���� 0 ����Ϊ �� ������ elseִ�����
//		{
//			arr[i] = tolower(arr[i]); // ��д��ĸתСд��
//			                          // �ո񲻷����仯����������
//		}
//
//		putchar(arr[i]);
//		// ������� i aM a sTUDENT
//	}
//
//}


//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	// ע�⣺
//	// �� �ַ����� ���� �ַ������� ��
//	// ���� �ַ� ���� ' ' �����ַ����� " "
//
//	// ��ʽһ���ַ�����
//	char ch1 = 'Q'; 
//	ch1 = tolower(ch1); //�� ��дQ ת Сдq
//	printf("%c\n", ch1); // ��ӡ q
//    // �ַ�ʹ�� %c ��ӡ
//
//	// ��ʽ�����ַ�����
//	char ch2 = toupper('Q'); // ��дQ ת��д������ ��дQ
//	putchar(ch2); // ��ӡ Q
//	// �ַ�����ʹ�� putchar() ���
//
//	// ���������ַ���ӦASCII��ֵ
//	char ch3 = toupper(113); // ASCII��ֵ113 ��Ӧ �ַ�Q ����дQ ת��д������ ��дQ
//	putchar(ch3); // ��ӡ Q
//
//    // ����ĸ�ַ�
//	char ch4 = toupper('2'); // ����ĸ�ַ�(�� ����ĸ�ַ���ASCII��ֵ) ���� ��ʲô�ַ� ֱ�� ���ʲô�ַ�
//	putchar(ch4); // ��ӡ 2
//
//	return 0;
//}


//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	// ע�⣺
//	// �� �ַ����� ���� �ַ������� ��
//	// ���� �ַ� ���� ' ' �����ַ����� " "
//
//	// ��ʽһ
//	char ch1 = 'w'; 
//	int ret1 = isdigit(ch1);
//	printf("ret1 = %d\n", ret1); // ��ӡ ret1 = 0
//
//	// ��ʽ��
//	int ret2 = isdigit('1');
//	printf("ret2 = %d\n", ret2); // ��ӡ ret2 = 4
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("test.txt", "r");
//	// fopen()���� �������� ���ļ���
//	// 
//	// ��������������һ���� �ļ������֣�
//	//               �ڶ����� �򿪵ķ�ʽ ������ "r" �� ֻ�� ����˼��
//	// 
//	// ���������� FILE*����
//	// 
//	// �ļ� ��Ҫ����� ����Ŀ �� ���·�� ���£�
//	// �����ܳɹ���
//
//	if (pf == NULL) 
//		// ����һ�� NULL��ָ�� ˵���ļ���ʧ�ܣ�
//		// ��ʧ�ܵ�ԭ���кܶ࣬���ļ������ڡ�����Ȩ�޲��� �ȵȣ�
//		// ��Ҫ�� strerror() �鿴����ʧ�ܵ�ԭ��
//	{
//		printf("%s\n", strerror(errno));
//		// ���� errno �� ȫ�ִ�����ı��� ��
//		// �� C���� �� �⺯�� ��ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ�� errno �У�
//		// ͨ�� strerror(errno) ���ܲ鵽 ��Ӧ���������Ϣ ��
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		char* str = strerror(i);
//
//		printf("%d -> %s\n", i, str);
//		//��ӡ ������0~4 ��Ӧ�Ĵ�����Ϣ
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "123.123@.@123";
//	char* p = "@.";
//
//	//��ʱ����
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//
//	//�и��ַ���
//	char* ret = NULL;
//
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "1124590960@qq.com";
//	char* p = "@.";
//	 
//	//��ʱ����
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//
//	//�и��ַ���
//	char* ret = NULL;
//
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//		// ���� forѭ�� �������ڣ�
//		// forѭ�� �� ��ʼ�� ֻ��ִ��һ�Σ��պ�����ִ�� strtok(arr, p) ��
//		// 
//		// ���� strtok(arr, p) ���صĲ��� NULL��ָ�� ʱ �� forѭ�� �����ж� Ϊ �� ��
//		// ���� forѭ��ִ����� ��
//		// 
//		// ÿ��ִ����󣬶�ִֻ�� forѭ�� �������� �� strtok(NULL, p) ��
//		// ������ forѭ�� ��ʼ�� �� strtok(arr, p) ��
//		// �պ����� strtok()�⺯�� ��ʹ��Ҫ��
//		// 
//		// ֱ�� ���ַ������Ҳ�������ı�� ��strtok() �򷵻�NULL ��
//		// ��ʱ forѭ�� �����ж� Ϊ �� ������ѭ��
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "1124590960@qq.com";
//	char* p = "@.";
//
//	//��ʱ����
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//
//	//�и��ַ���
//	char* ret = strtok(arr, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//	char* ret1 = strtok(NULL, p);
//	printf("%s\n", ret1);
//
//	ret1 = strtok(NULL, p);
//	printf("%s\n", ret1);
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	char* s1 = NULL;
//	char* s2 = NULL;
//
//	char* cur = (char*)p1;
//
//	//���ҵ��ַ��� Ϊ �� ��ֱ�ӷ��� �������ַ��� �� ���ַ� ��ַ
//	if (!*p2)
//		// !�� Ϊ �߼��� ��������� ���� �� �ٱ��� ��
//		// 
//		// �� *p2 == '\0' �� *p2 == 0 ������Ϊ�� ���� !*p2 �� Ϊ��   ���� ifִ����� ��
//		// �� *p2 != '\0' �� *p2 != 0 ������Ϊ�� ���� !*p2 �� Ϊ�� ������ ifִ����� ��
//		// 
//		// ԭ��Ϊ if(*p2 == '\0') ��
//	{
//		return (char*)p1;
//	}
//
//
//	while (*cur)
//	{
//		s1 = cur;
//
//		s2 = (char*)p2;
//
//		// �Ա��Ƿ�Ϊ�Ӵ�
//		while ((*s1 != '\0') && (*s1 == *s2))
//			// ����Ҫ�ж� (*s1 != '\0') �� (*s2 != '\0') ����һ�� Ҳ����(���費Ҫ (*s2 != '\0') )��
//			// ��Ϊ�� *s1 �� *s2 ��Ϊ '\0' ���� (*s1 != '\0') ������ whileѭ�� ��
//			//     �� *s1 Ϊ '\0' ���� *s2 ��Ϊ '\0' ���� (*s1 != '\0') ������ whileѭ�� ��
//			//     �� *s1 ��Ϊ '\0' ���� *s2 Ϊ '\0' ���� (*s1 == *s2) ������ whileѭ�� ��
//			//     �� *s1 ��Ϊ '\0' ���� *s2 ��Ϊ '\0' ���� (*s1 == *s2) ������жϡ�
//			// 
//			// ԭ��Ϊwhile ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2)) ��
//			// 
//			// 
//			// �������Ż�Ϊ while ((!*s1) && !(*s1-*s2)) ������ (!*s1) ��������Ż����ƣ�
//			// !(*s1-*s2) 
//			// �� *s1 == *s2 ���� *s1 - *s2 == 0 ������Ϊ�� ���� !(*s1-*s2) �� Ϊ��   ���� whileѭ�� ��
//			// �� *s1 != *s2 ���� *s1 - *s2 != 0 ������Ϊ�� ���� !(*s1-*s2) �� Ϊ�� ������ whileѭ�� ��
//		{
//			s1++;
//			s2++;
//		}
//
//		if (!*s2)
//			// !�� Ϊ �߼��� ��������� ���� �� �ٱ��� ��
//		    // 
//		    // �� *s2 == '\0' �� *s2 == 0 ������Ϊ�� ���� !*s2 �� Ϊ��   ���� ifִ�����
//		    // �� *s2 != '\0' �� *s2 != 0 ������Ϊ�� ���� !*s2 �� Ϊ�� ������ ifִ�����
//			// 
//			// ԭ��Ϊ if(*s2 == '\0')
//		{
//			return cur;
//		}
//
//		cur++;
//	}
//
//	return NULL;
//
//}
//
//int main()
//{
//	const char* str1 = "abbbcdef";
//	const char* str2 = "bbc";
//
//	char* ret = my_strstr(str1, str2);
//
//	if (ret == NULL)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	//��ӡ bbcdef
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	char* s1 = NULL; // ����ַ��Ա�ʱ���� s1 ��¼ָ���� �ַ���str1 ��λ��
//	char* s2 = NULL; // ����ַ��Ա�ʱ���� s2 ��¼ָ���� �ַ���str2 ��λ��
//
//	char* cur = (char*)p1; // ��¼�� �ַ���str1 �� �ĸ��ַ� ��ʼ�Աȣ�
//						   // ��Ϊ �ҵ����Ӵ� Ҫ���� ��ʼ�Ա� �� �Ǹ��ַ� �� ��ַ ���� s1 �� s2 һֱ�ڱ仯��
//					       // ������Ҫ cur ��¼�� �ַ���str1 �� �ĸ��ַ� ��ʼ�Աȣ��Ա� return���� ��
//						   // 
//						   // ��Ϊ p1 �������� const char* ���� ǿ������ת�� �� (char*) ���ܴ��� cur �С�
//
//	//���ҵ��ַ��� Ϊ �� ��ֱ�ӷ��� �������ַ��� �� ���ַ� ��ַ
//	if (*p2 == '\0')
//	{
//		return (char*)p1; // ��Ϊ p1 �������� const char* ���� ������������ �� char* ��������Ҫ ǿ������ת�� �� (char*)
//	}
//
//
//	while (*cur)
//		// �� (*cur == '\0') �� (*cur == 0) ʱ������ Ϊ0 Ϊ�� ������ whileѭ�� ��
//		// ˵�� �����ҵ��ַ���str1 �Ѿ��Աȵ����һ���ַ��� ����û���ҵ� �Ӵ���
//	{
//		s1 = cur;
//		// ÿ�� s1 ��Ҫ ���� �� �ַ���str1 �� ��ʼ�Ա� �� �ַ� �� ��ַ ��
//		// ��Ϊ s1 �� �Ա��Ƿ�Ϊ�Ӵ� �Ļ��� ���ܷ����ı䣬
//		// �������ã����ܻᵼ�±������Ӵ�����ȴû�ҵ��������
//
//		s2 = (char*)p2; // ÿ�ζ��Ǵ� str2 �� ���ַ� ��ʼ�Ա�
//		         //
//		         // ��Ϊ p2 �������� const char* ���� ǿ������ת�� �� (char*) ���ܴ��� s2 �С�
//
//		// �Ա��Ƿ�Ϊ�Ӵ�
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//			// ֻ�е� (*s1 != '\0') && (*s2 != '\0') ���ŶԱ� (*s1 == *s2) ����������
//			// ˵�� �����ҵ��ַ���str1 �� ���ҵ��ַ���str2 ���ַ� ��ͬ �����Լ������±Ƚϡ�
//			// 
//			// �� *s1 == '\0' ʱ˵�� �����ҵ��ַ���str1 �� ���ҵ��ַ���str2 �̣��������ҵ��Ӵ���
//			// 
//			// �� *s2 == '\0' ʱ˵�� ���ҵ��ַ���str2 �Ա���ɣ��� �����ҵ��ַ���str1 �ҵ��Ӵ���
//		{
//			s1++;
//			s2++;
//		}
//
//		if (*s2 == '\0')
//			// �� s2 �ҵ� '\0' ʱ��
//			// ˵���� �����ҵ��ַ���str1 ���� ���ҵ��ַ���str2 ���Ӵ� ��
//			// �򷵻� cur ��ֵ���� �ַ���str1 �� ��ʼ�Ա� �� �ַ� �� ��ַ ��
//		{
//			return cur;
//		}
//
//		cur++; //���� �����ҵ��ַ���str1 �� ��һ���ַ� �ٽ��жԱ�
//	}
//
//	return NULL; // �� (*cur == '\0') ʱ���� whileѭ�� ��
//				 // ˵�� �����ҵ��ַ���str1 �Ѿ��Աȵ����һ���ַ��� ����û���ҵ� �Ӵ���
//				 // �� �����ҵ��ַ���str1 ��û�� ���ҵ��ַ���str2 ���Ӵ���
//				 // ���Է��� NULL��ָ�� ��
//
//}
//
//int main()
//{
//	const char* str1 = "abbbcdef";
//	const char* str2 = "bbc";
//
//	char* ret = my_strstr(str1, str2);
//
//	if (ret == NULL)
//	{
//		printf("�Ҳ���\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	//��ӡ bbcdef
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	const char* p1 = "abcdefabcdef";
//	const char* p2 = "def";
//
//	char* ret = strstr(p1, p2);
//
//	printf("%s\n", ret); // ��ӡ defabcdef
//	// �ɴ˿ɼ���
//	// ���ص��� ���ҵ��ַ��� �� �����ҵ��ַ��� ��һ�γ��� �� ��ַ ��
//	// �� "abcdefabcdef" �� def abcdef �� ��ַ ��
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	const char* p1 = "abcdef"; // ��Ϊֻ�� �Ƚ� �ַ���������Ҫ �޸� �ַ�����
//	const char* p2 = "abcghi"; // ��ʹ�� const �� �ַ��� �������������ⲻС���޸�
//
//	int ret1 = strncmp(p1, p2, 3);
//	// strncmp()�⺯�� ���������� �� ֵ Ϊ num ���� �Ƚ� ǰnum ���ַ���
//	printf("ret1 = %d\n", ret1); // ��ӡ ret1 = 0
//
//	int ret2 = strncmp(p1, p2, 4);
//	printf("ret2 = %d\n", ret2); // ��ӡ ret2 = -1
//
//	int ret3 = strncmp(p1, p2, 15);
//	// �� strncmp()�⺯�� ���������� �� ֵ �ܴ󣬱� �ַ��� ������
//	// �͵��� û�ж� �Ƚ��ļ����ַ� �������ƣ��൱�� ֱ��ʹ�� strcmp()�⺯�� ���бȽϡ�
//	printf("ret3 = %d\n", ret3); // ��ӡ ret3 = -1
//
//	const char* p3 = "abcdef";
//
//	int ret4 = strncmp(p1, p3, 15);
//	printf("ret4 = %d\n", ret4); // ��ӡ ret4 = 0
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	char arr1[15] = "#\0##########";
//	char arr2[] = "abc";
//
//	strncat(arr1, arr2, 6);
//
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	char arr1[10] = "########";
//	char arr2[] = "abc";
//
//	strncpy(arr1, arr2, 5);
//
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//
//	//�Ƚ�
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0') // �����������ַ��� ���
//			// whileѭ�� ʱ�Ѿ�ȷ�� *str1 == *str2 ��
//			// �����ж� *str1 == '\0' ���൱��Ҳ�ж��� *str2 == '\0' ��
//		{
//			return 0; 
//		}
//
//		str1++;
//		str2++;
//	}
//
//	if (*str1 > *str2)
//	{
//		return 1; //��һ���������ַ��� ���� �ڶ����������ַ���
//	}
//	else
//	{
//		return -1; //��һ���������ַ��� С�� �ڶ����������ַ���
//	}
//	// ����ģ�� VS������ �� ����ֵ��
//	// 
//	// ��ģ���������������� GCC������ ���ص��� ���ַ�ASCII��ֵ֮�
//	// ��ֱ��д�ɣ�
//	// return *str1 - *str2;
//
//
//}
//
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "def";
//
//	int ret = my_strcmp(p1, p2);
//
//	printf("ret = %d\n", ret);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* arr1 = "abc";
//	char* arr2 = "def";
//
//	if (strcmp(arr1, arr2) > 0)
//	{
//		printf("arr1 > arr2\n");
//	}
//	else if (strcmp(arr1, arr2) == 0)
//	{
//		printf("arr1 = arr2\n");
//	}
//	else if (strcmp(arr1, arr2) < 0)
//	{
//		printf("arr1 < arr2\n");
//	}
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	strcat();
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src); // NULL��ָ�� �൱�� 0 ���� 0 Ϊ�� ��
//	// �� dest �� src ����Ϊ NULL ��Ϊ �� ��
//	// ��һ���൱�� 
//	// assert(dest != NULL);
//	// assert(src != NULL);
//	// ����
//	// assert(dest);
//	// assert(src);
//
//	char* ret = dest;
//	// ��Ϊ dest ������ ��������� dest++ ���ı䣬
//	// ������뷵�� ԭ��dest �е� ��ַ��
//	// ������ ret ���� ������ٷ��� ret ����ĵ�ַ ���ɡ�
//
//	//1���ҵ� Ŀ���ַ��� �� '\0'
//	while (*dest != '\0')
//	{
//		dest++; // ʹ dest ָ�� '\0' ��λ��
//	}
//
//
//	//2��׷���ַ���
//	// �൱�ڿ����� ׷�ӵ��ַ��� ������ Ŀ�꺯������(��Ϊ���� dest ָ�� '\0' ��λ��)
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return dest;
//
//}
//
//int main()
//{
//	char arr1[15] = "hello";
//	char arr2[] = "world";
//
//	my_strcat(arr1, arr2);
//
//	printf("%s\n", arr1);
//	//��ӡ helloworld
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[15] = "hello\0xxxxxxxx";
//	// strcat()�⺯�� ԭ��
//	// ���ҵ� Ŀ���ַ��� �� '\0' ,
//	// Ȼ��� ׷���ַ��� �� ��һ���ַ� �滻�� Ŀ���ַ��� �� '\0' ��
//	// ������� ������� �� ׷���ַ��� �� ÿ���ַ� ׷�ӵ� Ŀ���ַ��� �� '\0' ֮����ַ���
//	// ֱ�� ׷�ӵ� ׷���ַ��� �� '\0' ,
//	// �� ׷���ַ��� �� '\0' ׷�ӵ� Ŀ���ַ��� ֮�� ��ֹͣ��
//
//	char arr2[] = "world";
//
//	strcat(arr1, arr2);
//
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//// ��֮ǰ��ͬ���ǣ�
//// �������ﷵ�������� char* ��
//// strcpy()�⺯�� �� �������� Ҳ�� char* ��Ŀ���Ƿ��� ����Ŀ�ĵ� �� ��ַ��
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	char* ret = dest;
//	// ��Ϊ dest ������ ��������� dest++ ���ı䣬
//	// ������뷵�� ԭ��dest �е� ��ַ��
//	// ������ ret ���� ������ٷ��� ret ����ĵ�ַ ���ɡ�
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//
//}
//	
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "hello";
//
//	my_strcpy(arr1, arr2);
//	// ��Ȼ my_strcpy() ������һ�� char*���� �� ֵ ��
//	// ���ǿ��� ���ö��� ���� ���ֵ��
//	// �ͺñ�
//	// 3;
//	// ���﷨��Ҳ��֧�ֵġ�
//	// 
//	// ������
//	// my_strcpy(arr1, arr2);
//	// �ں����иı��� arr1 �����ݣ�
//	// ������������ arr1���ַ��ĵ�ַ û�䣬 
//	// printf("%s\n", arr1);
//	// ��ӡ �ı�� arr1 �����ݣ��� hello ��
//	// 
//	// my_strcpy() ������һ�� char*���� �� ֵ ������ ���������� �����ַ�ָ�� ��
//	// ��
//	// char* arr3 = my_strcpy(arr1, arr2);
//	// printf("%s\n", arr3);
//	// �����ܴ�ӡ hello ��
//
//	printf("%s\n", arr1); //��ӡ hello
//
//	return 0;
//}


//#include <string.h>
//int main()
//{
//	char arr1[] = {"abcdefg"};
//	char arr2[] = {"hello"};
//
//	strcpy(arr1, arr2);
//	// strcpy()�⺯�� �������� �ַ������� ��
//	// ��������������һ���� ����Ŀ�ĵ� �� ��ַ��
//	//             �ڶ����� ������������ �� ��ַ��
//	// �����ǽ� arr2 �����ݿ����� arr1 ��ȥ��
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//
//	int count = 0;
//
//	while (*str) 
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//
//}
//
//int main()
//{
//
//	if (my_strlen("abc") - my_strlen("abcdef") > 0)
//	{
//		printf("haha\n");
//	}
//	else
//	{
//		printf("gaga\n");
//	}
//	// ��ӡ gaga
//
//	return 0;
//}


//#include <stdio.h>
//size_t // ������ <stdio.h>ͷ�ļ�
//
//// ��32Ϊƽ̨Ϊ����
//// 00000000 00000000 00000000 00000011   -> 3�Ĳ���(����������ͬ)
//// 00000000 00000000 00000000 00000110   -> 6�Ĳ���(����������ͬ)
//// 
//// �����ʹ�ò���������㣺6 - 3 = -3
//// 11111111 11111111 11111111 11111101   -> -3�Ĳ���
//// 
//// ��Ϊ strlen()�⺯�� ���ص��� unsighed int ������
//// 11111111 11111111 11111111 11111101 ���λ ������ ����λ �� ���� ��Чλ ��
//// ����һ�� ����0 �ҷǳ������ ��


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("haha\n");
//	}
//	else
//	{
//		printf("gaga\n");
//	}
//	// ��ӡ haha
//	
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str) 
//{
//	assert(str != NULL); 
//
//	int count = 0; 
//
//	while (*str) // while (*str != '\0') ���Ըĳ� while (*str) ��
//		         // ��Ϊ '\0' �������� ʹ�õ��� ASCII��ֵ ���� 0 ��
//				 // *str != '\0 �� *str != 0 ���� while()ѭ�� ��0Ϊ�� �����ѭ���� 0Ϊ�� �򲻽���ѭ����
//				 // *str �պ����� while()ѭ�� ���ж�������
//				 // ���Կ���д�� while(*str) ��
//	{
//		count++; 
//		str++; 
//	}
//
//	return count; 
//
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//
//	printf("%d\n", len); //��ӡ 6
//
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str) // ���������� �ַ���"abcdef" �� ���ַ� �� ��ַ�������� char*�ַ�ָ�� ����
//                               // char* str �� const ���� ������ ������
//{
//	assert(str != NULL); // assert()�⺯�� �� ���� ����Ҫ���� <assert.h>ͷ�ļ�
//	                     // assert() ������ ���ʽ Ϊ�� �����·����� Ϊ�� �򱨴�
//
//	int count = 0; // �����������������ַ����� '\0' ֮ǰ�ж��ٸ��ַ�
//
//	while (*str != '\0') // ���� ����Ҫ�޸� strָ�� ָ���ַ� �� ���ݣ�
//		                 // ע�� ���� ָ���ַ��� �� ���� �� str �� �ַ������ַ��ĵ�ַ �� *str ֻ�ܷ��� һ���ַ���
//		                 // �� char* str ������ ������ ���Ͳ��ܱ��޸ģ�
//		                 // ������Ч��ֹ strָ�� ָ���ַ� �� ���� ���޸ġ�
//	{
//		count++; // ���ַ����� '\0' �����������һ��
//		str++; // ָ��ָ����һ���ַ�
//	}
//	
//	return count; // while()ѭ�� ������˵�� �����ַ����� ���������� ��������ֵ
//
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//
//	printf("%d\n", len); //��ӡ 6
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	// strlen()�⺯�� �����ַ����� '\0' ֮ǰ�ж��ٸ��ַ������� '\0' ���������ڡ�
//
//	char arr2[] = { 'a','b','c','d','e','f' }; // �ڴ��д��� 'a','b','c','d','e','f'
//	
//	char arr3[] = { "abc def" }; // �ڴ��д��� 'a','b','c',' ','d','e','f'
//
//	int len1 = strlen("abcdef"); // �ڴ��д��� 'a','b','c','d','e','f','\0'
//	printf("len1 = %d\n", len1); // ��� len1 = 6
//	// �ַ��� '\0' ֮ǰ�� 6 ���ַ�
//
//	int len2 = strlen(arr2);
//	printf("len2 = %d\n", len2); // ��� len1 = 33(���ֵ)
//	// �ַ���û�� '\0' ���� strlen()�⺯�� ��Խ����ʣ�ֱ���ҵ� '\0' Ϊֹ����ʲôʱ���ҵ� '\0' ��δ֪�ģ����� ������ֵ��
//
//	int len3 = strlen(arr3);
//	printf("len3 = %d\n", len3); // ��� len1 = 7
//	// �ַ��� '\0' ֮ǰ�� 6 ���ַ� ��
//	// �ɼ� strlen()�⺯�� ��� ' '�ո� ��Ϊһ���ַ����������ҵ� ' '�ո� ��ֹͣ���㣬 strlen()�⺯�� ֻ������ '\0' ��ֹͣ���㡣
//
//	return 0;
//}



//#include <stdio.h>
//int my_strlen(char* arr)
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(arr + 1);
//	}
//}
//
//int main()
//{
//	int len = my_strlen("a b c d e f");
//
//	printf("%d\n", len);
//
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>
//int my_strlen(char* arr)
//{
//	int count = 0;
//
//	while (*arr)
//	{
//		count++;
//		arr++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	int len = my_strlen("a b c d e f");
//
//	printf("%d\n", len);
//
//	return 0;
//}