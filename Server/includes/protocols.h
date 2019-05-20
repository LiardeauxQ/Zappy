/*
** EPITECH PROJECT, 2018
** protocols
** File description:
** protocols
*/

#pragma once

#include <stdint.h>

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * DANGLING_HANDLER -> Handler function is NULL
*/
enum HANDLING_ERRORS {
    NO_ERROR                = 0,
    TOO_FEW_PARAMETERS      = 1,
    TOO_MUCH_PARAMETERS     = 2,
    INVALID_PARAMETERS      = 3,
    DANGLING_HANDLER        = 4
};

/*
 * Enumeration of all base messages
 * for the Graphic Protocol
*/

enum GRAPHIC_PACKETS_FROM_CLIENT {
/*
 * Usable to determine the degree of change of a client.
*/
    CLT_PROTOCOL_ADDONS     = 1,
/*
 * Base Zappy commands.
*/
    CLT_MAP_SIZE            = 2,
    CLT_TILE_CONTENT        = 3,
    CLT_MAP_CONTENT         = 4,
    CLT_TEAMS_NAMES         = 5,
    CLT_PLAYER_POSITION     = 6,
    CLT_PLAYER_LEVEL        = 7,
    CLT_PLAYER_INVENTORY    = 8,
    CLT_TIME_UNIT_REQUEST   = 9,
    CLT_TIME_UNIT_CHANGE    = 10,
/*
 * Special commands reserved for addons.
*/
    CLT_CUSTOM              = 11
};

enum GRAPHIC_PACKETS_FROM_SERVER {
/*
 * Usable to determine the degree of change of a server.
*/
    SRV_PROTOCOL_ADDONS     = 12,
/*
 * Base Zappy commands.
*/
    SRV_MAP_SIZE            = 13,
    SRV_TILE_CONTENT        = 14,
    SRV_MAP_CONTENT         = 15,
    SRV_TEAMS_NAMES         = 16,
    SRV_NEW_PLAYER_CONNECT  = 17,
    SRV_PLAYER_POSITION     = 18,
    SRV_PLAYER_LEVEL        = 19,
    SRV_PLAYER_INVENTORY    = 20,
    SRV_EXPULSION           = 21,
    SRV_BROADCAST           = 22,
    SRV_INCANTATION_START   = 23,
    SRV_INCANTATION_END     = 24,
    SRV_EGG_LAYING          = 25,
    SRV_RESOURCE_DROP       = 26,
    SRV_RESOURCE_COLLECT    = 27,
    SRV_PLAYER_DEATH        = 28,
    SRV_EGG_LAYED           = 29,
    SRV_EGG_HATCHING        = 30,
    SRV_PLAYER_CONNECT_EGG  = 31,
    SRV_PLAYER_DEATH_EGG    = 32,
    SRV_TIME_UNIT_REQUEST   = 33,
    SRV_TIME_UNIT_CHANGE    = 34,
    SRV_END_GAME            = 35,
    SRV_MESSAGE_FROM_SRV    = 36,
    SRV_UNKNOWN_COMMAND     = 37,
    SRV_COMMAND_PARAMETER   = 38,
/*
 * Special command reserved for addons.
*/
    SRV_CUSTOM              = 40
};


/*
 * Each change to this document will need an incrementation of this value.
*/
#define PROTOCOL_VERSION    0x1


/*
 * Will be present before each data transfer
 * -> id is the ID of the packet transfered
 * (report to GRAPHIC_PACKETS_FROM_CLIENT or GRAPHIC_PACKETS_FROM_SERVER)
 * -> version is the protocol version (fallback to PROTOCOL_VERSION)
 * -> size is the size of the chunk of data transfered. Doesn't include the
 * packet header.
 * -> subid is only used when id is set on SRV_CUSTOM or CLT_CUSTOM.
 *  Indicate the handler to use for a custom packet.
*/
struct packet_header {
    uint8_t  id;
    uint8_t  version;
    uint16_t size;
    uint16_t subid;
};

typedef struct packet_header pkt_header_t;

/*
 * Handle a const payload. Must be const for subsequent treatment.
 * Return an error flag in case of error (HANDLING_ERRORS).
*/
typedef int (*data_handler)(const char *data);

/*
 * Will be used to handle a const char *, representing the size sized data
 * to be handled.
 * -> id is the ID of the packets to handle.
 * -> subid is the subID of the packets to handle if ID is (SRV|CLT)_CUSTOM
 * -> handler is a function pointer to the handler.
*/
struct packet_handler {
    uint8_t  id;
    uint16_t subid;
    data_handler handler;
};

typedef struct packet_handler pkt_handler_t;

/*
 * Monolithic structure used to register packet handlers.
 * handlers must be NULL-terminated;
*/
struct packet_handler_register {
    pkt_handler_t **handlers;
};

typedef struct packet_handler_register phr_t;

/*
 * Subsequent call for the same ID (or subid) will add the packet handler
 * to the list of packet handler for this specific packet.
*/
void register_pkt_handler(phr_t *registrar, pkt_handler_t *handler);

/*
 * Will unregister the specific packet handler based on the function pointer
 * and the id/subid.
*/
void unregister_pkt_handler(phr_t *registrat, pkt_handler_t *handler);


#ifdef __cplusplus
}
#endif

#pragma options align=reset

