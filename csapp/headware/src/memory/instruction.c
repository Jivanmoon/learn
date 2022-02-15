#include "instruction.h"
#include "../cpu/mmu.h"
#include "../cpu/register.h"
#include <stdio.h>
#include "dram.h"
static uint64_t decode_od(od_t od) {
    if(od.type == IMM) {
        return *((uint64_t *)&od.imm);
    }
    else if(od.type == REG) {
        return (uint64_t)od.reg1;
    }
    else {
        // mm
        uint64_t vaddr = 0;
        if(od.type == MM_IMM) {
            vaddr = od.imm;
        }
        else if(od.type == MM_REG) {
            //stroe reg
            vaddr = *(od.reg1);
        }
        else if(od.type == MM_IMM_REG) {
            vaddr = *(od.reg1) + od.imm;
        }
        else if(od.type == MM_REG1_REG2) {
            vaddr = *(od.reg1) + *(od.reg2);
        }
        else if(od.type == MM_IMM_REG1_REG2) {
            //stroe reg
            vaddr = *(od.reg1) + *(od.reg2) + od.imm;
        }
        else if(od.type == MM_REG2_S) {
            //stroe reg
            vaddr = (*(od.reg2)) * od.scal;
        }
        else if(od.type == MM_IMM_REG2_S) {
            //stroe reg
            vaddr = (*(od.reg2)) * od.scal +od.imm;
        }
        else if(od.type == MM_REG1_REG2_S) {
            //stroe reg
            vaddr = *(od.reg1) + (*(od.reg2)) * od.scal;
        }
        else if(od.type == mm_IMM_REG1_REG2_S) {
            //stroe reg
            vaddr = od.imm + *(od.reg1) + (*(od.reg2)) * od.scal;
        }
        return vaddr;
    }
}

void instruction_cycle() {
    inst_t *instr = (inst_t *)reg.rip;
    //imm : imm
    //reg : value
    //mm : paddr
    uint64_t src = decode_od(instr -> src);
    uint64_t dst = decode_od(instr -> dst);

    handler_t handler = handler_table[instr -> op];
    handler(src, dst);
    printf("    %s\n", instr -> code);
}

void init_handler_table() {
    handler_table[mov_reg_reg] = &mov_reg_reg_handler;
    handler_table[add_reg_reg] = &add_reg_reg_handler;
    handler_table[call] = &call_handler;
    handler_table[push_reg] = &push_reg_handler;
    handler_table[pop_reg] = &pop_reg_handler;
    handler_table[mov_reg_mem] = &mov_reg_mem_handler;

}

void mov_reg_reg_handler(uint64_t src, uint64_t dst) {
    *(uint64_t *)dst = *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void add_reg_reg_handler(uint64_t src, uint64_t dst) {
    *(uint64_t *)dst = *(uint64_t *)dst + *(uint64_t *)src;
    reg.rip = reg.rip + sizeof(inst_t);
}

void call_handler(uint64_t src, uint64_t dst) {
    //src: imm address of called function
    reg.rsp -= 8;
    //write return address to rsp memory
    write64bits_dram(
            va2pa(reg.rsp),
            reg.rip + sizeof(inst_t)
            );
    reg.rip = src;
}

void push_reg_handler(uint64_t src, uint64_t dst) {
    //src:reg
    //dst:empty
    reg.rsp = reg.rsp - 0x8;
    write64bits_dram(
            va2pa(reg.rsp),
            *(uint64_t *)src
            );
    reg.rip = reg.rip + sizeof(inst_t);
}

void pop_reg_handler(uint64_t src, uint64_t dst) {
    //todo
}

void mov_reg_mem_handler(uint64_t src, uint64_t dst) {
    //src:reg
    //dst:mem vaddr
    write64bits_dram(
            va2pa(dst),
            *(uint64_t *)src
            );
    reg.rip = reg.rip + sizeof(inst_t);
}