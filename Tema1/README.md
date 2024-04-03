# 🎰 Case Simulator

This repository contains a C++ simulation of a case opening system, similar to those found in popular video games where players can open cases to receive random items of varying rarity.
The simulation includes an authentication system for players, a case system with different item rarities, and a simple console-based UI for interacting with the CS2 like case opening simulator.

## ✨ Features

- **🔐 Player Authentication**: Users can log in with a username and password.
- **📦 Case Opening**: Simulate opening cases to receive items of different rarities.
- **💰 Balance Management**: Players have a balance that is affected by opening cases and can be topped up.
- **🌈 Item Rarity System**: Items are categorized into rarities (blue, purple, pink, red, gold), affecting their value and drop rate.
- **📊 Analytics**: After opening cases, players can view statistics on their spending and the items they've received.

### 🛠 Compilation

1. Clone the repository to your local machine.
2. Navigate to the directory containing `main.cpp`.
3. Compile the program using `run.bat`:

### 🎮 Usage

Follow the on-screen prompts to interact with the simulator. The options include:

1. **📦 Open cases**: Spend your balance to open cases and receive items.
2. **💼 Show balance**: Display your current balance.
3. **🔍 Show cases**: List all the items in the current case.
4. **📈 Show analytics**: View statistics on your spending and the items you've received.
5. **💳 Top up balance**: Add funds to your balance.
6. **🚪 Quit**: Exit the simulator.

## 📚 Class Variables Overview

The simulation is built around several key classes, each with its own set of variables that drive the functionality of the simulator:

- ⛹️‍♂️ **Player**: Represents a player in the simulator.
  - `playerName`: The name of the player.
  - `balance`: The current balance of the player.
  - `password`: The player's password for authentication.

- 🔫 **Item**: Represents an item that can be found within a case.
  - `itemName`: The name of the item.
  - `itemPrice`: The price or value of the item.
  - `itemRarity`: The rarity category of the item (e.g., blue, purple, pink, red, gold).

- 🎁 **Case**: Represents a case that players can open to receive items.
  - `caseName`: The name of the case.
  - `casePrice`: The price to open the case.
  - `items`: A collection of items that can be obtained from the case.
  - Rarity vectors (`blues`, `purples`, `pinks`, `reds`, `golds`): Collections of items categorized by rarity.

These classes and their variables are central to the operation of the case simulator, managing everything from user authentication to the logic of case opening and item distribution.

## ⚠️ Disclaimer

This simulator is for educational and entertainment purposes only. It does not involve real money or gambling.
