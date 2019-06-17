/*
** EPITECH PROJECT, 2018
** commands.h
** File description:
** commands header
*/

#pragma once

/* handle_broadcast.c */

int send_broadcast(const char *data);

/* handle_eggs.c */

int send_laying_egg(const char *data);
int send_laid_egg(const char *data);
int send_hatching_egg(const char *data);
int send_egg_connection(const char *data);
int send_egg_hatched_death(const char *data);

/* handle_end_game.c */

int send_end_game(const char *data);

/* handle_expulsion.c */

int send_player_expulsion(const char *data);

/* handle_incantation.c */

int send_incantation_start(const char *data);
int send_incantation_end(const char *data);

/* handle_map_content.c */

int get_map_content(const char *data);
int send_map_content(const char *data);

/* handle_map_size.c */

int get_map_size(const char *data);
int send_map_size(const char *data);

/* handle_name_teams.c */

int get_name_teams(const char *data);
int send_name_teams(const char *data);

/* handle_player_connection.c */

int send_player_connection(const char *data);

/* handle_player_death.c */

int send_player_death(const char *data);

/* handle_plauer_inventory.c */

int get_player_inventory(const char *data);
int send_player_inventory(const char *data);

/* handle_player_level.c */

int get_player_level(const char *data);
int send_player_level(const char *data);

/* handle_player_position.c */

int get_player_position(const char *data);
int send_player_position(const char *data);

/* handle_resources.c */

int send_resource_drop(const char *data);
int send_resource_collect(const char *data);

/* handle_server_message.c */

int send_message_to_client(const char *data);
int unknown_command(const char *data);

/* handle_tile_content.c */

int get_tile_content(const char *data);
int send_tile_content(const char *data);

/* time.c */

int get_time_unit(const char *data);
int send_time_unit(const char *data);
int get_time_update(const char *data);
int send_time_update(const char *data);
