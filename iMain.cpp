# define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
# include <math.h>
# include <time.h>
# include <Windows.h>
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define STATE_STICK_GROWING 0
# define STATE_STICK_GROWN 1
# define STATE_INITIAL 2
# define STATE_LAST 3
# define STATE_NEW 4
# define STATE_ANIMATION_STICK_FALL 5
# define STATE_ANIMATION_MOVE_RECT 6
# define STATE_ANIMATION_DEAD 7
# define STATE_ANIMATION_DEAD1 8
# define DEAD 0
# define ALIVE 1
FILE *flp;
int newscreen;
int m;
int c;
int a;
int s;
int fll;
char NAME[100];
char NAME1[100];
int idx = 0;
char scoreText[100];
char scoreText1[100];
char playerText[100];
char lifeText[100];
char highscoreText[100];
char newhighscoreText[100];
char player1Text[100];
int STATE;
int stick_left;
int stick_base;
int stick_width;
int stick_height;
int rectangle_point;
int rectangle_point1;
int rectangle_point2;
int circle_left;
int circle_base;
int f = 0;
int m_, n, p;
int score;
int life;
int grow_timer_called;
//int g;
//int j;
double angle;
int distance;
int rectangle1RangeLeft;
int rectangle1RangeRight;
int rectangle1width;
int rectangle1widthMin;
int rectangle1widthMax;
int rectangleWidth;
int isAlive;
int q;
void stickMake();
void grow();
void startGrowing();
void stopGrowing();
int width;
int high_score;
//int High_score(){

void sound1()
{
	PlaySound("Indiana Jones Theme Song (HD) (mp3cutnet)", NULL, SND_ASYNC);
}

void createdistance()
{


	distance = rand() % 350 + 60;

}
void reInitialise()
{
	rectangleWidth = rectangle1width;
	rectangle_point = 150;
	rectangle_point1 = rectangle1RangeLeft + rand() % (rectangle1RangeRight - rectangle1RangeLeft + 1);
	rectangle1width = rectangle1widthMin + rand() % (rectangle1widthMax - rectangle1widthMin + 1);

	angle = acos(0.0);
	stick_left = 145 + rectangleWidth;
	stick_base = 147;
	//stick_width = 10;
	stick_height = 0;
	circle_base = 160;
	circle_left = 160;
	//a = 0;
	//g = 0;

	//j = 1;


	//	if (STATE == STATE_INITIAL)
	//		rectangle_point = rectangle_point1 + distance;

	STATE = STATE_INITIAL;

	//rectangle_point = 200;
	//rectangle_point1 = 500;
	f = 0;
	//angle = 3.1416 / 2;


}
void initial()
{
	score = 0;
	life = 3;
	STATE = STATE_INITIAL;
	grow_timer_called = 0;

	circle_left = 160;

	rectangle1width = rectangleWidth = 50;

	rectangle1RangeLeft = 300;
	rectangle1RangeRight = 500;
	rectangle1widthMin = 35;
	rectangle1widthMax = 70;
	//a = 0;
	reInitialise();
	FILE* f;
	f = fopen("Score.txt", "r");
	fscanf(f, "%s ", NAME1);
	fscanf(f, "%d ", &high_score);
	fclose(f);
	printf("%d", high_score);
	printf("%s", NAME1);
}
void save_game()
{
	//initial();
	flp = fopen("Load Game.txt", "r");
	fscanf(flp, "%d ", &score);
	fscanf(flp, "%d ", &life);
	fscanf(flp, "%s ", NAME);
	fscanf(flp, "%d ", &n);
	fscanf(flp, "%d ", &p);
	//fscanf(flp, "%d", n);
	//fscanf(flp, "%d", p);
	fclose(flp);
}
void circle_move()
{

	if (STATE == STATE_ANIMATION_DEAD || STATE == STATE_ANIMATION_MOVE_RECT)
	{
		if (circle_left < stick_height + stick_left)
		{
			circle_left++;
		}
		else
		{
			if (STATE == STATE_ANIMATION_DEAD)
			{
				circle_base -= 10;
				if (circle_base == 0 && life != 0)
				{
					//printf("YOU ARE DEAD JIM\n");
					reInitialise();
				}
				else if (circle_base <= 0 && life == 0)
				{
					STATE = STATE_ANIMATION_DEAD1;
					//q = 1;
				}
			}
			else
			{

				if (rectangle_point1 > 150)
				{
					rectangle_point1--;
					rectangle_point--;
					stick_left--;
					circle_left--;
				}
				else
				{
					reInitialise();
				}
			}
		}
	}


}

void ar()
{
	//printf("%d\n", stick_left);
	if (STATE == STATE_ANIMATION_STICK_FALL)
	{
		if (angle > 0.0){
			angle = angle - acos(0.0) / 90;
		}
		//printf("%lf", angle);
		if (angle <= 0)
		{
			if (isAlive == ALIVE)
				STATE = STATE_ANIMATION_MOVE_RECT;
			else
			{
				STATE = STATE_ANIMATION_DEAD;

			}
			iSettimer(10, circle_move);
			//angle = 3.1416 / 2;
		}
	}

}
void stickmove()
{
	stick_left--;
}
void rs()
{
	rectangle_point--;
}
//for sliding the second rectangle
void rs1()
{
	if (rectangle_point1 > 150)
		rectangle_point1--;
	//if (rectangle_point1 <= 450 && rectangle_height <= 150)
	//rectangle_height++;
	else if (rectangle_point1 == 150)
	{
		//STATE = STATE_NEW;
		//initial();
		//grow();


		if (STATE == STATE_LAST)
		{
			createdistance();
		}
		rectangle_point = rectangle_point1 + distance;


		if (rectangle_point1 == 150)
		{
			int temp = rectangle_point;
			rectangle_point = rectangle_point1;
			rectangle_point1 = temp;
		}
		//printf("%d %d\n", rectangle_point, rectangle_point1);
		//printf("%d %d\n", rectangle_point, rectangle_point1);



		//rectangle_point1 = 200;
		/*if (circle_left == 220)
		{
		createdistance();
		STATE = STATE_INITIAL;
		//g = 0;
		}
		rectangle_point = rectangle_point1 + distance;*/
		//STATE = STATE_NEW;
		//STATE = STATE_INITIAL;
		//initial();
		//startGrowing();
		//STATE = STATE_STICK_GROWING;
		//grow();
	}
}
void grow()
{
	grow_timer_called = 1;
	if (STATE == STATE_STICK_GROWING)
	{
		stick_height += 5;
		if (stick_height + stick_base >= SCREEN_HEIGHT)
		{
			stick_height = SCREEN_HEIGHT - stick_base;
			stopGrowing();
		}
	}
}
void startGrowing()
{
	if (STATE == STATE_NEW || stick_height == 0)
	{
		STATE = STATE_STICK_GROWING;
		if (!grow_timer_called)iSettimer(100, grow);
		//printf("%d", STATE);
	}
}
//for sliding the 1st rectangle

void stickMake()
{
	iSetcolor(0.4, 0.7, 0.4);
	//int i = 0;
	for (int i = 0; i < 4; i++)
		iLine(stick_left + i, stick_base + i, stick_left + cos(angle)*stick_height + i, stick_base + sin(angle)*stick_height + i);
}

void make_circle()
{
	if (n == 1)
		iShowBMP(circle_left - 10, circle_base - 12, "stick-man4.bmp");
	else if (p == 1)
		iShowBMP(circle_left - 10, circle_base - 12, "stick-man1.bmp");
	else
		iShowBMP(circle_left - 10, circle_base - 10, "Capture hero242.bmp");
	//iSetcolor(.9, .1, .2);
	//iFilledCircle(circle_left, circle_base, 10, 100);
	//iFilledCircle(circle_left, circle_base + 13, 5, 100);
}

void text_create()
{

	iSetcolor(0, 0, 1);
	sprintf_s(scoreText, "SCORE: %d", score);
	iText(10, 560, scoreText, GLUT_BITMAP_TIMES_ROMAN_24);
	//iSetcolor(1, 1, 1);
	sprintf_s(lifeText, "LIFE: %d", life);
	iText(10, 530, lifeText, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(playerText, "PLAYER'S NAME:");
	iText(590, 530, playerText, GLUT_BITMAP_TIMES_ROMAN_24);

	sprintf_s(player1Text, "%s", NAME);
	iText(590, 510, player1Text, GLUT_BITMAP_TIMES_ROMAN_24);
	if (life == 0 && STATE == STATE_ANIMATION_DEAD1){
		//printf("%d", STATE);
		//printf("%d\n", life);
		fll = 1;
		iClear();
		iSetcolor(0, 0, 0);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		iShowBMP(0, 0, "BMKBACKGROUNDBLACKcopy.bmp");
		iShowBMP(300, 220, "256-256-da4555b24380d442df41fc883fbe3411 - Copy.bmp");
		iShowBMP(450, 220, "RESTART (2).bmp");
		//initial();
		iSetcolor(0, 1, 1);
		sprintf_s(scoreText1, "SCORE:%s : %d", NAME, score);
		iText(375, 165, scoreText1, GLUT_BITMAP_TIMES_ROMAN_24);
		if (high_score >= score){
			iSetcolor(0, 1, 1);
			iText(335, 120, highscoreText, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf_s(highscoreText, " HIGH SCORE:%s : %d", NAME1, high_score);
		}
		else{
			iSetcolor(0, 1, 1);
			iText(185, 120, newhighscoreText, GLUT_BITMAP_TIMES_ROMAN_24);
			sprintf_s(newhighscoreText, "Congratulations!!!! NEW HIGH SCORE:%s : %d", NAME, score);
			FILE* f;
			f = fopen("Score.txt", "w+");
			fprintf(f, "%s ", NAME);
			fprintf(f, " %d", score);
			fclose(f);
		}

	}
}

void stopGrowing()
{
	int l = 0;

	STATE = STATE_ANIMATION_STICK_FALL;


	if (stick_height >= (rectangle_point1 - stick_left) && stick_height <= (rectangle_point1 - stick_left + rectangle1width))
	{
		printf("STILL ALIVE\n");
		score += 10;
		isAlive = ALIVE;
	}
	else if ((stick_height < (rectangle_point1 - stick_left) || stick_height >(rectangle_point1 - stick_left + rectangle1width)))
	{
		life--;
		isAlive = DEAD;
		printf("DEAD\n");
	}
	iSettimer(1, ar);
	printf("%lf", angle);

}
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
	iClear();
	iSetcolor(1, 1, 1);
	iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	iShowBMP(0, 0, "BMKBACKGROUNDBLACKcopy.bmp");
	iShowBMP(300, 450, "STICK_NAME3.bmp");
	iShowBMP(500, 30, "256-256-da4555b24380d442df41fc883fbe3411.bmp");
	iShowBMP(170, 30, "256-256-3c541556ef22340382e659ac8a579f69.bmp");
	iShowBMP(350, 400, "button.bmp");
	iShowBMP(660, 460, "play-games-icon.bmp");
	iSetcolor(1, 1, 1);
	iText(320, 300, NAME, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(325, 350, "ENTER NAME:", GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(310, 297, 190, 2);
	if (newscreen == 1){
		iClear();
		iSetcolor(1, 1, 1);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		iShowBMP(0, 0, "18465868-White-wall-Stock-Photo-brick.bmp");
		iShowBMP(320, 420, "nerwr.bmp");
		//if (m_ == 1)
		iSetcolor(1, 0, 0);
		iShowBMP(200, 330, "Capture hero24.bmp");
		iText(180, 300, "RACHAM", GLUT_BITMAP_TIMES_ROMAN_24);
		//else if (n == 1)
		iShowBMP(350, 330, "stick-man4~1.bmp");
		iText(320, 300, "SUPER GUY", GLUT_BITMAP_TIMES_ROMAN_24);

		//else if (p == 1)
		iShowBMP(500, 330, "stick-man12.bmp");
		iText(470, 300, "SHADOW MAN", GLUT_BITMAP_TIMES_ROMAN_24);
	}


	if (a == 1){
		iClear();
		iSetcolor(1, 1, 1);
		iFilledRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		/*FILE* f;
		fopen("Score.txt", "w+");
		fprintf(f, "%s", &NAME);
		fclose(f);*/
		//iSetcolor(0, 0, 0);
		//iFilledRectangle(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
		//iShowBMP(680, 470, "bell_off.bmp");
		//iShowBMP(500,0, "400_F_44187514_eJlvHrHjLqcJzIGylF0kDhr9wDPE9NCe.bmp");
		iShowBMP(670, 0, "capture34.bmp");
		iShowBMP(0, 0, "capture342.bmp");
		iShowBMP(0, 310, "pause button.bmp");
		iShowBMP(645, 330, "save-icon.bmp");
		iShowBMP(300, 430, "BlackCloud2.bmp");
		//iShowBMP(150,430,"sdsfshjh.bmp");
		iShowBMP(130, 270, "Capture3445.bmp");

		make_circle();
		stickMake();
		iSetcolor(0.5, 0.5, 0.3);
		iFilledRectangle(rectangle_point, 0, rectangleWidth, 150);
		iFilledRectangle(rectangle_point1, 0, rectangle1width, 150);
		text_create();
	}
	if (s == 1){
		flp = fopen("Load Game.txt", "w+");
		fprintf(flp, "%d ", score);
		fprintf(flp, "%d ", life);
		fprintf(flp, "%s ", NAME);
		fprintf(flp, "%d ", n);
		fprintf(flp, "%d ", p);
		fclose(flp);
		s = 0;
	}


}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

	//place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (STATE == STATE_INITIAL && a == 1 && (mx < 645 || mx > 773 || my < 330 || my > 456) && (mx < 0 || mx > 128 || my < 310 || my > 456))
		{
			STATE = STATE_NEW;
			startGrowing();
		}
		if (newscreen != 1 && mx >= 170 && mx <= 426 && my >= 30 && my <= 286){
			a = 1;
			m = 1;
		}
		if (newscreen != 1 && a == 0 && mx >= 500 && mx <= 756 && my >= 30 && my <= 286)
			exit(0);
		/*if (newscreen != 1 && a == 0 && mx >= 660 && mx <= 788 && my >= 460 && my <= 588)
		{
		save_game();
		a = 1;
		}*/
		if (a!=1&&newscreen != 1 && mx >= 660 && mx <= 788 && my >= 460 && my <= 588){
			save_game();
			if (life == 0){
				initial();
			}
			//if (life!=0)
			else {
				initial();
				save_game();
			}
			a = 1;
		}
		if (life == 0)
		{
			if (fll == 1&&mx >= 300 && mx <= 428 && my >= 220 && my < 348){
				//initial();
				exit(0);
			}
			if (fll == 1&&mx >= 450 && mx <= 578 && my >= 220 && my < 348){
				initial();
				//s = 0;
				//exit(0);
			}
		}
		if (newscreen!=2&&mx >= 350 && mx <= 478 && my >= 400 && my <= 432){
			newscreen = 1;
		}
		if (newscreen == 1 && mx >= 200 && mx <= 264 && my >= 330 && my <= 394)
		{
			a = 1;
			p = 0;
			n = 0;
		}
		if (newscreen == 1 && mx >= 350 && mx <= 414 && my >= 330 && my <= 394)
		{
			a = 1;
			n = 1;
			p = 0;
		}
		if (newscreen == 1 && mx >= 500 && mx <= 564 && my >= 330 && my <= 394)
		{
			a = 1;
			p = 1;
			n = 0;
		}
		if (a == 1 && mx >= 0 && mx <= 128 && my >= 310 && my <= 456){
			a = 0;
			m_ = 1;
			newscreen = 0;
		}
		if (a == 1 && mx >= 645 && mx <= 773 && my >= 330 && my <= 456){
			//a = 0;
			m_ = 1;
			//newscreen = 0;
			s = 1;
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (STATE == STATE_STICK_GROWING)
			stopGrowing();
	}
}
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key != ','){
		NAME[idx] = key;
		idx++;
	}
	else if (key == ',' && idx>0){
		idx--;
		NAME[idx] = '\0';
	}
	//lace your codes for other keys here
}
int main()
{
	srand(time(NULL));
	initial();
	sound1();
	iSettimer(5900, sound1);
	printf("%d", a);
	//place your own initialization codes here.
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "STICK HERO");
	return 0;
}

