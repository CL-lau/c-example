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
		printf("�ڴ����ʧ��\n");
		return 0;
	}

    printf("������ѧ��:");
    scanf("%d",&pstu->num);
    if(search_student_info(pstu->num)!=NULL)
    {
	    printf("��ѧ���Ѿ�����Ϣ���С�\n");
	    return 0;
    }

    printf("����������:");
    getchar();
	gets(pstu->name);
	printf("�������Ա�:");
	scanf("%s",&pstu->sex);
	printf("����������:");
	scanf("%d",&pstu->age);
	printf("������Ӣ��ɼ�:");
	scanf("%d",&pstu->english);
	printf("��������ѧ�ɼ�:");
	scanf("%d",&pstu->math);
	printf("������C���Գɼ�:");
	scanf("%d",&pstu->clang);
	printf("���������˼�ɼ�:");
	scanf("%d",&pstu->macs);
	pstu->average=(pstu->english+pstu->math+pstu->clang+pstu->macs)/4;
	pstu->total=(pstu->english+pstu->math+pstu->clang+pstu->macs);

	//ÿ�δ�ѧ����Ϣ����ͷ������
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
		printf("������ѧ��Ϊ%d��ѧ��\n",num);
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
		printf("������ѧ��Ϊ%d��ѧ��\n",num);
		return 0;
	}
	printf("1.���� 2.�Ա� 3.���� 4.Ӣ��ɼ� 5.��ѧ�ɼ� 6.C���Գɼ� 7.���˼�ɼ�\n");
	printf("��ѡ���޸���Ϣ:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("�������µ�����:");
			getchar();
			gets(pstu->name);
			break;
		case 2:
			printf("�������µ��Ա�:");
			scanf("%s",pstu->sex);
			break;
		case 3:
			printf("�������µ�����:");
			scanf("%d",&pstu->age);
			break;
		case 4:
			printf("�������µ�Ӣ��ɼ�:");
			scanf("%d",&pstu->english);
			break;
		case 5:
			printf("�������µ���ѧ�ɼ�:");
			scanf("%d",&pstu->math);
			break;
		case 6:
			printf("�������µ�C���Գɼ�:");
			scanf("%d",&pstu->clang);
			break;
		case 7:
			printf("�����������˼�ɼ�:");
			scanf("%d",&pstu->macs);
			break;
		default:
		    printf("�밴��ʾҪ������\n");
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
		printf("ѧ��Ϊ:%d,����:%s,ƽ���ɼ�:%d\n",pstu->num,pstu->name,pstu->average);
		pstu=pstu->next;
	}
}

void display_total()
{
	student_info *pstu;
	pstu=student_list->next;
	while(pstu)
	{
		printf("ѧ��Ϊ:%d,����:%s,�ܳɼ�:%d\n",pstu->num,pstu->name,pstu->total);
		pstu=pstu->next;
	}
}

void display_student_info()
{
	student_info *pstu;
	pstu=student_list->next;
	printf("����ѧ����Ϣ����\n");
	printf("ѧ��\t����\t�Ա�\t����\tӢ��\t��ѧ\t�����\t���˼\tƽ����\t�ܷ�\n");
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
		printf("���ļ�ʧ��\n");
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
		printf("���ļ�ʧ��\n");
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
