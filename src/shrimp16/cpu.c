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
