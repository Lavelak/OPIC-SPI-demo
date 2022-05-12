/**
 * \file
 *
 * \brief HPL initialization related functionality implementation.
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

#include <hpl_ebi_config.h>
#include <hpl_ext_bus.h>
#include <hpl_sdramc.h>
#include <hpl_smc.h>
#include <peripheral_clk_config.h>

#define _SMC_SETUP(n)                                                                                                  \
	(SMC_SETUP_NCS_RD_SETUP(CONF_SMC_##n##_NCS_RD_SETUP) | SMC_SETUP_NRD_SETUP(CONF_SMC_##n##_NRD_SETUP)               \
	 | SMC_SETUP_NCS_WR_SETUP(CONF_SMC_##n##_NCS_WR_SETUP) | SMC_SETUP_NWE_SETUP(CONF_SMC_##n##_NWE_SETUP))

#define _SMC_PULSE(n)                                                                                                  \
	(SMC_PULSE_NCS_RD_PULSE(CONF_SMC_##n##_NCS_RD_PULSE) | SMC_PULSE_NRD_PULSE(CONF_SMC_##n##_NRD_PULSE)               \
	 | SMC_PULSE_NCS_WR_PULSE(CONF_SMC_##n##_NCS_WR_PULSE) | SMC_PULSE_NWE_PULSE(CONF_SMC_##n##_NWE_PULSE))

#define _SMC_CYCLE(n) (SMC_CYCLE_NRD_CYCLE(CONF_SMC_##n##_NRD_CYCLE) | SMC_CYCLE_NWE_CYCLE(CONF_SMC_##n##_NWE_CYCLE))

#define _SMC_MODE(n)                                                                                                   \
	(SMC_MODE_PS(CONF_SMC_##n##_PS) | (CONF_SMC_##n##_PMEN << SMC_MODE_PMEN_Pos)                                       \
	 | (CONF_SMC_##n##_TDF_MODE << SMC_MODE_TDF_MODE_Pos) | SMC_MODE_TDF_CYCLES(CONF_SMC_##n##_TDF_CYCLES)             \
	 | (CONF_SMC_##n##_DBW << SMC_MODE_DBW_Pos) | (CONF_SMC_##n##_BAT << SMC_MODE_BAT_Pos)                             \
	 | SMC_MODE_EXNW_MODE(CONF_SMC_##n##_NWAIT_MODE) | (CONF_SMC_##n##_WRITE_MODE << SMC_MODE_WRITE_MODE_Pos)          \
	 | (CONF_SMC_##n##_READ_MODE << SMC_MODE_READ_MODE_Pos))

#define _SDRAMC_MRS (CONF_SDRAM_MRS_BL | CONF_SDRAM_MRS_BT | CONF_SDRAM_MRS_LMODE | CONF_SDRAM_MRS_WRBURSTMODE)
#define _SDRAMC_EMRS (CONF_SDRAM_EMRS_PASR | CONF_SDRAM_EMRS_TCSR | CONF_SDRAM_EMRS_DS)
#define _SDRAMC_CR                                                                                                     \
	(SDRAMC_CR_TXSR((uint32_t)CONF_SDRAM_TXSR) | SDRAMC_CR_TRAS(CONF_SDRAM_TRAS) | SDRAMC_CR_TRCD(CONF_SDRAM_TRCD)     \
	 | SDRAMC_CR_TRP(CONF_SDRAM_TRP) | SDRAMC_CR_TRC_TRFC(CONF_SDRAM_TRC_TRFC) | SDRAMC_CR_TWR(CONF_SDRAM_TWR)         \
	 | (CONF_SDRAM_DBW << SDRAMC_CR_DBW_Pos) | SDRAMC_CR_CAS(CONF_SDRAM_CAS) | (CONF_SDRAM_NB << SDRAMC_CR_NB_Pos)     \
	 | SDRAMC_CR_NR(CONF_SDRAM_NR) | SDRAMC_CR_NC(CONF_SDRAM_NC))
#define _SDRAMC_LPR                                                                                                    \
	(SDRAMC_LPR_TIMEOUT(CONF_SDRAM_TIMEOUT) | SDRAMC_LPR_DS(CONF_SDRAM_DS) | SDRAMC_LPR_TCSR(CONF_SDRAM_TCSR)          \
	 | SDRAMC_LPR_PASR(CONF_SDRAM_PASR) | SDRAMC_LPR_LPCB(CONF_SDRAM_LPCB))
#define _SDRAMC_MDR (CONF_SDRAM_MD)
#define _SDRAMC_CFR1 ((CONF_SDRAM_UNAL << SDRAMC_CFR1_UNAL_Pos) | SDRAMC_CFR1_TMRD(CONF_SDRAM_TMRD))

#if CONF_SMC_0_INIT_EN
static const struct _smc_config smc_cfg0 = {_SMC_SETUP(0), _SMC_PULSE(0), _SMC_CYCLE(0), _SMC_MODE(0)};
#endif
#if CONF_SMC_1_INIT_EN
static const struct _smc_config smc_cfg1 = {_SMC_SETUP(1), _SMC_PULSE(1), _SMC_CYCLE(1), _SMC_MODE(1)};
#endif
#if CONF_SMC_2_INIT_EN
static const struct _smc_config smc_cfg2 = {_SMC_SETUP(2), _SMC_PULSE(2), _SMC_CYCLE(2), _SMC_MODE(2)};
#endif
#if CONF_SMC_3_INIT_EN
static const struct _smc_config smc_cfg3 = {_SMC_SETUP(3), _SMC_PULSE(3), _SMC_CYCLE(3), _SMC_MODE(3)};
#endif

#if CONF_SDRAM_INIT_EN
static const struct _sdramc_config sdram_cfg
    = {{_SDRAMC_MRS, _SDRAMC_EMRS}, _SDRAMC_CR, _SDRAMC_LPR, _SDRAMC_CFR1, _SDRAMC_MDR};
#endif

void _ext_bus_init(void)
{
#if CONF_SMC_SMSE
	_smc_scrambling_enable(CONF_SMC_KEY1, CONF_SMC_KEY2);
#endif

#if CONF_SMC_0_INIT_EN
	_smc_cs_init(&smc_cfg0, 0);
#if CONF_SMC_0_CSSE
	_smc_cs_scrambling_enable(0);
#endif
#endif

#if CONF_SMC_1_INIT_EN
	_smc_cs_init(&smc_cfg1, 1);
#if CONF_SMC_1_CSSE
	_smc_cs_scrambling_enable(1);
#endif
#endif

#if CONF_SMC_2_INIT_EN
	_smc_cs_init(&smc_cfg2, 2);
#if CONF_SMC_2_CSSE
	_smc_cs_scrambling_enable(2);
#endif
#endif

#if CONF_SMC_3_INIT_EN
	_smc_cs_init(&smc_cfg3, 3);
#if CONF_SMC_3_CSSE
	_smc_cs_scrambling_enable(3);
#endif
#endif

#if CONF_SDRAM_INIT_EN
	_sdramc_init(&sdram_cfg, CONF_MCK_FREQUENCY);
#if CONF_SDRAM_SMSE
	_sdramc_scrambling_enable(CONF_SDRAM_KEY1, CONF_SDRAM_KEY2);
#endif
#endif
}
