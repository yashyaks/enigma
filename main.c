#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char message[20], msg[10][10];
    int en[10][10],enmsg[10][10];
	int r,c,i,j,k,x,y,z;
	int choice,len,lencount,no_of_columns,det;

	printf("Welcome to Enigma\n");
	printf("What do you want to do:\n1. Encode a message\n2. Decode a message\n");
	scanf("%d",&choice);
	_flushall();

	switch(choice)
	{
	    case 1:
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
            lencount=1;
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

            //enter a encoding matrix(now manages case where inverse of the encoding matrix may not be possible)
            i=0;
            do
            {
                if(i>0)
                {
                    printf("\nThe inverse of the encoding matrix doesn't exist\nInput encoding matrix where inverse of the matrix exist\n\n");
                }
                printf("enter a 3 X 3 encryption matrix\n");
                for(r=0;r<=2;r++)
                {
                        printf("Enter element of Row %d: ",r+1);
                        scanf("%d %d %d",&en[r][0] ,&en[r][1] ,&en[r][2]);
                }
                x = (en[1][1] * en[2][2]) - (en[2][1] * en[1][2]);
                y = (en[1][0] * en[2][2]) - (en[2][0] * en[1][2]);
                z = (en[1][0] * en[2][1]) - (en[2][0] * en[1][1]);
                det = (en[0][0] * x) - (en[0][1] * y) + (en[0][2] * z);
                i++;

            }while(det<=0);

            //enigma_encode
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

            //displays encrypted message(now optimized to display hex thus displaying readable output)
            printf("Encrypted message is: ");
            for(r=0;r<=2;r++)
            {
                for(c=0;c<=no_of_columns;c++)
                {
                    printf("%x ", enmsg[r][c]);
                }
            }
            break;
        case 2:
            printf("work in progress");


	}
	return 0;
}



