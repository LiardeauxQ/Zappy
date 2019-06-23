import unittest

from AI.sources.ressources.stone import *
from AI.sources.ressources.stonesTypes import *
from AI.sources.ressources.dictionaries import *
from AI.sources.elevation.playerNeededForElevation import *
from AI.sources.socket.socket import *
from AI.sources.interactions.interactions import *


class TestStringMethods(unittest.TestCase):

    def test_type(self):
        s = Stone(StonesTypes.LINEMATE)
        self.assertEqual(s.type.describe(), 'LINEMATE')

    def test_change_type(self):
        s = Stone(StonesTypes.LINEMATE)
        self.assertEqual(s.type.describe(), 'LINEMATE')
        s.change_type(StonesTypes.MENDIANE)
        self.assertEqual(s.type.describe(), 'MENDIANE')



if __name__ == '__main__':
    unittest.main()