#include <stdio.h>

/*
0首页 1工大校报 2招生信息 3人才招聘 4招标公告
5就业信息 6图书情报 7电子邮箱 8bbs论坛 9ftp
10财务查询 11校内通知 12各类信息 13校内简讯 14学校公文
15办公服务 16电话电邮 17网络导航 18部门主页 19学校oa
20校友总会 21中国大学 22网络服务 23学校简介 24历史沿革
25机构设置 26校区分布 27合作交流 28本专科 29研究生
30继续教育 31精品课程 32本科在线 33学术会议 34科研信息
35博士后 36学生科技 37可拓学 38网上党校 39学生工作
40团学视窗 41国防生 42网上问答 43学校新闻 44校内专题
45图片新闻 46校内报修 47mba教育中心 48普通话测试 49研究生招生
*/
char *name[50] = {
	"首页    ", "工大校报", "招生信息", "人才招聘", "招标公告",
		"就业信息", "图书情报", "电子邮箱", "bbs论坛 ", "ftp     ",
		"财务查询", "校内通知", "各类信息", "校内简讯", "学校公文",
		"办公服务", "电话电邮", "网络导航", "部门主页", "学校oa  ",
		"校友总会", "中国大学", "网络服务", "学校简介", "历史沿革",
		"机构设置", "校区分布", "合作交流", "本专科   ", "研究生   ",
		"继续教育", "精品课程", "本科在线", "学术会议", "科研信息",
		"博士后   ", "学生科技", "可拓学   ", "网上党校", "学生工作",
		"团学视窗", "国防生   ", "网上问答", "学校新闻", "校内专题",
		"图片新闻", "校内报修", "mba教育中心", "普通话测试", "研究生招生"};
	const double D = 0.85, N = 50;
	
	struct linkout
	{
		int links[50];
		int lkout, linkin;
		int num;
		double wucha;
		double pagepr;
	};
	
	int main()
	{
		int i, j, ok;
		struct linkout page50out[50];
		
		
		for(i = 0; i < 50; i++)
		{
			for(j = 0; j < 50; j++)
			{
				page50out[i].links[j] = 0;
			}
			page50out[i].lkout = 0;
			page50out[i].linkin = 0;
			page50out[i].wucha = 0;
			page50out[i].num = i;
			page50out[i].pagepr = 1;
		}
		
		for (i = 1; i < 50; i++)
			page50out[0].links[i] = 1;
		
		page50out[2].links[49] = 1;
		page50out[2].links[29] = 1;
		page50out[4].links[43] = 1;
		page50out[5].links[0] = 1;
		page50out[6].links[0] = 1;
		page50out[10].links[0] = 1;
		page50out[11].links[13] = 1;
		page50out[11].links[12] = 1;
		page50out[11].links[4] = 1;
		page50out[11].links[0] = 1;
		page50out[12].links[0] = 1;
		page50out[12].links[4] = 1;
		page50out[12].links[11] = 1;
		page50out[12].links[13] = 1;
		page50out[13].links[13] = 1;
		page50out[13].links[12] = 1;
		page50out[13].links[11] = 1;
		page50out[13].links[4] = 1;
		page50out[13].links[0] = 1;
		page50out[15].links[45] = 1;
		page50out[15].links[44] = 1;
		page50out[15].links[42] = 1;
		page50out[15].links[33] = 1;
		page50out[15].links[26] = 1;
		page50out[15].links[25] = 1;
		page50out[15].links[24] = 1;
		page50out[15].links[23] = 1;
		page50out[15].links[22] = 1;
		page50out[15].links[18] = 1;
		page50out[15].links[17] = 1;
		page50out[15].links[16] = 1;
		page50out[15].links[2] = 1;
		page50out[15].links[0] = 1;
		page50out[16].links[45] = 1;
		page50out[16].links[44] = 1;
		page50out[16].links[42] = 1;
		page50out[16].links[33] = 1;
		page50out[16].links[26] = 1;
		page50out[16].links[25] = 1;
		page50out[16].links[24] = 1;
		page50out[16].links[23] = 1;
		page50out[16].links[22] = 1;
		page50out[16].links[18] = 1;
		page50out[16].links[17] = 1;
		page50out[16].links[15] = 1;
		page50out[16].links[2] = 1;
		page50out[16].links[0] = 1;
		page50out[17].links[45] = 1;
		page50out[17].links[44] = 1;
		page50out[17].links[42] = 1;
		page50out[17].links[33] = 1;
		page50out[17].links[26] = 1;
		page50out[17].links[25] = 1;
		page50out[17].links[24] = 1;
		page50out[17].links[23] = 1;
		page50out[17].links[22] = 1;
		page50out[17].links[18] = 1;
		page50out[17].links[15] = 1;
		page50out[17].links[16] = 1;
		page50out[17].links[2] = 1;
		page50out[17].links[0] = 1;
		page50out[18].links[45] = 1;
		page50out[18].links[44] = 1;
		page50out[18].links[42] = 1;
		page50out[18].links[33] = 1;
		page50out[18].links[26] = 1;
		page50out[18].links[25] = 1;
		page50out[18].links[24] = 1;
		page50out[18].links[23] = 1;
		page50out[18].links[22] = 1;
		page50out[18].links[15] = 1;
		page50out[18].links[17] = 1;
		page50out[18].links[16] = 1;
		page50out[18].links[2] = 1;
		page50out[18].links[0] = 1;
		page50out[22].links[45] = 1;
		page50out[22].links[44] = 1;
		page50out[22].links[42] = 1;
		page50out[22].links[33] = 1;
		page50out[22].links[26] = 1;
		page50out[22].links[25] = 1;
		page50out[22].links[24] = 1;
		page50out[22].links[23] = 1;
		page50out[22].links[15] = 1;
		page50out[22].links[18] = 1;
		page50out[22].links[17] = 1;
		page50out[22].links[16] = 1;
		page50out[22].links[2] = 1;
		page50out[22].links[0] = 1;
		page50out[23].links[45] = 1;
		page50out[23].links[44] = 1;
		page50out[23].links[42] = 1;
		page50out[23].links[33] = 1;
		page50out[23].links[26] = 1;
		page50out[23].links[25] = 1;
		page50out[23].links[24] = 1;
		page50out[23].links[15] = 1;
		page50out[23].links[22] = 1;
		page50out[23].links[18] = 1;
		page50out[23].links[17] = 1;
		page50out[23].links[16] = 1;
		page50out[23].links[2] = 1;
		page50out[23].links[0] = 1;
		page50out[24].links[45] = 1;
		page50out[24].links[44] = 1;
		page50out[24].links[42] = 1;
		page50out[24].links[33] = 1;
		page50out[24].links[26] = 1;
		page50out[24].links[25] = 1;
		page50out[24].links[15] = 1;
		page50out[24].links[23] = 1;
		page50out[24].links[22] = 1;
		page50out[24].links[18] = 1;
		page50out[24].links[17] = 1;
		page50out[24].links[16] = 1;
		page50out[24].links[2] = 1;
		page50out[24].links[0] = 1;
		page50out[25].links[45] = 1;
		page50out[25].links[44] = 1;
		page50out[25].links[42] = 1;
		page50out[25].links[33] = 1;
		page50out[25].links[26] = 1;
		page50out[25].links[15] = 1;
		page50out[25].links[24] = 1;
		page50out[25].links[23] = 1;
		page50out[25].links[22] = 1;
		page50out[25].links[18] = 1;
		page50out[25].links[17] = 1;
		page50out[25].links[16] = 1;
		page50out[25].links[2] = 1;
		page50out[25].links[0] = 1;
		page50out[26].links[45] = 1;
		page50out[26].links[44] = 1;
		page50out[26].links[42] = 1;
		page50out[26].links[33] = 1;
		page50out[26].links[15] = 1;
		page50out[26].links[25] = 1;
		page50out[26].links[24] = 1;
		page50out[26].links[23] = 1;
		page50out[26].links[22] = 1;
		page50out[26].links[18] = 1;
		page50out[26].links[17] = 1;
		page50out[26].links[16] = 1;
		page50out[26].links[2] = 1;
		page50out[26].links[0] = 1;
		page50out[29].links[47] = 1;
		page50out[33].links[45] = 1;
		page50out[33].links[44] = 1;
		page50out[33].links[42] = 1;
		page50out[33].links[15] = 1;
		page50out[33].links[26] = 1;
		page50out[33].links[25] = 1;
		page50out[33].links[24] = 1;
		page50out[33].links[23] = 1;
		page50out[33].links[22] = 1;
		page50out[33].links[18] = 1;
		page50out[33].links[17] = 1;
		page50out[33].links[16] = 1;
		page50out[33].links[2] = 1;
		page50out[33].links[0] = 1;
		page50out[36].links[0] = 1;
		page50out[36].links[34] = 1;
		page50out[36].links[40] = 1;
		page50out[38].links[0] = 1;
		page50out[40].links[0] = 1;
		page50out[41].links[0] = 1;
		page50out[42].links[45] = 1;
		page50out[42].links[44] = 1;
		page50out[42].links[15] = 1;
		page50out[42].links[33] = 1;
		page50out[42].links[26] = 1;
		page50out[42].links[25] = 1;
		page50out[42].links[24] = 1;
		page50out[42].links[23] = 1;
		page50out[42].links[22] = 1;
		page50out[42].links[18] = 1;
		page50out[42].links[17] = 1;
		page50out[42].links[16] = 1;
		page50out[42].links[2] = 1;
		page50out[42].links[0] = 1;
		page50out[43].links[0] = 1;
		page50out[43].links[1] = 1;
		page50out[44].links[45] = 1;
		page50out[44].links[15] = 1;
		page50out[44].links[42] = 1;
		page50out[44].links[33] = 1;
		page50out[44].links[26] = 1;
		page50out[44].links[25] = 1;
		page50out[44].links[24] = 1;
		page50out[44].links[23] = 1;
		page50out[44].links[22] = 1;
		page50out[44].links[18] = 1;
		page50out[44].links[17] = 1;
		page50out[44].links[16] = 1;
		page50out[44].links[2] = 1;
		page50out[44].links[0] = 1;
		page50out[45].links[15] = 1;
		page50out[45].links[44] = 1;
		page50out[45].links[42] = 1;
		page50out[45].links[33] = 1;
		page50out[45].links[26] = 1;
		page50out[45].links[25] = 1;
		page50out[45].links[24] = 1;
		page50out[45].links[23] = 1;
		page50out[45].links[22] = 1;
		page50out[45].links[18] = 1;
		page50out[45].links[17] = 1;
		page50out[45].links[16] = 1;
		page50out[45].links[2] = 1;
		page50out[45].links[0] = 1;
		
		for(i = 0; i < 50; i++)
		{
			for(j = 0; j < 50; j++)
			{
				if (page50out[i].links[j] == 1)
					page50out[i].lkout++;
			}
		}
        for(i = 0; i < 50; i++)
		{
			for(j = 0; j < 50; j++)
			{
				if (page50out[j].links[i] == 1)
					page50out[i].linkin++;
			}
		}
		
		double midsum = 0, oldpr;
		for(ok = 0; ok != 1;)
		{
			for(i = 0; i < 50; i++)
			{
				midsum = 0;
				for(j = 0; j < 50; j++)
				{
					if ((i != j) && (page50out[j].links[i] == 1))
					{
						midsum += (page50out[j].pagepr / page50out[j].lkout);
					}
				}
				oldpr = page50out[i].pagepr;
				page50out[i].pagepr = (midsum * D + (1-D)/N);
				page50out[i].wucha = (oldpr - page50out[i].pagepr);
				if (page50out[i].wucha < 0)
					page50out[i].wucha = (0 - page50out[i].wucha);
			}
			for(ok = 1, i = 0; i < 50 && ok == 1; i++)
			{
				if (page50out[i].wucha > 0.0001)
					ok = 0;
			}
		}
		
		struct linkout fororder[50], fortemp;
		for (i = 0; i < 50; i++)
			fororder[i] = page50out[i];
		
		for (i = 0; i < 50; i++)
		{
			for (j = 0; j < 49; j++)
			{
				if (fororder[j].pagepr < fororder[j+1].pagepr)
				{
					fortemp = fororder[j];
					fororder[j] = fororder[j+1];
					fororder[j+1] = fortemp;
				}
			}
		}
		
        puts("邻接矩阵\n");
		for (i = 0; i < 50; i ++)
			printf("v_%d: %s\t", i+1, name[page50out[i].num]);
		puts("\n");
		for (i = 0; i < 50; i++)
		{
			for (j = 0; j < 50; j++)
				printf("%d", page50out[i].links[j]);
			puts("");
		}
		
		puts("\n\n出入度:\n");
        for(i = 1; i < 50; i++)
		{
			printf("%s\t\tout: %d\t\tin: %d\n", name[page50out[i].num], page50out[i].lkout, page50out[i].linkin);
		}
		
		puts("\n\n据pr排名:\n");
		int no = 1;
		printf("%s\t\tpr: %lf\t\tno: %d\n", name[fororder[0].num], fororder[0].pagepr, no);
		for(i = 1; i < 50; i++)
		{
			if (fororder[i].pagepr < fororder[i-1].pagepr)
				no++;
			printf("%s\t\tpr: %lf\t\tno: %d\n", name[fororder[i].num], fororder[i].pagepr, no);
        }
        puts("\n图书馆主页排名第26");
		
		return 0;
}
