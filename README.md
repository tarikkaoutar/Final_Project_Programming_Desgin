
# Final project

this is the final project given by professor [Fu-Yin Cherng] following the requirement that we have learned in the semester at programming design.
I took inspiration from the Snake game to make my project, the code is written in C language, 
in this game, the player uses a 2-dimensional array to move a " P" around the board, 
As the player finds a village or gun, it chooses the items of the village(1:buy a magical sword; 2: go to the bar; 3:leave the village), 
and thereby able to kill all the monster. and as the player finds a trap will lose blood.
The game ends when the player either kill all monster or select exit(0).
# Our Design:
In our game, we will use a 2d list of integers called the map.  While the map we display shows village, player, monster, gun, a trap for the Player to get strength, 
blood, or fight with monster, the map will hold integer values corresponding to the player's, monster, village, gun, and the trap.  
For example, consider this situation:
row = 4 , column =3;             map
v    .     .    t                       [0,0] ,[0,1],[0,3],[0,4]
.    m     .    .                       [1,1]
.    P     .    G                       [2,1]
row = 0, coloum = 0 ===> V
# logic design
create 2d array using malloc size 1000,
 _setup village location and check the boundary if the input is outside the range or not, 
_setup monster location and check
boundary: if the input is outside the range or not (0,999)
print();
availability: check the input if the (column, row) occupied by another element (v,p,g,t);
_setup Player location and check
boundary: if the input is outside the range or not (0,999)
print();
availability: check the input if the (column, row) occupied by another element (v,p,g,t);
_setup trap location and check the boundary if the input is outside the range or not, 
_setup Gun location and check the boundary if the input is outside the range or not, 
check movement if the input is outside the range or occupied by another element(g,v, I,t,m) 
print(you are not able to go there)
/////////////////////////////////////////////////////////////////
go_up =====> [0,0] [0,1]=======>[P][0,1]
                          {1,0}==>{row-1=1- 1}==>{0,0}
                          [1,0] [1,1]=======>[1,0][1,1]
the player will move up
/////////////////////////////////////////////////////////////////
go_down===>{0,0}==>{row+1=0+ 1} ==>{1,0}
////////////////////////////////////////////////////////////////
go_left=====>[0,0] [0,1]=======>[0,0][0,1]
                         {0,1}===>{coloum-1=1 - 1}===>{0,0}
                          [1,0] [P]========>[P][1,1]
///////////////////////////////////////////////////////////////
go_right====>{1,0}==>{coloum+1=0+ 1}===>{1,1}
////////////////////////////////////////////////////////////////
==>if map row and column equal monster check the temp random bigger than 69 you have been beaten monster and replace monster by the player.
 if not, the monster hit you and you lose blood.
==>if map row and column equal gun increase strength and replace G by player.
==>if map row and column equal Trap decrease blood and replace T by player.
==>if map row and column equal village, select the village items.

## Acknowledgements

 - [Awesome Readme Templates](https://awesomeopensource.com/project/elangosundar/awesome-README-templates)
 - [Awesome README](https://github.com/matiassingers/awesome-readme)
 - [How to write a Good readme](https://bulldogjob.com/news/449-how-to-write-a-good-readme-for-your-github-project)
www.github.com
www.youtube.com
https://www.equestionanswers.com/c/dynamic-2d-3d-array.php


## Screenshots

![App Screenshot](https://paste.pics/7a467c73aefd241f08dc47d1a451c48a)
![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+https://paste.pics/187010a58bef600d226abb68ef106671)

