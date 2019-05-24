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
** DANGLING_HANDLER -> Handler function is NULL
*/
enum HANDLING_ERRORS {
    NO_ERROR                = 0,
    TOO_FEW_PARAMETERS      = 1,
    TOO_MUCH_PARAMETERS     = 2,
    INVALID_PARAMETERS      = 3,
    DANGLING_HANDLER        = 4
};

/*
** Enumeration of all base messages
** for the Graphic Protocol
*/

enum GRAPHIC_PACKETS_FROM_CLIENT {
/*
** Usable to determine the degree of change of a client.
*/
    CLT_PROTOCOL_ADDONS     = 1,
/*
** Base Zappy commands.
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
** Special commands reserved for addons.
*/
    CLT_CUSTOM              = 11
};

enum GRAPHIC_PACKETS_FROM_SERVER {
/*
** Usable to determine the degree of change of a server.
*/
    SRV_PROTOCOL_ADDONS     = 12,
/*
** Base Zappy commands.
*/
    SRV_MAP_SIZE            = 13,
    SRV_TILE_CONTENT        = 14,
    SRV_TEAMS_NAMES         = 15,
    SRV_NEW_PLAYER_CONNECT  = 16,
    SRV_PLAYER_POSITION     = 17,
    SRV_PLAYER_LEVEL        = 18,
    SRV_PLAYER_INVENTORY    = 19,
    SRV_EXPULSION           = 20,
    SRV_BROADCAST           = 21,
    SRV_INCANTATION_START   = 22,
    SRV_INCANTATION_END     = 23,
    SRV_EGG_LAYING          = 24,
    SRV_RESOURCE_DROP       = 25,
    SRV_RESOURCE_COLLECT    = 26,
    SRV_PLAYER_DEATH        = 27,
    SRV_EGG_LAYED           = 28,
    SRV_EGG_HATCHING        = 29,
    SRV_PLAYER_CONNECT_EGG  = 30,
    SRV_PLAYER_DEATH_EGG    = 31,
    SRV_TIME_UNIT_REQUEST   = 32,
    SRV_TIME_UNIT_CHANGE    = 33,
    SRV_END_GAME            = 34,
    SRV_MESSAGE_FROM_SRV    = 35,
    SRV_UNKNOWN_COMMAND     = 36,
    SRV_COMMAND_PARAMETER   = 37,
/*
** Special command reserved for addons.
*/
    SRV_CUSTOM              = 40
};

/*
** Enum for the orientation values used.
*/

enum ORIENTATION {
    NORTH = 1,
    EAST  = 2,
    SOUTH = 3,
    WEST  = 4
};

/*
** Enum for the incantation result.
*/

enum RESULT {
    KO = 0,
    OK = 1
};

/*
** Enum for the resources number.
*/

enum RESOURCE_NUMBER {
    FOOD        = 0,
    LINEMATE    = 1,
    DERAUMERE   = 2,
    SIBUR       = 3,
    MENDIANE    = 4,
    PHIRAS      = 5,
    THYSTAME    = 6
};

/*
** Each change to this document will need an incrementation of this value.
*/
#define PROTOCOL_VERSION    0x4


/*
** Will be present before each data transfer
** -> id is the ID of the packet transfered
** (report to GRAPHIC_PACKETS_FROM_CLIENT or GRAPHIC_PACKETS_FROM_SERVER)
** -> version is the protocol version (fallback to PROTOCOL_VERSION)
** -> size is the size of the chunk of data transfered. Doesn't include the
** packet header.
** -> subid is only used when id is set on SRV_CUSTOM or CLT_CUSTOM.
**  Indicate the handler to use for a custom packet.
*/
struct packet_header {
    uint8_t  id;
    uint8_t  version;
    uint16_t size;
    uint16_t subid;
};

typedef struct packet_header pkt_header_t;

/*
** Handle a const payload. Must be const for subsequent treatment.
** Return an error flag in case of error (HANDLING_ERRORS).
*/
typedef int (*data_handler)(const char *data);

/*
** Will be used to handle a const char *, representing the size sized data
** to be handled.
** -> id is the ID of the packets to handle.
** -> subid is the subID of the packets to handle if ID is (SRV|CLT)_CUSTOM
** -> handler is a function pointer to the handler.
*/
struct packet_handler {
    uint8_t  id;
    uint16_t subid;
    char *name;
    data_handler handler;
};

typedef struct packet_handler pkt_handler_t;

/*
** Monolithic structure used to register packet handlers.
** handlers must be NULL-terminated;
*/
struct packet_handler_register {
    size_t size;
    pkt_handler_t **handlers;
};

typedef struct packet_handler_register phr_t;

/*
** Subsequent call for the same ID (or subid) will add the packet handler
** to the list of packet handler for this specific packet.
*/
void register_pkt_handler(phr_t *registrar, pkt_handler_t *handler);

/*
** Will unregister the specific packet handler based on the function pointer
** and the id/subid.
*/
void unregister_pkt_handler(phr_t *registrat, pkt_handler_t *handler);

/*
** Start of packet structures.
*/

/*
** Client map size packet.
** Simple request on client side.
*/

struct clt_map_size {
};

typedef struct clt_map_size clt_map_size_t;

/*
** Server map size packet
** Answer from server with the map size on x and y.
*/

struct srv_map_size {
    unsigned int x;
    unsigned int y;
};

typedef struct srv_map_size srv_map_size_t;

/*
** Client tile content packet.
** Request on client side with the coordinate of the tile to request.
*/

struct clt_tile_content {
    unsigned int x;
    unsigned int y;
};

typedef struct clt_tile_content clt_tile_content_t;

/*
** Server tile content.
** Contains all informations about the tile content.
*/

struct srv_tile_content {
    unsigned int x;
    unsigned int y;
    unsigned int q0;
    unsigned int q1;
    unsigned int q2;
    unsigned int q3;
    unsigned int q4;
    unsigned int q5;
    unsigned int q6;
};

typedef struct srv_tile_content srv_tile_content_t;

/*
** Client map content packet.
** Simple request on client side.
*/

struct clt_map_content {
};

typedef struct clt_map_content clt_map_content_t;

/*
** Client team name packet.
** Simple request on client side.
*/

struct clt_teams_names {
};

typedef struct clt_teams_names clt_teams_names_t;

/*
** Server teams names packet.
** Contain the team name.
** Additionnal values are appended after each struct.
*/

struct srv_teams_names {
    char team_name[128];
};

typedef struct srv_teams_names srv_teams_names_t;

/*
** Server new connection packet.
*/

struct srv_new_player_connect {
    unsigned int player_num;
    unsigned int x;
    unsigned int y;
    enum ORIENTATION orientation;
    unsigned int level;
    char team_name[128];
};

typedef struct srv_new_player_connect srv_new_player_connect_t;

/*
** Client player position packet.
** Request the position of the player determined by the number.
*/

struct clt_player_pos {
    unsigned int player_num;
};

typedef struct clt_player_pos clt_player_pos_t;

/*
** Server player position packet.
*/

struct srv_player_pos {
    unsigned int player_num;
    unsigned int x;
    unsigned int y;
    enum ORIENTATION orientation;
};

typedef struct srv_player_pos srv_player_pos_t;

/*
** Client player level packet.
** Request the level of the player determined by the number.
*/

struct clt_player_level {
    unsigned int player_num;
};

typedef struct clt_player_level clt_player_level_t;

/*
** Server player level packet.
*/

struct srv_player_level {
    unsigned int player_num;
    unsigned int level;
};

typedef struct srv_player_level srv_player_level_t;

/*
** Client player inventory packet.
** Request the inventory of the player determined by the number.
*/

struct clt_player_inventory {
    unsigned int player_num;
};

/*
** Server player inventory packet.
*/

struct srv_player_inventory {
    unsigned int player_num;
    unsigned int x;
    unsigned int y;
    unsigned int q0;
    unsigned int q1;
    unsigned int q2;
    unsigned int q3;
    unsigned int q4;
    unsigned int q5;
    unsigned int q6;
};

typedef struct srv_player_inventory srv_player_inventory_t;

/*
** Server expulsion packet.
*/

struct srv_player_expulsion {
    unsigned int player_num;
};

typedef struct srv_player_expulsion srv_player_expulsion_t;

/*
** Server broadcast packet.
*/

struct srv_broadcast_msg {
    unsigned int player_num;
    char message[1024];
};

typedef struct srv_broadcast_msg srv_broadcast_msg_t;

/*
** Server start of incantation packet.
*/

struct srv_start_incantation {
    unsigned int x;
    unsigned int y;
    unsigned int level;
    unsigned int players[32];
};

typedef struct srv_start_incantation_msg srv_start_incantation_msg_t;

/*
** Server end of incantation packet.
*/

struct srv_end_incantation {
    unsigned int x;
    unsigned int y;
    enum RESULT result;
};

typedef struct srv_end_incantation_msg srv_end_incantation_msg_t;

/*
** Server "egg laying by the player" packet.
*/

struct srv_player_egg_laying {
    unsigned int player_num;
};

typedef struct srv_player_egg_laying srv_player_egg_laying_t;

/*
** Server resource dropping packet.
*/

struct srv_player_resource_dropped {
    unsigned int player_num;
    enum RESOURCE_NUMBER resource;
};

typedef struct srv_player_resource_dropped srv_player_resource_dropped_t;

/*
** Server resource collected packet.
*/

struct srv_player_resource_collected {
    unsigned int player_num;
    enum RESOURCE_NUMBER resource;
};

typedef struct srv_player_resource_collected srv_player_resource_collected_t;

/*
** Server player dead packet.
*/

struct srv_player_death {
    unsigned int player_num;
};

typedef struct srv_player_death srv_player_death_t;

/*
** Server player layed egg packet.
*/

struct srv_player_egg_layed {
    unsigned int player_num;
    unsigned int egg_num;
    unsigned int x;
    unsigned int y;
};

typedef struct srv_player_egg_layed srv_player_egg_layed_t;

/*
** Server egg hatching packet.
*/

struct srv_player_egg_hatching {
    unsigned int egg_num;
};

typedef struct srv_player_egg_hatching srv_player_egg_hatching_t;

/*
** Server player egg connection.
*/

struct srv_player_egg_connection {
    unsigned int egg_num;
};

typedef struct srv_player_egg_connection srv_player_egg_connection_t;

/*
** Server death of hatched egg.
*/

struct srv_hatched_egg_death {
    unsigned int egg_num;
};

typedef struct srv_hatched_egg_death srv_hatched_egg_death_t;

/*
** Server end of the game packet.
*/

struct srv_end_game {
    char winning_team[128];
};

typedef struct srv_end_game srv_end_game_t;

/*
** Message from server.
*/

struct srv_global_message {
    char message[256];
};

typedef struct srv_global_message srv_global_message_t;

/*
** Server unknwon command packet.
*/

struct srv_unknown_command {
};

typedef struct srv_unknown_command srv_unknown_command_t;

/*
** Ŝerver bad parameters.
*/

struct srv_bad_parameters {
};

typedef struct srv_bad_parameters srv_bad_parameters_t;

#ifdef __cplusplus
}
#endif

#pragma options align=reset

