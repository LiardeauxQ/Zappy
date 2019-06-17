///
/// EPITECH PROJECT, 2018
/// protocols
/// File description:
/// protocols
///

/// \mainpage Zappy documentation
///
/// \section intro_sec Documentation
///
/// This is the Zappy graphic protocol.
///
/// \section install_sec Ideologie
///
/// The protocol has been built on 3 main concept
/// - Simplicity
/// - Efficiency
/// - Scalability
///
/// \subsection Simplicity
///
/// There is a enum for:
/// - Errors: `HANDLING_ERRORS`
/// - Client requests: `GRAPHIC_PACKETS_FROM_CLIENT`
/// - Server requests: `GRAPHIC_PACKETS_FROM_SERVER`
///
/// A simple packet is composed of a
/// packet_header and the struct linked to it's `id`.
///
/// \subsection Efficiency
///
/// The efficiency of the protocol lay on the binary format.
/// String based protocol is good for Web-API but in our case
/// we don't need to encode our object in some kind of string format like JSON
/// because both ends of the sockets are `C/C++` so we can read directly to a
/// struct.
/// (Dont't Serialization and Deserialization)
///
/// \subsection Scalability
///
/// The scalability lay on the `CLT_CUSTOM` and `SRV_CUSTOM` requests `id`
/// The packet_header subid field of the header permit to handle custom form of data.
///

#pragma once

#include <stdint.h>
#include <stddef.h>

#ifdef __clang__
#   pragma pack(1)
#endif /* __clang__ */

#if defined (__GNUC__) && (__GNUC__ >= 7)
#   define PACKED __attribute__((packed))
#else
#   define PACKED
#endif

#ifdef __cplusplus
extern "C" {
#endif

///
/// DANGLING_HANDLER -> Handler function is NULL
///
enum HANDLING_ERRORS {
    NO_ERROR                = 0,
    TOO_FEW_PARAMETERS      = 1,
    TOO_MUCH_PARAMETERS     = 2,
    INVALID_PARAMETERS      = 3,
    DANGLING_HANDLER        = 4
};

///
/// Enumeration of all base messages
/// for the Graphic Protocol
///

enum GRAPHIC_PACKETS_FROM_CLIENT {
///
/// Usable to determine the degree of change of a client.
///
    CLT_PROTOCOL_ADDONS     = 1,
///
/// Base Zappy commands.
///
    CLT_MAP_SIZE            = 2,
    CLT_TILE_CONTENT        = 3,
    CLT_MAP_CONTENT         = 4,
    CLT_TEAMS_NAMES         = 5,
    CLT_PLAYER_POSITION     = 6,
    CLT_PLAYER_LEVEL        = 7,
    CLT_PLAYER_INVENTORY    = 8,
    CLT_TIME_UNIT_REQUEST   = 9,
    CLT_TIME_UNIT_CHANGE    = 10,
///
/// Special commands reserved for addons.
///
    CLT_CUSTOM              = 11
};

enum GRAPHIC_PACKETS_FROM_SERVER {
///
/// Usable to determine the degree of change of a server.
///
    SRV_PROTOCOL_ADDONS     = 12,
///
/// Base Zappy commands.
///
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
///
/// Special command reserved for addons.
///
    SRV_CUSTOM              = 40
};

///
/// Enum for the orientation values used.
///

enum ORIENTATION {
    NORTH = 1,
    EAST  = 2,
    SOUTH = 3,
    WEST  = 4
};

///
/// Enum for the incantation result.
///

enum RESULT {
    KO = 0,
    OK = 1
};

///
/// Enum for the resources number.
///

enum RESOURCE_NUMBER {
    FOOD        = 0,
    LINEMATE    = 1,
    DERAUMERE   = 2,
    SIBUR       = 3,
    MENDIANE    = 4,
    PHIRAS      = 5,
    THYSTAME    = 6
};

///
/// Each change to this document will need an incrementation of this value.
///

#define PROTOCOL_VERSION    0x6

#define SHORT_MSG_LEN 128
#define LONG_MSG_LEN 1024

///
/// Will be present before each data transfer
/// -> id is the ID of the packet transfered
/// (report to GRAPHIC_PACKETS_FROM_CLIENT or GRAPHIC_PACKETS_FROM_SERVER)
/// -> version is the protocol version (fallback to PROTOCOL_VERSION)
/// -> size is the size of the chunk of data transfered. Doesn't include the
/// packet header.
/// -> subid is only used when id is set on SRV_CUSTOM or CLT_CUSTOM.
///  Indicate the handler to use for a custom packet.
///

struct PACKED packet_header {
    uint8_t  id;
    uint8_t  version;
    uint16_t size;
    uint16_t subid;
};

typedef struct packet_header pkt_header_t;

#define PKT_HDR_LEN sizeof(struct packet_header)

///
/// Handle a const payload. Must be const for subsequent treatment.
/// Return an error flag in case of error (HANDLING_ERRORS).
///
typedef int (*data_handler)(const void *data);

///
/// Will be used to handle a const char *, representing the size sized data
/// to be handled.
/// -> id is the ID of the packets to handle.
/// -> subid is the subID of the packets to handle if ID is (SRV|CLT)_CUSTOM
/// -> handler is a function pointer to the handler.
///
struct PACKED packet_handler {
    uint8_t  id;
    uint16_t subid;
    char *name;
    data_handler handler;
};

typedef struct packet_handler pkt_handler_t;

#define PKT_HANDLER_LEN sizeof(struct packet_handler)

///
/// Monolithic structure used to register packet handlers.
/// handlers must be NULL-terminated;
///
struct PACKED packet_handler_register {
    size_t size;
    pkt_handler_t **handlers;
};

typedef struct packet_handler_register phr_t;

#define PKT_HANDLER_REG_LEN sizeof(struct packet_handler_register)
///
/// Subsequent call for the same ID (or subid) will add the packet handler
/// to the list of packet handler for this specific packet.
///
void register_pkt_handler(phr_t *registrar, pkt_handler_t *handler);

///
/// Will unregister the specific packet handler based on the function pointer
/// and the id/subid.
///
void unregister_pkt_handler(phr_t *registrat, pkt_handler_t *handler);

///
/// Start of packet structures.
///

///
/// Client map size packet.
/// Simple request on client side.
///

struct PACKED clt_map_size {
    char tmp;
};

typedef struct clt_map_size clt_map_size_t;

#define CLT_MAP_SIZE_LEN sizeof(struct clt_map_size)

///
/// Server map size packet
/// Answer from server with the map size on x and y.
///

struct PACKED srv_map_size {
    unsigned int x;
    unsigned int y;
};

typedef struct srv_map_size srv_map_size_t;

#define SRV_MAP_SIZE_LEN sizeof(struct srv_map_size)

///
/// Client tile content packet.
/// Request on client side with the coordinate of the tile to request.
///

struct PACKED clt_tile_content {
    unsigned int x;
    unsigned int y;
};

typedef struct clt_tile_content clt_tile_content_t;

#define CLT_TILE_CONTENT_LEN sizeof(struct clt_tile_content)

///
/// Server tile content.
/// Contains all informations about the tile content.
///

struct PACKED srv_tile_content {
    unsigned int x;
    unsigned int y;
    unsigned int q0;
    unsigned int q1;
    unsigned int q2;
    unsigned int q3;
    unsigned int q4;
    unsigned int q5;
    unsigned int q6;
    unsigned int players;
};

typedef struct srv_tile_content srv_tile_content_t;

#define SRV_TILE_CONTENT_LEN sizeof(struct srv_tile_content)

///
/// Client map content packet.
/// Simple request on client side.
///

struct PACKED clt_map_content {
    char tmp;
};

typedef struct clt_map_content clt_map_content_t;

#define CLT_MAP_CONTENT_LEN sizeof(struct clt_map_content)

///
/// Client team name packet.
/// Simple request on client side.
///

struct PACKED clt_teams_names {
    char tmp;
};

typedef struct clt_teams_names clt_teams_names_t;

#define CLT_TEAMS_NAMES_LEN sizeof(struct clt_teams_names)

///
/// Server teams names packet.
/// Contain the team name.
/// Additionnal values are appended after each struct.
///

struct PACKED srv_teams_names {
    char team_name[SHORT_MSG_LEN];
};

typedef struct srv_teams_names srv_teams_names_t;

#define SRV_TEAMS_NAMES_LEN sizeof(struct srv_teams_names)

///
/// Server new connection packet.
///

struct PACKED srv_new_player_connect {
    unsigned int player_num;
    unsigned int x;
    unsigned int y;
    enum ORIENTATION orientation;
    unsigned int level;
    char team_name[SHORT_MSG_LEN];
};

typedef struct srv_new_player_connect srv_new_player_connect_t;

#define SRV_NEW_PLAYER_CONNECT_LEN sizeof(struct srv_new_player_connect)

///
/// Client player position packet.
/// Request the position of the player determined by the number.
///

struct PACKED clt_player_pos {
    unsigned int player_num;
};

typedef struct clt_player_pos clt_player_pos_t;

#define CLT_PLAYER_POS_LEN sizeof(struct clt_player_pos)

///
/// Server player position packet.
///

struct PACKED srv_player_pos {
    unsigned int player_num;
    unsigned int x;
    unsigned int y;
    enum ORIENTATION orientation;
};

typedef struct srv_player_pos srv_player_pos_t;

#define SRV_PLAYER_POS_LEN sizeof(struct srv_player_pos)

///
/// Client player level packet.
/// Request the level of the player determined by the number.
///

struct PACKED clt_player_level {
    unsigned int player_num;
};

typedef struct clt_player_level clt_player_level_t;

#define CLT_PLAYER_LEVEL_LEN sizeof(struct clt_player_level)

///
/// Server player level packet.
///

struct PACKED srv_player_level {
    unsigned int player_num;
    unsigned int level;
};

typedef struct srv_player_level srv_player_level_t;

#define SRV_PLAYER_LEVEL_LEN sizeof(struct srv_player_level)

///
/// Client player inventory packet.
/// Request the inventory of the player determined by the number.
///

struct PACKED clt_player_inventory {
    unsigned int player_num;
};

#define CLT_PLAYER_INVENTORY_LEN sizeof(struct clt_player_inventory)

///
/// Server player inventory packet.
///

struct PACKED srv_player_inventory {
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

#define SRV_PLAYER_INVENTORY_LEN sizeof(struct srv_player_inventory)

///
/// Server expulsion packet.
///

struct PACKED srv_player_expulsion {
    unsigned int player_num;
};

typedef struct srv_player_expulsion srv_player_expulsion_t;

#define SRV_PLAYER_EXPULSION_LEN sizeof(struct srv_player_expulsion)

///
/// Server broadcast packet.
///

struct PACKED srv_broadcast_msg {
    unsigned int player_num;
    char message[LONG_MSG_LEN];
};

typedef struct srv_broadcast_msg srv_broadcast_msg_t;

#define SRV_BROADCAST_MSG_LEN sizeof(struct srv_broadcast_msg)

///
/// Server start of incantation packet.
///

struct PACKED srv_start_incantation {
    unsigned int x;
    unsigned int y;
    unsigned int level;
    unsigned int players[32];
};

typedef struct srv_start_incantation_msg srv_start_incantation_msg_t;

#define SRV_START_INCANTATION_LEN sizeof(struct srv_start_incantation)

///
/// Server end of incantation packet.
///

struct PACKED srv_end_incantation {
    unsigned int x;
    unsigned int y;
    enum RESULT result;
};

typedef struct srv_end_incantation_msg srv_end_incantation_msg_t;

#define SRV_END_INCANTATION_LEN sizeof(struct srv_end_incantation)

///
/// Server "egg laying by the player" packet.
///

struct PACKED srv_player_egg_laying {
    unsigned int player_num;
};

typedef struct srv_player_egg_laying srv_player_egg_laying_t;

#define SRV_PLAYER_EGG_LAYING_LEN sizeof(struct srv_player_egg_laying)

///
/// Server resource dropping packet.
///

struct PACKED srv_player_resource_dropped {
    unsigned int player_num;
    enum RESOURCE_NUMBER resource;
};

typedef struct srv_player_resource_dropped srv_player_resource_dropped_t;

#define SRV_PLAYER_RESOURCE_DROPPED_LEN sizeof(struct srv_player_resource_dropped)

///
/// Server resource collected packet.
///

struct PACKED srv_player_resource_collected {
    unsigned int player_num;
    enum RESOURCE_NUMBER resource;
};

typedef struct srv_player_resource_collected srv_player_resource_collected_t;

#define SRV_PLAYER_RESOURCE_COLLECTED_LEN sizeof(struct srv_player_resource_collected)

///
/// Server player dead packet.
///

struct PACKED srv_player_death {
    unsigned int player_num;
};

typedef struct srv_player_death srv_player_death_t;

#define SRV_PLAYER_DEATH_LEN sizeof(struct srv_player_death)

///
/// Server player layed egg packet.
///

struct PACKED srv_player_egg_layed {
    unsigned int player_num;
    unsigned int egg_num;
    unsigned int x;
    unsigned int y;
};

typedef struct srv_player_egg_layed srv_player_egg_layed_t;

#define SRV_PLAYER_EGG_LAYED_LEN sizeof(struct srv_player_egg_layed)

///
/// Server egg hatching packet.
///

struct PACKED srv_player_egg_hatching {
    unsigned int egg_num;
};

typedef struct srv_player_egg_hatching srv_player_egg_hatching_t;

#define SRV_PLAYER_EGG_HATCHING_LEN sizeof(struct srv_player_egg_hatching)

///
/// Server player egg connection.
///

struct PACKED srv_player_egg_connection {
    unsigned int egg_num;
};

typedef struct srv_player_egg_connection srv_player_egg_connection_t;

#define SRV_PLAYER_EGG_CONNECTION_LEN sizeof(struct srv_player_egg_connection)

///
/// Server death of hatched egg.
///

struct PACKED srv_hatched_egg_death {
    unsigned int egg_num;
};

typedef struct srv_hatched_egg_death srv_hatched_egg_death_t;

#define SRV_HATCHED_EGG_DEATH_LEN sizeof(struct srv_hatched_egg_death)

///
/// Server end of the game packet.
///

struct PACKED srv_end_game {
    char winning_team[SHORT_MSG_LEN];
};

typedef struct srv_end_game srv_end_game_t;

#define SRV_END_GAME_LEN sizeof(struct srv_end_game)

///
/// Message from server.
///

struct PACKED srv_global_message {
    char message[LONG_MSG_LEN];
};

typedef struct srv_global_message srv_global_message_t;

#define SRV_GLOBAL_MESSAGE_LEN sizeof(struct srv_global_message)

///
/// Server unknwon command packet.
///

struct PACKED srv_unknown_command {
    char tmp;
};

typedef struct srv_unknown_command srv_unknown_command_t;

#define SRV_UNKNOWN_COMMAND_LEN sizeof(struct srv_unknown_command)

///
/// Server bad parameters.
///

struct PACKED srv_bad_parameters {
    char tmp;
};

typedef struct srv_bad_parameters srv_bad_parameters_t;

#define SRV_BAD_PARAMETERS_LEN sizeof(struct srv_bad_parameters)

#ifdef __cplusplus
}
#endif

#ifdef __clang__
#   pragma options align=reset
#endif /* __clang__ */

