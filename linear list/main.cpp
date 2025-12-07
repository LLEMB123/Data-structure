#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"LIST.H"


int main()
{
	int num = 0;//获取线性表删除/查找的值或位置

	 seqlist L1;
	 initseqlist(&L1);//初始化顺序表
	 listinsert(&L1, 1, 1);//插入数据1
	 listinsert(&L1, 2, 2);//插入数据2
	 listinsert(&L1, 3, 3);//插入数据3
	 listinsert(&L1, 4, 4);//插入数据4
	 listinsert(&L1, 5, 5);//插入数据5
	 printlist(&L1);//打印线性表信息

	 insersize(&L1, 2);//为线性表增加2个内存空间：
	 listinsert(&L1, 1,9);//插入数据9
	 listdelete(&L1, 2, &num);//删除表中指定2的位置  num存储该位置的值
	 printf("删除位置的值为：%d\n", num);
	 printlist(&L1);//打印线性表信息

	 num=loactelist(&L1, 5);//按值（5）查找 查找失败返回0 查找成功返回该值的位置
	 printf("值的位置为：%d\n", num);

	 getnumlist(&L1, 2, &num);//按位（2）查找  num存储该位置的值
	 printf("位置的值为：%d\n", num);

      printlist(&L1);//打印线性表信息


	return 0;
}

