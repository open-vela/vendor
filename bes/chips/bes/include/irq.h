/****************************************************************************
 * arch/arm/include/bes/irq.h
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
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

/* This file should never be included directly but, rather, only indirectly
 * through nuttx/irq.h
 */

#ifndef __ARCH_ARM_INCLUDE_BES_IRQ_H
#define __ARCH_ARM_INCLUDE_BES_IRQ_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
//#include "best2300p.h"
#if defined(CONFIG_ARCH_CHIP_BES1501)
#define NR_IRQS (16 + 63)
#elif defined(CONFIG_ARCH_CHIP_BES1300)
#define NR_IRQS (16 + 47)
#elif defined(CONFIG_ARCH_CHIP_BES1302)
#define NR_IRQS (16 + 51)
#elif defined(CONFIG_ARCH_CHIP_BES1303)
#define NR_IRQS (16 + 57)
#elif defined(CONFIG_ARCH_CHIP_BES1306)
#define NR_IRQS (16 + 76)
#elif defined(CONFIG_ARCH_CHIP_BES1306P)
#define NR_IRQS (16 + 76)
#elif defined(CONFIG_ARCH_CHIP_BES1305)
#define NR_IRQS (16 + 76)
#elif defined(CONFIG_ARCH_CHIP_BES2001)
#define NR_IRQS (16 + 68)
#elif defined(CONFIG_ARCH_CHIP_BES2003)
#define NUTTX_USB_IRQ (16 + 7)
#define NR_IRQS (16 + 72)
#elif defined(CONFIG_ARCH_CHIP_BES2005)
#define NR_IRQS (16 + 72)
#elif defined(CONFIG_ARCH_CHIP_BES2009)
#define NUTTX_USB_IRQ (16 + 7)
#define NR_IRQS (16 + 155)
#elif defined(CONFIG_ARCH_CHIP_BES1600)
#define NUTTX_USB_IRQ (16 + 3)
#define NR_IRQS (16 + 72)
#elif defined(CONFIG_ARCH_CHIP_BES1600_BTH)
#define NR_IRQS (16 + 64)
#elif defined(CONFIG_ARCH_CHIP_BES1600_SENS)
#define NR_IRQS (16 + 52)
#elif defined(CONFIG_ARCH_CHIP_BES1700)
#define NUTTX_USB_IRQ (16 + 17)
#define NR_IRQS (16 + 120)
#elif defined(CONFIG_ARCH_CHIP_BES1700_BTH) || defined(CONFIG_ARCH_CHIP_BES1700_SENS)
#define NR_IRQS (16 + 127)
#elif defined(CONFIG_ARCH_CHIP_BES3601)
#define NUTTX_USB_IRQ (16 + 17)
#define NR_IRQS (16 + 120)
#elif defined(CONFIG_ARCH_CHIP_BES1501P)
#if defined(CONFIG_BES1501P_SENSOR)
#define NR_IRQS (16 + 52)
#else
#define NR_IRQS (16 + 64)
#endif
#elif defined(CONFIG_ARCH_CHIP_BES1502X)
#define NUTTX_USB_IRQ (16 + 7)
#if defined(CONFIG_BES1502X_SENSOR)
#define NR_IRQS (16 + 56)
#else
#define NR_IRQS (16 + 74)
#endif
#elif defined(CONFIG_ARCH_CHIP_BES1502P)
#if defined(CONFIG_BES1502P_SENSOR)
#define NR_IRQS (16 + 56)
#else
#define NR_IRQS (16 + 93)
#endif
#elif defined(CONFIG_ARCH_CHIP_BES1503)
#define NR_IRQS (16 + 72)
#elif defined(CONFIG_ARCH_CHIP_BES1503P)
#define NR_IRQS (16 + 78)
#endif

#endif /* __ARCH_ARM_INCLUDE_BES_IRQ_H */
