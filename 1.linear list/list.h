#pragma once
#ifndef LIST_H
#define LIST_H

#define initsize 5  //默认用malloc函数开辟的动态分配空间的n个类型的数据空间大小：n=initsizeof


//定义线性表的单个数据元素类型（结合日常生活中学生信息表理解：对应为单个学生个人的信息）
typedef struct {
	int* data;  //学生表可包含多个学生的数据，固可用数组和指针，使用指针更为方便
	int maxsize;//线性表操作的辅助数据：记录开辟了多大长度的空间内存，亦可用于二次空间的increase
	int length; //线性表操作的辅助数据：记录当前内存空间使用了多少
}seqlist;   //typedef 类型重定义结构体为seqlist（sequence list：顺序表）

//线性表基本操作功能函数
void initseqlist(seqlist* L);//初始化线性表
void insersize(seqlist* L, int addsize);//为线性表增加内存空间：
bool listinsert(seqlist* L, int location, int num);//插入数据
bool listdelete(seqlist* L, int location, int* num);//删除表中指定的位置  num存储该位置的值
int loactelist(seqlist* L, int num);//按值查找 查找失败返回0 查找成功返回该值的位置
int getnumlist(seqlist* L, int location, int* num);//按位查找  num存储该位置的值
void printlist(seqlist* L);//打印线性表信息

#endif 
