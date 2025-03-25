#include<iostream>
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int Score;
enum my
{
	WIDTH = 600,
	HEIGHT = 875,    //窗口高度和宽度
	BULLET_NUM = 15, //子弹数量
	ENEMY_NUM = 10,  //敌机数量
	BIG,
	SMALL
};
struct plane //飞机结构
{
	float x;
	float y;
	bool live;
	//是否存活
	int width;
	int height;
	int hp;
	int type;
	//敌机的类型
}role, bullet[BULLET_NUM], enemy[ENEMY_NUM];

IMAGE background;
IMAGE player[2];
IMAGE bull[2];
IMAGE img_enemy[2][2];
#pragma comment(lib,"MSIMG32.LIB")//windows自带的一个处理
inline void putimage1(int x, int y, IMAGE* img)//直接使用putimage函数的话
{//图片素材周围会有黑色框，于是我们自己写了一个putimage1函数，有进行透明度处理
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}
void loadimg()
{
	loadimage(&background, _T("images/background.png"));
	//加载背景图片
	loadimage(&player[0], _T("images/me1.png"));
	loadimage(&player[1], _T("images/me2.png"));
	//加载飞机图片
	loadimage(&bull[0], _T("images/bullet1.png"));
	loadimage(&bull[1], _T("images/bullet2.png"));
	//加载子弹图片
	loadimage(&img_enemy[0][0], _T("images/enemy1.png"));
	loadimage(&img_enemy[0][1],_T( "images/enemy2.png"));
	loadimage(&img_enemy[1][0], _T("images/enemy3_n1.png"));
	loadimage(&img_enemy[1][1], _T("images/enemy3_n2.png"));
	//加载敌机图片
}
void enemyHp(int i)
{
	int flag = rand() % 10;
	if (flag >= 0 && flag <= 2)
	{
		enemy[i].type = BIG;
		enemy[i].hp = 3;
		enemy[i].width = 169;
		enemy[i].height = 258;
	}
	else
	{
		enemy[i].type = SMALL;
		enemy[i].hp = 1;
		enemy[i].width = 57;
		enemy[i].height = 43;
	}
}
void gameInit()
{
	loadimg();
	role.x = WIDTH / 2;
	role.y = HEIGHT - 120;
	role.live = true;

	for (int i = 0; i < BULLET_NUM; i++)
	{
		bullet[i].x = 0;
		bullet[i].y = 0;
		bullet[i].live = false;
	}
	//初始化子弹
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i].live = false;
		enemyHp(i);
	}
	//初始化敌机
}
void gamedraw()
{
	putimage(0, 0, &background);
	putimage1(role.x, role.y, &player[0]);
	putimage1(role.x, role.y, &player[1]);
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i].live)
		{
			putimage1(bullet[i].x, bullet[i].y, &bull[0]);
			putimage1(bullet[i].x, bullet[i].y, &bull[1]);
		}
		//只有存活才进行绘制子弹
	}
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
		{
			if (enemy[i].type == BIG)
			{
				putimage1(enemy[i].x, enemy[i].y, &img_enemy[1][0]);
				putimage1(enemy[i].x, enemy[i].y, &img_enemy[1][1]);
			}
			else
			{
				putimage1(enemy[i].x, enemy[i].y, &img_enemy[0][0]);
				putimage1(enemy[i].x, enemy[i].y, &img_enemy[0][1]);
			}
		}
	}
	//绘制敌机

	//计分表
	settextcolor(WHITE);
	settextstyle(25, 0, _T("宋体"));
	TCHAR scoreStr[20];
	_stprintf_s(scoreStr, _T("得分: %d"), Score);
	outtextxy(10, 10, scoreStr);
}
//游戏的绘制函数
void createbullet()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (!bullet[i].live)
		{
			bullet[i].x = role.x + 60;
			bullet[i].y = role.y;
			bullet[i].live = true;
			break;
		}
	}
}
//创建子弹
void BulletMove(int speed)
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i].live)
		{
			bullet[i].y -= speed;
			if (bullet[i].y < 0)
			{
				bullet[i].live = false;
				//使子弹飞出屏幕后可以重新发射
			}
		}
	}
}
//子弹的移动
void playerMove(float speed)
{
#if 0
	if (_kbhit())
	{
		char key = _getch();
		switch (key)
		{
		case 'w':
		case 'W':
			role.y -= speed;
			break;
		case 's':
		case 'S':
			role.y += speed;
			break;
		case 'a':
		case 'A':
			role.x -= speed;
			break;
		case 'd':
		case 'D':
			role.x += speed;
			break;
		}
	}
#elif 1
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (role.y > 0)
		{
			role.y -= speed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (role.y < HEIGHT - 126)
		{
			role.y += speed;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (role.x > -51)
		{
			role.x -= speed;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (role.x < WIDTH - 51)
		{
			role.x += speed;
		}
	}
#endif
	static DWORD t1 = 0, t2 = 0;
	if (GetAsyncKeyState(VK_SPACE) && t2 - t1 > 100)
	{
		createbullet();
		t1 = t2;
		//创建一个子弹
	}
	t2 = GetTickCount();
	//防止子弹连续发射
}
//玩家的移动
void createEnemy()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live)
		{
			enemy[i].live = true;
			enemy[i].x = rand() % (WIDTH - 60);
			enemy[i].y = 0;
			enemyHp(i);
			break;
		}
	}
	//产生敌机
}
//创建敌机
void enemyMove(int speed)
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i].live)
		{
			enemy[i].y += speed;
			if (enemy[i].y > HEIGHT)
			{
				enemy[i].live = false;
			}
		}
	}
}
//敌机的移动
bool Timer(int ms, int id)
{
	static DWORD t[10];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}
//定时器
void playPlane()
{
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (!enemy[i].live)
			continue;
		for (int k = 0; k < BULLET_NUM; k++)
		{
			if (!bullet[k].live)
				continue;
			if (bullet[k].x > enemy[i].x && bullet[k].x<enemy[i].x + enemy[i].width && bullet[k].y>enemy[i].y && bullet[k].y < enemy[i].y + enemy[i].height)
			{
				bullet[k].live = false;
				enemy[i].hp--;
			}
		}
		if (enemy[i].hp <= 0)
		{
			enemy[i].live = false;
			Score += 10;
		}
	}
}
//子弹打敌机

int main()
{
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	//创建一个窗口
	gameInit();
	//双缓冲绘图
	BeginBatchDraw();
	while (1) {
		gamedraw();
		FlushBatchDraw();
		playerMove(0.3);
		BulletMove(2);
		if (Timer(1500, 0))
		{
			createEnemy();
		}
		if (Timer(20, 2))
		{
			enemyMove(1);
		}
		playPlane();
		//Sleep(0);
	}
	EndBatchDraw();
	return 0;
}