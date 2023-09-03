# showansi
Little Qt-console program that shows CP437-ANSI files in your console.

## What is this
I happened to get my hands on a collection of old text files containing ANSI graphics and CP437 characters, used in the 80s-90s for graphics on terminals and BBSes.

To view them on my linux system I typed:

        cat <file>

but the result was something like this:

![Tux, the Linux mascot](/assets/images/tux.png)

I then investigated the problem and realized that it was possible to make a simple converter to transform these files into a format that was interpretable by my console's bash. And so showansi was born.
