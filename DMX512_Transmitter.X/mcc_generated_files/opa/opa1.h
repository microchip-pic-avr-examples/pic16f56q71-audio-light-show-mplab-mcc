/**
 * OPA1 Generated Driver API Header File
 * 
 * @file opa1.h
 * 
 * @defgroup  opa1 OPA1
 * 
 * @brief This is the generated header file for the OPA1 driver.
 *
 * @version OPA1 Driver Version 1.0.0
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

#ifndef OPA1_H
#define OPA1_H

/**
  Section: Included Files
*/
#include <stdint.h>
#include <stdbool.h>

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_Initialize API
 */
#define OPA1_Initialize OPA1_Initialize

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_EnableChargePump API
 */
#define OPA1_EnableChargePump OPA1_EnableChargePump

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_DisableChargePump API
 */
#define OPA1_DisableChargePump OPA1_DisableChargePump

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_EnableSoftwareUnityGain API
 */
#define OPA1_EnableSoftwareUnityGain OPA1_EnableSoftwareUnityGain

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_DisableSoftwareUnityGain API
 */
#define OPA1_DisableSoftwareUnityGain OPA1_DisableSoftwareUnityGain

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_SetPositiveChannel API
 */
#define OPA1_SetPositiveChannel OPA1_SetPositiveChannel

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_SetPositiveSource API
 */
#define OPA1_SetPositiveSource OPA1_SetPositiveSource

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_SetNegativeChannel API
 */
#define OPA1_SetNegativeChannel OPA1_SetNegativeChannel

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_SetNegativeSource API
 */
#define OPA1_SetNegativeSource OPA1_SetNegativeSource

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_SetResistorLadder API
 */
#define OPA1_SetResistorLadder OPA1_SetResistorLadder

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_EnableHardwareOverride API
 */
#define OPA1_EnableHardwareOverride OPA1_EnableHardwareOverride

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_SetHardwareOverrideSource API
 */
#define OPA1_SetHardwareOverrideSource OPA1_SetHardwareOverrideSource

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_DisableHardwareOverride API
 */
#define OPA1_DisableHardwareOverride OPA1_DisableHardwareOverride

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_ManualInputOffsetCalibration API
 */
#define OPA1_ManualInputOffsetCalibration OPA1_ManualInputOffsetCalibration

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_StartAutomaticOffsetCalibration API
 */
#define OPA1_StartAutomaticOffsetCalibration OPA1_StartAutomaticOffsetCalibration

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_isAutomaticOffsetCalibrationDone API
 */
#define OPA1_isAutomaticOffsetCalibrationDone OPA1_isAutomaticOffsetCalibrationDone

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_StartPeakTroughReset API
 */
#define OPA1_StartPeakTroughReset OPA1_StartPeakTroughReset

/**
 * @ingroup  opa1
 * @brief    This macro defines the Custom Name for \ref OPA1_StopPeakTroughReset API
 */
#define OPA1_StopPeakTroughReset OPA1_StopPeakTroughReset

/**
 * @ingroup opa1
 * @enum OPA1_resistor_select
 * @brief Enumeration of R2/R1 resistor ratio
*/
typedef enum
{
    OPA1_R2byR1_is_0dp07,    /**<R2/R1 = 0.07*/
    OPA1_R2byR1_is_0dp14,    /**<R2/R1 = 0.14*/
    OPA1_R2byR1_is_0dp33,    /**<R2/R1 = 0.33*/
    OPA1_R2byR1_is_1,        /**<R2/R1 = 1*/
    OPA1_R2byR1_is_1dp67,    /**<R2/R1 = 1.67*/
    OPA1_R2byR1_is_3,        /**<R2/R1 = 3*/
    OPA1_R2byR1_is_7,        /**<R2/R1 = 7*/
    OPA1_R2byR1_is_15        /**<R2/R1 = 15*/
} OPA1_resistor_select;

/**
 * @ingroup opa1
 * @enum OPA1_posChannel_select
 * @brief Enumeration of available Positive Channels
*/
typedef enum
{
    OPA1_posChannel_Vss = 0x0,
    OPA1_posChannel_GSEL = 0x1,
    OPA1_posChannel_OPA1IN = 0x2,
    OPA1_posChannel_Vdd_by_2 = 0x3,
    OPA1_posChannel_DAC1 = 0x4,
    OPA1_posChannel_DAC2 = 0x5,
    OPA1_posChannel_DAC3 = 0x6
} OPA1_posChannel_select;

/**
 * @ingroup opa1
 * @enum OPA1_posSource_select
 * @brief Enumeration of available Positive Sources
*/
typedef enum
{
    OPA1_RA2_IN0_pos = 0x0,
    OPA1_RA4_IN1_pos = 0x1,
    OPA1_RA5_IN2_pos = 0x2,
    OPA1_RB1_IN3_pos = 0x3
} OPA1_posSource_select;

/**
 * @ingroup opa1
 * @enum OPA1_negChannel_select
 * @brief Enumeration of available Negative Channels
*/
typedef enum
{
    OPA1_negChannel_No_Connection = 0x0,
    OPA1_negChannel_GSEL = 0x1,
    OPA1_negChannel_OPA1IN = 0x2,
    OPA1_negChannel_DAC1 = 0x4,
    OPA1_negChannel_DAC2 = 0x5,
    OPA1_negChannel_DAC3 = 0x6
} OPA1_negChannel_select;

/**
 * @ingroup opa1
 * @enum OPA1_negSource_select
 * @brief Enumeration of available Negative Sources
*/
typedef enum
{
    OPA1_RA2_IN0_neg = 0x0,   
    OPA1_RA4_IN1_neg = 0x1,   
    OPA1_RA5_IN2_neg = 0x2,   
    OPA1_RB1_IN3_neg = 0x3,   
    OPA1_Vss = 0x7   
} OPA1_negSource_select;

/**
 * @ingroup opa1
 * @brief This routine initializes the OPA1 and must be called before any other OPA1 routine is called.
 * This routine should only be called once during system initialization.
 * @param None
 * @return None
*/
void OPA1_Initialize(void);

/**
 * @ingroup opa1
 * @brief Enables the OPA1 Charge Pump
 * @pre opa1 should be initialized with OPA1_Initialize() before calling this API.
 * @param None
 * @return None
*/
inline void OPA1_EnableChargePump(void);

/**
 * @ingroup opa1
 * @brief Disables the OPA1 Charge Pump
 * @param None
 * @return None
*/
inline void OPA1_DisableChargePump(void);

/**
 * @ingroup opa1
 * @brief Enables OPA1 to operate with unity gain
 * @param None
 * @return None
*/
inline void OPA1_EnableSoftwareUnityGain(void);

/**
 * @ingroup opa1
 * @brief Disables unity gain in OPA1 
 * @param None
 * @return None
*/
inline void OPA1_DisableSoftwareUnityGain(void);

/**
 * @ingroup opa1
 * @brief Sets the positive channel as per user selection
 * @param Desired positive channel. For available positive channels refer OPA1_posChannel_select enum from opa1.h file
 * @return None
*/
inline void OPA1_SetPositiveChannel(OPA1_posChannel_select posChannel);

/**
 * @ingroup opa1
 * @brief Sets the positive source as per user selection
 * @param Desired positive source. For available positive sources refer OPA1_posSource_select enum from opa1.h file
 * @return None
*/
inline void OPA1_SetPositiveSource(OPA1_posSource_select posSource);

/**
 * @ingroup opa1
 * @brief Sets the negative channel as per user selection
 * @param Desired negative channel. For available negative channels refer OPA1_negChannel_select enum from opa1.h file
 * @return None
*/
inline void OPA1_SetNegativeChannel(OPA1_negChannel_select negChannel);

/**
 * @ingroup opa1
 * @brief Sets the negative source as per user selection
 * @param Desired negative source. For available negative sources refer OPA1_negSource_select enum from opa1.h file
 * @return None
*/
inline void OPA1_SetNegativeSource(OPA1_negSource_select negSource);

/**
 * @ingroup opa1
 * @brief Sets the R1 and R2 values of internal resistor ladder as per user selection
 * @param Desired resistor selection. For available resistor values refer OPA1_resistor_sel enum from opa1.h file
 * @return None
*/
void OPA1_SetResistorLadder(OPA1_resistor_select resistorSelection);

/**
 * @ingroup opa1
 * @brief Enables hardware override by setting the override enable bit
 * @param None
 * @return None
*/
inline void OPA1_EnableHardwareOverride(void);

/**
 * @ingroup opa1
 * @brief Selects the Hardware Override Source and polarity
 * @pre The OPA1_EnableHardwareOverride() routine must be called before this routine
 * @param Desired hardware override source and source polarity
 * @return None
*/
void OPA1_SetHardwareOverrideSource(uint8_t overrideSource, uint8_t polarity);

/**
 * @ingroup opa1
 * @brief Disables the hardware override by clearing the override enable bit
 * @param None
 * @return None
*/
inline void OPA1_DisableHardwareOverride(void);

/**
 * @ingroup opa1
 * @brief Sets the input offset calibration
 * @param Desired input offset based on calibration
 * @return None
*/
inline void OPA1_ManualInputOffsetCalibration(uint8_t offset);

/**
 * @ingroup opa1
 * @brief Starts the automatic input offset calibration
 * @param None
 * @return None
*/
void OPA1_StartAutomaticOffsetCalibration(void);

/**
 * @ingroup opa1
 * @brief Checks if the automatic input offset calibration has been completed
 * @pre The OPA1_StartAutomaticOffsetCalibration() routine must be called before this routine
 * @param None
 * @return true or false
*/
inline bool OPA1_isAutomaticOffsetCalibrationDone(void);

/**
 * @ingroup opa1
 * @brief Initiate peak or trough reset
 * @pre The hardware control configuration registers must be set appropriately
 * @param None
 * @return None
*/
inline void OPA1_StartPeakTroughReset(void);

/**
 * @ingroup opa1
 * @brief Stop peak or trough reset
 * @pre The hardware control configuration registers must be set appropriately
 * @param None
 * @return None
*/
inline void OPA1_StopPeakTroughReset(void);

#endif //OPA1_H