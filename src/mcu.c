#include "mcu.h"
#include "eusart.h"
#include "interrupt.h"
#include "spi.h"

void SYSTEM_Initialize(){
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    SPI2_Initialize();
    EUSART_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
}

void OSCILLATOR_Initialize()
{
    // NOSC EXTOSC; NDIV 1; 
    OSCCON1 = 0x60;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 32_MHz; 
    OSCFRQ = 0x06;
    // HFTUN 0; 
    OSCTUNE = 0x00;
}

void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x3F;
    TRISC = 0x3B;

    /**
    ANSELx registers
    */
    ANSELC = 0x0F;
    ANSELA = 0x37;

    /**
    WPUx registers
    */
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONC = 0x3F;

    /**
    INLVLx registers
    */
    INLVLA = 0x3F;
    INLVLC = 0x3F;
    
	SSP2DATPPS = 0x00;   //RA0->MSSP2:SDI2;    
    RA1PPS = 0x16;   //RA1->MSSP2:SDO2;    
    RA2PPS = 0x15;   //RA2->MSSP2:SCK2;    
    SSP2CLKPPS = 0x02;   //RA2->MSSP2:SCK2;       
    RC2PPS = 0x0F;   //RC2->EUSART1:TX1;     
}