// CST126_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int lengthFinder(char * p)
{
	int counter = 0;
	for (p; p[0] != '\0'; p++)
	{
		counter++;
	}
	return counter;
}

int charFinder(char a, int str1_len, char * sentencePtr)
{
	int counter = 0;
	char * p = sentencePtr;
	for (char * p = sentencePtr; p < sentencePtr + str1_len; p++)
	{

		if (*p != a || a == ' ' || a == ',')
		{
			counter++;
			if (counter == str1_len && a != ' ' && a != ',')
			{
				std::cout << a << " is found at position -1" << '\n';
				return -1;

			}
		}
		else if (*p == a) 
		{
			std::cout << p[0] << " matches at position " << counter + 1 << '\n';
			counter++;
			return counter;
		}
	}

	return counter;
}

void asteriskPrint()
{
	for (int i = 0; i != 60; i++)
	{
		std::cout << "*" << ' ';
	}
}

int main()
{


	// for your convenience I've included a few other song quotes to test
	// 
	// "I've woken up on the wrong side of the bed everyday since 1987"
	// "Tommy doesn't know what day it is, he doesn't know who Jesus was or what praying is!"
	char sentence[] = { "Tommy doesn't know what day it is, he doesn't know who Jesus was or what praying is!" };


	// here are some test sets of characters
	// "a, B, C, d, E, f, G, h, I, j, K, l, M, n, O, P, q, r, S, T, u, V, W, x, Y, z"
	// i, I, w, z, r
	char testChars[] = { " i, I, w, z, r " };

	int str1_len = lengthFinder(sentence);
	int str2_len = lengthFinder(testChars);
	char * sentencePtr = sentence;

	asteriskPrint();

	std::cout << '\n';
	std::cout << "The string being tested is: " << sentence << '\n';
	std::cout << "The characters being tested against the string are: " << testChars << '\n';

	std::cout << '\n';
	asteriskPrint();

	std::cout << '\n' << '\n';
		for (int i = 0; i < str2_len; i++)
		{
			char a = testChars[i];
			
			int counter = charFinder(a, str1_len, sentencePtr);
		}

	return 0;
}