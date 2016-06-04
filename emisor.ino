#include <VirtualWire.h>
void setup()
{
// Initialize the IO and ISR
vw_setup(2000); // Bits per sec
}
void loop()
{
send((char*)"hum=100&tem=200&gps_x=69&gps_y=4");
delay(1000);
}
void send (char *message)
{
vw_send((uint8_t *)message, strlen(message));
vw_wait_tx(); // Wait until the whole message is gone
}
