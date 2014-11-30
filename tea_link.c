#include"link.h"

/****************************************************
*	实现功能：输出所有教师信息						*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void output_tea_node(TEA_PLINK tea_head)
{
	system("clear");
	
	if(NULL == tea_head->next)
	{
		printf("\n老师信息为空．\n");
		return;
	}
	printf("\n教师信息：");
	printf("\n\t工号    姓名                 性别       年龄            学科                  辅导员\n");

	TEA_PLINK p = tea_head->next;
	while(p != NULL)
	{
		printf(
			"\n\t%4d\t%-22s%-c\t\t%3d\t\t%-9s\t\t%-4s\n"
			,p->tea_data.id
			,p->tea_data.name
			,p->tea_data.sex
			,p->tea_data.age
			,p->tea_data.subject
			,p->tea_data.head_teacher
			);
		p = p->next;
	}
}

/****************************************************
*	实现功能：删除教师单个节点						*
*	输入参数：教师节点								*
*	返回值  ：无									*
****************************************************/
void delete_tea_node(TEA_PLINK tea_head)
{
	if(NULL == tea_head->next)
	{
		return;
	}
	TEA_PLINK p = tea_head->next;
	tea_head->next = p->next;
	
	free(p);
}

/****************************************************
*	实现功能：头插法将教师节点插入链表				*
*	输入参数：教师链表和教师结构体数据				*
*	返回值  ：无									*
****************************************************/
void head_insert_tea_node(TEA_PLINK tea_head, TEA tea_data)
{
	TEA_PLINK temp = create_tea_node(tea_data);
	temp->next = tea_head->next;
	tea_head->next = temp;
//	printf("头插入完成．\n");
}

/****************************************************
*	实现功能：创建教师节点							*
*	输入参数：教师结构体数据						*
*	返回值  ：新创建的教师节点						*
****************************************************/
TEA_PLINK create_tea_node(TEA tea_data)
{
	TEA_PLINK temp = (TEA_PLINK)malloc(sizeof(TEA_LINK));
	temp->tea_data = tea_data;
	temp->next = NULL;
//	printf("节点创建完成．\n");
	return temp;
}

/****************************************************
*	实现功能：教师信息输出排序						*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void bubble_sort_tea(TEA_PLINK tea_head)
{
	if(NULL == tea_head->next)
	{
	//	printf("\n教师信息为空，不能排序．\n");
		return;
	}
	
	TEA_PLINK tail = NULL;
	TEA_PLINK p, pre, temp;
	while(tea_head->next != tail)
	{
		p = tea_head->next;
		pre = tea_head;
		while(p->next != tail)
		{
			if(p->tea_data.id > p->next->tea_data.id)
			{
				temp = p->next;
				pre->next = p->next;
				p->next = p->next->next;
				pre->next->next = p;
				p = temp;
			}
			pre = pre->next;
			p = p->next;
		}
		tail = p;		//注意！不是：p = tail;
	}
}

/****************************************************
*	实现功能：查找教师节点							*
*	输入参数：教师链表和教师id						*
*	返回值  ：找到节点的前一个节点或NULL			*
****************************************************/
TEA_PLINK find_tea_pre_node(TEA_PLINK tea_head, int tea_id)
{
	if(NULL == tea_head->next)
	{
		return NULL;
	}
	TEA_PLINK q = tea_head;
	TEA_PLINK p = tea_head->next;
	while(p != NULL)
	{
		if(p->tea_data.id == tea_id)
		{
			return q;
		}
		q = q->next;
		p = p->next;
	}
	return NULL;
}

