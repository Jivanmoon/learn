//
// Created by jivan on 2022/2/9.
//
#include "cpu/register.h"
#include "memory/instruction.h"

int main() {
    return 0;
}

uint64_t decode_od(od_t od) {
    if(od.type == IMM) {
        return od.imm;
    }
    else if(od.type == REG) {
        return *(uint64_t *)od.reg1;
    }
    else {
        uint64_t addr;
        return mm[addr % MM_LEN];
    }
}

