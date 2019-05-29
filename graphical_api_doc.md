## Graphical API Documentation

This section is an index about functions you can use for building graphical environment.

## Resources:

First of all, be aware of all the elements and action which have an graphical impact on the project:

Objects:

- map (composed of tiles)
- players
- resources:
    - Food
    - Stones:
        - linemate
        - deraumere
        - sibur
        - mendiane
        - phiras
        - thystame
- HUD

Actions:

- Move
- Pick object
- Typing / Receiving message
- Incantation
- Egg management
- Death
- Win situation

## API Functiions:

In order to adapt the client graphical view with all those elements, the server will use our Graphical API.
It is composed of those functions.

- **void display_map()**
Display the map, filling every tile with elements it contains (resources/player/egg).
- **void display_hud()**
Display the HUD, filled with informations related to the selected tile.
- **void move_players()**
Move all concerned players from 1 unit in the direction they are looking.
- **void pick_food()**
The selected player picks food from the tile.
- **void pick_linemate()**
The selected player picks linemate from the tile.
- **void pick_deraumere()**
The selected player picks deraumere from the tile.
- **void pick_sibur()**
The selected player picks sibur from the tile.
- **void pick_mendiane()**
The selected player picks mendiane from the tile.
- **void pick_phiras()**
The selected player picks phiras from the tile.
- **void pick_thystame()**
The selected player picks thystame from the tile.
- **void player_message()**
Animate selected player when he's typing/receiving a message.
- **void display_incantation()**
Animate the tile with an incantation animation.
- **void create_egg()**
Create an egg on the player's tile.
- **void egg_animation()**
Display an egg animation when the egg is on the tile.
- **void add_player()**
Display a new player when the egg depop.
- **void kill_player()**
Death animation when a player must be destroyed.
- **void display_win_scene()**
Stop displaying the map and display the win scene, with the winner team name.