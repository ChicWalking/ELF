#include <iostream>
#include"elf.h"
#include <stdio.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    FILE  * file;
    file=fopen("C:/Users/rzx/Desktop/elf/elf/libhello-jni.so","rb");
    if (NULL==file)
    {
        printf("failde");
    }
    fseek(file,0,SEEK_END);
    int count = ftell(file);
    fseek(file,0,SEEK_SET);
    char buff[count];
    if(NULL==(fread(buff,1,count,file)))
    printf("fread failed");
    Elf32_Ehdr elf_head;
    memset((void*)&elf_head,0,sizeof(Elf32_Ehdr));
    memcpy((void*)&elf_head,buff,sizeof(Elf32_Ehdr));
    printf("magic:");
    for(int i=0;i<16;i++)
    {
        printf("%X  ",elf_head.e_ident[i]);
    }
    printf("\nfile type:");
    if(0==elf_head.e_type)
    {
        printf("null type");
    }
    else if(1==elf_head.e_type)
        printf("reset file");
    else if(2==elf_head.e_type)
        printf("exe file");
    else if(3==elf_head.e_type)
        printf("shared file");

    printf("\nfile system:");
    if(0==elf_head.e_machine)
        printf("null system");
    else if(1==elf_head.e_machine)
        printf("AT&T WE 32100");
    else if(2==elf_head.e_machine)
        printf("SPARC");
    else if(3==elf_head.e_machine)
        printf("Intel 80386 ");
    else if(4==elf_head.e_machine)
        printf("Motorola 68000");
    else if(5==elf_head.e_machine)
        printf("Motorola 88000");
    else if(7==elf_head.e_machine)
        printf("Intel 80860");
    else if(8==elf_head.e_machine)
        printf("MIPS RS3000");
    printf("\nentry:%x\n",elf_head.e_entry);
    printf("head size:%d",elf_head.e_ehsize);
    printf("start of section offset:%d\n",elf_head.e_shoff);
    printf("start of progtam offset:%d\n",elf_head.e_phoff);




}
