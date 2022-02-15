//
// Created by jivan on 2022/2/12.
//

#ifndef LEARNCPP_DRAM_H
#define LEARNCPP_DRAM_H
#include <stdint.h>

#define MM_LEN 1000
uint8_t mm[MM_LEN]; //physical memory

uint64_t read64bits_dram(uint64_t paddr);

void write64bits_dram(uint64_t paddr, uint64_t data);

void print_register();

void print_stack();


#endif //LEARNCPP_DRAM_H
