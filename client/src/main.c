#include "driver/uart.h"
#include "osapi.h"
#include "user_interface.h"
#include "wifi_settings.h"

void user_init(void) {
  uart_init(BIT_RATE_115200, BIT_RATE_115200);

  os_printf("SDK Version: %s\r\n", system_get_sdk_version());

  // Set wifi to Station Mode:
  wifi_set_opmode(0x01);

  // Configure wifi settings:
  struct station_config stationConfig;
  stationConfig.bssid_set = 0; // Don't check AP MAC address
  os_memcpy(&stationConfig.ssid, SSID, 32);
  os_memcpy(&stationConfig.password, PASSWORD, 64);
  wifi_station_set_config(&stationConfig);
}

