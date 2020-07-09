#include <stdio.h>
#include "header.h"
#include <string.h>

void main()
{

    int x,y,z,type_1=0,type_2=0,type_3=0;Stack S;
    char text[1000],modified[1000],ts_arr[1000],c;
    char type1_1='{';  char type1_2='}';  char type2_1='[';  char type2_2=']';  char type3_1='(';  char type3_2=')';
    //----------getting text field-------------//
    CreateStack(&S);
    printf("\n\n\n\n\t\tEnter expression did you want to check :");
    gets(text);
    x = strlen(text);

    //printf("\nlength of text :%d\n\n",x);
    int count=0;

    for(int i=0; i<x; i++)
    {
        if (text[i]=='{' || text[i]=='}' || text[i]=='(' || text[i]==')' || text[i]=='[' || text[i]==']')
        {
            modified[count]=text[i];
            count++;
        }
    }


    y = strlen(modified);
    for(int i=0; i<count;i++)
    {
        printf("%c",modified[i]);
        if(modified[i]==type1_1 || modified[i]==type2_1 || modified[i]==type3_1)
        {
            if(!IsStackFull(&S))
            {
                if(modified[i]==type1_1)
                {
                    type_1++;
                    Push(modified[i],&S);
                    printf("%c type_1++\t%d\n",c,type_1);
                }
                else if(modified[i]==type2_1)
                {
                    type_2++;
                    Push(modified[i],&S);
                    printf("%c type_2++\t%d\n",c,type_2);
                }
                else
                {
                    type_3++;
                    Push(modified[i],&S);
                    printf("%c type_3++\t%d\n",c,type_3);
                }
            }
        }
        else
        {
            if(!IsStackEmpty(&S))
            {
                if(type_1!=0)
                {
                    if(modified[i]==type1_2)
                    {
                        type_1--;
                        Pop(&c,&S);
                        printf("%c type_1--\t%d\n",c,type_1);
                    }
                }
                else if(type_2!=0)
                {
                    if(modified[i]==type2_2)
                    {
                        type_2--;
                        Pop(&c,&S);
                        printf("%c type_2--\t%d\n",c,type_2);
                    }
                }
                else if(type_3!=0)
                {
                    if(modified[i]==type3_2)
                    {
                        type_3--;
                        Pop(&c,&S);
                        printf("%c type_3--\t%d\n",c,type_3);
                    }
                }
            }
        }
    }

    printf("%d",type_1);
    printf("%d",type_2);
    printf("%d",type_3);
    if((type_1+type_2+type_3)!=0)
        printf("\n\n\t\t--------------------That is not correct formula--------------------\n\n");
    else
        printf("\n\n\t\t--------------------That is correct formula--------------------\n\n");

}
