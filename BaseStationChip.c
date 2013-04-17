#include "mbed.h"
#include <stdio.h>

DigitalOut pc_activity(LED1);
DigitalOut uart_activity(LED2);
DigitalOut errorLED(LED3);
DigitalOut winnerLED(LED4);
Serial pc(USBTX,USBRX);
Serial uart(p28,p27);

int receiveData(void);
int sendCommands(void);
int main() {
    char buffer[8];
    char handshake[] = "0110001";
    char requestToSend[] = "1001110";
    while (1) {
        uart_activity = 0;
        if (pc.readable()) {
            pc.gets(buffer,8);
            pc_activity = !pc_activity;
            if (strncmp(handshake,buffer,8) == 0) { 
                winnerLED = !winnerLED;
                pc.printf("%s", handshake); //send response
                receiveData();
            }
            if (strncmp(requestToSend,buffer,8) == 0) {
                errorLED = !errorLED;
                pc.printf("%s", requestToSend); //send response
                sendCommands();
            }
         }
         
            
    }
}

int receiveData(void) {
    char data[] = "48685433003393673274794796391420506490";
    for (int i=0;;i++) {
       // if (uart.readable()){ implement once connected to transmitter
            // uart.gets(data,38); 
            pc.printf("%s",data);
            return 0;        
         //}
        if (i==100) return -1;
    }
}
int sendCommands(void) {
    char commands[19];
    for (int i=0;;i++) {
        //if (pc.readable()){
            pc.gets(commands,19);
            uart_activity = !uart_activity;
            pc.printf("%s",commands); // Test line to ensure Data is read by the LPC1768 correctly
          //while (1) {
           // if (uart.writeable(){
                //uart.printf("%s",commands);
                  return 0;
            // }
           //}
        //}
        if (i==100) return -1;
    }
}
 
        




