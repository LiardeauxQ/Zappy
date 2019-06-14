/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** create map
*/

#include <stdlib.h>

#include "map.h"
#include "error.h"
#include "graphical/protocols.h"

map_t create_map(unsigned int width, unsigned int height)
{
    map_t map = {0};

    map.width = width;
    map.height = height;
    map.tiles = malloc(width * sizeof(srv_tile_content_t *));
    check_malloc(map.tiles);
    for (size_t i = 0 ; i < width ; i++) {
        map.tiles[i] = malloc(height * sizeof(srv_tile_content_t));
        check_malloc(map.tiles[i]);
        for (size_t j = 0 ; j < height ; j++) {
            map.tiles[i][j] = (srv_tile_content_t){0};
            map.tiles[i][j].x = width;
            map.tiles[i][j].y = height;
        }
    }
    return (map);
}
