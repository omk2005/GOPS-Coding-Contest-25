# GOPS-Coding-Contest-25: Our Strategy

This repository contains our team's submission for the **Game of Pure Strategy (GOPS)** coding challenge. We developed a C++ decision engine designed to outmaneuver opponents through dynamic pot evaluation and "Crunch Value" logic.

---

## 🎮 The Game: GOPS

GOPS is a simultaneous bidding game played with three sets of cards (1–13). A "Prize" card is flipped each round, and both players bid one card from their hand.

* **Higher bid wins** the prize.
* **Ties** cause the prize to stay in the pot for the next round.
* **The Goal** is to have the highest total points after all 13 rounds are played.

---

## 🧠 Our Strategy: "The Adaptive Cruncher"

Our team's `playCard` implementation doesn't just look at the current card; it calculates a dynamic "Crunch Value" to determine when to go all-in and when to fold. Here is our logic breakdown:

### 1. Small Pot Filtering

If the `currentPot` is 1 or less, we’ve decided it isn't worth wasting resources. Our bot will automatically play the **lowest available card** to save strength for higher-value rounds.

### 2. The "Crunch" Factor

We calculate a `crunchValue` based on how many rounds are left:


$$crunchValue = \max(15 - \text{remainingRounds}, 5)$$


If the pot meets this threshold and we have a card that can guaranteed-win against the opponent's best card, we play our **highest card** to secure the points.

### 3. Predictive Scaling & Target Selection

The bot estimates the opponent’s likely move using a scaling factor:

* It calculates a probability $p$ based on the pot size (scaled by 110% to stay aggressive).
* It targets a specific card in the opponent’s remaining hand based on this percentage.
* We use `std::upper_bound` to find the **smallest card in our hand that still beats the target.** This ensures we win the round while wasting as little "power" as possible.

### 4. High-Stakes Tie Logic

If we can't beat the opponent's predicted move:

* **High Stakes:** If the pot is significant ($p \ge 50$), we play our highest card to force a tie and keep the points on the table.
* **Low Stakes:** If the pot is small, we "trash" our lowest card to preserve our better cards for later.

---

## 🛠️ How to Run & Test

We’ve designed our code to be easily testable on an online compiler like **GDB**.

1. **Upload Files:** From the `Game_Files` folder, upload `main.cpp`, `DefaultStrategies.cpp`, `Player.cpp`, and `Player.hpp`.
2. **Add Our Function:** Copy and paste our `playCard` function into `DefaultStrategies.cpp`.
3. **Configure the Match:** * Open `main.cpp` and look at lines 29 and 30.
* Change the argument of one of the players to our function name:
```cpp
Player player1("OurTeamBot", playCard);

```




4. **Run:** Hit the "Run" button to see the turn-by-turn breakdown and final scores.

---

## 📈 Team Notes

* **Efficiency:** We used `std::vector` and `std::upper_bound` to keep the logic fast and readable.
* **Aggression:** The 110% scaling factor makes us play slightly higher cards than average, allowing us to dominate medium and large pots.

---
