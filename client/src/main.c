#include "driver/uart.h"
#include "osapi.h"
#include "user_interface.h"
#include "wifi_settings.h"

os_timer_t ip_check_timer;

void check_ip() {
  os_timer_disarm(&ip_check_timer);
  os_printf("Checking ip...\r\n");

  struct ip_info ipconfig;
  wifi_get_ip_info(STATION_IF, &ipconfig);

  if (wifi_station_get_connect_status() == STATION_GOT_IP)
  {
    os_printf("Got IP: ");
    uint8 buf[20];
    os_bzero(buf, sizeof(buf));
    os_printf(IPSTR, IP2STR(&ipconfig.ip));
  }
  else
  {
    os_printf("Failed to get IP - retrying.");
    os_timer_arm(&ip_check_timer, 10000, 0);
  }
}


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

  // Start IP check timer
  os_timer_disarm(&ip_check_timer);
  os_timer_setfn(&ip_check_timer, (os_timer_func_t *)check_ip, NULL);
  os_timer_arm(&ip_check_timer, 10000, 0);
}


