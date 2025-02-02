#ifndef _BUS_H
#define _BUS_H

#include <ram.h>

typedef struct {
    ram_t *ram;
} bus_t;

bus_t * bus_new(void);
void bus_free(bus_t *bus);

void bus_initialize_ram(bus_t *bus, uint16_t *binary, size_t size);

uint16_t bus_read(bus_t *bus, uint16_t address, size_t size);
void bus_write(bus_t *bus, uint16_t address, uint16_t value, size_t size);

#endif
