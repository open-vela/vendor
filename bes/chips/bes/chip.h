/************************************************************************************
 * arch/arm/src/bes/chip.h
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_BES_CHIP_H
#define __ARCH_ARM_SRC_BES_CHIP_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>

/* Include the memory map and the chip definitions file.  Other chip hardware files
 * should then include this file for the proper setup.
 */

#include <arch/irq.h>
//#include "hardware/bes130x_memorymap.h"

/* The common ARMv6/7-M vector handling logic expects the following definitions in
 * this file.  ARMV6/7M_PERIPHERAL_INTERRUPTS provides the number of supported
 * external interrupts which, for this architecture, is provided in the
 * arch/bes/irq.h header file.
 */

#define ARMV6M_PERIPHERAL_INTERRUPTS (NR_IRQS-16)
#define ARMV7M_PERIPHERAL_INTERRUPTS (NR_IRQS-16)
#define ARMV8M_PERIPHERAL_INTERRUPTS (NR_IRQS-16)

/* Cache line sizes (in bytes)for the BES130X */

#define ARMV7M_DCACHE_LINESIZE 16  /* 16 bytes (4 words) */
#define ARMV7M_ICACHE_LINESIZE 16  /* 16 bytes (4 words) */


#define ARMV8M_DCACHE_LINESIZE 16  /* 16 bytes (4 words) */
#define ARMV8M_ICACHE_LINESIZE 16  /* 16 bytes (4 words) */

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
#define SCS_BASE            (0xE000E000UL)                             /*!< System Control Space Base Address */
#define SCB_BASE            (SCS_BASE +  0x0D00UL)                     /*!< System Control Block Base Address */
#define SCB_ID_ADR          (SCB_BASE +     0x04C)                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Public Data
 ************************************************************************************/

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/
#ifdef __ASSEMBLY__

/****************************************************************************
 * Name: setirqstack
 *
 * Description:
 *   Set the current stack pointer to the  -"top" of the IRQ interrupt
 *   stack for the current CPU.
 *
 ****************************************************************************/

#if defined(CONFIG_SMP) && CONFIG_ARCH_INTERRUPTSTACK > 7
  .macro  setintstack, tmp1, tmp2
  ldr  \tmp2, =SCB_ID_ADR
  ldr \tmp1, [\tmp2]
  and  \tmp1, \tmp1, #3          /* Bits 0-1=CPU ID */
  ldr  \tmp2, =g_cpu_intstack_top    /* tmp2=Array of IRQ stack pointers */
  lsls \tmp1, \tmp1, #2          /* tmp1=Array byte offset */
  add  \tmp2, \tmp2, \tmp1       /* tmp2=Offset address into array */
  ldr  \tmp1, [\tmp2, #0]        /* tmp1=Address in stack allocation */
  mov     sp, \tmp1                  /* Instantiate the aligned stack */
  sub  \tmp2, \tmp1, #CONFIG_ARCH_INTERRUPTSTACK       /* Reserve signal context */
  bic  \tmp2, \tmp2, #7              /* Get the stack pointer with 8-byte alignment */
#ifdef CONFIG_ARMV8M_STACKCHECK_HARDWARE
  msr     msplim, \tmp2
#endif
  .endm
#endif
#endif

#endif /* __ARCH_ARM_SRC_BES_CHIP_H */
