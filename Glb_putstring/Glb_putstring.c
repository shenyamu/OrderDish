/************************************************************************
* 版权所有  (c)2008,   卓越计算机职业培训学校。
* 文件名称： Glb_putstring.c

* 内容摘要：
*     本文件实现关于控制输入的功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "..\\Glb_putstring\\Glb_putstring.h"

int glb_putString(char acStr[],char start,char end,int iMaxLen,int iPutType)
{
	  int k = 0;
	  switch(iPutType)// 1、输入字母 2、输入数字
       {
	     case 1:
               k = Control_input1(acStr,iMaxLen);
			   break;
	     case 2:
			   k = Control_input2(acStr,start,end,iMaxLen);
			   break;
		  default :
			   break;

       }
	      return k;
}




int Control_input1(char acStr[],int iMaxLen)//输入字符或汉字
{
     char t,y = 0;
  	 int  i;
	 i = 0;
    if (iMaxLen <= 10)
 {
     t = getch();
     while (i == 0 || t != 13) // 判断输入字符的合法性
	{
		 if (i>0 && t==8)
		{
			printf("\b \b"); //删除字符
			i--;
		}

		 else if(((t>='a'&&t<='z')||(t>='A'&&t<='Z')) && i < iMaxLen)// 是否为字母且位数有没有超
		{
		     if(iMaxLen == 1)
			 {
			   if (t=='y'||t=='n')// 选择时
			   {
			   y = t;
			   printf("%c",y);
			   i++;
			   }

			 }
			 else
			 {
				acStr[i]=t;
				printf("%c",acStr[i]);
				i++;
			}
		}

		   t=getch();
}
           if (iMaxLen != 1)
           {
		    acStr[i] = '\0';
           }

}
        else
		{
            fflush(stdin);
		    gets(acStr);// 输入汉字
		}

        return (y);// 返回y或n
}




int Control_input2(char acStr[],char start,char end,int iMaxLen)//输入数字
{
         char t;
	     int i,n,k;
	     n = i = 0;
		 if (acStr != NULL&&acStr[0] != 0)// 菜编号和台桌号递增
		 {
			 k = strlen(acStr);
			 for (;acStr[i] != '\0';i++)
			 n = n*10+acStr[i] - 48;// 字符转化成数字
			 n = n+1;               // 数字加一
			 for(i=k-1;i>=0;i--)
			 {
				 acStr[i] = (n%10 + 48);// 数字再转化成字符
				 n = n/10;
			 }
                 acStr[k] = '\0';
		         return 0;
		 }

		t=getch();
	    while (i == 0 || t != 13)
	{
		if (t == 27&&acStr != NULL)
		{
			strcpy(acStr,"0");
			return 0;
		}
		if(i>0 && t==8)// 删除键
		{
			printf("\b \b");
			i--;
		}

		else  if ((t>=start && t<=end) && i<iMaxLen)// 输入范围的合法性判断
	{
		  if (iMaxLen == 6)	// 密码输入，暗文显示
		{
		    acStr[i]=t;
			printf("%c",'*');
			i++;
		}
        else if (iMaxLen == 1)// 界面功能数字的选择
        {
		  n = t-48;
		  printf("%d",n);
		  i++;
        }
		   else
		   {
			 acStr[i]=t; // 编号输入，存放在acStr中
			 printf("%c",t);
			 i++;
		   }
   }

		   t=getch();
}

		  if (iMaxLen == 1)
		  {
		    return n;//返回一个数字，用来功能选择
		  }
		  else
		  {
		    acStr[i] = '\0';
		    for (i=0;acStr[i]!='\0';i++)
			n = n*10+acStr[i]-48;// 字符转化成int型
		    return n;//返回int型的数据，编号输入
		  }

}


