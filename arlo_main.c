/*
  Arlo - Test Ping Array.c
*/

#include "simpletools.h"
#include "arlodrive.h"
#include "ping.h"

int n = 0, pingPin, cmDist;
int pins[3] = {0, 1, 2};

int main()
{
  drive_speed(0, 0);
  while(1)
  {
    drive_speed(30, 30);
    if(n == 0)
    {
      print("%c", HOME);
      print("Ping))) Distances\n");
      print("-----------------\n");
    }
    
    pingPin = pins[n];
    cmDist = ping_cm(pingPin);
    
    switch(pingPin)
    {
      case 0: print("Front: "); break;
      case 1: print("Left:  "); break;
      case 2: print("Right: "); break;
    }
    
    print("%03d cm\n", cmDist);
    
    while(ping_cm(pingPin) < 35)
    {
      switch(pingPin)
      {
        case 0: drive_speed(-20, -20); pause(800); if(rand() % 2 == 1){drive_speed(-20,20);}else{drive_speed(20,-20)} pause(300); break;
        case 1: drive_speed(20, -20); break;
        case 2: drive_speed(-20, 20); break;
      }      
    }    
    n++;
    if(n >= 3) n =0;
    pause(200);
  }    
}    