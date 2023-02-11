// Saper.cpp
#include <vector>
#include "S_Functions.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int Number_row = 0; //���������� ����� �������������� � ������
	int Number_col = 0; //���������� ����� �������������� � �������
	int AmountOfMines = 0;			//���������� ��� ������ ������
	bool BoomFlag = 0, Game_Over = 0;
	int Row = 10, Col = 10;
	int count_null = 0, Uroven = 1;
	do
	{

		int count = 0;			// ������� �������� ������
		int Razmer = 1;			//������ ������� ����
		system("cls");
		do
		{
			system("cls");
			do
			{
				cout << "�������� ������ ������� ����";
				cout << R"(
10X10 - ������� 1
10X20 - ������� 2
���� ������ ��������� - ������� 0
)";
				cin >> Razmer;
			} while (Razmer < 0 || Razmer > 2);
			if (Razmer == 1) Col = 10;
			if (Razmer == 2) Col = 20;
			if (Razmer == 0) break;
			system("cls");
			cout << "�������� ������� ���������";
			cout << R"(
����� - ������� 1
������� - ������� 2
������� - ������� 3
���� ������ ��������� - ������� 0
)";
			cin >> Uroven;
		} while (Uroven < 0 || Uroven > 3);
		system("cls");
		if (Uroven == 1 && Razmer == 1) count_null = 10;
		if (Uroven == 1 && Razmer == 2) count_null = 20;
		if (Uroven == 2 && Razmer == 1) count_null = 15;
		if (Uroven == 2 && Razmer == 2) count_null = 30;
		if (Uroven == 3 && Razmer == 1) count_null = 20;
		if (Uroven == 3 && Razmer == 2) count_null = 40;
		if (Uroven == 0) break;				//����� �� ����
		int** Array = new int* [Row]; //��������� ������ ��� ������ ���������� �� ������ �������� Row
		//��� ������ ��������� �������� ����� ������, ��� ������ ������ ��� ������������ ���������� ������ ��������� ���� int
		if (!Array) { cout << "������ ��������� ������!" << endl; exit(1); };
		for (int i = 0; i < Row; i++) //����������� �������� ������ ��� ������ ������, ������� �������
		{
			//��������� ������ ��� ������������ ���������� ������, �������� �������� ��������� i-� ������
			Array[i] = new int[Col]; //��������� ������ ��� ������ ���-��� ��������� Col
			if (!Array[i])
			{
				cout << "������ ��������� ������!" << endl;
				//������������ ����� ���������� ������ ����� ��������� ���������
				for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
				{
					delete[] Array[j];
					Array[j] = nullptr;
				}
				if (Array) //��� ������ ���������
				{
					delete[] Array;
					Array = nullptr;
				}
				exit(1);
			}
		}
		////////////////////////////////////// ���������� ������� ������ � ���������. ���� � ������ 0, �� �������, ��� ������ ������������.
		/*do
		{
			int K = 0;
			if (count_null == 10) K = 6;
			if (count_null == 15 || count_null == 20) K = 3;
			if (count_null == 30 || count_null == 40) K = 3;
			bool kubik = rand() % 2;
			bool kubik_2 = rand() % 2;
			bool kubik_3 = rand() % 2;
			if (kubik == 0)
			{
				if (kubik_2 == 0)
				{
					for (int i = 0; i < Row; i++) // ���������� ���� ������ ������ ���� � ����� �������
					{
						for (int j = 0; j < Col; j++)
							{
								Array[i][j] = rand() % K;
								if (Array[i][j] != 0) Array[i][j] = 1;
								else
								{
									count_null--;
									if (count_null >= 0) Array[i][j] = 0;
									else Array[i][j] = 1;
								}
							}
					}
				}
				else
				{
					for (int i = 0; i < Row; i++) // ���������� ���� ������ ������ ���� � ������ ������
					{

						for (int j = 0; j < Col; j++)
						{
							Array[i][j] = rand() % K;
							if (Array[i][j] != 0) Array[i][j] = 1;
							else
							{
								count_null--;
								if (count_null >= 0) Array[i][j] = 0;
								else Array[i][j] = 1;
							}
						}
					}
				}
			}
			else
			{
				if (kubik_2 == 0)
				{
					for (int i = Row-1; i >= 0; i--) //���������� ���� ������ ����� ����� � ����� �������
					{

						for (int j = 0; j < Col; j++)
						{
							Array[i][j] = rand() % K;
							if (Array[i][j] != 0) Array[i][j] = 1;
							else
							{
								count_null--;
								if (count_null >= 0) Array[i][j] = 0;
								else Array[i][j] = 1;
							}
						}
					}
				}
				else
				{
					for (int i = Row-1; i >= 0; i--) //���������� ���� ������ ����� ����� � ������ ������
					{

						for (int j = Col-1; j >= 0; j--)
						{
							Array[i][j] = rand() % K;
							if (Array[i][j] != 0) Array[i][j] = 1;
							else
							{
								count_null--;
								if (count_null >= 0) Array[i][j] = 0;
								else Array[i][j] = 1;
							}
						}
					}
				}
			}
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					//cout << Array[i][j] << " ";
				}
				//cout << endl;
			}
		} while (count_null>=0); */

		int* arr = new int[count_null];

		for (int i = 0; i < count_null; ) {
			bool flag = false;

			arr[i] = rand() % 100;

			for (int j = 0; j < i; ++j) {
				if (arr[i] == arr[j]) {
					flag = true;
					break;
				}
			}

			if (flag == false) {
				//std::cout << arr[i] << ", ";
				i++;
			}
		}



		for (int i = 0; i < count_null; ++i) {
			if (Razmer == 1) {
				int x = arr[i] % 10;
				int y = arr[i] / 10;
				Array[x][y] = 0;
			}
			else if (Razmer == 2) {
				int x = arr[i] % 10;
				int y = rand() % 20;
				Array[x][y] = 0;
			}
		}

		for (int i = 0; i < Row; ++i) {
			for (int j = 0; j < Col; ++j) {
				if (Array[i][j]) {
					Array[i][j] = 1;
				}
			}
		}
		delete[] arr;
		/*
		//cout << endl;
		//cout << "kubik = " << kubik << endl;
		//cout << "kubik_2 = " << kubik_2 << endl;
		//cout << "count = " << count << endl;
		*/
		///////////////////////////////////// �������� ������ ������ ��� ������ -1, � ���� ������ ������ ��� ��� (�.�. �����), �� ������ ����� 9
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (Array[i][j] == 0)
				{
					count++;
					// �������� ����� ������ ��� ��� ������������ �������
					for (int n = i - 1; n < i + 2; n++)
					{
						if (n < 0 || n>Row - 1) continue;			//����� �� ������� ����
						for (int m = j - 1; m < j + 2; m++)
						{
							if (m < 0 || m > Col - 1) continue;	//����� �� ������� ����
							if (Array[n][m] == 0) continue;
							Array[n][m] = -1;				//������� ������ ����
						}
					}
					Array[i][j] = 0;
				}
				if (Array[i][j] != 0 && Array[i][j] != -1) Array[i][j] = 9;
			}
		}

		///////////////////////////////////////�������� ������� ������� �� ����� //////////////////////////////////////////////
		/*
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (Array[i][j] > 0) cout << " ";
				//cout << Array[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		//////////////////////////////////////// ������� ���������� ��� � ������� � ���� ������� /////////////////////////////////
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				AmountOfMines = 0;
				if (Array[i][j] == -1)
				{
					//������� ���������� ��� ������ ������
					for (int n = i - 1; n < i + 2; n++)
					{
						if (n < 0 || n>Row - 1) continue;			//����� �� ������� ����
						for (int m = j - 1; m < j + 2; m++)
						{
							if (m < 0 || m > Col - 1) continue;	//����� �� ������� ����
							if (Array[n][m] == 0) AmountOfMines++;
						}
					}
					Array[i][j] = AmountOfMines;
				}
			}
		}
		//////////////////////////�������� ������� ������� �� �����//////////////////////

		/*for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				//if (Array[i][j] >= 0) cout << " ";
				//cout << Array[i][j] << " ";
			}
			//cout << endl;
		}
		//cout << endl;*/

		///////////////���� ��������� ����� �������������� � ��������/////////////////////
		int** TempArray = new int* [Row]; //��������� ������ ��� ������ ���������� �� ������ �������� Row
		//��� ������ ��������� �������� ����� ������, ��� ������ ������ ��� ������������ ���������� ������ ��������� ���� int
		if (!TempArray) { cout << "������ ��������� ������!" << endl; exit(1); };
		for (int i = 0; i < Row; i++) //����������� �������� ������ ��� ������ ������, ������� �������
		{
			//��������� ������ ��� ������������ ���������� ������, �������� �������� ��������� i-� ������
			TempArray[i] = new int[Col]; //��������� ������ ��� ������ ���-��� ��������� Col
			if (!TempArray[i])
			{
				cout << "������ ��������� ������!" << endl;
				//������������ ����� ���������� ������ ����� ��������� ���������
				for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
				{
					delete[] TempArray[j];
					TempArray[j] = nullptr;
				}
				if (TempArray) //��� ������ ���������
				{
					delete[] Array;
					TempArray = nullptr;
				}
				exit(1);
			}
		}

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				TempArray[i][j] = -2;
			}
		}
		int** ptr = new int* [Row];
		if (!ptr) { cout << "������ ��������� ������!" << endl; exit(1); };
		for (int i = 0; i < Row; i++)
		{
			ptr[i] = new int[Col];
			if (!ptr[i])
			{
				cout << "������ ��������� ������!" << endl;
				//������������ ����� ���������� ������ ����� ��������� ���������
				for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
				{
					delete[] ptr[j];
					ptr[j] = nullptr;
				}
				if (ptr) //��� ������ ���������
				{
					delete[] ptr;
					ptr = nullptr;
				}
				exit(1);
			}
			ptr[i] = TempArray[i];
		}
		int** ptr1 = new int* [Row];
		if (!ptr1) { cout << "������ ��������� ������!" << endl; exit(1); };
		for (int i = 0; i < Row; i++)
		{
			ptr1[i] = new int[Col];
			if (!ptr1[i])
			{
				cout << "������ ��������� ������!" << endl;
				//������������ ����� ���������� ������ ����� ��������� ���������
				for (int j = i - 1; j >= 0; j--) //��� ��� ��������� ������
				{
					delete[] ptr1[j];
					ptr1[j] = nullptr;
				}
				if (ptr1) //��� ������ ���������
				{
					delete[] ptr1;
					ptr1 = nullptr;
				}
				exit(1);
			}
			ptr1[i] = Array[i];
		}
		FrontEnd(ptr, Row, Col);
		Game_Over = 0;
		do
		{
			//cout << "count = " << count << endl; //����� ���������� ���
			cout << "������� ���������� ����� ��������������" << endl;
			cout << "������� ����� ������: ";
			Number_row = Correct_Enter_Row(Number_row);
			cout << "������� ����� �������: ";
			Number_col = Correct_Enter_Col(Number_col, Col);
			system("cls");
			//cout << "���������� ����� ��������������: " << Number_row << "-� ������, " << Number_col << "-� �������." << endl;

			//cout << "Array[" << Number_row << "][" << Number_col << "]= " << Array[Number_row-1][Number_col-1] << endl;
			if (Array[Number_row - 1][Number_col - 1] == 0)
			{
				system("cls");
				Podriv(ptr1, Row, Col); // ����� ������� �� ����������� ���� ��� ��������� � ����
				//������������ ������
				//���� ������������ ������, ���������� ��� ������ ������, ���������� �������� ��������� ���� int
				for (int i = 0; i < Row; i++)
				{
					if (Array[i])
					{
						delete Array[i];
						delete TempArray[i];
						//delete ptr[i];
						//delete ptr1[i];
						Array[i] = nullptr;
						TempArray[i] = nullptr;
						//ptr[i] = nullptr;
						//ptr1[i] = nullptr;
					}
					else cout << "������ ��� ���� �����������!" << endl;
				}
				//������������ ������, ���������� ��� ������ ����������, ���������� ������ �����
				if (Array)
				{
					delete[] Array;
					delete[] TempArray;
					//delete[] ptr;
					//delete[] ptr1;
					Array = nullptr;
					TempArray = nullptr;
					//ptr = nullptr;
					//ptr1 = nullptr;
				}
				else cout << "������ ��� ���� �����������!" << endl;

				Game_Over = 1;
			}
			else
			{
				if (TempArray[Number_row - 1][Number_col - 1] == 9 || (TempArray[Number_row - 1][Number_col - 1] >= 1 && TempArray[Number_row - 1][Number_col - 1] <= 8))
				{
					int _2count = FrontEnd(ptr, Row, Col); //������� ���������� ���� � ���������� ���������� ���������� ����������� ������
					continue;
				}
				else
				{
					for (int n = (Number_row - 1) - 1; n <= (Number_row - 1) + 1; n++)
					{
						if (n < 0 || n>(Row - 1)) continue;			//����� �� ������� ����
						for (int m = (Number_col - 1) - 1; m <= (Number_col - 1) + 1; m++)
						{
							if (m < 0 || m >(Col - 1)) continue;	//����� �� ������� ����
							if (Array[n][m] == 9)
							{
								TempArray[n][m] = Array[n][m];   // ���� ������ ������ � ������ ��� ���, �� ��������� �������� ������ ���������� ������� TempArray ��� �������� � ������ ��� ����������
								for (int i = n - 1; i <= n + 1; i++)
								{
									if (i < 0 || i >(Row - 1)) continue;	//����� �� ������� ����
									for (int j = m - 1; j <= m + 1; j++)
									{
										if (j < 0 || j >(Col - 1)) continue;	//����� �� ������� ����
										if (Array[i][j] == 9)
										{
											TempArray[i][j] = Array[i][j];
											for (int n = i - 1; n <= i + 1; n++)
											{
												if (n < 0 || n >(Row - 1)) continue;	//����� �� ������� ����
												for (int m = j - 1; m <= j + 1; m++)
												{
													if (m < 0 || m >(Col - 1)) continue;	//����� �� ������� ����
													if (Array[n][m] == 9)
													{
														TempArray[n][m] = Array[n][m];
														for (int i = n - 1; i <= n + 1; i++)
														{
															if (i < 0 || i >(Row - 1)) continue;	//����� �� ������� ����
															for (int j = m - 1; j <= m + 1; j++)
															{
																if (j < 0 || j >(Col - 1)) continue;	//����� �� ������� ����
																if (Array[i][j] == 9)
																{
																	TempArray[i][j] = Array[i][j];
																	for (int n = i - 1; n <= i + 1; n++)
																	{
																		if (n < 0 || n >(Row - 1)) continue;	//����� �� ������� ����
																		for (int m = j - 1; m <= j + 1; m++)
																		{
																			if (m < 0 || m >(Col - 1)) continue;	//����� �� ������� ����
																			if (Array[n][m] == 9)
																			{
																				TempArray[n][m] = Array[n][m];
																				for (int i = n - 1; i <= n + 1; i++)
																				{
																					if (i < 0 || i >(Row - 1)) continue;	//����� �� ������� ����
																					for (int j = m - 1; j <= m + 1; j++)
																					{
																						if (j < 0 || j >(Col - 1)) continue;	//����� �� ������� ����
																						if (Array[i][j] == 9)
																						{
																							TempArray[i][j] = Array[i][j];
																							for (int n = i - 1; n <= i + 1; n++)
																							{
																								if (n < 0 || n >(Row - 1)) continue;	//����� �� ������� ����
																								for (int m = j - 1; m <= j + 1; m++)
																								{
																									if (m < 0 || m >(Col - 1)) continue;	//����� �� ������� ����
																									if (Array[n][m] == 9)
																									{
																										TempArray[n][m] = Array[n][m];
																										for (int i = n - 1; i <= n + 1; i++)
																										{
																											if (i < 0 || i >(Row - 1)) continue;	//����� �� ������� ����
																											for (int j = m - 1; j <= m + 1; j++)
																											{
																												if (j < 0 || j >(Col - 1)) continue;	//����� �� ������� ����
																												if (Array[i][j] == 9)
																												{
																													TempArray[i][j] = Array[i][j];
																													for (int n = i - 1; n <= i + 1; n++)
																													{
																														if (n < 0 || n >(Row - 1)) continue;	//����� �� ������� ����
																														for (int m = j - 1; m <= j + 1; m++)
																														{
																															if (m < 0 || m >(Col - 1)) continue;	//����� �� ������� ����
																															if (Array[n][m] == 9)
																															{
																																TempArray[n][m] = Array[n][m];
																																for (int i = n - 1; i <= n + 1; i++)
																																{
																																	if (i < 0 || i >(Row - 1)) continue;	//����� �� ������� ����
																																	for (int j = m - 1; j <= m + 1; j++)
																																	{
																																		if (j < 0 || j >(Col - 1)) continue;	//����� �� ������� ����
																																		if (Array[i][j] == 9)
																																		{
																																			TempArray[i][j] = Array[i][j];
																																		}
																																		if (Array[i][j] >= 1 && Array[i][j] <= 8) TempArray[i][j] = Array[i][j];
																																	}
																																}
																															}
																															if (Array[n][m] >= 1 && Array[n][m] <= 8) TempArray[n][m] = Array[n][m];
																														}
																													}
																												}
																												if (Array[i][j] >= 1 && Array[i][j] <= 8) TempArray[i][j] = Array[i][j];
																											}
																										}
																									}
																									if (Array[n][m] >= 1 && Array[n][m] <= 8) TempArray[n][m] = Array[n][m];
																								}
																							}
																						}
																						if (Array[i][j] >= 1 && Array[i][j] <= 8) TempArray[i][j] = Array[i][j];
																					}
																				}
																			}
																			if (Array[n][m] >= 1 && Array[n][m] <= 8) TempArray[n][m] = Array[n][m];
																		}
																	}
																}
																if (Array[i][j] >= 1 && Array[i][j] <= 8) TempArray[i][j] = Array[i][j];
															}
														}
													}
													if (Array[n][m] >= 1 && Array[n][m] <= 8) TempArray[n][m] = Array[n][m];
												}
											}
										}
										if (Array[i][j] >= 1 && Array[i][j] <= 8) TempArray[i][j] = Array[i][j];
									}
								}
							}
							if (Array[n][m] >= 1 && Array[n][m] <= 8) TempArray[n][m] = Array[n][m];
						}
					}
					
					int _2count = FrontEnd(TempArray, Row, Col); //������� ���������� ���� � ���������� ���������� ���������� ����������� ������
					
					if (count == _2count)
					{
						system("cls");
						Pobeda(ptr1, Row, Col);  // ����� ������� �� ����������� ���� ��� �������� � ����
						//������������ ������
						//���� ������������ ������, ���������� ��� ������ ������, ���������� �������� ��������� ���� int
						for (int i = 0; i < Row; i++)
						{
							if (Array[i])
							{
								delete Array[i];
								delete TempArray[i];
								//delete ptr[i];
								//delete ptr1[i];
								Array[i] = nullptr;
								TempArray[i] = nullptr;
								//ptr[i] = nullptr;
								//ptr1[i] = nullptr;
							}
							else cout << "������ ��� ���� �����������!" << endl;
						}
						//������������ ������, ���������� ��� ������ ����������, ���������� ������ �����
						if (Array)
						{
							delete[] Array;
							delete[] TempArray;
							//delete[] ptr;
							//delete[] ptr1;
							Array = nullptr;
							TempArray = nullptr;
							//ptr = nullptr;
							//ptr1 = nullptr;
						}
						else cout << "������ ��� ���� �����������!" << endl;

						if (Col == 10) cout << "		\x1b[32m�� ��������!\x1b[0m" << endl;
						if (Col == 20) cout << "		      \x1b[32m�� ��������!\x1b[0m" << endl;
						Game_Over = 1;
					}
				}
			}
		} while (Game_Over == 0);
		system("pause");
	} while (Uroven != 0);

}
