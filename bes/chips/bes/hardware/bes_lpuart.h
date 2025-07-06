/********************************************************************************************
 * arch/arm/src/bes/hardware/bes_lpuart.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author:  Gregory Nutt <gnutt@nuttx.org>
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
 ********************************************************************************************/

#ifndef __ARCH_ARM_SRC_BES_HARDWARE_BES_LPUART_H
#define __ARCH_ARM_SRC_BES_HARDWARE_BES_LPUART_H

/********************************************************************************************
 * Included Files
 ********************************************************************************************/

#include <nuttx/config.h>

union HAL_UART_IRQ_T {
    struct {
        uint32_t RIM  :1; // ri
        uint32_t CTSM :1; // cts
        uint32_t DCDM :1; // dcd
        uint32_t DSRM :1; // dsr
        uint32_t RX   :1; // rx
        uint32_t TX   :1; // tx
        uint32_t RT   :1; // receive timeout
        uint32_t FE   :1; // framing error
        uint32_t PE   :1; // parity error
        uint32_t BE   :1; // break error
        uint32_t OE   :1; // overrun
    };
    uint32_t reg;
};

int nuttx_uart_close(uint8_t  port_id);
int nuttx_uart_output(const unsigned char *buf, unsigned int buf_len);
uint32_t nuttx_uart_stop_dma_send(uint8_t  port_id);
uint32_t nuttx_uart_rx_dma_stop(uint8_t  port_id);
int nuttx_uart_rx_dma_start(uint8_t  port_id, uint8_t *rx_buffer, uint32_t buff_len, uint32_t *desc_cnt);
typedef void (*nuttx_uart_rxdma_handler_t)(uint32_t xfer_size, int dma_error, union HAL_UART_IRQ_T status);
typedef void (*nuttx_uart_txdma_handler_t)(uint32_t xfer_size, int dma_error);
void nuttx_uart_irq_set_dma_handler(uint8_t  port_id, nuttx_uart_rxdma_handler_t rxdma,nuttx_uart_txdma_handler_t txdma);
bool nuttx_uart_txready(uint8_t  port_id);
bool nuttx_uart_txempty(uint8_t  port_id);
bool nuttx_uart_rxavailable(uint8_t  port_id);
void nuttx_serialout(uint8_t  port_id, uint32_t data);
int nuttx_serial_receive(uint8_t  port_id, uint32_t *status);
int nuttx_uart_enable_txirq(uint8_t port_id, bool isEnable);
int nuttx_uart_enable_rxirq(uint8_t port_id, bool isEnable);
typedef void (*nuttx_uart_irq_handler_t)(uint8_t port_id, uint32_t status);
void nuttx_uart_irq_set_handler(uint8_t port_id, nuttx_uart_irq_handler_t irqhandler);


/********************************************************************************************
 * Pre-processor Definitions
 ********************************************************************************************/
#define bes_LPUART1_BASE   0 
#define bes_LPUART2_BASE   0 
#define bes_LPUART3_BASE   0 
#define bes_IRQ_LPUART1    0
#define bes_IRQ_LPUART2    0
#define bes_IRQ_LPUART3    0

/* Register offsets *************************************************************************/

#define bes_LPUART_UARTRSR_OFFSET        0x004   /*UART read status */
#define bes_LPUART_UARTECR_OFFSET        0x004   /*UART clear status */
#define bes_LPUART_UARTDR_OFFSET         0x000   /*UART Data Register */
#define bes_LPUART_RESERVED_008_OFFSET   0x008   /*UART reserved */
#define bes_LPUART_UARTFR_OFFSET         0x018   /*UART flag  */
#define bes_LPUART_RESERVED_OFFSET       0x01C   /*UART reserved */
#define bes_LPUART_UARTILPR_OFFSET       0x020   /*UART ilp */
#define bes_LPUART_UARTIBRD_OFFSET       0x024   /*UART ibr */
#define bes_LPUART_UARTFBRD_OFFSET       0x028   /*UART fbr */
#define bes_LPUART_UARTLCR_H_OFFSET      0x02C   /*UART line control*/
#define bes_LPUART_UARTCR_OFFSET         0x030   /*UART control */
#define bes_LPUART_UARTIFLS_OFFSET       0x034   /*UART fifo level */
#define bes_LPUART_UARTIMSC_OFFSET       0x038   /*UART mask control */
#define bes_LPUART_UARTRIS_OFFSET        0x03C   /*UART raw interrupt status */
#define bes_LPUART_UARTMIS_OFFSET        0x040   /*UART logic interrupt status */
#define bes_LPUART_UARTICR_OFFSET        0x044   /*UART interrupt control */
#define bes_LPUART_UARTDMACR_OFFSET      0x048   /*UART dma contrl */



/* Register addresses ***********************************************************************/

#define bes_LPUART1_UARTDR           (bes_LPUART1_BASE + bes_LPUART1_UARTDR_OFFSET)  /*UART Data Register */
#define bes_LPUART1_UARTRSR          (bes_LPUART1_BASE + bes_LPUART1_UARTRSR_OFFSET)  /*UART read status */
#define bes_LPUART1_UARTECR          (bes_LPUART1_BASE + bes_LPUART1_UARTECR_OFFSET)  /*UART clear status */
#define bes_LPUART1_RESERVED_008     (bes_LPUART1_BASE + bes_LPUART1_RESERVED_008_OFFSET)  /*UART reserved */
#define bes_LPUART1_UARTFR           (bes_LPUART1_BASE + bes_LPUART1_UARTFR_OFFSET)  /*UART flag  */
#define bes_LPUART1_RESERVED         (bes_LPUART1_BASE + bes_LPUART1_RESERVED_OFFSET)  /*UART reserved */
#define bes_LPUART1_UARTILPR         (bes_LPUART1_BASE + bes_LPUART1_UARTILPR_OFFSET)  /*UART ilp */
#define bes_LPUART1_UARTIBRD         (bes_LPUART1_BASE + bes_LPUART1_UARTIBRD_OFFSET)  /*UART ibr */
#define bes_LPUART1_UARTFBRD         (bes_LPUART1_BASE + bes_LPUART1_UARTFBRD_OFFSET)  /*UART fbr */
#define bes_LPUART1_UARTLCR_H        (bes_LPUART1_BASE + bes_LPUART1_UARTLCR_H_OFFSET)  /*UART line control*/
#define bes_LPUART1_UARTCR           (bes_LPUART1_BASE + bes_LPUART1_UARTCR_OFFSET)  /*UART control */
#define bes_LPUART1_UARTIFLS         (bes_LPUART1_BASE + bes_LPUART1_UARTIFLS_OFFSET)  /*UART fifo level */
#define bes_LPUART1_UARTIMSC         (bes_LPUART1_BASE + bes_LPUART1_UARTIMSC_OFFSET)  /*UART mask control */
#define bes_LPUART1_UARTRIS          (bes_LPUART1_BASE + bes_LPUART1_UARTRIS_OFFSET)  /*UART raw interrupt status */
#define bes_LPUART1_UARTMIS          (bes_LPUART1_BASE + bes_LPUART1_UARTMIS_OFFSET)  /*UART logic interrupt status */
#define bes_LPUART1_UARTICR          (bes_LPUART1_BASE + bes_LPUART1_UARTICR_OFFSET)  /*UART interrupt control */
#define bes_LPUART1_UARTDMACR        (bes_LPUART1_BASE + bes_LPUART1_UARTDMACR_OFFSET)  /*UART dma contrl */

#define bes_LPUART2_UARTDR           (bes_LPUART2_BASE + bes_LPUART2_UARTDR_OFFSET)  /*UART Data Register */
#define bes_LPUART2_UARTRSR          (bes_LPUART2_BASE + bes_LPUART2_UARTRSR_OFFSET)  /*UART read status */
#define bes_LPUART2_UARTECR          (bes_LPUART2_BASE + bes_LPUART2_UARTECR_OFFSET)  /*UART clear status */
#define bes_LPUART2_RESERVED_008     (bes_LPUART2_BASE + bes_LPUART2_RESERVED_008_OFFSET)  /*UART reserved */
#define bes_LPUART2_UARTFR           (bes_LPUART2_BASE + bes_LPUART2_UARTFR_OFFSET)  /*UART flag  */
#define bes_LPUART2_RESERVED         (bes_LPUART2_BASE + bes_LPUART2_RESERVED_OFFSET)  /*UART reserved */
#define bes_LPUART2_UARTILPR         (bes_LPUART2_BASE + bes_LPUART2_UARTILPR_OFFSET)  /*UART ilp */
#define bes_LPUART2_UARTIBRD         (bes_LPUART2_BASE + bes_LPUART2_UARTIBRD_OFFSET)  /*UART ibr */
#define bes_LPUART2_UARTFBRD         (bes_LPUART2_BASE + bes_LPUART2_UARTFBRD_OFFSET)  /*UART fbr */
#define bes_LPUART2_UARTLCR_H        (bes_LPUART2_BASE + bes_LPUART2_UARTLCR_H_OFFSET)  /*UART line control*/
#define bes_LPUART2_UARTCR           (bes_LPUART2_BASE + bes_LPUART2_UARTCR_OFFSET)  /*UART control */
#define bes_LPUART2_UARTIFLS         (bes_LPUART2_BASE + bes_LPUART2_UARTIFLS_OFFSET)  /*UART fifo level */
#define bes_LPUART2_UARTIMSC         (bes_LPUART2_BASE + bes_LPUART2_UARTIMSC_OFFSET)  /*UART mask control */
#define bes_LPUART2_UARTRIS          (bes_LPUART2_BASE + bes_LPUART2_UARTRIS_OFFSET)  /*UART raw interrupt status */
#define bes_LPUART2_UARTMIS          (bes_LPUART2_BASE + bes_LPUART2_UARTMIS_OFFSET)  /*UART logic interrupt status */
#define bes_LPUART2_UARTICR          (bes_LPUART2_BASE + bes_LPUART2_UARTICR_OFFSET)  /*UART interrupt control */
#define bes_LPUART2_UARTDMACR        (bes_LPUART2_BASE + bes_LPUART2_UARTDMACR_OFFSET)  /*UART dma contrl */

#define bes_LPUART3_UARTDR           (bes_LPUART3_BASE + bes_LPUART3_UARTDR_OFFSET)  /*UART Data Register */
#define bes_LPUART3_UARTRSR          (bes_LPUART3_BASE + bes_LPUART3_UARTRSR_OFFSET)  /*UART read status */
#define bes_LPUART3_UARTECR          (bes_LPUART3_BASE + bes_LPUART3_UARTECR_OFFSET)  /*UART clear status */
#define bes_LPUART3_RESERVED_008     (bes_LPUART3_BASE + bes_LPUART3_RESERVED_008_OFFSET)  /*UART reserved */
#define bes_LPUART3_UARTFR           (bes_LPUART3_BASE + bes_LPUART3_UARTFR_OFFSET)  /*UART flag  */
#define bes_LPUART3_RESERVED         (bes_LPUART3_BASE + bes_LPUART3_RESERVED_OFFSET)  /*UART reserved */
#define bes_LPUART3_UARTILPR         (bes_LPUART3_BASE + bes_LPUART3_UARTILPR_OFFSET)  /*UART ilp */
#define bes_LPUART3_UARTIBRD         (bes_LPUART3_BASE + bes_LPUART3_UARTIBRD_OFFSET)  /*UART ibr */
#define bes_LPUART3_UARTFBRD         (bes_LPUART3_BASE + bes_LPUART3_UARTFBRD_OFFSET)  /*UART fbr */
#define bes_LPUART3_UARTLCR_H        (bes_LPUART3_BASE + bes_LPUART3_UARTLCR_H_OFFSET)  /*UART line control*/
#define bes_LPUART3_UARTCR           (bes_LPUART3_BASE + bes_LPUART3_UARTCR_OFFSET)  /*UART control */
#define bes_LPUART3_UARTIFLS         (bes_LPUART3_BASE + bes_LPUART3_UARTIFLS_OFFSET)  /*UART fifo level */
#define bes_LPUART3_UARTIMSC         (bes_LPUART3_BASE + bes_LPUART3_UARTIMSC_OFFSET)  /*UART mask control */
#define bes_LPUART3_UARTRIS          (bes_LPUART3_BASE + bes_LPUART3_UARTRIS_OFFSET)  /*UART raw interrupt status */
#define bes_LPUART3_UARTMIS          (bes_LPUART3_BASE + bes_LPUART3_UARTMIS_OFFSET)  /*UART logic interrupt status */
#define bes_LPUART3_UARTICR          (bes_LPUART3_BASE + bes_LPUART3_UARTICR_OFFSET)  /*UART interrupt control */
#define bes_LPUART3_UARTDMACR        (bes_LPUART3_BASE + bes_LPUART3_UARTDMACR_OFFSET)  /*UART dma contrl */

/* Register bit definitions *****************************************************************/


/* LPUART Pin Configuration Register */

#define LPUART_PINCFG_TRGSEL_SHIFT     (0)       /* Bits 0-1:  Trigger Select */
#define LPUART_PINCFG_TRGSEL_MASK      (3 << LPUART_PINCFG_TRGSEL_SHIFT)
#  define LPUART_PINCFG_TRGSEL_DISABLE (0 << LPUART_PINCFG_TRGSEL_SHIFT) /* Trigger disabled */
#  define LPUART_PINCFG_TRGSEL_RXD     (1 << LPUART_PINCFG_TRGSEL_SHIFT) /* Trigger used instead of RXD pin */
#  define LPUART_PINCFG_TRGSEL_CTSB    (2 << LPUART_PINCFG_TRGSEL_SHIFT) /* Trigger used instead of CTS_B pin */
#  define LPUART_PINCFG_TRGSEL_TXDMOD  (3 << LPUART_PINCFG_TRGSEL_SHIFT) /* Trigger used to modulate the TXD output */
                                                 /* Bits 2-31:  Reserved */

/* LPUART Baud Rate Register */

#define LPUART_BAUD_SBR_SHIFT          (0)       /* Bits 0-12: Baud Rate Modulo Divisor. */
#define LPUART_BAUD_SBR_MASK           (0x1fff << LPUART_BAUD_SBR_SHIFT)
#define LPUART_BAUD_SBR(n)             ((uint32_t)(n) << LPUART_BAUD_SBR_SHIFT)
#define LPUART_BAUD_SBNS               (1 << 13) /* Bit 13: Stop Bit Number Select */
#define LPUART_BAUD_RXEDGIE            (1 << 14) /* Bit 14: RX Input Active Edge Interrupt Enable */
#define LPUART_BAUD_LBKDIE             (1 << 15) /* Bit 15: LIN Break Detect Interrupt Enable */
#define LPUART_BAUD_RESYNCDIS          (1 << 16) /* Bit 16: Resynchronization Disable */
#define LPUART_BAUD_BOTHEDGE           (1 << 17) /* Bit 17: Both Edge Sampling */
#define LPUART_BAUD_MATCFG_SHIFT       (18)      /* Bits 18-19: Match Configuration */
#define LPUART_BAUD_MATCFG_MASK        (3 << LPUART_BAUD_MATCFG_SHIFT)
#define LPUART_BAUD_MATCFG_ADDR      (0 << LPUART_BAUD_MATCFG_SHIFT) /* Address Match Wakeup */
#define LPUART_BAUD_MATCFG_IDLE      (1 << LPUART_BAUD_MATCFG_SHIFT) /* Idle Match Wakeup */
#define LPUART_BAUD_MATCFG_ONOFF     (2 << LPUART_BAUD_MATCFG_SHIFT) /* Match On and Match Off */
#define LPUART_BAUD_MATCFG_RWUENAB   (3 << LPUART_BAUD_MATCFG_SHIFT) /* Enables RWU on Data Match and Match
                                                                        * On/Off for transmitter CTS input */
                                                 /* Bit 20: Reserved */
#define LPUART_BAUD_RDMAE              (1 << 21) /* Bit 21: Receiver Full DMA Enable */
                                                 /* Bit 22: Reserved */
#define LPUART_BAUD_TDMAE              (1 << 23) /* Bit 23: Transmitter DMA Enable */
#define LPUART_BAUD_OSR_SHIFT          (24)      /* Bits 24-28: Oversampling Ratio */
#define LPUART_BAUD_OSR_MASK           (15 << LPUART_BAUD_OSR_SHIFT)
#define LPUART_BAUD_OSR(n)           ((uint32_t)((n) - 1) << LPUART_BAUD_OSR_SHIFT)
#define LPUART_BAUD_M10                (1 << 29) /* Bit 20: 10-bit Mode select */
#define LPUART_BAUD_MAEN2              (1 << 30) /* Bit 30: Match Address Mode Enable 2 */
#define LPUART_BAUD_MAEN1              (1 << 31) /* Bit 31: Match Address Mode Enable 1 */


/* LPUART Trans interrupt Status Register */

#define LPUART_RIM            (1 << 0)  // ri
#define LPUART_CTSM           (1 << 1)  // cts
#define LPUART_DCDM           (1 << 2)  // dcd
#define LPUART_DSRM           (1 << 3)  // dsr
#define LPUART_RX             (1 << 4)  // rx
#define LPUART_TX             (1 << 5)  // tx
#define LPUART_RT             (1 << 6)  // receive timeout
#define LPUART_FE             (1 << 7)  // framing error
#define LPUART_PE             (1 << 8)  // parity error
#define LPUART_BE             (1 << 9)  // break error
#define LPUART_OE             (1 << 10)  // overrun


/* LPUART Status Flag Register */

// Flag reg bits
#define LPUARTFR_RI           (1 << 8)  // Ring indicator
#define LPUARTFR_TXFE         (1 << 7)  // Transmit FIFO empty
#define LPUARTFR_RXFF         (1 << 6)  // Receive  FIFO full
#define LPUARTFR_TXFF         (1 << 5)  // Transmit FIFO full
#define LPUARTFR_RXFE         (1 << 4)  // Receive  FIFO empty
#define LPUARTFR_BUSY         (1 << 3)  // UART busy
#define LPUARTFR_DCD          (1 << 2)  // Data carrier detect
#define LPUARTFR_DSR          (1 << 1)  // Data set ready
#define LPUARTFR_CTS          (1 << 0)  // Clear to send


/* LPUART Control Register */
#define LPUARTCR_CTSEN        (1 << 15) // CTS hardware flow control enable
#define LPUARTCR_RTSEN        (1 << 14) // RTS hardware flow control enable
#define LPUARTCR_RTS          (1 << 11) // Request to send
#define LPUARTCR_DTR          (1 << 10) // Data transmit ready.
#define LPUARTCR_RXE          (1 << 9)  // Receive enable
#define LPUARTCR_TXE          (1 << 8)  // Transmit enable
#define LPUARTCR_LBE          (1 << 7)  // Loopback enable
#define LPUARTCR_UARTEN       (1 << 0)  // UART Enable

#define LPUART_ALL_INTS (LPUARTCR_CTSEN | LPUARTCR_RTSEN | LPUARTCR_RTS |  \
                         LPUARTCR_DTR | LPUARTCR_RXE  | LPUARTCR_TXE |  \
                         LPUARTCR_LBE  | LPUARTCR_UARTEN)

// Line Control Register Bits
#define LPUARTLCR_H_DMA_RT_EN         (1 << 15)
#define LPUARTLCR_H_DMA_RT_CNT(n)     (((n) & 0x7F) << 8)
#define LPUARTLCR_H_DMA_RT_CNT_MASK   (0x7F << 8)
#define LPUARTLCR_H_DMA_RT_CNT_SHIFT  (8)
#define LPUARTLCR_H_SPS               (1 << 7)  // Stick parity select
#define LPUARTLCR_H_WLEN_8            (3 << 5)
#define LPUARTLCR_H_WLEN_7            (2 << 5)
#define LPUARTLCR_H_WLEN_6            (1 << 5)
#define LPUARTLCR_H_WLEN_5            (0 << 5)
#define LPUARTLCR_H_FEN               (1 << 4)  // FIFOs Enable
#define LPUARTLCR_H_STP2              (1 << 3)  // Two stop bits select
#define LPUARTLCR_H_EPS               (1 << 2)  // Even parity select
#define LPUARTLCR_H_PEN               (1 << 1)  // Parity Enable
#define LPUARTLCR_H_BRK               (1 << 0)  // Send break





/* LPUART Data Register */

#define LPUART_DATA_SHIFT              (0)       /* Bits 0-7: Data bits 0-7 */
#define LPUART_DATA_MASK               (0xff << LPUART_DATA_SHIFT)
                                                 /* Bit 10 - 31:  Reserved */


/* LPUART FIFO Register */

#define LPUART_FIFO_RXFIFOSIZE_SHIFT   (0)       /* Bits 0-2: Receive FIFO. Buffer Depth */
#define LPUART_FIFO_RXFIFOSIZE_MASK    (7 << LPUART_FIFO_RXFIFOSIZE_SHIFT)
#  define LPUART_FIFO_RXFIFOSIZE_1     (0 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 1 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_4     (1 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 4 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_8     (2 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 8 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_16    (3 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 16 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_32    (4 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 32 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_64    (5 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 64 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_128   (6 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 128 datawords */
#  define LPUART_FIFO_RXFIFOSIZE_256   (7 << LPUART_FIFO_RXFIFOSIZE_SHIFT) /* 256 datawords */
#define LPUART_FIFO_RXFE               (1 << 3)  /* Bit 3:  Receive FIFO Enable */
#define LPUART_FIFO_TXFIFOSIZE_SHIFT   (3)       /* Bits 4-6: Transmit FIFO. Buffer Depth */
#define LPUART_FIFO_TXFIFOSIZE_MASK    (7 << LPUART_FIFO_TXFIFOSIZE_SHIFT)
#  define LPUART_FIFO_TXFIFOSIZE_1     (0 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 1 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_4     (1 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 4 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_8     (2 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 8 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_16    (3 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 16 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_32    (4 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 32 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_64    (5 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 64 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_128   (6 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 128 datawords */
#  define LPUART_FIFO_TXFIFOSIZE_256   (7 << LPUART_FIFO_TXFIFOSIZE_SHIFT) /* 256 datawords */

#define LPUART_FIFO_TXFE               (1 << 7)  /* Bit 7:  Transmit FIFO Enable */
#define LPUART_FIFO_RXUFE              (1 << 8)  /* Bit 8:  Receive FIFO Underflow Interrupt Enable */
#define LPUART_FIFO_TXOFE              (1 << 9)  /* Bit 9:  Transmit FIFO Overflow Interrupt Enable */
#define LPUART_FIFO_RXIDEN_SHIFT       (10)      /* Bits 10-12:  Receiver Idle Empty Enable */
#define LPUART_FIFO_RXIDEN_MASK        (7 << LPUART_FIFO_RXIDEN_SHIFT)
#  define LPUART_FIFO_RXIDEN_DISABLE   (0 << LPUART_FIFO_RXIDEN_SHIFT) /* Disable RDRF assertion when receiver is idle */
#  define LPUART_FIFO_RXIDEN_1         (1 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 1 word */
#  define LPUART_FIFO_RXIDEN_2         (2 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 2 words */
#  define LPUART_FIFO_RXIDEN_4         (3 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 4 words */
#  define LPUART_FIFO_RXIDEN_8         (4 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 8 words */
#  define LPUART_FIFO_RXIDEN_16        (5 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 16 words */
#  define LPUART_FIFO_RXIDEN_32        (6 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 32 words */
#  define LPUART_FIFO_RXIDEN_64        (7 << LPUART_FIFO_RXIDEN_SHIFT) /* Enable RDRF assertion when receiver idle for 64 words */

#define LPUART_FIFO_RXFLUSH            (1 << 14) /* Bit 14: Receive FIFO/Buffer Flush */
#define LPUART_FIFO_TXFLUSH            (1 << 15) /* Bit 15: Transmit FIFO/Buffer Flush */
#define LPUART_FIFO_RXUF               (1 << 16) /* Bit 16: Receiver Buffer Underflow Flag */
#define LPUART_FIFO_TXOF               (1 << 17) /* Bit 17: Transmitter Buffer Overflow Flag */
                                                 /* Bits 18-21:  Reserved */
#define LPUART_FIFO_RXEMPT             (1 << 22) /* Bit 22: Receive Buffer/FIFO Empty */
#define LPUART_FIFO_TXEMPT             (1 << 23) /* Bit 23: Transmit Buffer/FIFO Empty */
                                                 /* Bits 24-31:  Reserved */

/* LPUART Watermark Register */

#define LPUART_WATER_TXWATER_SHIFT     (0)       /* Bits 0-1: Transmit Watermark */
#define LPUART_WATER_TXWATER_MASK      (3 << LPUART_WATER_TXWATER_SHIFT)
#  define LPUART_WATER_TXWATER(n)      ((uint32_t)(n) << LPUART_WATER_TXWATER_SHIFT)
                                                 /* Bits 2-7:  Reserved */
#define LPUART_WATER_TXCOUNT_SHIFT     (8)       /* Bits 8-10:Transmit Counter */
#define LPUART_WATER_TXCOUNT_MASK      (7 << LPUART_WATER_TXCOUNT_SHIFT)
#  define LPUART_WATER_TXCOUNT(n)      ((uint32_t)(n) << LPUART_WATER_TXCOUNT_SHIFT)
                                                 /* Bits 11-15:  Reserved */
#define LPUART_WATER_RXWATER_SHIFT     (16)      /* Bits 16-17: Receive Watermark */
#define LPUART_WATER_RXWATER_MASK      (3 << LPUART_WATER_RXWATER_SHIFT)
#  define LPUART_WATER_RXWATER(n)      ((uint32_t)(n) << LPUART_WATER_RXWATER_SHIFT)
                                                 /* Bits 18-23:  Reserved */
#define LPUART_WATER_RXCOUNT_SHIFT     (24)      /* Bits 24-26: Receive Counter */
#define LPUART_WATER_RXCOUNT_MASK      (7 << LPUART_WATER_RXCOUNT_SHIFT)
#  define LPUART_WATER_RXCOUNT(n)      ((uint32_t)(n) << LPUART_WATER_RXCOUNT_SHIFT)
                                                 /* Bits 27-31:  Reserved */

#endif /* __ARCH_ARM_SRC_bes_HARDWARE_bes_LPUART_H */
