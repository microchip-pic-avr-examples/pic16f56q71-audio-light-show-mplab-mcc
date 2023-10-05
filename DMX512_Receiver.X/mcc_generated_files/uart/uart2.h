/**
 * UART2 Generated Driver API Header File
 * 
 * @file uart2.h
 * 
 * @defgroup uart2 UART2
 * 
 * @brief This file contains API prototypes and other datatypes for UART2 module.
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

#ifndef UART2_H
#define UART2_H

/**
  Section: Included Files
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "../system/system.h"
#include "uart_drv_interface.h"

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

#define UART2_interface UART2


#define UART2_Initialize     UART2_Initialize
#define UART2_Deinitialize   UART2_Deinitialize
#define UART2_Write          UART2_Write
#define UART2_Read           UART2_Read
#define UART2__IsRxReady     UART2_IsRxReady
#define UART2_IsTxReady      UART2_IsTxReady
#define UART2_IsTxDone       UART2_IsTxDone

#define UART2_TransmitEnable       UART2_TransmitEnable
#define UART2_TransmitDisable      UART2_TransmitDisable
#define UART2_AutoBaudSet          UART2_AutoBaudSet
#define UART2_AutoBaudQuery        UART2_AutoBaudQuery
#define UART2_BRGCountSet               (NULL)
#define UART2_BRGCountGet               (NULL)
#define UART2_BaudRateSet               (NULL)
#define UART2_BaudRateGet               (NULL)
#define UART2__AutoBaudEventEnableGet   (NULL)
#define UART2_ErrorGet             UART2_ErrorGet

#define UART2_TxCompleteCallbackRegister     (NULL)
#define UART2_RxCompleteCallbackRegister      (NULL)
#define UART2_TxCollisionCallbackRegister  (NULL)
#define UART2_FramingErrorCallbackRegister UART2_FramingErrorCallbackRegister
#define UART2_OverrunErrorCallbackRegister UART2_OverrunErrorCallbackRegister
#define UART2_ParityErrorCallbackRegister  UART2_ParityErrorCallbackRegister
#define UART2_EventCallbackRegister        (NULL)

/**
 @ingroup uart2
 @struct uart2_status_t
 @breif This is an instance of UART2_STATUS for UART2 module
 */
typedef union {
    struct {
        uint8_t perr : 1;     /**<This is a bit field for Parity Error status*/
        uint8_t ferr : 1;     /**<This is a bit field for Framing Error status*/
        uint8_t oerr : 1;     /**<This is a bit field for Overfrun Error status*/
        uint8_t reserved : 5; /**<Reserved*/
    };
    size_t status;            /**<Group byte for status errors*/
}uart2_status_t;

/**
 Section: Data Type Definitions
 */

/**
 * @ingroup uart2
 * @brief External object for uart_drv_interface.
 */
extern const uart_drv_interface_t UART2;

/**
 * @ingroup uart2
 * @brief This API initializes the UART2 driver.
 *        This routine initializes the UART2 module.
 *        This routine must be called before any other UART2 routine is called.
 *        This routine should only be called once during system initialization.
 * @param None.
 * @return None.
 */
void UART2_Initialize(void);

/**
 * @ingroup uart2
 * @brief This API Deinitializes the UART2 driver.
 *        This routine disables the UART2 module.
 * @param None.
 * @return None.
 */
void UART2_Deinitialize(void);

/**
 * @ingroup uart2
 * @brief This API enables the UART2 module.     
 * @param None.
 * @return None.
 */
inline void UART2_Enable(void);

/**
 * @ingroup uart2
 * @brief This API disables the UART2 module.
 * @param None.
 * @return None.
 */
inline void UART2_Disable(void);

/**
 * @ingroup uart2
 * @brief This API enables the UART2 transmitter.
 *        UART2 should also be enable to send bytes over TX pin.
 * @param None.
 * @return None.
 */
inline void UART2_TransmitEnable(void);

/**
 * @ingroup uart2
 * @brief This API disables the UART2 transmitter.
 * @param None.
 * @return None.
 */
inline void UART2_TransmitDisable(void);

/**
 * @ingroup uart2
 * @brief This API enables the UART2 Receiver.
 *        UART2 should also be enable to receive bytes over RX pin.
 * @param None.
 * @return None.
 */
inline void UART2_ReceiveEnable(void);

/**
 * @ingroup uart2
 * @brief This API disables the UART2 Receiver.
 * @param None.
 * @return None.
 */
inline void UART2_ReceiveDisable(void);

/**
 * @ingroup uart2
 * @brief This API enables the UART2 send break control.
 * @param None.
 * @return None.
 */
inline void UART2_SendBreakControlEnable(void);

/**
 * @ingroup uart2
 * @brief This API disables the UART2 send break control.
 * @param None.
 * @return None.
 */
inline void UART2_SendBreakControlDisable(void);

/**
 * @ingroup uart2
 * @brief This API enables the UART2 AutoBaud Detection.
 * @param bool enable.
 * @return None.
 */
inline void UART2_AutoBaudSet(bool enable);


/**
 * @ingroup uart2
 * @brief This API reads the UART2 AutoBaud Detection Complete bit.
 * @param None.
 * @return None.
 */
inline bool UART2_AutoBaudQuery(void);

/**
 * @ingroup uart2
 * @brief This API Reset the UART2 AutoBaud Detection Complete bit.
 * @param None.
 * @return None.
 */
inline void UART2_AutoBaudDetectCompleteReset(void);

/**
 * @ingroup uart2
 * @brief This API reads the UART2 AutoBaud Detection overflow bit.
 * @param None.
 * @return None.
 */
inline bool UART2_IsAutoBaudDetectOverflow(void);

/**
 * @ingroup uart2
 * @brief This API Reset the UART2 AutoBaud Detection Overflow bit.
 * @param None.
 * @return None.
 */
inline void UART2_AutoBaudDetectOverflowReset(void);

/**
 * @ingroup uart2
 * @brief This API checks if UART2 receiver has received data and ready to be read.
 * @param None.
 * @retval true if UART2 receiver FIFO has a data
 * @retval false UART2 receiver FIFO is empty
 */
bool UART2_IsRxReady(void);

/**
 * @ingroup uart2
 * @brief This function checks if UART2 transmitter is ready to accept a data byte.
 * @param None.
 * @retval true if UART2 transmitter FIFO has atleast 1 byte space
 * @retval false if UART2 transmitter FIFO is full
 */
bool UART2_IsTxReady(void);

/**
 * @ingroup uart2
 * @brief This function return the status of transmit shift register (TSR).
 * @param None.
 * @retval true if Data completely shifted out from the TSR
 * @retval false if Data is present in Transmit FIFO and/or in TSR
 */
bool UART2_IsTxDone(void);

/**
 * @ingroup uart2
 * @brief This function gets the error status of the last read byte.
 *        This function should be called before UART2_Read().
 * @pre RX should be enable by calling UART2_RxEnable() before calling this API.
 * @param None.
 * @return Status of the last read byte. See uart2_status_t struct for more details.
 */
size_t UART2_ErrorGet(void);

/**
 * @ingroup uart2
 * @brief This function reads the 8 bits from receiver FIFO register.
 * @pre The transfer status should be checked to see if the receiver is not empty
 *      before calling this function. UART2_IsRxReady() should be checked in if () before calling this API.
 * @param None.
 * @return 8-bit data from RX FIFO register.
 */
uint8_t UART2_Read(void);

/**
 * @ingroup uart2
 * @brief This function writes a byte of data to the transmitter FIFO register.
 * @pre The transfer status should be checked to see if the transmitter is ready to accept a byte
 *      before calling this function. UART2_IsTxReady() should be checked in if() before calling this API.
 * @param txData  - Data byte to write to the TX FIFO.
 * @return None.
 */
void UART2_Write(uint8_t txData);

/**
 * @ingroup uart2
 * @brief This API registers the function to be called upon UART2 framing error.
 * @param callbackHandler - a function pointer which will be called upon framing error condition.
 * @return None.
 */
void UART2_FramingErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief This API registers the function to be called upon UART2 overrun error.
 * @param callbackHandler - a function pointer which will be called upon overrun error condition.
 * @return None.
 */
void UART2_OverrunErrorCallbackRegister(void (* callbackHandler)(void));

/**
 * @ingroup uart2
 * @brief This API registers the function to be called upon UART2 Parity error.
 * @param callbackHandler - a function pointer which will be called upon Parity error condition.
 * @return None.
 */
void UART2_ParityErrorCallbackRegister(void (* callbackHandler)(void));

#ifdef __cplusplus  // Provide C++ Compatibility


    }

#endif

#endif  // UART2_H
