# showansi
Little Qt-console program that shows CP437-ANSI files in your console.

## What is this
I happened to get my hands on a collection of old text files containing ANSI graphics and CP437 characters, used in the 80s-90s for graphics on terminals and BBSes.

To view them on my linux system I typed:

        cat <file>

but the result was something like this:

![cat visualization in bash](/assets/cat.png)

I then investigated the problem and realized that it was possible to make a simple converter to transform these files into a format that was interpretable by my console's bash. And so *showansi* was born.

Whith *showansi* you can convert old ANSI-CP437 files to Unicode chars and shows it in your *bash* console.

This is the same file converted by *showansi*:

![showansi visualization in bash](/assets/showansi.png)

Note that if the ANSI-CP437 file is animated, the animations are not lost and the *bash* console is able to display them correctly.

## Dependencies
To compile and run *showansi* you need to have Qt libraries >= version 6 installed.

## Compilation
Please go in program directory and type this in your bash console:

        qmake6
        make

To install *showansi* in the system, type:

        sudo cp showansi /usr/bin


## Simple Test
Please go in program directory and type this in your bash console:

        ./showansi test1.ans

or

        ./showansi test2.ans

Enjoy!

