
/************************************************************************
* 函数名称：int glb_putString(char acStr[],char start,char end,int iMaxLen,int iPutType)
* 功能描述：
*    控制输入函数
* 参数说明：
*    char acStr[]    存放输入的字符串
     char start      输入的最小数字
     char end        输入的最大数字
	 int iMaxLen     输入的最大位数
     int iPutType    输入字母或数字的参数 1为字母，2为数字
* 返回值：
*       整型数据
*************************************************************************/
int glb_putString(char acStr[],char start,char end,int iMaxLen,int iPutType);

/************************************************************************
* 函数名称：int Control_input1(char acStr[],int iMaxLen)
* 功能描述：
*         输入字母的函数
* 参数说明：
*    char acStr[]    存放输入的字符串
	 int iMaxLen     输入的最大位数
* 返回值：
*       整型数据
*************************************************************************/
int Control_input1(char acStr[],int iMaxLen);

/************************************************************************
* 函数名称：int Control_input2(char acStr[],char start,char end,int iMaxLen)
* 功能描述：
*         输入数字的函数
* 参数说明：
*    char acStr[]    存放输入的字符串
     char start      输入的最小数字
     char end        输入的最大数字  
	 int iMaxLen     输入的最大位数
* 返回值：
*       整型数据
*************************************************************************/
int Control_input2(char acStr[],char start,char end,int iMaxLen);

