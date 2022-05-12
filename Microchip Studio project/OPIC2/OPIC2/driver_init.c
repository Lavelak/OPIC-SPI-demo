/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hpl_spi_base.h>

/*! The buffer size for USART */
#define USART_0_BUFFER_SIZE 16

struct spi_m_sync_descriptor  SPI_0;
struct usart_async_descriptor USART_0;

static uint8_t USART_0_buffer[USART_0_BUFFER_SIZE];

/**
 * \brief EBI Clock initialization function
 */
void EXTERNAL_BUS_0_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_SDRAMC);
}

/**
 * \brief EBI pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void EXTERNAL_BUS_0_PORT_init()
{

	gpio_set_pin_function(PC20, MUX_PC20A_EBI_A2);

	gpio_set_pin_function(PC21, MUX_PC21A_EBI_A3);

	gpio_set_pin_function(PC22, MUX_PC22A_EBI_A4);

	gpio_set_pin_function(PC23, MUX_PC23A_EBI_A5);

	gpio_set_pin_function(PC24, MUX_PC24A_EBI_A6);

	gpio_set_pin_function(PC25, MUX_PC25A_EBI_A7);

	gpio_set_pin_function(PC26, MUX_PC26A_EBI_A8);

	gpio_set_pin_function(PC27, MUX_PC27A_EBI_A9);

	gpio_set_pin_function(PC28, MUX_PC28A_EBI_A10);

	gpio_set_pin_function(PC29, MUX_PC29A_EBI_A11);

	gpio_set_pin_function(PA20, MUX_PA20C_EBI_BA0);

	gpio_set_pin_function(PD17, MUX_PD17C_EBI_CAS);

	gpio_set_pin_function(PC7, MUX_PC7A_EBI_D7);

	gpio_set_pin_function(PE0, MUX_PE0A_EBI_D8);

	gpio_set_pin_function(PE1, MUX_PE1A_EBI_D9);

	gpio_set_pin_function(PE2, MUX_PE2A_EBI_D10);

	gpio_set_pin_function(PE3, MUX_PE3A_EBI_D11);

	gpio_set_pin_function(PE4, MUX_PE4A_EBI_D12);

	gpio_set_pin_function(PE5, MUX_PE5A_EBI_D13);

	gpio_set_pin_function(PA15, MUX_PA15A_EBI_D14);

	gpio_set_pin_function(PA16, MUX_PA16A_EBI_D15);

	gpio_set_pin_function(PC18, MUX_PC18A_EBI_NBS0);

	gpio_set_pin_function(PD15, MUX_PD15C_EBI_NBS1);

	gpio_set_pin_function(PD16, MUX_PD16C_EBI_RAS);

	gpio_set_pin_function(PD13, MUX_PD13C_EBI_SDA10);

	gpio_set_pin_function(PD23, MUX_PD23C_EBI_SDCK);

	gpio_set_pin_function(PD14, MUX_PD14C_EBI_SDCKE);

	gpio_set_pin_function(PC15, MUX_PC15A_EBI_SDCS);

	gpio_set_pin_function(PD29, MUX_PD29C_EBI_SDWE);
}

/**
 * \brief EBI initialization function
 */
void EXTERNAL_BUS_0_init(void)
{
	EXTERNAL_BUS_0_CLOCK_init();
	EXTERNAL_BUS_0_PORT_init();
	_ext_bus_init();
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_function(PD20, MUX_PD20B_SPI0_MISO);

	gpio_set_pin_function(PD21, MUX_PD21B_SPI0_MOSI);

	gpio_set_pin_function(PD22, MUX_PD22B_SPI0_SPCK);
}

void SPI_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_SPI0);
}

void SPI_0_init(void)
{
	SPI_0_CLOCK_init();
	spi_m_sync_set_func_ptr(&SPI_0, _spi_get_spi_m_sync());
	spi_m_sync_init(&SPI_0, SPI0);
	SPI_0_PORT_init();
}

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_0_CLOCK_init()
{
	_pmc_enable_periph_clock(ID_UART0);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_0_PORT_init()
{

	gpio_set_pin_function(PA9, MUX_PA9A_UART0_URXD0);

	gpio_set_pin_function(PA10, MUX_PA10A_UART0_UTXD0);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_0_init(void)
{
	USART_0_CLOCK_init();
	usart_async_init(&USART_0, UART0, USART_0_buffer, USART_0_BUFFER_SIZE, _uart_get_usart_async());
	USART_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	EXTERNAL_BUS_0_init();

	SPI_0_init();
	USART_0_init();
}
