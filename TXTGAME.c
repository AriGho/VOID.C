#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>






void delay(unsigned int mseconds)//Timer Module
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void combat(char playerName[],char gender[],char slot2[],char enemy[],int ammo,int lvl,int exp)//Combat Module
{
	
char his_her [50];
int itemDMG=0;
int enemyDMG;
int enemyHealth;
int playerHealth=10;

if(lvl >= 1)
{
itemDMG = (lvl + itemDMG - 1);
playerHealth = (lvl * 5 + playerHealth);
}  
   
if (strcmp(slot2,"PISTOL"))
     itemDMG = (itemDMG + 2);
else if(strcmp(slot2,"BLASTER"))
     itemDMG = (itemDMG + 4);
else if(strcmp(slot2,"LASER RIFLE"))
     itemDMG = (itemDMG + 7);

if (strcmp(slot2,"PISTOL"))
     itemDMG = (itemDMG + 2);
else if(strcmp(slot2,"BLASTER"))
     itemDMG = (itemDMG + 4);
else if(strcmp(slot2,"LASER RIFLE"))
     itemDMG = (itemDMG + 7);
     
if(strcmp(enemy,"ROBOT" )==0)
{
enemyDMG=3;
enemyHealth=6;
}
else if(strcmp(enemy,"DROID" )==0)
{
enemyDMG=4;
enemyHealth=10;
}
else if(strcmp(enemy,"MECHA" )==0)
{
enemyDMG=6;
enemyHealth=15;
}
else if(strcmp(enemy,"BOSS MECHA" )==0)
{
enemyDMG=8;
enemyHealth=30;
}

while (playerHealth !=0 && enemyHealth !=0)
{

if (strcmp(gender,"M" )==0)
{
strcpy(his_her,"his");
}
else if (strcmp(gender,"F")==0)
{
strcpy(his_her,"her");  
}
	
int eAttackChance = randomNum(eAttackChance,0,4); 
if (eAttackChance == 4)
{
playerHealth = playerHealth - enemyDMG;
printf("Enemy %s fires on %s",enemy,playerName);
printf("\t\t\t                               \n");
delay(2000);
printf("Enemy %s successfully hits %s for %d Hp.",enemy,playerName,enemyDMG);
printf("\t\t\t                               \n");
delay(2000); 
if (playerHealth <= 0)
{
printf("Your vision turns dark as you hit the floor.");
printf("\t\t\t                               \n");
delay(2000);
printf("You have died. Your journey ends here.");
printf("\t\t\t                               \n");
delay(2000);
exit(0);//exit
}
printf("Press any button to attack!");
printf("\t\t\t                               \n");
getch(); 	     
}
else
{
printf("Enemy %s fails to hit %s.",enemy,playerName);
printf("\t\t\t                               \n");
delay(2000);
printf("Enemy %s does no damage to %s",enemy,playerName);
printf("\t\t\t                               \n");
delay(2000);
printf("%s has %d health remaining",playerName,playerHealth);
printf("\t\t\t                               \n");
delay(2000);
}
int playerAttackChance = randomNum(playerAttackChance,0,2);
if (playerAttackChance == 2)
{
enemyHealth = enemyHealth - itemDMG;
ammo-=1;
printf("%s fires on enemy %s with %s %s",playerName,enemy,his_her,slot2);
printf("\t\t\t                               \n");
delay(2000);
printf("%s successfully hits enemy %s for %d Hp.",playerName,enemy,itemDMG);
printf("\t\t\t                               \n");
delay(2000); 
{
if(enemyHealth <= 0)
{
printf("%s successfully defeats enemy %s.",playerName,enemy);
printf("\t\t\t                               \n");
delay(2000);
printf("%s has %d Hp left.",playerName,playerHealth);
printf("\t\t\t                               \n");
delay(2000);
printf("%s has %d ammo left in %s",playerName,ammo,slot2);
printf("\t\t\t                               \n");
delay(2000);
printf("Press any button to continue.");
printf("\t\t\t                               \n");
getch(); 
break;
}
else
{
ammo-=1;
if (enemyHealth <= 0)
{
printf("%s successfully defeats enemy %s.",playerName,enemy);
printf("\t\t\t                               \n");
delay(2000);
printf("%s has %d Hp left.",playerName,playerHealth);
printf("\t\t\t                               \n");
delay(2000);
printf("%s has %d ammo left in %s",playerName,ammo,slot2);
printf("\t\t\t                               \n");
delay(2000);
printf("Press any button to continue.");
printf("\t\t\t                               \n");
getch();
break;
}
printf("%s fires on enemy %s with %s %s",playerName,enemy,his_her,slot2);
printf("\t\t\t                               \n");
delay(2000);
printf("%s misses the enemy %s",playerName,enemy);
printf("\t\t\t                               \n");
delay(2000); 
printf("%s has %d Hp left.",enemy,enemyHealth);
printf("\t\t\t                               \n");
delay(2000); 
printf("Press any button to attempt to dodge.");
printf("\t\t\t                               \n");
getch(); 
}  
}
}
}
exp = 5;
printf("Phew! That was close!");
printf("\t\t\t                               \n");
delay(2000);
printf("You gain %d exp points from defeating enemy %s.",exp,enemy);
printf("\t\t\t                               \n");
delay(2000);
}

int levelup(int exp,int lvl);

int randomNum(int chance,int min_num, int max_num)//Engine to generate numbers for combat and exploration.
        {
            int result=0,low_num=0,hi_num=0;
            if(min_num<max_num)
            {
                low_num=min_num;
                hi_num=max_num+1; // this is done to include max_num in output.
            }else{
                low_num=max_num+1;// this is done to include max_num in output.
                hi_num=min_num;
            }
            srand(time(NULL));
            result = (rand()%(hi_num-low_num))+low_num;
            chance = result;
            return chance;   
        }



void trade(char playerName[],int credits,int K,int medipak,int ammo,int batt,char slot1[])//Trade Module
{
int num1,x;
char game [50], cont [50], replay [50];
int quit=0,sw;
	
while(!quit)
{
printf("       ||YOU APPROACH THE CONSOLE||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||WELCOME %s||",playerName);
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||PLEASE SELECT AN OPTION||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||1. BUY||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||2. SELL||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||3. hAcK||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||4. EXIT||");
printf("\t\t\t                               \n"); 
delay(2000);
scanf("%d",&sw);
switch(sw)
{
case 1:
{
printf("The console displays the variety of goods on sale");
printf("\t\t\t                               \n"); 
delay(2000);
printf("\t\t\t                    _____            \n");
printf("\t\t\t                   |     |           \n");
printf("\t\t\t                   | | | |           \n");
printf("\t\t\t                   |_____|           \n");
printf("\t\t\t             ____ ___|_|___ ____     \n");
printf("\t\t\t            ()___)         ()___)    \n");
printf("\t\t\t           |/ | |VENDROTRON | | /|    \n");
printf("\t\t\t           |/ | |   MK - 1  | | /|   \n");
printf("\t\t\t          (___) |___________| (___)  \n");
printf("\t\t\t          (___)   (_______)   (___)  \n");
printf("\t\t\t          (___)     (___)     (___)  \n");
printf("\t\t\t          (___)      |_|      (___)  \n");
printf("\t\t\t          (___)  ___|___|___   | |   \n");
printf("\t\t\t           | |  |           |  | |   \n");
printf("\t\t\t           | |  |___________| |___|  \n");
printf("\t\t\t          |___|  |||     ||| ||   || \n");
printf("\t\t\t          (( ))  |||     ||| ((   ))  \n");
printf("\t\t\t                ()__)   (__()        \n");
printf("\t\t\t                |||       |||        \n");
printf("\t\t\t               |||         |||       \n");
printf("\t\t\t             _|||___     ___|||_     \n");
printf("\t\t\t            |_______|   |_______|    \n");
delay(2000);
int by;
printf("       ||PLEASE SELECT A WARE||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||1. MEDI-PAK (Hp) - 30 CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||2. AMMO - 5 ROUNDS/50 CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||3. BATTERY - 1 UNIT/60 CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||4. BACK||");
printf("\t\t\t                               \n"); 
delay(2000);
scanf("%d",&by);
switch(by)
{
case 1:
{	
if(credits<35)
{
printf("          ||YOU HAVE INSUFFICIENT CREDITS||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE MORE CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
}
else
{
printf("          ||MEDI-PAK (Hp) TRANSFERED||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits-=30);
printf("\t\t\t                               \n");
delay(2000);
medipak += 1;
}
break;
}
case 2:
{
if(credits<50)
{
printf("          ||YOU HAVE INSUFFICIENT CREDITS||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE MORE CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);	
}
else
{
printf("          ||AMMO TRANSFERED||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits-=50);
printf("\t\t\t                               \n");
delay(2000);
ammo += 5;
}
break;	
}
case 3:
{
if(credits<60)
{
printf("          ||YOU HAVE INSUFFICIENT CREDITS||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE MORE CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);	
}
else
{
printf("          ||BATTERY TRANSFERED||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits-=60);
printf("\t\t\t                               \n");
delay(2000);
batt += 1;
}
break;	
}
case 4:
{
printf("          ||COME BACK FOR BUSINESS LATER||");
printf("\t\t\t                               \n"); 
delay(2000);
break;	
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;	
}
}
break;
}
case 2:
{
printf("The console displays your inventory to sell.");
printf("\t\t\t                               \n"); 
delay(2000);
printf("\t\t\t                    _____            \n");
printf("\t\t\t                   |     |           \n");
printf("\t\t\t                   | | | |           \n");
printf("\t\t\t                   |_____|           \n");
printf("\t\t\t             ____ ___|_|___ ____     \n");
printf("\t\t\t            ()___)         ()___)    \n");
printf("\t\t\t           |/ | |VENDROTRON | | /|    \n");
printf("\t\t\t           |/ | |   MK - 1  | | /|   \n");
printf("\t\t\t          (___) |___________| (___)  \n");
printf("\t\t\t          (___)   (_______)   (___)  \n");
printf("\t\t\t          (___)     (___)     (___)  \n");
printf("\t\t\t          (___)      |_|      (___)  \n");
printf("\t\t\t          (___)  ___|___|___   | |   \n");
printf("\t\t\t           | |  |           |  | |   \n");
printf("\t\t\t           | |  |___________| |___|  \n");
printf("\t\t\t          |___|  |||     ||| ||   || \n");
printf("\t\t\t          (( ))  |||     ||| ((   ))  \n");
printf("\t\t\t                ()__)   (__()        \n");
printf("\t\t\t                |||       |||        \n");
printf("\t\t\t               |||         |||       \n");
printf("\t\t\t             _|||___     ___|||_     \n");
printf("\t\t\t            |_______|   |_______|    \n");
delay(2000);
int sy;
printf("       ||PLEASE SELECT A WARE TO SELL||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||1. MEDI-PAK (Hp) - 15 CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||2. AMMO - 5 ROUNDS/25 CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||3. BATTERY - 1 UNIT/30 CREDITS||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||4. PAWN/SELL||");
printf("\t\t\t                               \n"); 
delay(2000);
printf("       ||5. EXIT||");
printf("\t\t\t                               \n"); 
delay(2000);
scanf("%d",&sy);
switch(sy)
{
case 1:	
{
if(medipak>=1)
{
printf("          ||MEDI-PAK (Hp) TRANSFERED||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits+=15);
printf("\t\t\t                               \n");
delay(2000);
medipak -= 1;
}
else
{
printf("          ||YOU HAVE INSUFFICIENT MEDI-PAKS||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE MORE||");
printf("\t\t\t                               \n"); 
delay(2000);	
}
break;
}
case 2:
{
if(ammo>=5)
{
printf("          ||AMMO TRANSFERED||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits+=25);
printf("\t\t\t                               \n");
delay(2000);
ammo -= 5;
}
else
{
printf("          ||YOU HAVE INSUFFICIENT  AMMO||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE MORE||");
printf("\t\t\t                               \n"); 
delay(2000);	
}
break;
}
case 3:
{
if(batt>=1)
{
printf("          ||BATTERY TRANSFERED||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits+=30);
printf("\t\t\t                               \n");
delay(2000);
batt -= 1;
}
else
{
printf("          ||YOU HAVE INSUFFICIENT BATTERIES||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE MORE||");
printf("\t\t\t                               \n"); 
delay(2000);	
}
break;
}
case 4:
{
if(strcmp(slot1,"gold") == 0 )	
{
printf("          ||LOOT PAWNS FOR 150 CREDITS||");
printf("\t\t\t                               \n");
delay(2000);	
slot1[0] = 0;
credits += 150;
printf("          ||YOU HAVE %d CREDITS REMAINING||",credits);
printf("\t\t\t                               \n");
delay(2000);
}
else
{
printf("          ||YOU HAVE NOTHING TOO PAWN||");
printf("\t\t\t                               \n");
delay(2000);
printf("          ||COME BACK WHEN YOU HAVE SOMETHING||");
printf("\t\t\t                               \n"); 
delay(2000);	
}
break;	
}
case 5:
{
printf("          ||COME BACK FOR BUSINESS LATER||");
printf("\t\t\t                               \n"); 
delay(2000);
break;	
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;	
}
}
break;
}
case 3:
{
printf("The console displays........");
printf("\t\t\t                               \n"); 
delay(2000);
printf("          ||HACKING UNDERWAY||     ");
printf("\t\t\t                               \n");
delay(2000);
{
srand(time(NULL));
printf("Would you like to crack the code?");
scanf("%s",&game);
if ( strcmp(game,"y") == 0  || strcmp(game,"Y") == 0 )
{

    printf("\nThe rules are simple. You have have 5 tries to guess the computer's number. \n \n If you succeed you win the game, if you dont you lose the game. Good luck!");
    do
	{
    int r = rand()%25 +1;
    printf("\n\nEnter a number between 1 and 5 : ");
    scanf("%d",&num1);
    do
	{
    for(x=1; x<=3; x++)
	{
    if(num1 < r)
	{
        printf("\nClose! try a little higher... : ");
    }
    else if (num1 > r)
	{
        printf("\nClose! try a little lower...: ");
    }
    scanf("%d",&num1);
    }
    }while(num1!=r || x <= 3);
    printf("\nWinner! >> you entered %d and the computer generated %d! \n",num1, r);
    printf("\nWould you like to play again? (y or n) : ");
    scanf("\n%s",&replay);
    }while(strcmp(replay,"y")==0 || strcmp(replay,"Y")==0 );
    }
    printf("Thanks for playing! ");

    if (strcmp(game,"n") ==0  || strcmp(game,"N") ==0 )
	{
    printf("Okay, maybe next time! ");
    }	
}
printf("Machine appears to be hacked.");
printf("\t\t\t                               \n"); 
delay(2000);
printf("You get credited with 200 credits.");
printf("\t\t\t                               \n"); 
delay(2000);
credits+=200;
K-=5;
printf("You lose Karma for stealing.");
printf("\t\t\t                               \n"); 
delay(2000);
break;
}
case 4:
{
printf("          ||COME BACK FOR BUSINESS LATER||");
printf("\t\t\t                               \n"); 
delay(2000);
quit=1;
break;	
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;	
}
}
}
}








int main()
{
char s[20],l[20],a[20],i[20],c[20],k[20],fl[20],gender[20],ag[20];//convert age and flag to suitable form before converting to string.
int S,L,A,I,C,R = 25,age,K = 50,flag=0;
char number[10][20];
int x1 = 0;
char playerName[20];
int choi;
     printf("\n\t\t\tMAIN MENU:\n");
     printf("\t\t\t*_______________________________*\n");
     delay(2000);
     printf("\t\t\t1.NEW GAME\n");
     printf("\t\t\t*_______________________________*\n");
     delay(2000);
     printf("\t\t\t2.LOAD GAME\n");
     printf("\t\t\t*_______________________________*\n");
     delay(2000);
     printf("\t\t\t3.EXIT\n");
     printf("\t\t\t*_______________________________*\n");
     delay(2000);
     printf("Enter your choice:\t");
     scanf("%d",&choi);
     switch (choi)
     {
            case 1:
                 break;
            case 2:
            	{ 
                  FILE *fpload = fopen("d:\\game_data.txt","r"); /*CREATE THE TEXT FILE IN THE DIRECTORY*/
                  if (fpload == NULL) 
                  { 
				  printf("Couldn't open game data for reading.\n");
                  exit(0);
				  }

                
                         while( !feof(fpload))
                        {
                        for(x1=0;x1<=9;x1++)
                        
                        {
                       
                         fscanf(fpload,"%s",&number[x1]); 
                       
                        }
                        
                        }
                  
                 break;
             }
            case 3:
                 exit(0);
     }
     
      x1 = 0;
      strcpy(playerName,number[x1]);
      x1+=1;
      strcpy(gender,number[x1]);
      x1+=1;
      strcpy(ag,number[x1]);
      x1+=1;
      strcpy(s,number[x1]);
      x1+=1;
      strcpy(l,number[x1]);
      x1+=1;
      strcpy(a,number[x1]);
      x1+=1;
      strcpy(i,number[x1]); 
      x1+=1;
	  strcpy(c,number[x1]);
	  x1+=1;
	  strcpy(k,number[x1]);
	  x1+=1;
	  strcpy(fl,number[x1]);

	  
                   S= atoi(s);
                   L= atoi(l);
                   A= atoi(a);
                   I= atoi(i);
                   C= atoi(c);
                   K= atoi(k);
                   flag= atoi(fl);
                   age= atoi(ag);
				 				       
if(flag==1)
            {
             goto A;
            }
            
            else if(flag==2)
            {
             goto B;
            }
            
            else if(flag==3) 
			{      
             goto C;  
	     	}
			else if(flag==4)
			{
			goto D;
			}
			 	
printf("\t\t\t*_______________________________*\n");
delay(2000);
printf("\t\t\t.##.....##..#######..####.########.\n");
printf("\t\t\t.##.....##.##.....##..##..##.....##\n");
printf("\t\t\t.##.....##.##.....##..##..##.....##\n");
printf("\t\t\t.##.....##.##.....##..##..##.....##\n");
printf("\t\t\t..##...##..##.....##..##..##.....##\n");
printf("\t\t\t...##.##...##.....##..##..##.....##\n");
printf("\t\t\t....###.....#######..####.#######.\n");
delay(2000);
printf("\t\t\t*_______________________________*\n");
printf("\t\t\t                               \n"); 
printf("\t\t\t                               \n"); 
printf("\t\t\t                               \n"); 
printf("In the cold outer reaches of space, a bubble of life glides silently. \n");
printf("\t\t\t                              \n");
delay(2000);
printf("It is here that you find yourself awakening.\n"); 
printf("\t\t\t                               \n"); 
delay(2000);
printf("The light seems to blind you as you try to open your eyes.\n"); 
printf("\t\t\t                               \n");
delay(2000);
printf("You find yourself in a metal cylinder with a glass panel standing upright.\n"); 
printf("\t\t\t                               \n");
delay(2000); 
printf("The panel fogs with your hot breath.\n");
printf("\t\t\t                               \n"); 
delay(2000);
printf("It appears to have something written on it.\n"); 
printf("\t\t\t                               \n");
delay(2000); 
printf("You try to read the inscription on the glass.\n"); 
printf("\t\t\t                               \n");
delay(2000); 
printf("\t\t\t                               \n");
printf("          ||TO INITIATE RELEASE PRESS THE RED BUTTON NEXT TO YOUR RIGHT PALM||\n");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                               \n");
delay(2000);  
printf("You look down and see a red button next to your palm.\n"); 
printf("\t\t\t                               \n");
delay(2000); 
printf("Press any key to initiate release procedure.\n");
getch(); 
printf("\t\t\t                               \n");
delay(2000); 
printf("A computer screen slides down to your face.\n"); 
printf("\t\t\t                               \n");
delay(2000);
//Enter your name
printf("          ||ENTER YOUR NAME||\n"); 
printf("\t\t\t                               \n");
scanf("%s",&playerName);
//Enter your gender
printf("          ||ENTER YOUR GENDER (M/F)||\n"); 
printf("\t\t\t                               \n");
scanf("%s",&gender);
while(strcmp(gender,"M")!=0 && strcmp(gender,"F")!=0)
{
printf("          ||INCORRECT DATA ENTRY. RE-ENTER DATA.||\n"); 
printf("\t\t\t                               \n");
scanf("%s",&gender);
}
//Enter your age
int playerAge;
printf("          ||ENTER YOUR AGE||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&playerAge);
while (playerAge < 18 || playerAge >= 100)
{
printf("          ||INCORRECT DATA ENTRY. RE-ENTER DATA.||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&playerAge);
}
Q:printf("          ||ENTER YOUR STATS||\n");
printf("\t\t\t                               \n");
printf("          ||POINTS REMAINING 25||\n"); 
printf("\t\t\t                               \n");
printf("            ||STRENGTH (1 - 10)||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&S);
while ( S < 1 || S > 10 )
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
scanf("%d",&S);
}
R -= S;
printf("          ||POINTS REMAINING %d||\n",R); 
printf("\t\t\t                               \n");
printf("            ||LUCK (1 - 10)||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&L);
while ( L < 1 || L > 10 )
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
scanf("%d",&L);
}
R -= L;
printf("          ||POINTS REMAINING %d||\n",R); 
printf("\t\t\t                               \n");
printf("            ||AGILITY (1 - 10)||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&A);
while ( A < 1 || A > 10 )
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
scanf("%d",&A);
}
R -= A;
printf("          ||POINTS REMAINING %d||\n",R); 
printf("\t\t\t                               \n");
if (R <= 0)
{
 goto J;
}
printf("            ||INTELLIGENCE (1 - 10)||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&I);
while ( I < 1 || I > 10 )
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
scanf("%d",&I);
}
R -= I;
printf("          ||POINTS REMAINING %d||\n",R); 
printf("\t\t\t                               \n");
if (R <= 0)
{
 goto J;
}
printf("            ||CHARISMA (1 - 10)||\n"); 
printf("\t\t\t                               \n");
scanf("%d",&C);
while ( C < 1 || C > 10 )
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
scanf("%d",&C);
}
R -= C;
printf("          ||POINTS REMAINING %d||\n",R); 
printf("\t\t\t                               \n");
if (R <= 0)
{
 goto J;
}
//Method to check entry of stats
{
J:printf("          ||OUT OF POINTS||");
printf("\t\t\t                               \n");
printf("          ||YOU HAVE SELECTED THE FOLLOWING STATS||");
printf("\t\t\t                               \n");
printf("          ||STRENGTH||");
printf("\t\t\t                               \n");
printf("%d",S);
printf("          ||LUCK||");
printf("\t\t\t                               \n");
printf("%d",L);
printf("          ||AGILITY||");
printf("\t\t\t                               \n");
printf("%d",A);
printf("          ||CHARISMA||");
printf("\t\t\t                               \n");
printf("%d",C);
printf("          ||INTELLIGENCE||");
printf("\t\t\t                               \n");
printf("%d",I);
goto X;
}
char ans [50];
X:printf("        ||IS THIS YOUR FINAL SELECTION? (Y/N)||");
printf("\t\t\t                               \n");
scanf("%s",&ans);
if((strcmp(ans,"Y")!=0) && (strcmp(ans,"y")!=0))
{
printf("          ||INITIATING PROCESS AGAIN||");
goto Q;	
}
{
printf("          ||YOUR NAME IS %s||",playerName);
printf("\t\t\t                               \n");
printf("          ||YOUR GENDER IS %s||",gender);
printf("\t\t\t                               \n");
printf("          ||YOUR AGE IS %d||",playerAge);
printf("\t\t\t                               \n");
printf("          ||YOU HAVE SELECTED THE FOLLOWING STATS||");
printf("\t\t\t                               \n");
printf("          ||STRENGTH||");
printf("\t\t\t                               \n");
printf("%d",S);
printf("          ||LUCK||");
printf("\t\t\t                               \n");
printf("%d",L);
printf("          ||AGILITY||");
printf("\t\t\t                               \n");
printf("%d",A);
printf("          ||CHARISMA||");
printf("\t\t\t                               \n");
printf("%d",C);
printf("          ||INTELLIGENCE||");
printf("\t\t\t                               \n");
printf("%d",I);
}
printf("You step out of the pod.");
printf("\t\t\t                               \n");
delay(2000);
printf("Your eyes now focus on the room");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                       __             __       \n");
printf("\t\t\t                      |_]|           |[_|      \n");  
printf("\t\t\t                      / /,===========./ /      \n");  
printf("\t\t\t                      //:o-----------o://      \n");  
printf("\t\t\t                     /// X  X X X X  X ///     \n");  
printf("\t\t\t                    /// X X  X_X_X  X X ///    \n");  
printf("\t\t\t                __ /// X X   [___]   X X ///_  \n");
printf("\t\t\t               |/_/o X X  1 &/3/&    X X o/_/| \n"); 
printf("\t\t\t               |]_// X X   <//_//>       //_[| \n"); 
printf("\t\t\t                   /// X X   />&</2  X []///   \n");
printf("\t\t\t                    /// X X   []    X []/// \n");     
printf("\t\t\t                     /// X   [] []     ///  \n");                         
printf("\t\t\t                      //:o-----------o://   \n");     
printf("\t\t\t                      /_/`==========='/_/   \n");     
printf("\t\t\t                      /_]/           /[_/   \n"); 
delay(2000);
int sw,quit=0;      
while(!quit)
{
printf("Select one of the following actions :");
printf("\t\t\t                               \n");
delay(2000);
printf("1. Look ouside the ship.");
printf("\t\t\t                               \n");
delay(2000);
printf("2. Inspect the console.");
printf("\t\t\t                               \n");
delay(2000);
printf("3. Exit the room.");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&sw);
switch(sw)
{
case 1:
{
printf("You gaze into the canvas of black speckled by white.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t         *    .  *       .             *  \n");
printf("\t\t\t                      *                                \n");
printf("\t\t\t             *   .        *       .       .       *   \n");
printf("\t\t\t                      *                               \n");
printf("\t\t\t                                     .     .  *        * \n");
printf("\t\t\t          .            .        .                     \n");
printf("\t\t\t      *           *                     *      \n");
printf("\t\t\t                              .    \n");
printf("\t\t\t          *          .   *        \n");
delay(2000);
break;
}

case 2:
{
printf("        ||DATALOG - XX123 CLEARANCE EPSILON .....");
printf("\t\t\t                               \n");
delay(2000);
printf("The rest is just garbled.");
printf("\t\t\t                               \n");
delay(2000);
break;
}

case 3:
{
printf("You exit the room using the elevator.");
printf("\t\t\t                               \n");
delay(2000);
printf("The elevator plays the score of Baby by Justin Beiber....");
printf("\t\t\t                               \n");
delay(2000);
printf("You try to hum loudly to save your ears.");
printf("\t\t\t                               \n");
delay(2000);
quit=1;
break;
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
int opt ,lvl=1,ex,exp=0;
//Inventory Module to check up during game.
char slot1 [50],slot2 [50],slot3 [50];
strcpy(slot1,"EMPTY");
strcpy(slot1,"EMPTY");
strcpy(slot1,"EMPTY");
delay(2000);
printf("The elevator doors open to a dark hallway.");
printf("\t\t\t                               \n");
delay(2000);
printf("You can't see anything clearly.");
printf("\t\t\t                               \n");
delay(2000);
printf("The way ahead looks unsure.");
printf("\t\t\t                               \n");
delay(2000);
printf("You notice a glow emnating froom the floor.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t ||                   ||STAT MONITOR V.3000||                     || \n");
printf("\t\t\t ||   WELCOME %s                                                  || \n",playerName);
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||                                                               || \n"); 
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||                  PRESS ANY BUTTON TO BEGIN                    || \n");
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");                                          
delay(2000);
printf("It's a stat monitor!");
printf("\t\t\t                               \n");
delay(2000);
printf("Strangely it seems to know your name.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any button to open up the stat monitor.");
printf("\t\t\t                               \n");
getch(); 
delay(2000);
ex = 0;
opt = 0;
while(!ex)
{
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t ||                   ||STAT MONITOR V.3000||                     || \n");
printf("\t\t\t ||   WELCOME %s                                                  || \n",playerName);
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||   CHOOSE AN ACTION TO PERFORM:                                || \n");
printf("\t\t\t ||   1.STATS                                                     || \n"); 
printf("\t\t\t ||   2.INVENTORY                                                 || \n");
printf("\t\t\t ||   3.MISSION OBJECTIVE(S)                                      || \n");
printf("\t\t\t ||   4.EXIT GAME                                                 || \n");
printf("\t\t\t ||   5.BACK TO GAME                                              || \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");                                          
delay(2000);
printf("Choose any of the following options.");
printf("\t\t\t                               \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
{
printf("          ||YOUR NAME IS %s||",playerName);
printf("\t\t\t                               \n");
printf("          ||YOUR GENDER IS %s||",gender);
printf("\t\t\t                               \n");
printf("          ||YOUR AGE IS %d||",playerAge);
printf("\t\t\t                               \n");
printf("          ||YOU ARE LEVEL %d||",lvl);
printf("\t\t\t                               \n");
printf("          ||YOU HAVE THE FOLLOWING STATS||");
printf("\t\t\t                               \n");
printf("          ||STRENGTH||");
printf("\t\t\t                               \n");
printf("%d",S);
printf("          ||LUCK||");
printf("\t\t\t                               \n");
printf("%d",L);
printf("          ||AGILITY||");
printf("\t\t\t                               \n");
printf("%d",A);
printf("          ||CHARISMA||");
printf("\t\t\t                               \n");
printf("%d",C);
printf("          ||INTELLIGENCE||");
printf("\t\t\t                               \n");
printf("%d",I);
break;
}
case 2:
{
printf("          ||SLOT 1 -> %s||",slot1);
printf("\t\t\t                               \n");
printf("          ||SLOT 2 -> %s||",slot2);
printf("\t\t\t                               \n");
printf("          ||SLOT 3 -> %s||",slot3);
printf("\t\t\t                               \n");
break;
}
case 3:
{
printf("          ||EXPLORE THE HALLWAY||");
//printf("\t\t\t                               \n");//
break;
}
case 4:
{
exit(0);
break;
}
case 5:
{
ex=1;
break;
}
}
}
printf("You put the stat monitor in your pocket.");
printf("\t\t\t                               \n");
delay(2000);
printf("You decide to continue exploring the ship.");
printf("\t\t\t                               \n");
delay(2000);
int rest = 1;
int out = 0;
while (!out)
{
int kr = randomNum(kr,0,3);	
switch(kr)
{
case 1:
{
printf("You walk the corridor and reach a door.");
printf("\t\t\t                               \n");
delay(2000);
printf("You try to open it but the door is jammed.");
printf("\t\t\t                               \n");
delay(2000);
printf("Oh well, can't always have it all your way then.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to try again.");
printf("\t\t\t                               \n");
getch();
break;
}
case 2:
{
printf("You turn right and see a shiny object on the ground.");
printf("\t\t\t                               \n");
delay(2000);
printf("A closer look reveals it to be gold!");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to pick it up.");
printf("\t\t\t                               \n");
getch();
int c1=1;
strcpy(slot1,"GOLD");
printf("Time to head back on the trail.");
printf("\t\t\t                               \n");
delay(2000);
printf("You walk straight to the end of the dark hallway.");
printf("\t\t\t                               \n");
delay(2000);
printf("The metal creaking overhead makes your palms sweaty.");
printf("\t\t\t                               \n");
delay(2000);
printf("Fumble in the darkness until your hand finds a latch.");
printf("\t\t\t                               \n");
delay(2000);
printf("It's a way out!");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to open the latch.");
printf("\t\t\t                               \n");
getch();
printf("A bright light stings your eyes.");
printf("\t\t\t                               \n");
delay(2000);
out=1;
break;
}
case 3:
{
printf("You walk straight to the end of the dark hallway.");
printf("\t\t\t                               \n");
delay(2000);
printf("The metal creaking overhead makes your palms sweaty.");
printf("\t\t\t                               \n");
delay(2000);
printf("You fumble in the darkness until your hand finds a latch.");
printf("\t\t\t                               \n");
delay(2000);
printf("It's a way out!");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to open the latch.");
printf("\t\t\t                               \n");
getch();
printf("A bright light stings your eyes.");
printf("\t\t\t                               \n");
delay(2000);
out=1;
break;
}
case 4:
{
printf("You walk the corridor but feel your legs aching.");
printf("\t\t\t                               \n");
delay(2000);
printf("You stop to take a little rest.");
printf("\t\t\t                               \n");
delay(2000);
printf("Maybe you should have a healthier lifestyle.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to try again.");
printf("\t\t\t                               \n");
getch();
break;
}
}
}
int c1=1;
printf("The room is almost throbbing with energy.");
printf("\t\t\t                               \n");
delay(2000);
printf("You walk in silence as you look around.");
printf("\t\t\t                               \n");
delay(2000);
printf("What's that over there?");
printf("\t\t\t                               \n");
delay(2000);
printf("It's a corpse on the ground!");
printf("\t\t\t                               \n");
delay(2000);
printf("You walk unsteadily towards it.");
printf("\t\t\t                               \n");
delay(2000);
printf("It seems to be holding a pistol.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to pry away the pistol.");
printf("\t\t\t                               \n");
getch();
int pammo=10;
exp = 0, lvl = 1;
strcpy(slot2,"PISTOL");
printf("The pistol gleams in your hand.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                     _                                        \n");                             
printf("\t\t\t                    |_t+.__________________......_  /;_       \n");
printf("\t\t\t                    ;________________/     :    / t""o./__    \n");
printf("\t\t\t                    :---|------------------t-----^-`--'  /    \n");
printf("\t\t\t                     |__L___________________/____________/    \n");
printf("\t\t\t                                ''-. o .--. /--'/  l  .-t+.   \n");
printf("\t\t\t                                       | (   l) ;""   : /     \n");
printf("\t\t\t                                        l `--'' o;      Y      \n");
printf("\t\t\t                                        '''''';:  .-. : |      \n");
printf("\t\t\t                                              ::  '-'  ;|    \n");
printf("\t\t\t                                               ;;      :|   \n");
printf("\t\t\t                                               ::       ;   \n");
printf("\t\t\t                                               ;'-------'   \n");
printf("\t\t\t                                                '-------'    \n");
delay(2000);            
printf("You can always check your weapon using the stat monitor.");
printf("\t\t\t                               \n");
delay(2000);
printf("With some firepower you feel relaxed and continue.");
printf("\t\t\t                               \n");
delay(2000);
//Checkpoint A
{
int c1;
printf("Do you want to save your data?\n1.Yes\n2.No\nSelect your choice:");
scanf("%d",&c1);
switch (c1)
      { case 1:
	           //convert to string
	           flag+=1;
	           itoa(age,ag,10);
	           itoa(S,s,10);
	           itoa(L,l,10);
	           itoa(A,a,10);
	           itoa(I,i,10);
	           itoa(C,c,10);
	           itoa(K,k,10);
	           itoa(flag,fl,10);
	           //copy to file in string format
               FILE * fpsave = fopen("d:\\game_data.txt","w"); /*CREATE THE TEXT FILE IN THE DIRECTORY*/
               if (fpsave == NULL) 
                { printf("Couldn't open game data for writing.\n");
                exit(0);
				}
               fprintf(fpsave, "%s\n",playerName);
               fprintf(fpsave, "%s\n",gender);
               fprintf(fpsave, "%s\n",ag);
               fprintf(fpsave, "%s\n",s);
               fprintf(fpsave, "%s\n",l);
               fprintf(fpsave, "%s\n",a);
               fprintf(fpsave, "%s\n",i);
               fprintf(fpsave, "%s\n",c);
               fprintf(fpsave, "%s\n",k);
               fprintf(fpsave, "%s\n",fl);
               fclose(fpsave);     
             
        case 2:
               break; 
       }
}
A:printf("On your way then.");
printf("\t\t\t                               \n");
delay(2000);
ex=0;
int choice;
int go = 0;
char enemy[50];
while (!go)
{
printf("1. MOVE");
printf("\t\t\t                               \n");
delay(2000);
printf("2. REST");
printf("\t\t\t                               \n");
delay(2000);
printf("3. STAT MONITOR");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&choice);	
switch (choice)
{
case 1:
{
choice = 0;
int out = 0;
while (!out)
{
int oppo = randomNum(oppo,0,3);
switch(oppo)
{
case 1:
{
printf("You continue to move across the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see something move in the distance.");
printf("\t\t\t                               \n");
delay(2000);
printf("......Never mind whatever it was went away.......");
printf("\t\t\t                               \n");
delay(2000);
go = 1;
out = 1;
printf("you continue with the journey.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
case 2:
{
printf("You continue to move across the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see something move in the distance.");
printf("\t\t\t                               \n");
delay(2000);
strcpy(enemy,"ROBOT");
printf("Wait it's a %s!",enemy);
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                 -___________-           \n");
printf("\t\t\t                (/     _     /)          \n");
printf("\t\t\t                |_____(O)_____|          \n");
printf("\t\t\t                |/ / / | / / /|          \n");
printf("\t\t\t EXTERMINATE! ================= EXTERMINATE! \n");
printf("\t\t\t               |/ / | | | | / /|          \n");
printf("\t\t\t               ===================        \n");
printf("\t\t\t              |/// || || || || ///|       \n");
printf("\t\t\t              |||| || || || || ||||       \n");
printf("\t\t\t             |---___-----------,---|      \n"); 
printf("\t\t\t             |  /   /         -o-  |      \n");
printf("\t\t\t             |  /___/          '   |      \n");
printf("\t\t\t             +---------------------+      \n");
printf("\t\t\t             |_   __    ___    __   _|    \n");
printf("\t\t\t            (__) (__)  (___)  (__) (__)   \n");
printf("\t\t\t            |_    __    ___    __    _|   \n");              
printf("\t\t\t           (__)  (__)  (___)  (__)  (__)  \n");          
printf("\t\t\t            |_    ___    ___    ___    _|  \n");             
printf("\t\t\t           (__)  (___)  (___)  (___)  (__)  \n");            
printf("\t\t\t           |_     ___    ___    ___     _|  \n");           
printf("\t\t\t          (__)   (___)  (___)  (___)   (__)  \n");  
printf("\t\t\t          |_______________________________|  \n");
printf("\t\t\t                                              \n");
delay(2000);
printf("It's going to attack! Brace yourself!");
printf("\t\t\t                               \n");
delay(2000);
combat(playerName,gender,slot2,enemy,pammo,lvl,exp);
lvl=levelup(exp,lvl);
printf("Time to get moving.");
printf("\t\t\t                               \n");
delay(2000);
rest = 0;
go = 1;
out = 1;
break;
}
case 3:
{
printf("You continue to move across the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You stop to take a little rest.");
printf("\t\t\t                               \n");
delay(2000);
printf("Maybe you should have a healthier lifestyle.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to try again.");
printf("\t\t\t                               \n");
getch();
break;
}
default:
	{
		break;
	}
}
}
break;
}
case 2:
{
if(rest<1)
{
printf("You lie down on the ground and make yourself as comfortable as you can.");
printf("\t\t\t                               \n");
delay(2000);
printf("...ZZZZ....");
printf("\t\t\t                               \n");
delay(2000);
printf("You wake up with a start.");
printf("\t\t\t                               \n");
delay(2000);
rest+=1;
}
else if(rest=1)
{
printf("You are already feeling rested.");
printf("\t\t\t                               \n");
delay(2000);
printf("Up on your feet then.");
printf("\t\t\t                               \n");
delay(2000);
}
break;
}
case 3:
{
printf("Press any button to open up the stat monitor.");
printf("\t\t\t                               \n");
getch(); 
delay(2000);
while(!ex)
{
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t ||                   ||STAT MONITOR V.3000||                     || \n");
printf("\t\t\t ||   WELCOME %s                                                  || \n",playerName);
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||   CHOOSE AN ACTION TO PERFORM:                                || \n");
printf("\t\t\t ||   1.STATS                                                     || \n"); 
printf("\t\t\t ||   2.INVENTORY                                                 || \n");
printf("\t\t\t ||   3.MISSION OBJECTIVE(S)                                      || \n");
printf("\t\t\t ||   4.EXIT GAME                                                 || \n");
printf("\t\t\t ||   5.BACK TO GAME                                              || \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");                                          
delay(2000);
printf("Choose any of the following options.");
printf("\t\t\t                               \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
{
printf("          ||YOUR NAME IS %s||",playerName);
printf("\t\t\t                               \n");
printf("          ||YOUR GENDER IS %s||",gender);
printf("\t\t\t                               \n");
printf("          ||YOUR AGE IS %d||",playerAge);
printf("\t\t\t                               \n");
printf("          ||YOU ARE LEVEL %d||",lvl);
printf("\t\t\t                               \n");
printf("          ||YOU HAVE THE FOLLOWING STATS||");
printf("\t\t\t                               \n");
printf("          ||STRENGTH||");
printf("\t\t\t                               \n");
printf("%d",S);
printf("          ||LUCK||");
printf("\t\t\t                               \n");
printf("%d",L);
printf("          ||AGILITY||");
printf("\t\t\t                               \n");
printf("%d",A);
printf("          ||CHARISMA||");
printf("\t\t\t                               \n");
printf("%d",C);
printf("          ||INTELLIGENCE||");
printf("\t\t\t                               \n");
printf("%d",I);
break;
}
case 2:
{
printf("          ||SLOT 1 -> %s , %d||",slot1,c1);
printf("\t\t\t                               \n");
printf("          ||SLOT 2 -> %s , %d||",slot2,pammo);
printf("\t\t\t                               \n");
printf("          ||SLOT 3 -> %s||",slot3);
printf("\t\t\t                               \n");
break;
}
case 3:
{
printf("          ||INVESTIGATE THE ROOM||");
printf("\t\t\t                               \n");
break;
}
case 4:
{
exit(0);
break;
}
case 5:
{
ex=1;	
break;
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
printf("You reach the end of the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("A giant control panel with several buttons stares at you.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t              ________________________________________________      \n");
printf("\t\t\t            |                                                  |     \n");
printf("\t\t\t            |    _________________________________________     |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |  C:/> _                                 |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |      \n");
printf("\t\t\t            |   |                                         |    |       \n");
printf("\t\t\t            |   |                                         |    |       \n");
printf("\t\t\t            |   |                                         |    |        \n");
printf("\t\t\t            |   |_________________________________________|    |        \n");
printf("\t\t\t            |                                                  |         \n");
printf("\t\t\t            |_________________________________________________ |          \n");
printf("\t\t\t                    |___________________________________|                 \n");
printf("\t\t\t                 ___________________________________________              \n");
printf("\t\t\t             _-'    .-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.  --- `-_             \n");
printf("\t\t\t           _-'.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.--.  .-.-.`-_          \n");
printf("\t\t\t        _-'.-.-.-. .---.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-`__`. .-.-.-.`-_        \n");
printf("\t\t\t     _-'.-.-.-.-. .-----.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-----. .-.-.-.-.`-_     \n");
printf("\t\t\t  _-'.-.-.-.-.-. .---.-. .-------------------------. .-.---. .---.-.-.-.`-_   \n");
printf("\t\t\t :-------------------------------------------------------------------------:   \n");
printf("\t\t\t `---._.-------------------------------------------------------------._.---'    \n");
delay(2000);
printf("What should you do?");
printf("\t\t\t                               \n");
delay(2000);
int pass = 0;
int dec;
int gone;
while(!gone)
{
printf("1. INTERACT WITH THE CONTROL PANEL");
printf("\t\t\t                               \n");
delay(2000);
printf("2. LOOK AROUND.");
printf("\t\t\t                               \n");
delay(2000);
printf("3. LEAVE IT ALONE");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&dec);	
switch (dec)
{
case 1:
{
printf("You start tapping at the buttons.");
printf("\t\t\t                               \n");
delay(2000);
printf("You try to coax a response from the machine.");
printf("\t\t\t                               \n");
delay(2000);
if(I > 6 && pass == 1)
{
printf("You can't seem too figure out what you're doing");
printf("\t\t\t                               \n");
delay(2000);
printf("Try finding another way around.");
printf("\t\t\t                               \n");
delay(2000);
break;	
}
else
{
int yu = 0;
int watch = 0;	
while(!watch)
{	
printf("The screen turns green");
printf("\t\t\t                               \n");
delay(2000);
printf("         ||ACCESS GRANTED||");
printf("\t\t\t                               \n");
delay(2000);
printf("         ||WELCOME COMMANDER DEXTER||");
printf("\t\t\t                               \n");
delay(2000);
printf("         ||SELECT AN OPTION FROM BELOW||");
printf("\t\t\t                               \n");
delay(2000);
printf("         ||1. REPORTS||");
printf("\t\t\t                               \n");
delay(2000);
printf("         ||2. OBSERVATION||");
printf("\t\t\t                               \n");
delay(2000);
printf("         ||3. OPEN ESCAPE HATCH||");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&yu);
switch(yu)
{
case 1:
{
printf("            ||REPORTS||");
printf("\t\t\t                               \n");
delay(2000);
printf("0800 Hrs :: The facility is overrun.::");
printf("\t\t\t                               \n");
delay(2000);
printf("1000 Hrs:: Despite our best efforts");
printf("\t\t\t                               \n");
delay(2000);
printf(":: we have been defeated. Our forces...");
printf("\t\t\t                               \n");
delay(2000);
printf(":: have been scattered.::");
printf("\t\t\t                               \n");
delay(2000);
printf("1400 Hrs:: The computer virus has affected...");
printf("\t\t\t                               \n");
delay(2000);
printf(":: all systems. We need to escape now.");
printf("\t\t\t                               \n");
delay(2000);
printf("1800 Hrs:: There is one way to stop the machines..");
printf("\t\t\t                               \n");
delay(2000);
printf(":: The reactor room has a self destruct sequence....");
printf("\t\t\t                               \n");
delay(2000);
printf(":: Perhaps somebody........");
printf("\t\t\t                               \n");
delay(2000);
printf("            ||END OF REPORTS||");
printf("\t\t\t                               \n");
delay(2000);
break;
}
case 2:
{
printf("The monitor switches to a room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You look at the screen.");
printf("\t\t\t                               \n");
delay(2000);
printf("It shows other people!");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                                          |               \n");
printf("\t\t\t                                          |                \n"); 
printf("\t\t\t                                          |                \n");
printf("\t\t\t                                          |                \n");
printf("\t\t\t    _______                   ________    |                 \n");
printf("\t\t\t   |ooooooo|      ____       | __  __ |   |                 \n");
printf("\t\t\t   |[]+++[]|     [____]      |/  //  /|   |                 \n");
printf("\t\t\t   |+ ___ +|     ]()()[      |/__//__/|   |                 \n");
printf("\t\t\t   |:|   |:|   ___{__}___    |[][][][]|   |                  \n");
printf("\t\t\t   |:|___|:|  |__|    |__|   |++++++++|   |                  \n");
printf("\t\t\t   |[]===[]|   |_|_[]_|_|    | ______ |   |                  \n");
printf("\t\t\t _ ||||||||| _ | | __ | | __ ||______|| __|                   \n");
printf("\t\t\t   |_______|   |_|[::]|_|    |________|   |                   \n");
printf("\t\t\t               {_|_||_|_}                  |                   \n");
printf("\t\t\t                 |_||_|                     |                   \n");
printf("\t\t\t                _|_||_|_                     |                   \n");
printf("\t\t\t       ____    |___||___|                     |                   \n");
printf("\t\t\t      /  __|          ____                     |                   \n");
printf("\t\t\t      \( oo          (___ |                     |                   \n");
printf("\t\t\t      _|_o/_          oo~)/                                        \n");    
printf("\t\t\t     / ||| |         (-_ /_                                         \n");
printf("\t\t\t    /  __ ||___     / |||  |                                        \n");
printf("\t\t\t    | |_  |__/_)    || .-  |                                       \n");
printf("\t\t\t    |__|_) |        || . /_/                                         \n");
printf("\t\t\t      ||___|        (/__(_/                                           \n");
printf("\t\t\t      | | |          | |  |                                            \n");
printf("\t\t\t      | | |          | |  |                                             \n");
printf("\t\t\t      |_|_|          |_|__|                                             \n");
printf("\t\t\t      [__)_)        (_(___]                                              \n");
delay(2000);
printf("You try to reach out to them for help.");
printf("\t\t\t                               \n");
delay(2000);
printf("To that escape hatch then.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
case 3:
{
printf("You activate the escape hatch.");
printf("\t\t\t                               \n");
delay(2000);
printf("A panel slides open revealing a latch.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to open the hatch.");
printf("\t\t\t                               \n");
delay(2000);
getch();
watch=1;
gone=1;
break;
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}//Console option
}
}
break;
}//Interact option
case 2:
{
printf("You look around the place till you find a notepad.");
printf("\t\t\t                               \n");
delay(2000);
printf("It seems to have a faded writing on it.");
printf("\t\t\t                               \n");
delay(2000);
printf("It's the password to the control panel!");
printf("\t\t\t                               \n");
delay(2000);
pass = 1;
break;
}
case 3:
{
printf("You leave the coontrol panel and sit down.");
printf("\t\t\t                               \n");
delay(2000);
printf("It doesn't seem to do any good.");
printf("\t\t\t                               \n");
delay(2000);
printf("You decide to get back up on the job.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
printf("You climb up the hatch.");
printf("\t\t\t                               \n");
delay(2000);
//Checkpoint B
{
c1=0;
printf("Do you want to save your data?\n1.Yes\n2.No\nSelect your choice:");
scanf("%d",&c1);
switch (c1)
      { case 1:
	          
	           //convert to string
	           flag+=1;
	           itoa(age,ag,10);
	           itoa(S,s,10);
	           itoa(L,l,10);
	           itoa(A,a,10);
	           itoa(I,i,10);
	           itoa(C,c,10);
	           itoa(K,k,10);
	           itoa(flag,fl,10);
	           //copy to file in string format
               FILE * fpsave = fopen("d:\\game_data.txt","w"); /*CREATE THE TEXT FILE IN THE DIRECTORY*/
               if (fpsave == NULL) 
                { printf("Couldn't open game data for writing.\n");
                exit(0);
				}
               fprintf(fpsave, "%s\n",playerName);
               fprintf(fpsave, "%s\n",gender);
               fprintf(fpsave, "%s\n",ag);
               fprintf(fpsave, "%s\n",s);
               fprintf(fpsave, "%s\n",l);
               fprintf(fpsave, "%s\n",a);
               fprintf(fpsave, "%s\n",i);
               fprintf(fpsave, "%s\n",c);
               fprintf(fpsave, "%s\n",k);
               fprintf(fpsave, "%s\n",fl);
               fclose(fpsave);     
             
        case 2:
               break; 
       }
}
B:printf("On your way then.");
printf("\t\t\t                               \n");
delay(2000);
printf("You reach another floor.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t          ---------------------------             \n");
printf("\t\t\t         ^_[]_^                 ^_[]_^              \n");
printf("\t\t\t         |----|               5 |----|               \n");
printf("\t\t\t ________`-..-'________4________`-..-'______          \n");
printf("\t\t\t ===========================================             \n");
printf("\t\t\t          `||'                   `||'                     \n");
printf("\t\t\t           ||     ^==^   ^==^     ||                       \n");
printf("\t\t\t ___.____._ll_._1_|--|   |--|___._ll_.____.____              \n");
printf("\t\t\t XXX|XXXX|XIIX|XXX|--| 3 |--|XXX|XIIX|XXXX|XXXX               \n");
printf("\t\t\t XXX|XXXX|XIIX|XXX| 2|   |  |XXX|XIIX|XXXX|XXXX                 \n");
printf("\t\t\t                                                                  \n");
delay(2000);
printf("Where would you like to go?");
printf("\t\t\t                               \n");
delay(2000);
//Trading now allowed
int credits = 0;
int medipak = 0;
int batt = 0;
//
dec=0;
gone=0;
while(!gone)
{
printf("Select from the following places.");
printf("\t\t\t                               \n");
delay(2000);
printf("           ||1.WINDOW||");
printf("\t\t\t                               \n");
delay(2000);
printf("           ||2.ROOM TO THE SOUTH||");
printf("\t\t\t                               \n");
delay(2000);
printf("           ||3.MIDDLE HALLWAY||");
printf("\t\t\t                               \n");
delay(2000);
printf("           ||4.OUTER HALLWAY||");
printf("\t\t\t                               \n");
delay(2000);
printf("           ||5.OUTER CONTROL ROOM||");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&dec);
switch(dec)
{
case 1:
{
printf("You look outside the glass.");
printf("\t\t\t                               \n");
delay(2000);
printf("You gaze into the canvas of black speckled by white.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t         *    .  *       .             *  \n");
printf("\t\t\t                      *                                \n");
printf("\t\t\t             *   .        *       .       .       *   \n");
printf("\t\t\t                      *                               \n");
printf("\t\t\t                                     .     .  *        * \n");
printf("\t\t\t          .            .        .                     \n");
printf("\t\t\t      *           *                     *      \n");
printf("\t\t\t                              .    \n");
printf("\t\t\t          *          .   *        \n");
delay(2000);
break;
}
case 2:
{
printf("You enter the southern room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see a shiny object on the ground.");
printf("\t\t\t                               \n");
delay(2000);
printf("A closer look reveals it to be gold!");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to pick it up.");
printf("\t\t\t                               \n");
getch();
c1+=1;
if(strcmp(slot1,"GOLD")!=0)
{
strcpy(slot1,"GOLD");
}
printf("Time to head back on the trail.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see a vending machine!");
printf("\t\t\t                               \n");
delay(2000);
printf("It looks like a robot!");
printf("\t\t\t                               \n");
delay(2000);
printf("Thankfully it's friendly.");
printf("\t\t\t                               \n");
delay(2000);
int ok = 0;
int ve = 0;
while(!ok)
{
printf("Access vending machine console?");
printf("\t\t\t                               \n");
delay(2000);
printf("\n 1. YES(1) 2. NO(2)");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&ve);
switch(ve)
{
case 1:
{
trade(playerName,credits,K,medipak,pammo,batt,slot1);
break;
}
case 2:
{
printf("Another time maybe.");
printf("\t\t\t                               \n");
delay(2000);
ok = 1;
break;
}
}
}
printf("Off we go again!");
printf("\t\t\t                               \n");
delay(2000);
gone = 1;
break;
}
case 3:
{
printf("You enter the middle hallway.");
printf("\t\t\t                               \n");
delay(2000);
printf("You continue to move across the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see something move in the distance.");
printf("\t\t\t                               \n");
delay(2000);
printf("......Never mind whatever it was went away.......");
printf("\t\t\t                               \n");
delay(2000);
gone = 1;
printf("you continue with the journey.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
case 4:
{
printf("You continue to move across the outer hallway.");
printf("\t\t\t                               \n");
delay(2000);
printf("You stop to take a little rest.");
printf("\t\t\t                               \n");
delay(2000);
printf("Maybe you should have a healthier lifestyle.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to try again.");
printf("\t\t\t                               \n");
getch();
break;
}
case 5:
{
printf("You move to the outer control room.");
printf("\t\t\t                               \n");
delay(2000);
printf("Something catches your eye!");
printf("\t\t\t                               \n");
delay(2000);
printf("You see a vending machine!");
printf("\t\t\t                               \n");
delay(2000);
printf("It looks like a robot!");
printf("\t\t\t                               \n");
delay(2000);
printf("Thankfully it's friendly.");
printf("\t\t\t                               \n");
delay(2000);
int ok = 0;
int ve = 0;
while(!ok)
{
printf("Access vending machine console?");
printf("\t\t\t                               \n");
delay(2000);
printf("\n 1. YES(1) 2. NO(2)");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&ve);
switch(ve)
{
case 1:
{
trade(playerName,credits,K,medipak,pammo,batt,slot1);
break;
}
case 2:
{
printf("Another time maybe.");
printf("\t\t\t                               \n");
delay(2000);
ok = 1;
break;
}
}
}
printf("There's nothing else here.");
printf("\t\t\t                               \n");
delay(2000);
printf("It's time to head back.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
}
}
printf("You head out to the main area.");
printf("\t\t\t                               \n");
delay(2000);
printf("You can hear voices ahead.");
printf("\t\t\t                               \n");
delay(2000);
printf("What would you like to do?");
printf("\t\t\t                               \n");
delay(2000);
choice = 0;
go = 0;
ex =0;
while (!go)
{
printf("1. MOVE");
printf("\t\t\t                               \n");
delay(2000);
printf("2. REST ");
printf("\t\t\t                               \n");
delay(2000);
printf("3. STAT MONITOR");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&choice);	
switch (choice)
{
case 1:
{
if (rest!=1)
{
printf("Take a nap buddy. You need it.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
printf("You can see the other personnel.");
printf("\t\t\t                               \n");
delay(2000);                                     
printf("\t\t\t    _________________________      \n");
printf("\t\t\t      ||   ||     ||   ||           \n");
printf("\t\t\t      ||   ||, , ,||   ||            \n");
printf("\t\t\t      ||  (|||||(|||/  ||            \n");
printf("\t\t\t      ||  ||| _'_`|||  ||           \n");
printf("\t\t\t      ||   || o o ||   ||            \n");
printf("\t\t\t      ||  (||  - `||)  ||            \n");
printf("\t\t\t      ||   ||  =  ||   ||             \n");
printf("\t\t\t      ||   |||___|||   ||             \n");
printf("\t\t\t      ||___||) , (||___||             \n");
printf("\t\t\t     [||---||-|_|-||---||]             \n");
printf("\t\t\t     [||--_||_____||_--||]             \n");
printf("\t\t\t   (_(||)-|         |-(||)_)            \n");
delay(2000);
printf("PRISONER: 'Hey! over Here!'");
printf("\t\t\t                               \n");
delay(2000);                                     
printf("YOU: 'Hold on, let me get there.'");
printf("\t\t\t                               \n");
delay(2000);                                     
printf("PRISONER: 'That droid bot has captured us in here.'");
printf("\t\t\t                               \n");
delay(2000);                                     
printf("PRISONER: 'Oh well....he's right behind you.'");
printf("\t\t\t                               \n");
delay(2000);    
printf("YOU: 'Oh my god......'");
printf("\t\t\t                               \n");
delay(2000);  
strcpy(enemy,"DROID");
printf("It's a %s!",enemy);
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t     ____          ____         \n");
printf("\t\t\t    |oooo|        |oooo|         \n");
printf("\t\t\t    |oooo| .----. |oooo|        \n");
printf("\t\t\t    |Oooo|||_||_|||oooO|        \n");
printf("\t\t\t    `----' | __ | `----'        \n");
printf("\t\t\t    ,| |#||||__||||#| |,        \n");
printf("\t\t\t   |  ||#|| |||| ||#||  |       \n");
printf("\t\t\t  | |_||_|| |||| ||_||_| |      \n");
printf("\t\t\t |_||    o|=----=|o    ||_|      \n");
printf("\t\t\t <_>      |=|__|=|      <_>      \n");
printf("\t\t\t <_>      |------|      <_>       \n");
printf("\t\t\t | |   ___|======|___   | |        \n");
printf("\t\t\t||||  | |O|======|O| |  ||||       \n");
printf("\t\t\t|  |  | |O+------+O| |  |  |       \n");
printf("\t\t\t||||  |_+|        |+_|  ||||       \n");
printf("\t\t\t|__|  _|||        |||_  |__|       \n");
printf("\t\t\t      | ||        || |             \n");
printf("\t\t\t     [==|]        [|==]             \n");
printf("\t\t\t     [===]        [===]             \n");
printf("\t\t\t      >_<          >_<              \n");
printf("\t\t\t     || ||        || ||              \n");
printf("\t\t\t     || ||        || ||              \n");
printf("\t\t\t     || ||        || ||               \n");
printf("\t\t\t   __||_||__    __||_||__              \n");
printf("\t\t\t  |___n_n___|  |___n_n___|              \n");
delay(2000);
printf("PRISONER: 'Here take this blaster.'");
printf("\t\t\t                               \n");
delay(2000);  
printf("PRISONER: 'It might help you in your fight!'");
printf("\t\t\t                               \n");
delay(2000); 
printf("Press any key to take BLASTER from prisoner.");
printf("\t\t\t                               \n");
getch();
strcpy(slot2,"BLASTER");
int bammo=25;
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                            --[=]-    LS            [88[  O  ]88888]  o     \n");
printf("\t\t\t     _______|_|              .-.   .-|-===-|------|b|      .o8               \n");
printf("\t\t\t    |         |-------|------| |---| ||o  ||    | |88888888888               \n");
printf("\t\t\t    |_________|-------|______| `---' ||___||    o `~~~~~~~8888                \n");
printf("\t\t\t    `-------|_|-------|HHHHHHHHHHHHHH|-----|~~~________|_|8888                 \n");
printf("\t\t\t           =[_]=                   |++-----+--|  )888  |__8888                  \n");
printf("\t\t\t                                   ||         `==='88b    `888                   \n");
printf("\t\t\t                                                   888     `88                    \n"); 
printf("\t\t\t                                                   `88b     `8                     \n");
printf("\t\t\t                                                    d88P      `                     \n");
delay(2000);
printf("YOU: 'Here goes nothing......'");
printf("\t\t\t                               \n");
delay(2000); 
combat (playerName,gender,slot2,enemy,bammo,lvl,exp);
lvl=levelup(exp,lvl);
printf("PRISONER: 'Great job! Now get me out of here!'");
printf("\t\t\t                               \n");
delay(2000);
int que;
printf("Release this prisoner? (Y(1)/N(2))");
printf("\t\t\t                               \n");
delay(2000);   
scanf("%d",&que);
if (que!=1) 
{
printf("YOU: 'Sorry not my problem...'");
printf("\t\t\t                               \n");
delay(2000); 
printf("PRISONER: 'Hey there! Get back you rogue....'");
printf("\t\t\t                               \n");
delay(2000); 
printf("PRISONER: 'Hey....'");
printf("\t\t\t                               \n");
delay(2000);
printf("You have lost Karma for not helping the prisoner.");
printf("\t\t\t                               \n");
delay(2000);
K-=15;
go=1;
break;
}
printf("YOU: 'Here you go..just a minute...'");
printf("\t\t\t                               \n");
delay(2000); 
printf("PRISONER: 'Oh thanks friend, you're a real hero.'");
printf("\t\t\t                               \n");
delay(2000); 
printf("PRISONER: 'I have to go now, see you later.'");
printf("\t\t\t                               \n");
delay(2000);
printf("You have gained Karma for helping the prisoner.");
printf("\t\t\t                               \n");
delay(2000);
K+=15;
go=1;
break;    
}
case 2:
{
if(rest<1)
{
printf("You lie down on the ground and make yourself as comfortable as you can.");
printf("\t\t\t                               \n");
delay(2000);
printf("...ZZZZ....");
printf("\t\t\t                               \n");
delay(2000);
printf("You wake up with a start.");
printf("\t\t\t                               \n");
delay(2000);
rest+=1;
}
else if(rest=1)
{
printf("You are already feeling rested.");
printf("\t\t\t                               \n");
delay(2000);
printf("Up on your feet then.");
printf("\t\t\t                               \n");
delay(2000);
}
break;
}
case 3:
{
printf("Press any button to open up the stat monitor.");
printf("\t\t\t                               \n");
getch(); 
delay(2000);
while(!ex)
{
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t ||                   ||STAT MONITOR V.3000||                     || \n");
printf("\t\t\t ||   WELCOME %s                                                  || \n",playerName);
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||   CHOOSE AN ACTION TO PERFORM:                                || \n");
printf("\t\t\t ||   1.STATS                                                     || \n"); 
printf("\t\t\t ||   2.INVENTORY                                                 || \n");
printf("\t\t\t ||   3.MISSION OBJECTIVE(S)                                      || \n");
printf("\t\t\t ||   4.EXIT GAME                                                 || \n");
printf("\t\t\t ||   5.BACK TO GAME                                              || \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");                                          
delay(2000);
printf("Choose any of the following options.");
printf("\t\t\t                               \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
{
printf("          ||YOUR NAME IS %s||",playerName);
printf("\t\t\t                               \n");
printf("          ||YOUR GENDER IS %s||",gender);
printf("\t\t\t                               \n");
printf("          ||YOUR AGE IS %d||",playerAge);
printf("\t\t\t                               \n");
printf("          ||YOU ARE LEVEL %d||",lvl);
printf("\t\t\t                               \n");
printf("          ||YOU HAVE THE FOLLOWING STATS||");
printf("\t\t\t                               \n");
printf("          ||STRENGTH||");
printf("\t\t\t                               \n");
printf("%d",S);
printf("          ||LUCK||");
printf("\t\t\t                               \n");
printf("%d",L);
printf("          ||AGILITY||");
printf("\t\t\t                               \n");
printf("%d",A);
printf("          ||CHARISMA||");
printf("\t\t\t                               \n");
printf("%d",C);
printf("          ||INTELLIGENCE||");
printf("\t\t\t                               \n");
printf("%d",I);
break;
}
case 2:
{
printf("          ||SLOT 1 -> %s , %d||",slot1,c1);
printf("\t\t\t                               \n");
printf("          ||SLOT 2 -> %s , %d||",slot2,pammo);
printf("\t\t\t                               \n");
printf("          ||SLOT 3 -> %s||",slot3);
printf("\t\t\t                               \n");
break;
}
case 3:
{
printf("          ||HEAD TO THE REACTOR ROOM||");
printf("\t\t\t                               \n");
break;
}
case 4:
{
exit(0);
break;
}
case 5:
{
ex=1;	
break;
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
break;
}
}
}
int bammo=25;
//Checkpoint C
{
c1=0;
printf("Do you want to save your data?\n1.Yes\n2.No\nSelect your choice:");
scanf("%d",&c1);
switch (c1)
      { case 1:
	          
	           //convert to string
	           flag+=1;
	           itoa(age,ag,10);
	           itoa(S,s,10);
	           itoa(L,l,10);
	           itoa(A,a,10);
	           itoa(I,i,10);
	           itoa(C,c,10);
	           itoa(K,k,10);
	           itoa(flag,fl,10);
	           //copy to file in string format
               FILE * fpsave = fopen("d:\\game_data.txt","w"); /*CREATE THE TEXT FILE IN THE DIRECTORY*/
               if (fpsave == NULL) 
                { printf("Couldn't open game data for writing.\n");
                exit(0);
				}
               fprintf(fpsave, "%s\n",playerName);
               fprintf(fpsave, "%s\n",gender);
               fprintf(fpsave, "%s\n",ag);
               fprintf(fpsave, "%s\n",s);
               fprintf(fpsave, "%s\n",l);
               fprintf(fpsave, "%s\n",a);
               fprintf(fpsave, "%s\n",i);
               fprintf(fpsave, "%s\n",c);
               fprintf(fpsave, "%s\n",k);
               fprintf(fpsave, "%s\n",fl);
               fclose(fpsave);     
             
        case 2:
               break; 
       }
}
C:printf("On your way then.");
printf("\t\t\t                               \n");
delay(2000);
printf("You head down to the last level.");
printf("\t\t\t                               \n");
delay(2000);
printf("The dank smell from the recycling units suffocates you");
printf("\t\t\t                               \n");
delay(2000);
printf("Some grime from the dark roofs falls on your face.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to wipe grime");
printf("\t\t\t                               \n");
getch();
printf("The dark liquid has a viscous feeling in your fingers.");
printf("\t\t\t                               \n");
delay(2000);
printf("It's blood!'");
printf("\t\t\t                               \n");
delay(2000);
printf("You take a deep breath and think over what to do next.");
printf("\t\t\t                               \n");
delay(2000);
go=0;
out=0;
ex=0;
choice=0;
while (!go)
{
printf("1. MOVE");
printf("\t\t\t                               \n");
delay(2000);
printf("2. REST");
printf("\t\t\t                               \n");
delay(2000);
printf("3. STAT MONITOR");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&choice);	
switch (choice)
{
case 1:
{
go = 0;
int oppo = randomNum(oppo,0,3);
out=0;
while (!out)
{
switch(oppo)
{
case 1:
{
printf("You continue to move across the dark hall.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see something move in the distance.");
printf("\t\t\t                               \n");
delay(2000);
printf("......Never mind whatever it was went away.......");
printf("\t\t\t                               \n");
delay(2000);
go = 1;
out = 1;
printf("you continue with the journey.");
printf("\t\t\t                               \n");
delay(2000);
printf("Something catches your eye!");
printf("\t\t\t                               \n");
delay(2000);
printf("You see a vending machine!");
printf("\t\t\t                               \n");
delay(2000);
printf("It looks like a robot!");
printf("\t\t\t                               \n");
delay(2000);
printf("Thankfully it's friendly.");
printf("\t\t\t                               \n");
delay(2000);
int ok=0;
int ve=0;
while(!ok)
{
printf("Access vending machine console?");
printf("\t\t\t                               \n");
delay(2000);
printf("\n 1. YES(1) 2. NO(2)");
printf("\t\t\t                               \n");
delay(2000);
scanf("%d",&ve);
switch(ve)
{
case 1:
{
trade(playerName,credits,K,medipak,bammo,batt,slot1);
break;
}
case 2:
{
printf("Another time maybe.");
printf("\t\t\t                               \n");
delay(2000);
ok = 1;
break;
}
}
}
break;
}
case 2:
{
printf("You continue to move across the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You see something move in the distance.");
printf("\t\t\t                               \n");
delay(2000);
strcpy(enemy,"MECHA");
printf("Wait it's a %s!",enemy);
printf("\t\t\t                               \n");
delay(2000);                               
printf("\t\t\t          0 _____                     \n");
printf("\t\t\t           X_____|                    \n");
printf("\t\t\t   .-^-.  ||_| |_||  .-^-.            \n");
printf("\t\t\t  |_|_|_|_|  |_|  |_|_|_|_|           \n");
printf("\t\t\t  ||(_)| __|_____|__ |(_)||           \n");
printf("\t\t\t  ||| | |::||```||::| | |||           \n");
printf("\t\t\t  |`---_|::|-+-+-|::|_---'|            \n");
printf("\t\t\t | |  | |::|-|-|-|::| |  | |           \n");
printf("\t\t\t|_|   ||`--'-+-+-`--'||   |_|           \n");
printf("\t\t\t| |  | |===|_| |_|===| |  | |           \n");
printf("\t\t\t|  ||  |---|-|-|-|  o|  ||  |           \n");
printf("\t\t\t| ||| | O | |   | |   | ||| |           \n");
printf("\t\t\t| ||| ||-------------|o|||| |           \n");
printf("\t\t\t| ||| ||----| | |----|o|||| |           \n");
printf("\t\t\t| _|| ||-----|||-----|o|||_ |           \n");
printf("\t\t\t|||||  |     |||     |o||||||           \n");
printf("\t\t\t|_o|   |----|||||----|-' |o_|           \n");
printf("\t\t\t       |##  |   |  ##|                  \n");
printf("\t\t\t       |----|   |----|                  \n");
printf("\t\t\t       ||__ |   | __||                  \n");
printf("\t\t\t      [|'  `|] [|'  `|]                 \n");
printf("\t\t\t      [|`--'|] [|`--'|]                 \n");
printf("\t\t\t      ||__| || || |__||                 \n");
printf("\t\t\t      ||  | || || |  ||                 \n");
printf("\t\t\t      ||__|_|| ||_|__||                 \n");
printf("\t\t\t      ||    || ||    ||                 \n");
printf("\t\t\t      ||----|| ||----||                 \n");
printf("\t\t\t      |__||__| |__||__|                 \n");
printf("\t\t\t                               \n");
delay(2000);
printf("It's going to attack! Brace yourself!");
printf("\t\t\t                               \n");
delay(2000);
combat (playerName,gender,slot2,enemy,bammo,lvl,exp);
lvl=levelup(exp,lvl);
printf("Time to get moving.");
printf("\t\t\t                               \n");
delay(2000);
rest = 0;
go = 1;
out = 1;
}
case 3:
{
printf("You continue to move across the room.");
printf("\t\t\t                               \n");
delay(2000);
printf("You stop to take a little rest.");
printf("\t\t\t                               \n");
delay(2000);
printf("Maybe you should have a healthier lifestyle.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to try again.");
printf("\t\t\t                               \n");
getch();
break;
}
}
}
}
case 2:
{
if(rest<1 || medipak>=1)
{
printf("You lie down on the ground and make yourself as comfortable as you can.");
printf("\t\t\t                               \n");
delay(2000);
printf("...ZZZZ....");
printf("\t\t\t                               \n");
delay(2000);
printf("You wake up with a start.");
printf("\t\t\t                               \n");
delay(2000);
rest+=1;
}
else if(rest=1)
{
printf("You are already feeling rested.");
printf("\t\t\t                               \n");
delay(2000);
printf("Up on your feet then.");
printf("\t\t\t                               \n");
delay(2000);
}
break;
}
case 3:
{
printf("Press any button to open up the stat monitor.");
printf("\t\t\t                               \n");
getch(); 
delay(2000);
while(!ex)
{
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t ||                   ||STAT MONITOR V.3000||                     || \n");
printf("\t\t\t ||   WELCOME %s                                                  || \n",playerName);
printf("\t\t\t ||                                                               || \n");
printf("\t\t\t ||   CHOOSE AN ACTION TO PERFORM:                                || \n");
printf("\t\t\t ||   1.STATS                                                     || \n"); 
printf("\t\t\t ||   2.INVENTORY                                                 || \n");
printf("\t\t\t ||   3.MISSION OBJECTIVE(S)                                      || \n");
printf("\t\t\t ||   4.EXIT GAME                                                 || \n");
printf("\t\t\t ||   5.BACK TO GAME                                              || \n");
printf("\t\t\t  /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");
printf("\t\t\t   /= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =/ \n");                                          
delay(2000);
printf("Choose any of the following options.");
printf("\t\t\t                               \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
{
printf("          ||YOUR NAME IS %s||",playerName);
printf("\t\t\t                               \n");
printf("          ||YOUR GENDER IS %s||",gender);
printf("\t\t\t                               \n");
printf("          ||YOUR AGE IS %d||",playerAge);
printf("\t\t\t                               \n");
printf("          ||YOU ARE LEVEL %d||",lvl);
printf("\t\t\t                               \n");
printf("          ||YOU HAVE THE FOLLOWING STATS||");
printf("\t\t\t                               \n");
printf("          ||STRENGTH||");
printf("\t\t\t                               \n");
printf("%d",S);
printf("          ||LUCK||");
printf("\t\t\t                               \n");
printf("%d",L);
printf("          ||AGILITY||");
printf("\t\t\t                               \n");
printf("%d",A);
printf("          ||CHARISMA||");
printf("\t\t\t                               \n");
printf("%d",C);
printf("          ||INTELLIGENCE||");
printf("\t\t\t                               \n");
printf("%d",I);
break;
}
case 2:
{
printf("          ||SLOT 1 -> %s , %d||",slot1,c1);
printf("\t\t\t                               \n");
printf("          ||SLOT 2 -> %s , %d||",slot2,pammo);
printf("\t\t\t                               \n");
printf("          ||SLOT 3 -> %s||",slot3);
printf("\t\t\t                               \n");
break;
}
case 3:
{
printf("          ||INVESTIGATE THE ROOM||");
printf("\t\t\t                               \n");
break;
}
case 4:
{
exit(0);
break;
}
case 5:
{
ex=1;	
break;
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
}
default:
{
printf("          ||INVALID DATA ENTERED||");
printf("\t\t\t                               \n");
printf("          ||RE-ENTER CORRECT DATA||");
printf("\t\t\t                               \n");
break;
}
}
}
//Checkpoint D
{
c1=0;
printf("Do you want to save your data?\n1.Yes\n2.No\nSelect your choice:");
scanf("%d",&c1);
switch (c1)
{

       { case 1:
	          
	           //convert to string
	          flag+=1;
	           itoa(age,ag,10);
	           itoa(S,s,10);
	           itoa(L,l,10);
	           itoa(A,a,10);
	           itoa(I,i,10);
	           itoa(C,c,10);
	           itoa(K,k,10);
	           itoa(flag,fl,10);
	           //copy to file in string format
               FILE * fpsave = fopen("d:\\game_data.txt","w"); /*CREATE THE TEXT FILE IN THE DIRECTORY*/
               if (fpsave == NULL) 
                { printf("Couldn't open game data for writing.\n");
                exit(0);
				}
               fprintf(fpsave, "%s\n",playerName);
               fprintf(fpsave, "%s\n",gender);
               fprintf(fpsave, "%s\n",ag);
               fprintf(fpsave, "%s\n",s);
               fprintf(fpsave, "%s\n",l);
               fprintf(fpsave, "%s\n",a);
               fprintf(fpsave, "%s\n",i);
               fprintf(fpsave, "%s\n",c);
               fprintf(fpsave, "%s\n",k);
               fprintf(fpsave, "%s\n",fl);
               fclose(fpsave);     
}
             
        case 2:
       {
		
               break; 
       }
}
D:printf("On your way then.");
printf("\t\t\t                               \n");
delay(2000);
printf("Finally! You see the reactor room!");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t           | | |.-.| | |                 \n");
printf("\t\t\t       |/   |_.-' 8 '-._|   /|            \n");
printf("\t\t\t       | /  `     '  / |   / |           \n");
printf("\t\t\t  //-+-|  /               /  |-+-//      \n");
printf("\t\t\t  |//| |   /             / /|| |//|      \n");
printf("\t\t\t  |__|/|   |/           /|| ||/|__|      \n");
printf("\t\t\t   /_/ |   | /         / ||/ | /_/       \n");
printf("\t\t\t       |   | |/       /| |   |           \n");
printf("\t\t\t       |  .----------------. |           \n");
printf("\t\t\t       | (__________________)|           \n");
printf("\t\t\t       | (                  )|           \n");
printf("\t\t\t       |  `----------------' |           \n");
printf("\t\t\t    LS |   | ||L|___|L|| |   |           \n");
printf("\t\t\t       |   | |<=======>| |   |           \n");
printf("\t\t\t       |   | |/       /| |   |           \n");
printf("\t\t\t       |   | /* *      / |   |           \n");
printf("\t\t\t       |   |/* X *      /|   |           \n");
printf("\t\t\t    __ |   /  * *        /   | __        \n");
printf("\t\t\t   /_/ |  /               /  | /_/       \n");
printf("\t\t\t  |  |/| /      _____      / |/|  |      \n");
printf("\t\t\t  |//| |/     _||___||_     /| |//|      \n");
printf("\t\t\t  //-+-      (|'|   |'|)      -+-//      \n");
printf("\t\t\t                               \n");
delay(2000);  
printf("The grime and dust floats in the air.");
printf("\t\t\t                               \n");
delay(2000);
printf("You take in the surroundings.");
printf("\t\t\t                               \n");
delay(2000);
printf("You observe a latch nestled under some rubble");
printf("\t\t\t                               \n");
delay(2000);
printf("It says 'RADIATION SHIELDING VALVE'");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to activate valve.");
printf("\t\t\t                               \n");
getch();
printf("Suddenly the room starts blaring loudly.");
printf("\t\t\t                               \n");
delay(2000);
printf("A towering figure rises above you!");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                               \n");
delay(2000);                             
printf("\t\t\t                        | || |                                     \n");
printf("\t\t\t                        | || |                                      \n");
printf("\t\t\t                        | || |                                      \n");
printf("\t\t\t                        | || |            ____                      \n");
printf("\t\t\t                        | || |           |    |                     \n");
printf("\t\t\t                        | || |           |    |                     \n");
printf("\t\t\t                        | || |||       ||      |                    \n");
printf("\t\t\t                      (|~~~~~~|| _____ ||      |                     \n");
printf("\t\t\t                      .-.    .'|'.___.`|`.    .-.                    \n");
printf("\t\t\t                     : ~ :|`'`.| `---' |.''`|: ~ :                   \n");
printf("\t\t\t              /~~~~|||~~|~~~|___|~~~~~|___/~~~/~~/||~~~~|            \n");
printf("\t\t\t     ____    /   < || `| `|    :~~~~~~~:    /'    || >   |    ____    \n");
printf("\t\t\t    |     |~|`---___||   `| `|__:_ ||| _:__/' /'   ||___---'|~|   |   \n");
printf("\t\t\t    |   | | |    | `|    `|___:_|   |_:___/'    /' |    | | | |   |   \n");
printf("\t\t\t    |   |  :|    ||   `'|      :-------;      /'`   /|    |;  |   |    \n");
printf("\t\t\t    |   | `|   |  |     `'|___/:     :|___/'`     /  |   /'   |   |    \n");
printf("\t\t\t    |   |   |`/|  |    ,.  |  :     ;  |  .,    /    |/'    |   |    \n");
printf("\t\t\t    |   | |~|~|`|    | .'= | |   :___:   | / =`. /    |'    0 |   |    \n");
printf("\t\t\t    |   | | | | |     | === /-|         |-/ === |     |       |   |    \n");
printf("\t\t\t    |   | |._.| |    /| ==== ||         |/ ==== |/    |       |   |    \n");
printf("\t\t\t    |   |  | |  |  ;' |~~~~~~~||       ||~~~~~~~| `;  |       |   |    \n");
printf("\t\t\t    `|  |__| |__|  |  |       ||0     0||       |  |  |_______|  /'    \n");
printf("\t\t\t     `||~|' `|~|  |  |-------| |     | |-------|  |  |~~~~~~~|/'       \n");
printf("\t\t\t        `||   |_|  |  |       |  |   |  |       |  |  |______/'        \n");
printf("\t\t\t          |   ||   (  |       |   | |   |       |  )   /    |          \n");
printf("\t\t\t          |   ||   '.,|_______|    '    |_______|,.'   |_|: ;           \n");
printf("\t\t\t          |   |'       ||~~~~|           |~~~~||       `~~~~            \n");
printf("\t\t\t          |   |        ||    ||         ||    ||                        \n");
printf("\t\t\t          |   |     .'| `....'||`.   .'||`....' |`.                     \n");
printf("\t\t\t          |   |     | |       ||  | |  ||       | |                      \n");
printf("\t\t\t          |   |     | |=======||  | |  ||=======| |                      \n");
printf("\t\t\t          | U |     | |       ||  | |  ||       | |                      \n");
printf("\t\t\t           |_|      | |       ||  | |  ||       | |                      \n");
printf("\t\t\t                    ||        ||  | |  ||        ||                      \n");
printf("\t\t\t                    ||        ||  | |  ||        ||                       \n");
printf("\t\t\t                    | |       ||  | |  ||       | |                       \n");
printf("\t\t\t                    | | |~~~| || .' `. || |~~~| | |                       \n");
printf("\t\t\t                    `.||     ||'`     `'||     ||.'                        \n");
printf("\t\t\t                      `|.---.|'         `|.---.|'                          \n");
printf("\t\t\t                       |     |           |     |                            \n");
printf("\t\t\t                       |_____|           |_____|                            \n");
delay(2000);
printf("\t\t\t                               \n");
printf("YOU:'That is one big angry robot!'");
printf("\t\t\t                               \n");
delay(2000);
printf("YOU:'Oh wow! That IS one big robot!'");
printf("\t\t\t                               \n");
delay(2000);
printf("The rubble falls around as it awakens!");
printf("\t\t\t                               \n");
delay(2000); 
printf("You can hear some screaming!");
printf("\t\t\t                               \n");
delay(2000); 
int ki,kl,crow=0;
printf("It's a civilian trapped under the rubble.");
printf("\t\t\t                               \n");
delay(2000);
printf("You also see a LASER GUN nearby.");
printf("\t\t\t                               \n");
delay(2000); 
delay(2000);
while(!ki)
{
printf("Choose quickly!");
printf("\t\t\t                               \n");
delay(2000);             
printf("1. Save the Civilian");
printf("\t\t\t                               \n");
delay(2000); 
printf("2. Get the LASER GUN!");
printf("\t\t\t                               \n");	
scanf("%d",&kl);	
switch(kl)
{
case 1:
{
printf("You are a hero!");
printf("\t\t\t                               \n");
delay(2000);
printf("You rush to the civilian's aid and try to lift the rubble.");
printf("\t\t\t                               \n");
delay(2000);
if( S >=6 || crow == 1)
{
printf("Press any key to lift the rubble.");
printf("\t\t\t                               \n");
getch();
printf("CIVILIAN:'Thank you friend.'");
printf("\t\t\t                               \n");
delay(2000);
printf("CIVILIAN:'Here have some BLASTER AMMO.'");
printf("\t\t\t                               \n");
delay(2000);
bammo+=15;
printf("CIVILIAN:'I have to leave now.'");
printf("\t\t\t                               \n");
delay(2000);
printf("The civilian escapes to safety.");
printf("\t\t\t                               \n");
delay(2000);
printf("You gain karma for saving the civilian.");
printf("\t\t\t                               \n");
delay(2000);
K+=35;
printf("The metal monster hurtles toward you!");
printf("\t\t\t                               \n");
delay(2000);
printf("Brace yourself!");
printf("\t\t\t                               \n");
delay(2000); 
strcpy(enemy,"BOSS MECHA"); 
combat (playerName,gender,slot2,enemy,bammo,lvl,exp);
lvl=levelup(exp,lvl);                       
ki=1;
break;
}
else
{
printf("The rubble is too heavy!");
printf("\t\t\t                               \n");
delay(2000);
printf("You look around and find a crowbar!");
printf("\t\t\t                               \n");
delay(2000);
crow=1;
printf("But the giant appears to be getting closer..");
printf("\t\t\t                               \n");
delay(2000);
printf("Decision time again.");
printf("\t\t\t                               \n");
delay(2000);
break;
}
}
case 2:
{
printf("You are a cold hearted person!");
printf("\t\t\t                               \n");
delay(2000);
printf("You dash for the LASER GUN.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any key to equip LASER GUN.");
printf("\t\t\t                               \n");
getch();
strcpy(slot2,"LASER GUN");
int lammo = 60;	
printf("CIVILIAN:'OH NO....'");
printf("\t\t\t                               \n");
delay(2000);
printf("The giant kills the civilian!");
printf("\t\t\t                               \n");
delay(2000);
printf("You lose karma for running away!");
printf("\t\t\t                               \n");
delay(2000);
K-=35;
printf("The metal monster hurtles toward you!");
printf("\t\t\t                               \n");
delay(2000);
printf("Brace yourself!");
printf("\t\t\t                               \n");
delay(2000); 
strcpy(enemy,"BOSS MECHA"); 
combat (playerName,gender,slot2,enemy,lammo,lvl,exp);
levelup(exp,lvl);                       
ki=1;
break;
}
}
}
printf("The dust settles as you rise from the rubble.");
printf("\t\t\t                               \n");
delay(2000);
printf("The destroyed hulk of the metal monster burns at you feet.");
printf("\t\t\t                               \n");
delay(2000);
printf("There is but one thing left to do.");
printf("\t\t\t                               \n");
delay(2000);
printf("Activate the self destruct sequence by pushing any key.");
printf("\t\t\t                               \n");
getch();
printf("The counter starts ||00:59||");
printf("\t\t\t                               \n");
delay(2000); 
printf("You sink to the ground and await your fate.");
printf("\t\t\t                               \n");
delay(2000); 
if(K>=70)//Good Karma Ending
{
printf("A voice calls out...");
printf("\t\t\t                               \n");
delay(2000);
printf("SURVIVOR:'Hey you there...'");
printf("\t\t\t                               \n");
delay(2000);
printf("SURVIVOR:'Get on the escape pod'");
printf("\t\t\t                               \n");
delay(2000);
printf("You run to the escape pod and hop in.");
printf("\t\t\t                               \n");
delay(2000);
printf("Press any button to eject escape pod.");
printf("\t\t\t                               \n");
getch();
printf("    ||WELCOME COMMANDER %s DEXTER||",playerName);
printf("\t\t\t                               \n");
delay(2000);
printf("    ||NEXT STOP : EARTH||");
printf("\t\t\t                               \n");
delay(2000);
printf("The thrusters power up as you escape into space.");
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                                 .    .     .            +         .         .    \n");              
printf("\t\t\t       .                 .                   .               .                      \n");  
printf("\t\t\t               .    ,,o         .                  __.o+.                           \n");
printf("\t\t\t     .            od8^                  .      oo888888P^b           .              \n");
printf("\t\t\t        .       ,'.o'      .     .             `b^'''`b -`b   .                      \n");
printf("\t\t\t              ,'.'o'             .   .          t. = -`b -`t.    .                   \n");
printf("\t\t\t             ; d o' .        ___          _.--.. 8  -  `b  =`b                       \n");
printf("\t\t\t         .  dooo8<       .o:':__;o.     ,;;o88%%8bb - = `b  =`b.    .                 \n"); 
printf("\t\t\t     .     |^88^88=. .,x88/::/ | \\`;;;;;;d%%%%%88%88888/%x88888                      \n");
printf("\t\t\t           :-88=88%%L8`%`|::|_>-<_||%;;%;8%%=;:::=%8;;/%%%%/8888                       \n");
printf("\t\t\t       .   |=88 88%%|HHHH|::| >-< |||;%;;8%%=;:::=%8;;;%%%%+|]88        .               \n");
printf("\t\t\t           | 88-88%%LL.%.%b::Y_|_Y/%|;;;;`%8%%oo88%:o%.;;;;+|]88  .                     \n");
printf("\t\t\t           Yx88o88^^''`^^%8boooood..-/H_Hd%P%%88%P^%%^'/;;;/%%88                         \n");
printf("\t\t\t          . `'|^|          ~''''''      d%P ''''^' ;   = `+' - P                         \n");
printf("\t\t\t    .        `.`.b   .                :<%%>  .   :  -   d' - P      . .                  \n");
printf("\t\t\t               .`.b     .        .    `788      ,'-  = d' =.'                            \n");
printf("\t\t\t        .       ``.b.                           :..-  :'  P                               \n");
printf("\t\t\t             .   `q.>b         .               `^^^:::::,'       .                        \n");
printf("\t\t\t                 ""^^               .                     .                                \n");
printf("\t\t\t   .                                           .               .       .                    \n");
printf("\t\t\t     .         .          .                 .        +         .                            \n");
delay(2000);
exit(0);
}
else
{
printf("Maybe your actions have finally caught up to you.");
printf("\t\t\t                               \n");
delay(2000);
printf("As the room vaporises in a flash...");
printf("\t\t\t                               \n");
delay(2000);
printf("You remember your name...COMMANDER %s",playerName);
printf("\t\t\t                               \n");
delay(2000);
printf("COMMANDER %s DEXTER",playerName);
printf("\t\t\t                               \n");
delay(2000);
printf("\t\t\t                                          ____             \n");
printf("\t\t\t                     __,-~~/~    `---.                      \n");
printf("\t\t\t                   _/_,---(      ,    )                     \n"); 
printf("\t\t\t               __ /        <    /   )  )___                  \n");
printf("\t\t\t ------===;;;'====------------------===;;;===----- -  -       \n");
printf("\t\t\t                  ( /  ~'~''~'~''~'~/~''~)~'/                  \n");
printf("\t\t\t                  (_ (   /  (     >    /)                     \n");
printf("\t\t\t                   (_( _ <         >_>'                        \n");
printf("\t\t\t                      ~ `-i' ::>|--'                            \n");
printf("\t\t\t                          I;|.|.|                                \n");
printf("\t\t\t                         <|i::|i|`.                              \n");
printf("\t\t\t                        (` ^'''`-' ')                            \n");
printf("\t\t\t                               \n");
delay(2000);
exit(0);                   
}
return(0);
}
}
int levelup(int exp,int lvl)
{
int req=lvl*5;
if (exp == req)
{
exp=0;
lvl+=1;
printf("You have leveled up to LVL %d",lvl);
printf("\t\t\t                               \n");
delay(2000);
printf("You can now do +1 damage and have +5 health.");
printf("\t\t\t                               \n");
delay(2000);
return lvl;//assign back to lvl
}
else
{
return lvl;
}
}















