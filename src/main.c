#include <stdio.h>

typedef union block_byte_t
{
    unsigned char block_byte;

    struct
    {
        unsigned char nibble_1 : 4;
        unsigned char nibble_2 : 4;
    } block_nibble;
} block_byte_t;

typedef struct block_t
{
    block_byte_t row_12;
    block_byte_t row_34;
} block_t;

// void fprintf_byte (unsigned char byte)
// {
//     fprintf(stdout,
//             "%c%c%c%c%c%c%c%c\n",
//             ((byte) & 0x80 ? '1' : '0'),
//             ((byte) & 0x40 ? '1' : '0'),
//             ((byte) & 0x20 ? '1' : '0'),
//             ((byte) & 0x10 ? '1' : '0'),
//             ((byte) & 0x08 ? '1' : '0'),
//             ((byte) & 0x04 ? '1' : '0'),
//             ((byte) & 0x02 ? '1' : '0'),
//             ((byte) & 0x01 ? '1' : '0'));
// }

// void fprintf_nibble(unsigned char nibble)
// {
//     fprintf(stdout,
//             "%c%c%c%c\n",
//             ((nibble) & 0x08 ? '1' : '0'),
//             ((nibble) & 0x04 ? '1' : '0'),
//             ((nibble) & 0x02 ? '1' : '0'),
//             ((nibble) & 0x01 ? '1' : '0'));
// }

// void fprintf_block (block_t * p_block)
// {
//     // fprintf_byte(p_block->row_12);
//     // fprintf_byte(p_block->row_34);
//     fprintf_nibble(p_block->row_12 >> 4);
//     fprintf_nibble(p_block->row_12 & 0x0F);
//     fprintf_nibble(p_block->row_34 >> 4);
//     fprintf_nibble(p_block->row_34 & 0x0F);
//     return;
// }

void fprintf_block (block_t * p_block)
{
    // p_block has two block_byte_t members
    // each block_byte_t has a block_nibble member
    // each block_nibble has two nibbles

    fprintf(stdout,
            "%c%c%c%c\n",
            ((p_block->row_12.block_byte) & 0x80 ? '1' : '0'),
            ((p_block->row_12.block_byte) & 0x40 ? '1' : '0'),
            ((p_block->row_12.block_byte) & 0x20 ? '1' : '0'),
            ((p_block->row_12.block_byte) & 0x10 ? '1' : '0'));
}

int main (void)
{
    printf("Size of block_byte_t: %lu\n", sizeof(block_byte_t));
    block_t t_block = { (block_byte_t) { 0x4E }, (block_byte_t) { 0x00 } };
    printf("Size of block_t: %lu\n", sizeof(block_t));
    fprintf_block(&t_block);

    return 0;
}