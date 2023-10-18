#define pin 0
#include <stdint.h>
#define packetHeader uint8_t id; uint16_t checksum;
#define phSize 3
#define commonPacketProperties uint64_t timestamp; 

//is bigger than the biggest struct, so can safely contain the data
struct maxPacketSize{
packetHeader
uint8_t filler[64-phSize];
};

//a packet containing data for the cansat to act upon
struct commandPacket{
packetHeader
commonPacketProperties
};

//a packet containing the sensor data
struct dataPacket{
packetHeader
commonPacketProperties
};


uint8_t chechChecksum(struct maxPacketSize *structptr){
//check if length bytes in struct add to 0 as a uint16
}

uint8_t isData(){
//return 0 for no data and 1 for data
}

uint8_t getData(struct maxPacketSize *structptr){
//return 0 for nodata, and 1 for data
//place the data in the struct given
}

void sendData(struct maxPacketSize *structptr){
//send length bytes in the struct
}

void init(){
//initialize the library for transmition and recieving
}