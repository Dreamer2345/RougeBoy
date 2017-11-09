#pragma once
#define MAXOBJECT 25
#define CENTERX 64
#define CENTERY 32
#define TILE_SIZE 16
#define MAP_HEIGHT  10
#define MAP_WIDTH  10

#define CLOSED_CHEST  0
#define OPEN_CHEST  5

#define BARREL  4
#define EXPLOSIVE_BARREL  16

#define LOCKED_DOOR  2
#define OPEN_DOOR  6 //walkable
#define SPEAR_DOOR  15

#define SWITCH_ON  10
#define SWITCH_OFF  11
 

#define BLANK_WALL  1
#define FULL_BLOCK_WALL  7
#define WINFDOW_WALL  13
#define TORCH_WALL  12
#define SIGN_WALL  14


#define UP_STAIRS  9
#define DOWN_STAIRS  3 //Walkable
#define LOCKED_STAIRS  17

#define EMPTY  8 //Walkable
#define OFFSET 5



/*
 * MAP DEFINITIONS
 * 0 - Closed_chest
 * 1 - Blank_Wall
 * 2 - Locked_Door
 * 3 - Stairs_Down
 * 4 - Barrel
 * 5 - Open_chest
 * 6 - Open_Door
 * 7 - Full_Block_Wall
 * 8 - Blank Space
 * 9 - Stairs_UP
 * 10 - Switch_ON
 * 11 - Switch_OFF
 * 12 - Wall_Torch
 * 13 - Window_Wall
 * 14 - Sign_wall
 * 15 - Spear_Door
 * 16 - explosive_barrel
 * 17 - Locked_Stairs_Down
 */


const uint8_t PROGMEM MAP_1[] ={
  //Map Dimentions
  MAP_HEIGHT,MAP_WIDTH,
  //PLAYER STARTING POSITION    
  0,0,
  //MAP DATA
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,
  //Number of Objects
  2,
  //Objects
  //<ID><xpos><ypos><Health>
  1,2,2,0,
  1,2,2,0,
  };

 
byte Level;

const uint8_t * Maps[] = {MAP_1}; 
uint8_t Map[MAP_WIDTH*MAP_HEIGHT];



uint8_t GetBlock(int x,int y){
    if ((x < 0) || (y < 0) || (x > MAP_WIDTH) || (y > MAP_HEIGHT)){
      return BLANK_WALL;
      }
    uint8_t Block = Map[(x+(y*MAP_WIDTH))];
    return Block;
}




bool Walkable(int x,int y) {
  bool Walk = false;
  switch (GetBlock(x/16,y/16)){
    case OPEN_DOOR: Walk = true; break;
    case DOWN_STAIRS: Walk = true; break;
    case EMPTY: Walk = true; break;
    }
  return Walk;
}









  