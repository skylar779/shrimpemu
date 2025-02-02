#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdint.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define RAM_SIZE 0x10000
#define RAM_BASE 0x50
#define RAM_END (RAM_BASE + RAM_SIZE)

#define BYTE     8
#define WORD     16

typedef struct {
    uint16_t memory[RAM_SIZE];
    uint16_t code_size;
} ram_t;

ram_t * ram_new(void);
void ram_free(ram_t *ram);

void ram_initialize(ram_t *ram, uint16_t *binary, size_t binary_size);

uint16_t ram_read(ram_t *ram, uint16_t address, size_t size);
void ram_write(ram_t *ram, uint16_t address, uint16_t value, size_t size);

uint16_t ram_read8(ram_t *ram, uint16_t address);
uint16_t ram_read16(ram_t *ram, uint16_t address);

void ram_write8(ram_t *ram, uint16_t address, uint16_t value);
void ram_write16(ram_t *ram, uint16_t address, uint16_t value);

#endif
