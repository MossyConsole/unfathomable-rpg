<div align="center">
    <h1> Unfathomable: An Aspiring RPG built in C++ with SFML </h1>
</div>
<p>
    <i> Unfathomable </i> is an RPG game I programmed over the course of 8 weeks, in order to better learn C++ and to build a reasonably complex project to as my final project for a computer science course as a senior in highschool. 
    I accomplished this by first following a tutorial, then implementing my own features with the extra time I had before the semester's end. It is a top-down, pixelated (16x16 artificially-pixeled tiles) RPG set deep under the sea. In this readme, I detail my process as I went along programming it, as well as giving some general information about this project.
</p>

<h2> Contents </h2>
<ul>
    <li> My Process Thus Far </li>
    <li> About the Art </li>
    <li> Usage and Liscensing </li>
    <li> Screenshots </li>
    <li> External Links and Resources </li>
</ul>

<h2> My Process Thus Far </h2>
<p>
    I followed <b> Mustafa Sibai</b>'s YouTube Tutorial series: <b>Game Development in C++ with SFML</b>. Before this project, I had never built a big C++ project before, but as I had completed Harvard's online <b>CS50x2024</b> course, I had prior experience with the C programming language, so I had some familiarity with the syntax, but not much experience with C++. 
    In addition to learning the fundamentals of C++, I learnt how to use SFML (the Simple, Fast, Multimedia Library for C++). 
    From this tutorial, I also learnt how to use Github, Fork (the app), and Git, in order to put version control in place. 
    Speaking of Git, as of writing this, the newest and best version of my project does exist in the dev branch, and not master. 
    This is because I am not yet satisfied enough with the completeness of the game in order to push it to master. That will come with time, when I decide to come back and work on this again.
</p>
<p>
After completing the tutorial, which is to say I followed along to over 46 hours of YouTube videos (at 2x speed, so that I could finish on time), I decided to implement my own features. 
In the project (and by that I mean Visual Studio's definition of the word) for the map creator, I added feature so that the user could see all the tiles available to them to choose from. 
For this I added a sprite which displayed the whole tileset, in addition to a semi-transparent square which acted as a cursor, to show the user which sprite they have selected. 
Then, instead of mapping the tiles to numbers on the keyboard (as I wanted my tilesheets to have more than 10 tiles), I programmed it so that the user can move their square tile-picker cursor with WASD, as this is how they move the player character in the game proper.
Now, whenever the user used WASD, the position of their cursor would update to the next adjacent tile (or the furthest one if they started on the edge, to have wrapping) while internally, the ID of the tile they can use to draw with is replaced by the corresponging adjacent one in the 2D array of tiles.
</p>
<p>
    After that, I added a feature to the main game: dynamic collision detection. 
    When I say dynamic here, I mean that the program will, based off of preset data about the given tilesheet, create (transparent, aka invisible) collision sprites to overlay tiles that are set to have collision.
    This means that there is no extra work to be done by the user in the map creation process, when otherwise they would have to place collision tiles in a seperate layer of the map. 
    All they need do when adding a new tile set, is to go into the Map class and specify which index of tiles (0 through n, where n is the number of 16x16 pixel squares in tilesheet) should have collision. 
    Additionally, I set up a similar system for interaction tiles, like chests or doors, but I have yet to implement any features that use it.
<p>
    For the player-side of the collision, I just implemented a simple collision system on the x and y axes seperately, where if the player is close enough that their speed would have them go through the tile, their character sprite moves forward by 1 pixel per frame instead, until they reach the tile. As I write this, I'm realizing that I could've implemented a temporary speed that would constantly decrement and be applied only when the player wouldn't go through the tile, so that there is less of a noticeable change in speed. I may change the current system to that one in a future update.
</p>

<h2> About the Art </h2>
<p>
    All of the art is technically made by me, but I wouldn't claim ownership over the tilesets. 
    I used <b>Aseprite</b> for the pixel art, but I took tilesets from the Legend of Zelda: Link's Awakening video game.
    I used the website <b>The Spriter's Resource</b> to find them, and from there I put the images into Aseprite.
    In Aseprite, I recoloured the tiles so that they were in <i>Unfathomable</i>'s colour palette. 
    As an aside, my colour palette is based off of the original GameBoy's liquid-crystal-display's greens, but with their RGB values shifted.
    Back to the art, I then made completely original characters (a scuba diver protagonist, and a mean-looking squid) in Aseprite, and with that my art assets were done (for now).
</p>

<h2> Screenshots </h2>
<p>
    Here are some screenshots from both the map editor and the game itself:
</p>
<img src="rpg-game/Marketing (temp)/map_start.png" width=50% height=50% alt="Screenshot of Visual Studio Code and an open terminal, with an additional window containing a map editor for a pixel-art video game.">
<img src="rpg-game/Marketing (temp)/level-7.png" width=50% height=50% alt="Screenshot of Visual Studio Code and an open terminal, with an additional window containing a map editor for a pixel-art video game.">
<img src="rpg-game/Marketing (temp)/gameplay2.png" width=50% height=50% alt="Screenshot of Visual Studio Code and an open terminal, with an additional window containing a pixel-art video game.">
<img src="rpg-game/Marketing (temp)/caveplay.png" width=50% height=50% alt="Screenshot of Visual Studio Code and an open terminal, with an additional window containing a pixel-art video game.">

<h2> Usage and Liscensing </h2>
<p>
    I used SFML 2.5 for this project, as that was the version used by Mustafa Sibai in his YouTube series. Likewise, I chose Visual Studio for my IDE because I wanted to follow along to what he was doing.
</p>
<p>
    At the moment, I don't plan on releasing <i>Unfathomable</i> commercially, so you may do as you wish with this repo.  
    I also don't plan on spending too much time working further on this project, as it started just to help me learn and complete a project for school.
    Nevertheless, feel free to leave any comments or suggestions if you'd like, and I might respond.
    Once again this was just a fun personal project, so I don't expect myself to do much more with it as of writing this.
</p>

<h2> External Links and Resources </h2>
<ul>
    <li> 
        As I wrote earlier, this project is largely based off of Mustafa Sibai's YouTube tutorial series: "Game Development in C++ with SFML." This YouTube series is a fantastic resource for anyone willing to put in the time and effort to learn the basics of C++ (arrays, pointers, memory management, OOP, passing objects by address) and to learn as well how to use SFML to create a game in C++: 
        <ul> <li> <a href="https://youtube.com/playlist?list=PLs6oRBoE2-Q_fX_rzraQekRoL7Kr7s5xi&si=X_aeY8s9Ir1QYaDx"> Game Development in C++ with SFML - Mustafa Sibai (Playlist) </a> </li> </ul>
    </li>
    <li> 
        Here is the link to the Legend of Zelda: Link's Awakening tilesets:
        <ul> <li> <a href="https://www.spriters-resource.com/game_boy_gbc/thelegendofzeldalinksawakeningdx/sheet/9445/"> Link's Awakening - Overworld Tileset </a> </li> </ul>
    </li>
</ul>
