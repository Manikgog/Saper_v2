#pragma once

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

/////////////////////////////////// преобразование номера строки в букву для прорисовки поля игры  ////////////////////////////////////////////
char Dec_to_alpha(int row) {
	char A;
	switch (row) {
	case 1:
		A = 'a';
		break;
	case 2:
		A = 'b';
		break;
	case 3:
		A = 'c';
		break;
	case 4:
		A = 'd';
		break;
	case 5:
		A = 'e';
		break;
	case 6:
		A = 'f';
		break;
	case 7:
		A = 'g';
		break;
	case 8:
		A = 'h';
		break;
	case 9:
		A = 'i';
		break;
	case 10:
		A = 'j';
		break;
	}

	return A;
}




//////////////////////////////////// функция для вывода игрового поля на экран///////////////////////////////////
int FrontEnd(int* ptr[], int nRow, int nCol)
{
	///////////////////////////////прорисовка поля для игры////////////////////////////
	if (nCol == 10) cout << "		Игра \"САПЕР\"" << "\n\n";
	if (nCol == 20) cout << "			    Игра \"САПЕР\"" << "\n\n";
	int _2count = 0;							// счётчик неоткрытых клеток
	int** Massiv = new int* [nRow]; //выделение памяти под массив указателей на строки размером Row
	//где каждый указатель содержит адрес строки, где каждая строка это динамический одномерный массив элементов типа int
	if (!Massiv) { cout << "Ошибка выделения памяти!" << endl; exit(1); };
	for (int i = 0; i < nRow; i++) //динамически выделяем память под каждую строку, нужного размера
	{
		//выделение памяти под динамический одномерный массив, хранящий значения элементов i-й строки
		Massiv[i] = new int[nCol]; //выделение памяти под строку кол-вом элементов Col
		if (!Massiv[i])
		{
			cout << "Ошибка выделения памяти!" << endl;
			//освобождение ранее выделенной памяти перед закрытием программы
			for (int j = i - 1; j >= 0; j--) //под уже созданные строки
			{
				delete[] Massiv[j];
				Massiv[j] = nullptr;
			}
			if (Massiv) //под массив указтелей
			{
				delete[] Massiv;
				Massiv = nullptr;
			}
			exit(1);
		}
	}

	cout << "      ";
	for (int i = 1; i <= nCol; i++)
	{
		if (i < 10) cout << " " << "\x1b[36m" << i << "\x1b[0m" << " "; //вывод нумерации столбцов
		if (i >= 10) cout << "\x1b[36m" << i << "\x1b[0m" << " ";
	}
	cout << endl;
	for (int i = 0; i < nRow; i++)
	{
		cout << "   ";

		
		cout << "\x1b[36m" << Dec_to_alpha(i + 1) << "\x1b[0m" << "  ";	//вывод нумерации строчек
		for (int j = 0; j < nCol; j++)
		{
			if (ptr[i][j] == -2 || ptr[i][j] == 0) //если клетка не открыта
			{
				cout << "[ ]";	//вывод обрамления клеточек
				_2count++; //подсчёт количества неоткрытых клеток
			}

			else if (ptr[i][j] == 9) cout << "   ";				//вывод клетки без мин
			else cout << " " << ptr[i][j] << " ";					//вывод обрамления клеточек
		}
		cout << endl;
	}
	cout << endl;

	/*
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nRow; j++)
		{
			if (ptr[i][j] >= 0) cout << " ";
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	*/
	//освобождение памяти
	//цикл освобождения памяти, выделенной под каждую строку, содержащую значения элементов типа int
	for (int i = 0; i < nRow; i++)
	{
		if (Massiv[i])
		{
			delete Massiv[i];
			Massiv[i] = nullptr;
		}
		else cout << "Память уже была освобождена!" << endl;
	}
	//освобождение памяти, выделенной под массив указателей, содержащий адреса строк
	if (Massiv)
	{
		delete[] Massiv;
		Massiv = nullptr;
	}
	else cout << "Память уже была освобождена!" << endl;
	return _2count;
}

int alpha_to_dec(char A) {
	int row = 1;
	switch (A) {
	case 'A':
		row = 1;
		break;
	case 'a':
		row = 1;
		break;
	case 'B':
		row = 2;
		break;
	case 'b':
		row = 2;
		break;
	case 'C':
		row = 3;
		break;
	case 'c':
		row = 3;
		break;
	case 'D':
		row = 4;
		break;
	case 'd':
		row = 4;
		break;
	case 'E':
		row = 5;
		break;
	case 'e':
		row = 5;
		break;
	case 'F':
		row = 6;
		break;
	case 'f':
		row = 6;
		break;
	case 'G':
		row = 7;
		break;
	case 'g':
		row = 7;
		break;
	case 'H':
		row = 8;
		break;
	case 'h':
		row = 8;
		break;
	case 'I':
		row = 9;
		break;
	case 'i':
		row = 9;
		break;
	case 'J':
		row = 10;
		break;
	case 'j':
		row = 10;
		break;
	}
	return row;
}


///////////////////////////функция для проверки ввода номера строки/////////////////////////////////
int Correct_Enter_Row(char A)
{
	int row = 1;
	cin >> A; //ввод номера строки или столбца
	do
	{
		if (A < 65 || (A > 74 && A < 97) || A > 106)
		{
			cout << "Некорректный ввод, введите букву от a до j включительно!" << endl;
			cin >> A;
		}
	} while (A < 65 || (A > 74 && A < 97) || A > 106);

	/////////////////////////////// преобразование буквы в цифру /////////////////////////////////////
	
	return alpha_to_dec(A);
}

int Correct_Enter_Col(int A, int B)
{
	cin >> A; //ввод номера строки или столбца
	do
	{
		if (A < 1 || A>B)
		{
			cout << "Некорректный ввод, введите цифру от 1 до " << B << " включительно!" << endl;
			cin >> A;
		}
	} while (A < 1 || A>B);
	return A;
}

/////////////////////////// функция вывода поля при подрыве на мине ///////////////////////////////
void Podriv(int* ptr1[], int Row, int Col)
{
	///////////////////////////////прорисовка поля для игры////////////////////////////
	if (Col == 10) cout << "		Игра \"САПЕР\"" << "\n\n";
	if (Col == 20) cout << "			    Игра \"САПЕР\"" << "\n\n";
	int _2count = 0;
	int** Massiv = new int* [Row]; //выделение памяти под массив указателей на строки размером Row
	//где каждый указатель содержит адрес строки, где каждая строка это динамический одномерный массив элементов типа int
	if (!Massiv) { cout << "Ошибка выделения памяти!" << endl; exit(1); };
	for (int i = 0; i < Row; i++) //динамически выделяем память под каждую строку, нужного размера
	{
		//выделение памяти под динамический одномерный массив, хранящий значения элементов i-й строки
		Massiv[i] = new int[Col]; //выделение памяти под строку кол-вом элементов Col
		if (!Massiv[i])
		{
			cout << "Ошибка выделения памяти!" << endl;
			//освобождение ранее выделенной памяти перед закрытием программы
			for (int j = i - 1; j >= 0; j--) //под уже созданные строки
			{
				delete[] Massiv[j];
				Massiv[j] = nullptr;
			}
			if (Massiv) //под массив указтелей
			{
				delete[] Massiv;
				Massiv = nullptr;
			}
			exit(1);
		}
	}
	cout << "      ";
	for (int i = 1; i <= Col; i++)
	{
		if (i < 10) cout << " " << "\x1b[36m" << i << "\x1b[0m" << " "; //вывод нумерации столбцов
		if (i >= 10) cout << "\x1b[36m" << i << "\x1b[0m" << " ";
	}
	cout << endl;
	for (int i = 0; i < Row; i++)
	{
		cout << "   ";

		cout << "\x1b[36m" << Dec_to_alpha(i + 1) << "\x1b[0m" << "  ";	//вывод нумерации строчек
		for (int j = 0; j < Col; j++)
		{
			if (ptr1[i][j] == 0)
			{
				cout << " \x1b[31m*\x1b[0m ";	//вывод бомб
				_2count++;
			}

			else if (ptr1[i][j] == 9) cout << "   ";				//вывод клетки без мин
			else cout << " " << ptr1[i][j] << " ";					//вывод количества бомб вокруг клетки
		}
		cout << endl;
	}
	cout << endl;
	//освобождение памяти
	//цикл освобождения памяти, выделенной под каждую строку, содержащую значения элементов типа int
	for (int i = 0; i < Row; i++)
	{
		if (Massiv[i])
		{
			delete Massiv[i];
			Massiv[i] = nullptr;
		}
		else cout << "Память уже была освобождена!" << endl;
	}
	//освобождение памяти, выделенной под массив указателей, содержащий адреса строк
	if (Massiv)
	{
		delete[] Massiv;
		Massiv = nullptr;
	}
	else cout << "Память уже была освобождена!" << endl;
	if (Col == 10) cout << "	\x1b[33mВы подорвались на мине!\x1b[0m" << endl;
	if (Col == 20) cout << "			\x1b[33mВы подорвались на мине!\x1b[0m" << endl;
}



/////////////////////////// функция вывода поля при победе ///////////////////////////////
void Pobeda(int* ptr1[], int Row, int Col)
{
	///////////////////////////////прорисовка поля для игры////////////////////////////
	if (Col == 10) cout << "		Игра \"САПЕР\"" << "\n\n";
	if (Col == 20) cout << "			    Игра \"САПЕР\"" << "\n\n";
	int _2count = 0;
	int** Massiv = new int* [Row]; //выделение памяти под массив указателей на строки размером Row
	//где каждый указатель содержит адрес строки, где каждая строка это динамический одномерный массив элементов типа int
	if (!Massiv) { cout << "Ошибка выделения памяти!" << endl; exit(1); };
	for (int i = 0; i < Row; i++) //динамически выделяем память под каждую строку, нужного размера
	{
		//выделение памяти под динамический одномерный массив, хранящий значения элементов i-й строки
		Massiv[i] = new int[Col]; //выделение памяти под строку кол-вом элементов Col
		if (!Massiv[i])
		{
			cout << "Ошибка выделения памяти!" << endl;
			//освобождение ранее выделенной памяти перед закрытием программы
			for (int j = i - 1; j >= 0; j--) //под уже созданные строки
			{
				delete[] Massiv[j];
				Massiv[j] = nullptr;
			}
			if (Massiv) //под массив указтелей
			{
				delete[] Massiv;
				Massiv = nullptr;
			}
			exit(1);
		}
	}
	cout << "      ";
	for (int i = 1; i <= Col; i++)
	{
		if (i < 10) cout << " " << "\x1b[36m" << i << "\x1b[0m" << " "; //вывод нумерации столбцов
		if (i >= 10) cout << "\x1b[36m" << i << "\x1b[0m" << " ";
	}
	cout << endl;
	for (int i = 0; i < Row; i++)
	{
		cout << "   ";

		cout << "\x1b[36m" << Dec_to_alpha(i + 1) << "\x1b[0m" << "  ";	//вывод нумерации строчек
		for (int j = 0; j < Col; j++)
		{
			if (ptr1[i][j] == 0)
			{
				cout << " \x1b[32m*\x1b[0m ";	//вывод бомб
				_2count++;
			}

			else if (ptr1[i][j] == 9) cout << "   ";				//вывод клетки без мин
			else cout << " " << ptr1[i][j] << " ";					//вывод количества бомб вокруг клетки
		}
		cout << endl;
	}
	cout << endl;
	//освобождение памяти
	//цикл освобождения памяти, выделенной под каждую строку, содержащую значения элементов типа int
	for (int i = 0; i < Row; i++)
	{
		if (Massiv[i])
		{
			delete Massiv[i];
			Massiv[i] = nullptr;
		}
		else cout << "Память уже была освобождена!" << endl;
	}
	//освобождение памяти, выделенной под массив указателей, содержащий адреса строк
	if (Massiv)
	{
		delete[] Massiv;
		Massiv = nullptr;
	}
	else cout << "Память уже была освобождена!" << endl;
}

