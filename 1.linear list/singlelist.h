#pragma once
#ifndef SINGLELIST_H
#define SINGLELIST_H		

typedef struct singlelist
{
	int data;
	int length;
	struct singlelist* next;
} singlelist;

bool init_singlelist(singlelist** L);                // 初始化链表头（创建空表）
void delete_singlelist(singlelist* L);               // 释放链表所有节点
void print_singlelist(singlelist* L);                // 打印链表内容
int head_insert_singlelist(singlelist* L, int value);            // 头部插入节点
int location_insert_singlelist(singlelist* L, int location, int value); // 指定位置插入
int location_delete_singlelist(singlelist* L, int location, int value); // 指定位置删除
int location_changevlaue_singlelist(singlelist* L, int location, int value); // 修改指定位置值
int location_getvalue_singlelist(singlelist* L, int location, int* value); // 获取指定位置值

#endif

