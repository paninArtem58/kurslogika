//include "StdAfx.h"
//#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
//#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include <windows.h>
#include "string.h"
#include <cmath>

int **createG(int size){
	int **G;
	G = (int**)malloc(size * sizeof(int*));
	for(int i=0; i < size; i++){
		G[i] = ((int*)malloc(size * sizeof(int)));
	}

	for (int i=0; i < size; i++){
		for(int j = i; j<size; j++){
			G[i][j] = rand()%2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void **printG(int **G, int size){
	for (int i=0; i < size; i++){
		for(int j = 0; j<size; j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	return 0;
}



int **DFS(int **G, int s, int size, int *vis){
	printf("%d ", s);
	vis[s] = 1;
	for (int i = 0; i < size; i++)
	{
		if(G[s][i] == 1 && vis[i] == 0)
		{
			DFS(G, i, size, vis);
		}
	}
	return 0;
}

int main(){
	int size = 0, s = 0, *vis;
    srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("Введите размер массива: ");
	scanf("%d",&size);
	printf("Введите начальную вершину ");
	scanf("%d",&s);


	vis = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++) vis[i] = 0;
	int **G1 = createG(size);
	printG(G1, size);
	DFS(G1, s, size, vis);
}