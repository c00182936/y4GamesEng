// testing 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>
#include "../TestingClass.h"


void testNumbers(int &x, int&y, TestingBed &testBed)
{
	int temp;
	temp = testBed.testCase1(x, y);
	//assert(temp != NULL);
	//printf("%d\n", temp);
	if (x > y)
	{
		assert(temp == x);
		printf("%d\n", y);
	}
	else
	{
		assert(temp == y);
		printf("%d\n", x);
	}

}

int main()
{
	TestingBed testBed;
	int x, y;
	x = 3;
	y = 2;
	testNumbers(x, y,testBed);
	x = 2;
	y = 3;
	testNumbers(x, y,testBed);



	system("PAUSE");
    return 0;
}

