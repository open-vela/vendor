/****************************************************************************
 * vendor/bes/boards/best1600_ep/src/ap.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <nuttx/config.h>

#ifdef CONFIG_BES2003_CP
#include <stdint.h>
#include <assert.h>
#include <debug.h>
#include <ctype.h>

#include <nuttx/init.h>
#include <nuttx/timers/arch_rtc.h>
#include <nuttx/timers/rpmsg_rtc.h>
#include <arch/board/board.h>
#include "nuttx/sched.h"
#include "sched/sched.h"
#include <sys/mount.h>
#include "arm_internal.h"
#include <sys/boardctl.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "bes_dvfs.h"
#include <stdio.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/
void board_late_initialize(void)
{
   int ret = 0;
#ifdef CONFIG_CPULOAD_ONESHOT
    bes_cpuload_oneshot_initialize(0,100000);
#endif

#ifdef CONFIG_RPTUN
  up_rptun_init_cmcp();
#ifdef CONFIG_FS_HOSTFS_RPMSG
  hostfs_rpmsg_init("ap");
#endif
#endif
}

#include "chip.h"
#define TO_STRING_A(s)                  # s
#define TO_STRING(s)                    TO_STRING_A(s)
extern uint32_t  __cp_StackLimit;
extern uint32_t  __cp_StackTop;
extern unsigned _vectors[];
void __start(void)
{
    const uint32_t *src;
    uint32_t *dest;
    /* Set the stack limit before we attempt to call any functions */
    __asm__ volatile
    (
        "ldr r0, =" TO_STRING(__cp_StackLimit) ";"
        "msr      msplim, r0;"
        "ldr r3, =" TO_STRING(__cp_StackTop) ";"
        "msr msp, r3;"
    );

    /* Clear .bss.  We'll do this inline (vs. calling memset) just to be
    * certain that there are no issues with the state of global variables.
    */

    for (dest = &_sbss; dest < &_ebss; )
    {
        *dest++ = 0;
    }

    /* Move the initialized data section from his temporary holding spot in
    * FLASH into the correct place in SRAM.  The correct place in SRAM is
    * give by _sdata and _edata.  The temporary location is in FLASH at the
    * end of all of the other read-only data (.text, .rodata) at _eronly.
    */

    for (src = &_eronly, dest = &_sdata; dest < &_edata; )
    {
        *dest++ = *src++;
    }
    //NVIC_InitVectors_cp();
    //hal_trace_open_cp();
    NVIC_UpdateVectors_cp((uint32_t)_vectors);
    SystemInit_cp();
#if CONFIG_BES_LPUART
    hal_uart_printf_init();
    hal_uart_printf("system power on....");
#endif
    bes_global_shmem_setup_syslog_buffer();

    nx_start();
    /* Shouldn't get here */
    for (; ; );
}

void bes_chip_init_early()
{
    cp_ipc_init();
    cp_ipc_start();
}

#ifdef CONFIG_RPMSG_UART
void rpmsg_serialinit(void)
{
    uart_rpmsg_init("ap", "CP", 4096, true);
}
#endif

#endif /* CONFIG_BES2003_CP */
