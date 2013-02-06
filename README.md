Wireless-ATEM-Tally
===================

A Wireless (or wired) tally system for Blackmagic's ATEM vision mixers built upon Arduino Ethernet and Xbee's based upon the Skaarhoj code. Developed by Dreamhack AB.

For the first revision of this Tally system you will need the following:

<b>Coordinator</b> (the one interfacing with the ATEM and converting it to wireless):<br />
1 x Arduino Ethernet<br />
1 x Xbee Shield of your choice<br />
1 x Xbee Pro (i used S2B RP-SMA) with ZigBee AT coordinator firmware uploaded (Set to broadcast with <a href="http://www.digi.com/support/productdetail?pid=3352">X-CTU</a>, more info about <a href="https://sites.google.com/site/xbeetutorial/xbee-introduction/zigbee_setup">setting Xbee to broadcast here</a>).<br />

<br />
<b>Client</b> (for each client):<br />
1 x Arduino USB<br />
1 x Xbee Shield<br />
1 x Xbee Pro (i used S2B RP-SMA) with ZigBee AT Router firmware uploaded.<br />
1 x Red LED (for program indication)<br />
1 x Green LED (for preview indication)<br />
<br />
<b>TODO:</b><br />
Switch to API mode to use the XBees builtin output to minimize the client cost.<br />
Actually write the client.
<br />
<b>GPL licensed:</b>
To cite Kasper from his own project: <br/>
<i>"The library is licensed under GNU GPL v3. It allows you to use the library for any project, even commercial ones, as long as you keep the code using the library open - and deliver a copy to your client. In other words, even though you might deliver a black box hardware device, you still must give your client a copy of the Arduino sketch you have uploaded to the board. And who knows; either they will improve your product, maybe do nothing at all - or mess it up so you can sell some support hours. :-)"</i><br />
