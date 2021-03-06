/*
 * Copyright (C) 2019 Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <vm_config.h>
#include <vuart.h>
#include <pci_dev.h>

struct acrn_vm_config vm_configs[CONFIG_MAX_VM_NUM] = {
	{	/* VM0 */
		CONFIG_SOS_VM,
		.name = "ACRN SOS VM",
		.guest_flags = 0UL,
		.clos = { 0U },
		.memory = {
			.start_hpa = 0UL,
			.size = CONFIG_SOS_RAM_SIZE,
		},
		.os_config = {
			.name = "ACRN Service OS",
			.kernel_type = KERNEL_BZIMAGE,
			.kernel_mod_tag = "Linux_bzImage",
			.bootargs = SOS_VM_BOOTARGS
		},
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = SOS_COM1_BASE,
			.irq = SOS_COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = SOS_COM2_BASE,
			.irq = SOS_COM2_IRQ,
			.t_vuart.vm_id = 2U,
			.t_vuart.vuart_id = 1U,
		},
	},
	{	/* VM1 */
		CONFIG_POST_STD_VM(1),
		.cpu_affinity_bitmap = VM1_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = INVALID_COM_BASE,
		}
	},
	{	/* VM2 */
		CONFIG_POST_RT_VM(1),
		.guest_flags = 0UL,
		.cpu_affinity_bitmap = VM2_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM2_BASE,
			.irq = COM2_IRQ,
			.t_vuart.vm_id = 0U,
			.t_vuart.vuart_id = 1U,
		},
	},
	{	/* VM3 */
		CONFIG_POST_STD_VM(2),
		.cpu_affinity_bitmap = VM3_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = INVALID_COM_BASE,
		}
	},
	{	/* VM4 */
		CONFIG_POST_STD_VM(3),
		.cpu_affinity_bitmap = VM4_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = INVALID_COM_BASE,
		}
	},
	{	/* VM5 */
		CONFIG_POST_STD_VM(4),
		.cpu_affinity_bitmap = VM5_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = INVALID_COM_BASE,
		}
	},
	{	/* VM6 */
		CONFIG_POST_STD_VM(5),
		.cpu_affinity_bitmap = VM6_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = INVALID_COM_BASE,
		}
	},
	{	/* VM7 */
		CONFIG_KATA_VM(1),
		.cpu_affinity_bitmap = VM7_CONFIG_CPU_AFFINITY,
		.vuart[0] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = COM1_BASE,
			.irq = COM1_IRQ,
		},
		.vuart[1] = {
			.type = VUART_LEGACY_PIO,
			.addr.port_base = INVALID_COM_BASE,
		}
	},
};
