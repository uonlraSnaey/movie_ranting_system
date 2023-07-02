
typedef struct Movie {
	char m_name[20];         //电影名称
	char m_number[20];       //电影序号
	int m_year;              //电影上映年份
	int m_music;             //音乐得分
	int m_visual;            //视效得分
	int m_story;             //剧情得分
	int m_display;          //演出得分
	int m_totalScore;        //总得分
	int m_rankScore;         //排名
	bool m_qualifiedScore;   //判断电影口碑

	struct Movie* next;    //?1?70?1?78    
}Mov;

//0-1 登录方式管理员或者用户
//void log_in();
//0-1  加载数据       
void Load_data(Mov* pHead);

//0-2.  主页面
void Home_page()
{
	system("cls");

	printf("           ____________________________\n");
	printf("          |                            |\n");
	printf("          |      2023 电影评分系统     |\n");
	printf("          |____________________________|\n");
	printf("          |       1.录入电影信息       |\n");
	printf("          |       2.修改电影信息       |\n");
	printf("          |       3.删除电影           |\n");
	printf("          |       4.查询电影信息       |\n");
	printf("          |       5.查看电影排名       |\n");
	printf("          |       6.显示全部信息       |\n");
	printf("          |       7.存档               |\n");
	printf("          |       8.退出               |\n");
	printf("          |____________________________|\n");
	printf(" ------powered by Jiang Junfeng (kasensama)-----\n");
	printf("|                                              |\n");
	printf("|              Notice:                         |\n");
	printf("|          1.评分只能为整数                    |\n");
	printf("|          2.电影序号不超过十位（一般为四位）  |\n");
	printf("|          3.评分为百分制度，总分为400         |   \n");
	printf("|          4.非正常退出会造成新数据存档失败    |\n");
	printf("|______________________________________________|\n");
}

//0-3功能选择    
void Select_fuction(Mov* pHead);

//1-1.录入信息
void Input_new_movie(Mov* pHead);
//1-2. 判断口碑
void Judge_score(Mov* movie);
//1-3. 结尾链接
void Tail_add_node(Mov* pHead, Mov* new1);

//2-1. 找到希望修改信息的电影
void Search_movie_toChange(Mov* pHead);
//2-2. 修改信息选项
void Change_information_selection(Mov* movie);
//2-3. 修改成绩 
void Change_score(Mov* movie);

//3.删除电影  
void Delete_movie(Mov* pHead);

//4-1. 查询电影相关信息
void Search_movie(Mov* pHead);
//4-2.  打印电影信息
void Show_movieInformation(Mov* movie);

//5-1. 选择排名方法
void Rank_kindSelect(Mov* pHead);
//5-2. 创建需要排名的年份
Mov* Build_rankYear(Mov* pHead, int rankYear);
//5-3. 按各项评分排名    
void Rank_subjectSelect(Mov* pHead);
//5-4. 排名
void Rank_byScore(Mov* pHead, int subject);


//6-1. 打印全部信息
void Show_all_selection(Mov* pHead);
//6-2. 打印口碑较差的电影（避雷）
void Show_all_unqualified_movie(Mov* pHead);
//6-3. 打印全部电影信息 
void Show_all_movie(Mov* pHead);

//7. 保存
void Save_data(Mov* pHead);

