#define _CRT_SECURE_NO_WARNINGS

//*********************************
//*************讲解六**************
//*********************************

//杨氏矩阵
#include <stdio.h>
int FindNum(int arr[3][3], int k, int* px, int* py) // FindNum() 有 4 个参数，
													//     第一个是 杨氏矩阵的二维数组
													//     第二个是 寻找的数
													//     第三个是 二维数组 行数x 的 地址
													//     第四个是 二维数组 列数y 的 地址
													// 并返回一个 int类型，
													//     返回 1 为 找到了 需要寻找的数
													//     返回 0 为 找不到 需要寻找的数
{
	//使用 二维数组 右上角的数字 对比
	int x = 0; // 右上角数字 的 行 下标
	// 这个 x 是 函数里的x ，不是 主函数的x
	int y = *py - 1; // 右上角数字 的 列 下标
	// 这个 y 是 函数里的y ，不是 主函数的y

	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			// 找到了 就把 函数里的x 和 函数里的y ，
			// 通过 主函数的x 和 主函数的y 的 地址 ，
			// 传到 主函数的x 和 主函数的y 中去。
			*px = x;
			*py = y;

			return 1;
		}
	}

	return 0;

}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };

	int k = 7;

	int x = 3; // 二维数组 的 行数
	int y = 3; // 二维数组 的 列数

	int ret = FindNum(arr, k, &x, &y); // 这种 传地址的函数 叫 返回型函数
	// 这里 第三个 和 第四个 参数 ，分别传 x的地址 和 y的地址
	// FindNum()函数 中，可以通过地址改变 x 和 y 的值，
	// 当离开 FindNum()函数 后， x 和 y 的 值 仍是 改变后的值 。

	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是：%d %d\n", x, y);
	}
	else
	{
		printf("找不到\n");
	}

	return 0;
}

////杨氏矩阵
//// 杨氏矩阵：有一个二维数组，数组的每行从左到右是递增的，每列从上到下是递增的。
//// 如 1 2 3
////    4 5 6
////    7 8 9
//// 
//// 问题：在这样的数组中查找一个数字是否存在？
//// 要求：时间复杂度小于O(N)， O(N) 的意思是 不能使用穷举的方法，即不能遍历每一种可能。
//// 
//// 
//// 原理：
//// 如 1 2 3
////    4 5 6
////    7 8 9
//// 我们要找 数字K
//// 
//// 其中 右上角 和 左下角 的 数字 都很特殊，
//// 对于 右上角数字：
//// 若 右上角数字 > K ，则说明 K 不在 最左边那一 列 ，
//// 若 右上角数字 < K ，则说明 K 不在 最上边那一 行 。
//// 对于 左下角数字：
//// 若 左下角数字 > K ，则说明 K 不在 最下边那一 行 ，
//// 若 左下角数字 < K ，则说明 K 不在 最右边那一 列 。
//// 
//// 而  左上角 和 右下角 的 数字 没有什么特殊意义，
//// 
//// 我们可以通过 所找数字K 与对比 右上角 和 左下角 的 数字，每次排除 一行 或 一列。
////
//#include <stdio.h>
//int FindNum(int arr[3][3], int k, int row, int col) // FindNum() 有 4 个参数，
//													//     第一个是 杨氏矩阵的二维数组
//													//     第二个是 寻找的数
//													//     第三个是 二维数组 行数
//													//     第四个是 二维数组 列数
//													// 并返回一个 int类型，
//													//     返回 1 为 找到了 需要寻找的数
//													//     返回 0 为 找不到 需要寻找的数
//{
//	//使用 二维数组 右上角的数字 对比
//	int x = 0; // 右上角数字 的 行 下标
//	int y = col - 1; // 右上角数字 的 列 下标
//
//	while (x <= 2 && y >= 0)
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//
//	int k = 7;
//
//	int ret = FindNum(arr, k, 3, 3);
//
//	if (ret == 1)
//	{
//		printf("找到了\n");  
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int is_left_move(char* s1, char* s2)
//{
//	// 翻倍法
//	
//	//(优化)
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//
//	if (len1 != len2)
//		return 0; //当两个字符串长度不一样时，肯定不是通过左旋得来的，所以直接 返回 0 ，
//	              //函数中 return 权限最高， return 后相当于跳出这个函数，所以 return 后面的代码不会执行。
//
//	// 1. s1字符串 翻倍，即在 s1字符串 后面追加一个 s1字符串
//	strncat(s1, s1, len1); 
//
//	// 2. 判断 s2指向的字符串 是否是 s1指向的字符串 的 子串
//	char* ret = strstr(s1, s2);
//	if (ret == NULL) 
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//
//}
//
//int main()
//{
//	char s1[12] = "abcdef"; 
//
//	char s2[] = "cdefab";
//
//	printf("%d\n", is_left_move(s1,s2)); //打印 0
//
//	return 0;
//}

//*********************************
//*************讲解五**************
//*********************************

////判断一个字符串是否为另外一个字符串旋转之后的字符串。
////例如：
//// 给定s1 = AABCD 和 s2 = BCDAA ，返回1
//// 给定s1 = abcd  和 s2 = ACBD  ，返回0.
//#include <stdio.h>
//#include <string.h>
//void reverse(char* left, char* right) 
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//void left_move(char* arr, int k)
//{
//	//三步翻转法
//	int len = strlen(arr);
//
//	reverse(arr, arr + k - 1); 
//
//	reverse(arr + k, arr + len - 1); 
//
//	reverse(arr, arr + len - 1); //总体翻转
//
//}
//
//int is_left_move(char* s1, char* s2)
//{
//	int len = strlen(s1);
//	int i = 0;
//
//	for (i = 0; i < len; i++)
//	{
//		left_move(s1, 1);
//		// 这里的参数为什么不是 (s1, i) ？
//		// 因为每使用一次 left_move()函数 ， 字符串s1 就改变一次，
//		// 我们只需要它在每次循环中 左旋一次 即可，
//		// 若写成 (s1, i) ，当 i = 0 时，左旋 0 次，
//		//                  当 i = 1 时，在左旋 0 次 的基础上 再左旋 1 次，
//		//                  当 i = 2 时，在左旋 0 + 1 次 的基础上 再左旋 2 次，
//		// 就会造成错误。
//
//		int ret = strcmp(s1, s2);
//		//	strcmp()库函数 会根据 ASCII编码 依次比较 s1 和 s2 的每一个字符，直到 出现不一样的字符 或者 到达字符串末尾('\0') 结束。
//		//	返回值：
//		//	如果返回值 < 0，则表示 s1 小于 s2；
//		//	如果返回值 > 0，则表示 s2 小于 s1；
//		//	如果返回值 = 0，则表示 s1 等于 s2。
//
//		if (ret == 0)
//		{
//			return 1;
//		}
//	}
//	return 0; //对比完所有结果还不相同时才返回 0 ，所以要放在 for循环 外
//}
//
//int main()
//{
//	char s1[] = "AABCD";
//	char s2[] = "BCDAA";
//
//	printf("%d\n", is_left_move(s1,s2)); //打印 1
//
//	return 0;
//}



////左旋字符串
////实现一个函数，可以左旋字符串中的k个字符。
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//#include <stdio.h>
//#include <string.h>
//void reverse(char* left, char* right) // reverse() 有两个参数，第一个是 需翻转数组的 最左边地址，第二个是 需翻转数组的 最右边地址
//{
//	while (left < right)
//	{
//		// 原理：
//		// 从 两头开始 向 中间靠拢 对调元素，
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* arr, int k)
//{
//	//三步翻转法
//	//做法：如 abcdef ，要 左旋 2 位
//	// ab cdef -> 将字符串按 左旋的位数 分成两部分，一部分是旋转后往后移动，另一部分是旋转后往前移动
//	// 
//	// ba cdef -> 第一步：将 其中一部分(左边) 翻转
//	// ba fedc -> 第二步：将 另一  部分(右边) 翻转 
//	// 得到 bafedc ，
//	// cdefab  -> 第三步，将 总体 翻转
//	// 
//	// 所得 cdefab 即为所求
//	// 
//	// 
//	// 原理：
//	// 其实这个道理很简单，翻转后 前面的会变到后面去，
//	// 我们可以 先做第三步，总体先翻转
//	// 即 abcdef 翻转后得 fedcba
//	// 再做 前两步，每个部分各自翻转，
//	// 即 cdefab
//	// 
//	// 因为 翻转 意味着 数组内容会 倒序 ，
//	// 所以 第一步 和 第二部 的 翻转 都是为了 第三步 的 翻转 之后，数组内容 不会变成 倒序，
//	// 而 第三步 的 翻转 是为了 交换两部分的位置，达成 左旋 的目的。
//
//	int len = strlen(arr);
//
//	reverse(arr, arr + k - 1); //左边翻转
//	// 为什么 第二个参数 传 arr + k - 1 而不是 arr + k ？
//	// 因为若为 arr + k ，则当 k = 0 时 是 第一个元素的地址
//	//                      当 k = 1 时 是 第二个元素的地址
//	//                      当 k = 2 时 是 第三个元素的地址
//	//                      ......
//	// 而 k 的意思是 翻转 k 个字符，当 k = 2 时 我们 只需要翻转 第1个 和 第2个 字符，而不是 第3个 字符。
//
//	reverse(arr + k, arr + len - 1); //右边翻转
//	// 同理 右边翻转的左边地址 比 左边翻转的左边地址 高 1 个数组元素类型 的 长度
//	// 而 右边地址 arr + len - 1 是因为 不能把字符串最后面的 '\0' 也翻转了。
//
//	reverse(arr, arr + len - 1); //总体翻转
//
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	left_move(arr, 2); // left_move() 有两个参数，第一个是 待左旋的数组，第二个是 左旋的位数。
//
//	printf("%s\n", arr); //输出 cdefab
//
//	return 0;
//}

////左旋字符串
////实现一个函数，可以左旋字符串中的k个字符。
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//#include <stdio.h>
//#include <string.h>
//void left_move(char* arr, int k)
//{
//	int i = 0;
//	int j = 0;
//	int len = strlen(arr);
//
//	for (i = 0; i < k; i++) // 这个 for循环 控制 左旋的次数
//	{
//		//左旋一个字符
//		//1.拿起第一个字符(即 最左边的字符)
//		char tmp = *arr;
//		
//		//2.后面的字符 逐个往前 覆盖掉 前一位字符
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//
//		//3.把 拿起的第一个字符 放到 字符串 最后一位上
//		*(arr + len - 1) = tmp;
//
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	left_move(arr, 2); // left_move() 有两个参数，第一个是 待左旋的数组，第二个是 左旋的位数。
//
//	printf("%s\n", arr); //输出 cdefab
//
//	return 0; 
//}


//*********************************
//*************讲解四**************
//*********************************

//#include <stdlib.h> //使用 malloc()库函数 和 free()库函数 需引用头文件 <stdlib.h>
//int main()
//{
//	//申请空间
//	int* p = (int*)malloc(10 * sizeof(int));
//	// malloc()库函数 用来 申请空间，
//	// malloc(10 * sizeof(int)) 意思是 申请 10 个 int类型 的 空间 ，
//	// 申请后 malloc()库函数 会返回 申请好的空间 的 地址 ，
//	// malloc()库函数 的 返回类型 默认为 void* ，
//	// 而存入 int*类型 的 p 中，需要 强制类型转换成 int* 。
//
//	//释放空间
//	free(p);
//	// 意思是 释放 p 指向的 空间
//
//	//将 p 的 值 置为 NULL
//	p = NULL;
//
//	return 0;
//}

////比赛排名
////5位运动员参加了10米台跳水比赛，要求预测比赛结果，
////A选手说：B 第二，我第三；
////B选手说：我第二，E 第四；
////C选手说：我第一，D 第二；
////D选手说：C 最后，我第三；
////E选手说：我第四，A 第一；
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include <stdio.h>
//int main()
//{
//	int A = 0;
//	int B = 0;
//	int C = 0;
//	int D = 0;
//	int E = 0;
//	//A选手说：B 第二，我第三； -> B == 2 ， A == 3
//    //B选手说：我第二，E 第四； -> B == 2 ， E == 4
//    //C选手说：我第一，D 第二； -> C == 1 ， D == 2
//    //D选手说：C 最后，我第三； -> C == 5 ， D == 3
//    //E选手说：我第四，A 第一； -> E == 4 ， A == 1
//	//以上 判断 若为 真 则返回 1 ，若为 假 则返回 0 ，
//
//	// 通过 5层 for循环 ，罗列出所有名次的排序组合，包括名次相同的情况
//	for (A = 1; A <= 5; A++)
//	{
//		for (B = 1; B <= 5; B++)
//		{
//			for (C = 1; C <= 5; C++)
//			{
//				for (D = 1; D <= 5; D++)
//				{
//					for (E = 1; E <= 5; E++)
//					{
//						if ((B == 2) + (A == 3) == 1 && (B == 2) + (E == 4) == 1 && (C == 1) + (D == 2) == 1 && (C == 5) + (D == 3) && (E == 4) + (A == 1))
//							// 由题可知：
//							// 每位选手都说对了一半，
//							// 所以每个人 判定 两句话，一句真，一句假，
//							// 即 判断 为真 有 1 个，为假 有 1 个 ，返回值 的和 应该为 1 。
//							// 
//							// 对于每一位选手都是如此，
//							// 所以使用  &&逻辑与 ，全都成立 才为 真 ，表示 并且的意思
//						{
//							//要对输出的名次加以限制，排除名次相同的情况
//							if (A * B * C * D * E == 120) //名次之积 1 * 2 * 3 * 4 * 5 = 120
//								//为什么 A + B + C + D + E == 15 不行？
//								//如果判定条件为 A + B + C + D + E == 15 ，输出为：
//								// A = 1 , B = 2 , C = 5 , D = 2 , E = 5
//								// A = 3 , B = 1 , C = 5 , D = 2 , E = 4
//								// A = 3 , B = 4 , C = 1 , D = 3 , E = 4
//								//我们可以看见有时候 有两组相同的名次 且 少了一个名次 ，但 名次之和仍满足为 15
//								//所以 加法 并不能很好地限制名次
//							{
//								printf("A = %d , B = %d , C = %d , D = %d , E = %d\n", A, B, C, D, E);
//								//打印 A = 3 , B = 1 , C = 5 , D = 2 , E = 4
//							}
//						}
//
//					}
//				}
//			}
//		}
//	}
//
//	return 0;
//}


//*********************************
//*************讲解三**************
//*********************************

//赛马问题


////找杀手
////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。以下为4个嫌疑犯的供词。
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
////已知3个人说了真话，1个人说的是假话。现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include <stdio.h>
//int main()
//{
//	int killer = 0;
//	
//	for (killer = 'A'; killer <= 'D'; killer++)
//	// 字符 存入 int类型 中 ，存入的是 该字符 在 ASCII码表中 对应 十进制的值
//	{
//
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		// A说：不是我   -> killer != 'A'
//    	// B说：是C      -> killer == 'C'
//	    // C说：是D      -> killer == 'D'
//	    // D说：C在胡说  -> killer != 'D'
//		//以上 判断 若为 真 则返回 1 ，若为 假 则返回 0 ，
//		//
//		//由题可知：已知3个人说了真话，1个人说的是假话，
//		// 所以 判断 为真 有 3 个，为假 有 1 个 ，返回值 的和 应该为 3 。
//		// 
//		//即可以根据 返回值 之和 是否为 3 ，判断出 谁是杀手。
//		{
//			printf("killer = %c\n", killer); //打印 killer = C
//			// killer 是 int类型 ，使用 %c 打印 int类型 ，输出的是 int类型的十进制值 在 ASCII码表 中 对应的符号。
//		}
//
//	}
//
//	return 0;
//}

////在屏幕上打印杨辉三角:
////1
////1 1
////1 2 1
////1 3 3 1
////1 4 6 4 1
////......
//// 
////杨辉三角：每个元素的值 == 头顶两个元素的值之和
////  0 1 0
////   1 1 
////  1 2 1 
//// 1 3 3 1 
////1 4 6 4 1 
////......
//#include <stdio.h>
//int main()
//{
//	int arr[10][10] = { 0 };
//	int line = 0;
//
//	printf("打印几行杨辉三角(10行以内)：");
//	scanf("%d", &line);
//
//	//初始化杨辉三角
//	int i = 0;
//	int j = 0;
//	// 先把 二维数组 所有元素 置0
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			arr[i][j] = 0;
//		}
//	}
//	// 再把 二维数组 第一列 和 对角线 置 1 
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (j==0)
//			{
//				arr[i][j] = 1;
//			}
//			else if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//		}
//	}
//
//	//再计算 除了 第一列 和 对角线 上，其他元素的 值
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (j != 0 && j != i) //除了 第一列 和 对角线 上，其他的 元素
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]; //每个元素的值 == 头顶两个元素的值之和
//			}
//		}
//	}
//
//	//打印杨辉三角
//	for (i = 0; i < line; i++) //打印 line 行，所以 i < line
//	{
//		for (j = 0; j <= i; j++) //打印到 写对角线为止 ，所以 j <= i
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	// 输入 7
//	// 打印：
//	// 1
//	// 1 1
//	// 1 2 1
//	// 1 3 3 1
//	// 1 4 6 4 1
//	// 1 5 10 10 5 1
//	// 1 6 15 20 15 6 1
//
//	return 0;
//}

////在32位平台，大端模式下，处理器上的 变量b 等于什么？
//#include <stdio.h>
//int main()
//{
//	unsigned int a = 0x1234;
//
//	unsigned char b = *(unsigned char*)&a;
//
//	printf("%x\n", b);// 因为 VS编译器 是 小端模式，所以打印 34
//	//而大端模式下，应该打印 00 ，
//	//在32位平台，大端模式下，处理器上的 变量b 等于 0x00
//
//	return 0;
//}

//*********************************
//*************讲解二**************
//*********************************

////编程实现 喝汽水，
////         1瓶汽水1元，2个空瓶可以换一瓶汽水，
////         给20元，最多可以多少汽水?
//#include <stdio.h>
//int main()
//{
//	int money = 0; //给多少钱
//	printf("有多少钱：");
//	scanf("%d", &money);
//
//	int drink = 0; //已经喝过多少瓶
//	int empty = 0; //空瓶数量
//
//	if (money == 0)
//	{
//		drink = 0; //不这样设置，当 monry = 0 时，输出喝了 -1瓶 ，产生错误。
//	}
//	else
//	{
//		drink = money * 2 - 1;
//		// 从经济学价值交换的角度看， 2个空瓶 == 1瓶汽水 == 1元 ，即 一个空瓶 = 0.5元 ，
//		// 一瓶汽水 = 一个空瓶 + 瓶里汽水 = 1元 ，而现在知道 一个空瓶 = 0.5元 ，所以 瓶里汽水 = 0.5元 ，
//		// 假设有 2元 ，我们能买回来 瓶中汽水的数量 + 空瓶的数量 = 2 / 0.5 = 4份 ，
//		// 然而 我们最后喝完都会 剩下一个空瓶 ，所以 这个 4份 里面包含了 3份汽水 和 1份空瓶 ，
//		// 我们要计算的是 喝过多少瓶 ，所以 4份 - 1份空瓶 = 3份汽水 ，这 3份汽水 就是所求 ，
//		// 所以这个公式就是： 喝过多少份汽水 = money / 2 - 1 = money * 2 - 1 。
//	}
//
//	printf("最多能喝 %d 瓶\n", drink);
//	//输入 20 ，打印 最多能喝 39 瓶
//}

////编程实现 喝汽水，
////         1瓶汽水1元，2个空瓶可以换一瓶汽水，
////         给20元，最多可以多少汽水?
//#include <stdio.h>
//int main()
//{
//	int money = 0; //给多少钱
//	printf("有多少钱：");
//	scanf("%d", &money);
//
//	int drink = 0; //已经喝过多少瓶
//	int empty = 0; //空瓶数量
//
//	drink = money; //一开始用钱买了多少瓶，并喝完
//
//	empty = drink; //一开始用钱买了多少瓶，喝完后剩下的空瓶数量
//
//	//空瓶换汽水
//	while (empty >= 2) //只有 空瓶数量 大于2 时才能换
//	{
//		drink = drink + empty / 2; 
//		// 现在已经喝过多少瓶 = 上一次已经喝过多少瓶 + 这次空瓶换了多少瓶
//		//
//		// 这个式子 和 下面的式子 位置不能交换，若交换，空瓶子数量先被改变了，结果就不正确。
//
//		empty = empty / 2 + empty % 2;
//		// 现在的空瓶数量 = 刚才用空瓶换了几瓶汽水 + 刚才用空瓶换汽水，剩下的瓶子(如5个空瓶，只能换2瓶汽水，剩1个空瓶)
//
//	}
//
//	printf("最多能喝 %d 瓶\n", drink);
//	//输入 20 ，打印 最多能喝 39 瓶
//}

//*********************************
//*************讲解一**************
//*********************************

////打印菱形
////例如：
////      *                -> 6 空格 ，1  *号
////     ***               -> 5 空格 ，3  *号
////    *****              -> 4 空格 ，5  *号
////   *******             -> 3 空格 ，7  *号
////  *********            -> 2 空格 ，9  *号
//// ***********           -> 1 空格 ，11 *号
////*************          -> 0 空格 ，13 *号
//// ***********           -> 1 空格 ，11 *号
////  *********            -> 2 空格 ，9  *号
////   *******             -> 3 空格 ，7  *号
////    *****              -> 4 空格 ，5  *号
////     ***               -> 5 空格 ，3  *号
////      *                -> 6 空格 ，1  *号
//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	printf("请输入上半部分行数：");
//	scanf("%d", &line);
//
//	int i = 0;
//	int j = 0;
//
//	//打印上半部分
//	for (i = 0; i < line; i++)
//	{
//		//打印空格
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//
//		//打印 *号
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//
//		//打印换行
//		printf("\n");
//
//	}
//
//	//打印下半部分
//	for (i = 0; i < line - 1; i++)
//	{
//		//打印空格
//		for (j = 0; j < i + 1; j++)
//		{
//			printf(" ");
//		}
//
//		//打印 *号
//		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
//		{
//			printf("*");
//		}
//
//		//打印换行
//		printf("\n");
//
//	}
//
//	return 0;
//}

////写一个函数，可以逆序字符串内容
//#include <stdio.h>
//#include <string.h> 
//void reverse(char arr[])
//{
//	int len = (int)strlen(arr);
//
//	int left = 0;
//	int right = len - 1;
//	char ret;
//
//	while (left < right)
//	{
//		ret = arr[left];
//		arr[left] = arr[right];
//		arr[right] = ret;
//		right--;
//		left++;
//	}
//}
//
//int main()
//{
//	char arr[256] = { 0 };
//	printf("输入一个字符串：");
//
//	//scanf("%s", arr);
//
//	gets(arr);
//	// 虽然引用了 <stdio.h>头文件 但是仍会 报警告，
//	// 原因是这个函数不安全，从VS2015起 gets()函数 就没有了，因为可能会造成缓冲区溢出, 甚至程序崩溃。
//	// 
//	// 
//	// 因为， gets()函数 的定义为 char* gets(char* buffer) ,即
//	// gets() 用于从 标准输入设备 读入一个整行，以 '\n'(即回车) 或 EOF(即Ctrl+Z) 结束，
//	// 若成功结束，则 将读取的内容 写入 参数传入的指针指向的数组中 ，并返回 被写入数组的地址(被写入的数组 指 参数传入的指针指向的数组) ，
//	// 若出错或遇到文件结束时，则 返回NULL 。
//	// 
//	// 其中，行末的'\n'从流中取出，但不写入数组。
//	// 且 gets() 不检查 被写入的数组大小(此题指 数组arr ，我们要将这一行写入 数组arr 中) ，可以无限读取，不会判断上限，
//	// 如果 输入的字符串 超过 字符串长度(此题为256) ，它也不会做检测，此时就会发生溢出。
//	//
//	// 
//	// 当然，如果不管这个警告，那程序还是会运行成功,
//	// 如果不想报警告，就要使用VS提供的安全的函数 gets_s()函数 ，
//	// gets_s() 有两个参数，第一个是 数组的起始地址 ，
//	//                      第二个是 存储字符串的空间长度(被写入的数组能存多少个字符)(一般 参数传入的指针指向的数组多大 就能存多少个字符) ，
//	// 即写成 
//	// gets_s(arr, 256); 
//	// 就不会报错。
//	
//	reverse(arr);
//
//	printf("%s\n", arr);
//
//	return 0;
//}


//********************************************************


//*********************************
//*************讲解六**************
//*********************************

//////杨氏矩阵 
////有一个二维数组.
////数组的每行从左到右是递增的，每列从上到下是递增的.
////在这样的数组中查找一个数字是否存在。
////时间复杂度小于O(N);
////
////数组：
////1 2 3
////2 3 4
////3 4 5
////
////1 3 4
////2 4 5
////4 5 6
////
////1 2 3
////4 5 6
////7 8 9
//#include <stdio.h>
//int main()
//{
//
//	return 0;
//}




//*********************************
//*************讲解五**************
//*********************************

////实现一个函数，可以左旋字符串中的k个字符。
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//#include <stdio.h>
//#include <string.h>
//void turn(char arr[], int side, int lenth, int sz)
//{
//	int i = 0;
//	int j = 0;
//	char ret;
//	if (side == 1)
//	{
//		while (lenth)
//		{
//			for (i = 0; i < sz - 1; i++)
//			{
//				ret = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = ret;
//			}
//			lenth--;
//		}
//	}
//	else
//	{
//		while (lenth)
//		{
//			for (i = sz - 1; i > 0; i--)
//			{
//				ret = arr[i];
//				arr[i] = arr[i - 1];
//				arr[i - 1] = ret;
//			}
//			lenth--;
//		}
//	}
//}
//int main()
//{
//	char arr[20] = { 0 };
//	int input1 = 0;
//	int input2 = 0;
//
//	printf("请输入字符串：");
//	scanf("%s", &arr);
//	printf("左旋还是右旋(1/0)：");
//	scanf("%d", &input1);
//	printf("旋几位：");
//	scanf("%d", &input2);
//
//	int sz = (int)strlen(arr);
//
//	turn(arr, input1, input2, sz);
//
//	printf("%s\n", arr);
//
//	return 0;
//}

//*********************************
//*************讲解四**************
//*********************************

////5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
////A选手说：B第二，我第三；
////B选手说：我第二，E第四；
////C选手说：我第一，D第二；
////D选手说：C最后，我第三；
////E选手说：我第四，A第一；
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	int arr[5][2] = { {0,0},{0,0},{0,0},{0,0},{0,0} };
//
//	int count = 0;
//	int i = 0;
//	int j = 0;
//
//	while (1)
//	{
//		
//		int count = 0;
//		int i = 0;
//		int j = 0;
//		for (i = 0; i < 5; i++)
//		{
//			for (j = 0; j < 2; j++)
//			{
//				count = count + arr[i][j];
//			}
//		}
//		if (count == 5)
//		{
//			printf("A = %d , B = %d , C = %d , D = %d , E= %d\n", a, b, c, d, e);
//			break;
//		}
//	}
//
//	return 0;
//}



//*********************************
//*************讲解三**************
//*********************************

//////猜凶手
////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。以下为4个嫌疑犯的供词。
////
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
//// 
////已知3个人说了真话，1个人说的是假话。现在请根据这些信息，写一个程序来确定到底谁是凶手。
//#include <stdio.h>
//int main()
//{
//	int arr[4][4] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			arr[i][j] = 0;
//		}
//	}
//
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}


////打印杨辉三角
//#include <stdio.h>
//void trangle(int n)
//{
//	int arr[10][10] = { 0 };
//
//	int i = 0;
//	int j = 0;
//
//	//初始化杨辉三角
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				arr[i][j] = 1;
//			}
//		}
//	}
//
//	//编辑杨辉三角
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j != 0 && i != j)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//int main()
//{
//	int input = 0;
//	printf("打印几层杨辉三角：");
//	scanf("%d", &input);
//
//	trangle(input);
//
//	return 0;
//}


//*********************************
//*************讲解二**************
//*********************************

//调整数组，使奇数全部位于偶数前面
//#include <stdio.h>
//void line(int arr[], int sz)
//{
//	int left = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (arr[i] % 2 == 1)
//		{
//			int ret = arr[i];
//			arr[i] = arr[left];
//			arr[left] = ret;
//			left++;
//		}
//	}
//}
//int main()
//{
//
//	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	line(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

////编程实现：喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。
//#include <stdio.h>
//int main()
//{
//	int drink = 0;
//	int empty = 0;
//	int full = 0;
//
//	printf("有多少钱：");
//	scanf("%d", &full);
//
//	drink = full;
//	empty = full;
//	full = 0;
//
//	while (empty > 1)
//	{
//		full = empty / 2;
//		empty = empty % 2;
//
//		drink = drink + full;
//		empty = empty + full;
//		full = 0;
//
//	}
//
//	printf("可以喝 %d 瓶汽水\n", drink);
//
//	return 0;
//}



//*********************************
//*************讲解一**************
//*********************************

////打印菱形图案
//#include <stdio.h>
//int main()
//{
//	int line = 0;
//	printf("请输入上半部分行数：");
//	scanf("%d", &line);
//
//	int i = 0;
//	int j = 0;
//
//	//打印上半部分
//	for (i = 0; i < line; i++)
//	{
//		//打印空格
//		for (j = 0; j < line - 1 - i; j++)
//		{
//			printf(" ");
//		}
//
//		//打印 *号
//		for (j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//
//		//打印换行
//		printf("\n");
//	}
//
//	//打印下半部分
//	for (i = 0; i < line-1; i++)
//	{
//		//打印空格
//		for (j = 0; j < i+1; j++)
//		{
//			printf(" ");
//		}
//
//		//打印 *号
//		for (j = 0; j < 2*(line-1-i)-1; j++)
//		{
//			printf("*");
//		}
//
//		//打印换行
//		printf("\n");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = "*************";
//	char arr2[] = "             ";
//
//	int sz = sizeof(arr1) / sizeof(arr1[0]) - 1;
//
//	int left = sz/2;
//	int right = sz/2;
//	int i = 0;
//	for (i = 0; i <= sz/2; i++)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left--;
//		right++;
//		printf("%s\n", arr2);
//	}
//
//	left = 0;
//	right = sz-1;
//	for (i = 0; i <= sz / 2; i++)
//	{
//		arr2[left] = ' ';
//		arr2[right] = ' ';
//		left++;
//		right--;
//		printf("%s\n", arr2);
//	}
//
//}

//// 0~100000 之间的水仙花数
//#include <stdio.h>
//#include <math.h>
//int my_pow(int z, int count)
//{
//	int i = 0;
//	int reb = 1;
//
//	for (i = 0; i < count; i++)
//	{
//		reb = reb * z;
//	}
//
//	return reb;
//}
//int clsc(int i,int count)
//{
//	int reb = 0;
//	while (i > 0)
//	{
//		reb = reb + my_pow(i % 10, count);
//		i = i / 10;
//	}
//	return reb;
//}
//int main()
//{
//
//	int i = 0;
//	int result = 0;
//	int count = 0;
//
//	for (i = 0; i <= 100000; i++)
//	{
//		int ret = i;
//		count = 0;
//		while (ret > 0)
//		{
//			count++;
//			ret = ret / 10;
//		}
//
//		result = clsc(i,count);
//
//		if (i == result)
//		{
//			printf("%d ", i);
//		}
//
//	}
//
//	return 0;
//}

//求 Sn = a + aa + aaa + aaaa + aaaaa; 其中 a 是一个数字
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	int n = 0;
//	scanf("%d%d", &input, &n);
//
//	int sn = 0;
//	int i = 0;
//	int sb = input;
//	for (i = 0; i < n; i++)
//	{
//		sn = sn + sb;
//		sb = sb * 10 + input;
//	}
//
//	printf("Sn = %d\n", sn);
//
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//int test(int k,int n)
//{
//	if (n != 1)
//	{
//		return k * n + test(k, n / 10);
//	}
//	else
//	{
//		return k;
//	}
//}
//int main()
//{
//	int input = 0;
//	scanf("%d%d", &input);
//
//	int sn = test(input,11111);
//
//	printf("Sn = %d\n", sn);
//
//	return 0;
//}

////写一个函数，逆序字符串
//#include <stdio.h>
//void reline(char arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	char ret;
//
//	while (left < right)
//	{
//		ret = arr[left];
//		arr[left] = arr[right];
//		arr[right] = ret;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int  sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	printf("sz = %d\n", sz);
//	printf("start = %s\n", arr);
//
//	reline(arr, sz);
//
//	printf("finish = %s\n", arr);
//
//	return 0;
//}


//*********************************
//*************操作符**************
//*********************************

////编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
////#include <stdio.h>
////int main()
////{
////	int m = 0;
////	int n = 0;
////	printf("请输入两个数：");
////	scanf("%d%d", &m, &n);
////
////	int count = 0;
////
////	int i = 0;
////	for (i = 0; i < 32; i++)
////	{
////		if (((m >> i) & 1) != ((n >> i) & 1))
////			count++;
////	}
////
////	printf("不同位的个数：%d\n", count);
////
////	return 0;
////}
//#include <stdio.h>
//int main()
//{
//	int m = 0;
//	int n = 0;
//	printf("请输入两个数：");
//	scanf("%d%d", &m, &n);
//
//	int count = 0;
//
//	int mid = m ^ n;
//
//	while (mid)
//	{
//		mid = mid & (mid - 1);
//		count++;
//	}
//
//	printf("不同位的个数：%d\n", count);
//
//	return 0;
//}



////输出一个整数的每一位
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		printf("%d ", (input >> i) & 1);
//	}
//
//	return 0;
//}



////获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	int i = 0;
//
//	printf("偶数位：");
//	for (i = 0; i < 32; i += 2)
//	{
//		printf("%d ", (input >> i) & 1);
//	}
//
//	printf("\n");
//
//	printf("奇数位：");
//	for (i = 1; i < 32; i += 2)
//	{
//		printf("%d ", (input >> i) & 1);
//	}
//
//	return 0;
//}



////写一个函数返回参数二进制中 1 的个数
//#include <stdio.h>
////int count_one_bits(int input)
////{
////	int count = 0;
////	int i = 0;
////	for (i = 0; i < 32; i++)
////	{
////		if (((input>>i) & 1) == 1)
////		{
////			count++;
////		}
////	}
////	return count;
////}
//
//int count_one_bits(int input)
//{
//	int count = 0;
//	do
//	{
//		if (input != 0)
//		{
//			input = input & (input - 1);
//			count++;
//		}
//	} while (input);
//	return count;
//}
//
//int main()
//{
//	int input = 0;
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	printf("二进制中 1 的个数：%d\n", count_one_bits(input));
//
//	return 0;
//}