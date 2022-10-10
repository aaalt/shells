# Shells

In classic IRL shell game, three identical cups are placed face-down on a surface.
A small ball is placed beneath one of these cups so that it cannot be seen, 
and they are then shuffled by the operator. 
A player is invited to bet on which cup holds the ball. 

In practice, IRL game comes down to the player's confidence that he/she will notice 
cheating, which lies in operator's sleight of hand -- moving or hiding 
the ball between cups during play.

I propose to implement this ancient game in the form of a ternary toss.

The game should consist of three rounds. 
In each round player chooses one cup and wins the round with probability 1/3.

After three rounds there are four outcomes:
```
1. No wins                      | probability is 8/27
2. One win in three rounds      | probability is 12/27
3. Two wins in three rounds     | probability is 6/27
4. Three wins in three eounds   | probability is 1/27
```


# Calculations

To start calculations clone repo and run `make`


# Formulae

`HE = X * 1/27 + Y * 6/27 + Z * 12/27`
transmutes into
`27*HE = X + Y*6 + Z*12`

Where `X` is coefficient for case N4, three wins in three rounds,
`Y` is coefficient for case N3, two wins, and `Z` -- for case N2.

for ex.
```
27*HE = 25.65 + (0    * 6) + (0    * 12) =
      = 16    + (1.1  * 6) + (0.25 * 12) =
      = 3     + (1.77 * 6) + (1    * 12)
```

We can replace case N2, one win in three rounds, with `K` extra free games.
In this case formula is:
```
HE = X * 1/27 + Y * 6/27 + K * 12/27 * HE = 
   = X * 1/27 + Y * 6/27 + K * 12/27 * 
                  * (X * 1/27 + Y * 6/27 + K * 12/27 * HE) ->

27*HE = X + Y*6 + K*12*HE -> 
HE*(27 - K*12) = X + Y*6  ->
27 - K*12 > 0 because HE > 0
so K = 1 or K = 2

K = 1:
HE*15 = X + Y*6
for ex.
    HE*15 = 7.65 + 1.1*6 =
          = 5.25 + 1.5*6
          = 2.25 + 2  *6 

K = 2:
HE*3  = X + Y*6
for ex.
    HE*3  = 1 + 0.3*6 [bad case]
```

