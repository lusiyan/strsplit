#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 2048

#define TRUE  1
#define FALSE 0
#define true  1
#define false 0

#define DONE 1
#define FAIL 0
#define done 1
#define fail 0

char** strsplit(char* string, char* delimeter, int* cnt)
{
	// ** Keep Original String
	// ** All Split delimeter Part
	// *** 0,1,2,,3,4, ,5 --> [0] / [1] / [2] / [] / [3] / [4] / [ ] / [5]
	
	char** result;
	int i;
	int index = 0;
	int count = 0;
	
	char* pos_tmp;
	
	pos_tmp = string;
	
	while (*pos_tmp)
	{
		for (i = 0; i < strlen(delimeter); i++)
		{
			if (*pos_tmp == delimeter[i])
			{
				count++;
			}
		}
		pos_tmp++;
	}
	// delimeter count + 1 = array count
	count++;
	*cnt = count;
	
	result = malloc(sizeof(char*) * count);
	result[0] = strdup(string);
	
	pos_tmp = result[0];
	
	while (*pos_tmp)
	{
		for (i = 0; i < strlen(delimeter); i++)
		{
			if (*pos_tmp == delimeter[i])
			{
				index++;
				
				result[index] = pos_tmp + 1;
				
				*pos_tmp = '\0';
			}
		}
		pos_tmp++;
	}
	
	return result;
}

char** strsplit_nn(char* string, char* delimeter, int* cnt)
{
	// * Make By BAEK SeungWoo. 2023.11.24.
	// ** Keep Original String
	// ** All Split delimeter Part and not allow null
	// *** if del=[,] --> 0,1,2,,3,4 --> [0] / [1] / [2] / [3] / [4]
	
	char** result;
	char** tmp_str;
	int i, j;
	int index = 0;
	int count = 0;
	
	char* pos_tmp;
	
	pos_tmp = string;
	
	while (*pos_tmp)
	{
		for (i = 0; i < strlen(delimeter); i++)
		{
			if (*pos_tmp == delimeter[i])
			{
				count++;
			}
		}
		pos_tmp++;
	}
	// delimeter + 1 = array count
	count++;
	
	tmp_str = malloc(sizeof(char*) * count);
	tmp_str[0] = strdup(string);
	
	pos_tmp = tmp_str[0];
	
	while (*pos_tmp)
	{
		for (i = 0; i < strlen(delimeter); i++)
		{
			if (*pos_tmp == delimeter[i])
			{
				index++;
				
				tmp_str[index] = pos_tmp + 1;
				
				*pos_tmp = '\0';
			}
		}
		pos_tmp++;
	}
	
	result    = make_array_char2(2048, count);
	j = 0;
	for (i = 0; i < count; i++)
	{
		if (tmp_str[i][0] != '\0')
		{
			sprintf(result[j], "%s", tmp_str[i]);
			
			j++;
		}
	}
	*cnt = j;
	
	return result;
}

int main(int argc, char** argv)
{
	char** array_string = NULL;
	int cnt;
	int i;
	
	sprintf(__PROG__, "%s", argv[0]);
	
	array_string = strsplit(argv[1], ",", &cnt);
  
	for (i = 0; i < cnt; i++)
	{
		printf("[%02d] [%s]\n", i, array_string[i]);
	}
    
	free(array_string[0]);
	free(array_string);
  	
	return DONE;
}
