/**
  MSSP2 Generated Driver API Header File
  
  @Company
    Microchip Technology Inc.

  @File Name
    spi2.h
	
  @Summary
    This is the generated header file for the MSSP2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for SPI2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18426
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef _SPI2_H
#define _SPI2_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Macro Declarations
*/

#define SPI2_DUMMY_DATA 0x0

/**
  Section: SPI2 Module APIs
*/

/**
  @Summary
    Initializes the SPI2

  @Description
    This routine initializes the SPI2.
    This routine must be called before any other MSSP2 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    uint8_t     myWriteBuffer[MY_BUFFER_SIZE];
    uint8_t     myReadBuffer[MY_BUFFER_SIZE];
    uint8_t     writeData;
    uint8_t     readData;
    uint8_t     total;

    SPI2_Initialize();

    total = 0;
    do
    {
        total = SPI2_Exchange8bitBuffer(&myWriteBuffer[total], MY_BUFFER_SIZE - total, &myWriteBuffer[total]);

        // Do something else...

    } while(total < MY_BUFFER_SIZE);

    readData = SPI2_Exchange8bit(writeData);
    </code>
 */
void SPI2_Initialize(void);
void chipDisable();
void chipEnable();

/**
  @Summary
    Exchanges a data byte over SPI2

  @Description
    This routine exchanges a data byte over SPI2 bus.
    This is a blocking routine.

  @Preconditions
    The SPI2_Initialize() routine should be called
    prior to use this routine.

  @Param
    data - data byte to be transmitted over SPI2 bus

  @Returns
    The received byte over SPI2 bus

  @Example
    <code>
    uint8_t     writeData;
    uint8_t     readData;
    uint8_t     readDummy;

    SPI2_Initialize();

    // for transmission over SPI bus
    readDummy = SPI2_Exchange8bit(writeData);

    // for reception over SPI bus
    readData = SPI2_Exchange8bit(SPI2_DUMMY_DATA);
    </code>
 */
uint8_t SPI2_Exchange8bit(uint8_t data);

 /**
  @Summary
    Exchanges buffer of data over SPI2

  @Description
    This routine exchanges buffer of data (of size one byte) over SPI2 bus.
    This is a blocking routine.

  @Preconditions
    The SPI2_Initialize() routine should be called
    prior to use this routine.

  @Param
    dataIn  - Buffer of data to be transmitted over SPI2.
    bufLen  - Number of bytes to be exchanged.
    dataOut - Buffer of data to be received over SPI2.

  @Returns
    Number of bytes exchanged over SPI2.

  @Example
    <code>
    uint8_t     myWriteBuffer[MY_BUFFER_SIZE];
    uint8_t     myReadBuffer[MY_BUFFER_SIZE];
    uint8_t     total;

    SPI2_Initialize();

    total = 0;
    do
    {
        total = SPI2_Exchange8bitBuffer(&myWriteBuffer[total], MY_BUFFER_SIZE - total, &myWriteBuffer[total]);

        // Do something else...

    } while(total < MY_BUFFER_SIZE);
    </code>
 */
uint8_t SPI2_Exchange8bitBuffer(uint8_t *dataIn, uint8_t bufLen, uint8_t *dataOut);

/**
  @Summary
    Gets the SPI2 buffer full status

  @Description
    This routine gets the SPI2 buffer full status

  @Preconditions
    The SPI2_Initialize() routine should be called
    prior to use this routine.

  @Param
    None

  @Returns
    true  - if the buffer is full
    false - if the buffer is not full.

  @Example
    Refer to SPI2_Initialize() for an example
 */
bool SPI2_IsBufferFull(void);

/**
  @Summary
    Gets the status of write collision.

  @Description
    This routine gets the status of write collision.

  @Preconditions
    The SPI2_Initialize() routine must have been called prior to use this routine.

  @Param
    None

  @Returns
    true  - if the write collision has occurred.
    false - if the write collision has not occurred.

  @Example
    if(SPI2_HasWriteCollisionOccured())
    {
        SPI2_ClearWriteCollisionStatus();
    }
*/
bool SPI2_HasWriteCollisionOccured(void);

/**
  @Summary
    Clears the status of write collision.

  @Description
    This routine clears the status of write collision.

  @Preconditions
    The SPI2_Initialize() routine must have been called prior to use this routine.

  @Param
    None

  @Returns
    None

  @Example
    if(SPI2_HasWriteCollisionOccured())
    {
        SPI2_ClearWriteCollisionStatus();
    }
*/
void SPI2_ClearWriteCollisionStatus(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _SPI2_H
/**
 End of File
*/
