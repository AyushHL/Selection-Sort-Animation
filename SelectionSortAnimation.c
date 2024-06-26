#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

void clrscreen()
{
    system("cls");
    printf("\033[1;37m\033[m");
}

void PrintArr(int arr[], int n, int red, int green, int top, int bottom)
{
	for (int i = 0; i < n; i++)
	{
		if (i == top || i == bottom)
		{
			printf(" \t");
			if(i == n-1)
			{
				printf("\n");
			}
			continue;
		}

		if (i != red && i != green)
		{
			printf("%03d\t", arr[i]);
			if (i == n-1)
			{
				printf("\n");
			}
		}

		if (i == red)
		{
			printf("\033[1;31m%03d\t\033[m", arr[i]);
			printf("\033[1;37m\033[m");
			if(i == n-1)
			{
				printf("\n");
			}
			continue;
		}

		if (i == green)
		{
			printf("\033[1;32m%03d\t\033[m", arr[i]);
			printf("\033[1;37m\033[m");
			if(i == n-1)
			{
				printf("\n");
			}
			continue;
		}
	}
}

void PrintTop(int arr[], int n, int index, int spaces)
{
	printf("\033[1;33m\t\t\t  SELECTION SORT\n\033[m");
	if (index == -1)
	{
		printf("\n");
		return;
	}

	for (int i = 0; i < spaces; i++)
	{
		printf(" \t");

	}
	printf("\033[1;31m%03d\n\033[m", arr[index]);



}

void PrintBottom(int arr[], int n, int index, int spaces, int cursor)
{
    if (index == -1 && cursor == -1)
	{
        printf("\n");
        Sleep(1000);
        clrscreen();
        return;
    }

    for (int i = 0; i < spaces; i++)
	{
        printf(" \t");
    }

    if (cursor != -1)
	{
        printf("^\n");
    }
	else
	{
        printf("\033[1;32m%03d\n\033[m", arr[index]);
    }

    Sleep(1000);
    clrscreen();
}

void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			PrintTop(arr, n, -1, -1);
			PrintArr(arr, n, i, min, -1, -1);
			PrintBottom(arr, n, -1, j, 1);
			
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		PrintTop(arr, n, -1, -1);
		PrintArr(arr, n, i, min, -1, -1);
		PrintBottom(arr, n, -1, -1, -1);

		int space_top = i;
		int space_bottom = min;
		int numspace = min - i;
		if (i != min)
		{
			for (int j = numspace; j >= 0; j--)
			{
				PrintTop(arr, n, i, space_top);
				PrintArr(arr, n, i, min, i, min);
				PrintBottom(arr, n, min, space_bottom, -1);
				space_top++;
				space_bottom--;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;

		PrintTop(arr, n, -1, -1);
		PrintArr(arr, n, min, i, -1, -1);
		PrintBottom(arr, n, -1, -1, -1);
	}
}

int main()
{
	int arr[] = {34, 12, 76, 11, 23, 44, 87, 2, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("\033[1;31m\t\t\t  SELECTION SORT ANIMATION\033[m");
    fflush(stdout);
    Sleep(2000);
    clrscreen();

	printf("\033[1;31m\t\t\t  UNSORTED ARRAY\n\033[m\n");
	PrintArr(arr , n, -1, -1, -1, -1);
	fflush(stdout);
	sleep(10);
	clrscreen();

	SelectionSort(arr, n);

	printf("\033[1;31m\t\t\t   SORTED ARRAY\n\033[m\n");
	PrintArr(arr, n, -1, -1, -1, -1);
	printf("\n");
	Sleep(20000);

	return 0;

}