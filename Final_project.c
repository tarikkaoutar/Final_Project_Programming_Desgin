#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
#define increase_size 5
#define Max_of_location 999
/////////////////////////////////NOTE/////////////////////////////////////////////
// please all the function concept and explanation are in function explain-file//
/////////////////////////////////////////////////////////////////////////////////
void introduction(){
    printf("\t\t\t\t welcome to snake game concept made by Dalie\n\n\n");
    sleep(2);
    printf("\t\t\t\t\t Press Space to start game\n\n\n");
    sleep(2);
    printf("\t\t\t\t\t\t loading..");
    sleep(2);
    printf("...");
    sleep(2);
    printf("...\n");
    sleep(2);

}
char **create_map()
{

    char **map = (char**)malloc(sizeof(char*)*MAXSIZE);
    for(int i=0;i<MAXSIZE;i++){
        map[i]=(char*)malloc(sizeof(char)*MAXSIZE);
        for(int j=0;j<MAXSIZE;j++)
        {
            map[i][j]='.';
        }
    }
    return map;
}
void print_map(char** map,int *P_row,int *P_coloum)
{
    printf("=== MAP ===\n");
    for(int i = 0 ;i< *P_row + increase_size;i++)
    {
        for(int j = 0;j < *P_coloum + increase_size;j++)
        {
            printf(" %c",map[i][j]);
        }
        printf("\n");
    }
    printf("=== MAP ===\n");
}
void setup_village(char** map,int *V_r,int *V_c)
{
        printf("Set up the the village location!!!!\n");
        sleep(1);
        printf("Input the row and column for the village location:\n");
    while(scanf("%d %d",V_r,V_c)){
    if(check_boundary_V(*V_r,*V_c)==1){
        printf("the location is outside the map\n");
        printf("Input the row and column for the village location:\n");
    }
    else{
        map[*V_r][*V_c] = 'v';
        break;
        }
    }
}
int check_boundary_V(int V_r,int V_c)
{
    if(V_r > Max_of_location || V_r < 0 || V_c > Max_of_location || V_c < 0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Setup_Monster(char** map,int *M_r,int *M_c,int *total)
{
        printf("You need to assign location for %d monsters in total\n",*total);
    for(int i=0;i<*total;i++){
        printf("Set up the monster location!!!!\n");
        sleep(1);
        printf("Input the row and column for monster %d:",i);
    while(scanf("%d %d",M_r,M_c)){
    if(check_boundary_M(*M_r,*M_c)==1){
        printf("the location is outside the map\n");
        printf("Input the row and column for monster %d:",i);
        }
      else if(check_availability_M(map,*M_r,*M_c)==1){
        printf("the location is occupied\n");
        printf("Input the row and column for monster %d:",i);
        }
      else{
        map[*M_r][*M_c]= 'm';
        break;
           }
      }
    }
}
int check_boundary_M(int M_r ,int M_v)
{
    if(M_r > Max_of_location || M_r < 0 || M_v > Max_of_location ||  M_v < 0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_availability_M(char **map,int M_r,int M_c)
{
    if(map[M_r][M_c] != '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_boundary_P(int *P_row ,int *P_coloum)
{
    if(*P_row> Max_of_location || *P_row<0 || *P_coloum> Max_of_location ||  *P_coloum<0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_availability_P(char **map,int *P_row,int *P_coloum)
{
    if(map[*P_row][*P_coloum] != '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_move(char **map,int P_row,int P_coloum)
{
    if(P_row < 0 || P_row > Max_of_location || P_coloum < 0 || P_coloum > Max_of_location || map[P_row][P_coloum] != '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void go_up(char **map,int *P_row,int *P_coloum)
{
    if(check_move(map,(*P_row)-1,*P_coloum)==0)
    {
        map[*P_row][*P_coloum] = '.';
        *P_row-=1;
        map[*P_row][*P_coloum] = 'p';
        print_map(map,P_row,P_coloum);
    }
    else
    {
        printf("you can't go there\n ");
    }
}
void go_down(char **map,int *P_row,int *P_coloum)
{
    if(check_move(map,(*P_row)+1,*P_coloum)==0)
    {
        map[*P_row][*P_coloum] = '.';
        *P_row+=1;
        map[*P_row][*P_coloum] = 'p';
        print_map(map,P_row,P_coloum);
    }
    else
    {
        printf("you can't go there\n ");
    }
}
void go_left(char **map,int *P_row,int *P_coloum)
{
    if(check_move(map,*P_row,(*P_coloum)-1)==0)
    {
        map[*P_row][*P_coloum] = '.';
        *P_coloum-=1;
        map[*P_row][*P_coloum] = 'p';
        print_map(map,P_row,P_coloum);
    }
    else
    {
        printf("you can't go there\n ");
    }
}
void go_right(char **map,int *P_row,int *P_coloum)
{
    if(check_move(map,*P_row,(*P_coloum)+1)==0)
    {
        map[*P_row][*P_coloum] = '.';
        *P_coloum+=1;
        map[*P_row][*P_coloum] = 'p';
        print_map(map,P_row,P_coloum);
    }
    else
    {
        printf("you can't go there\n ");
    }
}

void game_start_go_up(char **map,int *P_row,int *P_coloum,int* strength,int *blood,int* sword)
{
    if(check_move(map,*P_row-1,*P_coloum)==0)
    {
        map[*P_row][*P_coloum] = '.';
        *P_row-=1;
        map[*P_row][*P_coloum] = 'p';
        print_map(map,P_row,P_coloum);
    }
    else
    {
        if(map[*P_row-1][*P_coloum] =='m')
        {
            int temp = (rand() %100) + 4 * (*strength);
            if(temp>69)
            {
                printf("you have beaten monster !!!\n\n");
                sleep(1);
                map[*P_row][*P_coloum] = '.';
                *P_row-=1;
                *sword += 1;
                 map[*P_row][*P_coloum] = 'p';
            }
            else
            {
                printf("You should have some powerful to protect yourself\n");
                sleep(1);
                *blood-=1;
            }
        }
        if(map[*P_row-1][*P_coloum] =='T')
        {
                printf("you fall into a trap!!!\n\n");
                printf("be careful next time!!!\n\n");
                sleep(1);
                *blood -= 1;
                map[*P_row][*P_coloum] = '.';
                *P_row-=1;
                map[*P_row][*P_coloum] = 'p';
        }
        if(map[*P_row-1][*P_coloum] =='G')
        {
                printf("The gun can kill monsters easily\n");
                sleep(1);
                *strength += 1;
                printf("You have %d attack power now!", *strength);
                map[*P_row][*P_coloum] = '.';
                *P_row-=1;
                map[*P_row][*P_coloum] = 'p';
        }
        if( map[*P_row-1][*P_coloum]  =='v')
        {
            printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?\n\n");
            int action;
            while(scanf("%d",&action)){
                    if(action == 1){
                        strength++;
                        printf("Nice sword! Now you have %d strength!\n",strength);
                        break;
                    }else if(action == 2 && blood == 10){
                        printf("Your blood is full. You don't need a beer\n.");
                        break;
                    }else{
                        printf("Nice beer! Now you have %d blood!\n",blood);
                        blood++;
                        break;
                    }if(action == 3){
                        printf("You are welcome to come back anytime!\n\n");
                        break;
                    }else if(action != 3){
                       printf("invalid number");
                       break;
                    }
           }
       }
    }
    print_map(map,P_row,P_coloum);
}
void game_start_go_down(char **map, int *P_row, int *P_coloum, int *strength, int *blood, int *sword)
{
    if(check_move(map,*P_row+1,*P_coloum)==0)
    {
                map[*P_row][*P_coloum] = '.';
                *P_row+=1;
                map[*P_row][*P_coloum] = 'p';
                print_map(map,P_row,P_coloum);
    }
    else
    {
        if(map[*P_row+1][*P_coloum] =='m')
        {
            int temp = (rand() %100) + 4 * (*strength);
            if(temp>69)
            {
                printf("you have beaten monster !!!\n\n");
                map[*P_row][*P_coloum] = '.';
                *P_row+=1;
                *sword += 1;
                map[*P_row][*P_coloum] = 'p';
            }
            else
            {
                printf("You should have some powerful to protect yourself\n");
                sleep(1);
                *blood-=1;
            }
        }
        if(map[*P_row+1][*P_coloum] =='T')
        {
                printf("you fall into a trap!!!\n\n");
                printf("be careful next time!!!\n\n");
                sleep(1);;
                *blood --;
                printf("You have %d blood now!", *blood);
                map[*P_row][*P_coloum] = '.';
                *P_row+=1;
                map[*P_row][*P_coloum] = 'p';
        }
        if(map[*P_row+1][*P_coloum] =='G')
        {
                printf("The gun can kill monsters easily\n");
                sleep(1);
                *strength++;
                map[*P_row][*P_coloum] = '.';
                *P_row+=1;
                map[*P_row][*P_coloum] = 'p';
        }
        if( map[*P_row+1][*P_coloum]  =='v')
        {
            printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?\n\n");
            int action;
            while(scanf("%d",&action)){
                    if(action == 1){
                        strength++;
                        printf("Nice sword! Now you have %d strength!\n",strength);
                        break;
                    }else if(action == 2 && blood == 10){
                        printf("Your blood is full. You don't need a beer\n.");
                        break;
                    }else{
                        printf("Nice beer! Now you have %d blood!\n",blood);
                        blood++;
                        break;
                    }if(action == 3){
                        printf("You are welcome to come back anytime!\n\n");
                        break;
                    }else if(action != 3){
                       printf("invalid number");
                       break;
                    }
            }
         }
    }
    print_map(map,P_row,P_coloum);

}
void game_start_go_right(char **map,int *P_row,int *P_coloum,int* strength,int* blood,int* sword)
{
    if(check_move(map,*P_row,*P_coloum+1)==0)
    {
        map[*P_row][*P_coloum] = '.';
        *P_coloum+=1;
        map[*P_row][*P_coloum] = 'p';
        print_map(map,P_row,P_coloum);
    }
    else
    {
        if(map[*P_row][*P_coloum+1] =='m')
        {
            int temp = (rand() %100) + 4 * (*strength);
            if(temp>69)
            {
                printf("you have beaten monster !!!\n\n");
                map[*P_row][*P_coloum] ='.';
                *P_coloum+=1;
                *sword += 1;
                map[*P_row][*P_coloum] ='p';
            }
            else
            {
                printf("You should have some powerful to protect yourself\n");
                *blood-=1;
            }
        }
        if(map[*P_row][*P_coloum+1] =='T')
        {
                printf("you fall into a trap!!!\n\n");
                printf("be careful next time!!!\n\n");
                sleep(1);
                *blood -= 1;
                map[*P_row][*P_coloum] ='.';
                 *P_coloum+=1;
                 map[*P_row][*P_coloum] ='p';
        }
        if(map[*P_row][*P_coloum+1]  =='G')
        {
                printf("The gun can kill monsters easily\n");
                sleep(1);
                *strength += 1;
                 map[*P_row][*P_coloum] ='.';
                 *P_coloum+=1;
                 map[*P_row][*P_coloum] ='p';
        }
        if( map[*P_row][*P_coloum+1]  =='v')
        {
            printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?\n\n");
            int action;
            while(scanf("%d",&action)){
                    if(action == 1){
                        strength++;
                        printf("Nice sword! Now you have %d strength!\n",strength);
                        break;
                    }else if(action == 2 && blood == 10){
                        printf("Your blood is full. You don't need a beer\n.");
                        break;
                    }else{
                        printf("Nice beer! Now you have %d blood!\n",blood);
                        blood++;
                        break;
                    }if(action == 3){
                        printf("You are welcome to come back anytime!\n\n");
                        break;
                    }if(action != 3){
                       printf("invalid number");
                       break;
                    }
             }
        }
    }
    print_map(map,P_row,P_coloum);
}
void game_start_go_left(char **map,int *P_row,int *P_coloum,int* strength, int* blood,int *sword)
{
    if(check_move(map,*P_row,*P_coloum-1)==0)
    {
      map[*P_row][*P_coloum] ='.';
        *P_coloum-=1;
         map[*P_row][*P_coloum] ='p';
         print_map(map,P_row,P_coloum);
    }
    else
    {
        if(map[*P_row][*P_coloum-1] =='m')
        {
            int temp = (rand() %100) + 4 * (*strength);
            if(temp>69)
            {
                printf("you have beaten monster !!!\n\n");
                map[*P_row][*P_coloum] ='.';
                *P_coloum-=1;
                *sword+=1;
                map[*P_row][*P_coloum] ='p';
            }
            else
            {
                printf("You should have some powerful to protect yourself\n");
                *blood-=1;
            }
        }
        if(map[*P_row][*P_coloum-1] =='T')
        {
            printf("you fall into a trap!!!\n\n");
            printf("be careful next time!!!\n\n");
            sleep(1);
            *blood -= 1;
            map[*P_row][*P_coloum] ='.';
            *P_coloum-=1;
           map[*P_row][*P_coloum] ='p';
        }
        if(map[*P_row][*P_coloum-1] =='G')
        {
            printf("The gun can kill monsters easily\n");
            sleep(1);
            strength+= 1;
            map[*P_row][*P_coloum] ='.';
            *P_coloum-=1;
            map[*P_row][*P_coloum] = 'p';
        }
        if(map[*P_row][*P_coloum-1] =='v')
        {
            printf("What do you want to do in our village (1:buy a magical sword; 2: go to the bar; 3:leave the village)?\n\n");
            int action;
            while(scanf("%d",&action)){
                    if(action == 1){
                        strength++;
                        printf("Nice sword! Now you have %d strength!\n",strength);
                        break;
                    }if(action == 2 && blood == 10){
                        printf("Your blood is full. You don't need a beer\n.");
                        break;
                    }else{
                        printf("Nice beer! Now you have %d blood!\n",blood);
                        blood++;
                        break;
                    }if(action == 3){
                        printf("You are welcome to come back anytime!\n\n");
                        break;
                    }if(action != 3){
                       printf("invalid number");
                       break;
                    }
              }
         }
    }
    print_map(map,P_row,P_coloum);
}

void setup_player( char** map ,int *P_row , int* P_coloum)
{
      printf("Set up the Player of location!!\n");
      sleep(1);
      printf("Input the row and column for Player:\n");
      while(scanf("%d %d",P_row,P_coloum)){
              if(check_boundary_P(P_row,P_coloum)==1){//checks whether row and coloum is out of the range
            printf("the location is outside the map\n");
              printf("Input the row and column for Player:\n");
              }
        else if(check_availability_P(map,P_row,P_coloum)==1){//check whether monstor and village has the same position
            printf("the location is occupied\n");
            printf("Input the row and column for Player:\n");
             }
        else{
        map[*P_row][*P_coloum]= 'p';
        break;
      }
  }

}
void Start_Fighting(char** map,int Position,int *P_row,int *P_coloum,int*strength,int *blood,int*sword)
{
    printf("[1] go up [2] go down [3] go right [4] go left [5] exit: \n");
    scanf("%d",&Position);
    switch(Position)
    {
        case 1:
            game_start_go_up(map,P_row,P_coloum,strength,blood,sword);
            break;
        case 2:
            game_start_go_down(map,P_row,P_coloum,strength,blood,sword);
            break;
        case 3:
            game_start_go_right(map,P_row,P_coloum,strength,blood,sword);
            break;
        case 4:
            game_start_go_left(map,P_row,P_coloum,strength,blood,sword);
            break;
        case 5:
            break;

    }
}
void gun(char **map, int *G_r, int *G_c)
{
        printf("Set up the Gun\n");
        sleep(1);
        printf("Input the row and column for Gun:\n");
    while(scanf("%d %d",G_r,G_c)){
    if(check_boundary_V(*G_r,*G_c)==1){
        printf("the location is outside the map\n");
        printf("Input the row and column for Gun:\n");
    }
    else{
        map[*G_r][*G_c] = 'G';
        break;
        }
    }
}
void trap(char** map,int *T_r,int *T_c)
{
        printf("Set up the traps\n");
        sleep(1);
        printf("Input the row and column for Trap:\n");
    while(scanf("%d %d",T_r,T_c)){
    if(check_boundary_V(*T_r,*T_c)==1){
        printf("the location is outside the map\n");
        printf("Input the row and column for Trap:\n");
    }
    else{
        map[*T_r][*T_c] = 'T';
        break;
        }
    }
}
void start_to_play(char **map,int *P_row,int *P_coloum,int Position,int*strength,int*blood,int *vl1,int*vl2,int* sword)
{
            printf("Hello adventurer.Are you ready for a new adventure?\n");
            sleep(1);
            printf("You have to fight against these evil monsters\n");
    while(1)
    {
        if(*sword==10)
        {
            printf("You Win! Congratulations!\n");
            break;
        }
        if(*blood<=0)
        {
            printf("GAME OVER!\n");
            break;
        }
        Start_Fighting(map,Position,P_row,P_coloum,strength,blood,sword);
    }
}
int main()
{
    int V_r,V_c,M_r,M_c,P_row,P_coloum;
    int choose_play,Position,total=5;
    int G_r,G_c,T_r,T_c;
    int blood=10;
    int strength=2;
    int sword=0;
    char **map;
    while(1)
    {
            introduction();
            map = create_map();
            gun(map,&G_r,&G_c);
            trap(map, &T_r, &T_c);
            setup_village(map,&V_r,&V_c);
            Setup_Monster(map,&M_r,&M_c,&total);
            printf("[1] Create a new map[2] Start travel the map: \n");
            scanf("%d",&choose_play);
        if(choose_play ==1){
            map = create_map();
            gun(map,&G_r,&G_c);
            trap(map, &T_r, &T_c);
            setup_village(map, &V_r,&V_c);
            Setup_Monster(map,&M_r,&M_c,&total);
        break;
           }
        break;
    }
            setup_player(map, &P_row,&P_coloum);
            print_map(map,&P_row,&P_coloum);
            printf("start to test controller\n");
    while(1)
    {
            printf("[1] go up [2] go down [3] go right [4] go left [5] exit: \n");
            scanf("%d",&Position);
        switch(Position)
        {
            case 1:
                go_up(map,&P_row,&P_coloum);
                continue;
            case 2:
                go_down(map,&P_row,&P_coloum);
                continue;
            case 3:
                go_right(map,&P_row,&P_coloum);
                continue;
            case 4:
                go_left(map,&P_row,&P_coloum);
                continue;
            case 5:
                break;
        }
        break;
    }
    start_to_play(map,&P_row,&P_coloum,Position,&strength,&blood,&V_r,&V_c,&sword);
    return 0;
}

