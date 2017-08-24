//
//  pentax.c
//  CTriangx
//
//  Created by SaitaSatoko on 2017/08/24.
//  Copyright © 2017年 SaitaSatoko. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "paramt.h"
#include "pentax.h"

double pentax(){
    double ax[20*2];//1次元配列で多次元配列を表現する.
    double bx[12*2];//1次元配列で多次元配列を表現する.
    int ix[12*5];//1次元配列で多次元配列を表現する.
    int i,j;
    double te1,te2,a,b,c,d,r,r1,fi,fi0,fi1,fi2,fi3;
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("out-pentax1.txt","w");
    fp2=fopen("out-pentax2.txt","w");
    fp3=fopen("out-pentax3.txt","w");
    
    printf("- pentax\n");
    printf("    pi:%f\n",pi);
    //     ax apex cote,fi
    //     bx center cote,fi
    //     ix apex points
    te1=54.0;
    te2=72.0;
    //     angles for pentax
    a=2.0/3.0*sqrt(3.0)*sin(te1/180.0*pi);
    b=sqrt(1.0-a*a);
    r=0.5/b;
    c=0.5/sin(0.5*te2/180.0*pi);
    fi=asin(c/r);
    fi1=fi/pi*180.0;
    fi=2.0*asin(0.5/r);
    fi2=fi/pi*180.0;
    d=c*cos(0.5*te2/180.0*pi);
    r1=sqrt(r*r-0.5*0.5);
    fi=asin(d/r1);
    fi3=fi/pi*180.0;
    //     apex cote,fi coordinates
    for(i=0;i<5;i++){
        ax[i+   +20]    =pi/2.5*((double)(i));
        ax[i+5  +20]    =pi/2.5*((double)(i));
        ax[i+10 +20]    =pi/2.5*((double)(i))+pi/5.0;
        ax[i+15 +20]    =pi/2.5*((double)(i))+pi/5.0;
        ax[i]           =pi-fi1/180.0*pi;
        ax[i+5]         =pi-(fi1+fi2)/180.0*pi;
        ax[i+10]        =(fi1+fi2)/180.0*pi;
        ax[i+15]        =fi1/180.0*pi;
    }
    //C     center cote,fi coordinates
    bx[0    +0]     =pi;
    bx[0    +12]    =0.0;
    for(i=0;i<5;i++){
        bx[1+i  +0] =pi-(fi3+fi3)/180.0*pi;
        bx[1+i  +12]=pi/2.5*((double)(i))+pi/5.0;
        bx[6+i  +0] =pi-(fi1+fi2+fi1)/180.0*pi;
        bx[6+i  +12]=pi/2.5*((double)(i));
    }
    bx[11   +0]=0.0;bx[11   +12]=0.0;
    //C     1st
    ix[0    +0]=1;
    ix[0    +1]=2;
    ix[0    +2]=3;
    ix[0    +3]=4;
    ix[0    +4]=5;
    //C     2nd
    ix[5    +0]=1;
    ix[5    +1]=6;
    ix[5    +2]=11;
    ix[5    +3]=7;
    ix[5    +4]=2;
    //C     3rd
    ix[10    +0]=2;
    ix[10    +1]=7;
    ix[10    +2]=12;
    ix[10    +3]=8;
    ix[10    +4]=3;
    //C     4th
    ix[15    +0]=3;
    ix[15    +1]=8;
    ix[15    +2]=13;
    ix[15    +3]=9;
    ix[15    +4]=4;
    //C     5th
    ix[20    +0]=4;
    ix[20    +1]=9;
    ix[20    +2]=14;
    ix[20    +3]=10;
    ix[20    +4]=5;
    //C     6th
    ix[25    +0]=5;
    ix[25    +1]=10;
    ix[25    +2]=15;
    ix[25    +3]=6;
    ix[25    +4]=1;
    //C     7th
    ix[30    +0]=6;
    ix[30    +1]=15;
    ix[30    +2]=20;
    ix[30    +3]=16;
    ix[30    +4]=11;
    //C     8th
    ix[35    +0]=7;
    ix[35    +1]=11;
    ix[35    +2]=16;
    ix[35    +3]=17;
    ix[35    +4]=12;
    //C     9th
    ix[40    +0]=8;
    ix[40    +1]=12;
    ix[40    +2]=17;
    ix[40    +3]=18;
    ix[40    +4]=13;
    //C     10th
    ix[45    +0]=9;
    ix[45    +1]=13;
    ix[45    +2]=18;
    ix[45    +3]=19;
    ix[45    +4]=14;
    //C     11th
    ix[50   +0]=10;
    ix[50   +1]=14;
    ix[50   +2]=19;
    ix[50   +3]=20;
    ix[50   +4]=15;
    //C     12th
    ix[55   +0]=16;
    ix[55   +1]=20;
    ix[55   +2]=19;
    ix[55   +3]=18;
    ix[55   +4]=17;
    fi0=fi1+fi2+fi1+fi3+fi3;
    //ちゃんと5角形ができているかテキストデータにして確認する.
    for(i=0;i<12;i++){
        for(j=1;j>=0;j--){
            if(j==1)    fprintf(fp1, "%f ", bx[i+j*12]);
            else        fprintf(fp1, "%f ", bx[i+j*12]-pi/2.0);
        }
        fputs("\n",fp1);
    }
    //ちゃんと5角形ができているかテキストデータにして確認する.
    for(i=0;i<20;i++){
        for(j=1;j>=0;j--){
            if(j==1)    fprintf(fp2, "%f ", ax[i+j*20]);
            else        fprintf(fp2, "%f ", ax[i+j*20]-pi/2.0);
        }
        fputs("\n",fp2);
    }
    //ちゃんと5角形ができているかテキストデータにして確認する.
    for(i=0;i<12;i++){
        for(j=0;j<5;j++){
            fprintf(fp3, "%f ", ax[ix[i*5+j]-1+20]);
            fprintf(fp3, "%f ", ax[ix[i*5+j]-1]-pi/2.0);
            fputs("\n",fp3);
            if (j==4){
                fprintf(fp3, "%f ", ax[ix[i*5+0]-1+20]);
                fprintf(fp3, "%f ", ax[ix[i*5+0]-1]-pi/2.0);
                fputs("\n",fp3);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return fi0;
    
}
