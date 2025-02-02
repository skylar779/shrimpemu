#include <bus.h>

#include <stdio.h>
#include <errno.h>

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

int bus_read(bus_t *bus, uint16_t address, uint16_t *out) {
    if (out == NULL) {
        return EINVAL;
    }

    if (address >= RAM_BASE && address <= RAM_END) {
        *out = ram_read(bus->ram, address);
        return 0;
    } else {
        return EFAULT;
    }
}

int bus_write(bus_t *bus, uint16_t address, uint16_t value) {
    if (address >= RAM_BASE && address <= RAM_END) {
        ram_write(bus->ram, address, value);
        return 0;
    } else {
        return EFAULT;
    }
}
