#define _CRT_SECURE_NO_WARNINGS 1

//// �� X86(32λƽ̨) �������³���
//
//#include <stdio.h>
//int main()
//{
//	union S
//	{
//		short k;
//		char arr[2];
//	};
//
//	union S s;
//
//	union S* ps = &s;
//
//	ps->arr[0] = 0x39;
//	ps->arr[1] = 0x38;
//
//	printf("%x\n", s.k); // ��ӡ 3839
//
//	return 0;
//}


//#include <stdio.h>
//#include <memory.h>
//int main()
//{
//	char arr[4];
//
//	struct S
//	{
//		char c1;
//		char c2 : 1;
//		char c3 : 2;
//		char c4 : 3;
//	};
//
//	struct S* ps;
//
//	ps = (struct S*)arr;
//
//	memset(arr, 0, 4);
//
//	ps->c1 = 2;
//	ps->c2 = 3;
//	ps->c3 = 4;
//	ps->c4 = 5;
//
//	printf("%02x %02x %02x %02x\n", arr[0], arr[1], arr[2], arr[3]);
//	// %02x ������
//	// x ������ ʮ������ ��ʽ�����
//	// 02 ������ 2 ��λ�������������λ��ǰ�油 0 ��������������λ������ʵ�������
//	// 
//	// ���������02 29 00 00
//	// 
//	// 
//	// %2x ������
//	// x ������ ʮ������ ��ʽ�����
//	// 2 ������ 2 ��λ�������������λ��ǰ�治����ⲹ 0 �����������λ������ʵ�������
//	// 
//	// ��������� 2 29  0  0 (λ������ 2 ���������Ჹ 0 )
//
//	return 0;
//}


//
//#include <stdio.h>
//
//#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
//// �� 32λƽ̨ ǿ������ת���� int����(4���ֽ�) ����Ϊ 32λƽ̨ �� ��ַ �� 32 ������λ�� �� 4 ���ֽڣ�
//// �� 64λƽ̨ ǿ������ת���� long long����(8���ֽ�) ����Ϊ 64λƽ̨ �� ��ַ �� 64 ������λ�� �� 8 ���ֽڣ�
//// �� ǿ������ת���� �Ų��� ��ַ���� �� ���� ����ᱨ �ضϾ��� ��
////    ���ǲ�Ӱ�챾����⣬��Ϊ�����ƫ��ֵ��С���ضϲ���Ӱ�����ֵ��
//
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c)); // ��ӡ 0
//
//	printf("%d\n", OFFSETOF(struct S, i)); // ��ӡ 4
//	
//	printf("%d\n", OFFSETOF(struct S, d)); // ��ӡ 8
//
//	return 0;
//}



//#include <stdio.h>
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//#define OFSETOF(STRUCT_NAME,MAMBER) (short)&(((STRUCT_NAME*)0)->MAMBER)
//
//int main()
//{
//	printf("%d\n", OFSETOF(struct S, c2));
//
//	return 0;
//}

//int main()
//{
//
//#if defined(OS_UNIX)
//
//    #ifdef OPTION1
//	    // unix_version_option1();
//    #endif
//
//    #ifdef OPTION2
//	    // unix_version_option2();
//    #endif
//
//#elif defined(OS_MSDOS)
//
//    #ifdef OPTION2
//	    // msdos_version_option2();
//    #endif
//
//#endif
//
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 0 };
//
//	int __DEBUG__ = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#ifdef __DEBUG__
//		printf("%d ", arr[i]); // Ϊ�˹۲������Ƿ�ֵ�ɹ�����Ҫ�۲�ű��룬����Ҫ�򲻱��롣
//#endif
//		// ������� __DEBUG__ ����룬���򲻱���
//
//	}
//	return 0;
//}
//
//#define __DEBUG__

//#include <stdio.h>
//
////#define __DEBUG__
//
//int main()
//{
//#if !defined(__DEBUG__)
//	printf("hehe\n");
//#endif 
//
//#ifndef __DEBUG__
//	printf("hehe\n");
//#endif
//
//	return 0;
//}


//#include <stdio.h>
//
//#define __DEBUG__
//
//int main()
//{
//#if defined(__DEBUG__)
//	printf("hehe\n");
//#endif 
//
//#ifdef __DEBUG__
//	printf("hehe\n");
//#endif
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//
//#if 1==2
//	printf("123\n");
//
//#elif 1==3
//	printf("456\n");
//
//#else
//	printf("789\n");
//
//#endif
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 0 };
//
//	int __DEBUG__ = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#if 1-1
//		printf("%d ", arr[i]);
//#endif
//
//	}
//	return 0;
//}

//#include <stdio.h>
//
////#define __DEBUG__
//
//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 0 };
//
//	int __DEBUG__ = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#ifdef __DEBUG__
//		printf("%d ", arr[i]); // Ϊ�˹۲������Ƿ�ֵ�ɹ�����Ҫ�۲�ű��룬����Ҫ�򲻱��롣
//#endif
//		// ������� __DEBUG__ ����룬���򲻱���
//
//	}
//	return 0;
//}



//// �� Linuxϵͳ �� gcc������ ������
//
//#include <stdio.h>
//int main()
//{
//	int arr[SZ] = { 0 };
//
//	int i = 0;
//
//	for (i = 0; i < SZ; i++)
//	{
//		arr[i] = i;
//	}
//
//	for (i = 0; i < SZ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//#define MAX 100
//
//int main()
//{
//	printf("%d\n", MAX);
//
//#undef MAX
//
//	printf("%d\n", MAX);
//
//	return 0;
//}

//#include <malloc.h>
//
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//// ʹ�� �� ��ʹ�ô��������⣬��
//// ���� (num) �� (type)���� �Ķ�̬�ڴ�ռ�
//
//int main()
//{
//	int* p = MALLOC(10, int);
//	// �൱�� int* p = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}

//#include <stdio.h>
//
//#define SIZEOF(type) sizeof(type)
//
//int main()
//{
//	int size = SIZEOF(int);
//	printf("%d\n", size);
//
//	return 0;
//}


//#include <stdio.h>
//
//// ��
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//// ����
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	float a = 5.1f;
//	float b = 10.2f;
//
//	// ��
//	float max1 = MAX(a, b);
//	printf("%lf\n", max1);
//
//	// ���� 
//	float max2 = Max(a, b);
//	printf("%lf\n", max2);
//
//	return 0;
//}



//#include <stdio.h>
//
//// ��
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//// ����
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int a = 5;
//	int b = 10;
//
//	// ��
//	int max1 = MAX(a, b);
//	printf("%d\n", max1);
//
//	// ����
//	int max2 = Max(a, b);
//	printf("%d\n", max2);
//
//	return 0;
//}


//#include <stdio.h>
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int  a = 5;
//	int b = 10;
//
//	int max = Max(a++, b++);
//
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	printf("max = %d\n", max);
//
//	return 0;
//}


//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//int main()
//{
//	int a = 5;
//	int b = 10;
//
//	int max = MAX(a++, b++);
//
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	printf("max = %d\n", max);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 0;
//
//	b = a + 1;
//	printf("a = %d ; b = %d\n", a, b);
//
//	b = ++a;
//	printf("a = %d ; b = %d\n", a, b);
//
//	return 0;
//}



//#include <stdio.h>
//int MAX(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 11;
//
//	int Max = MAX(a++, b++);
//
//	printf("%d\n", Max);
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//	return 0;
//}


//#include <stdio.h>
//
//#define CAT(X,Y) X##Y
//
//int main()
//{
//	int room10 = 2022;
//
//	printf("%d\n", CAT(room, 10));
//	// ��Ԥ����ʱ���ᱻ�滻��
//	// printf("%d\n", room##10 );
//	// 
//	// ���� �� �У� ## ���԰�λ�������ߵķ��źϳ�һ�����ţ�
//	// �����
//	// printf("%d\n", room10 );
//	// 
//	// ���Դ�ӡ 2022
//
//	return 0;
//}

//#include <stdio.h>
//
//#define PRINT(X) printf("the value of "#X" is %d\n",X)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	PRINT(a);
//
//	PRINT(b);
//
//	return 0;
//}

//#include <stdio.h>
//void PRINT(int x, char c)
//{
//	printf("the value of %c is %d\n", c, x);
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	PRINT(a, 'a');
//
//	PRINT(b, 'b');
//
//	return 0;
//}



//#include <stdio.h>
//void PRINT(int x)
//{
//	printf("the value of a is %d\n", x);
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	PRINT(a);
//
//	PRINT(b);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("hello world\n");
//
//	printf("hello ""world\n");
//
//	printf("he""llo ""wo""rld\n");
//
//	char* hw = "hello ""world";
//
//	printf("%s\n", hw);
//
//	return 0;
//}

//#define DOUBLE(X) ((X)+(X))
//
//#include <stdio.h>
//int main()
//{
//	int a = 5;
//
//	int ret = 10 * DOUBLE(a);
//
//	printf("%d\n", ret);
//
//	return 0;
//}


//#define DOUBLE(X) X+X
//
//#include <stdio.h>
//int main()
//{
//	int a = 5;
//
//	int ret = 10 * DOUBLE(a);
//
//	printf("%d\n", ret);
//
//	return 0;
//}



//#define SQUARE(X) (X)*(X)
//
//#include <stdio.h>
//int main()
//{
//	int ret = SQUARE(5 + 1);
//
//	printf("%d\n", ret);
//
//	return 0;
//}




//#define SQUARE(X) X*X
//
//#include <stdio.h>
//int main()
//{
//	int ret = SQUARE((5 + 1));
//
//	printf("%d\n", ret);
//
//	return 0;
//}



//#define SQUARE(X) X*X
//
//#include <stdio.h>
//int main()
//{
//	int ret = SQUARE(5 + 1);
//
//	printf("%d\n", ret);
//
//	return 0;
//}




//#define MAX 100;
//
//#include <stdio.h>
//int main()
//{
//	int max = MAX;
//	// ��δ������� û�����⣬
//	// ��ֵ��ע����ǣ�
//	// ��δ����൱�� int max = 100;;
//	// �� int max = 100;
//	//    ;
//	// �������
//
//	printf("%d\n", MAX);
//	// ��δ��� �����⣬�޷����룬
//	// ���� ���� �﷨��ʽ ���ǿ���������ģ�
//	// ��Ϊ���滻֮��������⣬�� printf("%d\n",100;); �� ǰһ�� ;�ֺ� ����
//
//	return 0;
//}

//// �������� stuff ���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
//#define DEBUG_PRINT printf("file:%s\tline:%d\t\
//date:%s\ttime:%s\n" ,\
//__FILE__,__LINE__ ,\
//__DATE__,__TIME__ )  
//
//#include <stdio.h>
//int main()
//{
//    DEBUG_PRINT;
//    // ��ӡ file:D:\virtual studio\C_Language_learn\Ԥ����\test.c   line:14 date:Apr  8 2022        time:20:44:47
//
//
//    return 0;
//}

//#define CASE break;case  //��д case��� ��ʱ���Զ��� break д�ϡ�
//
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//
//	switch (input)
//	{
//	case 1:
//		break;
//
//	case 2:
//		break;
//
//		// ����д���������Ǽ��� break;
//		// ��ʹ�� #define ����� CASE ����Ա�����������
//
//		CASE 3:
//		// �൱��
//		//     break;
//		// case 3:
//
//		CASE 4:
//		// �൱��
//    	//     break;
//	    // case 4:
//
//		CASE 5:
//		// �൱��
//		//     break;
//		// case 5:
//		break; // ���� ������ break; ����Ҫ�Լ�д��
//
//	}
//}




//#define  do_forever for(;;)    // ���Ŷ�Ӧ���� �� ����
//
//#include <stdio.h>
//int main()
//{
//	do_forever
//
//	return 0;
//	
//	// û�� ;�ֺ� �� ������ѭ����
//	// ��δ��� �൱��
//	// for(;;)
//	// {
//	//     return 0;
//	// }
//	// 
//	// ��Ϊȱ�� ;�ֺ� ����������Ӧ�ð� return 0; ��ϵ������
//}

//#define UNI unsigned           // ���Ŷ�Ӧ���� �� �ؼ���
//#define  do_forever for(;;)    // ���Ŷ�Ӧ���� �� ����
//
//#include <stdio.h>
//int main()
//{
//	UNI int i = 10;
//	// �൱�� unsigned int i = 10;
//
//	do_forever;
//	// �൱�� 
//	// for(;;)
//	// {
//	//     ;
//	// }
//	// ��δ����� ��ѭ�� �� ʲôҲû��
//
//	return 0;
//}


//#define MAX 100       // ���Ŷ�Ӧ���� �� ����
//#define STR "hehe"    // ���Ŷ�Ӧ���� �� �ַ���
//
//#include <stdio.h>
//int main()
//{
//	printf("%d\n", MAX); // ��ӡ 100
//
//	printf("%s\n", STR); // ��ӡ hehe
//
//	return 0;
//}


//#include <stdio.h>
//
//#define MAX 100 // �����Լ�ʹ�� #define ����ķ��ţ����� Ԥ�������
//
//int main()
//{
//	// Ԥ�������
//
//	printf("%s\n", __FILE__);
//	// ��ӡ D:\virtual studio\C_Language_learn\Ԥ����\test.c
//	//
//	// �� ��δ������� Դ�ļ� ����� ����·�� ��ʹ�� %s ��ӡ
//
//	printf("%d\n", __LINE__); 
//	// ��ӡ 15
//	//
//	// �� ��δ��� ����һ�� ��ʹ�� %d ��ӡ
//
//	printf("%s\n", __DATE__);
//	// ��ӡ Apr  8 2022
//	//
//	// �� ��δ��� ����ʱ������ ��ʹ�� %s ��ӡ
//
//	printf("%s\n", __TIME__);
//	// ��ӡ 18:27:16
//	//
//	// �� ��δ��� ����ʱ��ʱ�� ��ʹ�� %s ��ӡ
//
//	printf("%s\n", __FUNCTION__);
//	// ��ӡ main
//	//
//	// �� ��δ��� ����ʱ���ں����� ������ ��ʹ�� %s ��ӡ
//
//	return 0;
//}


//extern ADD(int x, int y); // extern ���� �����ⲿ����
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	int a = 10;
//	int b = 20;
//
//	int c = ADD(a, b);
//
//	printf("%d\n", c);
//
//	return 0;
//}