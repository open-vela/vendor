/************************************************************************************
 * arch/arm/src/bes/bes_gpio.h
 *
 *   Copyright (C) 2009-2011, 2013-2014 Gregory Nutt. All rights reserved.
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

#ifndef __ARCH_ARM_SRC_BES_BES_GPIO_H
#define __ARCH_ARM_SRC_BES_BES_GPIO_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>

#include "chip.h"

#if defined(CONFIG_ARCH_CHIP_BES2001)
#  include <arch/chip/bes2001_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES2003)
#  include <arch/chip/bes2003_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES2005)
#  include <arch/chip/bes2005_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES2009)
#  include <arch/chip/bes2009_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1306)
#  include <arch/chip/bes1306_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1306P)
#  include <arch/chip/bes1306p_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1305)
#  include <arch/chip/bes1305_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES2300)
#  include <arch/chip/bes2300_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1501)
#  include <arch/chip/bes1501_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1600_BTH)
#  include <arch/chip/bes1600_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1600_SENS)
#  include <arch/chip/bes1600_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1600)
#  include <arch/chip/bes1600_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1700_BTH) || defined(CONFIG_ARCH_CHIP_BES1700_SENS)
#  include <arch/chip/bes1700_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1700)
#  include <arch/chip/bes1700_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES3601)
#  include <arch/chip/bes3601_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1502X)
#  include <arch/chip/bes1502x_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1502P)
#  include <arch/chip/bes1502p_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1503)
#  include <arch/chip/bes1503_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1503P)
#  include <arch/chip/bes1503p_gpio.h>
#elif defined(CONFIG_ARCH_CHIP_BES1501P)
#  include <arch/chip/bes1501p_gpio.h>
#else
#  error Unrecognized BES architecture
#endif
#include <nuttx/ioexpander/ioexpander.h>

/* this is BES extend ioexpander api, for gpio init config(iomux)
 * before use this OPT, please check whether it conflicts with opt define in ioexpander.h
 */
#define IOEXPANDER_OPTION_BES_CONFIG    0x0F

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

/* Configuration ********************************************************************/

#if defined(CONFIG_BES_GPIOA_IRQ) || defined(CONFIG_BES_GPIOB_IRQ) || \
    defined(CONFIG_BES_GPIOC_IRQ) || defined(CONFIG_BES_GPIOD_IRQ) || \
    defined(CONFIG_BES_GPIOE_IRQ) || defined(CONFIG_BES_GPIOF_IRQ)
#  define CONFIG_BES_GPIO_IRQ 1
#else
#  undef CONFIG_BES_GPIO_IRQ
#endif

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/* Must be big enough to hold the 32-bit encoding */

typedef uint32_t gpio_pinset_t;

enum GPIO_DIR_T {
    GPIO_DIR_IN = 0,
    GPIO_DIR_OUT = 1,
};

/************************************************************************************
 * Name: bes_gpioirqinitialize
 *
 * Description:
 *   Initialize logic to support a second level of interrupt decoding for GPIO pins.
 *
 ************************************************************************************/

#ifdef CONFIG_BES_GPIO_IRQ
void bes_gpioirqinitialize(void);
#else
#  define bes_gpioirqinitialize()
#endif

/****************************************************************************
 * Name: bes_gpiopin
 *
 * Description:
 *   Return the index of the GPIO
 *
 ****************************************************************************/

uint8_t bes_gpiopin(gpio_pinset_t cfgset);

/****************************************************************************
 * Name: bes_gpiopincfg
 *
 * Description:
 *   Return the pincfg of the GPIO
 *
 ****************************************************************************/
uint32_t bes_gpiopincfg(uint8_t pin, uint8_t port);

/************************************************************************************
 * Name: bes_configgpio
 *
 * Description:
 *   Configure a GPIO pin based on bit-encoded description of the pin.
 *
 ************************************************************************************/

int bes_configgpio(gpio_pinset_t cfgset);

/************************************************************************************
 * Name: bes_gpiowrite
 *
 * Description:
 *   Write one or zero to the selected GPIO pin
 *
*/
void bes_gpiosetdir(gpio_pinset_t pinset, enum GPIO_DIR_T dir, uint8_t val_for_out);

/************************************************************************************
 * Name: bes_gpiowrite
 *
 * Description:
 *   Write one or zero to the selected GPIO pin
 *
 ************************************************************************************/
void bes_gpiowrite(gpio_pinset_t pinset, bool value);

/************************************************************************************
 * Name: bes_gpioread
 *
 * Description:
 *   Read one or zero from the selected GPIO pin
 *
 ************************************************************************************/
bool bes_gpioread(gpio_pinset_t pinset);

/************************************************************************************
 * Name: bes_gpioirq
 *
 * Description:
 *   Configure an interrupt for the specified GPIO pin.
 *
 ************************************************************************************/

#ifdef CONFIG_BES_GPIO_IRQ
void bes_gpioirq(gpio_pinset_t pinset);
#else
#  define bes_gpioirq(pinset)
#endif

/************************************************************************************
 * Name: bes_gpioirqenable
 *
 * Description:
 *   Enable the interrupt for specified GPIO IRQ
 *
 ************************************************************************************/

void bes_gpioirqenable(int irq);

/************************************************************************************
 * Name: bes_gpioirqdisable
 *
 * Description:
 *   Disable the interrupt for specified GPIO IRQ
 *
 ************************************************************************************/

void bes_gpioirqdisable(int irq);

/************************************************************************************
 * Function:  bes_dumpgpio
 *
 * Description:
 *   Dump all GPIO registers associated with the base address of the provided pinset.
 *
 ************************************************************************************/
#ifdef CONFIG_DEBUG_GPIO_INFO
int bes_dumpgpio(uint32_t pinset, const char *msg);
#else
#  define bes_dumpgpio(p,m)
#endif

/****************************************************************************
 * Name: bes_io_ioexpander_initialize
 *
 * Description:
 *   Instantiate and configure the I/O Expander device driver to use the
 *   provided gpio device instance.
 *
 * Input Parameters:
 *
 * Returned Value:
 *   an ioexpander_dev_s instance on success, NULL on failure.
 *
 ****************************************************************************/
FAR struct ioexpander_dev_s *bes_io_ioexpander_initialize(void);

bool bes_vmic_enable(uint8_t pinset, bool value);

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_BES_BES_GPIO_H */
