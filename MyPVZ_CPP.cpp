#include <Windows.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <mmsystem.h>
#include <fstream>
#include <cassert>
#include <tchar.h>
#include <stdarg.h>
#include <string>


#define KEY_DOWN(vKey) ((GetAsyncKeyState(vKey) & 0x8000) ? 1:0)
#define jssl 10000
#define lzjssl 10000
#define scjssl 10000

#define BROWNYELLOW     0x9CEBD3
#define BROWN           0x13458B

#pragma comment(lib,"Winmm.lib")	

using namespace std;

int CountLines(string filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename.c_str());//ios::in 表示以只读的方式读取文件
	if (ReadFile.fail())//文件打开失败:返回0
	{
		return 0;
	}
	else//文件存在
	{
		while (getline(ReadFile, tmp, 'x'))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}
string ReadLine(string filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename.c_str());
	lines = CountLines(filename);

	if (line <= 0)
	{
		return "Error 1: 行数错误，不能为0或负数。";
	}
	if (file.fail())
	{
		return "Error 2: 文件不存在。";
	}
	if (line > lines)
	{
		return "Error 3: 行数超出文件长度。";
	}
	while (getline(file, temp) && i < line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

int CountLinesWithoutX(string filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename.c_str());//ios::in 表示以只读的方式读取文件
	if (ReadFile.fail())//文件打开失败:返回0
	{
		return 0;
	}
	else//文件存在
	{
		while (getline(ReadFile, tmp))
		{
			n++;
		}
		ReadFile.close();
		return n;
	}
}
string ReadLineWithoutX(string filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename.c_str());
	lines = CountLinesWithoutX(filename);

	if (line <= 0)
	{
		return "Error 1: 行数错误，不能为0或负数。";
	}
	if (file.fail())
	{
		return "Error 2: 文件不存在。";
	}
	if (line > lines)
	{
		return "Error 3: 行数超出文件长度。";
	}
	while (getline(file, temp) && i < line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

int GetValue(string filename, int line)
{
	string val = ReadLine(filename, line);
	int OutPut = stoi(val);
	return OutPut;
}

IMAGE  IMG_Start,IMG_MainPage,IMG_PauseBG,IMG_QUIT;
IMAGE  IMG_commenzombie, IMG_background, IMG_pea, IMG_icepea, IMG_firepea0, IMG_firepea1, IMG_firepea00, IMG_firepea11;
IMAGE  IMG_sun, IMG_ZombiesWin,IMG_seedbank,IMG_seedbanklong;
IMAGE  IMG_wdss_z0, IMG_wdss_y0, IMG_wdss_z1, IMG_wdss_y1, IMG_wdss_z2, IMG_wdss_y2, IMG_wdss_z3, IMG_wdss_y3, IMG_wdss_z4, IMG_wdss_y4;
IMAGE  IMG_wdss_z5, IMG_wdss_y5, IMG_wdss_z6, IMG_wdss_y6, IMG_wdss_z7, IMG_wdss_y7, IMG_wdss_z8, IMG_wdss_y8, IMG_wdss_z9, IMG_wdss_y9;
IMAGE  IMG_wdss_z10, IMG_wdss_y10, IMG_wdss_z11, IMG_wdss_y11, IMG_wdss_z12, IMG_wdss_y12;
IMAGE  IMG_commenzombie0, IMG_commenzombie1, IMG_commenzombie2, IMG_commenzombie3, IMG_commenzombie4, IMG_commenzombie5, IMG_commenzombie6, IMG_commenzombie7, IMG_commenzombie8, IMG_commenzombie9, IMG_commenzombie10, IMG_commenzombie11, IMG_commenzombie12, IMG_commenzombie13, IMG_commenzombie14, IMG_commenzombie15, IMG_commenzombie16, IMG_commenzombie17, IMG_commenzombie18, IMG_commenzombie19, IMG_commenzombie20, IMG_commenzombie21;
IMAGE  IMG_lzzombie0, IMG_lzzombie1, IMG_lzzombie2, IMG_lzzombie3, IMG_lzzombie4, IMG_lzzombie5, IMG_lzzombie6, IMG_lzzombie7, IMG_lzzombie8, IMG_lzzombie9, IMG_lzzombie10, IMG_lzzombie11, IMG_lzzombie12, IMG_lzzombie13, IMG_lzzombie14, IMG_lzzombie15, IMG_lzzombie16, IMG_lzzombie17, IMG_lzzombie18, IMG_lzzombie19, IMG_lzzombie20 ;
IMAGE  kp_sfss, kp_jqwd, kp_sxss,kp_CherryBombCard , kp_CherryBombCardGray;
IMAGE  IMG_sfss_z0, IMG_sfss_y0, IMG_sfss_z1, IMG_sfss_y1, IMG_sfss_z2, IMG_sfss_y2, IMG_sfss_z3, IMG_sfss_y3, IMG_sfss_z4, IMG_sfss_y4, IMG_sfss_z5, IMG_sfss_y5, IMG_sfss_z6, IMG_sfss_y6, IMG_sfss_z7, IMG_sfss_y7, IMG_sfss_z8, IMG_sfss_y8, IMG_sfss_z9, IMG_sfss_y9, IMG_sfss_z10, IMG_sfss_y10, IMG_sfss_z11, IMG_sfss_y11, IMG_sfss_z12, IMG_sfss_y12, IMG_sfss_z13, IMG_sfss_y13, IMG_sfss_z14, IMG_sfss_y14;
IMAGE  IMG_jqwd_z0, IMG_jqwd_y0, IMG_jqwd_z1, IMG_jqwd_y1, IMG_jqwd_z2, IMG_jqwd_y2, IMG_jqwd_z3, IMG_jqwd_y3, IMG_jqwd_z4, IMG_jqwd_y4, IMG_jqwd_z5, IMG_jqwd_y5, IMG_jqwd_z6, IMG_jqwd_y6, IMG_jqwd_z7, IMG_jqwd_y7, IMG_jqwd_z8, IMG_jqwd_y8, IMG_jqwd_z9, IMG_jqwd_y9, IMG_jqwd_z10, IMG_jqwd_y10, IMG_jqwd_z11, IMG_jqwd_y11, IMG_jqwd_z12, IMG_jqwd_y12;
IMAGE  IMG_sxss_z0, IMG_sxss_y0, IMG_sxss_z1, IMG_sxss_y1, IMG_sxss_z2, IMG_sxss_y2, IMG_sxss_z3, IMG_sxss_y3, IMG_sxss_z4, IMG_sxss_y4, IMG_sxss_z5, IMG_sxss_y5, IMG_sxss_z6, IMG_sxss_y6, IMG_sxss_z7, IMG_sxss_y7, IMG_sxss_z8, IMG_sxss_y8, IMG_sxss_z9, IMG_sxss_y9, IMG_sxss_z10, IMG_sxss_y10, IMG_sxss_z11, IMG_sxss_y11, IMG_sxss_z12, IMG_sxss_y12, IMG_sxss_z13, IMG_sxss_y13, IMG_sxss_z14, IMG_sxss_y14, IMG_sxss_z15, IMG_sxss_y15;
IMAGE  IMG_czb_die0, IMG_czb_die1, IMG_czb_die2, IMG_czb_die3, IMG_czb_die4, IMG_czb_die5, IMG_czb_die6, IMG_czb_die7, IMG_czb_die8, IMG_czb_die9;
IMAGE  IMG_CB_0, IMG_CB_1, IMG_CB_2, IMG_CB_3, IMG_CB_4, IMG_CB_5, IMG_CB_6, IMG_CB_BOOM;
IMAGE  IMG_Almanac, IMG_AlmanacBig, IMG_Almanac_ZB00, IMG_Almanac_ZB01, IMG_Almanac_PT00, IMG_Almanac_PT01,IMG_Almanac_WD00,IMG_Almanac_WD01,IMG_Almanac_WF00, IMG_Almanac_WF01, IMG_Almanac_ZZ00, IMG_Almanac_ZZ01;
IMAGE  IMG_SCZB0, IMG_SCZB1, IMG_SCZB2, IMG_SCZB3, IMG_SCZB4, IMG_SCZB5, IMG_SCZB6, IMG_SCZB7, IMG_SCZB8, IMG_SCZB9, IMG_SCZB10, IMG_SCZB11, IMG_SCZB12, IMG_SCZB13, IMG_SCZB14, IMG_SCZB15, IMG_SCZB16, IMG_SCZB17, IMG_SCZB18, IMG_SCZB19, IMG_SCZB20, IMG_SCZB21, IMG_SCZB22;

ExMessage m;
const string pswd = "SUDO-DEBUG-2846579";
int setgame = 0;
int height = GetValue("Config.ini", 2);
int width = GetValue("Config.ini", 3);
int mapheight = GetValue("Config.ini", 4);
int DelayTime = GetValue("Config.ini", 5);
int GetCry = GetValue("Config.ini", 6);//打死x个僵尸可得到一个樱桃炸弹
int life = GetValue("Config.ini", 7);
int wdhb = GetValue("Config.ini", 8);
int hjs = GetValue("Config.ini", 9);
int lzhjs = GetValue("Config.ini", 10);
int schjs = GetValue("Config.ini", 11);
int sjs = GetValue("Config.ini", 21);
int CommenZombieSpeed = GetValue("Config.ini", 22);
int LuZhangZombieSpeed = GetValue("Config.ini", 23);
int ShaChuangZombieSpeed = GetValue("Config.ini", 24);
int ZWSD = GetValue("Config.ini", 25);
int WDSD = GetValue("Config.ini", 26);
int PTJSBlood = GetValue("Config.ini", 31);
int LZJSBlood = GetValue("Config.ini", 32);
int TWMJSBlood = GetValue("Config.ini", 33);
void GetSetKey()
{
	height = GetValue("Config.ini", 2);
	width = GetValue("Config.ini", 3);
	mapheight = GetValue("Config.ini", 4);
	DelayTime = GetValue("Config.ini", 5);
	GetCry = GetValue("Config.ini", 6);//打死x个僵尸可得到一个樱桃炸弹
	life = GetValue("Config.ini", 7);
	wdhb = GetValue("Config.ini", 8);
	hjs = GetValue("Config.ini", 9);
	lzhjs = GetValue("Config.ini", 10);
	schjs = GetValue("Config.ini", 11);
    //sjs = GetValue("Config.ini", 21);
	CommenZombieSpeed = GetValue("Config.ini", 22);
	LuZhangZombieSpeed = GetValue("Config.ini", 23);
	ShaChuangZombieSpeed = GetValue("Config.ini", 24);
	ZWSD = GetValue("Config.ini", 25);
	WDSD = GetValue("Config.ini", 26);
	PTJSBlood = GetValue("Config.ini", 31);
	LZJSBlood = GetValue("Config.ini", 32);
	TWMJSBlood = GetValue("Config.ini", 33);
}
int GetPeaClass = 0;
int Getsun = 0;
int Getsjs = 0;
int Getlife = 0;
int GetCherryNum = 0;
int ZombieLable = 1;
int LZZombieLable = 1;
int SCZombieLable = 1;
int ZombieNum = 0;
int LZZombieNum = 0;
int SCZombieNum = 0;
int PeaNum = 0;
int CherryBombNum = 0;
int CherryBombRemain = 0;
bool PickUpSFSS = false;
bool PickUpJQWD = false;
bool PickUpSXSS = false;
bool PickUpYTZD = false;
bool BoomSFSS = false;
bool BoomJQWD = false;
bool BoomSXSS = false;
bool BoomYTZD = false;
bool ExistYTZD = false;
bool PressPause = false;
bool gameover = false;
bool CursorOnAlmanac = false;
bool ClickAlmanac = false;
bool ToAlmanac = false;
bool GoBack = false;
bool GTSX = false;
TCHAR blank[] = _T("    ");
TCHAR tc_kill[] = _T("击杀僵尸");
TCHAR tc_wandouleixing[] = _T("豌豆类型          参数");
TCHAR tc_commenpea[] = _T("普通豌豆");
TCHAR tc_icepea[] = _T("寒冰豌豆");
TCHAR tc_firepea[] = _T("火焰豌豆");
TCHAR tc_shanghai10[] = _T("伤害 20");
TCHAR tc_jiansu[] = _T("减速");
TCHAR tc_shanghai50[] = _T("伤害 50");
TCHAR tc_shengming[] = _T("生命");
TCHAR tc_M[] = _T("图鉴 M");
TCHAR tc_E[] = _T("暂停 E");

int kx; //生成的卡牌的坐标 -双发豌豆
int ky;
int kz = 20;//-生成双发豌豆的僵尸lable
int jx;//生成的卡牌的坐标 -机枪豌豆
int jy;
int jz = 30;//-生成机枪豌豆的僵尸lable
int DIF = 0;
void OnGame();
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
{


	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{

			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{

				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
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
		return 0.01 * mapheight+100;
		break;

	case 1:
		return 0.20 * mapheight+100;
		break;

	case 2:
		return 0.40 * mapheight+100;
		break;

	case 3:
		return 0.60 * mapheight+100;
		break;

	case 4:
		return 0.79 * mapheight+100;
		break;
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
		ZWLX = 0;
		pnglable = 0;
		Peaclass = 0;
	}

	void MoveUp() { if (this->Y > 105) Y -= Speed; }
	void MoveDown() { if (this->Y < 0.85 * height) Y += Speed; }
	void MoveLeft() { if (this->X > 0.006 * width) X -= Speed; Direction = 0; }
	void MoveRight() { if (this->X < 0.91 * width) X += Speed; Direction = 1; }
	int GetX() { return X; }
	int GetY() { return Y; }
	int GetDirection() { return Direction; }
	int GetPeaclass() { return Peaclass; }
	void Print()
	{
		switch (ZWLX)
		{
		case 0:         //普通
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
				case 12: drawAlpha(&IMG_wdss_z12, X, Y); pnglable = 0; break;
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
			break;
		}

		case 1:           //双发
		{
			if (Direction == 0)
			{
				switch (pnglable)
				{
				case 0: drawAlpha(&IMG_sfss_z0, X, Y); pnglable++; break;
				case 1: drawAlpha(&IMG_sfss_z1, X, Y); pnglable++; break;
				case 2: drawAlpha(&IMG_sfss_z2, X, Y); pnglable++; break;
				case 3: drawAlpha(&IMG_sfss_z3, X, Y); pnglable++; break;
				case 4: drawAlpha(&IMG_sfss_z4, X, Y); pnglable++; break;
				case 5: drawAlpha(&IMG_sfss_z5, X, Y); pnglable++; break;
				case 6: drawAlpha(&IMG_sfss_z6, X, Y); pnglable++; break;
				case 7: drawAlpha(&IMG_sfss_z7, X, Y); pnglable++; break;
				case 8: drawAlpha(&IMG_sfss_z8, X, Y); pnglable++; break;
				case 9: drawAlpha(&IMG_sfss_z9, X, Y); pnglable++; break;
				case 10: drawAlpha(&IMG_sfss_z10, X, Y); pnglable++; break;
				case 11: drawAlpha(&IMG_sfss_z11, X, Y); pnglable++; break;
				case 12: drawAlpha(&IMG_sfss_z12, X, Y); pnglable++; break;
				case 13: drawAlpha(&IMG_sfss_z13, X, Y); pnglable++; break;
				case 14: drawAlpha(&IMG_sfss_z14, X, Y); pnglable = 0; break;
				}

			}  //left 
			else
			{
				switch (pnglable)
				{
				case 0: drawAlpha(&IMG_sfss_y0, X, Y); pnglable++; break;
				case 1: drawAlpha(&IMG_sfss_y1, X, Y); pnglable++; break;
				case 2: drawAlpha(&IMG_sfss_y2, X, Y); pnglable++; break;
				case 3: drawAlpha(&IMG_sfss_y3, X, Y); pnglable++; break;
				case 4: drawAlpha(&IMG_sfss_y4, X, Y); pnglable++; break;
				case 5: drawAlpha(&IMG_sfss_y5, X, Y); pnglable++; break;
				case 6: drawAlpha(&IMG_sfss_y6, X, Y); pnglable++; break;
				case 7: drawAlpha(&IMG_sfss_y7, X, Y); pnglable++; break;
				case 8: drawAlpha(&IMG_sfss_y8, X, Y); pnglable++; break;
				case 9: drawAlpha(&IMG_sfss_y9, X, Y); pnglable++; break;
				case 10: drawAlpha(&IMG_sfss_y10, X, Y); pnglable++; break;
				case 11: drawAlpha(&IMG_sfss_y11, X, Y); pnglable++; break;
				case 12: drawAlpha(&IMG_sfss_y12, X, Y); pnglable++; break;
				case 13: drawAlpha(&IMG_sfss_y13, X, Y); pnglable++; break;
				case 14: drawAlpha(&IMG_sfss_y14, X, Y); pnglable = 0; break;
				}
			}//right
			break;
		}

		case 2:          //机枪
		{
			if (Direction == 0)
			{
				switch (pnglable)
				{
				case 0: drawAlpha(&IMG_jqwd_z0, X, Y); pnglable++; break;
				case 1: drawAlpha(&IMG_jqwd_z1, X, Y); pnglable++; break;
				case 2: drawAlpha(&IMG_jqwd_z2, X, Y); pnglable++; break;
				case 3: drawAlpha(&IMG_jqwd_z3, X, Y); pnglable++; break;
				case 4: drawAlpha(&IMG_jqwd_z4, X, Y); pnglable++; break;
				case 5: drawAlpha(&IMG_jqwd_z5, X, Y); pnglable++; break;
				case 6: drawAlpha(&IMG_jqwd_z6, X, Y); pnglable++; break;
				case 7: drawAlpha(&IMG_jqwd_z7, X, Y); pnglable++; break;
				case 8: drawAlpha(&IMG_jqwd_z8, X, Y); pnglable++; break;
				case 9: drawAlpha(&IMG_jqwd_z9, X, Y); pnglable++; break;
				case 10: drawAlpha(&IMG_jqwd_z10, X, Y); pnglable++; break;
				case 11: drawAlpha(&IMG_jqwd_z11, X, Y); pnglable++; break;
				case 12: drawAlpha(&IMG_jqwd_z12, X, Y); pnglable = 0; break;
				}

			}  //left 
			else
			{
				switch (pnglable)
				{
				case 0: drawAlpha(&IMG_jqwd_y0, X, Y); pnglable++; break;
				case 1: drawAlpha(&IMG_jqwd_y1, X, Y); pnglable++; break;
				case 2: drawAlpha(&IMG_jqwd_y2, X, Y); pnglable++; break;
				case 3: drawAlpha(&IMG_jqwd_y3, X, Y); pnglable++; break;
				case 4: drawAlpha(&IMG_jqwd_y4, X, Y); pnglable++; break;
				case 5: drawAlpha(&IMG_jqwd_y5, X, Y); pnglable++; break;
				case 6: drawAlpha(&IMG_jqwd_y6, X, Y); pnglable++; break;
				case 7: drawAlpha(&IMG_jqwd_y7, X, Y); pnglable++; break;
				case 8: drawAlpha(&IMG_jqwd_y8, X, Y); pnglable++; break;
				case 9: drawAlpha(&IMG_jqwd_y9, X, Y); pnglable++; break;
				case 10: drawAlpha(&IMG_jqwd_y10, X, Y); pnglable++; break;
				case 11: drawAlpha(&IMG_jqwd_y11, X, Y); pnglable++; break;
				case 12: drawAlpha(&IMG_jqwd_y12, X, Y); pnglable = 0; break;
				}
			}//right
			break;
		}

		case 3:          //三线
		{
			if (Direction == 0)
			{
				switch (pnglable)
				{
				case 0: drawAlpha(&IMG_sxss_z0, X, Y); pnglable++; break;
				case 1: drawAlpha(&IMG_sxss_z1, X, Y); pnglable++; break;
				case 2: drawAlpha(&IMG_sxss_z2, X, Y); pnglable++; break;
				case 3: drawAlpha(&IMG_sxss_z3, X, Y); pnglable++; break;
				case 4: drawAlpha(&IMG_sxss_z4, X, Y); pnglable++; break;
				case 5: drawAlpha(&IMG_sxss_z5, X, Y); pnglable++; break;
				case 6: drawAlpha(&IMG_sxss_z6, X, Y); pnglable++; break;
				case 7: drawAlpha(&IMG_sxss_z7, X, Y); pnglable++; break;
				case 8: drawAlpha(&IMG_sxss_z8, X, Y); pnglable++; break;
				case 9: drawAlpha(&IMG_sxss_z9, X, Y); pnglable++; break;
				case 10: drawAlpha(&IMG_sxss_z10, X, Y); pnglable++; break;
				case 11: drawAlpha(&IMG_sxss_z11, X, Y); pnglable++; break;
				case 12: drawAlpha(&IMG_sxss_z12, X, Y); pnglable++; break;
				case 13: drawAlpha(&IMG_sxss_z13, X, Y); pnglable++; break;
				case 14: drawAlpha(&IMG_sxss_z14, X, Y); pnglable++; break;
				case 15: drawAlpha(&IMG_sxss_z15, X, Y); pnglable = 0; break;
				}
			}  //left 
			else
			{
				switch (pnglable)
				{
				case 0: drawAlpha(&IMG_sxss_y0, X, Y); pnglable++; break;
				case 1: drawAlpha(&IMG_sxss_y1, X, Y); pnglable++; break;
				case 2: drawAlpha(&IMG_sxss_y2, X, Y); pnglable++; break;
				case 3: drawAlpha(&IMG_sxss_y3, X, Y); pnglable++; break;
				case 4: drawAlpha(&IMG_sxss_y4, X, Y); pnglable++; break;
				case 5: drawAlpha(&IMG_sxss_y5, X, Y); pnglable++; break;
				case 6: drawAlpha(&IMG_sxss_y6, X, Y); pnglable++; break;
				case 7: drawAlpha(&IMG_sxss_y7, X, Y); pnglable++; break;
				case 8: drawAlpha(&IMG_sxss_y8, X, Y); pnglable++; break;
				case 9: drawAlpha(&IMG_sxss_y9, X, Y); pnglable++; break;
				case 10: drawAlpha(&IMG_sxss_y10, X, Y); pnglable++; break;
				case 11: drawAlpha(&IMG_sxss_y11, X, Y); pnglable++; break;
				case 12: drawAlpha(&IMG_sxss_y12, X, Y); pnglable++; break;
				case 13: drawAlpha(&IMG_sxss_y13, X, Y); pnglable++; break;
				case 14: drawAlpha(&IMG_sxss_y14, X, Y); pnglable++; break;
				case 15: drawAlpha(&IMG_sxss_y15, X, Y); pnglable = 0; break;
				}
			}//right
			break;
		}
		}
	}
		
	void CommenPea() { Peaclass = 0; }
	void IcePea() { Peaclass = 1; }
	void FirePea() { Peaclass = 2; }
	void SFSS() { ZWLX = 1; }
	void JQWD() { ZWLX = 2; }
	void SXSS() { ZWLX = 3; }
	int GetZWLX() { return ZWLX; }

private:
	int X;
	int Y;
	int Direction;
	int Peaclass;
	int Speed;
	int HP;
	int ZWLX;
	int pnglable;
};
class commenzombie
{
public:
	commenzombie() :X(-1), Y(-1), Speed(0), HP(-1), pnglablezombie(0), Active(false), DIE(false), turn(false) {};
	void SetZombies(float x, float y, int hp, float speed)
	{
		X = x;
		Y = y;
		HP = hp;
		Active = false;
		Speed = speed;
		CommenSpeed = speed;
		pnglablezombie = 0;
		DIE = false;
		turn = false;
	}
	void CZActive() { Active = true; }
	void Die() { if (Active == true) { Active = false; DIE = true; ZombieNum--; wdhb += 7; sjs += 1; } }
	void Move() { if (Active == true) X -= Speed; }
	void SlowDown() { Speed = 0.6; }
	void TakeCommonDamage() { HP -= 20; }
	void TakeFireDamage() { HP -= 50; }
	void UnSlowDown() { Speed = CommenSpeed; }
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
			case 21: drawAlpha(&IMG_commenzombie21, X, Y); pnglablezombie = 0; break;
			}
		}
		else if (DIE == true && pnglablezombie >= 0)
		{
			if (turn == false)
			{
				pnglablezombie = 0;
				turn = true;
			}
			switch (pnglablezombie)
			{
			case 0: drawAlpha(&IMG_czb_die0, X + dx, Y + dy); pnglablezombie++; break;
			case 1: drawAlpha(&IMG_czb_die1, X + dx, Y + dy); pnglablezombie++; break;
			case 2: drawAlpha(&IMG_czb_die2, X + dx, Y + dy); pnglablezombie++; break;
			case 3: drawAlpha(&IMG_czb_die3, X + dx, Y + dy); pnglablezombie++; break;
			case 4: drawAlpha(&IMG_czb_die4, X + dx, Y + dy); pnglablezombie++; break;
			case 5: drawAlpha(&IMG_czb_die5, X + dx, Y + dy); pnglablezombie++; break;
			case 6: drawAlpha(&IMG_czb_die6, X + dx, Y + dy); pnglablezombie++; break;
			case 7: drawAlpha(&IMG_czb_die7, X + dx, Y + dy); pnglablezombie++; break;
			case 8: drawAlpha(&IMG_czb_die8, X + dx, Y + dy); pnglablezombie++; break;
			case 9: drawAlpha(&IMG_czb_die9, X + dx, Y + dy); pnglablezombie = -1; break;
			}
		}
	}

private:
	float X;
	float Y;
	float Speed;
	float CommenSpeed;
	int HP;
	bool Active;
	int pnglablezombie;
	bool DIE;
	bool turn;
	int dx = -60;
	int dy = 20;
};
class luzhangzombie
{
public:
	luzhangzombie() :X(-1), Y(-1), Speed(0), HP(-1), pnglablezombie(0), Active(false), DIE(false), turn(false) {};
	void SetZombies(float x, float y, int hp, float speed)
	{
		X = x;
		Y = y;
		HP = hp;
		Active = false;
		Speed = speed;
		CommenSpeed = speed;
		pnglablezombie = 0;
		DIE = false;
		turn = false;
	}
	void CZActive() { Active = true; }
	void Die() { if (Active == true) { Active = false; DIE = true; LZZombieNum--; wdhb += 15; sjs += 1; } }
	void Move() { if (Active == true) X -= Speed; }
	void SlowDown() { Speed = 0.6; }
	void TakeCommonDamage() { HP -= 20; }
	void TakeFireDamage() { HP -= 50; }
	void UnSlowDown() { Speed = CommenSpeed; }
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
			case 0: drawAlpha(&IMG_lzzombie0, X, Y); pnglablezombie++; break;
			case 1: drawAlpha(&IMG_lzzombie1, X, Y); pnglablezombie++; break;
			case 2: drawAlpha(&IMG_lzzombie2, X, Y); pnglablezombie++; break;
			case 3: drawAlpha(&IMG_lzzombie3, X, Y); pnglablezombie++; break;
			case 4: drawAlpha(&IMG_lzzombie4, X, Y); pnglablezombie++; break;
			case 5: drawAlpha(&IMG_lzzombie5, X, Y); pnglablezombie++; break;
			case 6: drawAlpha(&IMG_lzzombie6, X, Y); pnglablezombie++; break;
			case 7: drawAlpha(&IMG_lzzombie7, X, Y); pnglablezombie++; break;
			case 8: drawAlpha(&IMG_lzzombie8, X, Y); pnglablezombie++; break;
			case 9: drawAlpha(&IMG_lzzombie9, X, Y); pnglablezombie++; break;
			case 10: drawAlpha(&IMG_lzzombie10, X, Y); pnglablezombie++; break;
			case 11: drawAlpha(&IMG_lzzombie11, X, Y); pnglablezombie++; break;
			case 12: drawAlpha(&IMG_lzzombie12, X, Y); pnglablezombie++; break;
			case 13: drawAlpha(&IMG_lzzombie13, X, Y); pnglablezombie++; break;
			case 14: drawAlpha(&IMG_lzzombie14, X, Y); pnglablezombie++; break;
			case 15: drawAlpha(&IMG_lzzombie15, X, Y); pnglablezombie++; break;
			case 16: drawAlpha(&IMG_lzzombie16, X, Y); pnglablezombie++; break;
			case 17: drawAlpha(&IMG_lzzombie17, X, Y); pnglablezombie++; break;
			case 18: drawAlpha(&IMG_lzzombie18, X, Y); pnglablezombie++; break;
			case 19: drawAlpha(&IMG_lzzombie19, X, Y); pnglablezombie++; break;;
			case 20: drawAlpha(&IMG_lzzombie20, X, Y); pnglablezombie = 0; break;
			}
		}
		else if (DIE == true && pnglablezombie >= 0)
		{
			if (turn == false)
			{
				pnglablezombie = 0;
				turn = true;
			}
			switch (pnglablezombie)
			{
			case 0: drawAlpha(&IMG_czb_die0, X + dx, Y + dy); pnglablezombie++; break;
			case 1: drawAlpha(&IMG_czb_die1, X + dx, Y + dy); pnglablezombie++; break;
			case 2: drawAlpha(&IMG_czb_die2, X + dx, Y + dy); pnglablezombie++; break;
			case 3: drawAlpha(&IMG_czb_die3, X + dx, Y + dy); pnglablezombie++; break;
			case 4: drawAlpha(&IMG_czb_die4, X + dx, Y + dy); pnglablezombie++; break;
			case 5: drawAlpha(&IMG_czb_die5, X + dx, Y + dy); pnglablezombie++; break;
			case 6: drawAlpha(&IMG_czb_die6, X + dx, Y + dy); pnglablezombie++; break;
			case 7: drawAlpha(&IMG_czb_die7, X + dx, Y + dy); pnglablezombie++; break;
			case 8: drawAlpha(&IMG_czb_die8, X + dx, Y + dy); pnglablezombie++; break;
			case 9: drawAlpha(&IMG_czb_die9, X + dx, Y + dy); pnglablezombie = -1; break;
			}
		}
	}

private:
	float X;
	float Y;
	float Speed;
	float CommenSpeed;
	int HP;
	bool Active;
	int pnglablezombie;
	bool DIE;
	bool turn;
	int dx = -60;
	int dy = 50;
};
class shachuangzombie
{
public:
	shachuangzombie() :X(-1), Y(-1), Speed(0), HP(-1), pnglablezombie(0), Active(false), DIE(false), turn(false) {};
	void SetZombies(float x, float y, int hp, float speed)
	{
		X = x;
		Y = y;
		HP = hp;
		Active = false;
		Speed = speed;
		CommenSpeed = speed;
		pnglablezombie = 0;
		DIE = false;
		turn = false;
	}
	void CZActive() { Active = true; }
	void Die() { if (Active == true) { Active = false; DIE = true; SCZombieNum--; wdhb += 20; sjs += 1; } }
	void Move() { if (Active == true) X -= Speed; }
	void SlowDown() { Speed = 0.6; }
	void TakeCommonDamage() { HP -= 20; }
	void TakeFireDamage() { HP -= 50; }
	void UnSlowDown() { Speed = CommenSpeed; }
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
			case 0: drawAlpha(&IMG_SCZB0, X, Y); pnglablezombie++; break;
			case 1: drawAlpha(&IMG_SCZB1, X, Y); pnglablezombie++; break;
			case 2: drawAlpha(&IMG_SCZB2, X, Y); pnglablezombie++; break;
			case 3: drawAlpha(&IMG_SCZB3, X, Y); pnglablezombie++; break;
			case 4: drawAlpha(&IMG_SCZB4, X, Y); pnglablezombie++; break;
			case 5: drawAlpha(&IMG_SCZB5, X, Y); pnglablezombie++; break;
			case 6: drawAlpha(&IMG_SCZB6, X, Y); pnglablezombie++; break;
			case 7: drawAlpha(&IMG_SCZB7, X, Y); pnglablezombie++; break;
			case 8: drawAlpha(&IMG_SCZB8, X, Y); pnglablezombie++; break;
			case 9: drawAlpha(&IMG_SCZB9, X, Y); pnglablezombie++; break;
			case 10: drawAlpha(&IMG_SCZB10, X, Y); pnglablezombie++; break;
			case 11: drawAlpha(&IMG_SCZB11, X, Y); pnglablezombie++; break;
			case 12: drawAlpha(&IMG_SCZB12, X, Y); pnglablezombie++; break;
			case 13: drawAlpha(&IMG_SCZB13, X, Y); pnglablezombie++; break;
			case 14: drawAlpha(&IMG_SCZB14, X, Y); pnglablezombie++; break;
			case 15: drawAlpha(&IMG_SCZB15, X, Y); pnglablezombie++; break;
			case 16: drawAlpha(&IMG_SCZB16, X, Y); pnglablezombie++; break;
			case 17: drawAlpha(&IMG_SCZB17, X, Y); pnglablezombie++; break;
			case 18: drawAlpha(&IMG_SCZB18, X, Y); pnglablezombie++; break;
			case 19: drawAlpha(&IMG_SCZB19, X, Y); pnglablezombie++; break;
			case 20: drawAlpha(&IMG_SCZB20, X, Y); pnglablezombie++; break;
			case 21: drawAlpha(&IMG_SCZB21, X, Y); pnglablezombie++; break;
			case 22: drawAlpha(&IMG_SCZB22, X, Y); pnglablezombie=0; break;
			}
		}
		else if (DIE == true && pnglablezombie >= 0)
		{
			if (turn == false)
			{
				pnglablezombie = 0;
				turn = true;
			}
			switch (pnglablezombie)
			{
			case 0: drawAlpha(&IMG_czb_die0, X + dx, Y + dy); pnglablezombie++; break;
			case 1: drawAlpha(&IMG_czb_die1, X + dx, Y + dy); pnglablezombie++; break;
			case 2: drawAlpha(&IMG_czb_die2, X + dx, Y + dy); pnglablezombie++; break;
			case 3: drawAlpha(&IMG_czb_die3, X + dx, Y + dy); pnglablezombie++; break;
			case 4: drawAlpha(&IMG_czb_die4, X + dx, Y + dy); pnglablezombie++; break;
			case 5: drawAlpha(&IMG_czb_die5, X + dx, Y + dy); pnglablezombie++; break;
			case 6: drawAlpha(&IMG_czb_die6, X + dx, Y + dy); pnglablezombie++; break;
			case 7: drawAlpha(&IMG_czb_die7, X + dx, Y + dy); pnglablezombie++; break;
			case 8: drawAlpha(&IMG_czb_die8, X + dx, Y + dy); pnglablezombie++; break;
			case 9: drawAlpha(&IMG_czb_die9, X + dx, Y + dy); pnglablezombie = -1; break;
			}
		}
	}

private:
	float X;
	float Y;
	float Speed;
	float CommenSpeed;
	int HP;
	bool Active;
	int pnglablezombie;
	bool DIE;
	bool turn;
	int dx = -60;
	int dy = 20;
};
myplant wdss(300, 300, ZWSD, 100, 1);
commenzombie ptjs[10001];
luzhangzombie lzjs[10001];
shachuangzombie scjs[10001];
class pea
{
public:
	void UsePeaCoin()
	{
		if (PeaClass == 0) wdhb -= 1;
		else if (PeaClass == 1) wdhb -= 2;
		else wdhb -= 3;
	}
	void SetupPea(int dx, int dy)
	{
		PeaClass = wdss.GetPeaclass();
		X = wdss.GetX() + dx;
		Y = wdss.GetY() + dy;
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
			if (Direction == 0) X -= WDSD;
			else X += WDSD;
		}
	}
	void Attack(commenzombie& js)
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
			break;
		}
	}
	void Attack(luzhangzombie& js)
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
	void Attack(shachuangzombie& js)
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
			if (PeaClass == 2)
			{
				switch (Direction)
				{
				case 1:
				{
					if (FirePeaLable == 0)
					{
						drawAlpha(&IMG_firepea0, X, Y);
						FirePeaLable = 1;
					}
					else
					{
						drawAlpha(&IMG_firepea1, X, Y);
						FirePeaLable = 0;
					}
					break;
				}
				case 0:
				{
					switch (FirePeaLable)
					{
					case 0:
						drawAlpha(&IMG_firepea00, X, Y);
						FirePeaLable = 1;
						break;
					case 1:
					{
						drawAlpha(&IMG_firepea11, X, Y);
						FirePeaLable = 0;
						break;
					}
					break;
					}
				}
				}
			}
		}
	}
	bool GetAct() { return Active; }
	int GetX() { return X; }
	int GetY() { return Y; }
	int GetDir() { return Direction; }

private:
	int X;
	int Y;
	int PeaClass;
	int Direction;
	int FirePeaLable;
	bool Active;

};
class Cherry
{
public:
	Cherry() :cX(-1), cY(-1), pnglableCherryBomb(0), Active(false), DIE(false) {};
	void SetCherryBomb()
	{
		CherryBombRemain--;
		if (wdss.GetDirection() == 0)
		{
			cX = wdss.GetX() - 200;
			cY = wdss.GetY();
			cbY = cY - 50;
			Active = true;
		}
		else
		{
			cX = wdss.GetX() + 200;
			cY = wdss.GetY();
			cbY = cY - 50;
			Active = true;
		}
	}
	void Die()
	{
		DIE = true;
	}
	void Print()
	{
		if (this->Active == true && this->DIE == false)
		{
			switch (pnglableCherryBomb)
			{
			case 0: drawAlpha(&IMG_CB_0, cX, cY); pnglableCherryBomb++; break;
			case 1: drawAlpha(&IMG_CB_1, cX, cY); pnglableCherryBomb++; break;
			case 2: drawAlpha(&IMG_CB_2, cX, cY); pnglableCherryBomb++; break;
			case 3: drawAlpha(&IMG_CB_3, cX, cY); pnglableCherryBomb++; break;
			case 4: drawAlpha(&IMG_CB_4, cX, cY); pnglableCherryBomb++; break;
			case 5: drawAlpha(&IMG_CB_5, cX, cY); pnglableCherryBomb++; break;
			case 6:
			{
				drawAlpha(&IMG_CB_6, cX, cY);
				pnglableCherryBomb++;
				if (cbY <= -10) cbY += 50;
				if (cbY >= 450)cbY -= 30;
				break;
			}
			case 7: drawAlpha(&IMG_CB_BOOM, cX-50, cbY); pnglableCherryBomb++; break;
			case 8:
			{
				PlaySound(TEXT("RESOURCE\\SND\\CherryBomb.wav"), NULL, SND_FILENAME | SND_ASYNC);
				KillZombies();
				pnglableCherryBomb++;
			}
			case 9: drawAlpha(&IMG_CB_BOOM, cX - 50, cbY); pnglableCherryBomb++; break;
			case 10: drawAlpha(&IMG_CB_BOOM, cX - 50, cbY); pnglableCherryBomb++; break;
			case 11: drawAlpha(&IMG_CB_BOOM, cX - 50, cbY); pnglableCherryBomb++; break;
			case 12: drawAlpha(&IMG_CB_BOOM, cX - 50, cbY); pnglableCherryBomb++; break;
			case 13: drawAlpha(&IMG_CB_BOOM, cX - 50, cbY); pnglableCherryBomb++; break;
			case 14: Die();
			}
		}
	}
	void KillZombies()
	{
		for (int m = 0; m <= jssl; m++)
		{
			int zX = ptjs[m].GetX() + 50;
			int zY = ptjs[m].GetY() + 100;
			int cmX = cX + 30;
			int cmY = cY + 50;//CherryBomb 中心坐标
			if((abs(cmX-zX)<=150)&&(abs(cmY-zY)<=150))
			//已弃用//if ((((zX >= cX) && (zX - cX) <= 100) && ((zY >= cY) && abs(zY - cY) <= 200)) || (((zX >= cX) && (zX - cX) <= 100) && ((zY <= cY) && abs(zY - cY) <= 100)) || (((zX <= cX) && abs(zX - cX) <= 200) && ((zY >= cY) && abs(zY - cY) <= 200)) || (((zX <= cX) && abs(zX - cX) <= 200) && ((zY <= cY) && abs(zY - cY) <= 100)))
			{
				if(ptjs[m].GetAct()==true) ptjs[m].Die();
			}
		}
		for (int m = 0; m <= lzjssl; m++)
		{
			int zX = lzjs[m].GetX() + 50;
			int zY = lzjs[m].GetY() + 100;
			int cmX = cX + 30;
			int cmY = cY + 50;//CherryBomb 中心坐标
			if ((abs(cmX - zX) <= 150) && (abs(cmY - zY) <= 150))
				//已弃用//if ((((zX >= cX) && (zX - cX) <= 100) && ((zY >= cY) && abs(zY - cY) <= 200)) || (((zX >= cX) && (zX - cX) <= 100) && ((zY <= cY) && abs(zY - cY) <= 100)) || (((zX <= cX) && abs(zX - cX) <= 200) && ((zY >= cY) && abs(zY - cY) <= 200)) || (((zX <= cX) && abs(zX - cX) <= 200) && ((zY <= cY) && abs(zY - cY) <= 100)))
			{
				if (lzjs[m].GetAct() == true) lzjs[m].Die();
			}
		}
		for (int m = 0; m <= scjssl; m++)
		{
			int zX = scjs[m].GetX() + 50;
			int zY = scjs[m].GetY() + 100;
			int cmX = cX + 30;
			int cmY = cY + 50;//CherryBomb 中心坐标
			if ((abs(cmX - zX) <= 150) && (abs(cmY - zY) <= 150))
				//已弃用//if ((((zX >= cX) && (zX - cX) <= 100) && ((zY >= cY) && abs(zY - cY) <= 200)) || (((zX >= cX) && (zX - cX) <= 100) && ((zY <= cY) && abs(zY - cY) <= 100)) || (((zX <= cX) && abs(zX - cX) <= 200) && ((zY >= cY) && abs(zY - cY) <= 200)) || (((zX <= cX) && abs(zX - cX) <= 200) && ((zY <= cY) && abs(zY - cY) <= 100)))
			{
				if (scjs[m].GetAct() == true) scjs[m].Die();
			}
		}
	}
	bool GetActive()
	{
		return Active;
	}
	bool GetDie()
	{
		return DIE;
	}

private:
	int cX;
	int cY;
	int cbY; //爆炸图案的位置，Y坐标
	bool Boom;
	int pnglableCherryBomb;
	bool Active;
	bool DIE;
};
class Almanac
{
public:
	Almanac():cdt(0),ax(130),ay(70) {};
	void Print()
	{
		BeginBatchDraw();
		switch (cdt)
		{
		case 0:
			if (MoveOn == false) drawAlpha(&IMG_Almanac_WF00, 130, 70);
			else putimage(ax, ay, &IMG_Almanac_WF01);
			break;
		case 1:
			if (MoveOn == false) drawAlpha(&IMG_Almanac_ZB00, 130, 70);
			else putimage(ax, ay, &IMG_Almanac_ZB01);
			break;
		case 2:
			if (MoveOn == false) putimage(ax, ay, &IMG_Almanac_PT00);
			else putimage(ax, ay, &IMG_Almanac_PT01);
			break;
		case 3:
			if (MoveOn == false) putimage(ax, ay, &IMG_Almanac_WD00);
			else putimage(ax, ay, &IMG_Almanac_WD01);
			break;
		case 4:
			if (MoveOn == false) putimage(ax, ay, &IMG_Almanac_ZZ00);
			else putimage(ax, ay, &IMG_Almanac_ZZ01);
			break;
		case 5:
			GoBack = true;
		}
		FlushBatchDraw();
	}
	void Next()
	{
		cdt++;
	}
	void Set()
	{
		MoveOn = false;
		cdt = 0;
		ax = 130;
		ay = 70;
	}
	void Moveon()
	{
		MoveOn = true;
	}
	void UnMoveon()
	{
		MoveOn = false;
	}

private:
	bool MoveOn;
	int cdt;
	int ax;
	int ay;
};
pea p[20000];
Cherry CherryBomb[10000];
Almanac ALMANAC;
void SetupZombies()
{
	for (int t = 1; t <= jssl; t++)
	{
		srand(time(NULL) + t * t);
		int dy = MapHeight(rand() % 5);
		ptjs[t].SetZombies(0.935 * width, dy, PTJSBlood, 0.1*CommenZombieSpeed);
	}
	for (int t = 1; t <= lzjssl; t++)
	{
		srand(time(NULL) + t * t);
		int dy = MapHeight(rand() % 5)-20;
		lzjs[t].SetZombies(0.935 * width, dy, LZJSBlood, 0.1*LuZhangZombieSpeed);
	}
	for (int t = 1; t <= scjssl; t++)
	{
		srand(time(NULL) + t * t);
		int dy = MapHeight(rand() % 5) - 20;
		scjs[t].SetZombies(0.935 * width, dy+15, TWMJSBlood, 0.1*ShaChuangZombieSpeed);
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
	if (sjs>=60&&LZZombieNum < lzhjs)
	{
		lzjs[LZZombieLable].CZActive();
		LZZombieNum++;
		LZZombieLable++;
	}
	if (sjs>=120 && SCZombieNum < schjs)
	{
		scjs[SCZombieLable].CZActive();
		SCZombieNum++;
		SCZombieLable++;
	}
}
void ZombiesMove()
{
	for (int t = 1; t <= jssl; t++)
	{
		if (ptjs[t].GetHP() <= 0) ptjs[t].Die();
		ptjs[t].Move();
	}
	for (int t = 1; t <= lzjssl; t++)
	{
		if (lzjs[t].GetHP() <= 0) lzjs[t].Die();
		lzjs[t].Move();
	}
	for (int t = 1; t <= scjssl; t++)
	{
		if (scjs[t].GetHP() <= 0) scjs[t].Die();
		scjs[t].Move();
	}
}
void PeaMove()
{
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		p[pn].move();
	}
}
void InAlmanac()
{
	if (MessageBox(NULL, TEXT("是否打开作者B站主页，以获取更多相关信息"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 32) == 6)
	{
		system("start https://space.bilibili.com/1945530511?spm_id_from=333.1007.0.0");
	}
	ToAlmanac = false;
	bool MoveOnNextPage = false;
	ALMANAC.Set();
	while (1)
	{
		FlushBatchDraw();
		m = getmessage();
		ALMANAC.Print();
		switch (m.message)
		{
		case WM_MOUSEMOVE:
			m.x;
			m.y;
			if (m.x > 650 && m.x < 770 && m.y>500 && m.y < 550)
			{
				ALMANAC.Moveon();
				MoveOnNextPage = true;
			}
			else
			{
				ALMANAC.UnMoveon();
				MoveOnNextPage = false;
			}
			break;
		case WM_LBUTTONDOWN:
			if(MoveOnNextPage) ALMANAC.Next();
			break;
		}
		FlushBatchDraw();
		if (GoBack == true)
		{
			GoBack = false;
			break;
		}
	}
}
void KbInput() {

	if (_kbhit())
	{
		int msg = _getch();
		switch (msg)
		{
		case 87:
		case 119:           //  W 按下
		{
			//wdss.SFSS();
			wdss.MoveUp();
			break;
		}

		case 83:          //S 按下
		case 115:
		{
			//wdss.JQWD();
			wdss.MoveDown();
			break;
		}

		case 68:              //D 按下
		case 100:
		{
			//wdss.SXSS();
			wdss.MoveRight();
			break;
		}

		case 97:             //A 按下
		case 65:
		{
			wdss.MoveLeft();
			break;
		}

		case 74:
		case 106:
		{
			switch (wdss.GetZWLX())
			{
			case 0:
			{
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(0, 0);
				else p[PeaNum].SetupPea(50, 0);
				p[PeaNum].UsePeaCoin();
				break;
			}
			case 1:
			{
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-25, 0);
				else p[PeaNum].SetupPea(50, 0);
				p[PeaNum].UsePeaCoin();
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(0, 0);
				else p[PeaNum].SetupPea(75, 0);
				break;
			}
			case 2:
			{
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-75, 10);
				else p[PeaNum].SetupPea(50, 10);
				p[PeaNum].UsePeaCoin();
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-50, 10);
				else p[PeaNum].SetupPea(75, 10);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-25, 10);
				else p[PeaNum].SetupPea(100, 10);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(0, 10);
				else p[PeaNum].SetupPea(125, 10);
				break;
			}
			case 3:
			{
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-75, 10);
				else p[PeaNum].SetupPea(50, 10);
				p[PeaNum].UsePeaCoin();
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-50, 10);
				else p[PeaNum].SetupPea(75, 10);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-25, 10);
				else p[PeaNum].SetupPea(100, 10);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(0, 10);
				else p[PeaNum].SetupPea(125, 10);

				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-75, -30);
				else p[PeaNum].SetupPea(50, -30);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-50, -30);
				else p[PeaNum].SetupPea(75, -30);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-25, -30);
				else p[PeaNum].SetupPea(100, -30);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(0, -30);
				else p[PeaNum].SetupPea(125, -30);

				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-75, 50);
				else p[PeaNum].SetupPea(50, 50);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-50, 50);
				else p[PeaNum].SetupPea(75, 50);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(-25, 50);
				else p[PeaNum].SetupPea(100, 50);
				PeaNum++;
				if (wdss.GetDirection() == 0) p[PeaNum].SetupPea(0, 50);
				else p[PeaNum].SetupPea(125, 50);
				break;
			}
			}
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

		case 80: 
		case 112:  //P按下，投出樱桃炸弹
		{
			if (CherryBombRemain > 0)
			{
				CherryBombNum += 1;
				CherryBomb[CherryBombNum].SetCherryBomb();
			}
			break;
		}

		case 69: //e按下 暂停
		case 101:
		{
			PressPause = true;
			break;
		}

		case 77:
		case 109: //m按下，进入图鉴
		{
			ToAlmanac = true;
			break;
		}
		}
	}
}
int main();
void MainPage();
void StopAllSound()
{
	mciSendString("close ksmusic", NULL, 0, NULL);
	mciSendString("close gcmusic", NULL, 0, NULL);
	mciSendString("close cgcmusic", NULL, 0, NULL);
	mciSendString("close ycmusic", NULL, 0, NULL);
}
void Pause()
{
	mciSendString("pause ksmusic", NULL, 0, NULL);
	mciSendString("pause gcmusic", NULL, 0, NULL);
	mciSendString("pause cgcmusic", NULL, 0, NULL);
	mciSendString("pause ycmusic", NULL, 0, NULL);
	ExMessage m;
	bool MoveOnContinue = false;
	bool MoveOnExit = false;
Re:
	if (PressPause == true)
	{
		for (;;)
		{
			BeginBatchDraw();
			Sleep(30);
			drawAlpha(&IMG_PauseBG, 300, 300);
			FlushBatchDraw();
			m = getmessage();
			switch (m.message)
			{
			case WM_MOUSEMOVE:
			{
				if (m.x > 323 && m.x < 472 && m.y>470 && m.y < 527) MoveOnContinue = true;
				else MoveOnContinue = false;
				if (m.x > 516 && m.x < 651 && m.y>472 && m.y < 527) MoveOnExit = true;
				else MoveOnExit = false;
				break;
			}
			case WM_LBUTTONDOWN:
			{
				if (MoveOnContinue)
				{
					PressPause = false;
					goto Re;
				}
				if (MoveOnExit)
				{
					StopAllSound();
					mciSendString("open RESOURCE\\SND\\MainTheme.mp3 alias ztq", NULL, 0, NULL);
					mciSendString("play ztq repeat", NULL, 0, NULL);
					PressPause = false;
					goto Re;
					break;
				}
				break;
			}
			}
			
		}
	}
	if (MoveOnExit) OnGame();
	mciSendString("play ksmusic repeat", NULL, 0, NULL);
	mciSendString("play gcmusic repeat", NULL, 0, NULL);
	mciSendString("play cgcmusic", NULL, 0, NULL);
	mciSendString("play ycmusic", NULL, 0, NULL);
}
void PrintOutPeaClass()
{
	int c = wdss.GetPeaclass();
	int PeaClassX = 118;
	int PeaClassY = 70;
	int ShangHaiX = 220;
	int ShangHaiY = 30;
	int JieShaoX = 125;
	int JieShaoY = 10;
	int XiaoHaoYangGuangX = 200;
	int XiaoHaoYangGuangY = 70;
	TCHAR yangguang[20];                                            //豌豆货币
	_stprintf_s(yangguang, _T(" %d "), wdhb);                       //处理豌豆货币
	TCHAR xiaohaoyangguang[20];
	settextcolor(BLACK);
	setbkcolor(BROWNYELLOW);
	outtextxy(30, 75, yangguang);                                   //输出豌豆货币
	settextcolor(WHITE);
	setbkcolor(BROWN);
	outtextxy(JieShaoX, JieShaoY, tc_wandouleixing);
	outtextxy(820, 70, tc_M);
	switch (c)
	{
	case 0:
		_stprintf_s(xiaohaoyangguang, _T(" 消耗阳光 %d  "), c + 1);
		outtextxy(PeaClassX, PeaClassY, tc_commenpea);
		drawAlpha(&IMG_pea, 135, 35);
		outtextxy(ShangHaiX, ShangHaiY, tc_shanghai10);
		outtextxy(XiaoHaoYangGuangX, XiaoHaoYangGuangY, xiaohaoyangguang);
		break;
	case 1:
		_stprintf_s(xiaohaoyangguang, _T(" 消耗阳光 %d  "), c + 1);
		outtextxy(PeaClassX, PeaClassY, tc_icepea);
		drawAlpha(&IMG_icepea, 135, 35);
		outtextxy(ShangHaiX, ShangHaiY, tc_shanghai10);
		outtextxy(ShangHaiX+10, ShangHaiY+20, tc_jiansu);
		outtextxy(XiaoHaoYangGuangX, XiaoHaoYangGuangY, xiaohaoyangguang);
		break;
	case 2:
		_stprintf_s(xiaohaoyangguang, _T(" 消耗阳光 %d  "), c + 1);
		outtextxy(PeaClassX, PeaClassY, tc_firepea);
		drawAlpha(&IMG_firepea0, 120, 35);
		outtextxy(ShangHaiX, ShangHaiY, tc_shanghai50);
		outtextxy(XiaoHaoYangGuangX, XiaoHaoYangGuangY, xiaohaoyangguang);
		break;
	}
}
void PrintOutCherryBombRemain()
{
	int CherryX = 315;
	int CherryY = 70;
	TCHAR yingtaozhadan[20];                                          //樱桃炸弹剩余个数
	_stprintf_s(yingtaozhadan, _T(" 剩余 %d 个 "), CherryBombRemain); //处理樱桃炸弹剩余个数
	outtextxy(CherryX, CherryY, yingtaozhadan);                                //樱桃炸弹个数
}
void BoomKP()
{
	if (PickUpSFSS == false && sjs >= 80&&wdss.GetZWLX()==0)
	{
		kx = 400;
		ky = 400;
		drawAlpha(&kp_sfss, kx, ky);
		BoomSFSS = true;
	}
	if (PickUpJQWD == false && sjs >= 160 && wdss.GetZWLX() == 1)
	{
		jx = 500;
		jy = 500;
		drawAlpha(&kp_jqwd, jx, jy);
		BoomJQWD = true;
	}
	if (wdhb >= 5000) GTSX = true;
	if (PickUpSXSS == false && GTSX == true && wdss.GetZWLX() == 2)
	{
		drawAlpha(&kp_sxss, 300, 300);
		BoomSXSS = true;
	}
}
void IfPick()
{
	if (BoomSFSS == true && abs(wdss.GetX() - kx) <= 30 && abs(wdss.GetY() - ky) <= 30)
	{
		PickUpSFSS = true;
		BoomSFSS = false;
		wdss.SFSS();
	}
	if (BoomJQWD == true && wdss.GetZWLX() == 1 && abs(wdss.GetX() - jx) <= 30 && abs(wdss.GetY() - jy) <= 30)
	{
		PickUpJQWD = true;
		BoomJQWD = false;
		wdss.JQWD();
		wdss.JQWD();
		wdss.JQWD();
	}
	if (BoomSXSS == true && wdss.GetZWLX() == 2 && (abs(wdss.GetX() - 300) <= 30 && abs(wdss.GetY() - 300) <= 30))
	{
		PickUpSXSS = true;
		BoomSXSS = false;
		wdss.SXSS();
	}
}
void CherryBombFresh()
{
	for (int cb = 0; cb <= CherryBombNum; cb++)
	{
		if (CherryBomb[cb].GetActive() == true && CherryBomb[cb].GetDie() == false)
		{
			CherryBomb[cb].Print();
		}
	}
}
void GetCherryBomb()
{
	if (sjs % GetCry == 0 && ExistYTZD == false && sjs!=0)
	{
		CherryBombRemain++;
		ExistYTZD = true;
	}
	if (ExistYTZD == true && sjs % GetCry != 0)
	{
		ExistYTZD = false;
	}
}
void PrintKillNumber()
{
	TCHAR killnumber[20];
	_stprintf_s(killnumber, _T(" 击杀 %d  "), sjs);
	outtextxy(415, 10, tc_kill);
	outtextxy(415, 40, killnumber);
}
void PrintLife()
{
	TCHAR liferemain[20];                                            
	_stprintf_s(liferemain, _T(" %d "), life);      
	outtextxy(530, 20, tc_shengming);
	outtextxy(535, 40, liferemain);
	outtextxy(920, 70, tc_E);
}
void PrintText()
{
	PrintOutCherryBombRemain();
	PrintOutPeaClass();
	PrintKillNumber();
	PrintLife();
}
void PrintBackground()
{
	putimage(0, 100, &IMG_background);
	drawAlpha(&IMG_sun, 0, 0);
	putimage(100, 0, &IMG_seedbanklong);
	putimage(300, 0, &IMG_seedbank);
	putimage(400, 0, &IMG_seedbank);
	putimage(500, 0, &IMG_seedbank);
	putimage(600, 0, &IMG_seedbank);
	putimage(700, 0, &IMG_seedbank);
	putimage(800, 0, &IMG_seedbank);
	putimage(900, 0, &IMG_seedbank);
	drawAlpha(&IMG_Almanac, 810, 10);
	drawAlpha(&IMG_QUIT, 920, 30);
	if (CherryBombRemain > 0)drawAlpha(&kp_CherryBombCard, 300, 10);
	else drawAlpha(&kp_CherryBombCardGray, 300, 10);
}
void Fresh()
{
	BeginBatchDraw();
	PrintBackground();
	PrintText();
	CherryBombFresh();
	GetCherryBomb();
	BoomKP();
	IfPick();
	wdss.Print();
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		p[pn].Print();
	}
	for (int t = 1; t <= jssl; t++)
	{
		ptjs[t].Print();
	}
	for (int t = 1; t <= lzjssl; t++)
	{
		lzjs[t].Print();
	}
	for (int t = 1; t <= scjssl; t++)
	{
		scjs[t].Print();
	}
	if (ToAlmanac) InAlmanac();
	Sleep(DelayTime);
	FlushBatchDraw();
}
void Setup()
{
	initgraph(width, height);
	cleardevice();
	loadimage(&IMG_background, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\background1.jpg"), width, height-100);
	loadimage(&IMG_MainPage, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\MainPage.png"), width, height);
	loadimage(&IMG_PauseBG, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\PauseBG.png"));
	loadimage(&IMG_QUIT, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\QUIT.png"));

	loadimage(&IMG_Almanac_ZB00, _T("RESOURCE\\IMG\\IMG_Almanac\\ZB00.png"));
	loadimage(&IMG_Almanac_ZB01, _T("RESOURCE\\IMG\\IMG_Almanac\\ZB01.png"));
	loadimage(&IMG_Almanac_PT00, _T("RESOURCE\\IMG\\IMG_Almanac\\PT00.png"));
	loadimage(&IMG_Almanac_PT01, _T("RESOURCE\\IMG\\IMG_Almanac\\PT01.png"));
	loadimage(&IMG_Almanac_WD00, _T("RESOURCE\\IMG\\IMG_Almanac\\WD00.png"));
	loadimage(&IMG_Almanac_WD01, _T("RESOURCE\\IMG\\IMG_Almanac\\WD01.png"));
	loadimage(&IMG_Almanac_WF00, _T("RESOURCE\\IMG\\IMG_Almanac\\WF00.png"));
	loadimage(&IMG_Almanac_WF01, _T("RESOURCE\\IMG\\IMG_Almanac\\WF01.png"));
	loadimage(&IMG_Almanac_ZZ00, _T("RESOURCE\\IMG\\IMG_Almanac\\ZZXX00.png"));
	loadimage(&IMG_Almanac_ZZ01, _T("RESOURCE\\IMG\\IMG_Almanac\\ZZXX01.png"));

	loadimage(&IMG_Start, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\Start.png"),width,height);

	loadimage(&IMG_sun, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\sun.png"),100,100);
	loadimage(&IMG_seedbank, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\seedbank.png"), 100, 100);
	loadimage(&IMG_seedbanklong, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\seedbank.png"), 200, 100);
	loadimage(&IMG_ZombiesWin, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\ZombiesWin.png"));
	loadimage(&IMG_Almanac, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\Almanac.png"),60,60);
	loadimage(&IMG_AlmanacBig, _T("RESOURCE\\IMG\\IMG_BACKGROUND\\Almanac.png"));
	loadimage(&IMG_wdss_z0, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z0.png"));
	loadimage(&IMG_wdss_y0, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y0.png"));
	loadimage(&IMG_wdss_z1, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z1.png"));
	loadimage(&IMG_wdss_y1, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y1.png"));
	loadimage(&IMG_wdss_z2, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z2.png"));
	loadimage(&IMG_wdss_y2, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y2.png"));
	loadimage(&IMG_wdss_z3, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z3.png"));
	loadimage(&IMG_wdss_y3, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y3.png"));
	loadimage(&IMG_wdss_z4, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z4.png"));
	loadimage(&IMG_wdss_y4, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y4.png"));
	loadimage(&IMG_wdss_z5, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z5.png"));
	loadimage(&IMG_wdss_y5, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y5.png"));
	loadimage(&IMG_wdss_z6, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z6.png"));
	loadimage(&IMG_wdss_y6, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y6.png"));
	loadimage(&IMG_wdss_z7, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z7.png"));
	loadimage(&IMG_wdss_y7, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y7.png"));
	loadimage(&IMG_wdss_z8, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z8.png"));
	loadimage(&IMG_wdss_y8, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y8.png"));
	loadimage(&IMG_wdss_z9, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z9.png"));
	loadimage(&IMG_wdss_y9, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y9.png"));
	loadimage(&IMG_wdss_z10, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z10.png"));
	loadimage(&IMG_wdss_y10, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y10.png"));
	loadimage(&IMG_wdss_z11, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z11.png"));
	loadimage(&IMG_wdss_y11, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y11.png"));
	loadimage(&IMG_wdss_z12, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_z12.png"));
	loadimage(&IMG_wdss_y12, _T("RESOURCE\\IMG\\IMG_WDSS\\wdss_y12.png"));

	loadimage(&IMG_commenzombie0, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb0.png"));
	loadimage(&IMG_commenzombie1, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb1.png"));
	loadimage(&IMG_commenzombie2, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb2.png"));
	loadimage(&IMG_commenzombie3, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb3.png"));
	loadimage(&IMG_commenzombie4, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb4.png"));
	loadimage(&IMG_commenzombie5, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb5.png"));
	loadimage(&IMG_commenzombie6, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb6.png"));
	loadimage(&IMG_commenzombie7, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb7.png"));
	loadimage(&IMG_commenzombie8, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb8.png"));
	loadimage(&IMG_commenzombie9, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb9.png"));
	loadimage(&IMG_commenzombie10, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb10.png"));
	loadimage(&IMG_commenzombie11, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb11.png"));
	loadimage(&IMG_commenzombie12, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb12.png"));
	loadimage(&IMG_commenzombie13, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb13.png"));
	loadimage(&IMG_commenzombie14, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb14.png"));
	loadimage(&IMG_commenzombie15, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb15.png"));
	loadimage(&IMG_commenzombie16, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb16.png"));
	loadimage(&IMG_commenzombie17, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb17.png"));
	loadimage(&IMG_commenzombie18, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb18.png"));
	loadimage(&IMG_commenzombie19, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb19.png"));
	loadimage(&IMG_commenzombie20, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb20.png"));
	loadimage(&IMG_commenzombie21, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb21.png"));

	loadimage(&IMG_lzzombie0, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ0.png"));
	loadimage(&IMG_lzzombie1, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ1.png"));
	loadimage(&IMG_lzzombie2, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ2.png"));
	loadimage(&IMG_lzzombie3, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ3.png"));
	loadimage(&IMG_lzzombie4, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ4.png"));
	loadimage(&IMG_lzzombie5, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ5.png"));
	loadimage(&IMG_lzzombie6, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ6.png"));
	loadimage(&IMG_lzzombie7, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ7.png"));
	loadimage(&IMG_lzzombie8, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ8.png"));
	loadimage(&IMG_lzzombie9, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ9.png"));
	loadimage(&IMG_lzzombie10, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ10.png"));
	loadimage(&IMG_lzzombie11, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ11.png"));
	loadimage(&IMG_lzzombie12, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ12.png"));
	loadimage(&IMG_lzzombie13, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ13.png"));
	loadimage(&IMG_lzzombie14, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ14.png"));
	loadimage(&IMG_lzzombie15, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ15.png"));
	loadimage(&IMG_lzzombie16, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ16.png"));
	loadimage(&IMG_lzzombie17, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ17.png"));
	loadimage(&IMG_lzzombie18, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ18.png"));
	loadimage(&IMG_lzzombie19, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ19.png"));
	loadimage(&IMG_lzzombie20, _T("RESOURCE\\IMG\\IMG_LuZhangZombie\\LZ20.png"));

	loadimage(&IMG_SCZB0, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB0.png"));
	loadimage(&IMG_SCZB1, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB1.png"));
	loadimage(&IMG_SCZB2, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB2.png"));
	loadimage(&IMG_SCZB3, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB3.png"));
	loadimage(&IMG_SCZB4, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB4.png"));
	loadimage(&IMG_SCZB5, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB5.png"));
	loadimage(&IMG_SCZB6, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB6.png"));
	loadimage(&IMG_SCZB7, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB7.png"));
	loadimage(&IMG_SCZB8, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB8.png"));
	loadimage(&IMG_SCZB9, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB9.png"));
	loadimage(&IMG_SCZB10, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB10.png"));
	loadimage(&IMG_SCZB11, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB11.png"));
	loadimage(&IMG_SCZB12, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB12.png"));
	loadimage(&IMG_SCZB13, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB13.png"));
	loadimage(&IMG_SCZB14, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB14.png"));
	loadimage(&IMG_SCZB15, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB15.png"));
	loadimage(&IMG_SCZB16, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB16.png"));
	loadimage(&IMG_SCZB17, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB17.png"));
	loadimage(&IMG_SCZB18, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB18.png"));
	loadimage(&IMG_SCZB19, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB19.png"));
	loadimage(&IMG_SCZB20, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB20.png"));
	loadimage(&IMG_SCZB21, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB21.png"));
	loadimage(&IMG_SCZB22, _T("RESOURCE\\IMG\\IMG_SCZOMBIES\\SCZB22.png"));

	loadimage(&IMG_czb_die0, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die0.png"));
	loadimage(&IMG_czb_die1, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die1.png"));
	loadimage(&IMG_czb_die2, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die2.png"));
	loadimage(&IMG_czb_die3, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die3.png"));
	loadimage(&IMG_czb_die4, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die4.png"));
	loadimage(&IMG_czb_die5, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die5.png"));
	loadimage(&IMG_czb_die6, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die6.png"));
	loadimage(&IMG_czb_die7, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die7.png"));
	loadimage(&IMG_czb_die8, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die8.png"));
	loadimage(&IMG_czb_die9, _T("RESOURCE\\IMG\\IMG_COMMENZOMBIE\\czb_die9.png"));

	loadimage(&IMG_sfss_y0, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss0.png"));
	loadimage(&IMG_sfss_z0, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz0.png"));
	loadimage(&IMG_sfss_y1, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss1.png"));
	loadimage(&IMG_sfss_z1, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz1.png"));
	loadimage(&IMG_sfss_y2, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss2.png"));
	loadimage(&IMG_sfss_z2, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz2.png"));
	loadimage(&IMG_sfss_y3, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss3.png"));
	loadimage(&IMG_sfss_z3, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz3.png"));
	loadimage(&IMG_sfss_y4, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss4.png"));
	loadimage(&IMG_sfss_z4, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz4.png"));
	loadimage(&IMG_sfss_y5, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss5.png"));
	loadimage(&IMG_sfss_z5, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz5.png"));
	loadimage(&IMG_sfss_y6, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss6.png"));
	loadimage(&IMG_sfss_z6, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz6.png"));
	loadimage(&IMG_sfss_y7, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss7.png"));
	loadimage(&IMG_sfss_z7, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz7.png"));
	loadimage(&IMG_sfss_y8, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss8.png"));
	loadimage(&IMG_sfss_z8, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz8.png"));
	loadimage(&IMG_sfss_y9, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss9.png"));
	loadimage(&IMG_sfss_z9, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz9.png"));
	loadimage(&IMG_sfss_y10, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss10.png"));
	loadimage(&IMG_sfss_z10, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz10.png"));
	loadimage(&IMG_sfss_y11, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss11.png"));
	loadimage(&IMG_sfss_z11, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz11.png"));
	loadimage(&IMG_sfss_y12, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss12.png"));
	loadimage(&IMG_sfss_z12, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz12.png"));
	loadimage(&IMG_sfss_y13, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss13.png"));
	loadimage(&IMG_sfss_z13, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz13.png"));
	loadimage(&IMG_sfss_y14, _T("RESOURCE\\IMG\\IMG_SFSS\\sfss14.png"));
	loadimage(&IMG_sfss_z14, _T("RESOURCE\\IMG\\IMG_SFSS\\sfssz14.png"));

	loadimage(&IMG_jqwd_z0, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz0.png"));
	loadimage(&IMG_jqwd_y0, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd0.png"));
	loadimage(&IMG_jqwd_z1, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz1.png"));
	loadimage(&IMG_jqwd_y1, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd1.png"));
	loadimage(&IMG_jqwd_z2, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz2.png"));
	loadimage(&IMG_jqwd_y2, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd2.png"));
	loadimage(&IMG_jqwd_z3, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz3.png"));
	loadimage(&IMG_jqwd_y3, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd3.png"));
	loadimage(&IMG_jqwd_z4, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz4.png"));
	loadimage(&IMG_jqwd_y4, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd4.png"));
	loadimage(&IMG_jqwd_z5, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz5.png"));
	loadimage(&IMG_jqwd_y5, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd5.png"));
	loadimage(&IMG_jqwd_z6, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz6.png"));
	loadimage(&IMG_jqwd_y6, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd6.png"));
	loadimage(&IMG_jqwd_z7, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz7.png"));
	loadimage(&IMG_jqwd_y7, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd7.png"));
	loadimage(&IMG_jqwd_z8, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz8.png"));
	loadimage(&IMG_jqwd_y8, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd8.png"));
	loadimage(&IMG_jqwd_z9, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz9.png"));
	loadimage(&IMG_jqwd_y9, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd9.png"));
	loadimage(&IMG_jqwd_z10, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz10.png"));
	loadimage(&IMG_jqwd_y10, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd10.png"));
	loadimage(&IMG_jqwd_z11, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz11.png"));
	loadimage(&IMG_jqwd_y11, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd11.png"));
	loadimage(&IMG_jqwd_z12, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwdz12.png"));
	loadimage(&IMG_jqwd_y12, _T("RESOURCE\\IMG\\IMG_JQWD\\jqwd12.png"));

	loadimage(&IMG_sxss_z0, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz0.png"));
	loadimage(&IMG_sxss_y0, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss0.png"));
	loadimage(&IMG_sxss_z1, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz1.png"));
	loadimage(&IMG_sxss_y1, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss1.png"));
	loadimage(&IMG_sxss_z2, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz2.png"));
	loadimage(&IMG_sxss_y2, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss2.png"));
	loadimage(&IMG_sxss_z3, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz3.png"));
	loadimage(&IMG_sxss_y3, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss3.png"));
	loadimage(&IMG_sxss_z4, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz4.png"));
	loadimage(&IMG_sxss_y4, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss4.png"));
	loadimage(&IMG_sxss_z5, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz5.png"));
	loadimage(&IMG_sxss_y5, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss5.png"));
	loadimage(&IMG_sxss_z6, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz6.png"));
	loadimage(&IMG_sxss_y6, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss6.png"));
	loadimage(&IMG_sxss_z7, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz7.png"));
	loadimage(&IMG_sxss_y7, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss7.png"));
	loadimage(&IMG_sxss_z8, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz8.png"));
	loadimage(&IMG_sxss_y8, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss8.png"));
	loadimage(&IMG_sxss_z9, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz9.png"));
	loadimage(&IMG_sxss_y9, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss9.png"));
	loadimage(&IMG_sxss_z10, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz10.png"));
	loadimage(&IMG_sxss_y10, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss10.png"));
	loadimage(&IMG_sxss_z11, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz11.png"));
	loadimage(&IMG_sxss_y11, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss11.png"));
	loadimage(&IMG_sxss_z12, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz12.png"));
	loadimage(&IMG_sxss_y12, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss12.png"));
	loadimage(&IMG_sxss_z13, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz13.png"));
	loadimage(&IMG_sxss_y13, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss13.png"));
	loadimage(&IMG_sxss_z14, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz14.png"));
	loadimage(&IMG_sxss_y14, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss14.png"));
	loadimage(&IMG_sxss_z15, _T("RESOURCE\\IMG\\IMG_SXSS\\sxssz15.png"));
	loadimage(&IMG_sxss_y15, _T("RESOURCE\\IMG\\IMG_SXSS\\sxss15.png"));

	loadimage(&IMG_pea, _T("RESOURCE\\IMG\\IMG_PEA\\pea.png"));
	loadimage(&IMG_icepea, _T("RESOURCE\\IMG\\IMG_PEA\\icepea.png"));
	loadimage(&IMG_firepea0, _T("RESOURCE\\IMG\\IMG_PEA\\firepea0.png"));
	loadimage(&IMG_firepea1, _T("RESOURCE\\IMG\\IMG_PEA\\firepea1.png"));
	loadimage(&IMG_firepea00, _T("RESOURCE\\IMG\\IMG_PEA\\firepea00.png"));
	loadimage(&IMG_firepea11, _T("RESOURCE\\IMG\\IMG_PEA\\firepea11.png"));

	loadimage(&IMG_CB_0, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb0.png"));
	loadimage(&IMG_CB_1, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb1.png"));
	loadimage(&IMG_CB_2, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb2.png"));
	loadimage(&IMG_CB_3, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb3.png"));
	loadimage(&IMG_CB_4, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb4.png"));
	loadimage(&IMG_CB_5, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb5.png"));
	loadimage(&IMG_CB_6, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb6.png"));
	loadimage(&IMG_CB_BOOM, _T("RESOURCE\\IMG\\IMG_CherryBomb\\CherryBomb_BOOM.png"));

	loadimage(&kp_sfss, _T("RESOURCE\\IMG\\IMG_CARD\\sfss.png"));
	loadimage(&kp_jqwd, _T("RESOURCE\\IMG\\IMG_CARD\\jqwd.png"));
	loadimage(&kp_sxss, _T("RESOURCE\\IMG\\IMG_CARD\\sxss.png"));
	loadimage(&kp_CherryBombCard, _T("RESOURCE\\IMG\\IMG_CARD\\CherryBombCard.png"));
	loadimage(&kp_CherryBombCardGray, _T("RESOURCE\\IMG\\IMG_CARD\\CherryBombGray.png"));
	BeginBatchDraw();
	//system("start RESOURCE\\Script\\Shift.vbs");
}
void LoseLife()
{
	for (int t = 1; t <= jssl; t++)
	{
		if (ptjs[t].GetX() <= 0)
		{
			//cout << "Game Over!" << endl;
			if (ptjs[t].GetAct() == true)
			{
				ptjs[t].Die();
				life--;
			}
		}
	}
	for (int t = 1; t <= lzjssl; t++)
	{
		if (lzjs[t].GetX() <= 0)
		{
			//cout << "Game Over!" << endl;
			if (lzjs[t].GetAct() == true )
			{
				lzjs[t].Die();
				life--;
			}
		}
	}
	for (int t = 1; t <= scjssl; t++)
	{
		if (scjs[t].GetX() <= 0)
		{
			//cout << "Game Over!" << endl;
			if (scjs[t].GetAct() == true )
			{
				scjs[t].Die();
				life--;
			}
		}
	}
}
void GameOver()
{
	if (wdhb < 0)
	{
		gameover = true;
	}
	if (life <= 0)
	{
		gameover = true;
	}
	if (gameover == true)
	{
		drawAlpha(&IMG_ZombiesWin, 200, 100);
		FlushBatchDraw();
		StopAllSound();
		mciSendString("open RESOURCE\\SND\\Lose.mp3 alias lsmusic", NULL, 0, NULL);
		mciSendString("play lsmusic", NULL, 0, NULL);
		Sleep(5000);
		if (MessageBox(NULL, TEXT("游戏结束，是否重新开始"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 32) == 6)
		{
			system("start PVZ-Ultimate.exe");
			exit(0);
		}
		else
		{
			exit(0);
		}
	}
}
void ShotOn()
{
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		if (p[pn].GetX() <= 0.005 * width || p[pn].GetX() >= 0.95 * width) p[pn].Die();
		for (int t = 1; t <= ZombieLable; t++)
		{
			if (p[pn].GetAct() == true && ptjs[t].GetAct() == true)
			{
				if (((p[pn].GetY() >= ptjs[t].GetY()) || ((p[pn].GetY() < ptjs[t].GetY() && ptjs[t].GetY() - p[pn].GetY() <= 10))) && abs(p[pn].GetY() - ptjs[t].GetY()) < 100)
				{
					if (abs(p[pn].GetX() - ptjs[t].GetX()) < 8)
					{
						PlaySound(TEXT("RESOURCE\\SND\\splat.wav"), NULL, SND_FILENAME | SND_ASYNC);
						p[pn].Attack(ptjs[t]);
						p[pn].Die();
					}
				}
			}
		}
	}
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		if (p[pn].GetX() <= 0.005 * width || p[pn].GetX() >= 0.95 * width) p[pn].Die();
		for (int t = 1; t <= LZZombieLable; t++)
		{
			if (p[pn].GetAct() == true && lzjs[t].GetAct() == true)
			{
				if (((p[pn].GetY() >= lzjs[t].GetY()) || ((p[pn].GetY() < lzjs[t].GetY() && lzjs[t].GetY() - p[pn].GetY() <= 10))) && abs(p[pn].GetY() - lzjs[t].GetY()) < 135)
				{
					if (abs(p[pn].GetX() - lzjs[t].GetX()) < 8)
					{
						PlaySound(TEXT("RESOURCE\\SND\\splat.wav"), NULL, SND_FILENAME | SND_ASYNC);
						p[pn].Attack(lzjs[t]);
						p[pn].Die();
					}
				}
			}
		}
	}
	for (int pn = 1; pn <= PeaNum; pn++)
	{
		if (p[pn].GetX() <= 0.005 * width || p[pn].GetX() >= 0.95 * width) p[pn].Die();
		for (int t = 1; t <= SCZombieLable; t++)
		{
			if (p[pn].GetAct() == true && scjs[t].GetAct() == true)
			{
				if (((p[pn].GetY() >= scjs[t].GetY()) || ((p[pn].GetY() < scjs[t].GetY() && scjs[t].GetY() - p[pn].GetY() <= 10))) && abs(p[pn].GetY() - scjs[t].GetY()) < 135)
				{
					if ((abs(p[pn].GetX() - scjs[t].GetX()) < 8) && (p[pn].GetDir()==0))
					{
						PlaySound(TEXT("RESOURCE\\SND\\splat.wav"), NULL, SND_FILENAME | SND_ASYNC);
						p[pn].Attack(scjs[t]);
						p[pn].Die();
					}
					else if((abs(p[pn].GetX() - scjs[t].GetX()) < 8) && (p[pn].GetDir() == 1))
					{
						PlaySound(TEXT("RESOURCE\\SND\\splat.wav"), NULL, SND_FILENAME | SND_ASYNC);
						p[pn].Die();
					}
				}
			}
		}
	}
}
void PlayWaterMusic()
{
	mciSendString("open RESOURCE\\SND\\Water.mp3 alias ycmusic", NULL, 0, NULL);
	mciSendString("play ycmusic repeat", NULL, 0, NULL);
	mciSendString("close cgcmusic", NULL, 0, NULL);
	mciSendString("close gcmusic", NULL, 0, NULL);
	mciSendString("close ksmusic", NULL, 0, NULL);
}
void PlayCGCMusic()
{
	mciSendString("close ycmusic", NULL, 0, NULL);
	mciSendString("close gcmusic", NULL, 0, NULL);
	mciSendString("open RESOURCE\\SND\\Conveyor.mp3 alias cgcmusic", NULL, 0, NULL);
	mciSendString("play cgcmusic repeat", NULL, 0, NULL);
}
void PlayGCMusic()
{
	mciSendString("close cgcmusic", NULL, 0, NULL);
	mciSendString("close ycmusic", NULL, 0, NULL);
	mciSendString("open RESOURCE\\SND\\高潮.mp3 alias gcmusic", NULL, 0, NULL);
	mciSendString("play gcmusic repeat", NULL, 0, NULL);
}
void ZombiesBoost()
{
	if (sjs >= 10 && DIF == 0)
	{
		hjs = 5;
		DIF++;
	}
	if (sjs >= 20 && DIF == 1)
	{
		hjs = 10;
		DIF++;
	}
	if (sjs >= 40 && DIF == 2)
	{
		hjs = 15;
		DIF++;
	}
	if (sjs >= 60 && DIF == 3)
	{
		hjs = 20;
		DIF++;
	}
	if (sjs >= 70 && DIF == 4)
	{
		lzhjs = 5;
		DIF++;
	}
	if (sjs >= 100 && DIF == 5)
	{
		
		lzhjs = 10;
		hjs = 25;
		DIF++;
	}
	if (sjs >= 200 && DIF == 6)
	{
		hjs = 30;
		lzhjs = 15;
		schjs = 5;
		DIF++;
	}
	if (sjs >= 250 && DIF == 7)
	{
		lzhjs = 20;
		hjs = 35;
		schjs = 8;
		DIF++;
	}
	if (sjs >= 300 && DIF == 8)
	{
		schjs = 10;
		DIF++;
	}
	if (sjs >= 400 && DIF == 9)
	{
		PlayWaterMusic();
		hjs = 3;
		lzhjs = 2;
		schjs = 1;
		DIF++;
	}
	if (sjs >= 550 && DIF == 10)
	{
		hjs = 13;
		lzhjs = 13;
		schjs = 13;
		DIF++;
	}
	if (sjs >= 600 && DIF == 11)
	{
		hjs = 20;
		lzhjs = 20;
		schjs = 20;
		DIF++;
	}
	if (sjs >= 650 && DIF == 12)
	{
		hjs = 30;
		lzhjs = 20;
		schjs = 10;
		DIF++;
	}
	if (sjs >= 750 && DIF == 13)
	{
		hjs = 30;
		lzhjs = 30;
		schjs = 30;
		DIF++;
	}
	if (sjs >= 800 && DIF == 14)
	{
		hjs = 40;
		lzhjs = 40;
		schjs = 40;
		DIF++;
	}
	if (sjs >= 900 && DIF == 15)
	{
		hjs = 50;
		lzhjs = 50;
		schjs = 50;
		DIF++;
	}
	if (sjs >= 1000 && DIF == 16)
	{
		PlayCGCMusic();
		hjs = 10;
		lzhjs = 10;
		schjs = 10;
		DIF++;
	}
	if (sjs >= 1200 && DIF == 17)
	{
		hjs = 100;
		lzhjs = 70;
		schjs = 50;
		DIF++;
	}
	if (sjs >= 1400 && DIF == 18)
	{
		hjs = 50;
		lzhjs = 50;
		schjs = 50;
		DIF++;
	}
	if (sjs >= 1600 && DIF == 19)
	{
		PlayWaterMusic();
		hjs = 2;
		lzhjs = 2;
		schjs = 2;
		DIF++;
	}
	if (sjs >= 2000 && DIF == 20)
	{
		PlayGCMusic();
		hjs = 60;
		lzhjs = 60;
		schjs = 60;
		DIF++;
	}
}

void Start()
{
	mciSendString("open RESOURCE\\SND\\MainTheme.mp3 alias ztq", NULL, 0, NULL);
	mciSendString("play ztq repeat", NULL, 0, NULL);
	bool MoveOnStart = false;
	bool Click = false;
	BeginBatchDraw();
START:
	while (!Click)
	{
		drawAlpha(&IMG_Start, 0, 0);
		FlushBatchDraw();
		ExMessage m;
		m = getmessage();
		//cout << m.x << "  " << m.y << endl;
		switch (m.message)
		{
			case WM_MOUSEMOVE:
				if (m.x >= 305 && m.x <= 683 && m.y >= 614 && m.y <= 672) MoveOnStart = true;
				else MoveOnStart = false;
				break;
			case WM_LBUTTONDOWN:
				if (MoveOnStart == true)
				{
					Click = true;
					goto START;
				}
				break;
		}
	}
}
void GetDefaultKey()
{
	Getsjs = stoi(ReadLineWithoutX("User_KillNumber.ini", 1));
	Getsun = stoi(ReadLineWithoutX("User_Sun.ini", 1));
	GetPeaClass = stoi(ReadLineWithoutX("User_PeaClass.ini", 1));
	GetCherryNum = stoi(ReadLineWithoutX("User_CherryBomb.ini", 1));
	Getlife = stoi(ReadLineWithoutX("User_Life.ini", 1));
}
void Exit()
{
	if (MessageBox(NULL, TEXT("是否存档"), TEXT("游戏提示"), MB_YESNO|MB_SYSTEMMODAL + 32) == 6)
	{
		ofstream outputsun("User_Sun.ini");
		outputsun << wdhb;
		outputsun.clear();
		outputsun.close();
		ofstream outputkln("User_KillNumber.ini");
		outputkln << sjs;
		outputkln.clear();
		outputkln.close();
		ofstream outputpcn("User_PeaClass.ini");
		outputpcn << wdss.GetPeaclass();
		outputpcn.clear();
		outputpcn.close();
		ofstream outputcrb("User_CherryBomb.ini");
		outputcrb << CherryBombRemain;
		outputcrb.clear();
		outputcrb.close();
		ofstream outputlf("User_Life.ini");
		outputlf << life;
		outputlf.clear();
		outputlf.close();
		MessageBox(NULL, TEXT("存档成功！"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 32);
	}
	exit(0);
}
void Set()
{
	if(stoi(ReadLineWithoutX("User_Debug.ini", 1))==0)
	{ 
	char s[19];
	InputBox(s, 19, "请输入16位设置密码 详情可以联系作者：\n微信/电话 13804137958 \nQQ：5719119266\n邮箱：QSQ68686868@163.com\n            QSQ68686868@sina.com", "加入开发者 --输入许可密钥", "xxxx-xxxxx-xxxxxxx", 400, 400, false);
	string q(s);
	//cout << q << endl;
	if (q == pswd)
	{
		ofstream outputmode("User_Debug.ini");
		outputmode << "1";
		outputmode.clear();
		outputmode.close();
		if (MessageBox(NULL, TEXT("许可证密钥正确，是否进入调试"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 64) == 6)
		{
			MessageBox(NULL, TEXT("调试方法:\n 只可更改键值，不能更改行数顺序！"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 64);
			system("Config.ini");
		}
	}
	else
	{
		MessageBox(NULL, TEXT("许可证密钥错误"), TEXT("游戏提示"), MB_OK | MB_SYSTEMMODAL + 16);
	}
	}
	else
	{
		if (MessageBox(NULL, TEXT("许可证密钥密钥已验证，是否进入调试"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 64) == 6)
		{
			MessageBox(NULL, TEXT("调试方法:\n 只可更改键值，不能更改行数顺序！"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 64);
			system("Config.ini");
		}
	}
	GetSetKey();
}
void MainPage()
{
	bool Go = false;
	bool MoveOnStart = false;
	bool MoveOnSetting = false;
	bool MoveOnHelp = false;
	bool MoveOnExit = false;
	bool MoveOnAchievement = false;
	bool MoveOnMinigame = false;
	bool MoveOnLivemode = false;
	bool MoveOnChangeUser = false;
	bool MoveOnBigHead = false;
	bool MoveOnSet = false;
    ExMessage aM;
	BeginBatchDraw();

REGO:
	while (!Go)
	{
		putimage(0,0,&IMG_MainPage);
		aM = getmessage();
		switch (aM.message)
		{
		case WM_MOUSEMOVE:
		{
			int X = aM.x;
			int Y = aM.y;
			if (X > 500 && X < 895 && Y>105 && Y < 237) MoveOnStart = true;
			else MoveOnStart = false;
			if (X > 896 && X < 958 && Y>569 && Y < 627) MoveOnExit = true;
			else MoveOnExit = false;
			if (X > 820 && X < 865 && Y>585 && Y < 632) MoveOnHelp = true;
			else MoveOnHelp = false;
			if (X > 692 && X < 799 && Y>520 && Y < 611) MoveOnSet = true;
			else MoveOnSet = false;
			break;
		}
		case WM_LBUTTONDOWN:
		{
			//cout << aM.x << "    " << aM.y << endl;
			if (MoveOnStart)
			{
				Go = true;
				goto REGO;
			}
			if (MoveOnExit) Exit();
			if (MoveOnHelp) InAlmanac();
			if (MoveOnSet) Set();
			break;
		}
		}
		FlushBatchDraw();
	}
}
void GetSave()
{
	if (Getsjs != 0)
	{
		if (MessageBox(NULL, TEXT("是否读取之前的存档"), TEXT("游戏提示"), MB_YESNO | MB_SYSTEMMODAL + 32) == 6)
		{
			wdhb = Getsun;
			sjs = Getsjs;
			CherryBombRemain = GetCherryNum;
			life = Getlife;
			int zwlx = GetPeaClass;
			switch (zwlx)
			{
			case 0:
				break;
			case 1:
				wdss.SFSS();
				wdss.SFSS();
				break;
			case 2:
				wdss.JQWD();
				wdss.JQWD();
				break;
			case 3:
				wdss.SXSS();
				wdss.SXSS();
				break;
			}
		}
	}
}
void OnGame()
{
	MainPage();
	GetDefaultKey();
	GetSave();
	if (setgame == 0)
	{
		SetupZombies();
		setgame = 1;
	}
	mciSendString("close ztq", NULL, 0, NULL);
	mciSendString("open RESOURCE\\SND\\开始.mp3 alias ksmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString("play ksmusic repeat", NULL, 0, NULL);  // 循环播放
	Fresh();
	while (1)
	{
		ActiveZombie();
		ZombiesBoost();
		ZombiesMove();
		PeaMove();
		KbInput();
		ShotOn();
		Fresh();
		Pause();
		LoseLife();
		GameOver();
	}
}
int main()
{
	Setup();
	Start();
	OnGame();
}

