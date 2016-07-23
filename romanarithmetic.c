#include <stdio.h>
#include <string.h>

int roman2integer(char *, int);
int indexofletter(char);

char roman[] = "IVXLCDM";
int decimal[] = {1,5,10,50,100,500,1000};

int main(int argc, char *argv[])
{
	int opt=0, len1=0, len2=0;
	int val1=0, val2=0;	
	
	if(argc < 3)
	{
		printf("Not enough inputs \n");
		return -1;
	}	
	printf("Welcome to Roman Calculator! \n");

	printf("Enter the operation you wish to perform: \n");
	printf("1. Addition \n");
	printf("2. Subtraction \n");
	printf("Enter: ");	
	scanf("%d",&opt);

	if(opt == 1)
		printf("You have choosen Addtion. \n");
	else if(opt == 2)
		printf("You have choosen Subtraction. \n");
	else
	{
		printf("Wrong selection of operation. \n");
		return -1;
	} 
	
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);

	val1 = roman2integer(argv[1],len1);
	val2 = roman2integer(argv[2],len2);
	printf("Integer Value1 = %d \n", val1);
	printf("Integer Value2 = %d \n", val1);
	
	if(opt == 1)	
		printf("Addition = %d \n", val1 + val2);	
	else if(opt == 2)
		printf("Subtraction = %d \n", val1 - val2);	
	

	return 0;
}

int roman2integer(char *str, int len)
{
	int i=0, j=0, val = 0;
	i = len-1;
	val = val + decimal[indexofletter(str[i])];
	j = i;
	i--;

	while(i>=0)
	{
		if(indexofletter(str[i]) >= indexofletter(str[j]))
			val = val + decimal[indexofletter(str[i])];
		else
			val = val - decimal[indexofletter(str[i])];
		
		i--;
		j--;
	} 
	return val;
}

int indexofletter(char x)
{
	int i=0;
	for(i=0;i<7;i++)
		if(x == roman[i])
		{
			return i;
		}
	return -1;
}
