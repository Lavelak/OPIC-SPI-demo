/**
 * \file
 *
 * \brief SAM SDRAM Controller
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

#ifndef _HPL_SDRAMC_H_INCLUDED
#define _HPL_SDRAMC_H_INCLUDED

#include <stdint.h>

struct _sdram_config {
	/** SDRAM Mode Register Set (MRS), A11/BA1=0 and A10/BA0=0 */
	uint16_t mrs;
	/** SDRAM Extended Mode Register Set (EMRS), A11/BA1=0 and A10/BA0=0 */
	uint16_t emrs;
};

struct _sdramc_config {
	/** SDRAM memory configuration */
	struct _sdram_config mcfg;

	/** SDRAMC Configuration Register */
	uint32_t cr;
	/** SDRAMC Low Power Register */
	uint16_t lpr;
	/** SDRAMC Configuration Register 1 */
	uint16_t cfr1;
	/** SDRAMC Low Power Register */
	uint8_t mdr;
};

void _sdramc_init(const struct _sdramc_config *cfg, const uint32_t clk);
void _sdramc_scrambling_enable(const uint32_t key1, const uint32_t key2);
void _sdramc_scrambling_disable(void);

#endif /* _HPL_SDRAMC_H_INCLUDED */
