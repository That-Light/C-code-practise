#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
////自己定义的函数需要放在主函数之前，否则报错无法正常运行
//void menu()
//{
//	printf("*************************************\n");
//	printf("*****     1.play     0.exit     *****\n");
//	printf("*************************************\n");
//}
//
////自己定义的函数需要放在主函数之前，否则报错无法正常运行
//void game()
//{
//	int ret = 0;   //存放生成的随机数
//	int guess = 0;   //存放每次猜测的数值
//
//	//1.第一步：生成随机数
//	ret = rand() % 100 +1;   //①：rand() 库函数需要引用头文件 <stdlib.h> 。 int rand (void) 即 rand() 无参数，调用会返回一个整型值
//		                     //②：需要用 srand() 设置随机数种子起点，不然每次重新启动程序生成的结果都相同
//	                         //③：rand() 生成 0~RAND_MAX(0x7fff(十六进制))，即 0~32767 之间的整数 。 RAND_MAX 转到定义需先引用头文件 <stdlib.h>
//	                         //④：( rand() % 100 + 1 ) ，因为 rand() 生成 0~32767 之间的整数，取模 %100 即生成 0~99 之间的整数，再 +1 即生成 1~100 之间的整数
//
//    //2.第二部：猜数字
//	while (1)   // while(一个非零整数) ，零为假，非零为真， while(1)恒为真，即死循环，循环里可用 break 跳出
//	{
//		printf("猜数字：");
//		scanf("%d", &guess);
//		if (ret > guess)
//		{
//			printf("猜小了\n");
//		}
//		else if (ret < guess)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了！\n");
//			break;
//		}
//	}
//}
//
////主函数
//int main()
//{
//	int input = 0;   //接收选择的值
//	
//	srand((unsigned int)time(NULL));   //置随机数种子，即设置一个随机数起点，只需在整个程序中设置一次就可，重复设置会导致每次生成的随机数之间相隔比较接近
//	                                   //
//	                                   // srand() :设置随机数生成起点
//									   //①：定义 void srand(unsigned int Seed) 即需要设置一个 整型值 作为 参数(种子)，返回类型为 空(无类型)
//									   //    但如果仅设置 1、2…… 这种固定的整数，会导致每次生成的随机数为同一个值，
//									   //    所以要设置一个时刻变化的整数，即 时间戳 time()
//									   //②：时间戳 time() 返回一个 长整型long ，而 srand() 需要一个 整型int ，所以要用 unsigned int 强制类型转换，
//									   //    将 time() 返回的 长整型long 转换成 srand() 需要的 无符号的整型
//									   //③：使用库函数 srand() 需引用头文件 <stdlib.h>
//									   // 
//	                                   // time() :时间戳
//									   //①：当前计算机时间 跟 计算机的起始时间(1970年1月1日0时0分0秒) 的 差值 换算成 秒
//									   //    即 当前计算机时间 - 1970年1月1日0时0分0秒 = （***）秒
//	                                   //②：使用库函数 time() 需引用头文件 <time.h>
//									   //③：定义 time_t time(time_t* timer); 即 设置一个 time_t* 的参数，返回一个 time_t 类型值
//	                                   //  一、返回类型 time_t ，转到定义即 #ifndef _CRT_NO_TIME_T
//                                       //                                     #ifdef _USE_32BIT_TIME_T
//									   //                        	              typedef __time32_t time_t;
//									   //                                     #else
//									   //                        	              typedef __time64_t time_t;
//									   //                                     #endif
//									   //                                   #endif
//									   //                      根据计算机操作位数将 __time32_t类型 或 __time64_t类型 重命名为 time_t类型
//									   //        而 __time32_t类型 或 __time64_t类型 ，转到定义即 typedef long __time32_t;
//	                                   //                                                         typedef __int64 __time64_t;
//									   //                      将 long类型 或 __int64类型 重命名，即将 长整型 重命名为 __time32_t类型 或 __time64_t 类型
//									   //                      (注意：在32位操作系统中，可用 long 表示 长整形；在64位操作系统中，可用 __int64 表示长整型)
//									   //    归根结底， time_t 就是一个 长整型long
//									   //     
//									   //  二、设置参数 time_t* ，为一个指针，这里设置 NULL ，即 空指针 即可
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("退出游戏");
//			break;
//		default:
//			printf("选择错误，请重新选择！\n");
//			break;
//		}
//
//	} while (input);   //这里比较巧妙， input = 0 时为 假 ，刚好满足 退出游戏 并 跳出循环； input != 0 时为 真 ，刚好满足 游戏选择 并 继续循环
//
//	return 0;
//}