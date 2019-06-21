/*
** EPITECH PROJECT, 2018
** commands.h
** File description:
** commands header
*/

#pragma once

#include <stdlib.h>

#include "graphical/protocols.h"
#include "world.h"

#define SENDER_MAGIC_NUM 0x01041976 // Foundation of 
#define SENDER_MAGIC_NUM_LEN 4

#define MAX_SENDERS             5
#define WORLD_SENDER_POS        0
#define PLAYER_SENDER_POS       1
#define INT_SENDER_POS          2
#define MSG_SENDER_POS          3
#define CUSTOM_SENDER_POS       4

struct sender_s {
    const void *data;
    size_t size;
    int sockfd;
    int is_last;
} __attribute__((packed));

typedef struct sender_s sender_t;

/* sender.c  */

sender_t *get_senders_from_data(const void *data);
void *convert_senders_to_data(const sender_t *senders);
size_t count_senders(const sender_t *senders);
void destroy_senders(sender_t *senders);

/* Structure of the default sender array
 * --> world_t
 * --> player_t
 * --> int
 * --> char **
 * --> custom
 */

/* handle_broadcast.c */

int send_broadcast(const void *data);
int assign_broadcast(char *msg, int size, int player_num, int sockfd);

/* egg_laying.c */

int assign_laying_egg(int egg_num, int sockfd);
int send_laying_egg(const void *data);

/* egg_layed.c */

int assign_layed_egg(player_t *player, int egg_num, int sockfd);
int send_layed_egg(const void *data);

/* egg_hatching.c */

int assign_hatching_egg(int egg_num, int sockfd);
int send_hatching_egg(const void *data);

/* egg_connection.c */

int send_egg_connection(const void *data);
int assign_egg_connection(int egg_num, int sockfd);

/* egg_hatched_egg.c */

int assign_egg_hatched_egg(int egg_num, int sockfd);
int send_egg_hatched_death(const void *data);

/* handle_end_game.c */

int assign_end_game(char *msg, int size, int sockfd);
int send_end_game(const void *data);

/* handle_expulsion.c */

int assign_player_expulsion(int player_num, int sockfd);
int send_player_expulsion(const void *data);

/* handle_incantation.c */

int assign_incantation_start(world_t *world, player_t *player, int sockfd);
int send_incantation_start(const void *data);
int assign_incantation_end(srv_end_incantation_t *srv, int sockfd);
int send_incantation_end(const void *data);

/* handle_map_content.c */

int assign_map_content(world_t *world, int sockfd);
int send_map_content(const void *data);

/* handle_map_size.c */

int assign_map_siz(world_t *world, int sockfd);
int send_map_size(const void *data);

/* handle_name_teams.c */

int get_name_teams(const void *data);
int send_name_teams(const void *data);

/* handle_player_connection.c */

int send_player_connection(const void *data);

/* handle_player_death.c */

int assign_player_death(int player_num, int sockfd);
int send_player_death(const void *data);

/* handle_player_inventory.c */

int assign_player_inventory(world_t *world,
        struct clt_player_inventory *clt, int sockfd);
int get_player_inventory(const void *data);
int send_player_inventory(const void *data);

/* handle_player_level.c */

int assign_player_level(world_t *world, clt_player_level_t *clt, int sockfd);
int get_player_level(const void *data);
int send_player_level(const void *data);

/* handle_player_position.c */

int assign_player_position(world_t *world, clt_player_pos_t *pos, int sockfd);
int get_player_position(const void *data);
int send_player_position(const void *data);

/* handle_resources.c */

int send_resource_drop(const void *data);
int send_resource_collect(const void *data);

/* handle_server_message.c */

int send_message_to_client(const void *data);
int unknown_command(const void *data);

/* handle_tile_content.c */

srv_tile_content_t convert_to_srv_tile_content(tile_content_t *tile,
        const unsigned int x, const unsigned int y);
char *write_tile_content(tile_content_t *tile,
        const unsigned int x, const unsigned int y, const int subid);
int assign_tile_content(world_t *world, clt_tile_content_t *clt, int sockfd);
int get_tile_content(const void *data);
int send_tile_content(const void *data);

/* time.c */

int get_time_unit(const void *data);
int send_time_unit(const void *data);
int get_time_update(const void *data);
int send_time_update(const void *data);

/* close_connection.c */

int get_close_connection(const void *data);
int send_close_connection(const void *data);
