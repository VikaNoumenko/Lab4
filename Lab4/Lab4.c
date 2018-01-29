//#include "stdafx.h"
#include "stdio.h"
#include "string.h"//для работы с Си-строками
#include "conio.h"//консольный ввод-вывод
#include "windows.h"
#include <locale.h>

#define _CRT_SECURE_NO_WARNINGS

struct company
{
	char surname[15], department[15], position[15], salary[15];
} array[100];


struct search
{
	char empty[15], d[15];
}   search[2];
    int i = 0,
	quantity = 0;


void enter()
{
	i = quantity;
	printf("Enter surname: ");
	scanf_s("%s",  &array[i].surname);
	printf("Enter department: ");
	scanf_s("%s", &array[i].department);
	printf("Enter position: ");
	scanf_s("%s", &array[i].position);
	printf("Enter salary: ");
	scanf_s("%s", &array[i].salary);
	printf("\n ADDED \n");
	quantity++;

}

void selection()
{
	for (int i = 0; i <= quantity - 1; i++) {
		if (array[i].surname != search[0].empty)
			printf("%s  ", array[i].surname);
		printf("%s  ", array[i].department);
		printf("%s  ", array[i].position);
		printf("%s  \n", array[i].salary);

	}
}

void commandSearch()
{
	printf("Enter command for searching: ");
	scanf_s("%s", &search[0].d);
	for (i = 0; i <= quantity - 1; i++)
	{
		if (!strcmp(array[i].surname, search[0].d))// сравнили строки
		{
			printf("%s  ", array[i].surname);
			printf("%s  \n", array[i].department);
			printf("%s  ", array[i].position);
			printf("%s  \n", array[i].salary);
		}
	}
}

void modification()
{
	printf("Enter commant for modification': \n");
	scanf_s("%s", &search[0].d);
	for (i = 0; i <= quantity - 1; i++)
	{
		if (!strcmp(array[i].surname, search[0].d))
		{
			printf("Enter new surname: ");
			scanf_s("%s", array[i].surname);
			printf("Enter new department: ");
			scanf_s("%s", array[i].department);
			printf("Enter new position: ");
			scanf_s("%s", array[i].position);
			printf("Enter new salary: ");
			scanf_s("%s", array[i].salary);
			printf("MODIFIED\n");
			break;
		}
	}
}
void deletion()
{
	printf("Enter command for deletion: ");
	scanf_s("%s", search[0].d);
	for (i = 0; i <= quantity - 1; i++) {
		if (!strcmp(array[i].surname, search[0].d))//Функция возвращает указатель на строку, в которую скопированы данные.
			strcpy_s(array[i].surname, search[0].empty);
		strcpy_s(array[i].department, array[i].surname);
		strcpy_s(array[i].position, array[i].surname);
		strcpy_s(array[i].salary, array[i].surname);
		{system("cls");// очистка экрана для консоли
		printf(" \n DELETED \n");
		}
	}
}

int main()
{
	int comm = 1;
	while (comm) {
		printf("\n SELECT COMMAND: \n 1)ADD' 2)PRINT' 3)MODIFY' 4)DELETE' 5)SEARCH 0)EXIT\n");
		printf("\n ENTER ACTION: ");
		scanf_s("%d", &comm);
		switch (comm) {
		case 1: enter(); break;
		case 2: selection(); break;
		case 3: modification(); break;
		case 4: deletion(); break;
		case 5: commandSearch(); break;
		case 0: printf("EXIT\n"); break;
		default:
			printf("NOT FOUND\n");
		}
	}
	_getch();
	return 0;
}