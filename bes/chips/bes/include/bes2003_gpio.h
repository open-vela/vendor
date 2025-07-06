/************************************************************************************
 * arch/arm/src/bes/bes2001_gpio.h
 * General Purpose Input/Output (GPIO) definitions for the BES2001
 *
 *   Copyright (C) 2009-2011, 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_BES_BES2001_GPIO_H
#define __ARCH_ARM_SRC_BES_BES2001_GPIO_H

/************************************************************************************
 * Included Files
 ************************************************************************************/
#include <nuttx/config.h>
/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
/* Configuration ********************************************************************/

#undef GPIO_HAVE_PULLDOWN
#undef GPIO_HAVE_PERIPHCD
#undef GPIO_HAVE_SCHMITT
#undef GPIO_HAVE_DELAYR

/* Bit-encoded input to bes_configgpio() ********************************************/

/* 32-bit Encoding:
 *
 *   DAA MMCC CIII VPPB BBBB
 */

/* VOLTAGE_DOMAINS
*  
*/
#define GPIO_VOLD_SHIFT                25                         /* Bits 25-26: Alternate function */
#define GPIO_VOLD_MASK                 (3 << GPIO_VOLD_SHIFT)
#  define GPIO_VOLD(n)                 ((n) << GPIO_VOLD_SHIFT)
#  define GPIO_PIN_VOLTAGE_VIO         (0  << GPIO_VOLD_SHIFT) 
#  define GPIO_PIN_VOLTAGE_MEM         (1  << GPIO_VOLD_SHIFT)
#  define GPIO_PIN_VOLTAGE_VBAT        (2  << GPIO_VOLD_SHIFT)

/* supports up to 128 alternate functions per pin:
 *
 *    .... .... .... AAAA .... .... .... ....
 */

#define GPIO_ALT_SHIFT                16                         /* Bits 16-24: Alternate function */
#define GPIO_ALT_MASK                 (255 << GPIO_ALT_SHIFT)
#  define GPIO_ALT(n)                 ((n) << GPIO_ALT_SHIFT)
#  define GPIO_ALT_NONE               (0  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_GPIO               (1  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_AS_GPIO            (1  << GPIO_ALT_SHIFT) 
#  define GPIO_ALT_BT_UART_CTS        (2  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_BT_UART_RTS        (3  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_BT_UART_RX         (4  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_BT_UART_TX         (5  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_CLK_32K_IN         (6  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_CLK_REQ_IN         (7  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_CLK_REQ_OUT        (8  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_CLK_OUT            (9  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2C_M0_SCL         (10  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2C_M0_SDA         (11  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2C_M1_SCL         (12  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2C_M2_SCL         (13  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2C_M2_SDA         (14  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2C_M1_SDA         (15  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_MCLK          (16  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SCK           (17  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDI0          (18  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDI1          (19  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDI2          (20  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDI3          (21  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDO0          (22  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDO1          (23  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDO2          (24  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_SDO3          (25  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S0_WS            (26  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SCK           (27  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDI0          (28  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDI1          (29  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDI2          (30  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDI3          (31  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDO0          (32  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDO1          (33  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDO2          (34  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_SDO3          (35  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_I2S1_WS            (36  << GPIO_ALT_SHIFT)

#  define GPIO_ALT_PCM_CLK            (37  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PCM_DI             (38  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PCM_DO             (39  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PCM_FSYNC          (40  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PDM0_CK            (41  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PDM0_D             (42  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PDM1_CK            (43  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PDM1_D             (44  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PDM2_CK            (45  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PDM2_D             (46  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM0               (47  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM1               (48  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM2               (49  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM3               (50  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM4               (51  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM5               (52  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM6               (53  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_PWM7               (54  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_CLK          (55  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_CMD          (56  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA0        (57  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA1        (58  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA2        (59  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA3        (60  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA4        (61  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA5        (62  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA6        (63  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SDMMC_DATA7        (64  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPDIF0_DI          (65  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPDIF0_DO          (66  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_CLK            (67  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_CS0            (68  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_CS1            (69  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_CS2            (70  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_CS3            (71  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_DCN            (72  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_DI0            (73  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_DI1            (74  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_DI2            (75  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_DI3            (76  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPI_DIO            (77  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_CLK         (78  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_CS0         (79  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_CS1         (80  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_CS2         (81  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_CS3         (82  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_DCN         (83  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_DI0         (84  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_DI1         (85  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_DI2         (86  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_DI3         (87  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_SPILCD_DIO         (88  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART0_RX           (89  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART0_TX           (90  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART1_CTS          (91  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART1_RTS          (92  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART1_RX           (93  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART1_TX           (94  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART2_RX           (95  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART2_TX           (96  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART2_CTS          (97  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART2_RTS          (98  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART3_RX           (99  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART3_TX           (100  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART3_CTS          (101  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_UART3_RTS          (102  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_UART_CTS        (103  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_UART_RTS        (104  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_UART_RX         (105  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_UART_TX         (106  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL0       (107  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL2       (108  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL3       (109  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL4       (110  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL5       (111  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL6       (112  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL7       (113  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL8       (114  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_FEM_CNTL9       (115  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_SDIO_CLK        (116  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_SDIO_DATA0      (117  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_SDIO_CMD        (118  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_SDIO_DATA1      (119  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_SDIO_DATA2      (120  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_SDIO_DATA3      (121  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_WAKE_HOST       (122  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_WF_TXON            (123  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_TE         (124  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_BL_PWM     (125  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_BL_EN      (126  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_CLK    (127  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_CS     (128  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_DIO    (129  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_DO1_DCN (130  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_DO2    (131  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_DO3    (132  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_DISPLAY_SPI_DI     (133  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_IR_RX              (134  << GPIO_ALT_SHIFT)
#  define GPIO_ALT_IR_TX              (135  << GPIO_ALT_SHIFT)

/* Input/Output mode:
 *
 *   MM.. .... .... ....
 */

#define GPIO_MODE_SHIFT            (14)        /* Bits 14-15: GPIO mode */
#define GPIO_MODE_MASK             (3 << GPIO_MODE_SHIFT)
#  define GPIO_INPUT               (0 << GPIO_MODE_SHIFT) /* Input */
#  define GPIO_OUTPUT              (1 << GPIO_MODE_SHIFT) /* Output */
#  define GPIO_PERIPHA             (2 << GPIO_MODE_SHIFT) /* Controlled by periph A signal */
#  define GPIO_PERIPHB             (3 << GPIO_MODE_SHIFT) /* Controlled by periph B signal */

/* These bits set the configuration of the pin:
 *
 *   ..CC C... .... ....
 */

#define GPIO_CFG_SHIFT             (11)        /* Bits 11-13: GPIO configuration bits */
#define GPIO_CFG_MASK              (7 << GPIO_CFG_SHIFT)

#  define GPIO_CFG_NOPULL          (0 << GPIO_CFG_SHIFT) /* Default, no pull */
#  define GPIO_CFG_PULLUP          (1 << GPIO_CFG_SHIFT) /* Bit 11: Internal pull-up */
#  define GPIO_CFG_PULLDOWN        (2 << GPIO_CFG_SHIFT) /* Bit 12: Internal pull-down */

/* Additional interrupt modes:
 *
 *   .... .III .... ....
 */

#define GPIO_INT_SHIFT             (8)         /* Bits 8-10: GPIO interrupt bits */
#define GPIO_INT_MASK              (7 << GPIO_INT_SHIFT)
#  define _GIO_INT_AIM             (1 << 10)   /* Bit 10: Additional Interrupt modes */
#  define _GPIO_INT_LEVEL          (1 << 9)    /* Bit 9: Level detection interrupt */
#  define _GPIO_INT_EDGE           (0)         /*        (vs. Edge detection interrupt) */
#  define _GPIO_INT_RH             (1 << 8)    /* Bit 9: Rising edge/High level detection interrupt */
#  define _GPIO_INT_FL             (0)         /*        (vs. Falling edge/Low level detection interrupt) */

#  define GPIO_INT_HIGHLEVEL       (_GIO_INT_AIM | _GPIO_INT_LEVEL | _GPIO_INT_RH)
#  define GPIO_INT_LOWLEVEL        (_GIO_INT_AIM | _GPIO_INT_LEVEL | _GPIO_INT_FL)
#  define GPIO_INT_RISING          (_GIO_INT_AIM | _GPIO_INT_EDGE  | _GPIO_INT_RH)
#  define GPIO_INT_FALLING         (_GIO_INT_AIM | _GPIO_INT_EDGE  | _GPIO_INT_FL)
#  define GPIO_INT_BOTHEDGES       (0)

/* If the pin is an GPIO output, then this identifies the initial output value:
 *
 *   .... .... V... ....
 */

#define GPIO_OUTPUT_SET            (1 << 7)    /* Bit 7: Initial value of output */
#define GPIO_OUTPUT_CLEAR          (0)

/* This identifies the GPIO port:
 *
 *   .... .... .PP. ....
 */

#define GPIO_PORT_SHIFT            (5)         /* Bit 5-6:  Port number */
#define GPIO_PORT_MASK             (3 << GPIO_PORT_SHIFT)
#  define GPIO_PORT_GPIO0           (0 << GPIO_PORT_SHIFT)
#  define GPIO_PORT_GPIO1           (1 << GPIO_PORT_SHIFT)

/* This identifies the bit in the port:
 *
 *   .... .... ...B BBBB
 */
// port 0   Gpio[31:0] 
#define GPIO_PIN_SHIFT             0           /* Bits 0-4: GPIO number: 0-31  with interrupt*/
#define GPIO_PIN_MASK              (31 << GPIO_PIN_SHIFT)
#define GPIO_PIN0                  (0  << GPIO_PIN_SHIFT)
#define GPIO_PIN1                  (1  << GPIO_PIN_SHIFT)
#define GPIO_PIN2                  (2  << GPIO_PIN_SHIFT)
#define GPIO_PIN3                  (3  << GPIO_PIN_SHIFT)
#define GPIO_PIN4                  (4  << GPIO_PIN_SHIFT)
#define GPIO_PIN5                  (5  << GPIO_PIN_SHIFT)
#define GPIO_PIN6                  (6  << GPIO_PIN_SHIFT)
#define GPIO_PIN7                  (7  << GPIO_PIN_SHIFT)
#define GPIO_PIN8                  (8  << GPIO_PIN_SHIFT)
#define GPIO_PIN9                  (9  << GPIO_PIN_SHIFT)
#define GPIO_PIN10                 (10 << GPIO_PIN_SHIFT)
#define GPIO_PIN11                 (11 << GPIO_PIN_SHIFT)
#define GPIO_PIN12                 (12 << GPIO_PIN_SHIFT)
#define GPIO_PIN13                 (13 << GPIO_PIN_SHIFT)
#define GPIO_PIN14                 (14 << GPIO_PIN_SHIFT)
#define GPIO_PIN15                 (15 << GPIO_PIN_SHIFT)
#define GPIO_PIN16                 (16 << GPIO_PIN_SHIFT)
#define GPIO_PIN17                 (17 << GPIO_PIN_SHIFT)
#define GPIO_PIN18                 (18 << GPIO_PIN_SHIFT)
#define GPIO_PIN19                 (19 << GPIO_PIN_SHIFT)
#define GPIO_PIN20                 (20 << GPIO_PIN_SHIFT)
#define GPIO_PIN21                 (21 << GPIO_PIN_SHIFT)
#define GPIO_PIN22                 (22 << GPIO_PIN_SHIFT)
#define GPIO_PIN23                 (23 << GPIO_PIN_SHIFT)
#define GPIO_PIN24                 (24 << GPIO_PIN_SHIFT)
#define GPIO_PIN25                 (25 << GPIO_PIN_SHIFT)
#define GPIO_PIN26                 (26 << GPIO_PIN_SHIFT)
#define GPIO_PIN27                 (27 << GPIO_PIN_SHIFT)
#define GPIO_PIN28                 (28 << GPIO_PIN_SHIFT)
#define GPIO_PIN29                 (29 << GPIO_PIN_SHIFT)
#define GPIO_PIN30                 (30 << GPIO_PIN_SHIFT)
#define GPIO_PIN31                 (31 << GPIO_PIN_SHIFT)

//port 1 Gpio[39:32]   /*no interrupt*/
#define GPIO_PIN32                  (32  << GPIO_PIN_SHIFT)
#define GPIO_PIN33                  (33  << GPIO_PIN_SHIFT)
#define GPIO_PIN34                  (34  << GPIO_PIN_SHIFT)
#define GPIO_PIN35                  (35  << GPIO_PIN_SHIFT)
#define GPIO_PIN36                  (36  << GPIO_PIN_SHIFT)
#define GPIO_PIN37                  (37  << GPIO_PIN_SHIFT)
#define GPIO_PIN38                  (38  << GPIO_PIN_SHIFT)
#define GPIO_PIN39                  (39  << GPIO_PIN_SHIFT)



#define PIN_LED1              GPIO_PIN32
#define PIN_LED2              GPIO_PIN33


/************************************************************************************
 * Public Types
 ************************************************************************************/



/************************************************************************************
 * Inline Functions
 ************************************************************************************/

#ifndef __ASSEMBLY__

/************************************************************************************
 * Public Data
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_BES_BES2001_GPIO_H */
