#include <bus.h>

bus_t *bus_new(void) {
    bus_t *bus = (bus_t *)malloc(sizeof(bus_t));

    bus->ram = ram_new();

    return bus;
}

void bus_free(bus_t *bus) {
    ram_free(bus->ram);
    free(bus);
}

void bus_initialize_ram(bus_t *bus, uint16_t *binary, size_t binary_size) {
    ram_initialize(bus->ram, binary, binary_size);
}

uint16_t bus_read(bus_t *bus, uint16_t address) {
    if (address >= RAM_BASE && address <= RAM_END) {
        return ram_read(bus->ram, address);
    } else {
        fprintf(stderr, "Invalid Memory Area 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
}

void bus_write(bus_t *bus, uint16_t address, uint16_t value) {
    if (address >= RAM_BASE && address <= RAM_END) {
        ram_write(bus->ram, address, value);
    } else {
        fprintf(stderr, "Invalid Memory Area 0x%x\n", address);
        exit(EXIT_FAILURE);
    }
}
