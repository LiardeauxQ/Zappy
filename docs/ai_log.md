# AI LOG FILES

This file present how AI files are made.

## File name
it's a .log file with a random id.
```zappy_ai_[id].log```
log file id is print during the execution of zappy_ai.


- - -

## File description

### Socket messaging
First of all the zappy client try to connect to zappoy server with socket
all socket log start with socket and a random id

exemple:

```DEBUG:root:socket [167954] Connection on http://localhost:6000 -> WELCOME```

### Inventory
when Ai as to server inventory, the client will log server inventory and next client invetory
exemple:
```
// Server:
DEBUG:root:[['food', '9'], ['linemate', '0'], ['deraumere', '0'], ['sibur', '0'], ['mendiane', '0'], ['phiras', '0'], ['thystame', '0']]
// Client:
DEBUG:root:Inventory >food 9; linemate0; mendiane0; phiras0; sibur0; thystame0; deraumere0

```

### Look
When client look for ressource the server will look the player's field of vision and then the deplacement decided by AI. next client will send to server all deplacement for take resseources.
exemple
```
DEBUG:root:[['player', 'food', 'food', 'food', 'mendiane', 'phiras'], ['food', 'food', 'food', 'food', 'food', 'linemate'], ['food', 'food', 'food', 'food', 'food', 'food', 'food', 'phiras'], ['food', 'food', 'food', 'food', 'food', 'food', 'sibur']]

DEBUG:root:['Forward', 'Left', 'Forward']
DEBUG:root:socket [167954] Send :Forward

DEBUG:root:socket [167954] recive :ok
DEBUG:root:['Left', 'Forward']
DEBUG:root:socket [167954] Send :Left

DEBUG:root:socket [167954] recive :ok
DEBUG:root:['Forward']
DEBUG:root:socket [167954] Send :Forward

DEBUG:root:socket [167954] recive :ok
DEBUG:root:socket [167954] Send :Take linemate

DEBUG:root:socket [167954] recive :ok
```

### Elevation 

exemple:
```
DEBUG:root:[['player', 'food', 'food', 'food', 'mendiane', 'phiras'], ['food', 'food', 'food', 'food', 'food', 'linemate'], ['food', 'food', 'food', 'food', 'food', 'food', 'food', 'phiras'], ['food', 'food', 'food', 'food', 'food', 'food', 'sibur']]
DEBUG:root:['Forward', 'Left', 'Forward']
DEBUG:root:socket [167954] Send :Forward

DEBUG:root:socket [167954] recive :ok

DEBUG:root:['Left', 'Forward']
DEBUG:root:socket [167954] Send :Left

DEBUG:root:socket [167954] recive :ok

DEBUG:root:['Forward']
DEBUG:root:socket [167954] Send :Forward

DEBUG:root:socket [167954] recive :ok

DEBUG:root:socket [167954] Send :Take linemate

DEBUG:root:socket [167954] recive :ok```



