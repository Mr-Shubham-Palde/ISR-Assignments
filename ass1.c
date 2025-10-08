
#include<stdio.h>
//#include<conio.h>
#include <string.h>
#include <stdlib.h>
char sw[50][10]={"our","we","what","or","by","it.","and","can","on","so","even","if","that","in","be","to","it","is","this","the","a","an","was","were","he","she","you","will","are","have","when","off","has","had","for","of","because","xx"};
char stm[50][10]={"able","fulness","ousness","ational","tional","alize","ful","ness","sses","ing","ed","s",".",",","ion","yy"};
char token[30]=" ";
int temp=0;
FILE *fp=NULL;
int i,flag=0,flag1=0,k,j;
int len;

struct index
{
	int no;
	char string[20];
	int frequency;
};

struct index i1[100];

void lower_case()
{
	temp=token[0];
	if(temp<=90)
	{
		token[0]=temp+32;
	}
}

void removesw()
{
	flag=0;
	lower_case();
	for(i=0;i<len;i++)
	{
		if(strcmp(token,sw[i])==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		token[0]=temp;
		strcpy(i1[k].string,token);
		k++;
	}
}

void stem()
{
    int len1,l=0;
    char *ptr=NULL;
    for(j=0;j<k;j++)
    {
	i=0;
	flag1=0;
	len1=0;
	while(i1[j].string[i]!='\0')
	{
		len1++;
		i++;
	}
	if(i1[j].string[len1-1]=='.')
	{
		i1[j].string[len1-1]='\0';
	}
	for(i=0;strcmp(stm[i],"yy")!=0;i++)
	{
		ptr=strstr(i1[j].string,stm[i]);
		if(ptr!=NULL)
		{
		   //printf("Got here");
		   flag1=1;
		   for(l=0;stm[i][l]!='\0';l++)
		   {
			if(i1[j].string[strlen(i1[j].string)-strlen(stm[i])+l]!=stm[i][l])
			{
				flag1=0;
				break;
			}
		   }
		   break;
		}
	}
	if(flag1==1)
	{
		if(strlen(i1[j].string)-strlen(stm[i])>0)
		{
			i1[j].string[strlen(i1[j].string)-strlen(stm[i])]='\0';
		}
	}
    }
}
void duplicate()
{
    int count,l=0,temp1;
    for(j=0;j<k;j++)
    {
	if(strcmp(i1[j].string,"null")!=0)
	{
	    count=1;
	    for(i=j+1;i<k;i++)
	    {
		if(strcmp(i1[j].string,i1[i].string)==0)
		{
			strcpy(i1[i].string,"null");
			count++;
		}
	    }
	    i1[j].no=l;
	    l++;
	    i1[j].frequency=count;
	}
    }

    for(i=0;i<k;i++)
    {
	if(strcmp(i1[i].string,"null")==0)
	{
		for(j=i;j<k;j++)
		{
			if(strcmp(i1[j].string,"null")!=0)
			{
				temp=i1[i].no;
				i1[i].no=i1[j].no;
				i1[j].no=temp;

				strcpy(token,i1[i].string);
				strcpy(i1[i].string,i1[j].string);
				strcpy(i1[j].string,token);

				temp1=i1[i].frequency;
				i1[i].frequency=i1[j].frequency;
				i1[j].frequency=temp1;

				break;
			}
		}
	}
    }
}

void calls(char fname[20])
{
	char freq=' ';
	len=0,k=0;

	fp=fopen(fname,"r");

	if(fp==NULL)
	{
		printf("\nCant read input file");
		//getch();
		exit(0);
	}
	else
	{
		while(strcmp(sw[i],"xx")!=0)
		{
			len++;
			i++;
		}
		while(!feof(fp))
		{
		      fscanf(fp,"%s",token);
		      removesw();
		}
	}
	fclose(fp);
	printf("----------------------------------------------------");
	printf("\nThe contents of %s file\n\n",fname);
	printf("----------------------------------------------------\n");
	fp=fopen(fname,"r");
	while(!feof(fp))
	{
		fscanf(fp,"%s",token);
		printf("%s ",token);
	}
	printf("\n\n");
	//getch();
	fclose(fp);

	printf("-----------------------------------------------------");
	printf("\n\nThe contents of file after removing Stop words\n");
	printf("-----------------------------------------------------\n");
	for(i=0;i<k;i++)
	{
		printf("%s ",i1[i].string);
	}
	printf("\n\n");
	//getch();
	stem();
	printf("-----------------------------------------------------");
	printf("\nThe contents of file after removing Suffix words\n");
	printf("-----------------------------------------------------\n");
	for(i=0;i<k;i++)
	{
	  printf("%s ",i1[i].string);
	}
	printf("\n\n");
	//getch();
	duplicate();
	printf("-----------------------------------------------------");
	printf("\n\nThe contents of the file after removing Duplicates\n");
	printf("-----------------------------------------------------\n");
	for(i=0;i<k&&strcmp(i1[i].string,"null")!=0;i++)
	{
		printf("%s ",i1[i].string);
	}
	//getch();
	printf("\n\n");
	printf("-----------------------------------------------------");
	printf("\n\nDOCUMENT REPRESENTATIVE for %s \n\n",fname);
	printf("-----------------------------------------------------");
	printf("\nNo.\tKeyword\t\tFrequency\n\n\n");
	printf("-----------------------------------------------------");
	printf("\n");
	fp=fopen("Doc_rep.txt","w");
	for(i=0;i<k&&strcmp(i1[i].string,"null")!=0;i++)
	{
		printf("%-2d\t%-15s\t   %-10d\n\n",i1[i].no,i1[i].string,i1[i].frequency);
		fputc(' ',fp);
		fputs(i1[i].string,fp);
		fputc(' ',fp);
		freq=i1[i].frequency+48;
		fputc(freq,fp);

	}
	fclose(fp);
	printf("-----------------------------------------------------");
}

void main()
{
	char fname[20];
	//clrscr();
	system("clear");

	printf("\nEnter Document name:- ");
	scanf("%s",fname);
	strcat(fname,".txt");

	calls(fname);
	//getch();

}


