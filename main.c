

//R.M.N.S.Samarakoon
//CT/2015/054


#include <stdio.h>
#include "head.h"
#include <string.h>

void main()
{
//----------Initialize variables-------------//
    int x,y,yescount=0;Stack S;
    char text[1000],modified1[1000],c,temp;
//----------getting text field-------------//
    CreateStack(&S);
    printf("\n\n\n\n\t     A palindrome is a word, number, phrase, or other sequence of \n\t     characters which reads the same backward as forward.\n\t     This program is familiar with characters.-------\n\n\t      Enter String did you want :\t");
    gets(text);
    x = strlen(text);
    //printf("\nlength of text :%d\n\n",x);
    int count=0;

    for(int i=0; i<=x; i++)
    {
        if (text[i] <= 'Z' && text[i] >= 'A' || text[i] <= 'z' && text[i] >= 'a')
        {
            temp = tolower(text[i]);
            //printf("%c",temp);
            modified1[count]=temp;
            //printf("%c",modified1[count]);
            //printf("%d\n",count);
            if(!IsStackFull(&S))
            {
                  Push(modified1[count],&S);
            }
            count++;
        }
    }
    //printf("\n%d\n",count);
    y = strlen(modified1);
    for(int i=0; i<count; i++)
    {
        Pop(&c,&S);
        //printf("%c",c);
        if(c==modified1[i])
        {
            //printf("yes\n\n");
            yescount++;
        }
        else
        {
            //printf("no\n\n");
            printf("\n\n\t                 -----------------------This is not  palindrome-----------------------\n\n");
            break;
        }
        if(yescount==count){
            printf("\n\n\t                 -----------------------This is  palindrome-----------------------\n\n");
        }
    }printf("\n\n\t                 -----------------------Thank you-----------------------\n\n");
}
