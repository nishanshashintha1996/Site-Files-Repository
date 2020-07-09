
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "head.h"
void main(){
    printf("\n\t______________________________________________________________________________________________");
    printf("\n\n\t\t\t\t\t --Postfix Calculator v 1.0--\n\t\t\t\t\t    (All rights reserved.)");
    printf("\n\t______________________________________________________________________________________________");
    printf("\n\n\t\t   **Instructions For Using Postfix Calculator :");
    printf("\n\n\t\t   1. Should Keep the spaces after a digit.");
    printf("\n\n\t\t   2. Don't use spaces after the operator.");
    printf("\n\n\t\t   3. End of the expression please enter the equal sign.");
    printf("\n\n\t\t   Example expression  =  1.25_0.2_3_+8 */=");
    char str[200], edt[200] ;
    int x,count=0,ans,avb = 1;
    float n,c;
    Stack S;
    CreateStack(&S);
    while(avb==1)
    {
        if(str[0]=='s'||str[0]=='S')
        {
            if(str[1]=='t'||str[1]=='T')
            {
                if(str[2]=='o'||str[2]=='O')
                {
                    if(str[3]=='p'||str[3]=='P')
                    {
                        if(strlen(str)==4)
                        {
                            avb=0;
                        }
                        else
                        {
                            avb=1;
                            gets(str);
                        }
                    }
                    else
                    {
                        avb=1;
                        gets(str);
                    }
                }
                else
                {
                    avb=1;
                    gets(str);
                }
            }
            else
            {
                avb=1;
                gets(str);
            }
        }
        else
        {
                printf("\n\t______________________________________________________________________________________________");
                printf("\n\n\n\t\t\t Enter Expression in Postfix Notation  :");
                int stepcount =0;
                gets(str);
                x = strlen(str);
                for(int y=0; y<x; y++){
                    if(str[y]=='?'){
                        if(str[y-1]!='+'||'-'||'*'||'/'){
                            if(!IsStackFull(&S)){
                                int tm_len = count;
                                int tem_number=0 ,edtf = 0 ,hcount=0, tcount=0 ;
                                char tem_array[10] , head[100] ,tail[100];
                                for(int p=0; p<tm_len; p++){
                                    if(edt[p]!='.'){
                                        if(edtf==0){
                                            head[hcount]=edt[p];
                                            hcount++;
                                        }
                                        else{
                                            tail[tcount]=edt[p];
                                            tcount++;
                                        }
                                    }
                                    else{
                                        edtf=1;
                                    }
                                }
                                int tem_pow=hcount;
                                float htot=0, ttot=0;
                                for(int r=0; r<hcount; r++){
                                    tem_array[0]=head[r];
                                    n = atof(tem_array);
                                    int tem_tenpow=1;
                                    tem_pow--;
                                    tem_tenpow = pow(10.0,tem_pow);
                                    htot += n * tem_tenpow;
                                }
                                if(tcount==0){
                                    tail[0]='0';
                                    tcount++;
                                }
                                int y = 0;
                                for(int s=0; s<tcount; s++){
                                    tem_array[0]=tail[s];
                                    n = atof(tem_array);
                                    float tem_tenpow = 0.0;
                                    y++;
                                    tem_tenpow = pow(10,(-1)*y);
                                    ttot += n * tem_tenpow;
                                }
                                float full_tot = htot+ttot;
                                Push(full_tot,&S);
                                count=0;
                            }
                        }
                    }
                    else{
                        if(str[y]=='+'||str[y]=='-'||str[y]=='*'||str[y]=='/'){
                            if(str[y]=='+'){
                                    Pop(&c,&S);
                                    float a=c;
                                    Pop(&c,&S);
                                    float b=c;
                                    Push(a+b,&S);
                                    stepcount++;
                                    printf("\n\t\t(step %d addition)      number %0.5f and number %0.5f\n\n",stepcount,b,a);
                            }
                            else if(str[y]=='-'){
                                    Pop(&c,&S);
                                    float a=c;
                                    Pop(&c,&S);
                                    float b=c;
                                    if(a<b){}
                                    Push(b-a,&S);
                                    stepcount++;
                                    printf("\n\t\t(step %d subtraction)      number %0.5f and number %0.5f\n\n",stepcount,b,a);
                            }
                            else if(str[y]=='/'){
                                    Pop(&c,&S);
                                    float a=c;
                                    Pop(&c,&S);
                                    float b=c;
                                    Push(b/a,&S);
                                    stepcount++;
                                    printf("\n\t\t(step %d division)      number %0.5f and number %0.5f\n\n",stepcount,b,a);
                            }
                            else if(str[y]=='*'){
                                    Pop(&c,&S);
                                    float a=c;
                                    Pop(&c,&S);
                                    float b=c;
                                    Push(a*b,&S);
                                    stepcount++;
                                    printf("\n\t\t(step %d multiply)      number %0.5f and number %0.5f\n\n",stepcount,b,a);
                            }
                            else{
                            }
                    }
                    else if(str[y]=='='){
                        Pop(&c,&S);
                        float a = c;
                        printf("\n\t----------------------------------------------------------------------------------------------");
                        printf("\n\t\tFinal answer is %0.5f\n\n",a);
                        printf("\t----------------------------------------------------------------------------------------------");
                    }
                    else{
                        edt[count]=str[y];
                        count++;
                    }
                }
            }
            avb=1;
        }

    }
    printf("\n\n\n\n\t______________________________________________________________________________________________");
    printf("\n\n\t\t\t\t--Thank You For Using Postfix Calculator v 1.0--");
    printf("\n\n\t\t\t\t               Have a Nice Day");
    printf("\n\t______________________________________________________________________________________________");
    printf("\n\n\n\n\n\n\n\n");
}
