#include "audio.hpp"
#include "Opus.hpp"
#include <iostream>
#include <unistd.h>

int main(int ac, char **av)
{
   audio od_server;
   audio od_client;
   Opus codec;

   paTestData test = od_server.record();
   od_client.play(test);
   printf("%f\n", test.recordedSamples[1000]);
   unsigned char *encoded = codec.encode(test);
   paTestData decoded = codec.decode(encoded);
   od_server.play(decoded);
   printf("%f\n", decoded.recordedSamples[1000]);
   od_client.play(decoded);
   printf("%f\n", decoded.recordedSamples[1000]);
   return (0);
}