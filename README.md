# UDPconnection

A simple UDP connection implementation using socket programming in C language which facilitate chatting using two different terminal 
over a local host only. 

NOTE: 
A simple UDP connection can be established without calling bind api at client at too but bind api is must for server end or sender end. 
Not calling bind api at client end doesn't mean that it's not get called.. It's called by OS itself. But At server end you have to call the bind api yourself explicitly or you won't have the required address where to send your message or data. 

serverUDP.c
clientUDP.c 
The above two file shows this concept. 
