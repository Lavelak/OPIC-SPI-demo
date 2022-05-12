/* Auto-generated config file hpl_ebi_config.h */
#ifndef HPL_EBI_CONFIG_H
#define HPL_EBI_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Static Memory Configuration
// <e> Initialize Static Memory 0
// <id> conf_smc_0_init_en
#ifndef CONF_SMC_0_INIT_EN
#define CONF_SMC_0_INIT_EN 0
#endif

// <o> NWE Setup Length (NWE_SETUP)  <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_0_nwe_setup
#ifndef CONF_SMC_0_NWE_SETUP
#define CONF_SMC_0_NWE_SETUP 0
#endif

// <o> NCS Setup Length in WRITE access (NCS_WR_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_0_ncs_wr_setup
#ifndef CONF_SMC_0_NCS_WR_SETUP
#define CONF_SMC_0_NCS_WR_SETUP 0
#endif

// <o> NRD Setup Length (NRD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_0_nrd_setup
#ifndef CONF_SMC_0_NRD_SETUP
#define CONF_SMC_0_NRD_SETUP 0
#endif

// <o> NRD Setup Length in READ access (NCS_RD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_0_ncs_rd_setup
#ifndef CONF_SMC_0_NCS_RD_SETUP
#define CONF_SMC_0_NCS_RD_SETUP 0
#endif

// <o> NWE Pulse Length (NWE_PULSE)  <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_0_nwe_pulse
#ifndef CONF_SMC_0_NWE_PULSE
#define CONF_SMC_0_NWE_PULSE 1
#endif

// <o> NCS Pulse Length in WRITE access (NCS_WR_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_0_ncs_wr_pulse
#ifndef CONF_SMC_0_NCS_WR_PULSE
#define CONF_SMC_0_NCS_WR_PULSE 1
#endif

// <o> NRD Pulse Length (NRD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_0_nrd_pulse
#ifndef CONF_SMC_0_NRD_PULSE
#define CONF_SMC_0_NRD_PULSE 1
#endif

// <o> NRD Pulse Length in READ access (NCS_RD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_0_ncs_rd_pulse
#ifndef CONF_SMC_0_NCS_RD_PULSE
#define CONF_SMC_0_NCS_RD_PULSE 1
#endif

// <o> Total Write Cycle Length (NWE_CYCLE)  <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_0_nwe_cycle
#ifndef CONF_SMC_0_NWE_CYCLE
#define CONF_SMC_0_NWE_CYCLE 0
#endif

// <o> Total Read Cycle Length (NRD_CYCLE) <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_0_nrd_cycle
#ifndef CONF_SMC_0_NRD_CYCLE
#define CONF_SMC_0_NRD_CYCLE 0
#endif

// <o> Read Mode
// <0=> Controlled by NCS
// <1=> Controlled by NRD
// <id> conf_smc_0_read_mode
#ifndef CONF_SMC_0_READ_MODE
#define CONF_SMC_0_READ_MODE 0
#endif

// <o> Write Mode
// <0=> Controlled by NCS
// <1=> Controlled by NWE
// <id> conf_smc_0_write_mode
#ifndef CONF_SMC_0_WRITE_MODE
#define CONF_SMC_0_WRITE_MODE 0
#endif

// <o> NWAIT Mode
// <i> Disabled Mode: The NWAIT input signal is ignored on the corresponding Chip Select.
// <i> Frozen Mode: If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.
// <i> Ready Mode: The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.
// <0=> Disabled
// <2=> Frozen
// <3=> Ready
// <id> conf_smc_0_nwait_mode
#ifndef CONF_SMC_0_NWAIT_MODE
#define CONF_SMC_0_NWAIT_MODE 0
#endif

// <o> Byte Access Type
// <i> Byte select access type: Write operation is controlled using NCS, NWE, NBS0, NBS1. Read operation is controlled using NCS, NRD, NBS0, NBS1.
// <i> Byte write access type: Write operation is controlled using NCS, NWR0, NWR1. Read operation is controlled using NCS and NRD.
// <0=> BYTE_SELECT
// <1=> BYTE_WRITE
// <id> conf_smc_0_bat
#ifndef CONF_SMC_0_BAT
#define CONF_SMC_0_BAT 0
#endif

// <o> Data Bus Width
// <0=> 8_BIT
// <1=> 16_BIT
// <id> conf_smc_0_dbw
#ifndef CONF_SMC_0_DBW
#define CONF_SMC_0_DBW 0
#endif

// <o> Data Float Time of cycles <0-15>
// <id> conf_smc_0_tdf_cycles
#ifndef CONF_SMC_0_TDF_CYCLES
#define CONF_SMC_0_TDF_CYCLES 0
#endif

// <o> Data Float Time Optimization
// <i> Disabled: The number of TDF wait states is inserted before the next access begins.
// <i> Enabled: The number of TDF wait states is optimized using the setup period of the next read/write access.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_0_tdf_mode
#ifndef CONF_SMC_0_TDF_MODE
#define CONF_SMC_0_TDF_MODE 0
#endif

// <o> Page Mode Enabled
// <i> Disabled: Standard read is applied
// <i> Enabled: Asynchronous burst read in Page mode is applied on the corresponding chip select.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_0_pmen
#ifndef CONF_SMC_0_PMEN
#define CONF_SMC_0_PMEN 0
#endif

// <o> Page Size (if page mode enabled)
// <0=> 4_BYTE
// <1=> 8_BYTE
// <2=> 16_BYTE
// <3=> 32_BYTE
// <id> conf_smc_0_ps
#ifndef CONF_SMC_0_PS
#define CONF_SMC_0_PS 0
#endif

// <q> CS0 Off-Chip Scrambling Enable
// <id> conf_smc_0_csse
#ifndef CONF_SMC_0_CSSE
#define CONF_SMC_0_CSSE 0
#endif

// </e>
// <e> Initialize Static Memory 1
// <id> conf_smc_1_init_en
#ifndef CONF_SMC_1_INIT_EN
#define CONF_SMC_1_INIT_EN 0
#endif

// <o> NWE Setup Length (NWE_SETUP)  <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_1_nwe_setup
#ifndef CONF_SMC_1_NWE_SETUP
#define CONF_SMC_1_NWE_SETUP 0
#endif

// <o> NCS Setup Length in WRITE access (NCS_WR_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_1_ncs_wr_setup
#ifndef CONF_SMC_1_NCS_WR_SETUP
#define CONF_SMC_1_NCS_WR_SETUP 0
#endif

// <o> NRD Setup Length (NRD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_1_nrd_setup
#ifndef CONF_SMC_1_NRD_SETUP
#define CONF_SMC_1_NRD_SETUP 0
#endif

// <o> NRD Setup Length in READ access (NCS_RD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_1_ncs_rd_setup
#ifndef CONF_SMC_1_NCS_RD_SETUP
#define CONF_SMC_1_NCS_RD_SETUP 0
#endif

// <o> NWE Pulse Length (NWE_PULSE)  <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_1_nwe_pulse
#ifndef CONF_SMC_1_NWE_PULSE
#define CONF_SMC_1_NWE_PULSE 1
#endif

// <o> NCS Pulse Length in WRITE access (NCS_WR_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_1_ncs_wr_pulse
#ifndef CONF_SMC_1_NCS_WR_PULSE
#define CONF_SMC_1_NCS_WR_PULSE 1
#endif

// <o> NRD Pulse Length (NRD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_1_nrd_pulse
#ifndef CONF_SMC_1_NRD_PULSE
#define CONF_SMC_1_NRD_PULSE 1
#endif

// <o> NRD Pulse Length in READ access (NCS_RD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_1_ncs_rd_pulse
#ifndef CONF_SMC_1_NCS_RD_PULSE
#define CONF_SMC_1_NCS_RD_PULSE 1
#endif

// <o> Total Write Cycle Length (NWE_CYCLE)  <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_1_nwe_cycle
#ifndef CONF_SMC_1_NWE_CYCLE
#define CONF_SMC_1_NWE_CYCLE 0
#endif

// <o> Total Read Cycle Length (NRD_CYCLE) <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_1_nrd_cycle
#ifndef CONF_SMC_1_NRD_CYCLE
#define CONF_SMC_1_NRD_CYCLE 0
#endif

// <o> Read Mode
// <0=> Controlled by NCS
// <1=> Controlled by NRD
// <id> conf_smc_1_read_mode
#ifndef CONF_SMC_1_READ_MODE
#define CONF_SMC_1_READ_MODE 0
#endif

// <o> Write Mode
// <0=> Controlled by NCS
// <1=> Controlled by NWE
// <id> conf_smc_1_write_mode
#ifndef CONF_SMC_1_WRITE_MODE
#define CONF_SMC_1_WRITE_MODE 0
#endif

// <o> NWAIT Mode
// <i> Disabled Mode: The NWAIT input signal is ignored on the corresponding Chip Select.
// <i> Frozen Mode: If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.
// <i> Ready Mode: The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.
// <0=> Disabled
// <2=> Frozen
// <3=> Ready
// <id> conf_smc_1_nwait_mode
#ifndef CONF_SMC_1_NWAIT_MODE
#define CONF_SMC_1_NWAIT_MODE 0
#endif

// <o> Byte Access Type
// <i> Byte select access type: Write operation is controlled using NCS, NWE, NBS0, NBS1. Read operation is controlled using NCS, NRD, NBS0, NBS1.
// <i> Byte write access type: Write operation is controlled using NCS, NWR0, NWR1. Read operation is controlled using NCS and NRD.
// <0=> BYTE_SELECT
// <1=> BYTE_WRITE
// <id> conf_smc_1_bat
#ifndef CONF_SMC_1_BAT
#define CONF_SMC_1_BAT 0
#endif

// <o> Data Bus Width
// <0=> 8_BIT
// <1=> 16_BIT
// <id> conf_smc_1_dbw
#ifndef CONF_SMC_1_DBW
#define CONF_SMC_1_DBW 0
#endif

// <o> Data Float Time of cycles <0-15>
// <id> conf_smc_1_tdf_cycles
#ifndef CONF_SMC_1_TDF_CYCLES
#define CONF_SMC_1_TDF_CYCLES 0
#endif

// <o> Data Float Time Optimization
// <i> Disabled: The number of TDF wait states is inserted before the next access begins.
// <i> Enabled: The number of TDF wait states is optimized using the setup period of the next read/write access.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_1_tdf_mode
#ifndef CONF_SMC_1_TDF_MODE
#define CONF_SMC_1_TDF_MODE 0
#endif

// <o> Page Mode Enabled
// <i> Disabled: Standard read is applied
// <i> Enabled: Asynchronous burst read in Page mode is applied on the corresponding chip select.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_1_pmen
#ifndef CONF_SMC_1_PMEN
#define CONF_SMC_1_PMEN 0
#endif

// <o> Page Size (if page mode enabled)
// <0=> 4_BYTE
// <1=> 8_BYTE
// <2=> 16_BYTE
// <3=> 32_BYTE
// <id> conf_smc_1_ps
#ifndef CONF_SMC_1_PS
#define CONF_SMC_1_PS 0
#endif

// <q> CS1 Off-Chip Scrambling Enable
// <id> conf_smc_1_csse
#ifndef CONF_SMC_1_CSSE
#define CONF_SMC_1_CSSE 0
#endif

// </e>
// <e> Initialize Static Memory 2
// <id> conf_smc_2_init_en
#ifndef CONF_SMC_2_INIT_EN
#define CONF_SMC_2_INIT_EN 0
#endif

// <o> NWE Setup Length (NWE_SETUP)  <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_2_nwe_setup
#ifndef CONF_SMC_2_NWE_SETUP
#define CONF_SMC_2_NWE_SETUP 0
#endif

// <o> NCS Setup Length in WRITE access (NCS_WR_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_2_ncs_wr_setup
#ifndef CONF_SMC_2_NCS_WR_SETUP
#define CONF_SMC_2_NCS_WR_SETUP 0
#endif

// <o> NRD Setup Length (NRD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_2_nrd_setup
#ifndef CONF_SMC_2_NRD_SETUP
#define CONF_SMC_2_NRD_SETUP 0
#endif

// <o> NRD Setup Length in READ access (NCS_RD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_2_ncs_rd_setup
#ifndef CONF_SMC_2_NCS_RD_SETUP
#define CONF_SMC_2_NCS_RD_SETUP 0
#endif

// <o> NWE Pulse Length (NWE_PULSE)  <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_2_nwe_pulse
#ifndef CONF_SMC_2_NWE_PULSE
#define CONF_SMC_2_NWE_PULSE 1
#endif

// <o> NCS Pulse Length in WRITE access (NCS_WR_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_2_ncs_wr_pulse
#ifndef CONF_SMC_2_NCS_WR_PULSE
#define CONF_SMC_2_NCS_WR_PULSE 1
#endif

// <o> NRD Pulse Length (NRD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_2_nrd_pulse
#ifndef CONF_SMC_2_NRD_PULSE
#define CONF_SMC_2_NRD_PULSE 1
#endif

// <o> NRD Pulse Length in READ access (NCS_RD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_2_ncs_rd_pulse
#ifndef CONF_SMC_2_NCS_RD_PULSE
#define CONF_SMC_2_NCS_RD_PULSE 1
#endif

// <o> Total Write Cycle Length (NWE_CYCLE)  <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_2_nwe_cycle
#ifndef CONF_SMC_2_NWE_CYCLE
#define CONF_SMC_2_NWE_CYCLE 0
#endif

// <o> Total Read Cycle Length (NRD_CYCLE) <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_2_nrd_cycle
#ifndef CONF_SMC_2_NRD_CYCLE
#define CONF_SMC_2_NRD_CYCLE 0
#endif

// <o> Read Mode
// <0=> Controlled by NCS
// <1=> Controlled by NRD
// <id> conf_smc_2_read_mode
#ifndef CONF_SMC_2_READ_MODE
#define CONF_SMC_2_READ_MODE 0
#endif

// <o> Write Mode
// <0=> Controlled by NCS
// <1=> Controlled by NWE
// <id> conf_smc_2_write_mode
#ifndef CONF_SMC_2_WRITE_MODE
#define CONF_SMC_2_WRITE_MODE 0
#endif

// <o> NWAIT Mode
// <i> Disabled Mode: The NWAIT input signal is ignored on the corresponding Chip Select.
// <i> Frozen Mode: If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.
// <i> Ready Mode: The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.
// <0=> Disabled
// <2=> Frozen
// <3=> Ready
// <id> conf_smc_2_nwait_mode
#ifndef CONF_SMC_2_NWAIT_MODE
#define CONF_SMC_2_NWAIT_MODE 0
#endif

// <o> Byte Access Type
// <i> Byte select access type: Write operation is controlled using NCS, NWE, NBS0, NBS1. Read operation is controlled using NCS, NRD, NBS0, NBS1.
// <i> Byte write access type: Write operation is controlled using NCS, NWR0, NWR1. Read operation is controlled using NCS and NRD.
// <0=> BYTE_SELECT
// <1=> BYTE_WRITE
// <id> conf_smc_2_bat
#ifndef CONF_SMC_2_BAT
#define CONF_SMC_2_BAT 0
#endif

// <o> Data Bus Width
// <0=> 8_BIT
// <1=> 16_BIT
// <id> conf_smc_2_dbw
#ifndef CONF_SMC_2_DBW
#define CONF_SMC_2_DBW 0
#endif

// <o> Data Float Time of cycles <0-15>
// <id> conf_smc_2_tdf_cycles
#ifndef CONF_SMC_2_TDF_CYCLES
#define CONF_SMC_2_TDF_CYCLES 0
#endif

// <o> Data Float Time Optimization
// <i> Disabled: The number of TDF wait states is inserted before the next access begins.
// <i> Enabled: The number of TDF wait states is optimized using the setup period of the next read/write access.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_2_tdf_mode
#ifndef CONF_SMC_2_TDF_MODE
#define CONF_SMC_2_TDF_MODE 0
#endif

// <o> Page Mode Enabled
// <i> Disabled: Standard read is applied
// <i> Enabled: Asynchronous burst read in Page mode is applied on the corresponding chip select.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_2_pmen
#ifndef CONF_SMC_2_PMEN
#define CONF_SMC_2_PMEN 0
#endif

// <o> Page Size (if page mode enabled)
// <0=> 4_BYTE
// <1=> 8_BYTE
// <2=> 16_BYTE
// <3=> 32_BYTE
// <id> conf_smc_2_ps
#ifndef CONF_SMC_2_PS
#define CONF_SMC_2_PS 0
#endif

// <q> CS2 Off-Chip Scrambling Enable
// <id> conf_smc_2_csse
#ifndef CONF_SMC_2_CSSE
#define CONF_SMC_2_CSSE 0
#endif

// </e>
// <e> Initialize Static Memory 3
// <id> conf_smc_3_init_en
#ifndef CONF_SMC_3_INIT_EN
#define CONF_SMC_3_INIT_EN 0
#endif

// <o> NWE Setup Length (NWE_SETUP)  <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_3_nwe_setup
#ifndef CONF_SMC_3_NWE_SETUP
#define CONF_SMC_3_NWE_SETUP 0
#endif

// <o> NCS Setup Length in WRITE access (NCS_WR_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_3_ncs_wr_setup
#ifndef CONF_SMC_3_NCS_WR_SETUP
#define CONF_SMC_3_NCS_WR_SETUP 0
#endif

// <o> NRD Setup Length (NRD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_3_nrd_setup
#ifndef CONF_SMC_3_NRD_SETUP
#define CONF_SMC_3_NRD_SETUP 0
#endif

// <o> NRD Setup Length in READ access (NCS_RD_SETUP) <0x00-0x3F>
// <i> length=(128*Value[5]+Value[4:0] cycles)
// <id> conf_smc_3_ncs_rd_setup
#ifndef CONF_SMC_3_NCS_RD_SETUP
#define CONF_SMC_3_NCS_RD_SETUP 0
#endif

// <o> NWE Pulse Length (NWE_PULSE)  <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_3_nwe_pulse
#ifndef CONF_SMC_3_NWE_PULSE
#define CONF_SMC_3_NWE_PULSE 1
#endif

// <o> NCS Pulse Length in WRITE access (NCS_WR_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_3_ncs_wr_pulse
#ifndef CONF_SMC_3_NCS_WR_PULSE
#define CONF_SMC_3_NCS_WR_PULSE 1
#endif

// <o> NRD Pulse Length (NRD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_3_nrd_pulse
#ifndef CONF_SMC_3_NRD_PULSE
#define CONF_SMC_3_NRD_PULSE 1
#endif

// <o> NRD Pulse Length in READ access (NCS_RD_PULSE) <0x01-0x7F>
// <i> length=(128*Value[6]+Value[5:0] cycles)
// <id> conf_smc_3_ncs_rd_pulse
#ifndef CONF_SMC_3_NCS_RD_PULSE
#define CONF_SMC_3_NCS_RD_PULSE 1
#endif

// <o> Total Write Cycle Length (NWE_CYCLE)  <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_3_nwe_cycle
#ifndef CONF_SMC_3_NWE_CYCLE
#define CONF_SMC_3_NWE_CYCLE 0
#endif

// <o> Total Read Cycle Length (NRD_CYCLE) <0x000-0x1FF>
// <i> length=(128*Value[8:7]+Value[6:0] cycles)
// <id> conf_smc_3_nrd_cycle
#ifndef CONF_SMC_3_NRD_CYCLE
#define CONF_SMC_3_NRD_CYCLE 0
#endif

// <o> Read Mode
// <0=> Controlled by NCS
// <1=> Controlled by NRD
// <id> conf_smc_3_read_mode
#ifndef CONF_SMC_3_READ_MODE
#define CONF_SMC_3_READ_MODE 0
#endif

// <o> Write Mode
// <0=> Controlled by NCS
// <1=> Controlled by NWE
// <id> conf_smc_3_write_mode
#ifndef CONF_SMC_3_WRITE_MODE
#define CONF_SMC_3_WRITE_MODE 0
#endif

// <o> NWAIT Mode
// <i> Disabled Mode: The NWAIT input signal is ignored on the corresponding Chip Select.
// <i> Frozen Mode: If asserted, the NWAIT signal freezes the current read or write cycle. After deassertion, the read/write cycle is resumed from the point where it was stopped.
// <i> Ready Mode: The NWAIT signal indicates the availability of the external device at the end of the pulse of the controlling read or write signal, to complete the access. If high, the access normally completes. If low, the access is extended until NWAIT returns high.
// <0=> Disabled
// <2=> Frozen
// <3=> Ready
// <id> conf_smc_3_nwait_mode
#ifndef CONF_SMC_3_NWAIT_MODE
#define CONF_SMC_3_NWAIT_MODE 0
#endif

// <o> Byte Access Type
// <i> Byte select access type: Write operation is controlled using NCS, NWE, NBS0, NBS1. Read operation is controlled using NCS, NRD, NBS0, NBS1.
// <i> Byte write access type: Write operation is controlled using NCS, NWR0, NWR1. Read operation is controlled using NCS and NRD.
// <0=> BYTE_SELECT
// <1=> BYTE_WRITE
// <id> conf_smc_3_bat
#ifndef CONF_SMC_3_BAT
#define CONF_SMC_3_BAT 0
#endif

// <o> Data Bus Width
// <0=> 8_BIT
// <1=> 16_BIT
// <id> conf_smc_3_dbw
#ifndef CONF_SMC_3_DBW
#define CONF_SMC_3_DBW 0
#endif

// <o> Data Float Time of cycles <0-15>
// <id> conf_smc_3_tdf_cycles
#ifndef CONF_SMC_3_TDF_CYCLES
#define CONF_SMC_3_TDF_CYCLES 0
#endif

// <o> Data Float Time Optimization
// <i> Disabled: The number of TDF wait states is inserted before the next access begins.
// <i> Enabled: The number of TDF wait states is optimized using the setup period of the next read/write access.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_3_tdf_mode
#ifndef CONF_SMC_3_TDF_MODE
#define CONF_SMC_3_TDF_MODE 0
#endif

// <o> Page Mode Enabled
// <i> Disabled: Standard read is applied
// <i> Enabled: Asynchronous burst read in Page mode is applied on the corresponding chip select.
// <0=> Disabled
// <1=> Enabled
// <id> conf_smc_3_pmen
#ifndef CONF_SMC_3_PMEN
#define CONF_SMC_3_PMEN 0
#endif

// <o> Page Size (if page mode enabled)
// <0=> 4_BYTE
// <1=> 8_BYTE
// <2=> 16_BYTE
// <3=> 32_BYTE
// <id> conf_smc_3_ps
#ifndef CONF_SMC_3_PS
#define CONF_SMC_3_PS 0
#endif

// <q> CS3 Off-Chip Scrambling Enable
// <id> conf_smc_3_csse
#ifndef CONF_SMC_3_CSSE
#define CONF_SMC_3_CSSE 0
#endif

// </e>

// <e> Static Memory Off-Chip Scrambling Enable
// <id> conf_smc_smse
#ifndef CONF_SMC_SMSE
#define CONF_SMC_SMSE 0
#endif

// <o> Static Memory Scrambling KEY1 <0x00000000-0xFFFFFFFF>
// <id> conf_smc_key1
#ifndef CONF_SMC_KEY1
#define CONF_SMC_KEY1 0x0
#endif

// <o> Static Memory Scrambling KEY2 <0x00000000-0xFFFFFFFF>
// <id> conf_smc_key2
#ifndef CONF_SMC_KEY2
#define CONF_SMC_KEY2 0x0
#endif

// </e>
// </h>

// <h> SDRAM Configuration
// <e> Initialize SDRAM
// <id> conf_sdram_init_en
#ifndef CONF_SDRAM_INIT_EN
#define CONF_SDRAM_INIT_EN 1
#endif

// <o> Number of Column Bits
// <0=> 8
// <1=> 9
// <2=> 10
// <3=> 11
// <id> conf_sdram_nc
#ifndef CONF_SDRAM_NC
#define CONF_SDRAM_NC 0
#endif

// <o> Number of Row Bits
// <0=> 11
// <1=> 12
// <2=> 13
// <id> conf_sdram_nr
#ifndef CONF_SDRAM_NR
#define CONF_SDRAM_NR 0
#endif

// <o> Number of Banks
// <0=> 2
// <1=> 4
// <id> conf_sdram_nb
#ifndef CONF_SDRAM_NB
#define CONF_SDRAM_NB 0
#endif

// <o> CAS Latency (cycles)
// <1=> 1
// <2=> 2
// <3=> 3
// <id> conf_sdram_cas
#ifndef CONF_SDRAM_CAS
#define CONF_SDRAM_CAS 2
#endif

// <o> Data Bus Width (bits)
// <1=> 16
// <id> conf_sdram_dbw
#ifndef CONF_SDRAM_DBW
#define CONF_SDRAM_DBW 1
#endif

// <o> Write Recovery Delay (cycles) <0-15>
// <id> conf_sdram_twr
#ifndef CONF_SDRAM_TWR
#define CONF_SDRAM_TWR 5
#endif

// <o> Row Cycle Delay and Row Refresh Cycle (cycles) <0-15>
// <id> conf_sdram_trc_trfc
#ifndef CONF_SDRAM_TRC_TRFC
#define CONF_SDRAM_TRC_TRFC 13
#endif

// <o> Row Precharge Delay (cycles) <0-15>
// <id> conf_sdram_trp
#ifndef CONF_SDRAM_TRP
#define CONF_SDRAM_TRP 5
#endif

// <o> Row to Column Delay (cycles) <0-15>
// <id> conf_sdram_trcd
#ifndef CONF_SDRAM_TRCD
#define CONF_SDRAM_TRCD 5
#endif

// <o> Active to Precharge Delay (cycles) <0-15>
// <id> conf_sdram_tras
#ifndef CONF_SDRAM_TRAS
#define CONF_SDRAM_TRAS 9
#endif

// <o> Exit Self Refresh to Active Delay (cycles) <0-15>
// <id> conf_sdram_txsr
#ifndef CONF_SDRAM_TXSR
#define CONF_SDRAM_TXSR 15
#endif

// <h> Low Power Configuration
// <o> Low Power Configuration
// <0=> DISABLED
// <1=> SELF_REFRESH
// <2=> POWER_DOWN
// <3=> DEEP_POWER_DOWN
// <i> DEEP_POWER_DOWN is unique to low-power SDRAM
// <id> conf_sdram_lpcb
#ifndef CONF_SDRAM_LPCB
#define CONF_SDRAM_LPCB 0
#endif

// <o> Time to Define When Low-power Mode is Enabled
// <0=> After the end of the last transfer
// <1=> 64 clock cycles after the end of the last transfer
// <2=> 128 clock cycles after the end of the last transfer
// <id> conf_sdram_timeout
#ifndef CONF_SDRAM_TIMEOUT
#define CONF_SDRAM_TIMEOUT 0
#endif

// <e> Use Low-power SDRAM
// <id> conf_sdram_lpsdram
#ifndef CONF_SDRAM_LPSDRAM
#define CONF_SDRAM_LPSDRAM 0
#endif

#ifndef CONF_SDRAM_MD
#define CONF_SDRAM_MD (CONF_SDRAM_LPSDRAM)
#endif

// <o> Partial Array Self-refresh (PASR) <0x0-0x7>
// <i> This feature is not supported when SDRAMC shares an external bus with another controller.
// <id> conf_sdram_pasr
#ifndef CONF_SDRAM_PASR
#define CONF_SDRAM_PASR 0
#endif

// <o> Temperature Compensated Self-Refresh (TCSR) <0x0-0x3>
// <i> This feature is not supported when SDRAMC shares an external bus with another controller.
// <id> conf_sdram_tcsr
#ifndef CONF_SDRAM_TCSR
#define CONF_SDRAM_TCSR 0
#endif

// <o> Drive Strength (DS) <0x0-0x4>
// <i> This feature is not supported when SDRAMC shares an external bus with another controller.
// <id> conf_sdram_ds
#ifndef CONF_SDRAM_DS
#define CONF_SDRAM_DS 0
#endif

// </e>
// </h>

// <o> Time between Load Mode Register Cmd to Active or Refresh Command (cycles) <0-15>
// <id> conf_sdram_tmrd
#ifndef CONF_SDRAM_TMRD
#define CONF_SDRAM_TMRD 2
#endif

// <o> Unaligned Access
// <0=> UNSUPPORTED
// <1=> SUPPORTED
// <i> This mode is enabled with masters which have an AXI interface.
// <id> conf_sdram_unal
#ifndef CONF_SDRAM_UNAL
#define CONF_SDRAM_UNAL 1
#endif

// </e>

// <e> SDRAM Off-Chip Scrambling Enable
// <id> conf_sdram_smse
#ifndef CONF_SDRAM_SMSE
#define CONF_SDRAM_SMSE 0
#endif

// <o> SDRAM Scrambling KEY1 <0x00000000-0xFFFFFFFF>
// <id> conf_sdram_key1
#ifndef CONF_SDRAM_KEY1
#define CONF_SDRAM_KEY1 0x0
#endif

// <o> SDRAM Scrambling KEY2 <0x00000000-0xFFFFFFFF>
// <id> conf_sdram_key2
#ifndef CONF_SDRAM_KEY2
#define CONF_SDRAM_KEY2 0x0
#endif

// </e>

// <e> Advanced Settings
// <id> conf_sdram_advanced_settings
#ifndef CONF_SDRAM_ADVANCED_SETTINGS
#define CONF_SDRAM_ADVANCED_SETTINGS 0
#endif

// <h> SDRAM Mode Register Set (MRS) value
// <o.0..2> Bust length (BL)
// <0x0=> 1
// <0x1=> 2
// <0x2=> 4
// <0x3=> 8
// <i> A0..2 (BA1/A11=0 and BA0/A10=0)
// <id> conf_sdram_mrs_bl
#ifndef CONF_SDRAM_MRS_BL
#define CONF_SDRAM_MRS_BL 0x2
#endif

// <o.3> Bust Type (BT)
// <0x0=> Sequential
// <0x1=> Interleaved
// <i> A3 (BA1/A11=0 and BA0/A10=0)
// <id> conf_sdram_mrs_bt
#ifndef CONF_SDRAM_MRS_BT
#define CONF_SDRAM_MRS_BT 0x0
#endif

// <o.4..6> CAS Latency
// <0x2=> 2
// <0x3=> 3
// <0x6=> 2.5
// <i> A4..6 (BA1/A11=0 and BA0/A10=0)
// <i> CAS Latency 3 is for DDR400 only
// <id> conf_sdram_mrs_lmode
#ifndef CONF_SDRAM_MRS_LMODE
#define CONF_SDRAM_MRS_LMODE 0x20
#endif

// <o.9> Write Burst Mode
// <0x0=> Use the read burst length and mode
// <0x1=> Non-bust (single location)
// <i> A9 (BA1/A11=0 and BA0/A10=0)
// <id> conf_sdram_mrs_wrburstmode
#ifndef CONF_SDRAM_MRS_WRBURSTMODE
#define CONF_SDRAM_MRS_WRBURSTMODE 0x0
#endif

// </h>

// <h> SDRAM Extended Mode Register Set (EMRS) value

// <o.0..2> Self Refresh Coverage
// <0x0=> All Banks
// <0x1=> One Bank (A11=0)
// <0x5=> Half of One Bank (A11=0, Row Address MSB=0)
// <0x6=> Quarter of One Bank (A11=0, Row Address 2 MSB=0)
// <i> A0..2 (BA1/A11=1 and BA0/A10=0)
// <id> conf_sdram_emrs_pasr
#ifndef CONF_SDRAM_EMRS_PASR
#define CONF_SDRAM_EMRS_PASR 0x0
#endif

// <o.3..4> Maximum Case Temp.
// <0x0=> 85
// <0x1=> 70
// <0x2=> 45
// <0x3=> Auto
// <i> A3..4 (BA1/A11=1 and BA0/A10=0)
// <id> conf_sdram_emrs_tcsr
#ifndef CONF_SDRAM_EMRS_TCSR
#define CONF_SDRAM_EMRS_TCSR 0x0
#endif

// <o.5..6> Driver Strength
// <0x0=> Full Strength
// <0x1=> 1/2 Strength
// <0x2=> 1/4 Strength
// <i> A5..6 (BA1/A11=1 and BA0/A10=0)
// <id> conf_sdram_emrs_ds
#ifndef CONF_SDRAM_EMRS_DS
#define CONF_SDRAM_EMRS_DS 0x0
#endif

// </h>
// </e>
// </h>

// <<< end of configuration section >>>

#endif // HPL_EBI_CONFIG_H
