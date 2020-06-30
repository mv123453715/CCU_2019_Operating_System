#define MAXLEN  1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv) {
    char* buffer;// char
    buffer = (char*)malloc(MAXLEN*(sizeof(char*)));
    memset(buffer,0,MAXLEN);
    int len = 1;  //string hello len
    char* ret; // output 
    ret = (char*)malloc(MAXLEN*(sizeof(char*)));
    memset(ret,0,MAXLEN);
    printf("使用 'int 0x80' 呼叫system call\n");
    printf("please input 1 char:\n") ;
    
    __asm__ volatile (
       "mov $3, %%rax\n"    //read是第3號system call   rax = sys_read
       "mov $0, %%rbx\n"    //stdin                    filedes 文件描述符號
       "mov %1, %%rcx\n"    //buffer                    rcx = hello
       "mov %2, %%rdx\n"    //buffer size               rdx = len 
       "int $0x80\n"        // syscall software exception
       "mov %%rcx, %0"      //ret = buffer
       : "=m"(ret)          //output
       : "g" (buffer), "g" (len)//input
       : "rax", "rbx", "rcx", "rdx");//restore register
    printf("回傳值是：%c\n", ret[0]);//printf
}//main

