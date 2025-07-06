/****************************************************************************
 * vendor/bes/boards/best1600_ep/src/audio.c
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

#ifdef CONFIG_BES1600_AUDIO

#include <nuttx/cache.h>
#include <nuttx/serial/uart_rpmsg.h>
#include "hal_dma.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: board_late_initialize
 *
 * Description:
 *   If CONFIG_BOARD_LATE_INITIALIZE is selected, then an additional
 *   initialization call will be performed in the boot-up sequence to a
 *   function called board_late_initialize().  board_late_initialize() will
 *   be called immediately after up_initialize() is called and just before
 *   the initial application is started.  This additional initialization
 *   phase may be used, for example, to initialize board-specific device
 *   drivers.
 *
 ****************************************************************************/

#ifdef CONFIG_BOARD_LATE_INITIALIZE
void board_late_initialize(void)
{
  /* Perform board-specific initialization */
#ifdef CONFIG_RPTUN
#if defined(CONFIG_BES_RPTUN_M552HIFI)
  up_rptun_init_m552hifi();
#endif
#if defined(CONFIG_BES_RPTUN_HIFI2BTH)
  up_rptun_init_hifi2bth();
#endif
#endif

#if defined(CONFIG_HIFI4_USE_AUDMA)
  hal_audma_open();
  af_open();
#endif
}
#endif /* CONFIG_BOARD_LATE_INITIALIZE */

#ifdef CONFIG_RPMSG_UART
void rpmsg_serialinit(void)
{
#ifdef CONFIG_BES_RPTUN_M552HIFI
#ifdef CONFIG_BES_GEN_HIFI_BIN
    uart_rpmsg_init("ap", "AUDIO", 4096, true);
#else
    uart_rpmsg_init("audio", "AUDIO", 4096, false);
#endif
#endif
}
#endif

int board_app_initialize(uintptr_t arg)
{

}

#ifdef CONFIG_BOARD_EARLY_INITIALIZE
void board_early_initialize()
{
#if defined(CONFIG_CALIB_SLOW_TIMER)
  hal_sys_timer_calib();
#endif
#if !defined(CONFIG_USE_SLOW_TIMER)
  hwtimer_init();
#endif
#ifdef CONFIG_XTENSA_ICACHE
  up_enable_icache();
#endif
#ifdef CONFIG_XTENSA_DCACHE
  up_enable_dcache();
#endif
  bes_xtansa_mpu_init();

#if 1//def USE_EARLYSERIALINIT
  bes_earlyserialinit();
#endif

#if defined(CONFIG_AUDIO_RPMSG_CLIENT)
  rpmsg_audio_initialize(0);
#endif
#if defined(CONFIG_WATCHDOG)
  bes_wdt_initialize();
#endif
}
#endif

#endif /* CONFIG_BES1600_AUDIO */
