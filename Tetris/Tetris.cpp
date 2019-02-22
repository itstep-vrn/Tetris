/*
	Игра "Тетрис"
	Учебный проект консольной версии игры "Тетрис"
	(c) Starinin Andrey, Kitavina Natal'ya, Sanzharovskiy Dmitry, Karygin Roman, Frolov Dmitry, Bardin Valentin, Bryantsev Vsevolod, Ivutin Anton, Protsenko Vyacheslav, Protsenko Mikhail
	(c) Компьютерная академия ШАГ. Воронеж
	Версия: 0.1 (Февраль 2019 г.)
*/

#include <iostream>
#include "pch.h"

using namespace std;

const int ROW = 20; // количество строк
const int COL = 10; // количество столбцов

int game_place[ROW][COL] = {}; // двумерный массив размерностью 20х10 (игровое поле)

int score = 0; // подсчёт очков
int temp; // временная переменная, для подсчёта заполненности строки

/*
	Типы фигур:
	1 - I (палка)
	2 - J
	3 - L
	4 - 0 (квадрат)
	5 - S
	6 - Z
	7 - T
*/
void InitFig_I(int position);
void InitFig_J(int position);
void InitFig_L(int position);
void InitFig_O();                 //
void InitFig_S(int position);
void InitFig_Z(int position);
void InitFig_T(int position);
void StartFig(int type, int position);

bool RowFull(int row); // определение заполненности строки
int GameScore(); // определение очков
void DeleteRow(); // удаление заполненной строки

bool GameOver(); // определение проигрыша


int main()
{

}

void Fig_I_Pos1(int x,int y) //I горизонталь
{
	game_place[x][y] = 1;
	game_place[x][y+1] = 1;
	game_place[x][y+2] = 1;
	game_place[x][y+3] = 1;
}
void Fig_I_Pos2(int x, int y)// I вертикаль
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x+2][y] = 1;
	game_place[x+3][y] = 1;
}

void Fig_J_Pos1(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x+2][y-1] = 1;
	game_place[x+2][y] = 1;
}

void Fig_J_Pos2(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x][y+1] = 1;
	game_place[x][y+2] = 1;
	game_place[x-1][5] = 1;
}

void Fig_J_Pos3(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x][y+1] = 1;
	game_place[x+1][y] = 1;
	game_place[x+2][y] = 1;
}

void Fig_J_Pos4(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x][y-1] = 1;
	game_place[x][y-2] = 1;
}

void Fig_Z_Pos1(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x][y+1] = 1;
	game_place[x+1][y-1] = 1;
}

void Fig_Z_Pos2(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x+1][y+1] = 1;
	game_place[x+1][y+1] = 1;
}

void Fig_T_Pos1(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x][y-1] = 1;
	game_place[x][y+1] = 1;
}

void Fig_T_Pos2(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x+2][y] = 1;
	game_place[x+2][y-1] = 1;
}

void Fig_T_Pos3(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x+1][y-1] = 1;
	game_place[x+1][y+1] = 1;
}

void Fig_T_Pos4(int x, int y)
{
	game_place[x][y] = 1;
	game_place[x+1][y] = 1;
	game_place[x+2][y] = 1;
	game_place[x+2][y+1] = 1;
}

void InitFig_I(int position)
{
	switch (position)
	{
	case 1: // горизонтальное положение
	{
		Fig_I_Pos1(0, 3);
		
	}
	break;
	case 2: // вертикальное положение
	{
		Fig_I_Pos2(0, 5);
	}
	break;
	}
}

void InitFig_O(int position)
{
	game_place[0][4] = 1;
	game_place[0][5] = 1;
	game_place[1][4] = 1;
	game_place[1][5] = 1;
}

void InitFig_J(int position)
{
	switch (position)
	{
	case 1: 
	{
		Fig_J_Pos1(0,5);
		
	}
		break;
	case 2:
	{
		Fig_J_Pos2(1, 5);
		
	}
		break;
	case 3: 
	{
		Fig_J_Pos3(0, 5);
		
	}
		break;
	case 4: 
	{

		Fig_J_Pos4(0, 5);
	
	}
	break;
	}
}

void InitFig_Z(int position)
{
	switch (position)
	{
	case 1:
	{
		Fig_Z_Pos1(0, 5);
		
	}
	break;
	case 2:
	{

		Fig_Z_Pos2(0,5);
		
	}
		break;
	}
}
void InitFig_T(int position)
{
	switch (position)
	{
	case 1:
	{

		Fig_T_Pos1(0, 5);
		
	}
	break;
	case 2:
	{  
		Fig_T_Pos2(0,5);
		
	}
	break;
	case 3:
	{

		Fig_T_Pos3(0, 5);
		;
	}
	break;
	case 4:
	{

		Fig_T_Pos4(0, 5);
		
	}
	break;
	}
}

void StartFig(int type, int position)
{
	switch (type)
	{
	case 1: InitFig_I(position);
		break;
	case 2: InitFig_J(position);
		break;
	case 3: InitFig_L(position);
		break;
	case 4: InitFig_O();
		break;
	case 5: InitFig_S(position);
		break;
	case 6: InitFig_Z(position);
		break;
	case 7: InitFig_T(position);
		break;
	default:
		break;
	}
}

bool RowFull(int row)
{
	temp = 0;
	for (int j = 0; j < COL; j++)
	{
		temp = temp + game_place[row][j];
	}

	if (temp == 10)
		return true;
	else
		return false;
}

int GameScore()
{

	int k = 0; // переменная, подсчёт заполненных строк
	for (int i = 0; i < ROW; i++)
	{
		if (RowFull(i)) // если строка заполенная, то увеличиваем счётчик заполненных строк на 1
			k++;
	}

	switch (k)
	{
	case 1: return 100; // при заполнении одной строки даётся 100 очков
		break;
	case 2: return 300; // при заполнении двух строк даётся 300 очков
		break;
	case 3: return 700; // при заполнении трёх строк даётся 700 очков
		break;
	case 4: return 1500; // при заполнении четырёх строк даётся 1500 очков
		break;
	default: return 0;
		break;
	}
}

void DeleteRow()
{
	int m = 0;

	for (int i = 0; i < ROW; i++)
	{
		if (RowFull(i))
		{
			m = i;
			do {
				for (int j = 0; j < COL; j++)
				{
					game_place[m][j] = game_place[m - 1][j];
				}
				m--;
			} while (m != 0);

		}
	}
}

bool GameOver()
{
	// функция проверяет верхнюю строчку игрового поля на наличие в ней "1" (признак фигуры), если есть хоть одна единица - проигрыш
	for (int i = 0; i < COL; i++)
	{
		if (game_place[0][i] == 1)
			return true;
		else
			return false;
	}
}
