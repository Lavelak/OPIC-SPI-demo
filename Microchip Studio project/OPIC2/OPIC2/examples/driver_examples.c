/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

/** Memory base address for EBI access example */
#define MEM_BASE SDRAM_CS_ADDR

/*
 * Example of accessing external bus memory
 */
void EXTERNAL_BUS_0_example(void)
{
	volatile uint32_t *pu32 = (uint32_t *)MEM_BASE;
	volatile uint16_t *pu16 = (uint16_t *)MEM_BASE;
	volatile uint8_t * pu8  = (uint8_t *)MEM_BASE;
	/* Backup one WORD */
	uint32_t bak = _ext_bus_read_u32((void *)pu32);
	/* Write and verify BYTE */
	*pu8 = 0xAA;
	if (*pu8 != 0xAA) {
		/* Error ! */
		while (1)
			;
	}
	*pu8 = 0x55;
	if (*pu8 != 0x55) {
		/* Error ! */
		while (1)
			;
	}

	/* Write and verify HALF WORD */
	*pu16 = 0xAAAA;
	if (*pu16 != 0xAAAA) {
		/* Error ! */
		while (1)
			;
	}
	*pu16 = 0x5555;
	if (*pu16 != 0x5555) {
		/* Error ! */
		while (1)
			;
	}

	/* Write and verify WORD */
	*pu32 = 0xAAAA5555;
	if (*pu32 != 0xAAAA5555) {
		/* Error ! */
		while (1)
			;
	}
	*pu32 = 0x5A5A55AA;
	if (*pu32 != 0x5A5A55AA) {
		/* Error ! */
		while (1)
			;
	}
	/* Restore one WORD */
	_ext_bus_write_u32((void *)pu32, bak);
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_0[12] = "Hello World!";

void SPI_0_example(void)
{
	struct io_descriptor *io;
	spi_m_sync_get_io_descriptor(&SPI_0, &io);

	spi_m_sync_enable(&SPI_0);
	io_write(io, example_SPI_0, 12);
	
	io_read(io, example_SPI_0, 12);
}

/**
 * Example of using USART_0 to write "Hello World" using the IO abstraction.
 *
 * Since the driver is asynchronous we need to use statically allocated memory for string
 * because driver initiates transfer and then returns before the transmission is completed.
 *
 * Once transfer has been completed the tx_cb function will be called.
 */

static uint8_t example_USART_0[12] = "Hello World!";

static void tx_cb_USART_0(const struct usart_async_descriptor *const io_descr)
{
	/* Transfer completed */
}

void USART_0_example(void)
{
	struct io_descriptor *io;

	usart_async_register_callback(&USART_0, USART_ASYNC_TXC_CB, tx_cb_USART_0);
	/*usart_async_register_callback(&USART_0, USART_ASYNC_RXC_CB, rx_cb);
	usart_async_register_callback(&USART_0, USART_ASYNC_ERROR_CB, err_cb);*/
	usart_async_get_io_descriptor(&USART_0, &io);
	usart_async_enable(&USART_0);

	io_write(io, example_USART_0, 12);
}
