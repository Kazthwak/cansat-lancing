#define pin 0

//is bigger than the biggest struct, so can safely contain the data
struct maxPacketSize{
uint8_t filler[64];
};

//a packet containing data for the cansat to act upon
struct commandPacket{

};

//a packet containing the sensor data
struct dataPacket{

};


uint8_t chechChecksum(void* struct, uint16_t length){
//check if length bytes in struct add to 0
}

uint8_t isData(){
//return 0 for no data and 1 for data
}

uint8_t getData(void* struct){
//return 0 for nodata, and 1 for data
//place the data in the struct given
}

void sendData(void* struct, uint16_t length){
//send length bytes in the struct
}