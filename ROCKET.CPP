#include <graphics.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dos.h>
#include <string.h>
#include <iostream.h>
#include <time.h>
void draw_line(int x1, int y1, int x2, int y2) //bresenham line drawing algorithm
{
    int incx = 1, incy = 1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0)
	dx = -dx;
    if (dy < 0)
	dy = -dy;
    if (x2 < x1)
	incx = -1;
    if (y2 < y1)
	incy = -1;
    int x = x1;
    int y = y1;
    if (dx > dy)
    {
	putpixel(x, y, RED);
	int e = 2 * dy - dx;
	for (int i = 0; i < dx; i++)
	{
	    if (e >= 0)
	    {
		y += incy;
		e += 2 * (dy - dx);
	    }
	    else
	    {
		e += 2 * dy;
	    }
	    x += incx;
	    putpixel(x, y, RED);
	}
    }
    else
    {
	putpixel(x, y, RED);
	int e = 2 * dx - dy;
	for (int i = 0; i < dy; i++)
				{
	    if (e >= 0)
	    {
		x += incx;
		e += 2 * (dx - dy);
		;
	    }
	    else
		e += 2 * dx;
	    y += incy;
	    putpixel(x, y, RED);
	}
    }
}
void EightWayPlot(int xc, int yc, int x, int y)
{
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, YELLOW);
    putpixel(y + xc, x + yc, 12);
    putpixel(y + xc, -x + yc, 14);
    putpixel(-y + xc, -x + yc, 15);
    putpixel(-y + xc, x + yc, 6);
}
void draw_circle(int xc, int yc, int r) //bresenham circle drawing algorithm
{
    int x = 0, y = r, d = 3 - (2 * r);
    EightWayPlot(xc, yc, x, y);
    while (x <= y)
    {
	if (d <= 0)
	{
	    d = d + (4 * x) + 6;
	}
	else
	{
	    d = d + (4 * x) - (4 * y) + 10;
	    y = y - 1;
	}
	x = x + 1;
	EightWayPlot(xc, yc, x, y);
    }
}
void main(void)
{
    char ch;
    int gd=DETECT,gm,errorcode, i;
    initgraph(&gd, &gm,"c:\\turboc3\\BGI");
    setcolor(WHITE);
    settextstyle(3, 0, 3);
    outtextxy(100, 100, "Welcome to ISRO Rocket Launch Mission");
    delay(1000);
    cleardevice();
    outtextxy(100, 100, "Press 'Y' to start, 'N' to exit");
    ch = getch();
    if (ch == 'y' || ch == 'Y')
    {
	setbkcolor(BLACK);
	cleardevice();
	setcolor(4);
	settextstyle(10, 0, 8);
	for (int i = 10; i > 0; i--)
	{
	    char result[50];
	    sprintf(result, "T - %d", i);
	    outtextxy(100,100, result);
	    delay(1000);
	    cleardevice();
	}
	settextstyle(0, 0, 8);
	outtextxy(100,100, "LIFT-OFF!");
	delay(1000);
	cleardevice();
	////******************LAUNCH***************
	for (i = 1; i <= 300; i++)
	{
	    //rocket body

	    draw_line(280, 130 - i, 320, 130 - i);

	    draw_line(320, 130 - i, 320, 300 - i);

	    draw_line(320, 300 - i, 280, 300 - i);

	    draw_line(280, 300 - i, 280, 130 - i);
	    //booster 1

	    draw_line(250, 190 - i, 280, 190 - i);

	    draw_line(280, 190 - i, 280, 300 - i);

	    draw_line(280, 300 - i, 250, 300 - i);

	    draw_line(250, 300 - i, 250, 190 - i);

	    //booster 2

	    draw_line(320, 190 - i, 350, 190 - i);

	    draw_line(350, 190 - i, 350, 300 - i);

	    draw_line(350, 300 - i, 320, 300 - i);

	    draw_line(320, 300 - i, 320, 190 - i);

	    // body cone

	    sector(300, 70 - i, 250, 290, 65, 65);

	    // booster 1 cone

	    sector(265, 150 - i, 250, 290, 45, 45);

	    // booster 2 cone
	    sector(335, 150 - i, 250, 290, 45, 45);

	    // moon


	    draw_circle(150,50, 20);

	    //body flames

	    draw_circle(300, 323 - i, 33);

	    draw_circle(300, 360 - i, 25);

	    draw_circle(300, 390 - i, 15);

	    //booster 1 flames
	    draw_circle(265, 310 - i, 20);

	    draw_circle(265, 335 - i, 12);

	    draw_circle(265, 350 - i, 8);

	    //booster 2 flames
	    draw_circle(335, 310 - i, 20);

	    draw_circle(335, 335 - i, 12);

	    draw_circle(335, 350 - i, 8);

	    //ground

	    draw_line(0, 400 + i, 800, 400 + i);

	    draw_line(800, 400 + i, 800, 800 + i);

	    draw_line(800, 180 + i, 0, 800 + i);

	    draw_line(0,800 + i, 0, 400 + i);

	    //rocket support

	    draw_line(210, 200 + i, 225, 200 + i);

	    draw_line(225, 200 + i, 225, 400 + i);

	    draw_line(225, 400 + i, 210, 400 + i);

	    draw_line(210, 400 + i, 210, 200 + i);

	    delay(10);
	    cleardevice();
	}
	////*******************DEPLOY******************

	cleardevice();
	for (i=0; i < 300; i++)
	{

	    bar(280, 130, 320, 300); //rocket body

	    if (i < 50)
	    {
		bar(250 - i, 190 + i, 280 - i, 300 + i); //booster 1

		bar(320 + i, 190 + i, 350 + i, 300 + i); //booster 2

		//booster 1 cone

		sector(255 - i, 150 + i, 250, 290, 45, 45);

		//booster 2 cone

		sector(325 + i, 150 + i, 250, 290, 45, 45);
		//booster 1 flames

		draw_circle(265 - i, 310 + i, 20);

		draw_circle(265 - i, 335 + i, 12);

		//booster 2 flames
		draw_circle(335 + i, 310 + i, 20);

		draw_circle(335 + i, 335 + i, 12);

	    }
	    else if (i >= 50 && i < 100)
	    {
		i = i - 50;
		bar(200 - (i / 2), 240 + i, 230 - (i / 2), 350 + i); //booster 1

		bar(370 + (i / 2), 240 + i, 400 + (i / 2), 350 + i); //booster 2

		//booster 1 cone

		sector(215 - (i / 2), 200 + i, 250, 290, 45, 45);

		//booster 2 cone

		sector(385 + (i / 2), 200 + i, 250, 290, 45, 45);

		//booster 1 flames

		draw_circle(215 - (i / 2), 360 + i, 20);

		//booster 2 flames

		draw_circle(385 + (i / 2), 360 + i, 20);

		i = i + 50;
	    }
	    else
	    {
		i = i - 100;

		bar(175, 290 + i, 205, 400 + i); //booster 1

		bar(395, 290 + i, 425, 400 + i); //booster 2

		//booster 1 cone

		sector(190, 250 + i, 250, 290, 45, 45);

		//booster 2 cone

		sector(410, 250 + i, 250, 290, 45, 45);

		i = i + 100;
	    }
	    // body cone

	    sector(300, 70, 250, 290, 65, 65);

	    draw_circle(300, 360, 25);

	    draw_circle(300, 390, 15);

	    //stars

	    draw_circle(600, 400 + i, 2);

	    draw_circle(100, 200 + i, 2);

	    draw_circle(200, 600 + i, 2);

	    draw_circle(400, 100 + i, 2);

	    draw_circle(700, 300 + i, 2);

	    draw_circle(100, i, 2);

	    draw_circle(200, -100 + i, 2);

	    draw_circle(750, 100 + i, 2);

	    draw_circle(450, -200 + i, 2);

	    delay(20);
	    cleardevice();
	}
	//********************IN SPACE************************
	for (i = 0; i < 200; i++)
	{

	    draw_circle(200 - i, 400 + i, 135 - (i / 2));


	    int arr1[] = {320, 250, 440, 130, 460, 150, 340, 270, 320, 250}; //body

	    sector(480, 110, 205, 245, 45, 45); //body cone

	    //moon

	    draw_circle(500 - i, -150 + i, 20);

	    delay(30);
	    cleardevice();
	}

	//******************LANDING*****************
	setbkcolor(BLACK);
	cleardevice();
	for (i=0; i < 240; i++)
	{
	    if (i < 200)
	    {

		bar(380, 230 + i, 420, 400 + i);

		sector(400, 170 + i, 250, 290, 65, 65);

		draw_circle(400, 410 + i, 30 - (i / 10));

		setcolor(WHITE);
		settextstyle(1, 0, 1);

	    }
	    else
	    {

		sector(400, 370, 290, 190, 65, 65);

		bar(380, 430, 420, 600);

		setcolor(2);
		settextstyle(0, 0, 4);
		outtextxy(120, 200, "MISSION SUCCESS!");
		delay(10);
	    }
	    setfillstyle(1, 8);
	    draw_line(0, 600, 800, 600);
	    draw_line(800, 600, 800, 800);
	    draw_line(800, 800, 0, 800);
	    draw_line(0, 800, 0, 600);

	    delay(20);
	    cleardevice();
	}
    }
    else
    {
	cleardevice();
	setcolor(4);
	settextstyle(0, 0, 4);
	outtextxy(160, 200, "TRY AGAIN");
	delay(2000);
    }
    exit(0);
    getch();
    closegraph();
}