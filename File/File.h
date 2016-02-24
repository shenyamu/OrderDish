#ifndef _FILE_H_
#define _FILE_H_
#include <stdio.h>
#include "..\\List\List.h"
/************************************************************************
* 函数名称：FILE *File_open(char *dirname)
* 功能描述：
*    文件夹创建，打开文件函数
* 参数说明：
*    char *dirname   文件名
* 返回值：
*    返回打开文件的指针
*************************************************************************/
FILE *File_open(char *dirname);

/************************************************************************
* 函数名称：int File_write(FILE *fp,pList head,int size,int n)
* 功能描述：
*    链表写入文件函数
* 参数说明：
*    FILE *fp         要写入文件的文件指针
     pList head       要写入链表的头指针
     int size         要写入的结构体大小
     int n             要写入的起始位置
* 返回值：
*    写入的数据个数
*************************************************************************/
int File_write(FILE *fp,pList head,int size,int n);

/************************************************************************
* 函数名称：pList File_read(FILE *fp,int size)
* 功能描述：
*    文件数据读出函数
* 参数说明：
*    FILE *fp    要读出的文件指针
     int size    要读出的结构体大小
* 返回值：
*    读出的链表头指针
*************************************************************************/
pList File_read(FILE *fp,int size);

/************************************************************************
* 函数名称：void File_updata(FILE *fp,pList head,int size,int (*p)(pList))
* 功能描述：
*    文件数据修改函数
* 参数说明：
*    FILE *fp     要修改的文件指针
     pList head   要修改的头结点
     int size     要修改的结构体大小
	 int (*p)(pList)  修改的函数指针
* 返回值：
*    无
*************************************************************************/
void File_updata(FILE *fp,pList head,int size,int (*p)(pList));

/************************************************************************
* 函数名称：void File_remove(FILE *fp,pList head,int size,int (*p)(pList))
* 功能描述：
*    文件数据删除函数，员工和台桌的假删除
* 参数说明：
*    FILE *fp      要删除的文件指针
     pList head    要删除的头结点
     int size      要删除的结构体大小
	 int (*p)(pList)   删除的函数指针
* 返回值：
*    无
*************************************************************************/
void File_remove(FILE *fp,pList head,int size,int (*p)(pList));

/************************************************************************
* 函数名称：void File_del(FILE *fp,char dir[],pList head,int size,int (*pdel)(pList))
* 功能描述：
*    文件数据删除函数，菜谱真删除
* 参数说明：
*    FILE *fp      要删除的文件指针
     char dir[]    文件路径
     pList head    要删除的头结点
     int size      要删除的结构体大小
	 int (*pdel)(pList)   删除的函数指针
* 返回值：
*    无
*************************************************************************/
void File_del(FILE *fp,char dir[],pList head,int size,int (*pdel)(pList));

/************************************************************************
* 函数名称：void File_add(FILE *fp,pList head,int size,void *(*pstr)(void *data))
* 功能描述：
*    文件数据增加函数
* 参数说明：
*    FILE *fp      要增加的文件指针
     pList head    要增加的头结点
     int size      要增加的结构体大小
	 void *(*pstr)(void *data)   数据增加的函数指针，返回新增数据
* 返回值：
*    无
*************************************************************************/
void File_add(FILE *fp,pList head,int size,void *(*pstr)(void *data));

#endif
