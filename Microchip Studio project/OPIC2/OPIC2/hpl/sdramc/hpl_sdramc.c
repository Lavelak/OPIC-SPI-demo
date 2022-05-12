/**
 * \file
 *
 * \brief SDRAMC related functionality implementation
 *
 * Copyright (C) 2016 - 2017 Atmel Corporation. All rights reserved.
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

#include <hpl_sdramc.h>
#include <utils_assert.h>

void _sdramc_init(const struct _sdramc_config *cfg, const uint32_t clk)
{
	volatile uint32_t  i;
	volatile uint16_t *sdram = (uint16_t *)SDRAM_CS_ADDR;

	ASSERT(cfg);

	hri_matrix_set_CCFG_SMCNFCS_SDRAMEN_bit(MATRIX);
	/* Step 1. */
	/* Set the features of SDRAM device into the Configuration Register */
	hri_sdramc_write_CR_reg(SDRAMC, cfg->cr);
	hri_sdramc_write_CFR1_reg(SDRAMC, cfg->cfr1);

	/* Step 2. */
	/* For low-power SDRAM, Temperature-Compensated Self Refresh (TCSR),
	   Drive Strength (DS) and Partial Array Self Refresh (PASR) must be set
	   in the Low-power Register. */
	hri_sdramc_write_LPR_reg(SDRAMC, cfg->lpr);

	/* Step 3. */
	/* Program the memory device type into the Memory Device Register */
	hri_sdramc_write_MDR_reg(SDRAMC, cfg->mdr);

	/* Step 4. */
	/* A minimum pause of 200 ?s is provided to precede any signal toggle.
	   (6 core cycles per iteration) */
	for (i = 0; i < ((clk / 1000000) * 200 / 6); i++) {
		;
	}

	/* Step 5. */
	/* A NOP command is issued to the SDR-SDRAM. Program NOP command into
	   Mode Register, and the application must set Mode to 1 in the Mode
	   Register. Perform a write access to any SDR-SDRAM address to
	   acknowledge this command. Now the clock which drives SDR-SDRAM
	   device is enabled. */
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_NOP);
	*sdram = 0x0;

	/* Step 6. */
	/* An all banks precharge command is issued to the SDR-SDRAM. Program
	   all banks precharge command into Mode Register, and the application
	   must set Mode to 2 in the Mode Register. Perform a write access to
	   any SDRSDRAM address to acknowledge this command. */
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_ALLBANKS_PRECHARGE);
	*sdram = 0x0;

	/* Add some delays after precharge */
	for (i = 0; i < ((clk / 1000000) * 200 / 6); i++) {
		;
	}

	/* Step 7. */
	/* Eight auto-refresh (CBR) cycles are provided. Program the auto
	   refresh command (CBR) into Mode Register, and the application
	   must set Mode to 4 in the Mode Register. Once in the idle state,
	   eight AUTO REFRESH cycles must be performed. */
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x1;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x2;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x3;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x4;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x5;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x6;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x7;
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_AUTO_REFRESH);
	*sdram = 0x8;

	/* Step 8. */
	/* A Mode Register Set (MRS) cycle is issued to program the parameters
	   of the SDRAM devices, in particular CAS latency and burst length.
	   BA[1..0]: 0x00 */
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_LOAD_MODEREG);
	*((uint16_t *)(sdram + cfg->mcfg.mrs)) = 0xcafe;
	/* Add some delays */
	for (i = 0; i < ((clk / 1000000) * 200 / 6); i++) {
		;
	}

	/* Step 9. */
	/* For low-power SDR-SDRAM initialization, an Extended Mode Register Set
	   (EMRS) cycle is issued to program the SDR-SDRAM parameters (TCSR,
	   PASR, DS). The write address must be chosen so that BA[1] is set to
	   1 and BA[0] is set to 0. */
	if (cfg->mcfg.emrs) {
		hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_EXT_LOAD_MODEREG);
		*((uint16_t *)(sdram + (1 << cfg->mcfg.emrs))) = 0x0;
	}

	/* Step 10. */
	/* The application must go into Normal Mode, setting Mode to 0 in the
	   Mode Register and perform a write access at any location in the\
	   SDRAM to acknowledge this command. */
	hri_sdramc_write_MR_reg(SDRAMC, SDRAMC_MR_MODE_NORMAL);
	*sdram = 0x0;

	/* Step 11. */
	/* Write the refresh rate into the count field in the SDRAMC Refresh
	   Timer register. Set Refresh timer to 15.625 us. */
	i = clk / 1000u;
	i *= 15625u;
	i /= 1000000u;
	SDRAMC->SDRAMC_TR = SDRAMC_TR_COUNT(i);
}

void _sdramc_scrambling_enable(const uint32_t key1, const uint32_t key2)
{
	SDRAMC->SDRAMC_OCMS |= SDRAMC_OCMS_SDR_SE;
	SDRAMC->SDRAMC_OCMS_KEY1 = key1;
	SDRAMC->SDRAMC_OCMS_KEY2 = key2;
}

void _sdramc_scrambling_disable(void)
{
	SDRAMC->SDRAMC_OCMS &= ~SDRAMC_OCMS_SDR_SE;
}
