/**
 * \file
 *
 * \brief SAM Static Memory Controller
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
 */

#ifndef _HPL_SMC_H_INCLUDED
#define _HPL_SMC_H_INCLUDED

#include <stdint.h>

/**
 * Static Memory Controller peripheral init values
 */
struct _smc_config {
	/* SETUP register value */
	uint32_t setup;
	/* PLUSE register value */
	uint32_t pulse;
	/* CYCLE register value */
	uint32_t cycle;
	/* MODE register value */
	uint32_t mode;
};

/**
 * \brief Enable Scrambling for Static Memory Controller
 *
 * \param[in] key1 Off Chip Memory Scrambling Key Part 1
 * \param[in] key2 Off Chip Memory Scrambling Key Part 2
 */
void _smc_scrambling_enable(const uint32_t key1, const uint32_t key2);

/**
 * \brief Initialize Static Memory for specific Chip Select
 *
 * \param[in] cfg Pointer to static memory configuration struct
 * \param[in] cs  Chip Select Number
 */
void _smc_cs_init(const struct _smc_config *cfg, const uint8_t cs);

/**
 * \brief Enable Scrambling for Static Memory with specific Chip Select
 *
 * \param[in] cs  Chip Select Number
 */
void _smc_cs_scrambling_enable(const uint8_t cs);

#endif /* _HPL_SMC_H_INCLUDED */
