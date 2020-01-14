/*
 * AHRS_Frames.h
 *
 *  Created on: 11.01.2020
 *      Author: Piotr Zieliński
 */

#ifndef AHRS_FRAMES_H_
#define AHRS_FRAMES_H_

#include <stdint.h> //Just for Visual Studio Code's InteliJ

#define STD_MSG_MAX_PAYLOAD_LEN   254                      //Max length of payload in standard frame
#define STD_MSG_SIZEMAX           STD_MSG_MAX_PAYLOAD_LEN + 5    //Max length of whole standard frame
#define EXT_MSG_MAX_PAYLOAD_LEN   2048                     //Max length of payload in extended frame
#define EXT_MSG_SIZEMAX           EXT_MSG_MAX_PAYLOAD_LEN + 8    //Max length of whole extended frame

typedef uint8_t AHRS_RawFrame[__STD_MSG_SIZEMAX];

typedef enum {
    XDI_TemperatureGroup = 

} AHRS_MID;


/*typedef struct
{
    uint8_t Preambule = 0xFA;   //Preambule. Indicator of start of packet    
    uint8_t BID = 0xFF;         //Bus identifier or Address   
    uint8_t MID;                //Message identifier
    uint8_t LEN;                //Nr of bytes in Data field. Max 254 for Standard Lengh message frame
    uint8_t Data[254];          //Data bytes
    uint8_t Checksum;           //Checksumm of message

} AHRS_StdLenFrame;

typedef struct
{
    uint8_t Preambule = 0xFA;   //Preambule. Indicator of start of packet    
    uint8_t BID = 0xFF;         //Bus identifier or Address    
    uint8_t MID;                //Message identifier
    uint8_t LEN = 255;          //255 for Extended Lengh message frame
    uint16_t EXTLEN;            //Nr of bytes in Data field:  (255 - 2048)
    uint8_t Data[2048];         //Data bytes
    uint8_t Checksum;           //Checksumm of message    
} AHRS_ExtLenFrame; */

typedef struct
{
    uint8_t MID;                                //Message identifier
    uint8_t LEN;                                //Nr of bytes in Data field
    uint8_t Data[__STD_MSG_MAX_PAYLOAD_LEN];    //Data field

} AHRS_StdMessage;

typedef struct
{
    uint8_t MID;                                //Message identifier
    uint8_t LEN;                                //Nr of bytes in Data field
    uint8_t Data[__EXT_MSG_MAX_PAYLOAD_LEN];    //Data field
} AHRS_ExtMessage;

typedef struct
{
    /* data */
}AHRS_Quaternions;


AHRS_StdMessage AHRS_Parse_StdFrame(AHRS_STDFrame_Raw raw);
AHRS_ExtMessage AHRS_Parse_ExtFrame(AHRS_EXTFrame_Raw raw);






#endif /* AHRS_FRAMES_H_ */