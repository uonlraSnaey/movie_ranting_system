#include <windows.h>
//0-0

//0-1.��������
void Load_data(Mov* pHead)
{
	int loading = 4;
	
	while (loading--)  //��²������ڸ�ɶ nvn
	{
		system("cls");
		for (int i = 0; i < loading; i++)
		{	
			printf("---������---");
			printf(" >>>>>>");Sleep(1000);
		}
		printf("\n");
		
	}
	int number = 0;//��¼��ǰ��Ҫ���ֵĵ�Ӱ����
	Mov* pMove = pHead;
	FILE* fp = fopen("movie.txt", "r");

	if (fp == NULL)
	{
		printf("==	 ==               =                       = = = = = =        ==            = \n");
		printf("==	==              == ==                     =                  =  =          = \n");
		printf("=== ==             ==   ==                    =                  =    =        = \n");
		printf("====              ==     ==                   =                  =     =       = \n");
		printf("====             ==  ==   ==         S        = = = = = =        =      =      = \n");
		printf("==  ==          ==         ==                 =                  =       =     = \n");
		printf("==   ==        ==           ==                =                  =         =   = \n");
		printf("==    ==      ==             ==               = = = = = =        =           = = \n");

		                                //https://github.com/uonlraSnaey

		printf(" _______________________________\n");
		printf("|  ��ǰ��ʱû�е�Ӱ��Ϣ.         |\n");
		printf("|  �� enter ��ʼ  ...           |\n");
		printf("|_______________________________|\n");
		getchar();
		return;
	}
	while (1)
	{
		Mov* newMovie = (Mov*)malloc(sizeof(Mov));
		if (fscanf(fp, "%s\t %s\t %d\t %d\t %d\t %d\t %d\t %d\n",
			newMovie->m_name, newMovie->m_number,
			& newMovie->m_year, &newMovie->m_music,
			& newMovie->m_visual, &newMovie->m_story,
			& newMovie->m_display, &newMovie->m_totalScore,
			& newMovie->m_totalScore) == EOF)
		{

			free(newMovie);
			break;
		}
		number++;
		Judge_score(newMovie);
		newMovie->next = NULL;
		pMove->next = newMovie;
		pMove = pMove->next;
	}

	printf(" _______________________________________\n");
	printf("|              -�������-                |\n");
	printf("|  ��ǰϵͳ�Ѿ�¼�� %3d  ����Ӱ��Ϣ      |\n", number);
	printf("|        �� enter ����ϵͳ               |\n");
	printf("|________________________________________|\n");
	getchar();
}

//0-3 ѡ�����
void Select_fuction(Mov* pHead)
{
	int select = 0;
	while (1)
	{
		int N = 0;
		Home_page();

		while(scanf("%d",&select)==0 || select==0 || select>8)
		{
			getchar();
			printf("��������ȷ��ϵͳ������ţ�1 - 8��:");
		}

		switch (select)
		{
		case 1://¼���Ӱ��Ϣ
			Input_new_movie(pHead);
			break;
		case 2://ɾ����Ӱ
			Search_movie_toChange(pHead);
			getchar();
			break;
		case 3: //��ѯĳ����Ӱ��Ϣ
			Delete_movie(pHead);
			break;
		case 4://��ӡ��Ӱ��������Ϣ
			Search_movie(pHead);
			getchar();
			break;
		case 5://��ѯ��Ӱ����
			Rank_kindSelect(pHead);
			getchar();
			break;
		case 6://��ʾϵͳ������Ϣ
			Show_all_selection(pHead);
			getchar();
			break;
		case 7://����
			Save_data(pHead);//������������������������������
			getchar();
			break;
		case 8://�˳�ϵͳ
			Save_data(pHead);//�汣����
			exit(0);
			break;
		default:
			break;
		}
	}
}
//1-1. �����Ӱ��Ϣ
void Input_new_movie(Mov* pHead)
{
	int N;
	printf("�������ֵĵ�Ӱ����:\n");
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		system("cls");

		Mov* newMovie = (Mov*)malloc(sizeof(Mov));
		memset(newMovie, 0, sizeof(Mov));
		newMovie->next = NULL;

		printf("��Ӱ����:");
		scanf("%s", newMovie->m_name);
		printf("���:");
		while(scanf("%s",&newMovie->m_number)==0 || strlen(newMovie->m_number)>10)
		{
			getchar();
			printf("ERROR������������!\n");
			printf("��Ӱ���:");
		}
		printf("���:");
		scanf("%d", &newMovie->m_year);
		printf("���ֵ÷�:");
		while(scanf("%d",&newMovie->m_music)==0 || newMovie->m_music>100)
		{
			getchar();
			printf("ERROR������������!\n");
			printf("���ֵ÷�:");
		}
		printf("��Ч�÷�:");
		while(scanf("%d",&newMovie->m_visual)==0 || newMovie->m_visual>100)
		{
			getchar();
			printf("ERROR������������!\n");
			printf("��Ч�÷�:");
		}
		printf("����÷�:");
		while(scanf("%d",&newMovie->m_story)==0 || newMovie->m_story>100)
		{
			getchar();
			printf("ERROR������������!\n");
			printf("����÷�:");
		}
		printf("�ݳ��÷�:");
		while(scanf("%d",&newMovie->m_display)==0 || newMovie->m_display>100)
		{
			getchar();
			printf("ERROR������������!\n");
			printf("�ݳ��÷�:");
		}
		newMovie->m_totalScore = newMovie->m_music + newMovie->m_visual + newMovie->m_story + newMovie->m_display;
		newMovie->m_rankScore = 0;
		Judge_score(newMovie);//�жϿڱ�
		getchar();

		Tail_add_node(pHead, newMovie);
		printf("�ɹ�¼��������Ϣ!\n");
		getchar();
	}
}
//1-2.�жϿڱ��û�
void Judge_score(Mov* movie)
{
	int cnt = 0;// ���� < 60 ����Ŀ
	cnt = (movie->m_music < 60) + (movie->m_visual < 60)\
		+ (movie->m_story < 60) + (movie->m_display < 60);
	if (cnt >= 2)
		movie->m_qualifiedScore = false;
	else
		movie->m_qualifiedScore = true;
}
//1-3.��β��������
void Tail_add_node(Mov* pHead, Mov* new1)
{
	Mov* pMove = pHead;
	while (pMove->next)
	{
		pMove = pMove->next;
	}
	pMove->next = new1;
}

//2-1.�ҵ�Ҫ�޸����ݵĵ�Ӱ
void Search_movie_toChange(Mov* pHead)
{
	system("cls");

	int ifSelect=1;
	while(ifSelect)
	{
		system("cls");
		printf("ѡ���޸ĵ�Ӱ��Ϣ��;��:\n");
		printf(" ______________\n");
		printf("|   1.����     |\n");
		printf("|   2.���     |\n");
		printf("|______________|\n");
		printf("|3.�鿴ȫ����Ϣ |\n");
		printf("|   4.����     |\n");
		printf("|______________|\n");

		Mov* pMove = pHead;
		int selectWay;//ѡ����ҷ�ʽ
		while(scanf("%d",&selectWay)==0 || selectWay==0 || selectWay>4)
		{
			getchar();
			printf("��������ȷ�Ĳ���;��:");
		}

		switch (selectWay)
		{
		case 1://�0�0����
			char name[20];
			printf("����:");
			scanf("%s", name);
			while (pMove->next)
			{
				pMove = pMove->next;
				if (!strcmp(name, pMove->m_name))
				{
					Change_information_selection(pMove);
					return;
				}
			}
			break;
		case 2://�0�0���
			char number[20];
			printf("���:");
			scanf("%s", number);
			while (pMove->next)
			{
				pMove = pMove->next;
				if (!strcmp(number, pMove->m_number))
				{
					Change_information_selection(pMove);
					return;
				}
			}
			break;
		case 3://ȫ����Ϣ
			Show_all_movie(pHead);
			break;
		case 4:
			return ;
			break;
		default:
			break;
		}
		if(selectWay != 3)
		{
			getchar();
			printf("δ�ҵ���ѧ��,�޸Ĳ�����Ч\n");
			getchar();
		}
		printf("�Ƿ�Ҫ�����޸Ĳ���?[1-��  0-��]");
		scanf("%d",&ifSelect);
	}
}
//2-2.�޸���Ϣѡ��
void Change_information_selection(Mov* movie)
{
	system("cls");
	printf("�޸ĵ�Ӱ%s����һ����Ϣ:\n", movie->m_name);
	printf(" __________\n");
	printf("|1.����    |\n");
	printf("|2.���    |\n");
	printf("|3.���    |\n");
	printf("|4.�ɼ�    |\n");
	printf("|__________|\n");
	printf("|5.����    |\n");
	printf("|__________|\n");

	int select;
	while(scanf("%d",&select)==0 || select==0 || select>5)
	{
		getchar();
		printf("ERROR!,��������ȷ��ѡ�����:");
	}
	switch (select)
	{
	case 1:
		printf("ԭ�� %s,��Ϊ:", movie->m_name);
		char newName[20];
		scanf("%s", newName);
		strcpy(movie->m_name, newName);
		break;
	case 2:
		printf("ԭ���%s,��Ϊ:", movie->m_number);
		char newNumber[20];
		while(scanf("%s",newNumber)==0 || strlen(newNumber)>10)
		{
			getchar();
			printf("ERROR! ,���������룡!\n");
			printf("���:");
		}
		strcpy(movie->m_number, newNumber);
		break;
	case 3:
		printf("ԭ��ӳ��� %d,��Ϊ:", movie->m_year);
		scanf("%d", &movie->m_year);
		break;
	case 4:
		Change_score(movie);
		break;
	default:
		break;
	}
	if(select != 5)
	{
		printf("�޸ĳɹ�.\n");
		getchar();
	}
}
//2-3.�޸ĳɼ� 
void Change_score(Mov* movie)
{
	system("cls");
	int ret;
	printf("%s", movie->m_name);
	printf("���ֵ÷�:%d ,�Ƿ�Ҫ�޸�?\n[0-��;1-��]", movie->m_music);
	scanf("%d", &ret);
	while (ret)
	{
		printf("��Ϊ:");
		scanf("%d", &movie->m_music);
		if(movie->m_music > 100)
		{
			ret=1;
			printf("���������쳣,����������!\n");
		}else{
			ret=0;
		}
	}
	printf("��Ч�÷�:%d ,�Ƿ�Ҫ�޸�?\n[0-��;1-��]", movie->m_visual);
	scanf("%d", &ret);
	while (ret)
	{
		printf("��Ϊ:");
		scanf("%d", &movie->m_visual);
		if(movie->m_visual > 100)
		{
			ret=1;
			printf("���������쳣,����������!\n");
		}else{
			ret=0;
		}
	}
	printf("����÷�:%d ,�Ƿ�Ҫ�޸�?\n[0-��;1-��]", movie->m_story);
	scanf("%d", &ret);
	while (ret)
	{
		printf("��Ϊ:");
		scanf("%d", &movie->m_story);
		if(movie->m_story > 100)
		{
			ret=1;
			printf("���������쳣,����������!\n");
		}else{
			ret=0;
		}
	}
	printf("�ݳ��÷�:%d ,�Ƿ�Ҫ�޸�?\n[0-��;1-��]", movie->m_display);
	scanf("%d", &ret);
	while (ret)
	{
		printf("��Ϊ:");
		scanf("%d", &movie->m_display);
		if(movie->m_display > 100)
		{
			ret=1;
			printf("���������쳣,����������!\n");
		}else{
			ret=0;
		}
	}
	movie->m_totalScore = movie->m_music + movie->m_visual + movie->m_story + movie->m_display;
	Judge_score(movie);
	return;
}

//3.ɾ����Ӱ 
void Delete_movie(Mov* pHead)
{
	Mov* prev = NULL;//�ȴ�������ʱ��,����ָ��pMove��ǰһλ

	Mov* pMove = pHead;
	system("cls");

	printf("ͨ��ʲô;��ɾ����Ӱ:\n");
	printf(" ______________\n");
	printf("|   1.����     |\n");
	printf("|   2.���     |\n");
	printf("|______________|\n");
	printf("|3.�鿴ȫ������ |\n");
	printf("|   4.����     |\n");
	printf("|______________|\n");

	int searchWay;//ѡ�����򷽷�
	while(scanf("%d",&searchWay)==0 || searchWay==0 || searchWay>4)
	{
		getchar();
		printf("��������ȷ�Ĳ���;��:");
	}

	switch (searchWay)
	{
	case 1:
		char name[20];
		printf("����:");
		scanf("%s", name);
		while (pMove->next)
		{
			prev = pMove;
			pMove = pMove->next;
			if (!strcmp(name, pMove->m_name))
			{
				prev->next = pMove->next;
				printf("�ɹ�ɾ����Ӱ!");
				getchar();
				return;
			}
		}
		break;
	case 2:
		char number[20];
		printf("���:");
		scanf("%s", number);
		while (pMove->next)
		{
			pMove = pMove->next;
			if (!strcmp(number, pMove->m_number))
			{
				prev->next = pMove->next;
				printf("�ɹ�ɾ����Ӱ!");
				getchar();
				return;
			}
		}
		break;
	case 3:
		Show_all_movie(pHead);
		getchar();
		Delete_movie(pHead);
		break;
	default:
		break;
	}
	if(searchWay==1 || searchWay==2)
	{
		getchar();
		printf(" __________________________________\n");
		printf("|  ERROR,δ��¼�õ�Ӱ��Ϣ��ɾ��ʧ��  |\n");
		printf("|__________________________________|\n");
		getchar();
	}
}
//7. ����
void Save_data(Mov* pHead)
{
	FILE* fp;
	Mov* pMove = pHead;
	if ((fp = fopen("movie.txt", "w")) == NULL)
	{
		printf("�浵ʧ��");
	}
	else
	{
		while (pMove->next)
		{
			pMove = pMove->next;
			fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", pMove->m_name, \
				pMove->m_number, pMove->m_year, pMove->m_music, \
				pMove->m_visual, pMove->m_story, pMove->m_display, \
				pMove->m_totalScore);
		}
	}

	printf("�浵�ɹ�!nwn");
	getchar();
	fclose(fp);
}
