#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


#define MAXHEROES 4

int HeroesNameCheck(char hr) 
{
    if (hr == 'B' || hr == 'W' || hr == 'E' || hr == 'D')
        return 1;
    return 0;
}

int HeroesDuplication(char *Heroes, int num, char epilogh) 
{
    for (int i = 0; i < num; i++) 
    {
        if (epilogh == Heroes[i])
            return 1;
    }
    return 0;
}

int HeroHealth(char hp) 
{
    switch (hp) 
    {
        case 'B': return 8;
        case 'D': return 7;
        case 'E': return 6;
        case 'W': return 4;
        default: return 0;
    }
}
int HeroMove(char mv) 
{
    switch (mv) 
    {
        case 'B':
                return 8;
        case 'D':
                return 6;
        case 'E':
                return 12;
        case 'W':
                return 10;
        default:
                return 0;
    }
}

char* HeroChoices(int *outCount) 
{
    int num;
    char epilogh;
    char *sumhr = (char *)malloc(MAXHEROES * sizeof(char));
    int counter = 0;

    if (sumhr == NULL) 
    {
        printf("Segmetation Fault.\n");
        *outCount = 0;
        return NULL;
    }

    printf("Let's Start! Selections:\n");
    printf("Barbarian (B)\nDwarf (D)\nElf (E)\nWizard (W)\n");

    do 
    {
        printf("How many heroes do you want to choose?(1-4): ");
        scanf("%d", &num);
    } while (num < 1 || num > 4);

    while (counter < num) 
    {
        printf("Give character for Hero: %d (B/D/E/W): ", counter + 1);
        scanf(" %c", &epilogh);

        if (!HeroesNameCheck(epilogh)) 
        {
            printf("Invalid hero selection. Try Again!\n");
            continue;
        }

        if (HeroesDuplication(sumhr, counter, epilogh)) 
        {
            printf("The hero has already sellected. Pick another one.\n");
            continue;
        }

        sumhr[counter] = epilogh;
        printf("You chose: %c! Life: %d\n", epilogh, HeroHealth(epilogh));
        counter++;
    }

    *outCount = num;
    return sumhr;
}

char* MonsterEasyLevel(int *pl) 
{
    srand(time(NULL));
    int plhthos = rand() % 2 + 1;
    char *monsterhp = (char *)malloc(plhthos * sizeof(char));
    for (int i = 0; i < plhthos; i++) 
    {
        monsterhp[i] = rand() % 3 + 1;
    }
    *pl = plhthos;
    return monsterhp;
}

char* MonsterMediumLevel(int *pl) 
{
    srand(time(NULL));
    int plhthos = rand() % 4 + 1;
    char *monsterhp = (char *)malloc(plhthos * sizeof(char));
    for (int i = 0; i < plhthos; i++) 
    {
        monsterhp[i] = rand() % 3 + 4;
    }
    *pl = plhthos;
    return monsterhp;
}

char* MonsterHardLevel(int *pl) 
{
    srand(time(NULL));
    int plhthos = rand() % 6 + 1;
    char *monsterhp = (char *)malloc(plhthos * sizeof(char));
    for (int i = 0; i < plhthos; i++) 
    {
        monsterhp[i] = rand() % 3 + 7;
    }
    *pl = plhthos;
    return monsterhp;
}

void PrintDungeon(char **dungeon,int ROWS,int COLS) 
{
    printf("  ");
    for (char c = 'A'; c < 'A' + COLS; ++c) 
    {
        printf("%c ", c);
    }
    printf("\n");

    for (int i = -1; i < ROWS; i++) 
    {
        printf("--");
    }
    printf("-\n");

    for (int i = 0; i < ROWS; i++) 
    {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) 
        {
            if (j == 0) printf("|");
            printf("%c ", dungeon[i][j]);
        }
        printf("\n\n");
    }
}

void PutWalls(char **dungeon,int ROWS,int COLS,int lvl) 
{
    int door, finder;
    srand(time(NULL));
    if(lvl==0)
    {
        
    
    finder = rand() % (COLS - 1);
    for (int i = 0; i < COLS; i++) 
      {
          int x = rand() % 2;
          int y = rand() % 2;
          if (x == 1) dungeon[i][finder] = '.';
          else dungeon[i][finder] = '#';
          if (y == 1) dungeon[i][finder + 1] = '.';
          else dungeon[i][finder + 1] = '#';
       }
    door = rand() % (ROWS - 1);
    dungeon[door][finder] = '.';
    dungeon[door][finder + 1] = '.';
  }
     else if(lvl==1)
    {
        for(int j=0;j<2;j++)
        {    
          finder = rand() % (COLS - 1);
         for (int i = 0; i < COLS; i++) 
         {
          int x = rand() % 2;
          int y = rand() % 2;
          if (x == 1) dungeon[i][finder] = '.';
          else dungeon[i][finder] = '#';
          if (y == 1) dungeon[i][finder + 1] = '.';
          else dungeon[i][finder + 1] = '#';
       }
    
       door = rand() % (ROWS - 1);
       dungeon[door][finder] = '.';
       dungeon[door][finder + 1] = '.';
    
    }
  }
   else if(lvl==2)
    {
        for(int j=0;j<3;j++)
        {    
          finder = rand() % (COLS - 1);
         for (int i = 0; i < COLS; i++) 
         {
          int x = rand() % 2;
          int y = rand() % 2;
          if (x == 1) dungeon[i][finder] = '.';
          else dungeon[i][finder] = '#';
          if (y == 1) dungeon[i][finder + 1] = '.';
          else dungeon[i][finder + 1] = '#';
       }
    
       door = rand() % (ROWS - 1);
       dungeon[door][finder] = '.';
       dungeon[door][finder + 1] = '.';
    
    }
  }
}


void PutFurniture(char **dungeon,int ROWS,int COLS) 
{
    int x, y;
    srand(time(NULL));
    for (int i = 0; i < 6; i++) 
    {
        x = rand() % ROWS;
        y = rand() % COLS;
        dungeon[x][y] = '@';
    }
}

void PutHeroes(char **dungeon, char *sumhr, int heroCount, int **positions,int ROWS,int COLS) 
{
    int x, y, placed = 0;
    srand(time(NULL));
    while (placed < heroCount) 
    {
        x = rand() % ROWS;
        y = rand() % COLS;
        if (dungeon[x][y] == '.') 
        {
            dungeon[x][y] = sumhr[placed];
            positions[placed][0] = x;
            positions[placed][1] = y;
            placed++;
        }
    }
}

char* PutMonsters(char **dungeon, char *monsterhp, int *pl,int ROWS,int COLS) 
{
    int x, y, placed = 0;
    char *pinak=(char *)malloc( *pl * sizeof(char));
    srand(time(NULL));
    while (placed < *pl) 
    {
        x = rand() % ROWS;
        y = rand() % COLS;
        if (dungeon[x][y] == '.') 
        {
           pinak[placed] =dungeon[x][y];
            dungeon[x][y] = monsterhp[placed] + '0';
            placed++;
        }
    }
    return pinak;
}
void characterMove(char *command, char **dungeon, char *select, int hero_num, int **positions, int *remainingMoves,int ROWS,int COLS) 
{
    int mhkos = strlen(command);
    int thesh = -1, i, p1, p2, steps, times, t = 0;
    char com;

    for (i = 0; i < hero_num; i++) 
    {
        if (select[i] == command[0]) 
        {
            thesh = i;
            break;
        }
    }

    if (thesh == -1) 
    {
        printf("Hero not found!\n");
        return;
    }

    times = remainingMoves[thesh];
    if (times <= 0) 
    {
        printf("Hero: %c doesn't have any moves left.\n", command[0]);
        return;
    }

    printf("You chose %c to move! Remaining moves: %d\n", command[0], times);

    p1 = positions[thesh][0];
    p2 = positions[thesh][1];

    i = 2;
    while (i < mhkos) 
    {
        com = command[i];

        if (i + 1 >= mhkos || command[i + 1] < '0' || command[i + 1] > '9') 
        {
            printf("Invalid command after the %c\n", com);
            return;
        }

        steps = command[i + 1] - '0';

        if (t + steps > times) 
        {
            printf("You reached the move's limit (%d)!\n", times);
            return;
        }

        int new_p1 = p1;
        int new_p2 = p2;

        switch (com) 
        {
            case 'U': case 'u': new_p1 -= steps; break;
            case 'D': case 'd': new_p1 += steps; break;
            case 'L': case 'l': new_p2 -= steps; break;
            case 'R': case 'r': new_p2 += steps; break;
            default:
            {
                printf("Invalid order: %c\n", com);
                return;
            }
        }

        if (new_p1 < 0 || new_p1 >= ROWS || new_p2 < 0 || new_p2 >= COLS) 
        {
            printf("Invalid move! Out of dungeon!.\n");
            return;
        }

        if (dungeon[new_p1][new_p2] != '.') 
        {
            printf("Invalid Move! The cell (%d, %c) isn't free from '%c'.\n", new_p1 + 1, new_p2 + 'A', dungeon[new_p1][new_p2]);
            return;
        }

        dungeon[p1][p2] = '.';
        dungeon[new_p1][new_p2] = command[0];
        p1 = new_p1;
        p2 = new_p2;
        t += steps;

        i += 2;
    }

    positions[thesh][0] = p1;
    positions[thesh][1] = p2;
    remainingMoves[thesh] -= t;
    printf("Move successful. Remaining moves: %d\n", remainingMoves[thesh]);
}
int DiceAttack()
{
    int dice=0;
    int att=0;
    for(int i=1;i<=3;i++)
    {
        dice=1+(rand()%6);
        if(dice>=1 && dice<=3)
        {
            att=att+1;
        }
    }
    return att;
}
int DiceHeroDef()
{
    int dice=0;
    int def=0;
    for(int i=1;i<=3;i++)
    {
         dice=1+(rand()%6);
        if(dice>=4 && dice<=5)
        {
            def=def+1;
        }
    }
    return def;
}
int DiceMonsterDef()
{
    int dice=0;
    int def=0;
    for(int i=1;i<=3;i++)
    {
       dice=1+(rand()%6);
        if(dice==6)
        {
            def=def+1;
        }
    }
    return def;
}
void Battle(char **dungeon, char *command, int **positions, int hero_num, char *select,int attack,int defence,int *life,int ROWS,int COLS)
{
    
    int mhkos = strlen(command);
    int thesh = -1;
    int i;
    int p1, p2;
    int targetP1 = -1, targetP2 = -1;
    int att;
    int def;
    int x,y;
    char target;
    int damage;
    int oldHP,newHP;
    
    printf("BATTLE COMMENCE!!!!!!\n");
   
    
    for (int i = 0; i < hero_num; i++) 
    {
        if (select[i] == command[0]) 
        {
            thesh = i;
            break;
        }
    }

    if (thesh == -1) 
    {
        printf("Hero not found!\n");
        return;
    }

    p1 = positions[thesh][0];
    p2 = positions[thesh][1];

    printf("You chose the %c to attack! \n", command[0]);

    // Έλεγχος εντολής
    i = 1;
    if (command[i] != '>') 
    {
        printf("You missed the > symbol.\n");
        return;
    }

    i = 2;
    if (command[i] != 'a' && command[i] != 'A') 
    {
        printf("You have to type 'a' or 'A' to attack.\n");
        return;
    }

    i = 3;
    if (command[i] != '*') 
    {
        printf("You missed the '*' symbol.\n");
        return;
    }

    i = 4;
    char com = command[i];
    char com2 = command[i+1];

    
    switch (command[0]) 
    {
        case 'B': 
            printf("The Barbarian holds his sword and can attack up, down, left, or right.\n");
             x = com2 - '1'; 
             y = com - 'A';  
             target = dungeon[x][y];

            if (target >= '1' && target <= '9') 
            {
                if (p1 > 0 && dungeon[p1 - 1][p2] == target)
                {
                    targetP1 = p1 - 1;
                    targetP2 = p2;
                } 
                else if (p1 < ROWS - 1 && dungeon[p1 + 1][p2] == target) 
                {
                    targetP1 = p1 + 1;
                    targetP2 = p2;
                }
                else if (p2 > 0 && dungeon[p1][p2 - 1] == target) 
                {
                    targetP1 = p1;
                    targetP2 = p2 - 1;
                } 
                else if (p2 < COLS - 1 && dungeon[p1][p2 + 1] == target)
                {
                    targetP1 = p1;
                    targetP2 = p2 + 1;
                }
            }
            if (targetP1 == -1) 
            {
                printf("The target is not in range!\n");
                return;
            }

            printf("Successful attack! Enemy at (%d,%d) was hit!\n", targetP1 + 1, targetP2 + 1);
            
             att = DiceAttack();
            def = DiceMonsterDef();

            damage = att - def;
            if (damage < 0) damage = 0;

            oldHP = target - '0';
            newHP = oldHP - damage;

           printf("You made %d damage! (Monster's HP): %d → %d)\n", damage, oldHP, newHP > 0 ? newHP : 0);

            if (newHP <= 0) 
            {
              printf("The monster was hit with %d damage and killed!!\n", damage);
             dungeon[x][y] = '.';
            }       
            else 
            {
             printf("The monster was hit with %d damage. Life before: %d → now: %d\n", damage, oldHP, newHP);
             dungeon[x][y] = newHP + '0';  
            }
            break;
            case 'W' :
            printf("The Wizard holds his Mighty staff and can attack any vile monster on the map.\n");
             x = com2 - '1'; 
             y = com - 'A'; 
             targetP1=x;
             targetP2=y;

             target = dungeon[x][y];
            if (target < '1' || target > '9') 
            {
               printf("This target is not a  monster\n");
                return;
            }
           
            printf("Successful attack! Enemy at (%d,%d) was hit!\n", targetP1 + 1, targetP2 + 1);
            
             att = DiceAttack();
            def = DiceMonsterDef();

             damage = att - def;
            if (damage < 0) damage = 0;

            oldHP = target - '0';
            newHP = oldHP - damage;

           printf("You made %d damage! (Monster's HP): %d → %d)\n", damage, oldHP, newHP > 0 ? newHP : 0);

            if (newHP <= 0) 
            {
              printf("The monster was hit with %d damage and killed!!\n", damage);
             dungeon[x][y] = '.';
            }       
            else 
            {
             printf("The monster was hit with %d damage. Life before: %d → now: %d\n", damage, oldHP, newHP);
             dungeon[x][y] = newHP + '0';  
            }
            break;
            
            
            case 'D' :
              printf("The Dwarf holds his Iron Axe and attacks up down right left and diagonically.\n");

             x = com2 - '1'; 
             y = com - 'A';  

                 target = dungeon[x][y];

            if (target >= '1' && target <= '9') 
            {
                if (p1 > 0 && dungeon[p1 - 1][p2] == target)
                {
                    targetP1 = p1 - 1;
                    targetP2 = p2;
                } 
                else if (p1 < ROWS - 1 && dungeon[p1 + 1][p2] == target) 
                {
                    targetP1 = p1 + 1;
                    targetP2 = p2;
                }
                else if (p2 > 0 && dungeon[p1][p2 - 1] == target) 
                {
                    targetP1 = p1;
                    targetP2 = p2 - 1;
                } 
                else if (p2 < COLS - 1 && dungeon[p1][p2 + 1] == target)
                {
                    targetP1 = p1;
                    targetP2 = p2 + 1;
                }else if (p1 > 0 && p2 > 0 && dungeon[p1 - 1][p2 - 1] == target) 
                {
                  targetP1 = p1 - 1;
                  targetP2 = p2 - 1;
                }
                else if (p1 > 0 && p2 < COLS - 1 && dungeon[p1 - 1][p2 + 1] == target) 
                {
                  targetP1 = p1 - 1;
                  targetP2 = p2 + 1;
                }
                else if (p1 < ROWS - 1 && p2 > 0 && dungeon[p1 + 1][p2 - 1] == target) 
                {
                  targetP1 = p1 + 1;
                  targetP2 = p2 - 1;
                }
                else if (p1 < ROWS - 1 && p2 < COLS - 1 && dungeon[p1 + 1][p2 + 1] == target) 
                {
                  targetP1 = p1 + 1;
                  targetP2 = p2 + 1;
                }
            }
            if (targetP1 == -1) 
            {
                printf("The target is not in range!\n");
                return;
            }

            printf("Successful attack! Enemy at (%d,%d) was hit!\n", targetP1 + 1, targetP2 + 1);
            
             att = DiceAttack();
             def = DiceMonsterDef();

            damage = att - def;
            if (damage < 0) damage = 0;

            oldHP = target - '0';
            newHP = oldHP - damage;

           printf("You made %d damage! (Monster's HP): %d → %d)\n", damage, oldHP, newHP > 0 ? newHP : 0);

            if (newHP <= 0) 
            {
              printf("The monster was hit with %d damage and killed!\n", damage);
             dungeon[x][y] = '.';
            }       
            else 
            {
             printf("The monster was hit with %d damage. Life before: %d → now: %d\n", damage, oldHP, newHP);
             dungeon[x][y] = newHP + '0';  
            }
            
            break;
            case 'E' :
             printf("The Elf holds his Bow and can attack in a straight line (up/down/left/right) until a monster is hit or blocked.\n");
    
          x = com2 - '1';
          y = com - 'A';
         target = dungeon[x][y];

            if (x != p1 && y != p2) 
            {
              printf("The Elf can only attack along the same row or column.\n");
              return;
            }

    
        int flag = 0;
        int start, end;
        if (x == p1) 
        {  
       
          if (y < p2)
          {
            start = y + 1;
            end = p2;
          } else 
          {
            start = p2 + 1;
            end = y;
          }
          for (int j = start; j < end; j++)
          {
            if (dungeon[x][j] != '.')
            {
               flag = 1;
                printf("There is an obstacle at (%d,%d) between the Elf and the target.\n", x + 1, j + 1);
                break;
            }
           }
        } 
        else if (y == p2) 
        {  
        if (x < p1)
        {
            start = x + 1;
            end = p1;
        }
        else 
        {
            start = p1 + 1;
            end = x;
        }
        for (int i = start; i < end; i++) 
        {
            if (dungeon[i][y] != '.') 
            {
               flag = 1;
                printf("There is an obstacle at (%d,%d) between the Elf and the target.\n", i + 1, y + 1);
                break;
            }
        }
    }

       if (flag)
      {
        printf("There is an obstacle between the Elf and the target. Cannot attack.\n");
        return;
      }

   
      if (target < '1' || target > '9')
      {
        printf("The target is not a valid monster.\n");
        return;
      }

  
    printf("Successful attack! Enemy at (%d,%d) was hit!\n", x + 1, y + 1);
    att = DiceAttack();
    def = DiceMonsterDef();
    damage = att - def;
    if (damage < 0) damage = 0;
    oldHP = target - '0';
    newHP = oldHP - damage;
   printf("You dealt %d damage! (Monster HP: %d → %d)\n", damage, oldHP, newHP);

   if (newHP <= 0)
    {
     newHP = 0;
    }

    if (newHP <= 0) 
    {
        printf("The monster is dead!\n");
        dungeon[x][y] = '.';
    } else
    {
        dungeon[x][y] = newHP + '0';
    }
    break;
    
            default:
            printf("Unknown hero: %c\n", command[0]);
            break;
        
        
    }
  
}

void CreateMonsterJustice(char **dungeon, char *command, int difficulty,int ROWS,int COLS)
{
    int x, y, i;
    char colChar, rowChar;
    char target;
    int counter = 0;
    int length = strlen(command);

    srand(time(NULL)); 

    if (command[counter] != 'M' && command[counter] != 'm')
    {
        printf("You have to put M or m!!\n");
        return;
    }
    counter++;

    if (command[counter] != '>') 
    {
        printf("You have to put '>'!!\n");
        return;
    }
    counter++;

    if (length < counter + 2) 
    {
        printf("Invalid command format! Use M>A1 for example.\n");
        return;
    }

    colChar = command[counter];     
    rowChar = command[counter + 1]; 

    y = colChar - 'A';   
    x = rowChar - '1';  

    if (x < 0 || y < 0 || x >= ROWS || y >= COLS) 
    {
        printf("Coordinates out of bounds!\n");
        return;
    }

    target = dungeon[x][y];

    if (target == '.') 
    {
        switch (difficulty) 
        {
            case 1:
                i = rand() % 3 + 1; 
                dungeon[x][y] = '0' + i;
                break;
            case 2: 
                i = rand() % 3 + 4;
                dungeon[x][y] = '0' + i;
                break;
            case 3: 
                i = rand() % 3 + 7; 
                dungeon[x][y] = '0' + i;
                break;
            default:
                printf("Invalid selection of difficulty (k should be 1, 2 or 3)\n");
                break;
        }
        printf("Monster created at %c%d: %c\n", colChar, rowChar,dungeon[x][y]);
    } 
    else if (dungeon[x][y] >= 'A' && dungeon[x][y] <= 'Z') 
    {
        printf("Monster at %c%d destroyed.\n", colChar, rowChar);
        dungeon[x][y] = '.';
    } 
    else if (dungeon[x][y] == '#' || dungeon[x][y] == '@')
    {
        printf("You didn't choose a monster or an empty cell... Zargon is disappointed with you!!! ;(\n");
    }
    else if(dungeon[x][y]>='1' || dungeon[x][y]<=9)
    {
        printf("Monster at %c%c destroyed.\n", colChar, rowChar+'0'+1);
        dungeon[x][y]='.';
        
    }
    
}
void ZargonTurn(char **dungeon, int **hero_pos, char *hero_ids, int *hero_hp, int hero_num, int ROWS, int COLS)
{
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int max_steps = 10;

    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (dungeon[i][j] >= '1') 
            {
                if (dungeon[i][j] <= '9') 
                {
                    int attacked = 0;

                    for (int d = 0; d < 4; d++) 
                    {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (ni >= 0) 
                        {
                            if (ni < ROWS) 
                            {
                                if (nj >= 0) 
                                {
                                    if (nj < COLS) 
                                    {
                                        char cell = dungeon[ni][nj];
                                        for (int h = 0; h < hero_num; h++) 
                                        {
                                            if (cell == hero_ids[h]) 
                                            {
                                                if (hero_hp[h] > 0) 
                                                {
                                                    int skulls = DiceAttack();
                                                    int shields = DiceHeroDef();
                                                    int damage = skulls - shields;
                                                    if (damage < 0) 
                                                    {
                                                        damage = 0;
                                                    }
                                                    hero_hp[h] -= damage;
                                                    if (hero_hp[h] < 0) 
                                                    {
                                                        hero_hp[h] = 0;
                                                    }

                                                    printf("Monster at (%d,%d) attacked %c for %d damage. Remaining HP: %d\n", i + 1, j + 1, hero_ids[h], damage, hero_hp[h]);
                                                    
                                                    if (hero_hp[h] == 0) 
                                                    {
                                                        dungeon[ni][nj] = '.';
                                                        printf("%c has fallen!\n", hero_ids[h]);
                                                    }
                                                    attacked = 1;
                                                    break;
                                                }
                                            }
                                        }
                                        if (attacked) 
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if (attacked) 
                    {
                        continue;
                    }

                    int min_dist = 9999;
                    int tx = -1;
                    int ty = -1;

                    for (int h = 0; h < hero_num; h++) 
                    {
                        if (hero_hp[h] > 0) 
                        {
                            int dist = abs(hero_pos[h][0] - i) + abs(hero_pos[h][1] - j);
                            if (dist < min_dist) 
                            {
                                min_dist = dist;
                                tx = hero_pos[h][0];
                                ty = hero_pos[h][1];
                            }
                        }
                    }

                    int cx = i;
                    int cy = j;

                    for (int s = 0; s < max_steps; s++) 
                    {
                        int moved = 0;
                        int dx1;
                        int dy1;

                        if (tx < cx) 
                        {
                            dx1 = -1;
                        } 
                        else if (tx > cx) 
                        {
                            dx1 = 1;
                        } 
                        else 
                        {
                            dx1 = 0;
                        }

                        if (ty < cy) 
                        {
                            dy1 = -1;
                        } 
                        else if (ty > cy) 
                        {
                            dy1 = 1;
                        } 
                        else 
                        {
                            dy1 = 0;
                        }

                        int nx = cx + dx1;
                        int ny = cy + dy1;

                        if (nx >= 0) 
                        {
                            if (nx < ROWS) 
                            {
                                if (dungeon[nx][cy] == '.') 
                                {
                                    dungeon[nx][cy] = dungeon[cx][cy];
                                    dungeon[cx][cy] = '.';
                                    cx = nx;
                                    moved = 1;
                                }
                            }
                        }

                        if (moved == 0) 
                        {
                            if (ny >= 0) 
                            {
                                if (ny < COLS) 
                                {
                                    if (dungeon[cx][ny] == '.') 
                                    {
                                        dungeon[cx][ny] = dungeon[cx][cy];
                                        dungeon[cx][cy] = '.';
                                        cy = ny;
                                        moved = 1;
                                    }
                                }
                            }
                        }

                        if (moved == 0) 
                        {
                            break;
                        }
                    }
                }
            }
        }
    }
}




int main(void)
{
    char **dungeon;
    char choice;
    int difficulty, heroCount;
    char *heroes;
    int pl = 0;
    char *monsters;
    int k;
    int attack, defend;
    int COLS = 6;
    int ROWS = 6;
    int lvl = 0;

    printf("\t\t-ˏˋ⋆ WELCOME ⋆ˊˎ-\n");
    printf("Do you want to start the game? (Y/N): ");
    scanf(" %c", &choice);

    if (choice != 'Y' && choice != 'y')
    {
        printf("Game canceled. See you!\n");
        return 0;
    }

    heroes = HeroChoices(&heroCount);
    int *lifes = malloc(heroCount * sizeof(int));
    for (int i = 0; i < heroCount; i++)
    {
        lifes[i] = HeroHealth(heroes[i]);
    }

    printf("Choose difficulty level (1-3): ");
    scanf("%d", &difficulty);

    while (lvl < 3)
    {
        if (lvl == 0)
        {
            ROWS = 6;
            COLS = 6;
        }
        else if (lvl == 1)
        {
            ROWS = 8;
            COLS = 8;
        }
        else
        {
            ROWS = 9;
            COLS = 9;
        }

        dungeon = malloc(ROWS * sizeof(char *));
        for (int i = 0; i < ROWS; i++)
        {
            dungeon[i] = malloc(COLS * sizeof(char));
            for (int j = 0; j < COLS; j++)
            {
                dungeon[i][j] = '.';
            }
        }

        int **positions = malloc(heroCount * sizeof(int *));
        for (int i = 0; i < heroCount; i++)
        {
            positions[i] = malloc(2 * sizeof(int));
        }

        int **monster_pos = malloc(100 * sizeof(int *));
        for (int i = 0; i < 100; i++)
        {
            monster_pos[i] = malloc(2 * sizeof(int));
        }

        int *remainingMoves = malloc(heroCount * sizeof(int));
        for (int i = 0; i < heroCount; i++)
        {
            remainingMoves[i] = HeroMove(heroes[i]);
        }

        switch (difficulty)
        {
            case 1:
                monsters = MonsterEasyLevel(&pl);
                break;
            case 2:
                monsters = MonsterMediumLevel(&pl);
                break;
            case 3:
                monsters = MonsterHardLevel(&pl);
                break;
            default:
                printf("Invalid Choice\n");
                continue;
        }

        PutWalls(dungeon, ROWS, COLS, lvl);
        PutFurniture(dungeon, ROWS, COLS);
        PutHeroes(dungeon, heroes, heroCount, positions, ROWS, COLS);
        PutMonsters(dungeon, monsters, &pl, ROWS, COLS);
        PrintDungeon(dungeon, ROWS, COLS);

        printf("\n~~~ Important Notification ~~~\n");
        printf("| Barbarian: 8 moves \n| Dwarf: 6 moves \n| Elf: 12 moves \n| Wizard: 10 moves\n");

        if (lvl == 0)
        {
            printf("「 ✦ FIRST ROUND ✦ 」\n  ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\n");
        }
        else if (lvl == 1)
        {
            printf("「 ✦ SECOND ROUND ✦ 」\n  ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\n");
        }
        else
        {
            printf("「 ✦ FINAL ROUND ✦ 」\n  ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\n");
        }

        int gameActive = 1;
        while (gameActive)
        {
            int choiceValid = 1;
            printf("\nGame Player Choices\n1. Movement\n2. Battle\n3. End Turn\n4. Put/Destroy Monsters\n5. Terminate Game\nYour choice:  ");
            scanf("%d", &k);

            switch (k)
            {
                case 1:
                {
                    char aws;
                    while (1)
                    {
                        int allZero = 1;
                        for (int i = 0; i < heroCount; i++)
                        {
                            if (remainingMoves[i] > 0)
                            {
                                allZero = 0;
                                break;
                            }
                        }

                        printf("Do you want to finish your turn (Press Y/y or N/n):\n");
                        scanf(" %c", &aws);
                        if (aws == 'y' || aws == 'Y')
                        {
                            break;
                        }

                        if (allZero)
                        {
                            printf("All of the heroes are out of moves. End round!\n");
                            break;
                        }

                        char *command = malloc(100);
                        printf("Give movement order (e.g. B>D3R1): ");
                        scanf(" %s", command);
                        characterMove(command, dungeon, heroes, heroCount, positions, remainingMoves, ROWS, COLS);
                        PrintDungeon(dungeon, ROWS, COLS);
                        free(command);
                    }
                    break;
                }

                case 2:
                {
                    char *command = malloc(100);
                    printf("Give battle command (e.g. B>A*3): ");
                    scanf(" %s", command);
                    Battle(dungeon, command, positions, heroCount, heroes, attack, defend, lifes, ROWS, COLS);
                    PrintDungeon(dungeon, ROWS, COLS);
                    free(command);

                    int alive = 0;
                    for (int i = 0; i < ROWS; i++)
                    {
                        for (int j = 0; j < COLS; j++)
                        {
                            if (dungeon[i][j] >= '1' && dungeon[i][j] <= '9')
                            {
                                alive++;
                            }
                        }
                    }

                    if (alive == 0)
                    {
                       
                       printf("You killed all the monsters! Let's go to the next round.\n");
                            
                        
                    }
                    break;
                }

                case 3:
                {
                    printf("Turn ended. Now Zargon plays...\n");
                    ZargonTurn(dungeon, positions, heroes, lifes, heroCount, ROWS, COLS);
                    PrintDungeon(dungeon, ROWS, COLS);
                    for (int i = 0; i < heroCount; i++)
                    {
                         remainingMoves[i] = HeroMove(heroes[i]);
                    }

                    int allDead = 1;
                    for (int i = 0; i < heroCount; i++) 
                    {
                        if (lifes[i] > 0) 
                        {
                            allDead = 0;
                            break;
                        }
                    }

                    if (allDead)
                    {
                        printf("\nAll heroes have fallen...\n");
                        printf("   _____                         ____                 \n");
                        printf("  / ____|                       / __ \\                \n");
                        printf(" | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
                        printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n");
                        printf(" | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
                        printf("  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n");
                        printf("                   GAME OVER                  \n");
                        gameActive = 0;
                        lvl = 3;
                        break;
                    }

                    break;
                }

                case 4:
                {
                    char *command = malloc(100);
                    printf("Give monster command: ");
                    scanf(" %s", command);
                    CreateMonsterJustice(dungeon, command, difficulty, ROWS, COLS);
                    PrintDungeon(dungeon, ROWS, COLS);
                    free(command);

                    int alive = 0;
                    for (int i = 0; i < ROWS; i++)
                    {
                        for (int j = 0; j < COLS; j++)
                        {
                            if (dungeon[i][j] >= '1' && dungeon[i][j] <= '9')
                            {
                                alive++;
                            }
                        }
                    }

                    if (alive == 0)
                    {
                        gameActive = 0;
                    }
                    break;
                }

                case 5:
                {
                    printf("You chose to finish the game.\n");
                    gameActive = 0;
                    lvl = 4;
                    break;
                }

                default:
                {
                    printf("Invalid choice.\n");
                    break;
                }
            }
        }

        for (int i = 0; i < ROWS; i++)
        {
            free(dungeon[i]);
        }
        free(dungeon);

        for (int i = 0; i < heroCount; i++)
        {
            free(positions[i]);
        }
        free(positions);

        for (int i = 0; i < 100; i++)
        {
            free(monster_pos[i]);
        }
        free(monster_pos);

        free(remainingMoves);
        free(monsters);

        if (lvl < 3)
        {
            lvl++;
        }
    }
    if(lvl==3)
    {
        printf("~~~YOUR HEROES MADE IT OUT OF THE DUNGEON VICTORIUS~~~");
        printf("\nZARGON AND HIS ARMY LIE IN RUINS\nCONGRATULATIONS");

    }
    

    free(heroes);
    free(lifes);

    return 0;
}