#include <compiler.h>
#include <hpl_smc.h>
#include <utils_assert.h>

void _smc_scrambling_enable(const uint32_t key1, const uint32_t key2)
{
	hri_smc_write_KEY1_reg(SMC, key1);
	hri_smc_write_KEY2_reg(SMC, key2);
	hri_smc_set_OCMS_SMSE_bit(SMC);
}

void _smc_cs_init(const struct _smc_config *cfg, const uint8_t cs)
{
	ASSERT(cfg && (cs < 4));

	hri_smc_write_SETUP_reg(SMC, cs, cfg->setup);
	hri_smc_write_PULSE_reg(SMC, cs, cfg->pulse);
	hri_smc_write_CYCLE_reg(SMC, cs, cfg->cycle);
	hri_smc_write_MODE_reg(SMC, cs, cfg->mode);
}

void _smc_cs_scrambling_enable(const uint8_t cs)
{
	ASSERT(cs < 4);

	hri_smc_set_OCMS_reg(SMC, SMC_OCMS_CS0SE << cs);
}
