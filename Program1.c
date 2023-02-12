/*
 * Program1.c
 *
 *  Created on: Feb 8, 2023
 *      Author: j507s861
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE* ptr;
	int numOfInputs = 12;
	char* month[] = { "January",
					"February",
					"March",
					"April",
					"May",
					"June",
					"July",
					"August",
					"September",
					"October",
					"November",
					"December"};
	double costsPerMonths[numOfInputs];
	ptr = fopen("input.txt", "r");
	//if (NULL == ptr)
	//{
	//	printf("File can't be opened \n");
	//	return 0;
	//}
	for(int i; i<numOfInputs; i++)
	{
		fscanf(ptr,"%lf",&costsPerMonths[i]);
	}
	fclose(ptr);
	printf("Month       Sales\n");
	for(int i; i<numOfInputs; i++)
	{
		printf("%s       %lf\n",month[i], costsPerMonths[i]);
	}

	return 0;
}
