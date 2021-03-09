# Week 3 : 18-22 January, 2021
## Problem:
Travelling Salesman Problem (TSP) is a hard problem, and is simple to state. Given a graph in
which the nodes are locations of cities, and edges are labelled with the cost of travelling between
cities, find a cycle containing each city exactly once, such that the total cost of the tour is as low
as possible.
For the state of Rajasthan, find out at least twenty important tourist locations. Suppose your
relatives are about to visit you next week. Use Simulated Annealing to plan a cost effective tour
of Rajasthan. It is reasonable to assume that the cost of travelling between two locations is
proportional to the distance between them.

## Solution:

 - Some constant data I used in the code 
```sh
RATE_OF_COOLING=0.9;
INTIAL_TEMP=10000.00;
MIN_TEMP= 0.00001;
```
- Formula's used in code
```sh
Probability Function=exp(currentDistance-AdjacentDistatnce)/Temperature;
New Temperature=OldTemperature*(1-RATE_OF_COOLING);
```

## Run Process:
```sh
 First clone the repo and save in your local machine at appropriate folder.
 Open folder in ecllipse IDE.
 run the Driver.java file.
```
## Output:
![TSPRJ](https://user-images.githubusercontent.com/48892208/109255132-617c8c80-7819-11eb-843b-0e35a99fb01a.gif)
