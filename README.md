# adaships
Challenge Outline

The task is to design and develop Adaship which is a battleship like game.
It was to be a 10x10 board with the ships placed on the board according to the board limitations.
The method to producing this was by first figuring out how to create and display the board on the console display. Second was how to place to ships and boundary limits, then how to attack and show hits and misses.
 
![image](https://user-images.githubusercontent.com/56548553/193835662-42de1e3a-18b2-4081-9601-44f1115c3cb0.png)

It will be started by creating the game board to be displayed on the console window to give the users a visual while playing. Making sure there is a grid with placement squares to place the ships and select where to attack and show hit and misses.
Next is to create a system for ship placement by the players with borders and limits to prevent ships being out of bounds of the game board. Taking into factor the predetermined length of each ship type (from 2 – 5) and allowing for horizontal and vertical directions for the ships being placed.
Player should be able to attack by choosing where to attack using grid positions by typing the position into the console once the game has started.
Hit and misses will be displayed by text coming up on the console stating to the player whether the attack landed or not. At the same time or directly after the board should be updated showing that where the attacked was placed was a hit or a miss.
If a ship is hit the ship object will lose hp which is based off the ships length, upon losing all of it’s health the ship will be registered as sunken with a notification being giving to the player.
Winner is determined by who sank all of the opponents ships first thus ending the game.

 Development
Due to time constraints it was not developed to the right standard, where it became a single player game and all ships were placed randomly.
No known bugs came up during development but the testing was not extensive an rather just to make sure everything works to a game completion on a very streamlined process.

Evaluation
The product works in a basic way, I would improve it by adding the other features stated at development. I would consider giving a Local Area Network playability between two computers. A lot more could have been done but due to constraints a lot of planned features had to be scrapped and the product did not turn out as initially planned but I still a good prototype or skeleton to build upon
