## Why this exists?

- First assignment from `Programming-2` class of 2023-2 (UENF)

## What did it ask/What did I have to do?

- Given an input matrix of random numbers, reduce the amount of unique numbers inside it to an amount `X` chosen by the user. Use the K-Means Clustering algorithm to do so.
- Perform comparisons between the result and the the original matrix and make corrections to numbers based on how off they were from their original counterparts.
- Finish when differences between remaining unique numbers and their original numbers is less then 1. Output to stdout every matrix from this step.

## What did I do/learn?

- Started to learn C/C++ build systems
- Took a first look onto CMake for building libraries
- Learned the basics of OpenCV for image manipulation
- Learned K-Means clustering as a method of reducing tones of an image
- Made [OpenCV-ToneRemover](https://github.com/MintzyG/ToneRemover-OpenCV)
- Messed around with the Filesystem in C++
- Helped 10 people from class finish their assignments in time :)

## What do I think of this after?

The professor should not have given this as a first assignment for a class where only two people programmed in C before.
Even worse was the delivery time, two weeks. Bruno and I helped lots of people finish in time however some couldn't do it still.

Encountering all the crazy bugs with image processing and actually looking at their weird results was cool and inspiring, got me to add glitch art to my todo list, specifically Pixel Sorting.

This was the first time I encountered passing an unitialized array/struct in to a function, used a little hack to fix it here. Actual fix I learned while doing Quick-Sort
