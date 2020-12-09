
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
			void go_south_east(int* lat, int* lon)
			{
				*lat = *lat - 1;
				*lon = *lon + 1;
			}
			void go_south_west(int* lat, int* lon)
			{
				*lat = *lat + 1;
				*lon = *lon - 1;
			}
			void go_north(int* lat, int* lon)
			{
				*lat = *lat + 1;

			}
			void go_south(int* lat, int* lon)
			{
				*lat = *lat - 1;

			}
			void go_east(int* lat, int* lon)
			{
				*lon = *lon + 1;

			}
			void go_west(int* lat, int* lon)
			{
				*lon = *lon - 1;

			}
			int main()
			{
				char direction[3];
				int days = 1;
				int food = 1000;
				int latitude = 32;
				int longitude = -64; 
				int program_end = 0;      
				printf("you are lost in the bermuda rectangle! you have to make it out before you run out of food.\n");
				printf("there are 10 members of the crew so every day you lose 10 food.\n");
				printf("to start out with you have 1000 food, but you might catch some fish.\n");
				printf("all we know is that we have to get to [1, 1].\n");
				printf("we are currently at: [%i, %i]\n", latitude, longitude);
				printf("se = south east, sw = south west, n = north, s = south, w = west, e = east.\n");
				while (program_end != 1)
				{
					
					int fish = rand() % 100;
					int wheel_of_fortune = rand() % 100; 
					food = food - 10;
					days = days + 1;
					printf("point the sail, captain: ");
					scanf_s("%2s", direction, 3);
					if (strcmp(direction, "se") == 0)
					{
						go_south_east(&latitude, &longitude);
					}
					else if (strcmp(direction, "sw") == 0)
					{
						go_south_west(&latitude, &longitude);
					}
					else if (strcmp(direction, "n") == 0)
					{
						go_north(&latitude, &longitude);
					}
					else if (strcmp(direction, "s") == 0)
					{
						go_south(&latitude, &longitude);
					}
					else if (strcmp(direction, "w") == 0)
					{
						go_west(&latitude, &longitude);
					}
					else if (strcmp(direction, "e") == 0)
					{
						go_east(&latitude, &longitude);
					}
					printf("avast! now at: [%i, %i]\n", latitude, longitude);
					
					switch (wheel_of_fortune) 
					 {
					 case 1:
						 food = food + 20;
						 printf("a crew member caught 5 fish worth 20 food!\n");
						 break;
					 case 33:
					   	 food = food + 10;
						 printf("a crew member caught 2 fish worth 10 food!\n");
						 break;
					 case 69:
						 food = food + fish; 
						 printf("a crew member caught %i fish with a fishing net worth %i food!\n", fish, fish); 
						 break;
					 case 100:
						 food = food - 5;
						 printf("a crew member got sick and requiered more food.\n you lost 5 food.\n");
						 break;
					 case 55:
						 food = food - 20;
						 printf("there was a storm which ruined some food.\n you lost 20 food.\n");
						 break;
					 case 46:
						 food = food - 200;
						 printf("there was a hole in the ship!\n you lost 200 food!\n");
						 break;
					 case 27:
						 food = food + fish; 
						 printf("you got lucky and found a tresure chest with some food\n you got %i food!\n", fish); 
						 break;
					 case 80:
						 food = food - 700;
						 printf("your ship got fucking robbed by pirates\n you lost 400 food and tooth\n");
						 break;
					 default:
						 printf("nothing happened today\n");
						 break;
					 }
					printf("you have %i food left\n", food);
					printf("it is day %i\n", days);
					if (food <= 0)
					 {
						 printf("looks like you are out of food\n game over\n :(\n");
						 printf("you lasted %i", days);
						 program_end = 1;  
					 }
					if (latitude == 1 && longitude == 1) 
					 {
						 printf("you escaped!\n you made it to the mainland\n");
						 printf("it took %i", days);
						 printf("you had %i leftovers\n :)\n", food);
							program_end = 1;
					 }
				}
				 int end = 0; 
				while (end != 1) 
				 {   
					 char stop[3];
					 printf("press l to leave the game: ");
					 scanf_s("%2s", stop, 3); 
					 if (strcmp(stop, "l") == 0) 
					  {
						 end = 1; 
					  }
				 }
				return 0;
			}
		
	