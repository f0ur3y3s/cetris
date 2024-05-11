# Cetris

Cetris is a clone of Tetris written in C.

- [Cetris](#cetris)
  - [Building](#building)
  - [Cleaning](#cleaning)
  - [Testing](#testing)
  - [Technical details](#technical-details)
    - [Example](#example)
      - [T-block](#t-block)


## Building

```bash
make
```

## Cleaning

```bash
make clean
```

## Testing

```bash
make test
```

## Technical details

Inspiration taken from [emard's tetris](https://github.com/emard/tetris4terminals/blob/master/tetris.c) implementation for the PIC16.
Each block is represented by a bit array of 8 bits. Each block contains 2 bit arrays totaling 4 nibbles to represent the block.

### Example

Empty block
```
0b 0000 0000
0b 0000 0000

. . . .
. . . .
. . . .
. . . .

```

#### T-block
```
0b 0100 1110
0b 0000 0000

. []. .
[][][].
. . . .
. . . .
```

```
0b 0100 0110
0b 0100 0000

. []. .
. [][].
. []. .
. . . .
```

```
0b 0000 1110
0b 0100 0000

. . . .
[][][].
. []. .
. . . .
```

```
0b 0100 1100
0b 0100 0000

. []. .
[][]. .
. []. .
. . . .
```
