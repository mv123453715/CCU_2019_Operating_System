#include <stdio.h>
int main(int argc, char** argv) {
    unsigned long msr;
    asm volatile ( "rdtsc\n\t"  // Returns the time in EDX:EAX.
                  "shl $32, %%rdx\n\t"    // Shift edx to the upper bits left. 
                  "or %%rdx, %%rax\n\t"          // 'Or' in the lower bits. 
                                 //rdx upper bits is edx or lower bit eax and store to rax  
                  "mov %%rax, %0\n" //move will store memory fully
                 : "=m" (msr) // msr會放在記憶體 //=a show that rax low bit from eax 
                 :
                 : "rdx");
    printf("msr: %lx\n", msr);
}

