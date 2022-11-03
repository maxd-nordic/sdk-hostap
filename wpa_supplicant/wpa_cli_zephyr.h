/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef __WPA_CLI_ZEPHYR_H_
#define __WPA_CLI_ZEPHYR_H_

#include <sys/unistd.h>

#include <zephyr/kernel.h>

#include "includes.h"
#include "common/cli.h"
#include "common/wpa_ctrl.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/edit.h"
#include "utils/list.h"
#include "wpa_supplicant_i.h"

int wpa_cli_zephyr_init(struct wpa_supplicant *wpa_s);
void wpa_cli_zephyr_deinit(void);
int wpa_cli_zephyr_cmd(int argc, const char *argv[]);
/* Public data structures - no serialization done, so, non-nested only */
struct add_network_resp {
    int network_id;
};

/* Public APIs */
int wpa_cli_api_add_network(struct add_network_resp *resp);

#endif /* __WPA_CLI_ZEPHYR_H_ */
