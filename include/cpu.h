#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include <stdlib.h>
#include <bus.h>

#define BYTE            8
#define WORD            16
#define DWORD           32

#define NUM_REGISTERS   16

typedef struct {
    uint16_t registers[NUM_REGISTERS];
} registers_t;

uint16_t register_read(registers_t *registers, size_t index);
void register_write(registers_t *registers, size_t index, uint16_t value);

typedef struct {
    registers_t registers;
    uint16_t program_counter;
    uint16_t flags_register;
    bus_t *bus;
} cpu_t;

cpu_t * cpu_new(void);
void cpu_free(cpu_t *cpu);

#endif
