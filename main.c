/* BILL CLINTON: ULTIMATE WARRIOR */
/* Created by alfalfa */

/*include block*/
#include <stdio.h>
#include <sys/time.h>

/*structure and type defs*/
struct entity {
    unsigned char name[64];
    unsigned long maxhp;
    unsigned int level;
    signed long health; /*signed because if it were unsigned, it would wrap around, making attacking require additional checks. may change in update*/
    unsigned int strength;
    unsigned int curstr;
    unsigned int curdef;
    unsigned int defense;
    unsigned int magic;
    unsigned int curmag;
    unsigned char abilities[64]; /*used char because it is the shortest measurement. all values are either 1 or 0, true or false, respectively*/
    unsigned char inventory[256]; /* ^ */
    };
typedef struct entity ent;
struct faction {
    unsigned char name[64];
    ent *leader;
    };
typedef struct faction fact;

/*entities are external vars, these lists keeps track of them*/
ent *elist[256];
ent *essentials[256];
ent *nlist[256]; /*null list used in clearing elist*/
/*function declarations*/
void newgame(void);
int baserng(int); /*generate random number, 1-10*/
int stdrng(void); /*typically used rng; character based, uses baserng*/
void clearcharbuffer(void); /*clears the entity buffer, copies essentials into it*/
void lcopy(ent **, ent **, int); /*copies array 1 to array 2*/

void lcopy(ent **l1, ent **l2, int buffer) {
    int i = 0;
    while(buffer-- ){
        *(l2+i) = *(l1+i);
        i++;
        }
    return;
    }


void clearcharbuffer(void) {
    extern ent *essentials[];
    extern ent *elist[];
    extern ent *nlist[];
    lcopy(nlist, elist, 256); /*clears elist*/
    lcopy(essentials, elist, 256); /*refills elist*/


    }


int main(){newgame();}


int stdrng(void) {
    extern ent *elist[];
    ent *player;
    player = elist[0];
    int seed;
    seed = ((player->level + player->strength + player->defense + player->magic)/4);
    return rng(rng(rng(seed))+seed);
    }
int rng(int seed) {
    return (((time(NULL)+seed)%10)+1);
    }
void newgame(void) {
    extern ent *elist[];
    ent player;
    *(player.name) = "Bill Clinton";
    player.health = 25;
    player.maxhp = 25;
    player.strength = 5;
    player.curstr = 5;
    player.defense = 5;
    player.curdef = 5;
    player.magic = 5;
    player.curmag = 5;
    essentials[0] = &player;
    printf("It is a dark time in America. A dark time of fear, war, and plague.\nSorrow runs rampant, as fear courses through the veins of innocence.\nBarack Hussein Obama has just been elected.\nOnly you, Bill Clinton, can stop this massacre of American values.\n\n");
    clearcharbuffer();
    }
