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

/* handle_broadcast.c */

int send_broadcast(const void *data);

/* handle_eggs.c */

int send_laying_egg(const void *data);
int send_laid_egg(const void *data);
int send_hatching_egg(const void *data);
int send_egg_connection(const void *data);
int send_egg_hatched_death(const void *data);

/* handle_end_game.c */

int send_end_game(const void *data);

/* handle_expulsion.c */

int send_player_expulsion(const void *data);

/* handle_incantation.c */

int send_incantation_start(const void *data);
int send_incantation_end(const void *data);

/* handle_map_content.c */

int get_map_content(const void *data);
int send_map_content(const void *data);

/* handle_map_size.c */

int send_map_size(const void *data);

/* handle_name_teams.c */

int get_name_teams(const void *data);
int send_name_teams(const void *data);

/* handle_player_connection.c */

int send_player_connection(const void *data);

/* handle_player_death.c */

int send_player_death(const void *data);

/* handle_plauer_inventory.c */

int get_player_inventory(const void *data);
int send_player_inventory(const void *data);

/* handle_player_level.c */

int get_player_level(const void *data);
int send_player_level(const void *data);

/* handle_player_position.c */

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
int get_tile_content(const void *data);
int send_tile_content(const void *data);

/* time.c */

int get_time_unit(const void *data);
int send_time_unit(const void *data);
int get_time_update(const void *data);
int send_time_update(const void *data);
