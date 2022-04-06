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
//	//	// fgetc库函数 遇到 读取失败 或者 文件结束 都会返回 EOF
//	//	// 
//	//	// 读取一个字符并打印，直到读取到 EOF 为止
//	//{
//	//	putchar(c);
//	//}
// //   // 此时 读取文件结束
//
//	printf("\n");
//
//	// 若判断 是什么原因结束，则
//	if (ferror(pf))
//		// ferror库函数 用于 查找一个流中是否存在错误，
//		// 存在错误 返回 非0值 ；
//		// 没有错误 返回 0 。
//	{
//		puts("stream error"); // 说明 流 存在错误 
//	}
//	else if (feof(pf))
//		// feof库函数 用于 当文件结束时，判断是 读取失败 结束，还是 遇到文件尾(EOF) 结束，
//		// 遇到文件尾(EOF) 结束 返回 非0值；
//		// 读取失败结束 返回 0。
//	{
//		puts("End of file reached successfully"); // 遇到文件尾(EOF) 结束
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
//	printf("%d\n", ch); // 打印 97 ，即 字符'a' 的 ASCII码值
//
//	ch = fgetc(pf);
//	printf("%d\n", ch); // 打印 -1 ，即 EOF文件结束标志 的值
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
//	// 读取一个字符后，文件指针 自动向后 跳动一个字符 的 长度
//
//	printf("%c\n", ch); // 打印 a
//
//	rewind(pf); // 让文件指针的位置回到文件的起始位置
//
//	ch = fgetc(pf);
//	// 读取一个字符后，文件指针 自动向后 跳动一个字符 的 长度
//
//	printf("%c\n", ch); // 打印 a
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
//	// 读取一个字符后，文件指针 自动向后 跳动一个字符 的 长度
//
//	long pos = ftell(pf);
//
//	printf("%d\n", pos); // 打印 1
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
//	printf("%d\n", pos); // 打印 4
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
//	// 先 定位文件指针
//	fseek(pf, 2, SEEK_SET);
//
//	// 再 读取文件
//	int ch = fgetc(pf);
//
//	printf("%c\n", ch); // 打印 c
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
//	// 先 定位文件指针
//	fseek(pf, 2, SEEK_CUR);
//
//	// 再 读取文件
//	int ch = fgetc(pf);
//
//	printf("%c\n", ch); // 打印 c
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
//	// "rb" 表示以 二进制读取 的方式打开
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// 从文件中以 二进制的形式 读取 数据
//	fread(&tmp, sizeof(struct S), 1, pf);
//	// 从 文件pf 中读取 1 个 sizeof(struct S) 大小的数据，存放到 tmp 中。
//
//	printf("%s %d %lf\n", tmp.name, tmp.age, tmp.score);
//	// double类型 用 %lf 打印
//	// 
//	// 打印 张三 20 99.900000
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
//	// "wb" 表示以 二进制写入 的方式打开
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// 以 二进制的形式 把数据 写入 到文件中
//	fwrite(&s, sizeof(struct S), 1, pf);
//	// 把 1 个大小为 sizeof(struct S) 的 数据s ，写入到 文件pf 中。
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
//	struct S s = { "张三",20,99.9 };
//
//	FILE* pf = fopen("test.txt", "wb");
//	// "wb" 表示以 二进制写入 的方式打开
//
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// 以 二进制的形式 把数据 写入 到文件中
//	fwrite(&s, sizeof(struct S), 1, pf);
//	// 把 1 个大小为 sizeof(struct S) 的 数据s ，写入到 文件pf 中。
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
//	char buf[1024] = { 0 }; // 标准化数据 写入 字符串 后，该字符串 保存的位置
//
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	// 把一个 标准化的数据 写入 字符串
//
//	printf("%s\n", buf);
//	// 打印100 3.140000 abcdef ，
//	// 是一个 字符串
//
//	struct S tmp = { 0 };
//
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	// 从 字符串buf 中 读取 标准化的数据内容，
//	// 存放到 结构体变量tmp 对应类型的 结构体成员 中。
//	//
//	// 变量 需要进行 &取地址 操作，而 数组名 本身就是 首元素地址
//
//	printf("%d %f %s", tmp.n, tmp.score, tmp.arr);
//	// 打印100 3.140000 abcdef ，
//	// 此时 不是一个 字符串，
//	// 而是 结构体变量tmp 中的 结构体成员 对应类型的数据
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
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr); // 从 标准输入流(即 键盘) 读取
//
//	fprintf(stdout, "%d %.2f %s", s.n, s.score, s.arr); // 输出到 标准输出流(即 屏幕)
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
//	// 其中 3.14 这个数，默认是 double类型 的 ，而 3.14f 指明是 float类型 的。
//
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// 格式化的形式 读取文件
//	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);
//	// 变量 需要进行 &取地址 操作，而 数组名 本身就是 首元素地址
//
//	fprintf(stdout, "%d %f %s", s.n, s.score, s.arr);
//	// 与 printf("%d %f %s", s.n, s.score, s.arr); 作用相同，
//	// 打印 100 3.140000 abcdef
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
//	// 其中 3.14 这个数，默认是 double类型 的 ，而 3.14f 指明是 float类型 的。
//
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//
//	// 格式化的形式 写入文件
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
//	gets(buf); // 从 标准输入流(即 键盘) 读取
//
//	puts(buf); // 输出到 标准输出流(即 屏幕)
//
//	// 键盘 输入什么，屏幕 输出什么
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, stdin); // 从 标准输入流(即 键盘) 读取
//
//	fputs(buf, stdout); // 输出到 标准输出流(即 屏幕)
//
//	// 键盘 输入什么，屏幕 输出什么
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
//	// 读取文件
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, pf);
//	puts(buf); // 将 printf("%s", buf); 改成该代码
//
//	fgets(buf, 1024, pf);
//	puts(buf); // 将 printf("%s", buf); 改成该代码
//
//	// 关闭文件
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
//	// 读取文件
//	char buf[1024] = { 0 };
//
//	fgets(buf, 1024, pf);
//	printf("%s", buf);
//	// 读完一行后 光标 会自动跳转到 下一行，直接读取就能读出下一行的内容
//	fgets(buf, 1024, pf);
//	printf("%s", buf);
//
//	// 关闭文件
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
//	// 写入文件
//	fputs("hello\n", pf);
//	fputs("world", pf);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int ch = fgetc(stdin);
//	// 从 标准输入设备(流) ，即 键盘 上 读取 数据
//
//	fputc(ch, stdout);
//	// 将 数据 写入 到 标准输出设备(流) ，即 屏幕 上。
//
//	// 键盘 输入 任意字符，屏幕 输出 该字符。
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
//	// 读取字符
//	printf("%c", fgetc(pfRead)); // 打印 'h'
//	printf("%c", fgetc(pfRead)); // 打印 'a'
//	printf("%c", fgetc(pfRead)); // 打印 'p'
//	printf("%c", fgetc(pfRead)); // 打印 'p'
//	printf("%c", fgetc(pfRead)); // 打印 'y'
//	// fgetc()库函数 每读取一个字符，读取光标 会 往后 跳动一个字符，以实现向后读取数据
//
//	// 关闭文件
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
//	// 写入字符
//	fputc('h', pfWrite);
//	fputc('a', pfWrite);
//	fputc('p', pfWrite);
//	fputc('p', pfWrite);
//	fputc('y', pfWrite);
//
//	// 关闭文件
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
//	// 打开文件
//	FILE* pf = fopen("test.txt", "w");
//	// 第二个参数 "w" 表示 以写的形式 打开文件。
//
//	if (pf == NULL) // 打开文件失败
//	{
//		printf("%s\n", strerror(errno)); // 打印错误信息
//	}
//	else // 打开文件成功
//	{
//		// 使用文件
//		// ......
//
//		// 关闭文件
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
//	// fopen()库函数 用来打开文件，
//	// 在 相对路径(即 该解决方案的保存路径)底下 打开一个 "test.txt" 文件，
//	// 
//	// 用 "wb" 的方式打开，其中 "w" 表示 写入 ， "b" 表示 二进制 ，
//	// 所以 "wb" 表示以 二进制写入 的方式打开。
//	// 
//	// 若 相对路径底下 没有这个文件，用 "wb" 的方式打开 会自动创建一个文件。
//
//	fwrite(&a, 4, 1, pf);// 二进制的形式写到文件中
//	// fwrite()库函数 用来 给文件 写入数据，
//	// 其中，
//	// 第一个参数 &a 表示 数据来源于 a ，
//	// 第二个参数 4 表示 开辟 4 个字节的空间，
//	// 第三个参数 1 表示 写入 1 个这样的数据，
//	// 第四个参数 pf 表示 把数据写入 pf指针 维护的文件处。
//
//	fclose(pf); // 关闭文件
//	// fclode()库函数 用于 关闭文件
//	
//	pf = NULL; // pf指针 维护的文件 被关闭后，该指针要 被置为 NULL空指针 ，以免造成非法访问
//
//	return 0;
//}
