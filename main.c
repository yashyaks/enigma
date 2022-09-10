#include <stdio.h>
#include <string.h>

int main()
{
	char msg[10][10], en[10][10], enmsg[10][10];
	int r,c,i,len,j,k,choice,determinant;
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
        printf("%d",len);
        for(i=0;i<=len-1;i++)
        {
                msg[0][i]=message[i];
        }
        for(i=0;i<=len;i++)
        {
                msg[1][i]=0;
                msg[2][i]=0;
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
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=len;j++)
            {
                enmsg[i][j]=0;
                for(k=0;k<=3;k++)
                {
                    enmsg[i][j]=enmsg[i][j]+en[i][k]*msg[k][j];
                }
            }
        }
        //displays encrypted message matrix
        for(r=0;r<=2;r++)
        {
            for(c=0;c<=len-1;c++)
            {
                printf("%d",enmsg[r][c]);
            }
            printf("\n");
        }
	}
	if (choice==2)
    {
        printf("Work in Progress");
    }
	return 0;
}

