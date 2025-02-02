#include <ram.h>

ram_t * ram_new(void) {
    ram_t *ram = (ram_t *)malloc(sizeof(ram_t));
    memset(ram->memory, 0, RAM_SIZE);
    ram->code_size = 0;

    return ram;
}

void ram_free(ram_t *ram) {
    free(ram);
}

void ram_initialize(ram_t *ram, uint16_t *binary, size_t binary_size) {
    ram->code_size = binary_size;
    memcpy(ram, binary, binary_size);
}

uint16_t ram_read(ram_t *ram, uint16_t address, size_t size) {
    switch (size) {
    case BYTE:
        return ram_read8(ram, address);
        break;
    case WORD:
        return ram_read16(ram, address);
        break;
    default:
        fprintf(stderr, "ERROR: Invalid Read Size %zu\n", size);
        exit(EXIT_FAILURE);
        break;
    }
    __builtin_unreachable();
}

void ram_write(ram_t *ram, uint16_t address, uint16_t value, size_t size) {
    switch (size)
    {
    case BYTE:
        ram_write8(ram, address, value);
        break;
    case WORD:
        ram_write16(ram, address, value);
        break;
    default:
        fprintf(stderr, "ERROR: Invalid Write Size %zu\n", size);
        exit(EXIT_FAILURE);
        break;
    }
}

// Read the lower byte of the address.
uint16_t ram_read8(ram_t *ram, uint16_t address) {
    size_t index = address - RAM_BASE;
    return ram->memory[index] & 0xff;
}

uint16_t ram_read16(ram_t *ram, uint16_t address) {
    size_t index = address - RAM_BASE;
    return ram->memory[index];
}

// Write lower byte of the address.
void ram_write8(ram_t *ram, uint16_t address, uint16_t value) {
    size_t index = address - RAM_BASE;
    ram->memory[index] = value & 0xff;
}

void ram_write16(ram_t *ram, uint16_t address, uint16_t value) {
    size_t index = address - RAM_BASE;
    ram->memory[index] = value;
}

