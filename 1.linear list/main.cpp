#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"LIST.H"
#include"singlelist.h"


//线性表基本功能主函数测试

//int main()
//{
//	int num = 0;//获取线性表删除/查找的值或位置
//
//	 seqlist L1;
//	 initseqlist(&L1);//初始化顺序表
//	 listinsert(&L1, 1, 1);//插入数据1
//	 listinsert(&L1, 2, 2);//插入数据2
//	 listinsert(&L1, 3, 3);//插入数据3
//	 listinsert(&L1, 4, 4);//插入数据4
//	 listinsert(&L1, 5, 5);//插入数据5
//	 printlist(&L1);//打印线性表信息
//
//	 insersize(&L1, 2);//为线性表增加2个内存空间：
//	 listinsert(&L1, 1,9);//插入数据9
//	 listdelete(&L1, 2, &num);//删除表中指定2的位置  num存储该位置的值
//	 printf("删除位置的值为：%d\n", num);
//	 printlist(&L1);//打印线性表信息
//
//	 num=loactelist(&L1, 5);//按值（5）查找 查找失败返回0 查找成功返回该值的位置
//	 printf("值的位置为：%d\n", num);
//
//	 getnumlist(&L1, 2, &num);//按位（2）查找  num存储该位置的值
//	 printf("位置的值为：%d\n", num);
//
//      printlist(&L1);//打印线性表信息
//
//
//	return 0;
//}
//


//单链表基本功能主函数测试
int main()
{
	singlelist *L;
	init_singlelist(&L);//初始化单链表
	head_insert_singlelist(L, 1);//头节点插入元素1
	head_insert_singlelist(L, 2);//头节点插入元素2
	head_insert_singlelist(L, 3);//头节点插入元素3
	printf("单链表内容为：\n");	
	print_singlelist(L);//打印单链表
	printf("在位置2插入元素4后，单链表内容为：\n");
	location_insert_singlelist(L, 2, 4);//指定位置2插入元素4
	print_singlelist(L);//打印单链表
	int value = 0;
	value=location_delete_singlelist(L, 2, value);//指定位置2删除元素，value存储该位置的值
	printf("删除位置的值为：%d\n", value);
	printf("删除位置2后，单链表内容为：\n");
	print_singlelist(L);//打印单链表
	location_changevlaue_singlelist(L, 2, 5);//指定位置2修改元素为5
	printf("修改位置2的值为5后，单链表内容为：\n");
	print_singlelist(L);//打印单链表
	location_getvalue_singlelist(L, 2, &value);//指定位置2获取元素值
	printf("获取位置2的值为：%d\n", value);
	delete_singlelist(L);//销毁单链表
	printf("单链表已销毁。\n");
	return 0;
}