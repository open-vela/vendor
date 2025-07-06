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

#define CHIP_MPCORE_VBASE       0x58300000
#define PGTABLE_L1_SIZE         0x00004000  /* 16K - 4G */

#define IDLE_STACK_BASE         g_cpu0_idlestack

#ifndef __ASSEMBLY__
typedef long long __s64;
typedef unsigned char __u8;
extern uint32_t _nuttx_heap_end;
#define PGTABLE_BASE_VADDR      ((uint32_t)&_nuttx_heap_end+0x10000-PGTABLE_L1_SIZE)
#else
#define PGTABLE_BASE_VADDR      (_nuttx_heap_end+0x10000-PGTABLE_L1_SIZE)
#endif

#define PGTABLE_BASE_PADDR      (PGTABLE_BASE_VADDR)
#define PGTABLE_L2_SIZE         0x000008000 /* 32K - 32M */
#define PGTABLE_L2_PBASE        (PGTABLE_BASE_PADDR-PGTABLE_L2_SIZE)
#define PGTABLE_L2_VBASE        PGTABLE_L2_PBASE

#define PGTABLE_END_PADDR       (PGTABLE_BASE_PADDR + PGTABLE_L1_SIZE)
#define PGTABLE_END_VADDR       (PGTABLE_BASE_VADDR + PGTABLE_L1_SIZE)

#define PGTABLE_PSRAM_L2_SIZE   0x000003800 /* 14K - 14M */
#define PGTABLE_PSRAM_L2_PBASE  (PGTABLE_BASE_PADDR-PGTABLE_L2_SIZE-PGTABLE_PSRAM_L2_SIZE)
#define PGTABLE_PSRAM_L2_VBASE  PGTABLE_PSRAM_L2_PBASE

#define PGTABLE_SRAM_L2_SIZE    0x000000800 /* 2K - 2M */
#define PGTABLE_SRAM_L2_PBASE   (PGTABLE_BASE_PADDR-PGTABLE_L2_SIZE-PGTABLE_PSRAM_L2_SIZE-PGTABLE_SRAM_L2_SIZE)
#define PGTABLE_SRAM_L2_VBASE   PGTABLE_SRAM_L2_PBASE

#if defined(CONFIG_BOOT_RUNFROMFLASH)
#define NUTTX_TEXT_VADDR        (CONFIG_FLASH_VSTART & 0xfff00000)
#define NUTTX_TEXT_PADDR        (CONFIG_FLASH_START & 0xfff00000)
#define NUTTX_TEXT_SIZE         (CONFIG_FLASH_SIZE & 0xfff00000)

/* The "primary" RAM is the SDRAM or SRAM used for .bss and .data */

#define NUTTX_RAM_VADDR         (CONFIG_RAM_VSTART & 0xfff00000)
#define NUTTX_RAM_PADDR         (CONFIG_RAM_START & 0xfff00000)
#define NUTTX_RAM_SIZE          (CONFIG_RAM_SIZE)

#else

#define NUTTX_TEXT_PADDR        _stext
#define NUTTX_TEXT_VADDR        _stext
#define NUTTX_TEXT_SIZE         0x100000

#endif

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
  .macro  setirqstack, tmp1, tmp2
  mrc  p15, 0, \tmp1, c0, c0, 5  /* tmp1=MPIDR */
  and  \tmp1, \tmp1, #3          /* Bits 0-1=CPU ID */
  ldr  \tmp2, =g_irqstack_top    /* tmp2=Array of IRQ stack pointers */
  lsls \tmp1, \tmp1, #2          /* tmp1=Array byte offset */
  add  \tmp2, \tmp2, \tmp1       /* tmp2=Offset address into array */
  ldr  sp, [\tmp2, #0]           /* sp=Address in stack allocation */
  .endm
#endif

/****************************************************************************
 * Name: setfiqstack
 *
 * Description:
 *   Set the current stack pointer to the  -"top" of the FIQ interrupt
 *   stack for the current CPU.
 *
 ****************************************************************************/

#if defined(CONFIG_SMP) && CONFIG_ARCH_INTERRUPTSTACK > 7
  .macro  setfiqstack, tmp1, tmp2
  mrc  p15, 0, \tmp1, c0, c0, 5  /* tmp1=MPIDR */
  and  \tmp1, \tmp1, #3          /* Bits 0-1=CPU ID */
  ldr  \tmp2, =g_fiqstack_top    /* tmp2=Array of FIQ stack pointers */
  lsls \tmp1, \tmp1, #2          /* tmp1=Array byte offset */
  add  \tmp2, \tmp2, \tmp1       /* tmp2=Offset address into array */
  ldr  sp, [\tmp2, #0]           /* sp=Address in stack allocation */
  .endm
#endif

#endif /* __ASSEMBLY__ */

#endif /* __ARCH_ARM_SRC_BES_CHIP_H */
