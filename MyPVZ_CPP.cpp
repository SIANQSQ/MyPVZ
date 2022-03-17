#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include<iostream>
#include<mmsystem.h>

#define KEY_DOWN(vKey) ((GetAsyncKeyState(vKey) & 0x8000) ? 1:0)

#define jssl 50

#pragma comment(lib,"Winmm.lib")	

using namespace std;

IMAGE  IMG_commenzombie, IMG_background, IMG_pea,IMG_icepea,IMG_firepea;
IMAGE  IMG_wdss_z0, IMG_wdss_y0, IMG_wdss_z1, IMG_wdss_y1, IMG_wdss_z2, IMG_wdss_y2, IMG_wdss_z3, IMG_wdss_y3, IMG_wdss_z4, IMG_wdss_y4;
IMAGE  IMG_wdss_z5, IMG_wdss_y5, IMG_wdss_z6, IMG_wdss_y6, IMG_wdss_z7, IMG_wdss_y7, IMG_wdss_z8, IMG_wdss_y8, IMG_wdss_z9, IMG_wdss_y9;
IMAGE  IMG_wdss_z10, IMG_wdss_y10, IMG_wdss_z11, IMG_wdss_y11, IMG_wdss_z12, IMG_wdss_y12; 
IMAGE  IMG_commenzombie0, IMG_commenzombie1, IMG_commenzombie2, IMG_commenzombie3, IMG_commenzombie4, IMG_commenzombie5, IMG_commenzombie6, IMG_commenzombie7, IMG_commenzombie8, IMG_commenzombie9, IMG_commenzombie10,IMG_commenzombie11, IMG_commenzombie12, IMG_commenzombie13, IMG_commenzombie14, IMG_commenzombie15, IMG_commenzombie16, IMG_commenzombie17, IMG_commenzombie18, IMG_commenzombie19, IMG_commenzombie20, IMG_commenzombie21;
int ZombieLable = 1;
int ZombieNum = 0;
int PeaNum = 0;
int pnglable = 0;
DWORD* dst = NULL;
DWORD* draw = NULL;
DWORD* src = NULL;
int picture_width = -1;
int picture_height = -1;
int graphHeight = -1;
int dstX = -1;
int graphWidth = -1;

int sa;
int dr;
int dg;
int db;
int sr;
int sg;
int sb;
int srcX;

int wdhb = 15;
int hjs = 3;

TCHAR blank[] = _T("    ");
TCHAR tc_commenpea[] = _T("当前豌豆类型：普通豌豆   消耗1个豌豆币！");
TCHAR tc_icepea[] = _T("当前豌豆类型：寒冰豌豆   消耗2个豌豆币！");
TCHAR tc_firepea[] = _T("当前豌豆类型：火焰豌豆   消耗3个豌豆币！");

void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
{


	// 变量初始化
	dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	draw = GetImageBuffer();
	src = GetImageBuffer(picture); //获取picture的显存指针
	picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{

			srcX = ix + iy * picture_width; //在显存里像素的角标
			sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			sg = ((src[srcX] & 0xff00) >> 8);   //G
			sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{

				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				dr = ((dst[dstX] & 0xff0000) >> 16);
				dg = ((dst[dstX] & 0xff00) >> 8);
				db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
				| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
				| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
int MapHeight(int dy)
{
	switch (dy)
	{
	case 0:
		return 100;

	case 1:
		return 280;

	case 2:
		return 500;

	case 3:
		return 660;

	case 4:
		return 860;


	}

}
class myplant
{
public:

	myplant(int x, int y, int speed, int hp, int direction)
	{
		X = x;
		Y = y;
		Speed = speed;
		HP = hp;
		Direction = direction;
	}

	void MoveUp() { if(this->Y>6) Y -= Speed; }
	void MoveDown() { if (this->Y <950) Y += Speed; }
	void MoveLeft() { if(this->X>6) X -= Speed; Direction = 0; }
	void MoveRight() { if(this->X<980) X += Speed; Direction = 1; }

	int GetX() { return X; }
	int GetY() { return Y; }
	int GetDirection() { return Direction; }
	int GetPeaclass() { return Peaclass; }

	void Print()
	{
		if (Direction == 0)
		{
			switch (pnglable)
			{
			case 0: drawAlpha(&IMG_wdss_z0, X, Y); pnglable++; break;
			case 1: drawAlpha(&IMG_wdss_z1, X, Y); pnglable++; break;
			case 2: drawAlpha(&IMG_wdss_z2, X, Y); pnglable++; break;
			case 3: drawAlpha(&IMG_wdss_z3, X, Y); pnglable++; break;
			case 4: drawAlpha(&IMG_wdss_z4, X, Y); pnglable++; break;
			case 5: drawAlpha(&IMG_wdss_z5, X, Y); pnglable++; break;
			case 6: drawAlpha(&IMG_wdss_z6, X, Y); pnglable++; break;
			case 7: drawAlpha(&IMG_wdss_z7, X, Y); pnglable++; break;
			case 8: drawAlpha(&IMG_wdss_z8, X, Y); pnglable++; break;
			case 9: drawAlpha(&IMG_wdss_z9, X, Y); pnglable++; break;
			case 10: drawAlpha(&IMG_wdss_z10, X, Y); pnglable++; break;
			case 11: drawAlpha(&IMG_wdss_z11, X, Y); pnglable++; break;
			case 12: drawAlpha(&IMG_wdss_z12, X, Y); pnglable=0; break;
			}
			
		}  //left 
		else
		{
			switch (pnglable)
			{
			case 0: drawAlpha(&IMG_wdss_y0, X, Y); pnglable++; break;
			case 1: drawAlpha(&IMG_wdss_y1, X, Y); pnglable++; break;
			case 2: drawAlpha(&IMG_wdss_y2, X, Y); pnglable++; break;
			case 3: drawAlpha(&IMG_wdss_y3, X, Y); pnglable++; break;
			case 4: drawAlpha(&IMG_wdss_y4, X, Y); pnglable++; break;
			case 5: drawAlpha(&IMG_wdss_y5, X, Y); pnglable++; break;
			case 6: drawAlpha(&IMG_wdss_y6, X, Y); pnglable++; break; 
			case 7: drawAlpha(&IMG_wdss_y7, X, Y); pnglable++; break;
			case 8: drawAlpha(&IMG_wdss_y8, X, Y); pnglable++; break;
			case 9: drawAlpha(&IMG_wdss_y9, X, Y); pnglable++; break;
			case 10: drawAlpha(&IMG_wdss_y10, X, Y); pnglable++; break; 
			case 11: drawAlpha(&IMG_wdss_y11, X, Y); pnglable++; break;
			case 12: drawAlpha(&IMG_wdss_y12, X, Y); pnglable = 0; break;
			}
		}//right
	}
	void CommenPea()
	{
		Peaclass = 0;
		cout << "change commen pea class!" << endl;
	}
	void IcePea()
	{
		Peaclass = 1;
		cout << "change ice pea class!" << endl;
	}
	void FirePea()
	{
		Peaclass = 2;
		cout << "change fire pea class!" << endl;
	}

private:
	int X;
	int Y;
	int Direction;
	int Peaclass;
	int Speed;
	int HP;
};
class commenzombie
{
public:
	commenzombie() :X(-1), Y(-1),Speed(0),HP(-1),Active(false){};
	void SetZombies(float x,float y,int hp,float speed)
	{
		X = x;
		Y = y;
		HP = hp;
		Active = false;
		Speed = speed;
		pnglablezombie = 0;
	}

	void CZActive() { Active = true; cout << "Zombie -> Active Successfully!" << endl; }
	void Die() { if (Active == true) { Active = false; ZombieNum--; wdhb += 7; } }
	void Move() { if (Active == true) X -= Speed; }
	void SlowDown() { Speed = 0.0000305; }
	void TakeCommonDamage() { HP -= 20; }
	void TakeFireDamage() { HP -= 50; }
	void UnSlowDown() { Speed = 0.001; }   
	int GetX() { return X; }
	int GetY() { return Y; }
	bool GetAct() { return Active; }
	int GetHP() { return HP; }
	void Print()
	{
		if (Active == true)
		{
			switch (pnglablezombie)
			{
			case 0: drawAlpha(&IMG_commenzombie0, X, Y); pnglablezombie++; break;
			case 1: drawAlpha(&IMG_commenzombie1, X, Y); pnglablezombie++; break;
			case 2: drawAlpha(&IMG_commenzombie2, X, Y); pnglablezombie++; break;
			case 3: drawAlpha(&IMG_commenzombie3, X, Y); pnglablezombie++; break;
			case 4: drawAlpha(&IMG_commenzombie4, X, Y); pnglablezombie++; break;
			case 5: drawAlpha(&IMG_commenzombie5, X, Y); pnglablezombie++; break;
			case 6: drawAlpha(&IMG_commenzombie6, X, Y); pnglablezombie++; break;
			case 7: drawAlpha(&IMG_commenzombie7, X, Y); pnglablezombie++; break;
			case 8: drawAlpha(&IMG_commenzombie8, X, Y); pnglablezombie++; break;
			case 9: drawAlpha(&IMG_commenzombie9, X, Y); pnglablezombie++; break;
			case 10: drawAlpha(&IMG_commenzombie10, X, Y); pnglablezombie++; break;
			case 11: drawAlpha(&IMG_commenzombie11, X, Y); pnglablezombie++; break;
			case 12: drawAlpha(&IMG_commenzombie12, X, Y); pnglablezombie++; break;
			case 13: drawAlpha(&IMG_commenzombie13, X, Y); pnglablezombie++; break;
			case 14: drawAlpha(&IMG_commenzombie14, X, Y); pnglablezombie++; break;
			case 15: drawAlpha(&IMG_commenzombie15, X, Y); pnglablezombie++; break;
			case 16: drawAlpha(&IMG_commenzombie16, X, Y); pnglablezombie++; break;
			case 17: drawAlpha(&IMG_commenzombie17, X, Y); pnglablezombie++; break;
			case 18: drawAlpha(&IMG_commenzombie18, X, Y); pnglablezombie++; break;
			case 19: drawAlpha(&IMG_commenzombie19, X, Y); pnglablezombie++; break;
			case 20: drawAlpha(&IMG_commenzombie20, X, Y); pnglablezombie++; break;
			case 21: drawAlpha(&IMG_commenzombie21, X, Y); pnglablezombie=0; break;
			}
		}
	}

private:
	int X;
	int Y;
	float Speed;
	int HP;
	bool Active;
	bool Slow;
	int pnglablezombie;
};
myplant wdss(300, 300, 5, 100, 1);
commenzombie ptjs[1001];
class pea 
{
public:
	void SetupPea()
	{
		X = wdss.GetX();
		Y = wdss.GetY();
		PeaClass = wdss.GetPeaclass();
		if (PeaClass == 0) wdhb -= 1;
		else if (PeaClass == 1) wdhb -= 2;
		else wdhb -= 3;
		Direction = wdss.GetDirection();
		Active = true;
	}

	void Die()
	{
		Active = false;
	}
	void move()
	{
		if (Active == true)
		{
			if (Direction == 0) X -= 10;
			else X += 10;
		}
	}

	void Attack(commenzombie &js)
	{
		switch (this->PeaClass)
		{
		case 0:
			js.TakeCommonDamage();
			break;
		case 1:
			js.TakeCommonDamage();
			js.SlowDown();
			break;
		case 2:
			js.TakeFireDamage();
			js.UnSlowDown();
		}
	}

	void Print()
	{
		if (Active == true)
		{
			if (PeaClass == 0) drawAlpha(&IMG_pea, X, Y);
			if (PeaClass == 1) drawAlpha(&IMG_icepea, X, Y);
			if (PeaClass == 2) drawAlpha(&IMG_firepea, X, Y);
		}
	}

	bool GetAct() { return Active; }
	int GetX() { return X; }
	int GetY() { return Y; }

private:
	int X;
	int Y;
	int PeaClass;
	int Direction;
	bool Active;
	
};
pea p[2000];

void SetupZombies()
{
	for(int t=1;t<=jssl;t++)
	{
		srand(time(NULL) + t * t);
		int dy = MapHeight(rand() % 5);
		ptjs[t].SetZombies(935, dy, 100,0.001);
		cout << "Zombies" << t << "  ->    setup successfully" << endl;
	}
}
void ActiveZombie()
{
	if (ZombieNum < hjs)
	{
		ptjs[ZombieLable].CZActive();
		ZombieNum++;
		ZombieLable++;
	}
}
void ZombiesMove()
{
	for (int t = 1; t <= jssl; t++)
	{
		if (ptjs[t].GetHP() <= 0) ptjs[t].Die();
		ptjs[t].Move();
	}
}
void PeaMove()
{
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		p[pn].move();
	}
}
void KBInput() {

	if (_kbhit())         
	{
		int msg = _getch();
		switch (msg)
		{
		case 87:
		case 119:           //  W 按下
		{
			wdss.MoveUp();
			break;
		}

		case 83:          //S 按下
		case 115:
		{
			wdss.MoveDown();
			break;
		}

		case 68:              //D 按下
		case 100:
		{
			wdss.MoveRight();
			break;
		}

		case 97:             //A 按下
		case 65:
		{
			wdss.MoveLeft();
			break;
		}
		
		case 120:        //ZombiesDie
		{
			ptjs[1].Die();
			break;
		}

		case 74:
		case 106:
		{
			PeaNum++;
			p[PeaNum].SetupPea();
			break;
		}

		case 113:           //Q按下，更改豌豆类型
		case 81:
		{
			int c = wdss.GetPeaclass();
			if (c == 0) { wdss.IcePea(); }
			else if (c == 1) wdss.FirePea();
			else wdss.CommenPea();
			break;
		}
		}
	}
}

void OutPutPeaClass()
{
	int c = wdss.GetPeaclass();
	switch (c)
	{
	case 0:
		outtextxy(0, 0, tc_commenpea);
		break;
	case 1:
		outtextxy(0, 0, tc_icepea);
		break;
	case 2:
		outtextxy(0, 0, tc_firepea);
		break;
	}
}

void Fresh()
{
	BeginBatchDraw();
	TCHAR t[20];
	_stprintf_s(t, _T("豌豆还剩 %d 个"), wdhb);
	putimage(0, 0, &IMG_background);
	outtextxy(0, 20, t);
	OutPutPeaClass();
	wdss.Print();
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		p[pn].Print();
	}
	for (int t = 1; t <= jssl; t++)
	{
		ptjs[t].Print();
	}
	Sleep(50);
	EndBatchDraw();
	
}
void Setup()
{
	initgraph(1000, 1000); 
	mciSendString("open 开始.mp3 alias ksmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString("play ksmusic repeat", NULL, 0, NULL);  // 循环播放
	cleardevice();
	setfillcolor(GREEN);
	setbkcolor(GREEN);
	loadimage(&IMG_background, _T("background1.jpg"), 1000, 1000);
	loadimage(&IMG_wdss_z0, _T("wdss_z0.png")); 
	loadimage(&IMG_wdss_y0, _T("wdss_y0.png"));
	loadimage(&IMG_wdss_z1, _T("wdss_z1.png"));
	loadimage(&IMG_wdss_y1, _T("wdss_y1.png"));
	loadimage(&IMG_wdss_z2, _T("wdss_z2.png"));
	loadimage(&IMG_wdss_y2, _T("wdss_y2.png"));
	loadimage(&IMG_wdss_z3, _T("wdss_z3.png"));
	loadimage(&IMG_wdss_y3, _T("wdss_y3.png"));
	loadimage(&IMG_wdss_z4, _T("wdss_z4.png"));
	loadimage(&IMG_wdss_y4, _T("wdss_y4.png"));
	loadimage(&IMG_wdss_z5, _T("wdss_z5.png"));
	loadimage(&IMG_wdss_y5, _T("wdss_y5.png"));
	loadimage(&IMG_wdss_z6, _T("wdss_z6.png"));
	loadimage(&IMG_wdss_y6, _T("wdss_y6.png"));
	loadimage(&IMG_wdss_z7, _T("wdss_z7.png"));
	loadimage(&IMG_wdss_y7, _T("wdss_y7.png"));
	loadimage(&IMG_wdss_z8, _T("wdss_z8.png"));
	loadimage(&IMG_wdss_y8, _T("wdss_y8.png"));
	loadimage(&IMG_wdss_z9, _T("wdss_z9.png"));
	loadimage(&IMG_wdss_y9, _T("wdss_y9.png"));
	loadimage(&IMG_wdss_z10, _T("wdss_z10.png"));
	loadimage(&IMG_wdss_y10, _T("wdss_y10.png"));
	loadimage(&IMG_wdss_z11, _T("wdss_z11.png"));
	loadimage(&IMG_wdss_y11, _T("wdss_y11.png"));
	loadimage(&IMG_wdss_z12, _T("wdss_z12.png"));
	loadimage(&IMG_wdss_y12, _T("wdss_y12.png"));

	loadimage(&IMG_commenzombie0, _T("czb0.png"));
	loadimage(&IMG_commenzombie1, _T("czb1.png"));
	loadimage(&IMG_commenzombie2, _T("czb2.png"));
	loadimage(&IMG_commenzombie3, _T("czb3.png"));
	loadimage(&IMG_commenzombie4, _T("czb4.png"));
	loadimage(&IMG_commenzombie5, _T("czb5.png"));
	loadimage(&IMG_commenzombie6, _T("czb6.png"));
	loadimage(&IMG_commenzombie7, _T("czb7.png"));
	loadimage(&IMG_commenzombie8, _T("czb8.png"));
	loadimage(&IMG_commenzombie9, _T("czb9.png"));
	loadimage(&IMG_commenzombie10, _T("czb10.png"));
	loadimage(&IMG_commenzombie11, _T("czb11.png"));
	loadimage(&IMG_commenzombie12, _T("czb12.png"));
	loadimage(&IMG_commenzombie13, _T("czb13.png"));
	loadimage(&IMG_commenzombie14, _T("czb14.png"));
	loadimage(&IMG_commenzombie15, _T("czb15.png"));
	loadimage(&IMG_commenzombie16, _T("czb16.png"));
	loadimage(&IMG_commenzombie17, _T("czb17.png"));
	loadimage(&IMG_commenzombie18, _T("czb18.png"));
	loadimage(&IMG_commenzombie19, _T("czb19.png"));
	loadimage(&IMG_commenzombie20, _T("czb20.png"));
	loadimage(&IMG_commenzombie21, _T("czb21.png"));

	loadimage(&IMG_pea, _T("pea.png"));
	loadimage(&IMG_icepea, _T("icepea.png"));
	loadimage(&IMG_firepea, _T("firepea.png"));

	putimage(0, 0, &IMG_background);
}
void GameOver()
{
	if (wdhb < 0)
	{
		cout << "Game Over!" << endl;
		EndBatchDraw();
		closegraph();

	}
	for (int t = 1; t <= jssl; t++)
	{
		if (ptjs[t].GetX() == 0)
		{
			cout << "Game Over!" << endl;
			ptjs[t].Die();
			EndBatchDraw();
			closegraph();
		}
	}
}
void ShotOn()
{
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		if (p[pn].GetX() <= 5 || p[pn].GetX() >= 990) p[pn].Die();
		for (int t = 1; t <= ZombieLable; t++)
		{
			if (p[pn].GetAct() == true && ptjs[t].GetAct() == true)
			{
				if (p[pn].GetY() > ptjs[t].GetY() && abs(p[pn].GetY() - ptjs[t].GetY()) < 150)
				{
					if (abs(p[pn].GetX() - ptjs[t].GetX())<8)
					{
						p[pn].Attack(ptjs[t]);
						//cout << "Zombie ->" << t << "HP->   " << ptjs[t].GetHP() << endl;
						p[pn].Die();
					}
				}
			}
		}
	}
}

void ZombiesBoost()
{
	if (ZombieLable == 7)
	{
		hjs = 8;
		mciSendString("close ksmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
		mciSendString("open 高潮.mp3 alias gcmusic", NULL, 0, NULL);//打开背景音乐
		mciSendString("play gcmusic repeat", NULL, 0, NULL);  // 循环播放
	}
}

int main()
{
	Setup();
	SetupZombies();
	while (1)
	{
		ActiveZombie();
		ZombiesBoost();
		ZombiesMove();
		PeaMove();
		KBInput();
		ShotOn();
		Fresh();
		GameOver();
	}
}
