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

typedef enum {
    ADD = 0x00,
    SUB = 0x01,
    MUL = 0x02,
    DIV = 0x03,
    SHA = 0x04,
    MOD = 0x05,
    AND = 0x06,
    OR = 0x07,
    XOR = 0x08,
    NOT = 0x09,
    SHL = 0x0a,
    ROL = 0x0a,
    SHR = 0x0b,
    ROR = 0x0b,
    JMP = 0x0c,
    CALL = 0x0c,
    RET = 0x0d,
    RETI = 0x0d,
    INT = 0x0e,
    MOV = 0x0f,
    LD = 0x10,
    ST = 0x11,
    LDFLG = 0x12,
    STFLG = 0x13,
} opcode_t;

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

uint16_t cpu_fetch(cpu_t *cpu);

void execute(cpu_t *cpu);
void execute_general(cpu_t *cpu, uint16_t instruction);
void execute_imm(cpu_t *cpu, uint16_t instruction);

#endif
