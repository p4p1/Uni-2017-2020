This document guides you how to communicate with the server

1) The Client connects on the server by using the given host and the given port

2) Once you are connected to the server, you can send theses messages to communicate with the server:
   1. "id:[CLIENT ID]"
      sets the id of the client

   2. "pw:[CLIENT PWD]"
      sets the password of the client

   3. "createroom:[ROOMNAME]:[PORT]"
      create a communication room and the client will automaticly join the room

   4. "joinroom:[ROOMNAME]"
      join your target room to start conversation

   5. "exit"
      quit the room of you have one

   6. "request"
      request every informations that are required for the UDP communication

3) By sending theses informations to the server, you will get responses as follow:

   [type of message]:[status]

cf. "id:OK" or "pw:KO"

4) When the server checks the room and if there is more than 2 client on the same room, the server will be ready to send every informations that will be used for the UDP communications. (cf. ip, port)