#define MAXLEN  1024
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 int main(int argc, char** argv) {
     char* buffer;// char
     buffer = (char*)malloc(MAXLEN*(sizeof(char*)));
     memset(buffer,0,MAXLEN);
     long len_tc = 1;  //string hello len
     char* ret; // output 
     ret = (char*)malloc(MAXLEN*(sizeof(char*)));
     memset(ret,0,MAXLEN);
     printf("使用 'syscall' 呼叫system call\n");
     printf("please input 1 char:\n") ;
     __asm__ volatile (
        "mov $0, %%rax\n" //read是第0號system call
        "mov $0, %%rdi\n" //stdin
        "mov %1, %%rsi\n" //buffer
        "mov %2, %%rdx\n" //buffer size
        "syscall\n"        //使用syscall比int 0x80快
        "mov %%rsi, %0"        //ret = buffer
        :"=m"(ret)
        :"g" (buffer), "g" (len_tc)
        :"rax", "rbx", "rcx", "rdx");
        printf("回傳值是：%c\n", ret[0]);
}//main

