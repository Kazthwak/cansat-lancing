#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>
#include <stdint.h>

#define pin 0
#define packetHeader uint8_t id; uint16_t checksum;
#define phSize 3
#define commonPacketProperties uint64_t timestamp; 

//is bigger than the biggest struct, so can safely contain the data
struct maxPacketSize{
packetHeader
uint8_t filler[64-phSize];
// uint8_t filler[2];
};

//a packet containing data for the cansat to act upon, only if needed. If not I can restructure a bit
struct commandPacket{
packetHeader
commonPacketProperties
};

//a packet containing the sensor data
struct dataPacket{
packetHeader
commonPacketProperties
};


//both seem to work
void generateChecksum(struct maxPacketSize* structptr){
structptr->checksum = 0;
uint16_t sum = 0;
for(uint8_t i = 0; i < sizeof(struct maxPacketSize)/2; i++){
	sum += ((uint16_t*)structptr)[i];
}
structptr->checksum = (sum*-1);
}

uint8_t chechChecksum(struct maxPacketSize* structptr){
//check if length bytes in struct add to 0 as a uint16
uint16_t sum = 0;
for(uint8_t i = 0; i < sizeof(struct maxPacketSize)/2; i++){
	sum += ((uint16_t*)structptr)[i];
}
return(!sum);
}

uint8_t isData(){
//return 0 for no data and 1 for data
}

uint8_t getData(struct maxPacketSize *structptr){
//return 0 for nodata, and 1 for data
//place the data in the struct given
}

//wait for data to be available then recieve it
void waitForData(struct maxPacketSize *structptr){
restart:
if(getData(structptr)){
	return;
}
goto restart;
}


void sendData(struct maxPacketSize *structptr){
//send length bytes in the struct
}

void init(){
//initialize the library for transmition and recieving
Mirf.cePin = 7;
Mirf.csnPin = 8;
Mirf.spi = &MirfHardwareSpi;
Mirf.init();
Mirf.setRADDR((byte *)"serv1");
// Mirf.payload = sizeof(maxPacketSize);
Mirf.payload = sizeof(int)
Mirf.config();
}