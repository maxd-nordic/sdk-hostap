/*
 * Copyright (c) 2022 Nordic Semiconductor
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 *
 */

#ifndef ZEPHYR_SUPP_MGMT_H
#define ZEPHYR_SUPP_MGMT_H

#include <zephyr/net/wifi_mgmt.h>

#define MAX_SSID_LEN 32
#define MAC_ADDR_LEN 6

/**
 * @brief Request a connection
 *
 * @param iface_name: Wi-Fi interface name to use
 * @param params: Connection details
 *
 * @return: 0 for OK; -1 for ERROR
 */
int zephyr_supp_connect(const struct device *dev,
						struct wifi_connect_req_params *params);
/**
 * @brief Forces station to disconnect and stops any subsequent scan
 *  or connection attempts
 *
 * @param iface_name: Wi-Fi interface name to use
 *
 * @return: 0 for OK; -1 for ERROR
 */
int zephyr_supp_disconnect(const struct device *dev);

/**
 * @brief Add a network to wpa_supplicant's list of configured networks.
 * 
 * @param dev Wi-Fi interface to use
 * @param params Network details
 * @return 0 on success, negative error code on failure
 */
int zephyr_supp_add_network(const struct device *dev,
			    struct wifi_connect_req_params *params);

/**
 * @brief Remove a network from wpa_supplicant's list of configured networks.
 * @note This will disconnect if the currently connected network is to be removed.
 * 
 * @param dev Wi-Fi interface to use
 * @param params Network details or NULL to remove all networks
 * @return 0 on success, negative error code on failure
 */

int zephyr_supp_remove_network(const struct device *dev,
			       struct wifi_connect_req_params *params);

/**
 * @brief Connect to any configured network and reconnect if necessary.
 * 
 * @param dev Wi-Fi interface to use
 * @return 0 on success, negative error code on failure
 */
int zephyr_supp_request_connection(const struct device *dev);

/**
 * @brief
 *
 * @param iface_name: Wi-Fi interface name to use
 * @param wifi_iface_status: Status structure to fill
 * 
 * @return: 0 for OK; -1 for ERROR
 */
int zephyr_supp_status(const struct device *dev,
	struct wifi_iface_status *status);
#endif /* ZEPHYR_SUPP_MGMT_H */
