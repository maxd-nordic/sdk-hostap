/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef __WPA_CLI_ZEPHYR_H_
#define __WPA_CLI_ZEPHYR_H_

#include <sys/unistd.h>

#include <zephyr/kernel.h>
#include <stdint.h>

#ifdef WPA_SUPPLICANT_I_H

int wpa_cli_zephyr_init(struct wpa_supplicant *wpa_s);
void wpa_cli_zephyr_deinit(void);

#endif /* WPA_SUPPLICANT_I_H */

int wpa_cli_zephyr_cmd(int argc, const char *argv[]);
/* Public data structures - no serialization done, so, non-nested only */
struct add_network_resp {
    int network_id;
};

/* Public APIs */
int wpa_cli_api_add_network(struct add_network_resp *resp);
int wpa_cli_api_set_network_ssid(int network_id, char *ssid);
int wpa_cli_api_set_network_psk(int network_id, char *psk);
int wpa_cli_api_set_network_sae_password(int network_id, char *sae_password);
int wpa_cli_api_set_network_type(int network_id, const char *type);
int wpa_cli_api_set_network_bssid(int network_id, uint8_t *mac);
int wpa_cli_api_set_network_favorite(int network_id);
int wpa_cli_api_set_network_band_2_4_GHz(int network_id);
int wpa_cli_api_set_network_band_5_GHz(int network_id);
int wpa_cli_api_remove_network(int network_id);
int wpa_cli_api_remove_all_networks(void);
int wpa_cli_api_enable_network(int network_id);
int wpa_cli_api_request_connection(void);


#endif /* __WPA_CLI_ZEPHYR_H_ */
