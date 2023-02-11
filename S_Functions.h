#pragma once

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

/////////////////////////////////// �������������� ������ ������ � ����� ��� ���������� ���� ����  ////////////////////////////////////////////
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




//////////////////////////////////// ������� ��� ������ �������� ���� �� �����///////////////////////////////////
int FrontEnd(int* ptr[], int nRow, int nCol)
{
	///////////////////////////////���������� ���� ��� ����////////////////////////////
	if (nCol == 10) cout << "		���� \"�����\"" << "\n\n";
	if (nCol == 20) cout << "			    ���� \"�����\"" << "\n\n";
	int _2count = 0;							// ������� ���������� ������
	int** Massiv = new int* [nRow]; //��������� ������ ��� ������ ���������� �� ������ �������� Row
	//��� ������ ��������� �������� ����� ������, ��� ������ ������ ��� ������������ ���������� ������ ��������� ���� int
	if (!Massiv) { cout << "������ ��������� ������!" << endl; exit(1); };
	for (int i = 0; i < nRow; i++) //����������� �������� ������ ��� ������ ������, ������� �������
	{
		//��������� ������ ��� ������������ ���������� ������, �������� �������� ��������� i-� ������
		Massiv[i] = new int[nCol]; //��������� ������ ��� ������ ���-��� ��������� Col
		if (!Massiv[i])
		{
			cout << "������ ��������� ������!" << endl;
			//������������ ����� ���������� ������ ����� ��������� ���������
			for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
			{
				delete[] Massiv[j];
				Massiv[j] = nullptr;
			}
			if (Massiv) //��� ������ ���������
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
		if (i < 10) cout << " " << "\x1b[36m" << i << "\x1b[0m" << " "; //����� ��������� ��������
		if (i >= 10) cout << "\x1b[36m" << i << "\x1b[0m" << " ";
	}
	cout << endl;
	for (int i = 0; i < nRow; i++)
	{
		cout << "   ";

		
		cout << "\x1b[36m" << Dec_to_alpha(i + 1) << "\x1b[0m" << "  ";	//����� ��������� �������
		for (int j = 0; j < nCol; j++)
		{
			if (ptr[i][j] == -2 || ptr[i][j] == 0) //���� ������ �� �������
			{
				cout << "[ ]";	//����� ���������� ��������
				_2count++; //������� ���������� ���������� ������
			}

			else if (ptr[i][j] == 9) cout << "   ";				//����� ������ ��� ���
			else cout << " " << ptr[i][j] << " ";					//����� ���������� ��������
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
	//������������ ������
	//���� ������������ ������, ���������� ��� ������ ������, ���������� �������� ��������� ���� int
	for (int i = 0; i < nRow; i++)
	{
		if (Massiv[i])
		{
			delete Massiv[i];
			Massiv[i] = nullptr;
		}
		else cout << "������ ��� ���� �����������!" << endl;
	}
	//������������ ������, ���������� ��� ������ ����������, ���������� ������ �����
	if (Massiv)
	{
		delete[] Massiv;
		Massiv = nullptr;
	}
	else cout << "������ ��� ���� �����������!" << endl;
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


///////////////////////////������� ��� �������� ����� ������ ������/////////////////////////////////
int Correct_Enter_Row(char A)
{
	int row = 1;
	cin >> A; //���� ������ ������ ��� �������
	do
	{
		if (A < 65 || (A > 74 && A < 97) || A > 106)
		{
			cout << "������������ ����, ������� ����� �� a �� j ������������!" << endl;
			cin >> A;
		}
	} while (A < 65 || (A > 74 && A < 97) || A > 106);

	/////////////////////////////// �������������� ����� � ����� /////////////////////////////////////
	
	return alpha_to_dec(A);
}

int Correct_Enter_Col(int A, int B)
{
	cin >> A; //���� ������ ������ ��� �������
	do
	{
		if (A < 1 || A>B)
		{
			cout << "������������ ����, ������� ����� �� 1 �� " << B << " ������������!" << endl;
			cin >> A;
		}
	} while (A < 1 || A>B);
	return A;
}

/////////////////////////// ������� ������ ���� ��� ������� �� ���� ///////////////////////////////
void Podriv(int* ptr1[], int Row, int Col)
{
	///////////////////////////////���������� ���� ��� ����////////////////////////////
	if (Col == 10) cout << "		���� \"�����\"" << "\n\n";
	if (Col == 20) cout << "			    ���� \"�����\"" << "\n\n";
	int _2count = 0;
	int** Massiv = new int* [Row]; //��������� ������ ��� ������ ���������� �� ������ �������� Row
	//��� ������ ��������� �������� ����� ������, ��� ������ ������ ��� ������������ ���������� ������ ��������� ���� int
	if (!Massiv) { cout << "������ ��������� ������!" << endl; exit(1); };
	for (int i = 0; i < Row; i++) //����������� �������� ������ ��� ������ ������, ������� �������
	{
		//��������� ������ ��� ������������ ���������� ������, �������� �������� ��������� i-� ������
		Massiv[i] = new int[Col]; //��������� ������ ��� ������ ���-��� ��������� Col
		if (!Massiv[i])
		{
			cout << "������ ��������� ������!" << endl;
			//������������ ����� ���������� ������ ����� ��������� ���������
			for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
			{
				delete[] Massiv[j];
				Massiv[j] = nullptr;
			}
			if (Massiv) //��� ������ ���������
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
		if (i < 10) cout << " " << "\x1b[36m" << i << "\x1b[0m" << " "; //����� ��������� ��������
		if (i >= 10) cout << "\x1b[36m" << i << "\x1b[0m" << " ";
	}
	cout << endl;
	for (int i = 0; i < Row; i++)
	{
		cout << "   ";

		cout << "\x1b[36m" << Dec_to_alpha(i + 1) << "\x1b[0m" << "  ";	//����� ��������� �������
		for (int j = 0; j < Col; j++)
		{
			if (ptr1[i][j] == 0)
			{
				cout << " \x1b[31m*\x1b[0m ";	//����� ����
				_2count++;
			}

			else if (ptr1[i][j] == 9) cout << "   ";				//����� ������ ��� ���
			else cout << " " << ptr1[i][j] << " ";					//����� ���������� ���� ������ ������
		}
		cout << endl;
	}
	cout << endl;
	//������������ ������
	//���� ������������ ������, ���������� ��� ������ ������, ���������� �������� ��������� ���� int
	for (int i = 0; i < Row; i++)
	{
		if (Massiv[i])
		{
			delete Massiv[i];
			Massiv[i] = nullptr;
		}
		else cout << "������ ��� ���� �����������!" << endl;
	}
	//������������ ������, ���������� ��� ������ ����������, ���������� ������ �����
	if (Massiv)
	{
		delete[] Massiv;
		Massiv = nullptr;
	}
	else cout << "������ ��� ���� �����������!" << endl;
	if (Col == 10) cout << "	\x1b[33m�� ����������� �� ����!\x1b[0m" << endl;
	if (Col == 20) cout << "			\x1b[33m�� ����������� �� ����!\x1b[0m" << endl;
}



/////////////////////////// ������� ������ ���� ��� ������ ///////////////////////////////
void Pobeda(int* ptr1[], int Row, int Col)
{
	///////////////////////////////���������� ���� ��� ����////////////////////////////
	if (Col == 10) cout << "		���� \"�����\"" << "\n\n";
	if (Col == 20) cout << "			    ���� \"�����\"" << "\n\n";
	int _2count = 0;
	int** Massiv = new int* [Row]; //��������� ������ ��� ������ ���������� �� ������ �������� Row
	//��� ������ ��������� �������� ����� ������, ��� ������ ������ ��� ������������ ���������� ������ ��������� ���� int
	if (!Massiv) { cout << "������ ��������� ������!" << endl; exit(1); };
	for (int i = 0; i < Row; i++) //����������� �������� ������ ��� ������ ������, ������� �������
	{
		//��������� ������ ��� ������������ ���������� ������, �������� �������� ��������� i-� ������
		Massiv[i] = new int[Col]; //��������� ������ ��� ������ ���-��� ��������� Col
		if (!Massiv[i])
		{
			cout << "������ ��������� ������!" << endl;
			//������������ ����� ���������� ������ ����� ��������� ���������
			for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
			{
				delete[] Massiv[j];
				Massiv[j] = nullptr;
			}
			if (Massiv) //��� ������ ���������
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
		if (i < 10) cout << " " << "\x1b[36m" << i << "\x1b[0m" << " "; //����� ��������� ��������
		if (i >= 10) cout << "\x1b[36m" << i << "\x1b[0m" << " ";
	}
	cout << endl;
	for (int i = 0; i < Row; i++)
	{
		cout << "   ";

		cout << "\x1b[36m" << Dec_to_alpha(i + 1) << "\x1b[0m" << "  ";	//����� ��������� �������
		for (int j = 0; j < Col; j++)
		{
			if (ptr1[i][j] == 0)
			{
				cout << " \x1b[32m*\x1b[0m ";	//����� ����
				_2count++;
			}

			else if (ptr1[i][j] == 9) cout << "   ";				//����� ������ ��� ���
			else cout << " " << ptr1[i][j] << " ";					//����� ���������� ���� ������ ������
		}
		cout << endl;
	}
	cout << endl;
	//������������ ������
	//���� ������������ ������, ���������� ��� ������ ������, ���������� �������� ��������� ���� int
	for (int i = 0; i < Row; i++)
	{
		if (Massiv[i])
		{
			delete Massiv[i];
			Massiv[i] = nullptr;
		}
		else cout << "������ ��� ���� �����������!" << endl;
	}
	//������������ ������, ���������� ��� ������ ����������, ���������� ������ �����
	if (Massiv)
	{
		delete[] Massiv;
		Massiv = nullptr;
	}
	else cout << "������ ��� ���� �����������!" << endl;
}

