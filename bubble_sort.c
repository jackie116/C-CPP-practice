//
//  main.c
//  c testing
//
//  Created by 黃昱崴 on 2020/2/21.
//  Copyright © 2020 黃昱崴. All rights reserved.
//bubble sort

#include <stdio.h>
#define SIZE 5
void show(int a[]);
void bubble(int a[]);
int main(void) {
    // insert code here...
    int a[SIZE]={26,5,81,7,63};
    
    printf("排序前：\n");
    show(a);
    bubble(a);
    printf("排序後：\n");
    show(a);
    
    return 0;
}

//顯示函式
void show(int a[]){
    for(int i=0;i<SIZE;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

//bubble sorting
void bubble(int a[]){
    int temp=0;
    for(int i=0;i<SIZE-1;i++){
        for(int j=0;j<SIZE-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    }
    
}
