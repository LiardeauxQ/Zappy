
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

# ACTION TO MOVE TO LOOK POSITION

move_to_case = {
    0 : [],
    1 : ["Forward", "Left", "Forward"],
    2 : ["Forward"],
    3 : ["Forward", "Right", "Forward"],
    4 : ["Forward", "Forward", "Left", "Forward", "Forward"],
    5 : ["Forward", "Forward", "Left", "Forward"],
    6 : ["Forward", "Forward"],
    7 : ["Forward", "Forward", "Right", "Forward"],
    8 : ["Forward", "Forward", "Right", "Forward", "Forward"],
    9 : ["Forward", "Forward", "Forward", "Left", "Forward", "Forward", "Forward"],
    10 : ["Forward", "Forward", "Forward", "Left", "Forward", "Forward"],
    11 : ["Forward", "Forward", "Forward", "Left", "Forward"],
    12 : ["Forward", "Forward", "Forward"],
    13 : ["Forward", "Forward", "Forward", "Right", "Forward"],
    14 : ["Forward", "Forward", "Forward", "Right", "Forward", "Forward"],
    15 : ["Forward", "Forward", "Forward", "Right", "Forward", "Forward", "Forward"]
}