/****************************************************************************
 * arch/arm/include/bes/debug.h
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

#ifndef __ARCH_ARM_INCLUDE_BES_DEBUG_H
#define __ARCH_ARM_INCLUDE_BES_DEBUG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN extern
#endif
#if defined(CONFIG_ARCH_CHIP_BES2001)
#if defined(CONFIG_GEN_CMCP_BIN)
int hal_uart_printf(const char *fmt, ...);
#ifndef __arch_syslog
#define __arch_syslog(lvl,format, ...)  hal_uart_printf(format,##__VA_ARGS__)
#endif
#else
EXTERN int hal_trace_printf_without_crlf(const char *fmt, ...);

#ifndef __arch_syslog
#define __arch_syslog(lvl,format, ...)  hal_trace_printf_without_crlf(format,##__VA_ARGS__)
#endif
#endif
#else
EXTERN int hal_trace_printf(uint32_t attr, const char *fmt, ...);

#ifndef BITFIELD_VAL
#define BITFIELD_VAL(field, value)          (((value) & (field ## _MASK >> field ## _SHIFT)) << field ## _SHIFT)
#endif

#define TO_STRING_A(s)                  # s
#define TO_STRING(s)                    TO_STRING_A(s)

#ifndef MACRO_CONCAT
#define MACRO_CONCAT_(a, b)             a ## b
#define MACRO_CONCAT(a, b)              MACRO_CONCAT_(a, b)
#endif

#define TR_ATTR_ARG_NUM_SHIFT               0
#define TR_ATTR_ARG_NUM_MASK                (0xF << TR_ATTR_ARG_NUM_SHIFT)
#define TR_ATTR_ARG_NUM(n)                  BITFIELD_VAL(TR_ATTR_ARG_NUM, n)
#define TR_ATTR_LEVEL_SHIFT                 4
#define TR_ATTR_LEVEL_MASK                  (0x7 << TR_ATTR_LEVEL_SHIFT)
#define TR_ATTR_LEVEL(n)                    BITFIELD_VAL(TR_ATTR_LEVEL, n)
#define TR_ATTR_MOD_SHIFT                   7
#define TR_ATTR_MOD_MASK                    (0x7F << TR_ATTR_MOD_SHIFT)
#define TR_ATTR_MOD(n)                      BITFIELD_VAL(TR_ATTR_MOD, n)
#define TR_ATTR_IMM                         (1 << 14)
#define TR_ATTR_NO_LF                       (1 << 15)
#define TR_ATTR_NO_TS                       (1 << 16)
#define TR_ATTR_NO_ID                       (1 << 17)

// Count variadic argument number
#define _VAR_ARG_18(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, ...) a18
#define COUNT_ARG_NUM(...)                  _VAR_ARG_18(unused, ##__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define __trcname                           MACRO_CONCAT(__trc, __LINE__)
#if defined(USE_TRACE_ID)
#define  EXTRA_ARG
#define TRC_SECTION_CONCAT(a, b)            a.b
#define TRC_SECTION_NAME                    TRC_SECTION_CONCAT(.trc_str, __LINE__)
#define TRC_STR_LOC                         __attribute__((section(TO_STRING(TRC_SECTION_NAME))))
#define TRC_STR2(sec, str)                  (({ static const char TRC_STR_LOC __trcname[] = (str); __trcname; }))
#define TRC_STR(str)                        TRC_STR2(TRC_STR_LOC, str)

#ifndef __arch_syslog
#define __arch_syslog(lvl,format, ...)  \
    hal_trace_printf(TR_ATTR_LEVEL(lvl>=7?6:lvl) | TR_ATTR_NO_LF | TR_ATTR_ARG_NUM(COUNT_ARG_NUM(__VA_ARGS__)), TRC_STR(format), ##__VA_ARGS__)
#endif
#else

#ifndef __arch_syslog
#define __arch_syslog(lvl,format, ...)  \
    hal_trace_printf(TR_ATTR_LEVEL(lvl>=7?6:lvl) | TR_ATTR_NO_LF , format, ##__VA_ARGS__)
#endif
#endif

#endif
#endif /* __ARCH_ARM_INCLUDE_BES_DEBUG_H */
