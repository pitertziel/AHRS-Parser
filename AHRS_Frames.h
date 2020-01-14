/*
 * AHRS_Frames.h
 *
 *  Created on: 11.01.2020
 *      Author: Piotr Zieliński
 */

#ifndef AHRS_FRAMES_H_
#define AHRS_FRAMES_H_

#include <stdint.h> //Just for Visual Studio Code's InteliJ

/* Frames lengths - begin*/
#define STD_MSG_MAX_PAYLOAD_LEN   254                      //Max length of payload in standard frame
#define STD_MSG_SIZEMAX           STD_MSG_MAX_PAYLOAD_LEN + 5    //Max length of whole standard frame
#define EXT_MSG_MAX_PAYLOAD_LEN   2048                     //Max length of payload in extended frame
#define EXT_MSG_SIZEMAX           EXT_MSG_MAX_PAYLOAD_LEN + 8    //Max length of whole extended frame
/* Frames lengths - end*/

typedef uint8_t AHRS_RawStdFrame[STD_MSG_SIZEMAX];
typedef uint8_t AHRS_RawExtFrame[EXT_MSG_SIZEMAX];

/*Structures defining possible pockets - begin*/
typedef struct
{
    double q[4];
}Pocket_Quaternions;

typedef struct
{
    double Roll, Pitch, Yaw;
}Pocket_EulerAngles;

typedef struct
{
    double a,b,c,d,e,f,g,h,i;
}Pocket_RotationMatrix;

typedef struct
{
    double dv_x, dv_y, dv_z;
}Pocket_DeltaV;

typedef struct
{
    double dq[4];
}Pocket_DeltaQ;

typedef struct
{
    double accX, accY, accZ;
}Pocket_Acceleration;

typedef struct
{
    double freeAccX, freeAccY, freeAccZ;
}Pocket_FreeAcceleration;

typedef struct
{
    double accX, accY, accZ;
}Pocket_AccelerationHR;

typedef struct
{
    double gyrX, gyrY, gyrZ;
}Pocket_RateOFTurn;

typedef struct
{
    double gyrX, gyrY, gyrZ;
}Pocket_RateOFTurnHR;
/*Structures defining possible pockets - end*/

typedef struct 
{
    typedef enum PocketMID_t
    {
        quaternion, freeacc
    } PocketMID;

    union PocketData
    {

    }

    Po


}Pocket_t;



#endif /* AHRS_FRAMES_H_ */