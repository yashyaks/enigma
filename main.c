#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char msg[10][10], en[10][10], enmsg[10][10];
	int r,c,i,j,k,choice,len,lencount=1,no_of_columns;
	char message[20];

	printf("Welcome to Enigma\n");
	printf("What do you want to do:\n1. Encode a message\n2. Decode a message\n");
	scanf("%d",&choice);
	_flushall();

	if(choice==1)
	{
        printf("enter a message: ");
        gets(message);
        printf("%s\n",message);
        len=strlen(message);

        no_of_columns=ceil(len/3);
        //sets initial value of entire matrix to zero
        for(r=0,i=0;r<=2;r++)
        {
            for(c=0;c<=no_of_columns;c++)
            {
                    msg[r][c]=0;
            }
        }
        //converts message to matrix (now includes optimization for using all rows and columns)
        for(r=0,i=0;r<=2;r++)
        {
            for(c=0;c<=no_of_columns;c++)
            {
                if(lencount<=len)
                {
                    msg[r][c]=message[i];
                    i++;
                }
                else
                    break;
                lencount++;
            }
        }

        //enter a encoding matrix
        printf("enter a 3 X 3 encryption matrix\n");
        for(r=0;r<=2;r++)
        {
            for(c=0;c<=2;c++)
            {
                printf("Enter a value:");
                scanf("%d",&en[r][c]);
            }
        }

        //enigma
        for(i=0;i<=2;i++)
        {
            for(j=0;j<=no_of_columns;j++)
            {
                enmsg[i][j]=0;
                for(k=0;k<=2;k++)
                {
                    enmsg[i][j]=enmsg[i][j]+en[i][k]*msg[k][j];
                }
            }
        }

        //displays encrypted message matrix
        for(r=0;r<=2;r++)
        {
            for(c=0;c<=no_of_columns;c++)
            {
                printf("%5d",enmsg[r][c]);
            }
            printf("\n");
        }
        //displays encrypted message(now optimized to display hex thus displaying readable output)
        for(r=0;r<=2;r++)
        {
            for(c=0;c<=no_of_columns;c++)
            {
                printf("%x ",enmsg[r][c]);
            }
        }
	}
	if (choice==2)
    {
        printf("Work in Progress");
    }
	return 0;
}

