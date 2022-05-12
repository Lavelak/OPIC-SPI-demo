/**
 * \file
 *
 * \brief External Bus related functionality declaration.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef _HPL_EXT_BUS_H_INCLUDED
#define _HPL_EXT_BUS_H_INCLUDED

/**
 * \addtogroup HPL External Bus
 *
 * \section hpl_ext_bus_rev Revision History
 * - v1.0.0 Initial Release
 *
 *@{
 */

#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \name HPL functions
 */
/*@{*/

/**
 * \brief Initialize external bus interface
 */
void _ext_bus_init(void);

/**
 * \brief Read unsigned 8-bit data from external bus
 * \param[in] addr Pointer to external bus address to read
 * \return unsigned 8-bit data
 */
static inline uint8_t _ext_bus_read_u8(void *addr)
{
	return *(volatile uint8_t *)addr;
}

/**
 * \brief Read unsigned 16-bit data from external bus
 * \param[in] addr Pointer to external bus address to read
 * \return unsigned 16-bit data
 */
static inline uint16_t _ext_bus_read_u16(void *addr)
{
	ASSERT(((uint32_t)addr & 0x1) == 0);
	return *(volatile uint16_t *)addr;
}

/**
 * \brief Read unsigned 32-bit data from external bus
 * \param[in] addr Pointer to external bus address to read
 * \return unsigned 32-bit data
 */
static inline uint32_t _ext_bus_read_u32(void *addr)
{
	ASSERT(((uint32_t)addr & 0x3) == 0);
	return *(volatile uint32_t *)addr;
}

/**
 * \brief Read unsigned 64-bit data from external bus
 * \param[in] addr Pointer to external bus address to read
 * \return unsigned 64-bit data
 */
static inline uint64_t _ext_bus_read_u64(void *addr)
{
	ASSERT(((uint32_t)addr & 0x7) == 0);
	return *(volatile uint64_t *)addr;
}

/**
 * \brief Write unsigned 8-bit data to external bus
 * \param[out] addr Pointer to external bus address to write to
 * \param[in] data To write
 */
static inline void _ext_bus_write_u8(void *addr, const uint8_t data)
{
	*(volatile uint8_t *)addr = data;
}

/**
 * \brief Write unsigned 16-bit data to external bus
 * \param[out] addr Pointer to external bus address to write to
 * \param[in] data To write
 */
static inline void _ext_bus_write_u16(void *addr, const uint16_t data)
{
	ASSERT(((uint32_t)addr & 0x1) == 0);
	*(volatile uint16_t *)addr = data;
}

/**
 * \brief Write unsigned 32-bit data to external bus
 * \param[out] addr Pointer to external bus address to write to
 * \param[in] data To write
 */
static inline void _ext_bus_write_u32(void *addr, const uint32_t data)
{
	ASSERT(((uint32_t)addr & 0x3) == 0);
	*(volatile uint32_t *)addr = data;
}

/**
 * \brief Write unsigned 64-bit data to external bus
 * \param[out] addr Pointer to external bus address to write to
 * \param[in] data To write
 */
static inline void _ext_bus_write_u64(void *addr, const uint64_t data)
{
	ASSERT(((uint32_t)addr & 0x7) == 0);
	*(volatile uint64_t *)addr = data;
}

	/*@}*/

#ifdef __cplusplus
}
#endif
/**@}*/
#endif /* _HPL_EXT_BUS_H_INCLUDED */
