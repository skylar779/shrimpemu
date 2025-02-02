#include <cpu.h>

#include <memory.h>

uint16_t register_read(registers_t *registers, size_t index) {
    return registers->registers[index];
}

void register_write(registers_t *registers, size_t index, uint16_t value) {
    registers->registers[index] = value;
}

cpu_t *cpu_new(void) {
    cpu_t *cpu = (cpu_t *)malloc(sizeof(cpu_t));
    memset(cpu->registers.registers, 0, NUM_REGISTERS);
    cpu->flags_register = 0;
    cpu->program_counter = 0;
    cpu->bus = bus_new();
    return cpu;
}

void cpu_free(cpu_t *cpu) {
    bus_free(cpu->bus);
    free(cpu);
}

uint16_t cpu_fetch(cpu_t *cpu) {
    uint16_t present_program_counter = cpu->program_counter;

    return bus_read(cpu->bus, present_program_counter);
}

void execute(cpu_t *cpu) {
    uint16_t instruction = cpu_fetch(cpu);
    uint16_t opcode = (instruction & 0xf800) >> 11;
    uint16_t flags = (instruction & 0x70) >> 4;
    
    switch (opcode) {
    case ADD:
        if (flags & 0x4) {
            cpu->program_counter += 1;
            execute_imm(cpu, instruction);
            cpu->program_counter += 1;
        }
    
    default:
        break;
    }
}

void execute_general(cpu_t *cpu, uint16_t instruction)
{
}

void execute_imm(cpu_t *cpu, uint16_t instruction) {
    uint16_t immediate = cpu_fetch(cpu);

    
}
