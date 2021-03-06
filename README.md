# Algorithms

## Sorting Algorithms

# Data Structures

## Hash Tables

* [Linear Probing](https://github.com/Xandynhu/Algorithms/tree/main/Data%20Structures/Linear%20Probing)

* [Separate Chaining](https://github.com/Xandynhu/Algorithms/tree/main/Data%20Structures/Separate%20Chaining)

## Lists

## Trees

* [BST - Binary Search Tree]()

# Projects

## Movies Data Center
Program:
* [Movies Data Center](https://github.com/Xandynhu/Algorithms/tree/main/Projects/Movies%20Data%20Center/src)

Description:

Program that reads some .csv files and build a data center about them.
The data are divided into three files which each one contain:

* movie.csv  -> movieID,"title","genre1|genre2|...|genreN"
* tag.csv    -> userID,movieID,"tag",timestamp
* rating.csv -> userID,movieID,rating,timestamp

After read the files and build the data center, enter into console mode.
In console mode does four searches by specific commands:

* movie < prefix >
    * Returns all movies with these prefix showing:
    * movieID, title, genres, rating, count

* user < userID >
    * Returns all the movies analysed by this user showing:
    * user_rating, title, global_rating, count

* top < N > < genre >
    * Returns all the N best rated movies with at least 1000 ratings, showing:
    * title, genres, rating, count

* tag < "tag1" "tag2" ... "tagN" >
    * Return all movies related to these tags, showing:
    * title, genre, rating, count


## Cubes Reduction in Karnaugh's Map
Program:
* [Cubes Reduction](https://github.com/Xandynhu/Algorithms/tree/main/Projects/Cubes%20Reduction%20Karnaugh's%20Map)

Description:

Receiving a vector of integers representing the "true" lines of the truth table, returns a vector of integers representing the minimals cubes possible.