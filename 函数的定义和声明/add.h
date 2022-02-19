#define _CRT_SECURE_NO_WARNINGS

//防止 同一个 头文件 被 包含 多次
//因为 包含 相当于把 头文件 里面的内容 拷贝 一份到 主文件 中，分工写代码中可能多次 包含 ，造成内存浪费
#ifndef __ADD_H__   // if not define ,如果没有定义过 __ADD_H__(名字) 的 头文件，则
#define __ADD_H__   //定义 __ADD_H__(名字) 的头文件，并 包含 进 主文件 中，否则不再进行 包含

//函数声明
// .h文件 里面放 函数的声明
int Add(int x, int y);

#endif   //结束包含