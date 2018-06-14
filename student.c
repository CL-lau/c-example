#include "student.h"
#include<stdio.h>
#include<string.h>
#include<malloc.h>

void init_student_info_list()
{
	student_list = (student_info *)malloc(sizeof(student_info));
	student_list->next = NULL;
}

int student_list_empty()
{
	return student_list->next==NULL;
}

int add_student_info()
{
	student_info *pstu=(student_info *)malloc(sizeof(student_info));
	if(pstu==NULL)
	{
		printf("内存分配失败\n");
		return 0;
	}

    printf("请输入学号:");
    scanf("%d",&pstu->num);
    if(search_student_info(pstu->num)!=NULL)
    {
	    printf("该学号已经在信息表中。\n");
	    return 0;
    }

    printf("请输入姓名:");
    getchar();
	gets(pstu->name);
	printf("请输入性别:");
	scanf("%s",&pstu->sex);
	printf("请输入年龄:");
	scanf("%d",&pstu->age);
	printf("请输入英语成绩:");
	scanf("%d",&pstu->english);
	printf("请输入数学成绩:");
	scanf("%d",&pstu->math);
	printf("请输入C语言成绩:");
	scanf("%d",&pstu->clang);
	printf("请输入马克思成绩:");
	scanf("%d",&pstu->macs);
	pstu->average=(pstu->english+pstu->math+pstu->clang+pstu->macs)/4;
	pstu->total=(pstu->english+pstu->math+pstu->clang+pstu->macs);

	//每次从学生信息链表头部插入
	pstu->next =student_list->next;
	student_list->next = pstu;
	return 1;
}

int delete_student_info(int num)
{
	student_info *pstu;
	student_info *qstu;
	if(search_student_info(num)==NULL)
	{
		printf("不存在学号为%d的学生\n",num);
		return 0;
	}
	pstu=student_list->next;
	qstu=student_list;
	while(pstu->num!=num)
	{
		qstu=pstu;
		pstu=pstu->next;
	}
	qstu->next=pstu->next;
	free(pstu);
	return 1;
}

int modify_student_info(int num)
{
	int choice;
	student_info *pstu =search_student_info(num);
	if(pstu==NULL)
	{
		printf("不存在学号为%d的学生\n",num);
		return 0;
	}
	printf("1.姓名 2.性别 3.年龄 4.英语成绩 5.数学成绩 6.C语言成绩 7.马克思成绩\n");
	printf("请选择修改信息:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("请输入新的姓名:");
			getchar();
			gets(pstu->name);
			break;
		case 2:
			printf("请输入新的性别:");
			scanf("%s",pstu->sex);
			break;
		case 3:
			printf("请输入新的年龄:");
			scanf("%d",&pstu->age);
			break;
		case 4:
			printf("请输入新的英语成绩:");
			scanf("%d",&pstu->english);
			break;
		case 5:
			printf("请输入新的数学成绩:");
			scanf("%d",&pstu->math);
			break;
		case 6:
			printf("请输入新的C语言成绩:");
			scanf("%d",&pstu->clang);
			break;
		case 7:
			printf("请输入新马克思成绩:");
			scanf("%d",&pstu->macs);
			break;
		default:
		    printf("请按提示要求输入\n");
	}
	return 1;
}

student_info *search_student_info(int num)
{
	student_info *pstu;
	pstu = student_list->next;
	while(pstu&&pstu->num!=num)
	{
		pstu=pstu->next;
	}
	return pstu;
}

void display_average()
{
	student_info *pstu;
	pstu=student_list->next;
	while(pstu)
	{
		printf("学号为:%d,姓名:%s,平均成绩:%d\n",pstu->num,pstu->name,pstu->average);
		pstu=pstu->next;
	}
}

void display_total()
{
	student_info *pstu;
	pstu=student_list->next;
	while(pstu)
	{
		printf("学号为:%d,姓名:%s,总成绩:%d\n",pstu->num,pstu->name,pstu->total);
		pstu=pstu->next;
	}
}

void display_student_info()
{
	student_info *pstu;
	pstu=student_list->next;
	printf("所有学生信息如下\n");
	printf("学号\t姓名\t性别\t年龄\t英语\t数学\t计算机\t马克思\t平均分\t总分\n");
	while(pstu)
	{
		printf("%d\t",pstu->num);
		printf("%s\t",pstu->name);
		printf("%s\t",pstu->name);
		printf("%d\t",pstu->age);
		printf("%d\t",pstu->english);
		printf("%d\t",pstu->math);
		printf("%d\t",pstu->clang);
		printf("%d\t",pstu->macs);
		printf("%d\n",pstu->average);
		printf("%d\n",pstu->total);
		pstu=pstu->next; 
	}
}

int save_file()
{
	FILE *pfile;
	student_info *pstu;
	pfile =fopen("student.txt","wb");
	if(pfile==NULL)
	{
		printf("打开文件失败\n");
		return 0;
	}
	pstu=student_list->next;
	while(pstu)
	{
		fprintf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d%4d%4d",pstu->num,pstu->name,pstu->sex,pstu->age,pstu->english,pstu->math,pstu->clang,pstu->macs,pstu->average,pstu->total);
		pstu=pstu->next;
	}
	fclose(pfile);
	return 1;
}

int read_file()
{
	FILE *pfile;
	student_info *pstu;
	pfile=fopen("student.txt","rb");
	if(pfile==NULL)
	{
		printf("打开文件失败\n");
		return 0;
	}
	while(!feof(pfile))
	{
		pstu=(student_info *)malloc(sizeof(student_info));
		fscanf(pfile,"%5d%15s%9s%4d%4d%4d%4d%4d%4d%4d",&pstu->num,pstu->name,pstu->sex,&pstu->age,&pstu->english,&pstu->math,&pstu->clang,&pstu->macs,&pstu->average,&pstu->total);
		pstu->average=(pstu->english+pstu->math+pstu->clang+pstu->macs)/4;
		pstu->total=(pstu->english+pstu->math+pstu->clang+pstu->macs);
		pstu->next=student_list->next;
		student_list->next=pstu;
	}
	fclose(pfile);
	return 1;
}
