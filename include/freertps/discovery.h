#ifndef FREERTPS_DISCOVERY_H
#define FREERTPS_DISCOVERY_H

#include <stdint.h>
#include "freertps/participant.h"

#define FRUDP_PID_PAD                           0x0000
#define FRUDP_PID_SENTINEL                      0x0001
#define FRUDP_PID_PARTICIPANT_LEASE_DURATION    0x0002
#define FRUDP_PID_TOPIC_NAME                    0x0005
#define FRUDP_PID_TYPE_NAME                     0x0007
#define FRUDP_PID_RELIABILITY                   0x001a
#define FRUDP_PID_PROTOCOL_VERSION              0x0015
#define FRUDP_PID_VENDOR_ID                     0x0016
#define FRUDP_PID_RELIABILITY                   0x001a
#define FRUDP_PID_LIVELINESS                    0x001b
#define FRUDP_PID_DURABILITY                    0x001d
#define FRUDP_PID_PRESENTATION                  0x0021
#define FRUDP_PID_PARTITION                     0x0029
#define FRUDP_PID_DEFAULT_UNICAST_LOCATOR       0x0031
#define FRUDP_PID_METATRAFFIC_UNICAST_LOCATOR   0x0032
#define FRUDP_PID_METATRAFFIC_MULTICAST_LOCATOR 0x0033
#define FRUDP_PID_HISTORY                       0x0040
#define FRUDP_PID_DEFAULT_MULTICAST_LOCATOR     0x0048
#define FRUDP_PID_TRANSPORT_PRIORITY            0x0049
#define FRUDP_PID_PARTICIPANT_GUID              0x0050
#define FRUDP_PID_BUILTIN_ENDPOINT_SET          0x0058
#define FRUDP_PID_PROPERTY_LIST                 0x0059
#define FRUDP_PID_ENDPOINT_GUID                 0x005a
#define FRUDP_PID_KEY_HASH                      0x0070

#define FRUDP_BUILTIN_EP_PARTICIPANT_ANNOUNCER           0x00000001
#define FRUDP_BUILTIN_EP_PARTICIPANT_DETECTOR            0x00000002
#define FRUDP_BUILTIN_EP_PUBLICATION_ANNOUNCER           0x00000004
#define FRUDP_BUILTIN_EP_PUBLICATION_DETECTOR            0x00000008
#define FRUDP_BUILTIN_EP_SUBSCRIPTION_ANNOUNCER          0x00000010
#define FRUDP_BUILTIN_EP_SUBSCRIPTION_DETECTOR           0x00000020
#define FRUDP_BUILTIN_EP_PARTICIPANT_PROXY_ANNOUNCER     0x00000040
#define FRUDP_BUILTIN_EP_PARTICIPANT_PROXY_DETECTOR      0x00000080
#define FRUDP_BUILTIN_EP_PARTICIPANT_STATE_ANNOUNCER     0x00000100
#define FRUDP_BUILTIN_EP_PARTICIPANT_STATE_DETECTOR      0x00000200
#define FRUDP_BUILTIN_EP_PARTICIPANT_MESSAGE_DATA_WRITER 0x00000400
#define FRUDP_BUILTIN_EP_PARTICIPANT_MESSAGE_DATA_READER 0x00000800

void frudp_discovery_init();
void frudp_discovery_fini();
void frudp_discovery_tick();

#define FRUDP_DISCOVERY_TX_BUFLEN 4096
extern uint8_t g_frudp_discovery_tx_buf[FRUDP_DISCOVERY_TX_BUFLEN];
extern uint16_t g_frudp_discovery_tx_buf_wpos;

#define FRUDP_DISCOVERY_MAX_PARTICIPANTS 20
extern frudp_participant_t g_frudp_discovery_participants
                                      [FRUDP_DISCOVERY_MAX_PARTICIPANTS];
extern int g_frudp_discovery_num_participants;

#endif
