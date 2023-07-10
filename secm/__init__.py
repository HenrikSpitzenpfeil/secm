"""
secm

A Python library to control Scanning electrochemical microscopes and
scanning droplet cells by Sensolytics.

See https://www.sensolytics.de/de/

"""

__version__ = "0.1.0"
__author__ = "Henrik Spitzenpfeil"

from secm.secm import SECM
from secm.position_storage import PositionStorage
import secm.sdc