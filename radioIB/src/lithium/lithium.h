/*
 * lithium.h
 *
 * Created: 4/18/2014 2:11:27 AM
 *  Author: akd54_admin
 */ 

#include <asf.h>
#include "../vcp/common.h"
#include "../tasks/tasks.h"
#include "config/conf_usart_serial.h"
#include "../vcp/vcp_library.h"


#ifndef LITHIUM_H_
#define LITHIUM_H_

#define LI_HDR 8
#define AX_HDR 14
#define LI_FTR 2
#define AX_FTR 2

#define HE 0x48
#define LO 0x65
#define TRANSMIT 0x20
#define TELEMETRY 0x07

#define FC_MSG 0x08
#define FC_CMD 0x18

#define PWB_MSG 0x28
#define PWB_CMD 0x38

#define CDH_MSG 0x48
#define CDH_CMD 0x58

#define HE_ERR 0x01
#define LO_ERR 0x02
#define SIZE_ERR 0x03
#define CHKSUM_ERR 0x04
#define VCP_CREAT_ERR 0x05

void calculate_header_chksum			(uint8ptr hdr); 


#endif /* LITHIUM_H_ */