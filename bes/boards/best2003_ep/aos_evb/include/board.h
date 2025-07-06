/****************************************************************************
 * boards/arm/bes/bes2003_ep/include/board.h
 *
 *   Copyright (C) 2019 Gregory Nutt. All rights reserved.
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
 ****************************************************************************/

#ifndef __BOARDS_INCLUDE_BOARD_H
#define __BOARDS_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
#  include <stdint.h>
#  include <stdbool.h>
#endif

extern uint32_t _nuttx_heap_end;
#undef CONFIG_RAM_END
#define CONFIG_RAM_END ((unsigned)&_nuttx_heap_end)

#define PERFORMANCE_DEBUG 0
#if !defined(CONFIG_BES_FLASH_SUSPEND)
//#define LARGE_ERASE_BLOCK
#endif

#ifdef  CONFIG_ARCH_BOARD_CUSTOM_BES2003_EVB
#include <arch/board/board_bes2003evb.h>
#endif

#ifdef  CONFIG_ARCH_BOARD_CUSTOM_XIAOMI_K03
#include <arch/board/board_xiaomi_k03.h>
#endif

#ifdef  CONFIG_ARCH_BOARD_CUSTOM_XIAOMI_86V1
#include <arch/board/board_xiaomi_86v1.h>
#endif

#define KPAGES (1024/BES_FLASH_PAGESIZE)
#ifdef LARGE_ERASE_BLOCK
#define ERASE_PAGE   (32*KPAGES)
#define MTD_BES_RESERVED_PAGE   (64*KPAGES)
#else
#define ERASE_PAGE   (4*KPAGES)
#define MTD_BES_RESERVED_PAGE   (112*KPAGES)
#endif

#if defined(CONFIG_RECOVERY_SUPPORT) && (CONFIG_RECOVERY_BIN_SIZE != (FLASH_BL_SIZE+FLASH_OTA_SIZE+FLASH_OTA_BACKUP_SIZE+FLASH_OTAINFO_SIZE))
#error "Wrong CONFIG_RECOVERY_BIN_SIZE"
#endif

#ifdef LARGE_ERASE_BLOCK
#define BOARDMISC_OFFSET    (8*1024)
#else
#define BOARDMISC_OFFSET    (0*1024)
#endif

#define BOARD_BOOTMODE_CODE1    (1 << 21)   //crash
#define BOARD_BOOTMODE_CODE2    (1 << 24)   //wdt
#define BOARD_BOOTMODE_CODE3    (1 << 27)   //wdt a7

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* The BES2003 is fitted with a 6MHz Crystal */

#define BOARD_XTAL_FREQUENCY 6000000


/* If CONFIG_ARCH_LEDs is defined, then NuttX will control the LEDs on board
 * the BES1302EVB.  The following definitions describe how NuttX controls the
 * LEDs:
 *
 *   SYMBOL                Meaning                      LED state
 *                                                      RED   GREEN  BLUE
 *   -------------------  ----------------------------  -----------------
 */

#define LED_STARTED       1 /* NuttX has been started    OFF   OFF    OFF */
#define LED_HEAPALLOCATE  2 /* Heap has been allocated   OFF   OFF    ON  */
#define LED_IRQSENABLED   0 /* Interrupts enabled        OFF   OFF    ON  */
#define LED_STACKCREATED  3 /* Idle stack created        OFF   ON     OFF */
#define LED_INIRQ         0 /* In an interrupt          (no change)       */
#define LED_SIGNAL        0 /* In a signal handler      (no change)       */
#define LED_ASSERTION     0 /* An assertion failed      (no change)       */
#define LED_PANIC         4 /* The system has crashed    FLASH OFF    OFF */
#undef  LED_IDLE            /* BES1302EVB in sleep mode (Not used)        */


/* Alternate function pin selections ****************************************/

/* By default, the serial console will be provided on the OpenSDA VCOM port:
 *
 *   OpenSDA UART TX  PTC7 (LPUART1_TX)
 *   OpenSDA UART RX  PTC6 (LPUART1_RX)
 */

#define PIN_LPUART1_RX    PIN_LPUART1_RX_1  /* PTC6 */
#define PIN_LPUART1_TX    PIN_LPUART1_TX_1  /* PTC7 */


/*
*   System Power Control definitions
*   XXX_PDOMAIN - module power domain index
*   XXX_ACTIVITY_PRIORITY - act power priority, range from 0 to 9,
*                           larger number means higher priority
*/

#define ADC_BUTTON_PDOMAIN                0
#define ADC_BUTTON_ACTIVITY_PRIORITY      9

#define GPIO_BUTTON_PDOMAIN               0
#define GPIO_BUTTON_ACTIVITY_PRIORITY     9

#define GPIO_IR_PDOMAIN                   0
#define GPIO_IR_ACTIVITY_PRIORITY         8


#define CONSOLE_IO_PDOMAIN                0
#define CONSOLE_IO_ACTIVITY_PRIORITY      9


#define FLASH_IO_PDOMAIN                  0
#define FLASH_IO_ACTIVITY_PRIORITY        2

#define CPULOAD_TIMER_PDOMAIN             0
#define CPULOAD_TIMER_ACTIVITY_PRIORITY   2

#define RPMSG_IO_PDOMAIN                  0
#define RPMSG_IO_ACTIVITY_PRIORITY        2


#define I2C_IO_PDOMAIN                    0
#define I2C_IO_ACTIVITY_PRIORITY          2


#define SPI_IO_PDOMAIN                    0
#define SPI_IO_ACTIVITY_PRIORITY          2


#define UART_IO_PDOMAIN                   0
#define UART_IO_ACTIVITY_PRIORITY         2


#define WIFI_IO_PDOMAIN                   0
#define WIFI_IO_ACTIVITY_PRIORITY         8


#define BT_IO_PDOMAIN                     0
#define BT_IO_ACTIVITY_PRIORITY           8

#ifndef BOARD_LCDC_HFP
#ifdef CONFIG_DSI_VIDEO_MODE
#define BOARD_LCDC_HFP                  80
#define BOARD_LCDC_HBP                  80
#define BOARD_LCDC_VFP                  24
#define BOARD_LCDC_VBP                  24
#define BOARD_LCDC_HSYNC                1
#define BOARD_LCDC_VSYNC                1
#else
#define BOARD_LCDC_HFP                  12
#define BOARD_LCDC_HBP                  10
#define BOARD_LCDC_VFP                  10
#define BOARD_LCDC_VBP                  10
#define BOARD_LCDC_HSYNC                10
#define BOARD_LCDC_VSYNC                2
#endif
#endif

#define BOARD_LCDC_GCR_DEN              1
#define BOARD_LCDC_GCR_DBW              5
#define BOARD_LCDC_GCR_DGW              6
#define BOARD_LCDC_GCR_DRW              5

#if defined(CONFIG_LCDC_L1_ARGB8888)
#define PIXEL_BITS      32
#elif defined(CONFIG_LCDC_L1_RGB888)
#define PIXEL_BITS      24
#elif defined(CONFIG_LCDC_L1_RGB565)
#define PIXEL_BITS      16
#else
#define PIXEL_BITS      32
#endif
#if defined(CONFIG_FB_DOUBLE_BUFFER)
#define FB_COUNT 2
#else
#define FB_COUNT 1
#endif

#ifdef CONFIG_FB_STATIC_BUFFER
extern uint32_t __framebuffer_start__[];
#if CONFIG_FB_BUFFER_FIXED_ADDR != 0
#define CONFIG_LCDC_FB_BASE       ((uint32_t)CONFIG_FB_BUFFER_FIXED_ADDR)
#else
#define CONFIG_LCDC_FB_BASE       ((uint32_t)&__framebuffer_start__[0])
#endif
#else
#define CONFIG_LCDC_FB_BASE       (0)
#endif
#define CONFIG_LCDC_FB_SIZE       (BOARD_LCDC_WIDTH*BOARD_LCDC_HEIGHT*FB_COUNT*PIXEL_BITS/8)

#endif  /* __BOARDS_BEST2003_EP_INCLUDE_BOARD_H */
