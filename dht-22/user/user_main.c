#include "driver/uart.h"
#include "osapi.h"
#include "dht.h"

void user_init(void) {
  uart_init(BIT_RATE_115200, BIT_RATE_115200);

  os_printf("SDK Version: %s\r\n", system_get_sdk_version());

  DHTInit(SENSOR_DHT22, 10000);
}

