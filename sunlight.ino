// This #include statement was automatically added by the Particle IDE.
#include "lib1.h"

int photo_res = A2;

void setup()
{
    pinMode(photo_res, INPUT);
}

bool published = false;

void loop ()
{
    int light = analogRead(photo_res);
    
    if (light > 1 && published == false)
    {
        published = true;
        Particle.publish("light", "It is bright in your environment", PRIVATE);
    }
    
    if (light < 1 && published == true)
    {
        published = false;
        Particle.publish("light", "It is dark in your environment", PRIVATE);
    }
    
    delay(15000);
}