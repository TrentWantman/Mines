# Mines Documentation

## **Overview**

This is a remastered version of the Stake.com game "Mines" with improvements to the UI and brand new creative story components and achievements. The best part: you don't lose money!

---

## **Files and Functions**

### **GameController.cpp**
The `GameController` class manages the overall game flow, handling user input, rendering, and game state transitions.

#### **Functions:**
- **`GameController()`**  
  Initializes the game, including the window, UI elements (buttons, text, etc.), and the game state. This constructor sets up the initial layout of the tiles and other interactive components.

- **`void Run()`**  
  Main game loop that continuously processes input, updates the game state, and renders the game elements until the window is closed.

- **`void ProcessEvents()`**  
  Handles player input such as mouse clicks and key presses. It processes each event (e.g., closing the window, clicking on tiles, interacting with UI elements).

- **`void Update()`**  
  Updates the game state based on the current state (e.g., revealing tiles, adjusting wager, handling payouts).

- **`void Render()`**  
  Draws the game elements like tiles, buttons, and text on the screen depending on the current game state.

- **`void InitializeTiles()`**  
  Sets up the initial grid of tiles that the player interacts with.

- **`void DrawTiles()`**  
  Draws all the tiles in the game.

- **`void SetTiles()`**  
  Resets the game board and randomly places mines and gems on the tiles.

- **`void CheckTiles(sf::Vector2i mousePos)`**  
  Checks if a tile has been clicked and reveals the tile's content (gem or mine).

- **`void CountGems()`**  
  Counts the number of gems revealed by the player during the game.

- **`void RevealTiles()`**  
  Reveals all tiles on the board at the end of the game (when the player loses or cashes out).

- **`void EndGame(bool win)`**  
  Ends the current round by revealing all tiles, updating the player's bank balance, and preparing for the next round.

- **`void UpdateWagerOutput()`**  
  Updates the visual representation of the player's wager on the screen.

- **`void UpdatePayoutOutput()`**  
  Updates the payout display based on the player's current wager and multiplier.

- **`void UpdateMultiplierOutput()`**  
  Updates the multiplier display, showing how much the wager is being multiplied.

- **`void UpdateMineGemOutput()`**  
  Updates the display for the number of mines and gems selected by the player.

---

### **Bank.cpp**
The `Bank` class manages the player's balance and provides functionality to deposit and withdraw funds. It also handles the visual display of the bank's balance.

#### **Functions:**
- **`Bank()`**  
  Initializes the bank balance and sets up the UI for displaying the balance.

- **`void withdrawl(double amount)`**  
  Deducts the specified `amount` from the player's bank balance.

- **`void deposit(double amount)`**  
  Adds the specified `amount` to the player's bank balance.

- **`void drawBank(sf::RenderWindow& window)`**  
  Renders the bank balance and associated UI elements on the game window.

- **`void UpdateBankOutput()`**  
  Updates the text displaying the bank balance on the screen.

---

### **BetButton.cpp**
Handles the "Bet" button in the game, allowing the player to place their bet before starting a round.

#### **Functions:**
- **`BetButton()`**  
  Initializes the bet button and sets the default state (not hovered, not clicked).

- **`void hoverCheck(const sf::Vector2i& mousePos)`**  
  Checks if the mouse is hovering over the button and changes its appearance if necessary.

- **`bool isClicked()`**  
  Returns `true` if the player clicks on the button.

- **`void draw(sf::RenderWindow& window)`**  
  Draws the bet button on the game window.

- **`void setPosition(float x, float y)`**  
  Sets the button's position on the game screen.

---

### **CashoutButton.cpp**
Handles the "Cash Out" button, which allows the player to cash out and end the game, collecting their winnings.

#### **Functions:**
- **`CashoutButton()`**  
  Initializes the cashout button and sets the default state (not hovered, not clicked).

- **`void hoverCheck(const sf::Vector2i& mousePos)`**  
  Checks if the mouse is hovering over the cashout button and changes the button’s appearance.

- **`bool isClicked()`**  
  Returns `true` if the player clicks on the button to cash out.

- **`void draw(sf::RenderWindow& window)`**  
  Draws the cashout button on the game window.

- **`void setPosition(float x, float y)`**  
  Sets the position of the cashout button on the game screen.

---

### **EasterEgg.cpp**
The `EasterEgg` class manages hidden events that are triggered based on specific player actions, such as reaching certain milestones with their bank balance.

#### **Functions:**
- **`EasterEgg()`**  
  Initializes the Easter egg system and its UI elements.

- **`void checkStatus(double& bank, GameState gameState, sf::Event& event, sf::Text& bankText, Wallpapers& wallpapers)`**  
  Checks the player's current bank and game state to determine if any Easter egg events should be triggered.

- **`void checkStep4(double bank, double wagerAmount, GameState gameState, Wallpapers& wallpapers)`**  
  Checks if the player has gone "all-in" and updates the Easter egg progress accordingly.

- **`void processGameResult(double multiplier, double& bank)`**  
  Adjusts the player's bank based on the game result (win or loss) and checks for any Easter egg triggers.

---

### **GameSaver.cpp**
The `GameSaver` class handles saving and loading the game’s state to and from a file.

#### **Functions:**
- **`GameSaver()`**  
  Constructor that sets up the game-saving mechanism.

- **`void saveGame(...)`**  
  Saves the current game state (e.g., bank balance, Easter egg progress, game history) to the file `saveFile.txt`.

- **`void loadGame(...)`**  
  Loads the game state from `saveFile.txt` and restores all game elements (e.g., bank balance, Easter egg step, and game history).

---

### **History.cpp**
Manages the history of the game, recording details of each round played, such as wagers, number of mines and gems, and payout amounts.

#### **Functions:**
- **`History()`**  
  Initializes the game history tracker.

- **`void addRound(int mines, int gems, double wager, double multiplier, double payout)`**  
  Adds a round to the history with details like the number of mines, revealed gems, wager, multiplier, and payout.

- **`void drawHistory(sf::RenderWindow& window)`**  
  Draws the history of previous rounds on the game window.

---

### **Multiplier.xlsx**
Contains data related to the game’s multiplier system, which calculates payout multipliers based on the number of gems revealed.

#### **Contents:**
- **Multiplier values**: Maps the number of gems revealed to the corresponding multiplier that increases the player's payout.

---

### **saveFile.txt**
Stores the serialized game data, including player’s bank balance, Easter egg progress, and the game’s history.

#### **Contents:**
- **Bank balance**: The player’s current bank balance.
- **Easter egg progress**: The step of the Easter egg sequence the player has unlocked.
- **Wallpaper unlocks**: The wallpapers that have been unlocked.
- **Game history**: Previous rounds, including wager, multiplier, and payout.

---

### **PayoutDisplay.cpp**
Handles the display of potential payouts the player could receive based on their current wager and the multiplier.

#### **Functions:**
- **`PayoutDisplay()`**  
  Initializes the payout display and related UI elements.

- **`void updatePayout(double multiplier, double wager)`**  
  Updates the displayed payout based on the current wager and multiplier.

- **`void drawPayout(sf::RenderWindow& window)`**  
  Draws the payout information on the game window.

---
### **Jeff.cpp**
The `Jeff` class manages some financial aspects of the game, such as borrowing money or repaying debt. It interacts with the player's bank and tracks the amount of money owed by the player.

#### **Functions:**
- **`Jeff()`**  
  Initializes the `Jeff` object and sets the `owedMoney` attribute to 0.

- **`void borrowMoney()`**  
  Increases the `owedMoney` by $100 each time it is called, simulating borrowing money from Jeff.
  Can only be used when players bank balance is at $0.
  Adds $100 to players bank balance.

- **`void pay()`**  
  Resets the `owedMoney` attribute to 0, simulating the repayment of all debt.
  Removes the amount of debt from the players bank balance.

- **`void displayOwedMoney(sf::RenderWindow& window)`**  
  Displays the current amount owed by the player on the screen.

---

### **Menu.cpp**
Handles the game’s main menu, including options such as starting a game, accessing settings, and more.

#### **Functions:**
- **`Menu()`**  
  Initializes the menu UI and its options.

- **`void drawMenu(sf::RenderWindow& window)`**  
  Draws the menu options on the game window, allowing the player to select options.

- **`void handleClick(sf::Vector2i mousePos)`**  
  Processes mouse clicks on the menu options and triggers corresponding actions.

- **`void updateMenu()`**  
  Updates the menu elements, enabling animations or state changes as the player navigates through the options.

---

### **MineOptions.cpp**
Manages the options for selecting the number of mines in the game, allowing the player to adjust game difficulty.

#### **Functions:**
- **`MineOptions()`**  
  Initializes the mine options available for the player to choose from.

- **`void drawMineOptions(sf::RenderWindow& window)`**  
  Draws the available mine options on the screen.

- **`void setMines(int mines)`**  
  Sets the number of mines for the game based on the player's selection.

---

### **random.cpp**
Provides utility functions for generating random numbers and shuffling game elements.

#### **Functions:**
- **`int getRandomNumber(int min, int max)`**  
  Returns a random number between the specified `min` and `max`.

---

### **Texture.cpp**
Handles loading and managing the textures used in the game, such as the visuals for tiles, buttons, and background elements.

#### **Functions:**
- **`Texture()`**  
  Initializes the texture manager and prepares it for loading textures.

- **`sf::Texture& GetTexture(const std::string& textureName)`**  
  Loads a texture from the specified file or returns a cached version if the texture has already been loaded.

- **`void removeTexture(const std::string& textureName)`**  
  Removes a texture from the cache to free up memory when it is no longer needed.

---

### **Tile.cpp**
The `Tile` class represents each tile on the game board. Tiles can either contain mines or gems and are revealed as part of the gameplay.

#### **Functions:**
- **`Tile()`**  
  Initializes a tile, setting its default state as unrevealed and empty.

- **`void revealTile()`**  
  Reveals the tile’s content, showing whether it contains a mine or a gem.

- **`void drawTile(sf::RenderWindow& window)`**  
  Draws the tile on the game window, showing either the default hidden state or the revealed content.

- **`bool isMine()`**  
  Returns `true` if the tile contains a mine, otherwise `false`.

---

### **WallPaper.cpp** and **Wallpapers.cpp**
Handles the game’s wallpaper, which serves as the background for various game stages. Multiple wallpapers can be unlocked and displayed depending on the player's progress.

#### **Functions in `WallPaper.cpp`:**
- **`WallPaper()`**  
  Loads a wallpaper from a file and prepares it for rendering.

- **`void draw(sf::RenderWindow& window)`**  
  Draws the wallpaper on the game window, ensuring the background is updated in real-time.

#### **Functions in `Wallpapers.cpp`:**
- **`Wallpapers()`**  
  Manages multiple wallpapers that can be unlocked based on the player's progression in the game.

- **`void unlockWallpaper(int index)`**  
  Unlocks a new wallpaper when specific conditions are met in the game.

- **`void drawAllWallpapers(sf::RenderWindow& window)`**  
  Renders all unlocked wallpapers on the screen.

---

### **WagerOptions.cpp**
Manages the player's options for setting the wager amount during the game. The player can choose how much money they want to bet before revealing tiles.

#### **Functions:**
- **`WagerOptions()`**  
  Initializes the wager options available to the player.

- **`void drawWagerOptions(sf::RenderWindow& window)`**  
  Displays the wager options on the screen.

- **`void setWager(int wager)`**  
  Sets the player's wager amount based on their selection.

---

### **mine_options.h**
Defines the available mine options, allowing the player to choose how many mines will be placed on the game board.

#### **Attributes:**
- **`int mines`**  
  The current number of mines selected by the player.

#### **Functions:**
- **`void setMines(int mines)`**  
  Sets the number of mines based on the player’s choice.

---

### **multiplier.h**
Defines the logic for calculating the payout multiplier based on the number of tiles revealed during the game.

#### **Attributes:**
- **`double multiplier`**  
  The current multiplier value, which increases as more gems are revealed.

#### **Functions:**
- **`double getMultiplier(int revealedGems)`**  
  Returns the multiplier value based on the number of gems revealed during the round.

---

### **random.h**
Defines the utility functions for generating random values in the game.

#### **Functions:**
- **`int getRandomNumber(int min, int max)`**  
  Returns a random number within the specified range.

---

### **saveFile.txt**
Stores the game’s serialized data, allowing the player to save and resume their progress. This file contains key details like the player's bank balance, Easter egg progress, and wallpaper unlocks.

#### **Contents:**
- **Bank balance**: The current balance of the player’s bank.
- **Easter egg progress**: The stage of the Easter egg sequence that has been unlocked.
- **Wallpaper unlocks**: Information about the wallpapers that the player has unlocked.
- **Game history**: Details of past rounds, including wager amounts, payouts, and game results.

---

### **Multiplier.xlsx**
Contains multiplier data used to calculate payouts. This file provides the data used to scale the player's earnings based on how many gems are revealed during each round.

#### **Contents:**
- **Multiplier values**: The table of multipliers based on the number of gems revealed during the game, which influences the player’s final payout.

---

## **How to Use**
1. **Build the Game**: Compile the project using CMake and run the executable.
2. **Game Flow**: Players place wagers, reveal tiles, and try to avoid mines while revealing gems.
3. **Saving and Loading**: The game’s state is automatically saved to `saveFile.txt` when the game ends, and it can be loaded when the game restarts.

---
