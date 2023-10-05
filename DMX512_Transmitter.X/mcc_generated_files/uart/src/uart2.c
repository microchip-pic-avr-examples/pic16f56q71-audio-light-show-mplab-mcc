/**
 * UART2 Generated Driver API Header File
 * 
 * @file uart2.c
 * 
 * @ingroup uart2
 * 
 * @brief This is the generated driver implementation file for the UART2 driver using CCL
 *
 * @version UART2 Driver Version 3.0.4
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

/**
  Section: Included Files
*/
#include "../uart2.h"

/**
  Section: Macro Declarations
*/

/**
  Section: Driver Interface
 */

const uart_drv_interface_t UART2 = {
    .Initialize = &UART2_Initialize,
    .Deinitialize = &UART2_Deinitialize,
    .Read = &UART2_Read,
    .Write = &UART2_Write,
    .IsRxReady = &UART2_IsRxReady,
    .IsTxReady = &UART2_IsTxReady,
    .IsTxDone = &UART2_IsTxDone,
    .TransmitEnable = &UART2_TransmitEnable,
    .TransmitDisable = &UART2_TransmitDisable,
    .AutoBaudSet = &UART2_AutoBaudSet,
    .AutoBaudQuery = &UART2_AutoBaudQuery,
    .BRGCountSet = NULL,
    .BRGCountGet = NULL,
    .BaudRateSet = NULL,
    .BaudRateGet = NULL,
    .AutoBaudEventEnableGet = NULL,
    .ErrorGet = &UART2_ErrorGet,
    .TxCompleteCallbackRegister = NULL,
    .RxCompleteCallbackRegister = NULL,
    .TxCollisionCallbackRegister = NULL,
    .FramingErrorCallbackRegister = &UART2_FramingErrorCallbackRegister,
    .OverrunErrorCallbackRegister = &UART2_OverrunErrorCallbackRegister,
    .ParityErrorCallbackRegister = &UART2_ParityErrorCallbackRegister,
    .EventCallbackRegister = NULL,
};

/**
  Section: UART2 variables
*/
volatile uart2_status_t uart2RxLastError;

/**
  Section: UART2 APIs
*/

void (*UART2_FramingErrorHandler)(void);
void (*UART2_OverrunErrorHandler)(void);
void (*UART2_ParityErrorHandler)(void);

static void UART2_DefaultFramingErrorCallback(void);
static void UART2_DefaultOverrunErrorCallback(void);
static void UART2_DefaultParityErrorCallback(void);

/**
  Section: UART2  APIs
*/

void UART2_Initialize(void)
{

    // Set the UART2 module to the options selected in the user interface.

    //
    U2RXB = 0x0; 
    //TXB disabled; 
    U2TXB = 0x0; 
    //P1L 0x0; 
    U2P1L = 0x0; 
    //P2L 0x0; 
    U2P2L = 0x0; 
    //P3L 0x0; 
    U2P3L = 0x0; 
    //MODE Asynchronous 8-bit mode; RXEN enabled; TXEN enabled; ABDEN disabled; BRGS high speed; 
    U2CON0 = 0xB0; 
    //SENDB disabled; BRKOVR disabled; RXBIMD Set RXBKIF on rising RX input; WUE disabled; ON enabled; 
    U2CON1 = 0x80; 
    //FLO off; TXPOL not inverted; STP Transmit 1Stop bit, receiver verifies first Stop bit; RXPOL not inverted; RUNOVF RX input shifter stops all activity; 
    U2CON2 = 0x0; 
    //BRGL 130; 
    U2BRGL = 0x82; 
    //BRGH 6; 
    U2BRGH = 0x6; 
    //TXBE empty; STPMD in middle of first Stop bit; TXWRE No error; 
    U2FIFO = 0x20; 
    //ABDIE disabled; ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; 
    U2UIR = 0x0; 
    //TXCIF equal; RXFOIF not overflowed; RXBKIF No Break detected; FERIF no error; CERIF No Checksum error; ABDOVF Not overflowed; PERIF Byte not at top; TXMTIF empty; 
    U2ERRIR = 0x80; 
    //TXCIE disabled; RXFOIE disabled; RXBKIE disabled; FERIE disabled; CERIE disabled; ABDOVE disabled; PERIE disabled; TXMTIE disabled; 
    U2ERRIE = 0x0; 

    UART2_FramingErrorCallbackRegister(UART2_DefaultFramingErrorCallback);
    UART2_OverrunErrorCallbackRegister(UART2_DefaultOverrunErrorCallback);
    UART2_ParityErrorCallbackRegister(UART2_DefaultParityErrorCallback);

    uart2RxLastError.status = 0;  
}

void UART2_Deinitialize(void)
{
    U2RXB = 0x00;
    U2TXB = 0x00;
    U2P1L = 0x00;
    U2P2L = 0x00;
    U2P3L = 0x00;
    U2CON0 = 0x00;
    U2CON1 = 0x00;
    U2CON2 = 0x00;
    U2BRGL = 0x00;
    U2BRGH = 0x00;
    U2FIFO = 0x00;
    U2UIR = 0x00;
    U2ERRIR = 0x00;
    U2ERRIE = 0x00;
}

inline void UART2_Enable(void)
{
    U2CON1bits.ON = 1; 
}

inline void UART2_Disable(void)
{
    U2CON1bits.ON = 0; 
}

inline void UART2_TransmitEnable(void)
{
    U2CON0bits.TXEN = 1;
}

inline void UART2_TransmitDisable(void)
{
    U2CON0bits.TXEN = 0;
}

inline void UART2_ReceiveEnable(void)
{
    U2CON0bits.RXEN = 1;
}

inline void UART2_ReceiveDisable(void)
{
    U2CON0bits.RXEN = 0;
}

inline void UART2_SendBreakControlEnable(void)
{
    U2CON1bits.SENDB = 1;
}

inline void UART2_SendBreakControlDisable(void)
{
    U2CON1bits.SENDB = 0;
}

inline void UART2_AutoBaudSet(bool enable)
{
    if(enable)
    {
        U2CON0bits.ABDEN = 1; 
    }
    else
    {
      U2CON0bits.ABDEN = 0;  
    }
}


inline bool UART2_AutoBaudQuery(void)
{
    return (bool)U2UIRbits.ABDIF; 
}

inline void UART2_AutoBaudDetectCompleteReset(void)
{
    U2UIRbits.ABDIF = 0; 
}

inline bool UART2_IsAutoBaudDetectOverflow(void)
{
    return (bool)U2ERRIRbits.ABDOVF; 
}

inline void UART2_AutoBaudDetectOverflowReset(void)
{
    U2ERRIRbits.ABDOVF = 0; 
}

bool UART2_IsRxReady(void)
{
    return (bool)(!U2FIFObits.RXBE);
}

bool UART2_IsTxReady(void)
{
    return (bool)(U2FIFObits.TXBE && U2CON0bits.TXEN);
}

bool UART2_IsTxDone(void)
{
    return U2ERRIRbits.TXMTIF;
}

size_t UART2_ErrorGet(void)
{
    uart2RxLastError.status = 0;
    
    if(U2ERRIRbits.FERIF)
    {
        uart2RxLastError.ferr = 1;
        if(NULL != UART2_FramingErrorHandler)
        {
            UART2_FramingErrorHandler();
        }  
    }
    if(U2ERRIRbits.RXFOIF)
    {
        uart2RxLastError.oerr = 1;
        if(NULL != UART2_OverrunErrorHandler)
        {
            UART2_OverrunErrorHandler();
        }   
    }

    return uart2RxLastError.status;
}

uint8_t UART2_Read(void)
{
    return U2RXB;
}


void UART2_Write(uint8_t txData)
{
    U2TXB = txData; 
}


int getch(void)
{
    while(!(UART2_IsRxReady()));
    return UART2_Read();
}

void putch(char txData)
{
    while(!(UART2_IsTxReady()));
    return UART2_Write(txData);   
}





static void UART2_DefaultFramingErrorCallback(void)
{
    
}

static void UART2_DefaultOverrunErrorCallback(void)
{
    
}

static void UART2_DefaultParityErrorCallback(void)
{
    
}

void UART2_FramingErrorCallbackRegister(void (* callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
        UART2_FramingErrorHandler = callbackHandler;
    }
}

void UART2_OverrunErrorCallbackRegister(void (* callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
        UART2_OverrunErrorHandler = callbackHandler;
    }    
}

void UART2_ParityErrorCallbackRegister(void (* callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
        UART2_ParityErrorHandler = callbackHandler;
    } 
}
