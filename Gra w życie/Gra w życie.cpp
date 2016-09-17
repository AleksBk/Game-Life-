// Gra w ¿ycie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#define N 40
#define M 15
using namespace std;
//-----------------------------------------------------
void CzytajStan( FILE* plik1, int** t)
{
	char c;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{

			fscanf(plik1, "%1c", &c);
			t[i][j] = atoi(&c);
		}
		fscanf(plik1, "%1c", &c);
	}
}
//----------------------------------------------------
void Wyœwietl(int** t)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if( t[i][j]== 1 ) cout << "O";
			else cout << " ";
		}
		cout << endl;
	}
}
//----------------------------------------------------
void PoliczSasiadów(int**t, FILE* plik, int a, int b)
{
	int sasiad=0; 

	if (b + 1 < N)
	{
		if (t[a][b + 1] == 1) sasiad++;
	}

	if (b - 1 >= 0)
	{
		if (t[a][b - 1] == 1) sasiad++;
	}

	if ((a - 1 >= 0) && (b - 1 >= 0))
	{
		if (t[a - 1][b - 1] == 1) sasiad++;
	}
	if ((a - 1 >= 0) && (b + 1 < N))
	{
		if (t[a - 1][b + 1] == 1) sasiad++;
	}
	if (a - 1 >= 0)
	{
		if (t[a - 1][b] == 1) sasiad++;
	}
	if ((a + 1 < M) && (b + 1 < N))
	{
		if (t[a + 1][b + 1] == 1) sasiad++;
	}
	if ((a + 1 < M) && (b - 1 >= 0))
	{
		if (t[a + 1][b - 1] == 1) sasiad++;
	}
	if (a + 1 < M)
	{
		if (t[a + 1][b] == 1) sasiad++;
	}

	if (t[a][b]== 1 && (sasiad < 2 || sasiad >= 4))
	{
		//zapisanie w pliku nowej sytuacjii 
		fprintf(plik, "0");
	}
	else if (t[a][b] == 1 && (sasiad >= 2 && sasiad < 4))
	{
		fprintf(plik, "1"); 
	}
	else if ( t[a][b] == 0 && sasiad == 3)
	{
		fprintf(plik, "1");
	}
	else 
		fprintf(plik, "0");
	
	
}
//--------------------------------------------------------------
int main()
{
	int **tab = new int*[M];
	for (int i = 0; i < M; i++)
	{
		tab[i] = new int[N]; 
	}

	FILE* plik1;
	FILE* plik2;
	if( (plik1 = fopen("stan.txt", "r")) != NULL) CzytajStan(plik1, tab); 


	Wyœwietl(tab); 
	int k = 0; 
	while ( k !=100)
	{

		plik2=fopen("stan1.txt", "w");

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				PoliczSasiadów(tab, plik2, i, j);
			}
			fprintf(plik2, "\n");
		}
		fclose(plik2);
		plik2 = fopen("stan1.txt", "r");
		CzytajStan(plik2, tab);
		
		Sleep(100);
		system("cls");
		
	
		Wyœwietl(tab);
		k++; 
		fclose(plik2);
	}
	//------------------------------------------------------------------
		for (int i = 0; i < M; i++)
		{
			delete[] tab[i]; 
		}
		delete[] tab; 
	 
    return 0;
}

