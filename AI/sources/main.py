from AI.sources.ressources.stone import *
from AI.sources.ressources.stonesTypes import *
from AI.sources.ressources.dictionaries import *
from AI.sources.elevation.playerNeededForElevation import *
from AI.sources.socket.socket import *
from AI.sources.interactions.interactions import *


if __name__ == "__main__":
    client = Player()

    client.client.sendMessage("abc\n");
    client.look();

