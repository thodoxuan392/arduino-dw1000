#ifndef DW1000_PORT_H
#define DW1000_PORT_H

#include <cstdint>
#include <cstdbool>
#include <cstring>
#include <string>
#include <cmath>

#include <hal/clock.h>
#include <hal/gpio.h>
#include <hal/spi.h>

#include <utils_logger.h>

typedef unsigned char byte;
typedef bool boolean;
#define delayMicroseconds CLOCK_delayUs
#define delay CLOCK_delayMs
#define millis CLOCK_getTick
#define analogRead(value) 0
#define random(min,max) (rand()%(max - min) + min)
#define randomSeed(value) (void)value
#define HIGH   true
#define LOW false
#define DW_1000_SPI_ID SPI_ID_1
#define SPI_TRANSFER_TIME_MS 1000
#define SPI_TX_MAX_LEN 1024
#define SPI_RX_MAX_LEN 1024
#define DW1000_HW_RESET true
#define DW1000_DEBUG_STR_LN(str) utils_log_debug("%s\r\n", str)
#define DW1000_DEBUG_STR(str) utils_log_debug("%s", str)
#define DW1000_DEBUG_INT_LN(int) utils_log_debug("%d\r\n", int)
#define DW1000_DEBUG_INT(int) utils_log_debug("%d", int)


static inline uint32_t bitSet(byte &value, uint8_t pos){
    value |= 1 << pos;
    return value;
}

static inline uint32_t bitClear(byte &value, uint8_t pos){
    value &= ~(1 << pos);
    return value;
}

static inline uint32_t bitRead(byte value, uint8_t pos){
    return (value & (1<< pos)) != 0;
}

#endif  // DW1000_PORT_H