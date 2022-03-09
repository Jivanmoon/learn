// Memory Management Unit 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "cpu.h"
#include "memory.h"
#include "common.h"

uint64_t va2pa(uint64_t vaddr, core_t *cr)
{
    return vaddr % PHYSICAL_MEMORY_SPACE;
}