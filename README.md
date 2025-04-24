# GOPS-Coding-Contest-25
Game of Pure Strategy:<br>
<br>We created a function (C++) that returns a card that best guarantees a victory based on the situation.<br><br>
int playCard(int a[14], int b[14], int flippedCard, int currentPot)<br>
&nbsp; a: int array for our cards [ace 1, ... king 13]<br>
&nbsp; b: int array for opponent’s cards<br>
&nbsp; flippedCard: single integer from 1-13 indicating the flipped card for the round<br>
&nbsp; currentPot: positive integer indicating the current total value of the pot (same as the previous argument unless the previous round was a tie)<br>

Since it's easy to, let's test this on an online compiler (GDB)<br>
Upload 4 files: main.cpp, DefaultStrategies.cpp, Player.cpp, Player.hpp<br>
In order to test your function, copy and paste it into DefaultStrategies<br>
Then go to main (look at lines 29 and 30)<br>
Change the argument of one of the two players to the name of your function, and run.<br>
&nbsp; teams can play against each other by creating their own functions and doing the above<br>

