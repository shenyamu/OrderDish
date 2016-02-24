#ifndef _LIST_H_
#define _LIST_H_

struct List
{
	void * pData;// ������ָ��
	struct List * pNext;// �ṹ��ָ��
	
};
typedef struct List * pList;

/************************************************************************
* �������ƣ�pList List_init(void *data)
* ����������
*    ��������ʼ������
* ����˵����
*    void *data     ������ʼ������������
* ����ֵ��
*       ������������ĵ�ַ
*************************************************************************/
pList List_init(void *data);

/************************************************************************
* �������ƣ�void List_print(pList head,void (*pstr)(pList))
* ����������
*    �������ݴ�ӡ����
* ����˵����
*    pList head        Ҫ��ӡ������ͷָ�� 
     void (*pstr)(pList)   ���ݴ�ӡ�ĺ���ָ��
* ����ֵ��
*       ��
*************************************************************************/
void List_print(pList head,void (*pstr)(pList));

/************************************************************************
* �������ƣ�void List_add(pList head,void *data)
* ����������
*    ����������Ӻ���
* ����˵����
*    pList head       Ҫ���ӵ�����ͷָ��
     void *data       Ҫ���ӵ�����   
* ����ֵ��
*       ��
*************************************************************************/
void List_add(pList head,void *data);

/************************************************************************
* �������ƣ�int  List_count(pList head)
* ����������
*    �����������������
* ����˵����
*    pList head       Ҫ����������ͷָ��
* ����ֵ��
*       ���ؽ�����
*************************************************************************/
int  List_count(pList head);

/************************************************************************
* �������ƣ�void List_free(pList head);
* ����������
*    �����ͷź���
* ����˵����
*    pList head       Ҫ�ͷŵ�����ͷָ��
* ����ֵ��
*       ��
*************************************************************************/
void List_free(pList head);

#endif






