#include "mbed.h"

DigitalOut pc_activity(LED1);
DigitalOut uart_activity(LED2);
Serial pc(USBTX,USBRX);
Serial uart(p28,p27);

int main() {

    while(1) {
        if(pc.readable()) {
            uart.putc(pc.getc());
            pc_activity = !pc_activity;
        }
        if(uart.readable()) {
            pc.putc(uart.getc());
            uart_activity = !uart_activity;
        }
    }
}
