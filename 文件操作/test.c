#define _CRT_SECURE_NO_WARNINGS 1






//#include <stdio.h>
//#include <stdlib.h>
//int main(void)
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (!pf) 
//	{
//		perror("File opening failed");
//		return EXIT_FAILURE;
//	}
//
//	//int c = 0;
//	//while ((c = fgetc(pf)) != EOF)
//	//	// fgetc�⺯�� ���� ��ȡʧ�� ���� �ļ����� ���᷵�� EOF
//	//	// 
//	//	// ��ȡһ���ַ�����ӡ��ֱ����ȡ�� EOF Ϊֹ
//	//{
//	//	putchar(c);
//	//}
// //   // ��ʱ ��ȡ�ļ�����
//
//	printf("\n");
//
//	// ���ж� ��ʲôԭ���������
//	if (ferror(pf))
//		// ferror�⺯�� ���� ����һ�������Ƿ���ڴ���
//		// ���ڴ��� ���� ��0ֵ ��
//		// û�д��� ���� 0 ��
//	{
//		puts("stream error"); // ˵�� �� ���ڴ��� 
//	}
//	else if (feof(pf))
//		// feof�⺯�� ���� ���ļ�����ʱ���ж��� ��ȡʧ�� ���������� �����ļ�β(EOF) ������
//		// �����ļ�β(EOF) ���� ���� ��0ֵ��
//		// ��ȡʧ�ܽ��� ���� 0��
//	{
//		puts("End of file reached successfully"); // �����ļ�β(EOF) ����
//	}
//	else
//	{
//		printf("test\n");
//	}
//
//	fclose(pf);
//	pf = NULL;
//}



//#include <stdlib.h>
//int main()
//{
//	EXIT_FAILURE;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");
//
//	if (pf == NULL)
//	{
//		perror("hehe");
//
//		printf("hehe: %s\n", strerror(errno));
//
//		return 0;
//	}
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	int ch = fgetc(pf);
//	printf("%d\n", ch); // ��ӡ 97 ���� �ַ�'a' �� ASCII��ֵ
//
//	ch = fgetc(pf);
//	printf("%d\n", ch); // ��ӡ -1 ���� EOF�ļ�������־ ��ֵ
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	int ch = fgetc(pf);
//	// ��ȡһ���ַ����ļ�ָ�� �Զ���� ����һ���ַ� �� ����
//
//	printf("%c\n", ch); // ��ӡ a
//
//	rewind(pf); // ���ļ�ָ���λ�ûص��ļ�����ʼλ��
//
//	ch = fgetc(pf);
//	// ��ȡһ���ַ����ļ�ָ�� �Զ���� ����һ���ַ� �� ����
//
//	printf("%c\n", ch); // ��ӡ a
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	int ch = fgetc(pf);
//	// ��ȡһ���ַ����ļ�ָ�� �Զ���� ����һ���ַ� �� ����
//
//	long pos = ftell(pf);
//
//	printf("%d\n", pos); // ��ӡ 1
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	fseek(pf, -2, SEEK_END);
//
//	long pos = ftell(pf);
//
//	printf("%d\n", pos); // ��ӡ 4
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// �� ��λ�ļ�ָ��
//	fseek(pf, 2, SEEK_SET);
//
//	// �� ��ȡ�ļ�
//	int ch = fgetc(pf);
//
//	printf("%c\n", ch); // ��ӡ c
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// �� ��λ�ļ�ָ��
//	fseek(pf, 2, SEEK_CUR);
//
//	// �� ��ȡ�ļ�
//	int ch = fgetc(pf);
//
//	printf("%c\n", ch); // ��ӡ c
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//#include <stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S tmp = { 0 };
//
//	FILE* pf = fopen("test.txt", "rb");
//	// "rb" ��ʾ�� �����ƶ�ȡ �ķ�ʽ��
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// ���ļ����� �����Ƶ���ʽ ��ȡ ����
//	fread(&tmp, sizeof(struct S), 1, pf);
//	// �� �ļ�pf �ж�ȡ 1 �� sizeof(struct S) ��С�����ݣ���ŵ� tmp �С�
//
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//	// double���� �� %lf ��ӡ
//	// 
//	// ��ӡ ���� 20 99.900000
//	
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S tmp = { 0 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	// "wb" ��ʾ�� ������д�� �ķ�ʽ��
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// �� �����Ƶ���ʽ ������ д�� ���ļ���
//	fwrite(&s, sizeof(struct S), 1, pf);
//	// �� 1 ����СΪ sizeof(struct S) �� ����s ��д�뵽 �ļ�pf �С�
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//#include <stdio.h>
//struct S
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	struct S s = { "����",20,99.9 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	// "wb" ��ʾ�� ������д�� �ķ�ʽ��
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// �� �����Ƶ���ʽ ������ д�� ���ļ���
//	fwrite(&s, sizeof(struct S), 1, pf);
//	// �� 1 ����СΪ sizeof(struct S) �� ����s ��д�뵽 �ļ�pf �С�
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//#pragma pack(1)
//struct S
//{
//	int i;// 2 , 0-1
//
//	char c;// 1 , 2
//
//};
//#pragma pack()
//
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	return 0;
//}



//#include <stdio.h>
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };
//
//	char buf[1024] = { 0 }; // ��׼������ д�� �ַ��� �󣬸��ַ��� �����λ��
//
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	// ��һ�� ��׼�������� д�� �ַ���
//
//	printf("%s\n", buf);
//	// ��ӡ100 3.140000 abcdef ��
//	// ��һ�� �ַ���
//
//	struct S tmp = { 0 };
//
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	// �� �ַ���buf �� ��ȡ ��׼�����������ݣ�
//	// ��ŵ� �ṹ�����tmp ��Ӧ���͵� �ṹ���Ա �С�
//	//
//	// ���� ��Ҫ���� &ȡ��ַ �������� ������ ������� ��Ԫ�ص�ַ
//
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	// ��ӡ100 3.140000 abcdef ��
//	// ��ʱ ����һ�� �ַ�����
//	// ���� �ṹ�����tmp �е� �ṹ���Ա ��Ӧ���͵�����
//
//	return 0;
//}


//#include <stdio.h>
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 0 };
//
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr); // �� ��׼������(�� ����) ��ȡ
//
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr); // ����� ��׼�����(�� ��Ļ)
//
//	return 0;
//}


//#include <stdio.h>
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };
//	// ���� 3.14 �������Ĭ���� double���� �� ���� 3.14f ָ���� float���� �ġ�
//
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// ��ʽ������ʽ ��ȡ�ļ�
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//	// ���� ��Ҫ���� &ȡ��ַ �������� ������ ������� ��Ԫ�ص�ַ
//
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//	// �� printf("%d %f %s", s.n, s.score, s.arr); ������ͬ��
//	// ��ӡ 100 3.140000 abcdef
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14f,"abcdef" };
//	// ���� 3.14 �������Ĭ���� double���� �� ���� 3.14f ָ���� float���� �ġ�
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// ��ʽ������ʽ д���ļ�
//	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char buf[1024] = { 0 };
//
//	gets(buf); // �� ��׼������(�� ����) ��ȡ
//
//	puts(buf); // ����� ��׼�����(�� ��Ļ)
//
//	// ���� ����ʲô����Ļ ���ʲô
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, stdin); // �� ��׼������(�� ����) ��ȡ
//
//	fputs(buf, stdout); // ����� ��׼�����(�� ��Ļ)
//
//	// ���� ����ʲô����Ļ ���ʲô
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	char buf[1024] = { 0 };
//	gets(buf);
//	puts(buf);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// ��ȡ�ļ�
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, pf);
//	puts(buf); // �� printf("%s", buf); �ĳɸô���
//
//	fgets(buf, 1024, pf);
//	puts(buf); // �� printf("%s", buf); �ĳɸô���
//
//	// �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// ��ȡ�ļ�
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, pf);
//	printf("%s", buf);
//	// ����һ�к� ��� ���Զ���ת�� ��һ�У�ֱ�Ӷ�ȡ���ܶ�����һ�е�����
//	fgets(buf, 1024, pf);
//	printf("%s", buf);
//
//	// �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// д���ļ�
//	fputs("hello\n", pf);
//	fputs("world", pf);
//
//	// �ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int ch = fgetc(stdin);
//	// �� ��׼�����豸(��) ���� ���� �� ��ȡ ����
//
//	fputc(ch, stdout);
//	// �� ���� д�� �� ��׼����豸(��) ���� ��Ļ �ϡ�
//
//	// ���� ���� �����ַ�����Ļ ��� ���ַ���
//
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pfRead = fopen("test.txt", "r");
//
//	if (pfRead == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	// ��ȡ�ַ�
//	printf("%c", fgetc(pfRead)); // ��ӡ 'h'
//	printf("%c", fgetc(pfRead)); // ��ӡ 'a'
//	printf("%c", fgetc(pfRead)); // ��ӡ 'p'
//	printf("%c", fgetc(pfRead)); // ��ӡ 'p'
//	printf("%c", fgetc(pfRead)); // ��ӡ 'y'
//	// fgetc()�⺯�� ÿ��ȡһ���ַ�����ȡ��� �� ���� ����һ���ַ�����ʵ������ȡ����
//
//	// �ر��ļ�
//	fclose(pfRead);
//	pfRead = NULL;
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	FILE* pfWrite = fopen("test.txt", "w");
//
//	if (pfWrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//
//	// д���ַ�
//	fputc('h', pfWrite);
//	fputc('a', pfWrite);
//	fputc('p', pfWrite);
//	fputc('p', pfWrite);
//	fputc('y', pfWrite);
//
//	// �ر��ļ�
//	fclose(pfWrite);
//	pfWrite = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//int main()
//{
//	// ���ļ�
//	FILE* pf = fopen("test.txt", "w");
//	// �ڶ������� "w" ��ʾ ��д����ʽ ���ļ���
//
//	if (pf == NULL) // ���ļ�ʧ��
//	{
//		printf("%s\n", strerror(errno)); // ��ӡ������Ϣ
//	}
//	else // ���ļ��ɹ�
//	{
//		// ʹ���ļ�
//		// ......
//
//		// �ر��ļ�
//		fclose(pf);
//		pf = NULL;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//FILE


//#include <stdio.h>
//int main()
//{
//	int a = 10000;
//
//	FILE* pf = fopen("test.txt", "wb");
//	// fopen()�⺯�� �������ļ���
//	// �� ���·��(�� �ý�������ı���·��)���� ��һ�� "test.txt" �ļ���
//	// 
//	// �� "wb" �ķ�ʽ�򿪣����� "w" ��ʾ д�� �� "b" ��ʾ ������ ��
//	// ���� "wb" ��ʾ�� ������д�� �ķ�ʽ�򿪡�
//	// 
//	// �� ���·������ û������ļ����� "wb" �ķ�ʽ�� ���Զ�����һ���ļ���
//
//	fwrite(&a, 4, 1, pf);// �����Ƶ���ʽд���ļ���
//	// fwrite()�⺯�� ���� ���ļ� д�����ݣ�
//	// ���У�
//	// ��һ������ &a ��ʾ ������Դ�� a ��
//	// �ڶ������� 4 ��ʾ ���� 4 ���ֽڵĿռ䣬
//	// ���������� 1 ��ʾ д�� 1 �����������ݣ�
//	// ���ĸ����� pf ��ʾ ������д�� pfָ�� ά�����ļ�����
//
//	fclose(pf); // �ر��ļ�
//	// fclode()�⺯�� ���� �ر��ļ�
//	
//	pf = NULL; // pfָ�� ά�����ļ� ���رպ󣬸�ָ��Ҫ ����Ϊ NULL��ָ�� ��������ɷǷ�����
//
//	return 0;
//}
