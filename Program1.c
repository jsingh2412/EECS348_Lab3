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
	char* months[] = { "January",
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
	for(int i=0; i<numOfInputs; i++)
	{
		fscanf(ptr,"%lf",&costsPerMonths[i]);
	}
	fclose(ptr);
	printf("Month       Sales\n");
	for(int i=0; i<numOfInputs; i++)
	{
		printf("%-12s%.2lf\n",months[i], costsPerMonths[i]);
	}
	double min,max,minIndex,maxIndex;
	double avg = 0;
	min=costsPerMonths[0];
	max=costsPerMonths[0];
	minIndex = 0;
	maxIndex = 0;
	for(int i=0; i<numOfInputs; i++)
	{
		avg+=costsPerMonths[i];
		if(min>costsPerMonths[i])
		{
			min = costsPerMonths[i];
			minIndex=i;
		}
		if(max<costsPerMonths[i])
		{
			max = costsPerMonths[i];
			maxIndex=i;
		}
	}
	printf("Sales summary:\n\n");
	printf("Minimum sales:     $%.2lf  (%s)\n",min,months[minIndex]);
	printf("Maximum sales:     $%.2lf  (%s)\n",max,months[maxIndex]);
	printf("Minimum sales:     $%.2lf\n",avg/12);

	printf("\n\nSix-Month Moving Average Report:\n\n");
	for(int i=0; i<7; i++)
	{
	    avg=0;
		for(int j=i; j<i+6; j++)
    	{
    		avg+=costsPerMonths[j];
    	}
    	printf("%-10s-  %-10s $%.2lf\n", months[i], months[i+5], avg/6);
	}

	printf("\n\nSales Report (Highest to Lowest):\n");
	printf("  Month      Sales\n");
	int newmax;
	printf(" %-10s$%.2lf\n", months[maxIndex], costsPerMonths[maxIndex]);
	int monthsRemaining=11;
	while(monthsRemaining>0)
	{
		newmax=costsPerMonths[0];
		for(int j=0; j<12; j++)
		{
		    if(costsPerMonths[j]<max && costsPerMonths[j]>newmax)
		    {
		        newmax = costsPerMonths[j];
		        maxIndex = j;
		    }
		}
		max = newmax;
		monthsRemaining--;
		printf(" %-10s$%.2lf\n", months[maxIndex], costsPerMonths[maxIndex]);
	}
	
	return 0;
}
