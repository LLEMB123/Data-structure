
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>  //malloc函数需调用库文件
#include"LIST.H" 

//内存的动态分配---线性表

//初始化线性表：主要是初始化需要开辟多少合适的内存空间。不易过多也不易过少
void initseqlist(seqlist* L)
{
	L->data = (int*)malloc(initsize * sizeof(int)); //malloc函数开辟空间
	L->maxsize = initsize;  //空间的最大长度默认为initsize
	L->length = 0;
}


//为线性表增加内存空间：可以简单的理解成学习表的表格不够
void insersize(seqlist* L, int addsize)
{
	int* p = L->data;    //需将以前开辟的空间地址用中间指针变量指向，为了实现将旧的空间内容复制到新的空间去
	L->data = (int*)malloc((L->maxsize + addsize) * sizeof(int));  //开辟增加后的空间内存
	for (int i = 0; i < L->length; i++)  //复制旧的内存空间内容给新的内存空间
	{
		L->data[i] = p[i]; //数组本质也是指针的操作，固可替换
	}
	L->maxsize = L->maxsize + addsize; //新增加后的内存空间长度
	free(p);  //释放旧的空间内存，若不释放会造成空间被占，固而浪费，free与malloc搭配使用
}

//插入数据

bool listinsert(seqlist* L, int location, int num)  // 表地址   插入位置   插入元素
{
	if (location<0 || location>L->maxsize || (L->length >= L->maxsize))  //健壮性判定（位置越界，内存已满）
	{
		printf("false:位次输入错误或内存已满\n");
		return false;
	}


	for (int j = L->length; j >= location; j--)  //由尾开始倒退元素，腾出需插入元素的位置
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[location - 1] = num;  //指定位置插入元素
	L->length++;   //更改当前表中的数据长度
	return true;
}


//删除表中指定的位置

bool listdelete(seqlist* L, int location, int* num)  //表地址   表位置   存储删除位置的元素
{
	*num = L->data[location - 1];       //指针“返回”删除位置的元素
	if (location<0 || location>L->maxsize)   //判断输入位置的正确性
	{
		printf("false:位次输入错误\n");
		return false;
	}


	for (int j = location; j < L->length; j++) //由需删除位置的下一个位置依次开始往前覆盖
	{
		L->data[j - 1] = L->data[j];
	}
	L->length--;  //更改数据的长度
	return true;
}


//按值查找 查找失败返回0
int loactelist(seqlist* L, int num)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == num)
		{
			return i + 1;
		}
	}
	return false;
}

//按位查找 
int getnumlist(seqlist* L, int location, int* num)
{
	if (location<0 || location>L->maxsize)   //判断输入位置的正确性
	{
		printf("false:位次输入错误\n");
		return false;
	}
	*num = L->data[location - 1];  //返回该位置的值
	return true;
}


//打印线性表信息
void printlist(seqlist* L)
{
	printf("表的现内容长度：%-2d ；表的最大内存容量：%-2d。\n", L->length, L->maxsize);
	
	if (L->length == 0) //判断标准内容是否为空
	{
		printf("内容为空。\n");
	}
	else {
		printf("表内容为：");
		for (int i = 0; i < L->length; i++)  //遍历打印表中数据
		{

			printf("%-2d", L->data[i]);
			printf(",");
		}
		printf("\n");
	}

	
}
