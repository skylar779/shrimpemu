#ifndef RAM_H
#define RAM_H

#include <stdint.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define RAM_SIZE 0xffaf
#define RAM_BASE 0x50
#define RAM_END (RAM_SIZE + RAM_BASE)

#define WORD     16

typedef struct {
    uint16_t memory[RAM_SIZE];
    uint16_t code_size;
} ram_t;

ram_t * ram_new(void);
void ram_free(ram_t *ram);

void ram_initialize(ram_t *ram, uint16_t *binary, size_t binary_size);

uint16_t ram_read(ram_t *ram, uint16_t address);
void ram_write(ram_t *ram, uint16_t address, uint16_t value);

#endif
