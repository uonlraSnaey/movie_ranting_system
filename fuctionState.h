
typedef struct Movie {
	char m_name[20];         //��Ӱ����
	char m_number[20];       //��Ӱ���
	int m_year;              //��Ӱ��ӳ���
	int m_music;             //���ֵ÷�
	int m_visual;            //��Ч�÷�
	int m_story;             //����÷�
	int m_display;          //�ݳ��÷�
	int m_totalScore;        //�ܵ÷�
	int m_rankScore;         //����
	bool m_qualifiedScore;   //�жϵ�Ӱ�ڱ�

	struct Movie* next;    //?1?70?1?78    
}Mov;

//0-1 ��¼��ʽ����Ա�����û�
//void log_in();
//0-1  ��������       
void Load_data(Mov* pHead);

//0-2.  ��ҳ��
void Home_page()
{
	system("cls");

	printf("           ____________________________\n");
	printf("          |                            |\n");
	printf("          |      2023 ��Ӱ����ϵͳ     |\n");
	printf("          |____________________________|\n");
	printf("          |       1.¼���Ӱ��Ϣ       |\n");
	printf("          |       2.�޸ĵ�Ӱ��Ϣ       |\n");
	printf("          |       3.ɾ����Ӱ           |\n");
	printf("          |       4.��ѯ��Ӱ��Ϣ       |\n");
	printf("          |       5.�鿴��Ӱ����       |\n");
	printf("          |       6.��ʾȫ����Ϣ       |\n");
	printf("          |       7.�浵               |\n");
	printf("          |       8.�˳�               |\n");
	printf("          |____________________________|\n");
	printf(" ------powered by Jiang Junfeng (kasensama)-----\n");
	printf("|                                              |\n");
	printf("|              Notice:                         |\n");
	printf("|          1.����ֻ��Ϊ����                    |\n");
	printf("|          2.��Ӱ��Ų�����ʮλ��һ��Ϊ��λ��  |\n");
	printf("|          3.����Ϊ�ٷ��ƶȣ��ܷ�Ϊ400         |   \n");
	printf("|          4.�������˳�����������ݴ浵ʧ��    |\n");
	printf("|______________________________________________|\n");
}

//0-3����ѡ��    
void Select_fuction(Mov* pHead);

//1-1.¼����Ϣ
void Input_new_movie(Mov* pHead);
//1-2. �жϿڱ�
void Judge_score(Mov* movie);
//1-3. ��β����
void Tail_add_node(Mov* pHead, Mov* new1);

//2-1. �ҵ�ϣ���޸���Ϣ�ĵ�Ӱ
void Search_movie_toChange(Mov* pHead);
//2-2. �޸���Ϣѡ��
void Change_information_selection(Mov* movie);
//2-3. �޸ĳɼ� 
void Change_score(Mov* movie);

//3.ɾ����Ӱ  
void Delete_movie(Mov* pHead);

//4-1. ��ѯ��Ӱ�����Ϣ
void Search_movie(Mov* pHead);
//4-2.  ��ӡ��Ӱ��Ϣ
void Show_movieInformation(Mov* movie);

//5-1. ѡ����������
void Rank_kindSelect(Mov* pHead);
//5-2. ������Ҫ���������
Mov* Build_rankYear(Mov* pHead, int rankYear);
//5-3. ��������������    
void Rank_subjectSelect(Mov* pHead);
//5-4. ����
void Rank_byScore(Mov* pHead, int subject);


//6-1. ��ӡȫ����Ϣ
void Show_all_selection(Mov* pHead);
//6-2. ��ӡ�ڱ��ϲ�ĵ�Ӱ�����ף�
void Show_all_unqualified_movie(Mov* pHead);
//6-3. ��ӡȫ����Ӱ��Ϣ 
void Show_all_movie(Mov* pHead);

//7. ����
void Save_data(Mov* pHead);

