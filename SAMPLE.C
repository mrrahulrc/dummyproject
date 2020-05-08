#include<stdio.h>
void main()
{
    char *ch;
    int i,j,k,l;char temp;
    ch = (char *)malloc(sizeof(char));
    printf("enter the string: \n");
    scanf("%s",ch);
    for(i=0; *(ch+i)!='\0';i++);

    for(l=0;l<i;l++)
    {
        for(j=0;j<i-1;j++)
        {
            temp = *(ch+j);
            *(ch+j) = *(ch+j+1);
            *(ch+j+1) = temp;
            for(k=0;k<i;k++)
            {
                printf("%c",*(ch+k));
            }
            printf("\n");
        }
    }
}
