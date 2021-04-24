## Week 6 : 15-19 February, 2020


Learning Objective:
To implement Expectation Maximization routine for learning parameters of a Hidden Markov Model, to be able to use EM framework for deriving algorithms for problems with hidden or partial information.

Reference:
A Revealing Introduction to Hidden Markov Models, Mark Stamp, 2018
What is the expectation maximization algorithm? Chuong B Do and Serafim Batzoglou, Nature Biotechnology, Vol 26, Num 8, August 2008

# Problem Statement:
- Read through the reference carefully. Implement routines for learning the parameters of HMM given in section 7. In section 8, “A not-so-simple example”, an interesting exercise is carried out. Perform a similar experiment on “War and Peace” by Leo Tolstoy. 
- Ten bent (biased) coins are placed in a box with unknown bias values. A coin is randomly picked from the box and tossed 100 times. A file containing results of five hundred such instances is presented in tabular form with 1 indicating head and 0 indicating tail. Find out the unknown bias values. (2020_ten_bent_coins.csv) To help you, a sample code for two bent coin problem along with data is made available in the work folder: two_bent_coins.csv and embentcoinsol.m
- A point set with real values is given in 2020_em_clustering.csv. Considering that there are two clusters, use EM to group together points belonging to the same cluster. Try and argue that k-means is an EM algorithm.
