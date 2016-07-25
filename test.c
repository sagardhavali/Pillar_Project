#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int roman2integer(char *, int);
void integer2roman(int);
bool isvalidroman(char *str);
int indexofletter(char);
void postdigit(char, int);
void predigit(char, char);

char roman[] = "IVXLCDM";
int decimal[] = {1,5,10,50,100,500,1000};
char answer[1000]={0};
int ind=0;

int main(int argc, char *argv[])
{
	int opt=0, len1=0, len2=0;
	int val1=0, val2=0;
	int result=0;	
	
	if(isvalidroman(argv[1]))	
		printf("Entered	roman number is valid \n");
	else
		printf("Entered roman number is INVALID \n");
	printf("Integer Value = %d \n", roman2integer(argv[1],strlen(argv[1])));
	
	/*if(argc < 3)
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
	printf("Integer Value2 = %d \n", val2);
	
	if(opt == 1)
	{	
		result = val1 + val2;	
		integer2roman(result);
	}
	else if(opt == 2)
	{
		result = val1 - val2;
		if(result == 0)
			printf("The answer is Null \n");
		else if(result < 0)
			printf("The answer is negative \n");
		else
			integer2roman(result);
	}	
	
	integer2roman(8); */
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

void integer2roman(int num)
{
	int i=0;

	while(num != 0)
	{
		if(num >= 1000)
		{
			postdigit('M', num/1000);
			num = num - (num/1000)*1000;
		}
		else if(num >= 500)
		{
			if(num < 900)
			{
				postdigit('D', num/500);
				num = num - (num/500)*500;
			}
			else
			{
				predigit('C','M');
				num = num - 900;
			}
		}
		else if(num >= 100)
		{
			if(num < 400)
			{
				postdigit('C', num/100);
				num = num - (num/100)*100;
			}
			else
			{
				predigit('L','D');
				num = num - 400;
			}
		}
		else if(num >= 50)
		{
			if(num < 90)
			{
				postdigit('L', num/50);
				num = num - (num/50)*50;
			}
			else
			{
				predigit('X','C');
				num = num - 90;
			}
		}
		else if(num >= 10)
		{
			if(num < 40)
			{
				postdigit('X', num/10);
				num = num - (num/10)*10;
			}
			else
			{
				predigit('X','L');
				num = num - 40;
			}
		}
		else if(num >= 5)
		{
			if(num < 9)
			{
				postdigit('V', num/5);
				num = num - (num/5)*5;
			}
			else
			{
				predigit('I','X');
				num = num - 9;
			}
		}
		else if(num >= 1)
		{
			if(num < 4)
			{
				postdigit('I', num/1);
				num = num - (num/1)*1;
			}
			else
			{
				predigit('I','V');
				num = num - 4;
			}
		}
	}

	printf("Roman Number is: ");
	for(i=0;i<ind;i++)
		printf("%c", answer[i]);
	printf("\n");
}

void postdigit(char c, int n)
{
	int i=0;
	for(i=0;i<n;i++)
		answer[ind++] = c;
}

void predigit(char num1, char num2)
{
	answer[ind++] = num1;
	answer[ind++] = num2;
}

bool isvalidroman(char *str)
{
	int len = strlen(str);
	int i=0, prev=0, pres=0, count=0;
	int first_M = 0;

	if(str[0] == 'M')
		first_M = 1;
	else
		first_M = 0;

	for(i=0;i<len;i++)
	{
		pres = indexofletter(str[i]);
		if(pres == -1)
			return false;
		count++;
		if(prev == pres)
		{
			if(pres%2 == 1)
				return false;
			if(pres%2 == 0 && count == 2 && str[i] == 'M' && first_M == 0)
				return false;
		}
		else
			count = 1;
		if(count >3 && str[i] != 'M')
			return false;		
		prev = pres;
	}
		
	prev = indexofletter(str[0]);
	count = 0;
	for(i=1;i<len;i++)
	{
		pres = indexofletter(str[i]);
		if(pres == prev)
			count++;
		if(pres > prev && count == 1)
			return false;	
	}
	
	return true;
}

