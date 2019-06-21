from AI.sources.ressources.stone import *
from AI.sources.ressources.stonesTypes import *
from AI.sources.ressources.dictionaries import *
from AI.sources.elevation.playerNeededForElevation import *
from AI.sources.socket.socket import *
from AI.sources.interactions.interactions import *
import getopt
import sys
import logging

def usage():
    print("""USAGE: ./zappy_ai -p port -n name -h machine
    port is the port number
    name is the name of the team
    machine is the name of the machine; localhost by default""")

if __name__ == "__main__":

    log = 'zappy_ai_' + str(random.randint(0, 9999)) + '.log'
    print("AI log file:", log)
    logging.basicConfig(filename=log,level=logging.DEBUG)
    host = 'localhost'
    port = 6000
    team = 'test_team'
    
    try:
        optlist, args = getopt.getopt(sys.argv[1:], 'p:n:h:', ["help"])
    except getopt.GetoptError as err:
        print(err)
        usage()
        sys.exit(84)
    for o, a in optlist:
        if o == "--help":
            usage()
            sys.exit()
        elif o in ("-h"):
            host = a
        elif o in ("-p"):
            port = int(a)
        elif o in ("-n"):
            team = a
    client = Player(port, team, host)
    c = client.client.sendMessage(team + "\n")
    print (c)
    if "ko" in c:
        print("Imposible to set team name ", team, " inside zappy_server http://", host, ":", port, sep = '')
        logging.debug("Imposible to set team name ", team, " inside zappy_server http://", host, ":", port)
        sys.exit(84)
    client.start();
    
