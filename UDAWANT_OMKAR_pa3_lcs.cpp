#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
char x[100], y[100];
int lcs[100][100]; 

void printLCS(int, int);			//Print the Longest common substring
void compare(int, int);				//compare strings

void printLCS(int i, int j)
{
	if(i == 0 || j == 0)
	{
		return;
	}
	
	if(x[i] == y[j])
	{
		printLCS(i-1, j-1);			
		printf("%c", x[i]);			//print substring character by character
	}
	else if(lcs[i][j-1] >= lcs[i-1][j])
	{
		printLCS(i, j-1);
	}
	else 
	{
		printLCS(i-1, j);
	}
}

void compare(int m, int n)
{
	int i,j;
	for(j=0; j <= n; j++)
	{
		lcs[0][j] = 0;
	}
	for(i=1; i <= m; i++)
	{
		lcs[i][0] = 0;
	}
	
	for(i=1; i <= m; i++)					//check string for common sequence
	{
		for(j=1; j <= n; j++)
		{
			if(x[i] == y[j])
			{
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}
			else if(lcs[i][j-1] >= lcs[i-1][j])
			{
				lcs[i][j] = lcs[i][j-1];
			}
			else
			{
				lcs[i][j] = lcs[i-1][j];
			}
		}
	}
	printf("\nLength of LCS: %d",lcs[m][n]);		//print length of LCS
	printf("\nLCS: ");
	printLCS(m,n);									//print string char by char
	printf("\n");
}

int main(int argc, char* argv[])
{
	char* s1;
	char* s2;
	int i, m, n;

	s1 = argv[1];					//store string 1
	s2 = argv[2];					//store string 2

	m = strlen(s1);					//get length of String 1
	n = strlen(s2);					//get length of String 2

  	if ( argc == 3 )				//check for number of arguments
  	{
  		if( m > 100 || n > 100 )		//if more than 100 characters in string, print long string return -2
  		{
  			printf("The string length too long\n");
  			return -2;
  		}
  		else							//exact number of arguments then execute program
  		{
  			for(i=1; i <= m; i++)
			{
				x[i] = s1[i - 1];		//initialize array X
			}
		
			for(i=1; i <= n; i++)
			{
				y[i] = s2[i - 1];		//initialize array y
			}

			compare(m,n);
  		}
  	}
  	else if ( argc > 3 ) 				//more than 2 strings, print Error
	{
    	printf("Error\n");
    	return -1;
  	}
  	else								//less than 2 strings, print missing input
  	{
  		printf("Missing input\n");
  		return -1;
  	}

	return 0;
}