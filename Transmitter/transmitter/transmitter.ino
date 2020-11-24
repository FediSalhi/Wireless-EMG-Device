#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN         
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.


void setup() {

radio.begin();                  //Starting the Wireless communication
radio.openWritingPipe(address); //Setting the address where we will send the data
radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
radio.stopListening();          //This sets the module as transmitter
}
void loop()
{

// Read filtered EMG signal as anlog input
int sensorValue = analogRead(A0);
float voltage= sensorValue * (5.0 / 1023.0);

voltage_str = String(voltage);

//const char text[] = "Your Button State is HIGH";

radio.write(&voltage_str, sizeof(voltage_str));                  //Sending the message to receiver

}
