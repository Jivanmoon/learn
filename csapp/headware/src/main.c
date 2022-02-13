//
// Created by jivan on 2022/2/9.
//
#include "cpu/register.h"
#include "memory/instruction.h"
#include "disk/code.c"
#include "memory/dram.h"
#include "cpu/mmu.h"
#include <stdio.h>
#include "elf.h"

int main() {
    init_handler_table();
    //init
    reg.rax = 0x12340000;
    reg.rbx = 0x0;
    reg.rcx = 0x7ffff7fa7718;
    reg.rdx = 0xabcd;
    reg.rsi = 0x7fffffffcb88;
    reg.rdi = 0x1;
    reg.rbp = 0x7fffffffcaa0;
    reg.rsp = 0x7fffffffca80;
    reg.rip = (uint64_t)&program[11];


    mm[va2pa(0x7fffffffcaa0)] = 0x00401160;     //rbp
    mm[va2pa(0x7fffffffca9f)] = 0x12340000;
    mm[va2pa(0x7fffffffca90)] = 0x0000abcd;
    mm[va2pa(0x7fffffffca8f)] = 0x00401020;
    mm[va2pa(0x7fffffffca80)] = 0x00401160;     //rsp

    //run instruction
    for(int i = 0; i < INST_LEN; ++i) {
        instruction_cycle();
    }


    //verify
    int match = 1;
    match = match && (reg.rax == 0x1234abcd);
    match = match && (reg.rbx == 0x0);
    match = match && (reg.rcx == 0x7ffff7fa7718);
    match = match && (reg.rdx == 0x12340000);
    match = match && (reg.rsi == 0xabcd);
    match = match && (reg.rdi == 0x12340000);
    match = match && (reg.rbp == 0x7fffffffcaa0);
    match = match && (reg.rsp == 0x7fffffffca80);

    match = match && (mm[va2pa(0x7fffffffcaa0)] == 0x00401160);
    match = match && (mm[va2pa(0x7fffffffca9f)] == 0x12340000);
    match = match && (mm[va2pa(0x7fffffffca90)] == 0x0000abcd);
    match = match && (mm[va2pa(0x7fffffffca8f)] == 0x1234abcd);
    match = match && (mm[va2pa(0x7fffffffca80)] == 0x00401160);

    if(match == 1) {
        printf("register match\n");
    }
    else {
        printf("register not match\n");
    }

    match = match && (mm[va2pa(0x7fffffffcaa0)] == 0x00401160);
    match = match && (mm[va2pa(0x7fffffffca9f)] == 0x12340000);
    match = match && (mm[va2pa(0x7fffffffca90)] == 0x0000abcd);
    match = match && (mm[va2pa(0x7fffffffca8f)] == 0x1234abcd);
    match = match && (mm[va2pa(0x7fffffffca80)] == 0x00401160);

    if(match == 1) {
        printf("memory match\n");
    }
    else {
        printf("memory not match\n");
    }
    return 0;
}

