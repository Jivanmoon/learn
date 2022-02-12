//
// Created by jivan on 2022/2/12.
//
#include "mmu.h"
#include "../memory/dram.h"

uint64_t va2pa(uint64_t vaddr) {
    return vaddr % MM_LEN;
}

