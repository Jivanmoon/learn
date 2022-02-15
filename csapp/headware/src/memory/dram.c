//
// Created by jivan on 2022/2/12.
//
#include "dram.h"
#include "../cpu/register.h"
#include "../cpu/mmu.h"
#include <stdio.h>
#define SRAM_CAHCE_SETTING 0

uint64_t read64bits_dram(uint64_t paddr) {
    if(SRAM_CAHCE_SETTING == 1) {
        return 0x0;
    }
    uint64_t val = 0x0;
    for(int i = 0; i < 8; ++i) {
        val += (((uint64_t)mm[paddr + i]) << (8 * i));
    }
    return val;
}

void write64bits_dram(uint64_t paddr, uint64_t data) {
    if(SRAM_CAHCE_SETTING == 1) {
        return ;
    }

    for(int i = 0; i < 8; ++i) {
        mm[paddr + i] = (data >> (i * 8)) & 0xff;
    }
}

void print_register() {
    printf("rax = %16lx\trbx = %16lx\trcx = %16lx\trdx = %16lx\n",
           reg.rax, reg.rbx, reg.rcx, reg.rdx);
    printf("rsi = %16lx\trdi = %16lx\trbp = %16lx\trsp = %16lx\n",
           reg.rsi, reg.rdi, reg.rbp, reg.rsp);
    printf("rip = %16lx\n", reg.rip);
}

void print_stack() {
    int n = 10;
    uint64_t *high = (uint64_t *)&mm[va2pa(reg.rsp)];
    high = &high[n];

    uint64_t rsp_start = reg.rsp + n * 8;

    for(int i = 0; i < 2 * n; ++i) {
        uint64_t *ptr = (uint64_t *)(high - i);
        printf("0x%lx : %16lx", rsp_start, (uint64_t)*ptr);

        if(i == n) {
            printf(" <== rsp");
        }
        rsp_start -= 8;
        printf("\n");
    }
}
