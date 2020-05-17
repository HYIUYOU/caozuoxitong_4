//
//  main.cpp
//  操作系统实验四
//
//  Created by 何忆源 on 2020/5/10.
//  Copyright © 2020 何忆源. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 
 
int main(int argc,char *argv[])
{
    pid_t pid1,pid2;        //进程标识符
    pid1 = fork();     //创建一个新的进程
    if(pid1<0)
    {
        printf("创建进程失败!");
        exit(1);
    }
    else if(pid1==0)   //如果pid为0则表示当前执行的是子进程
    {
        printf("子进程B,进程标识符是%d\n",getpid());
    }
    else          //否则为父进程
    {
        pid2 = fork();//创建一个新的进程
        if(pid2<0)
        {
            printf("创建进程失败!");
            exit(1);
        }
        else if(pid2==0)   //如果pid为0则表示当前执行的是子进程
        {
            printf("子进程C,进程标识符是%d\n",getpid());
        }
        else          //否则为父进程
        {
            printf("父进程A,进程标识符是%d\n",getpid());
        }
    }
    return 0;
}

