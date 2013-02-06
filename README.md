Wireless-ATEM-Tally
===================

A Wireless (or wired) tally system for Blackmagic's ATEM vision mixers built upon Arduino Ethernet and Xbee's based upon the Skarhooj code.

For the first revision of this Tally system you will need the following:

Coordinator (the one interfacing with the ATEM and converting it to wireless):
1 x Arduino Ethernet
1 x Xbee Shield of your choice
1 x Xbee Pro (i used S2B RP-SMA) with ZigBee AT coordinator firmware uploaded (Set to broadcast with <a href="http://www.digi.com/support/productdetail?pid=3352">X-CTU</a>, more info about <a href="https://sites.google.com/site/xbeetutorial/xbee-introduction/zigbee_setup">setting Xbee to broadcast here</a>).

Per each client you will need:
1 x Arduino USB
1 x Xbee Shield
1 x Xbee Pro (i used S2B RP-SMA) with ZigBee AT Router firmware uploaded.
1 x Red LED (for program indication)
1 x Green LED (for preview indication)