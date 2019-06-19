
CONSTANTS = {
    "linemate_necessary": [-1, 1, 1, 2, 1, 1, 1, 2, 0],
    "linemate_desirable": [-1, 2, 3, 3, 2, 2, 3, 2, 0],
    "deraumere_necessary": [-1, 0, 1, 0, 1, 2, 2, 2, 0],
    "deraumere_desirable": [-1, 1, 1, 1, 2, 3, 3, 2, 0],
    "sibur_necessary": [-1, 0, 1, 1, 2, 1, 3, 2, 0],
    "sibur_desirable": [-1, 1, 2, 3, 3, 4, 5, 2, 0],
    "mendiane_necessary": [-1, 0, 0, 0, 0, 3, 0, 2, 0],
    "mendiane_desirable": [-1, 0, 0, 0, 3, 3, 2, 2, 0],
    "phiras_necessary": [-1, 0, 0, 2, 1, 0, 1, 2, 0],
    "phiras_desirable": [-1, 0, 2, 3, 1, 1, 3, 2, 0],
    "thystame_necessary": [-1, 0, 0, 0, 0, 0, 0, 1, 0],
    "thystame_desirable": [-1, 0, 0, 0, 0, 0, 1, 1, 0],
}

move_to_case = [None] * 16
move_to_case[0] = {}
move_to_case[1] = {"Forward", "Left", "Forward"}
move_to_case[2] = {"Forward"}
move_to_case[3] = {"Forward", "Right", "Forward"}
move_to_case[4] = {"Forward", "Forward", "Left", "Forward", "Forward"}
move_to_case[5] = {"Forward", "Forward", "Left", "Forward"}
move_to_case[6] = {"Forward", "Forward"}
move_to_case[7] = {"Forward", "Forward", "Right", "Forward"}
move_to_case[8] = {"Forward", "Forward", "Right", "Forward", "Forward"}
move_to_case[9] = {"Forward", "Forward", "Forward", "Left", "Forward", "Forward", "Forward"}
move_to_case[10] = {"Forward", "Forward", "Forward", "Left", "Forward", "Forward"}
move_to_case[11] = {"Forward", "Forward", "Forward", "Left", "Forward"}
move_to_case[12] = {"Forward", "Forward", "Forward"}
move_to_case[13] = {"Forward", "Forward", "Forward", "Right", "Forward"}
move_to_case[14] = {"Forward", "Forward", "Forward", "Right", "Forward", "Forward"}
move_to_case[15] = {"Forward", "Forward", "Forward", "Right", "Forward", "Forward", "Forward"}
