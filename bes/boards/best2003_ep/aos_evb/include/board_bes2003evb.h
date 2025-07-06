/****************************************************************************
 * boards/arm/bes/bes2003_ep/include/board_bes2003evb.h
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

#ifndef __BOARD_BES2001EVB_INCLUDE_BOARD_H
#define __BOARD_BES2001EVB_INCLUDE_BOARD_H

#define CFG_HW_HAVE_PWR_KEY 1
#define CFG_HW_PWL_NUM 0
#define CFG_HW_GPIOKEY_NUM 1
#define CFG_HW_ADCKEY_NUMBER 4
#define CFG_HW_ADCKEY_ADC_MAXVOLT 1000
#define CFG_HW_ADCKEY_ADC_MINVOLT 0
#define CFG_HW_ADCKEY_ADC_KEYVOLT_BASE 130

#include <nuttx/config.h>

//ref hal_iomux_2003.c
#if defined (CONFIG_BES_MODEM)
#define I2C0_IOMUX_INDEX    20 // hal_iomux_set_i2c0
#define I2C1_IOMUX_INDEX    14 // hal_iomux_set_i2c1
#elif defined (CONFIG_BES_CAMCSI)
#define I2C0_IOMUX_INDEX    00 // hal_iomux_set_i2c0
#define I2C1_IOMUX_INDEX    14 // hal_iomux_set_i2c1
#else
#define I2C0_IOMUX_INDEX    00 // hal_iomux_set_i2c0
#define I2C1_IOMUX_INDEX    06 // hal_iomux_set_i2c1
#endif
#define UART2_IOMUX_INDEX   00 // hal_iomux_set_uart2

/*
*  CSICAM configuration
*/
#ifdef CONFIG_BES_CAMCSI
#define CAMERA_I2C_PORT   0
#define GPIO_CAMCSI_PWDN  (GPIO_CFG_PULLDOWN|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO|GPIO_OUTPUT|GPIO_OUTPUT_SET|GPIO_PIN20) /* pin 2_4 */
#define GPIO_CAMCSI_RSTN  (GPIO_CFG_PULLDOWN|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO|GPIO_OUTPUT|GPIO_OUTPUT_CLEAR|GPIO_PIN21) /* pin 2_5 */
#endif

/**
 * Board lcd Configuration
 */
#if defined(CONFIG_BES_LCD_RM69330)
#define BOARD_LCDC_WIDTH               454
#define BOARD_LCDC_HEIGHT              454
#elif defined(CONFIG_BES_LCD_NT38350)
#define BOARD_LCDC_WIDTH               480
#define BOARD_LCDC_HEIGHT              480
#elif defined(CONFIG_BES_LCD_A064)
#define BOARD_LCDC_WIDTH               480
#define BOARD_LCDC_HEIGHT              480
#define BOARD_LCDC_HFP                  80
#define BOARD_LCDC_HBP                  80
#define BOARD_LCDC_VFP                  24
#define BOARD_LCDC_VBP                  24
#define BOARD_LCDC_HSYNC                1
#define BOARD_LCDC_VSYNC                1
#elif defined(CONFIG_BES_LCD_GC9503NP)
#define BOARD_LCDC_WIDTH               480
#define BOARD_LCDC_HEIGHT              800
#define BOARD_LCDC_HFP                  80
#define BOARD_LCDC_HBP                  80
#define BOARD_LCDC_VFP                  24
#define BOARD_LCDC_VBP                  24
#define BOARD_LCDC_HSYNC                1
#define BOARD_LCDC_VSYNC                1
#elif defined(CONFIG_BES_LCD_ST7701S)
#define BOARD_LCDC_WIDTH               480
#define BOARD_LCDC_HEIGHT              640
#define BOARD_LCDC_HFP                  60
#define BOARD_LCDC_HBP                  60
#define BOARD_LCDC_VFP                  13
#define BOARD_LCDC_VBP                  13
#define BOARD_LCDC_HSYNC                10
#define BOARD_LCDC_VSYNC                10
#elif defined(CONFIG_BES_LCD_ST7796U)
#define BOARD_LCDC_WIDTH               320
#define BOARD_LCDC_HEIGHT              480
#define BOARD_LCDC_HFP                  50
#define BOARD_LCDC_HBP                  50
#define BOARD_LCDC_VFP                  15
#define BOARD_LCDC_VBP                  15
#define BOARD_LCDC_HSYNC                8
#define BOARD_LCDC_VSYNC                4
#elif defined(CONFIG_BES_LCD_ST7785M)
#define BOARD_LCDC_WIDTH               320
#define BOARD_LCDC_HEIGHT              240
#define BOARD_LCDC_HFP                  50
#define BOARD_LCDC_HBP                  66
#define BOARD_LCDC_VFP                  200 // 30fps
#define BOARD_LCDC_VBP                  200 // 30fps
#define BOARD_LCDC_HSYNC                10
#define BOARD_LCDC_VSYNC                200 // 30fps
#elif defined(CONFIG_BES_LCD_ST7797)
#define BOARD_LCDC_WIDTH               320
#define BOARD_LCDC_HEIGHT              480
#define BOARD_LCDC_HFP                  40
#define BOARD_LCDC_HBP                  40
#define BOARD_LCDC_VFP                  15
#define BOARD_LCDC_VBP                  15
#define BOARD_LCDC_HSYNC                10
#define BOARD_LCDC_VSYNC                4
#elif defined(CONFIG_BES_LCD_HX8394)
#define BOARD_LCDC_WIDTH               480
#define BOARD_LCDC_HEIGHT              1280
#define BOARD_LCDC_HFP                  26
#define BOARD_LCDC_HBP                  26
#define BOARD_LCDC_VFP                  16
#define BOARD_LCDC_VBP                  14
#define BOARD_LCDC_HSYNC                2
#define BOARD_LCDC_VSYNC                2
#elif defined(CONFIG_BES_LCD_ST7703)
#define BOARD_LCDC_WIDTH               640
#define BOARD_LCDC_HEIGHT              1280
#define BOARD_LCDC_HFP                  22
#define BOARD_LCDC_HBP                  28
#define BOARD_LCDC_VFP                  15
#define BOARD_LCDC_VBP                  13
#define BOARD_LCDC_HSYNC                10
#define BOARD_LCDC_VSYNC                3
#elif defined(CONFIG_BES_LCD_JD9165A)
#define BOARD_LCDC_WIDTH               1024
#define BOARD_LCDC_HEIGHT              600
#define BOARD_LCDC_HFP                  160
#define BOARD_LCDC_HBP                  136
#define BOARD_LCDC_VFP                  12
#define BOARD_LCDC_VBP                  21
#define BOARD_LCDC_HSYNC                24
#define BOARD_LCDC_VSYNC                3
#define CONFIG_LCDC_FB_BPP              24
#elif defined(CONFIG_BES_LCD_JT4007)
#define BOARD_LCDC_WIDTH               480
#define BOARD_LCDC_HEIGHT              480
#define BOARD_LCDC_HFP                  40
#define BOARD_LCDC_HBP                  20
#define BOARD_LCDC_VFP                  20
#define BOARD_LCDC_VBP                  20
#define BOARD_LCDC_HSYNC                20
#define BOARD_LCDC_VSYNC                10
#elif defined(CONFIG_VIDEO_FB)
#error "BOARD_LCDC_WIDTH/BOARD_LCDC_HEIGHT not defined"
#endif

#if defined(CONFIG_LV_FBDEV_USE_STATIC_BUFFER) && \
    ((CONFIG_LV_FBDEV_HOR_RES*CONFIG_LV_FBDEV_VER_RES) != (BOARD_LCDC_WIDTH*BOARD_LCDC_HEIGHT))
#define CONFIG_ZOOM_TO_SCREEN
#undef BOARD_LCDC_HEIGHT
#undef BOARD_LCDC_WIDTH
#define BOARD_LCDC_HEIGHT           CONFIG_LV_FBDEV_VER_RES
#define BOARD_LCDC_WIDTH            CONFIG_LV_FBDEV_HOR_RES
#endif

#include <arch/chip/bes_gpio.h>

#ifndef __ASSEMBLY__
#include <stdint.h>
#include <stdbool.h>
#endif

/*
*  BUTTON configuration
*/
#define NUM_BUTTONS (CFG_HW_ADCKEY_NUMBER+CFG_HW_GPIOKEY_NUM+1)   // ADCKEY + GPIOKEY + POWER KEY

/*
* User LED configuration
*/
#define NUM_GPIOLED                       2
#define PIN_LED1_BIT                      (1 << NUM_LEDPINLED)      /* bit in ledset */
#define PIN_LED2_BIT                      (1 << (NUM_LEDPINLED +1)  /* bit in ledset */

#define GPIOPIN_LED1                      PIN_LED1        /* pin 3_4 */
#define GPIOPIN_LED2                      PIN_LED2        /* pin 3_5 */

/*
*  RGB LED configuration
*/

#define CONFIG_RGBLED_RPWM_ID0            BES_HAL_LED_ID1
#define CONFIG_RGBLED_GPWM_ID1            BES_HAL_PWM_ID_2
#define CONFIG_RGBLED_BPWM_ID2            BES_HAL_PWM_ID_3
#define CONFIG_RRGBLED_RGPIO_ID           PIN_LED1
#define CONFIG_RRGBLED_GGPIO_ID           GPIO_PIN28   /* pin 3_4 */
#define CONFIG_RRGBLED_BGPIO_ID           GPIO_PIN29   /* pin 3_5 */

#define RGBLED_RPWM                       GPIO_ALT_GPIO
#define RGBLED_GPWM                       GPIO_ALT_PWM2
#define RGBLED_BPWM                       GPIO_ALT_PWM3


#ifndef CONFIG_RRGBLED_RGPIO_ID
   #error "Unknown gpio id for red led"
#else
   #define GPIO_RGBLED_RPINSET       CONFIG_RRGBLED_RGPIO_ID|GPIO_PORT_GPIO0 \
                                     |GPIO_OUTPUT|RGBLED_RPWM|GPIO_PIN_VOLTAGE_VIO
#endif

#ifndef CONFIG_RRGBLED_GGPIO_ID
   #error "Unknown gpio id for green led"
  #else
   #define GPIO_RGBLED_GPINSET      CONFIG_RRGBLED_GGPIO_ID|GPIO_PORT_GPIO0 \
                                    |GPIO_OUTPUT|RGBLED_GPWM|GPIO_PIN_VOLTAGE_VIO
#endif

#ifndef CONFIG_RRGBLED_BGPIO_ID
   #error "Unknown gpio id for blue led"
#else
   #define GPIO_RGBLED_BPINSET      CONFIG_RRGBLED_BGPIO_ID|GPIO_PORT_GPIO0 \
                                    |GPIO_OUTPUT|RGBLED_BPWM|GPIO_PIN_VOLTAGE_VIO
#endif

/*
*  IRC configuration
*/

/*irc transmiter use PWM  to  generate  ir signal*/
#ifndef CONFIG_BES_TX_PWM_ID
#define CONFIG_BES_TX_PWM_ID      2
#endif

#ifndef CONFIG_BES_IR_TX_PIN
#define CONFIG_BES_IR_TX_PIN      GPIO_PIN29    //pin 3_5
#endif

#define GPIO_IR_TX_PINCFG         CONFIG_BES_IR_TX_PIN|GPIO_PORT_GPIO0 \
                                  |GPIO_OUTPUT|GPIO_ALT_PWM5|GPIO_PIN_VOLTAGE_VIO

#define GPIO_IR_TX_PINCFG_GPIO    CONFIG_BES_IR_TX_PIN|GPIO_PORT_GPIO0 \
                                  |GPIO_OUTPUT|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO
/*irc receiver capture the ir sinale with gpio interrupt */
#ifndef CONFIG_IR_RX_PIN
#define CONFIG_IR_RX_PIN          GPIO_PIN28  //pin 3_4
#endif

#define GPIO_IR_RX_INT_PINCFG_FL  CONFIG_IR_RX_PIN|GPIO_PORT_GPIO0|GPIO_INT_FALLING \
                                  |GPIO_CFG_PULLUP|GPIO_INPUT|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO

#define GPIO_IR_RX_INT_PINCFG_RH  CONFIG_IR_RX_PIN|GPIO_PORT_GPIO0|GPIO_INT_RISING \
                                  |GPIO_CFG_PULLUP|GPIO_INPUT|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO



#ifndef CONFIG_IR_NEC_DECODER
#    define CONFIG_IR_NEC_DECODER     1
#endif
/*
*  I2C devices configuration
*/

#  define GPIO_GPIO_SCL    (GPIO_CFG_PULLUP|GPIO_PORT_GPIO0 |GPIO_ALT_GPIO|GPIO_PIN6|GPIO_PIN_VOLTAGE_VIO)  /* pin 0_6 */
#  define GPIO_GPIO_SDA    (GPIO_CFG_PULLUP|GPIO_PORT_GPIO0 |GPIO_ALT_GPIO|GPIO_PIN7|GPIO_PIN_VOLTAGE_VIO)  /* pin 0_7 */

#define GPIO_TP_INT  (GPIO_CFG_PULLUP|GPIO_INT_FALLING|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO|GPIO_INPUT|GPIO_PIN23) /* pin 2_7 */
#define GPIO_TP_RST  (GPIO_CFG_PULLUP|GPIO_PORT_GPIO0|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO|GPIO_OUTPUT|GPIO_PIN5) /* pin 0_5 */

#define ZINITIX_I2C_ADDRESS          0x20
#define NT38350_I2C_ADDRESS          0x62


#ifdef CONFIG_BES_ACCLIS2DH

#define acclis2dh_port   0        /* use i2c port 0     i2c = bes_i2cbus_initialize(0)*/
#define acclis2dh_addr   0x1d//0x18
#ifndef CONFIG_BES_HARDWARE_MIWARE_EN
#define ACCLIST_INT2_PINIDX       GPIO_PIN13
#define ACCLIST_INT2_PINCFG       GPIO_PIN13|GPIO_PORT_GPIO0|GPIO_INT_FALLING|GPIO_CFG_PULLUP \
                                  |GPIO_INPUT|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO
#endif
#endif

/* External rm69330 Pins */
#define GPIO_PANEL_RST  (GPIO_CFG_PULLUP|GPIO_OUTPUT|GPIO_PORT_GPIO0 |GPIO_ALT_GPIO|GPIO_PIN3|GPIO_PIN_VOLTAGE_VIO)  // pin 0_3
#define GPIO_PANEL_LED  (GPIO_CFG_PULLUP|GPIO_OUTPUT|GPIO_PORT_GPIO0 |GPIO_ALT_GPIO|GPIO_PIN22|GPIO_PIN_VOLTAGE_VIO)  // pin 2_6

/*
* SPI device configuration
*/
#ifdef CONFIG_BES_MODEM
#define SPI_IOMUX_INDEX     04
#define SPI_IOMUX_4WIRE
#define GPIO_MODEM_CS    GPIO_PIN6  // HAL_GPIO_PIN_P0_6
#define GPIO_MODEM_HRDY  GPIO_PIN1  // HAL_GPIO_PIN_P0_1
#define GPIO_MODEM_DRDY  GPIO_PIN22 // HAL_GPIO_PIN_P2_6
#define GPIO_MODEM_DINT  GPIO_PIN0  // HAL_GPIO_PIN_P0_0
#define GPIO_MODEM_DIRE  GPIO_PIN10 // HAL_GPIO_PIN_P1_2
#endif

/* SPI0 */
#   define GPIO_SPI0_CLK  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPI_CLK|GPIO_PIN23|GPIO_PIN_VOLTAGE_VIO)   /* pin 2_7 */
#   define GPIO_SPI0_CS0  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPI_CS0|GPIO_PIN22|GPIO_PIN_VOLTAGE_VIO)   /* pin 2_6 */
#   define GPIO_SPI0_DIO  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPI_DIO|GPIO_PIN21|GPIO_PIN_VOLTAGE_VIO)   /* pin 2_5 */
#   define GPIO_SPI0_DI0  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPI_DI0|GPIO_PIN20|GPIO_PIN_VOLTAGE_VIO)   /* pin 2_4  4 wire only*/

/* SPI1/SPILCD */
#   define GPIO_SPILCD_CLK  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPILCD_CLK|GPIO_PIN3|GPIO_PIN_VOLTAGE_VIO)   /* pin 0_3 */
#   define GPIO_SPILCD_CS0  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPILCD_CS0|GPIO_PIN2|GPIO_PIN_VOLTAGE_VIO)   /* pin 0_2 */
#   define GPIO_SPILCD_DIO  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPILCD_DIO|GPIO_PIN1|GPIO_PIN_VOLTAGE_VIO)   /* pin 0_1 */
#   define GPIO_SPILCD_DI0  (GPIO_CFG_NOPULL|GPIO_PORT_GPIO0 |GPIO_ALT_SPILCD_DI0|GPIO_PIN0|GPIO_PIN_VOLTAGE_VIO)   /* pin 0_0  4 wire only*/

/*
*  gpio set exported to user space
*/

#define NUM_OUTPUT_EXPGPIO         0
#define NUM_INPUT_EXPGPIO          0
#define NUM_LEVELINT_EXPGPIO       0
#define NUM_EDGEINT_EXPGPIO        0


/*
*  speaker external PA enable pin
*/
#define  SPEAKER_EXT_PAEN_PINSET   GPIO_PIN18|GPIO_PORT_GPIO0|GPIO_OUTPUT|GPIO_ALT_GPIO|GPIO_PIN_VOLTAGE_VIO  /* pin 2_2*/


/*
*  SD card dected pin
*/
#if defined(CONFIG_MMCSD_HAVE_CARDDETECT)
#define GPIO_SD_DETECT_PIN  GPIO_PIN2 /* pin 0_2 */
#endif


/*
* battery and charger
*/

#define GPADC_CHAN_BATTERY   1
#define GPADC_ATP_ONESHOT  -1
#define GPADC_BAD_VALUE  0xFFFF

#define BES_BATTERY_LEVEL_MIN     0
#define BES_BATTERY_LEVEL_MAX     100
#define BES_BATTERY_STABLE_COUNT  5
#define BES_BATTERY_MONITOR_PERIODIC_US  1000000
#define BES_BATTERY_MEASURE_PERIODIC_NORMAL_MS   1000
#define BES_BATTERY_MIN_MV (3200)
#define BES_BATTERY_PD_MV   (3100)
#define BES_BATTERY_MAX_MV (4300)
#define BES_BATTERY_MV_BASE ((BES_BATTERY_MAX_MV-BES_BATTERY_PD_MV)/(100))

#define BES_BATT_OV_DELAY_1S   1000000
#define BES_BATT_OV_DELAY_2S   2000000
#define BES_BATT_OV_DELAY_3S   3000000
#define BES_BATT_OV_DELAY_4S   4000000
#define BES_BATT_OV_DELAY_8S   8000000


#define BES_BATT_UV_DELAY_1S   1000000
#define BES_BATT_UV_DELAY_2S   2000000
#define BES_BATT_UV_DELAY_3S   3000000
#define BES_BATT_UV_DELAY_4S   4000000
#define BES_BATT_UV_DELAY_8S   8000000
#define BES_BATT_UV_DELAY_16S  16000000


#define BES_BATTERY_CHARGE_OFFSET_MV  (20)
#define BES_CHARGER_PLUGINOUT_DEBOUNCE_MS   (50)
#define BES_BATTERY_CHARGING_SLOPE_TABLE_COUNT  (6)
#define BES_CHARGER_PLUGINOUT_DEBOUNCE_CNT (3)
#define BES_BATTERY_CHARGING_PERIODIC_MS (BES_BATTERY_MEASURE_PERIODIC_NORMAL_MS)
#define BES_BATTERY_CHARGING_EXTPIN_MEASURE_CNT (BES_BATTERY_CHARGING_PERIODIC_MS<2*1000?2*1000/BES_BATTERY_CHARGING_PERIODIC_MS:1)
#define BES_BATTERY_CHARGING_EXTPIN_DEDOUNCE_CNT (6)
#define BES_BATTERY_CHARGING_OVERVOLT_MEASURE_CNT (BES_BATTERY_CHARGING_PERIODIC_MS<2*1000?2*1000/BES_BATTERY_CHARGING_PERIODIC_MS:1)
#define BES_BATTERY_CHARGING_OVERVOLT_DEDOUNCE_CNT (3)
#define BES_BATTERY_CHARGING_SLOPE_MEASURE_CNT (BES_BATTERY_CHARGING_PERIODIC_MS<20*1000?20*1000/BES_BATTERY_CHARGING_PERIODIC_MS:1)
#define BES_BATTERY_CHARGE_TIMEOUT_MIN   (90)

#define BES_BATTERY_OPEN_MODE_CHARGING  1
#define BES_BATTERY_OPEN_MODE_NORMAL    0


/*
*   dvfs
*/

#define UP_THRESHOLD 20
#define DN_THRESHOLD 60
#define NUM_SYS_FREQ_POINTS   9

#define FREQ_MAXID 0
#define FREQ_MINID 8

#define FREQ_IDLE    104000
#define FREQ_NORMAL  320000
#define FREQ_STANDBY 52000
#define FREQ_DSLEEP  32  //32


enum SYSFREQ_USER_T {
    SYSFREQ_USER_IDLE,
    SYSFREQ_USER_IRC_0,
    SYSFREQ_USER_AUD_REC_1,
    SYSFREQ_USER_AUD_PLAY_2,
    SYSFREQ_USER_BT_IF_3,
    SYSFREQ_USER_WIFI_IF_4,
    SYSFREQ_USER_FLASH_IO_5,
    SYSFREQ_USER_QTY
};

#define DVFS_AUTO_USER 9

#define CODEC_SADC_VOL (5)
#ifdef CONFIG_AISPEECH_ALG
#define CODEC_MIC_CH0_SADC_VOL              5
#define CODEC_MIC_CH1_SADC_VOL              11
#define CODEC_MIC_CH2_SADC_VOL              11
#else
#ifdef CONFIG_ARCH_BOARD_CUSTOM_XIAOMI_M01
#define CODEC_MIC_CH0_SADC_VOL              3
#define CODEC_MIC_CH1_SADC_VOL              3
#define CODEC_MIC_CH2_SADC_VOL              0
#else
#define CODEC_MIC_CH0_SADC_VOL              5
#define CODEC_MIC_CH1_SADC_VOL              11
#define CODEC_MIC_CH2_SADC_VOL              11
#endif
#endif

#define CFG_HW_AUD_INPUT_PATH_NUM           (1)
#define AUD_INPUT_VMIC_CFG                  (AUD_VMIC_MAP_VMIC1)

#define SW_VOLUME_LEVEL_COUNT               (100)
#define TGT_VOLUME_LEVEL_COUNT              (TGT_VOLUME_LEVEL_QTY+SW_VOLUME_LEVEL_COUNT-16)
#define SW_VOLUME_DEFAULT_LEVEL             (98)

//config codec iir.
#define EQ_HW_DAC_IIR_LIST_NUM              1
#define EQ_HW_ADC_IIR_LIST_NUM              1
#define EQ_HW_IIR_LIST_NUM                  1
#define EQ_SW_IIR_LIST_NUM                  1
#define EQ_HW_FIR_LIST_NUM                  3

//#define CFG_HW_AUD_OUTPUT_POP_SWITCH (enum HAL_IOMUX_PIN_T)(((CONFIG_AUDIO_PA_SWITCH_GPIO/10)<<3)|(CONFIG_AUDIO_PA_SWITCH_GPIO%10))

#define BES_FLASH_BASE        0x28000000
#define BES_FLASH_SIZE        0x1000000
#define BES_FLASH_SECTOR_SIZE 4096
#define BES_FLASH_PAGESIZE    256

#if defined(CONFIG_RECOVERY_SUPPORT)
#define FLASH_BL_SIZE         (256*1024) // bl: bootloader 256K
#define FLASH_OTA_SIZE        (512*1024)   // ota : 512K
#define FLASH_OTA_BACKUP_SIZE (512*1024) // ota backup: 512K
#define FLASH_OTAINFO_SIZE    (64*1024) // ota info 64K
#endif

#define FLASH_SST_SIZE        (512*1024) // sst: 512K secure storage for tee (unused for k03)
#define FLASH_TEE_SIZE        (1*1024*1024) // tee: 1M (unused for K03)

#define FLASH_APP_SIZE        (4*1024*1024 + 704*1024) // ap: 4.6875M
#define FLASH_A7_SIZE         (8*1024*1024) // a7: 8M

#if defined(CONFIG_MTD)
#define FLASH_DATA_SIZE       (1*1024*1024) // data: 1M
#endif

#define FLASH_MISC_SIZE       (128 *1024) // misc: misc

#ifndef BOARD_FLASH_PTABLE
#if defined(CONFIG_RECOVERY_SUPPORT)
#define BOARD_FLASH_PTABLE \
  {\
    .name       = "ota_b",\
    .firstblock = (FLASH_BL_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
    .nblocks    = (FLASH_OTA_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\
  {\
    .name       = "ota",\
    .firstblock = ((FLASH_BL_SIZE+FLASH_OTA_SIZE)/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
    .nblocks    = (FLASH_OTA_BACKUP_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\
  {\
    .name       = "ota_info",\
    .firstblock = ((FLASH_BL_SIZE+FLASH_OTA_SIZE+FLASH_OTA_BACKUP_SIZE)/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
    .nblocks    = (FLASH_OTAINFO_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\
  {\
    .name       = "ap",\
    .firstblock = (CONFIG_RECOVERY_BIN_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
    .nblocks    = (FLASH_APP_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\
  {\
    .name       = "a7",\
    .firstblock = ((CONFIG_RECOVERY_BIN_SIZE+FLASH_APP_SIZE)/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
    .nblocks    = (FLASH_A7_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\

#else
#define BOARD_FLASH_PTABLE \
  {\
    .name       = "ap",\
    .firstblock = 0,\
    .nblocks    = (FLASH_APP_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\

#endif

#define BOARD_FLASH_PTABLE_REMAIN \
  {\
    .name       = "data",\
    .firstblock = (BES_FLASH_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE - 128*KPAGES\
                                    - (FLASH_DATA_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
    .nblocks    = (FLASH_DATA_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE,\
  },\
  /* the last 128K is used for other  partition*/ \
  {\
    .name       = "misc", /*now misc is fixed at offset 120 or 128 to compatible with DVT1 machine*/ \
    .firstblock = (BES_FLASH_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE - MTD_BES_RESERVED_PAGE - ERASE_PAGE - ERASE_PAGE, \
    .nblocks    = ERASE_PAGE,\
  },\
  {\
    .name       = "bootinfo",\
    .firstblock = (BES_FLASH_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE - MTD_BES_RESERVED_PAGE - ERASE_PAGE,\
    .nblocks    = ERASE_PAGE,\
  },\
  {\
    .name       = "bes_reserved",\
    .firstblock = (BES_FLASH_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE - MTD_BES_RESERVED_PAGE,\
    .nblocks    = MTD_BES_RESERVED_PAGE - ERASE_PAGE,\
  },\
  {\
    .name       = "factory",\
    .firstblock = (BES_FLASH_SIZE/BES_FLASH_PAGESIZE + ERASE_PAGE - 1)/ERASE_PAGE*ERASE_PAGE - ERASE_PAGE,\
    .nblocks    = ERASE_PAGE,\
  },\

#endif

#endif  /* __BOARD_XIAOMI_86V1_INCLUDE_BOARD_H */
