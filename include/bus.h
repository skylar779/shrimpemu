#ifndef BUS_H
#define BUS_H

#include <ram.h>

#include <stdlib.h>
#include <stdint.h>

typedef struct {
    ram_t *ram;
} bus_t;

bus_t * bus_new(void);
void bus_free(bus_t *bus);

void bus_initialize_ram(bus_t *bus, uint16_t *binary, size_t binary_size);

int bus_read(bus_t *bus, uint16_t address, uint16_t *out);
int bus_write(bus_t *bus, uint16_t address, uint16_t value);

#endif
