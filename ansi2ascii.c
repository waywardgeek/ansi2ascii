// This program simply converts ANSI to ASCII, making sensical conversions
// suitable for casual reading.

#include <stdio.h>
#include <stdbool.h>

static int prevWasSpace = false;
static int needSpace = false;

// Print the string, making sure to surround it with spaces.
static inline void printWord(char *string)
{
    if(!prevWasSpace) {
        putchar(' ');
    }
    printf("%s", string);
    prevWasSpace = false;
    needSpace = true;
}

// Replace the character with an ASCII equivalent, which can be an equivalent
// character, a word, or nothing.
static inline void printEquivalent(int c)
{
    switch(c) {
    case 0x7f: break;
    case 0x80: printWord("euro"); break;
    case 0x81: break;
    case 0x82: putchar('\''); break;
    case 0x83: putchar('f'); break;
    case 0x84: putchar('"'); break;
    case 0x85: printWord("..."); break;
    case 0x86: break;
    case 0x87: break;
    case 0x88: putchar('^'); break;
    case 0x89: putchar('%'); break;
    case 0x8A: putchar('S'); break;
    case 0x8B: putchar('<'); break;
    case 0x8C: putchar('E'); break;
    case 0x8D: break;
    case 0x8E: putchar('Z'); break;
    case 0x8F: break;
    case 0x90: break;
    case 0x91: putchar('\''); break;
    case 0x92: putchar('\''); break;
    case 0x93: putchar('"'); break;
    case 0x94: putchar('"'); break;
    case 0x95: putchar('*'); break;
    case 0x96: putchar('-'); break;
    case 0x97: putchar('-'); break;
    case 0x98: putchar('~'); break;
    case 0x99: printWord("TM"); break;
    case 0x9A: putchar('S'); break;
    case 0x9B: putchar('>'); break;
    case 0x9C: putchar('e'); break;
    case 0x9D: break;
    case 0x9E: putchar('z'); break;
    case 0x9F: putchar('Y'); break;
    case 0xA0: putchar(' '); break;
    case 0xA1: break;
    case 0xA2: printWord("cents"); break;
    case 0xA3: printWord("pounds"); break;
    case 0xA4: printWord("currency"); break;
    case 0xA5: printWord("yen"); break;
    case 0xA6: putchar('|'); break;
    case 0xA7: break;
    case 0xA8: break;
    case 0xA9: printWord("copyright"); break;
    case 0xAA: putchar('a'); break;
    case 0xAB: printWord("<<"); break;
    case 0xAC: printWord("not"); break;
    case 0xAD: putchar('-'); break;
    case 0xAE: printWord("restricted"); break;
    case 0xAF: break;
    case 0xB0: printWord("degrees"); break;
    case 0xB1: printWord("plus/minus"); break;
    case 0xB2: putchar('2'); break;
    case 0xB3: putchar('3'); break;
    case 0xB4: putchar('\''); break;
    case 0xB5: putchar('u'); break;
    case 0xB6: break;
    case 0xB7: putchar('*'); break;
    case 0xB8: putchar(','); break;
    case 0xB9: putchar('1'); break;
    case 0xBA: putchar('0'); break;
    case 0xBB: printWord(">>"); break;
    case 0xBC: printWord("1/4"); break;
    case 0xBD: printWord("1/3"); break;
    case 0xBE: printWord("3/4"); break;
    case 0xBF: break;
    case 0xC0: putchar('A'); break;
    case 0xC1: putchar('A'); break;
    case 0xC2: putchar('A'); break;
    case 0xC3: putchar('A'); break;
    case 0xC4: putchar('A'); break;
    case 0xC5: putchar('A'); break;
    case 0xC6: printWord("AE"); break;
    case 0xC7: putchar('C'); break;
    case 0xC8: putchar('E'); break;
    case 0xC9: putchar('E'); break;
    case 0xCA: putchar('E'); break;
    case 0xCB: putchar('E'); break;
    case 0xCC: putchar('I'); break;
    case 0xCD: putchar('I'); break;
    case 0xCE: putchar('I'); break;
    case 0xCF: putchar('I'); break;
    case 0xD0: putchar('D'); break;
    case 0xD1: putchar('N'); break;
    case 0xD2: putchar('O'); break;
    case 0xD3: putchar('O'); break;
    case 0xD4: putchar('O'); break;
    case 0xD5: putchar('O'); break;
    case 0xD6: putchar('O'); break;
    case 0xD7: putchar('*'); break;
    case 0xD8: putchar('0'); break;
    case 0xD9: putchar('U'); break;
    case 0xDA: putchar('U'); break;
    case 0xDB: putchar('U'); break;
    case 0xDC: putchar('U'); break;
    case 0xDD: putchar('Y'); break;
    case 0xDE: putchar('Y'); break;
    case 0xDF: putchar('s'); break;
    case 0xE0: putchar('a'); break;
    case 0xE1: putchar('a'); break;
    case 0xE2: putchar('a'); break;
    case 0xE3: putchar('a'); break;
    case 0xE4: putchar('a'); break;
    case 0xE5: putchar('a'); break;
    case 0xE6: printWord("ae"); break;
    case 0xE7: putchar('c'); break;
    case 0xE8: putchar('e'); break;
    case 0xE9: putchar('e'); break;
    case 0xEA: putchar('e'); break;
    case 0xEB: putchar('e'); break;
    case 0xEC: putchar('i'); break;
    case 0xED: putchar('i'); break;
    case 0xEE: putchar('i'); break;
    case 0xEF: putchar('i'); break;
    case 0xF0: putchar('o'); break;
    case 0xF1: putchar('n'); break;
    case 0xF2: putchar('o'); break;
    case 0xF3: putchar('o'); break;
    case 0xF4: putchar('o'); break;
    case 0xF5: putchar('o'); break;
    case 0xF6: putchar('o'); break;
    case 0xF7: putchar('/'); break;
    case 0xF8: putchar('0'); break;
    case 0xF9: putchar('u'); break;
    case 0xFA: putchar('u'); break;
    case 0xFB: putchar('u'); break;
    case 0xFC: putchar('u'); break;
    case 0xFD: putchar('y'); break;
    case 0xFE: putchar('y'); break;
    case 0xFF: putchar('y'); break;
    default:
        printf("Unexpected character %c\n", c);
    }
}

int main(int argc, char **argv)
{
    FILE *file;
    int c;

    if(argc != 2) {
        printf("Usage: ansi2ascii file\n");
        return 1;
    }
    file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Unable to open file %s for reading.\n", argv[0]);
        return 1;
    }
    c = getc(file);
    while(c != EOF) {
        // Print a space if we need one to separate from a word we printed
        if(c > ' ' && needSpace) {
            putchar(' ');
        }
        needSpace = false;
        if(c < 0x7f) {
            putc(c, file);
        } else {
            printEquivalent(c);
        }
        c = getc(file);
    }
    return 0;
}
