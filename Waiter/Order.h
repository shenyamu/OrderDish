#ifndef _ORDER_H_
#define _ORDER_H_

#include <conio.h>
#include "..\\File\File.h"
#include "..\\List\List.h"
#include "..\\Table\Table.h"
#include "..\\Menu\Menu.h"
#include "..\\Log_in\Log_in.h"
#include "..\\Glb_putstring\\Glb_putstring.h"

struct Order_t //订单
{
	char ordernum[15]; //订单号
	char acname[10]; // 结账服务员
	char tablenum[6]; // 台桌号
	int money; //总金额
	int amount; //总份数
	
};

struct Title_t  //详单
{
	char ordernum[15]; //订单号
	struct Menu_t pMenu;// 某一道菜
	int amount;// 某一道菜的份数
	
};

/************************************************************************
* 函数名称：struct Order_t *Order_init(char str[])
* 功能描述：
           订单结构体初始化函数
* 参数说明：
*       char str[]  点菜的台桌号
* 返回值：
*        返回初始化的订单结点指针
*************************************************************************/
struct Order_t *Order_init(char str[]);

/************************************************************************
* 函数名称：struct Title_t *Title_init(struct Order_t *pNew,struct Menu_t *data,int n)
* 功能描述：
           详单结构体初始化函数
* 参数说明：
*       struct Order_t *pNew     点菜中台桌对应的订单数据的指针
        struct Menu_t *data      新增的菜谱数据
        int n                    菜的份数
* 返回值：
*        返回初始化的详单结点指针
*************************************************************************/
struct Title_t *Title_init(struct Order_t *pNew,struct Menu_t *data,int n);

/************************************************************************
* 函数名称：void Order_add(int count1,struct Order_t *pNew,pList pTitle,pList pOrder,pList pMenu,char tabpath[])
* 功能描述：
           加菜功能函数
* 参数说明：
*       int count1               菜谱链表的个数
        struct Order_t *pNew    对应的订单数据指针
        pList pTitle            详单链表的头指针
        pList pOrder            订单链表的头指针
        pList pMenu             菜谱链表的头指针
        char tabpath[]          详单的中间存放路径
* 返回值：
*       无
*************************************************************************/
void Order_add(int count1,struct Order_t *pNew,pList pTitle,pList pOrder,pList pMenu,char tabpath[]);
/************************************************************************
* 函数名称：void Order_del(int count1,struct Order_t *pNew,pList pTitle,pList pMenu,pList pOrder,char tabpath[])
* 功能描述：
           减菜功能函数
* 参数说明：
*       int count1               菜谱链表的个数
        struct Order_t *pNew    对应的订单数据指针
        pList pTitle            详单链表的头指针
        pList pOrder            订单链表的头指针
        pList pMenu             菜谱链表的头指针
        char tabpath[]          详单的中间存放路径
* 返回值：
*       无
*************************************************************************/
void Order_del(int count1,struct Order_t *pNew,pList pTitle,pList pMenu,pList pOrder,char tabpath[]);

/************************************************************************
* 函数名称：void Order_statist(struct Order_t *pNew,pList pTitle)
* 功能描述：
           订单的总金额、总份数统计函数
* 参数说明：
*       struct Order_t *pNew     订单数据的指针
        pList pTitle             详单链表的头指针
* 返回值：
*        无
*************************************************************************/
void Order_statist(struct Order_t *pNew,pList pTitle);

/************************************************************************
* 函数名称：void Order_print(pList pMenu,pList pTitle,struct Order_t *pNew)
* 功能描述：
           订单打印函数
* 参数说明：
*       pList pMenu            菜谱的头指针
        pList pTitle           详单的头指针
        struct Order_t *pNew   订单数据的指针
* 返回值：
*        无
*************************************************************************/
void Order_print(pList pMenu,pList pTitle,struct Order_t *pNew);

/************************************************************************
* 函数名称：long Ordernum_get(char num[],char str[])
* 功能描述：
           自动生成订单号的函数
* 参数说明：
*       char num[]    订单结构体中的订单号成员变量
        char str[]    点菜的台桌号
* 返回值：
*        返回订单号
*************************************************************************/
long Ordernum_get(char num[],char str[]);

/************************************************************************
* 函数名称：void Orderdate_input(long *stardate,long *enddate)
* 功能描述：
           开始日期和结束日期的输入函数
* 参数说明：
*       long *stardate    开始日期的指针
        long *enddate     结束日期的指针
* 返回值：
*        无
*************************************************************************/
void Orderdate_input(long *stardate,long *enddate);

/************************************************************************
* 函数名称：void convert(char s[],int data,int n)
* 功能描述：
           日期转换函数
* 参数说明：
*       char s[]     存放转换结果
        int data    待转换的日期
        int n       日期的位数
* 返回值：
*        无
*************************************************************************/
void convert(char s[],int data,int n);

/************************************************************************
* 函数名称：void Order_search_unbuy(pList pOrder,pList pTable)
* 功能描述：
           未买订单查询函数
* 参数说明：
*      pList pOrder     订单的头指针
    
* 返回值：
*        无
*************************************************************************/
void Order_search_unbuy(pList pOrder);

/************************************************************************
* 函数名称：void Order_search_buy()
* 功能描述：
           已买订单查询函数
* 参数说明：
*        无
* 返回值：
*        无
*************************************************************************/
void Order_search_buy();

/************************************************************************
* 函数名称：void Title_print(pList pTitle,struct Order_t *pOrder)
* 功能描述：
           详单打印函数
* 参数说明：
*      pList pTitle             详单的头指针
       struct Order_t *pOrder   订单数据的指针
* 返回值：
*        无
*************************************************************************/
void Title_print(pList pTitle,struct Order_t *pOrder);

#endif


