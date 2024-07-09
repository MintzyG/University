# Conway's Game of Life

### Basics
Conway's Game of Life is what we call a celular automaton, which is a regular grid, each in one of a finite number of states, in this case the two states are:
- Dead
- Alive

The grid is two dimensional, and normally infinite, but to describe the game logically, the most we need is a 3x3.
Each cell has 8 neighbours and follows a set of four rules, which are:

- 1: If a cell is Alive and has less than 2 neighbours, it dies.
- 2: If a cell is Alive and has 2 or 3 neighbours, it keeps living.
- 3: If a cell is Dead and has Exactly three neighbours, it lives.
- 4: If a cell is Alive and has more than 3 neighbours, it dies.

It is important to note that every cell process it state at the same time as every other cell in the grid.


### Where did we start?

Since now you know the basics, how did we start making this a circuit?
Well we chose to tackle how a cell interprets a rule first, which we did in a circuit we named LOD23S.

### LOD23S

![](https://github.com/MintzyG/MyMonoRepo/blob/master/Univeristy/DigitalLogic/imgs/LOD23S.png)

Here we receive as input the amount of neighbours the current cell has in binary, the circuit then processes
which rule to activate independent of cell state, it outputs 1 in channel 'E' if a rule is activated and then
outputs 1 in either channel '2' or '3' to identify which rule was activated, if no rule was actiivated we can assume
the cell died, since the two remaining rules are about the cell death. Since here we do nothing with the current cell state
this information is sent to the next circuit to process what happens to the cell, that circuit it CSRTA23S.

### CSRA23S

![](https://github.com/MintzyG/MyMonoRepo/blob/master/Univeristy/DigitalLogic/imgs/CSRTA23S.png)

Inside this circuit we receive the previous chip outputs and the current cell's state, then we process what should happen
with this cell, originally we would just set the next state directly, so if the cell was alive and had three neighbours
we'd output 1. This however had a curious side effect of making half the truth table of the chip impossible, since the previous
chip was incapable of outputting half the truth table. The way we did solve this problem was a re-interpretation of how
this chip interprets the rules and cell state, it no longer outputs the next state directly, it now outputs if we should flip
the current state or not, this makes the impossible outputs a zero, meaning "do not flip state", however we have to remove
functionality from the chip to actually apply the next state to the cell. Do not worry about the flip flop at the end of the chip,
this will be explained later.

### CELL HEART

![](https://github.com/MintzyG/MyMonoRepo/blob/master/Univeristy/DigitalLogic/imgs/CELL-HEART.png)
