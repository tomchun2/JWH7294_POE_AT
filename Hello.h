#define FW_VERSION_MAJOR 0
#define FW_VERSION_MINOR 5

#define MCLK_HZ 1000000UL // 3MHz MCLK, the way the MCU starts up

//I2C variables
#define I2C_SLAVE_ADDRESS 0x22   //7bit=0x48,8bit=0x90

#define MAX_BUFFER_SIZE     20

uint8_t transmitData;
unsigned char TXByteCtr;
unsigned char SlaveFlag = 0;
//==== cmd len====//
const uint16_t cmd_send_len[]={4,1,4,1,1,1,1};
//==== cmd 1 =====//
const uint8_t cmd_1_regAddr[]={0xc0,0xc1,0xc3,0xc5};
const uint8_t cmd_1_regData[]={0x6c,0xc0,0x1f,0x10};
//==== cmd 2(reset) =====//
const uint8_t cmd_2_regAddr[]={0x1A};
const uint8_t cmd_2_regData[]={0x20};
//==== cmd 3 =====//
const uint8_t cmd_3_regAddr[]={0xec,0xec,0xec,0xec};
const uint8_t cmd_3_regData[]={0x00,0x00,0x00,0x00};
//==== cmd 4(read) ====//
const uint8_t cmd_4_regAddr[]={0xec};
const uint8_t cmd_4_regData[]={0x00};
//==== cmd 5 (enable sram) ====//
const uint8_t cmd_5_regAddr[]={0xed};
const uint8_t cmd_5_regData[]={0x80};
//==== cmd 7 (release CPU) ====//
const uint8_t cmd_7_regAddr[]={0xed};
const uint8_t cmd_7_regData[]={0x10};



/* ReceiveBuffer: Buffer used to receive data in the ISR
 * RXByteCtr: Number of bytes left to receive
 * ReceiveIndex: The index of the next byte to be received in ReceiveBuffer
 * TransmitBuffer: Buffer used to transmit data in the ISR
 * TXByteCtr: Number of bytes left to transfer
 * TransmitIndex: The index of the next byte to be transmitted in TransmitBuffer
 * */
#pragma PERSISTENT(ReceiveBuffer)
uint8_t ReceiveBuffer[MAX_BUFFER_SIZE] = {0};
#pragma PERSISTENT(RXByteCtr)
uint8_t RXByteCtr = 0;
#pragma PERSISTENT(ReceiveIndex)
uint8_t ReceiveIndex = 0;
#pragma PERSISTENT(TransmitBuffer)
uint8_t TransmitBuffer[MAX_BUFFER_SIZE] = {0};
#pragma PERSISTENT(TXByteCtr)
uint8_t TXByteCtr = 0;
#pragma PERSISTENT(TransmitIndex)
uint8_t TransmitIndex = 0;
#pragma PERSISTENT(fw_size)
uint16_t fw_size=0;
#pragma PERSISTENT(count)
uint16_t count=0;

#pragma PERSISTENT(FW_Ver)
uint8_t FW_Ver[2] = {0};

uint8_t dl_flag=0;

#define POE_CTL_PIN BIT3   //P2.3






