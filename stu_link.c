#include"link.h"

/****************************************************
*	实现功能：输出所有学生信息						*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void output_stu_node(STU_PNODE stu_head)
{
	system("clear");

	if(NULL == stu_head->next)
	{
		printf("\n学生信息为空．\n");
		return;
	}
	printf("\n\t 学号   姓名                   性别     年龄   班级     数学成绩       语文成绩        C语言成绩         总分\n");
	
	STU_PNODE p = stu_head->next;
	while(p != NULL)
	{
		printf("\n\t%6d\t%-22s\t%2c\t%3d\t%2d\t%6.2f\t\t%6.2f\t\t%6.2f\t\t%6.2f\n"
			,p->stu_data.id
			,p->stu_data.name
			,p->stu_data.sex
			,p->stu_data.age
			,p->stu_data.class_num
			,p->stu_data.math_score
			,p->stu_data.chinese_score
			,p->stu_data.c_program_score
			,p->stu_data.total_score
			);
		p = p->next;
	}
}

/****************************************************
*	实现功能：学生信息输出排序						*
*	输入参数：学生链表和排序方式					*
*	返回值  ：无									*
****************************************************/
void stu_bubble_sort(STU_PNODE stu_head, int select)
{
	if(NULL == stu_head->next)
	{
		return;
	}
	
	STU_PNODE tail = NULL;

	STU_PNODE p, pre, temp;
	while(stu_head->next != tail)
	{
		p = stu_head->next;
		pre = stu_head;
		while(p->next != tail)
		{
			int flag = 0;
			switch(select)
			{
				case SORT_BY_ID:
								if(p->stu_data.id > p->next->stu_data.id)
									flag = 1;
								break;
				case SORT_BY_TOTAL_SCORE:
								if(p->stu_data.total_score < p->next->stu_data.total_score)
									flag = 1;
								break;
				case SORT_BY_MATH:
								if(p->stu_data.math_score < p->next->stu_data.math_score)
									flag = 1;
								break;
				case SORT_BY_CHINESE:
								if(p->stu_data.chinese_score < p->next->stu_data.chinese_score)
									flag = 1;
								break;
				case SORT_BY_C_PROGRAM:
								if(p->stu_data.c_program_score < p->next->stu_data.c_program_score)
									flag = 1;
								break;
			}
			
			if(flag)
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
*	实现功能：删除学生单个节点						*
*	输入参数：学生节点								*
*	返回值  ：无									*
****************************************************/
void delete_stu_node(STU_PNODE stu_head)
{
	if(NULL == stu_head->next)
	{
		printf("学生信息为空，没有数据可删．\n");
		return;
	}
	STU_PNODE p = stu_head->next;
	stu_head->next = p->next;
	
	free(p);

}


/****************************************************
*	实现功能：查找学生节点							*
*	输入参数：学生链表和学生id						*
*	返回值  ：找到节点的前一个节点或NULL			*
****************************************************/
STU_PNODE find_stu_pre_node(STU_PNODE stu_head, int stu_id)
{
	if(NULL == stu_head->next)
	{
		return NULL;
	}
	STU_PNODE q = stu_head;
	STU_PNODE p = stu_head->next;
	while(p != NULL)
	{
		if(p->stu_data.id == stu_id)
		{
			return q;
		}
		q = q->next;
		p = p->next;
	}
	return NULL;
}

/****************************************************
*	实现功能：头插法将学生节点插入链表				*
*	输入参数：学生链表和学生结构体数据				*
*	返回值  ：无									*
****************************************************/
void head_insert_stu_node(STU_PNODE stu_head, STU stu_data)
{
	STU_PNODE temp = create_stu_node(stu_data);
	temp->next = stu_head->next;
	stu_head->next = temp;
//	printf("头插入完成．\n");
}

/****************************************************
*	实现功能：创建学生节点							*
*	输入参数：学生结构体数据						*
*	返回值  ：新创建的学生节点						*
****************************************************/
STU_PNODE create_stu_node(STU stu_data)
{
	STU_PNODE temp = (STU_PNODE)malloc(sizeof(STU_NODE));
	temp->stu_data = stu_data;
	temp->next = NULL;
//	printf("节点创建完成．\n");
	return temp;
}

