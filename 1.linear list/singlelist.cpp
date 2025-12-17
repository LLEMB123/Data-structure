#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include"singlelist.h"

/*	 文件：singlelist.cpp
   描述：实现一个简单的单链表（带头结点）的基本操作：
         初始化、销毁、打印、头插入、指定位置插入、指定位置删除、
         指定位置修改值、指定位置获取值。
   备注：本文件为注释增强版本，未修改原有实现逻辑，仅补充说明。
*/

/*
//// 创建单链表结构体（注：该结构体定义应在 singlelist.h 中）
// typedef struct
// {
//     int data;
//     int length;       // 头结点通常记录链表长度（当前实现使用此字段）
//     singlelist* next; // 指向下一个结点
// } singlelist, singlenode;
*/

// 销毁单链表
// 参数：L - 指向链表头结点或任意结点的指针（通常传入头结点）
// 说明：逐结点释放内存，最终释放到 NULL；若传入 NULL，函数不做任何操作。
void delete_singlelist(singlelist* L)
{
    // 遍历释放每一个结点
	while (L)
	{
		singlelist* temp = L; // 保存当前结点指针以便释放
		L = L->next;          // 移动到下一个结点
		free(temp);           // 释放当前结点内存
	}
}



// 初始化单链表（分配头结点）
// 参数：L - 指向 singlelist* 的指针，调用方应传入头指针的地址（singlelist**）
// 返回：true 表示分配并初始化成功，false 表示分配失败
// 说明：该函数在头指针处分配一个头结点并初始化 data/length/next 字段。
// 注意：此处使用了赋值表达式 (*L = malloc(...)) 放在 if 中判断返回值是否非空。
bool init_singlelist(singlelist**L)
{
	// 在 if 中进行赋值并判断是否分配成功
	if (*L = (singlelist*)malloc(sizeof(singlelist)))
	{
		(*L)->data = 0;    // 头结点 data 默认为 0（可用于存放特殊信息）
		(*L)->length = 0;  // 头结点记录链表长度（当前元素个数，不含头结点）
		(*L)->next = NULL; // 初始时没有后继结点
		return true;
	}
	else
		return false;
	
}

// 打印单链表（从头结点的下一个结点开始打印）
// 参数：L - 指向链表头结点
// 说明：按结点顺序逐行打印 data 值，格式化为宽度为 3 的整型输出。
// 注意：如果链表为空（头结点的 next 为 NULL），函数不会输出任何数据。
void print_singlelist(singlelist* L)
{
	// 跳过头结点，循环遍历所有实际存放数据的结点
	while (L->next)
	{
		L = L->next;
		printf("%-3d\n", L->data); // 左对齐输出数据并换行
	}
}


// 头节点插入元素（在头结点之后插入新结点）
// 参数：L - 指向头结点，value - 要插入的值
// 返回：int（函数体中使用 true/false 返回，非严格布尔）
// 说明：在头部插入新结点并将 head->length 自增
int head_insert_singlelist(singlelist* L, int value)
{
	// 为新结点分配内存
	if (singlelist* temp = (singlelist*)malloc(sizeof(singlelist)))
	{
		L->length++;            // 更新长度（头结点维护）
		temp->next = L->next;   // 新结点的 next 指向原来的第一个结点（可能为 NULL）
		L->next = temp;         // 头结点的 next 指向新结点
		temp->data = value;     // 设置新结点数据
		return true;            // 返回成功（1）
		
	}
	else {
		return false;           // 分配失败，返回 0
	}
}

// 指定位置插入元素（在位置 location 之后插入）
// 参数：L - 指向头结点，location - 插入位置索引（按实现，通常为 0..length），value - 要插入的值
// 返回：int（true 表示成功，false 表示失败）
// 说明：函数中存在一个条件判断：(location > L->length) && (location <= 0)
//       该判断逻辑看起来有误（应为 OR），但此处保留原实现并在注释中标注。
int location_insert_singlelist(singlelist* L, int location,int value)
{
	// 尝试分配新结点
	if (singlelist* temp = (singlelist*)malloc(sizeof(singlelist)))
	{
		// 边界检查（注意：原代码使用 &&，这会导致错误的有效区间判断）
		if ((location > L->length) && (location <= 0))
		{
			printf("位置错误\n");
			return false;
		}
		else {
			// 遍历到待插入位置的结点（从头结点开始走 location 步，最终 L 为插入位置的结点）
			for (int i = 1; i < location; i++)
			{
				L = L->next;
			}
			// 执行插入：新结点接入链表
			temp->next = L->next;
			L->next = temp;
			temp->data = value;
			return true;
		}
	}
	else {
		printf("内存空间不足\n");
		return false;
	}
}


// 指定位置删除元素
// 参数：L - 指向头结点，location - 要删除的结点位置（1 表示第一个数据结点），value - 用于返回被删除的值（当前以值传入并返回）
// 返回：int - 若出错返回 false（0），成功时返回被删除结点的 data 值（注意：函数签名与常规设计不同）
// 说明：实现中对 length 的维护存在错误（L->length++ 应为 L->length--），此处仅注释指出，不修改代码逻辑。
int location_delete_singlelist(singlelist* L, int location,int value)
{
	// 检查位置是否合法（位置 > length 或 <= 0 则错误）
	if (location > L->length || location <= 0)
	{
		printf("位置错误\n");
		return false;
	}
	else
	{
		L->length++; // 注意：此处逻辑有误，删除操作应当使长度减一（L->length--）。保留原代码但标注问题。
		singlelist* pre = L;
		// 遍历到将要删除的结点：循环 location 次，结束后 L 指向要删除的结点，pre 指向其前驱
		for (int i = 0; i < location; i++)
		{
			pre = L;
			L = L->next;
		}
		value = L->data;       // 保存被删除结点的数据到 value（只是局部赋值）
		pre->next = L->next;   // 前驱跳过当前结点，链表断开当前结点
		free(L);               // 释放删除结点
		return value;          // 返回被删除结点的值
	}
}

// 指定位置改变元素值
// 参数：L - 指向头结点，location - 要修改的结点位置（1 表示第一个数据结点），value - 要设置的新值
// 返回：int（true 表示成功，false 表示失败）
// 说明：函数遍历到目标结点并修改其 data 字段。
int location_changevlaue_singlelist(singlelist* L, int location, int value)
{
	if (location > L->length || location <= 0)
	{
		printf("位置错误\n");
		return false;
	}
	else {
		// 遍历到目标结点（从头结点走 location 步）
		for (int i = 0; i < location; i++)
		{
			L = L->next;
		}
		L->data = value; // 修改数据
		return true;
	}
}


// 指定位置获取元素值
// 参数：L - 指向头结点，location - 要获取的结点位置，value - 用于返回值（同样以值传入）
// 返回：int - 若出错返回 false（0），否则返回目标结点的 data 值
// 说明：注意本函数通过值参数 value 返回数据（实际效果是通过返回值返回），调用者需根据返回值获取数据。
int location_getvalue_singlelist(singlelist* L, int location, int *value)
{
	if (location > L->length || location <= 0)
	{
		printf("位置错误\n");
		return false;
	}
	else {
		// 遍历到目标结点
		for (int i = 0; i < location; i++)
		{
			L = L->next;
		}
		*value = L->data; // 将数据赋给局部变量 value
		return true;
	}
}
