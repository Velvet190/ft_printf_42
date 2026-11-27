#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"

#define TEST(label, format, ...) \
do { \
    int r1; \
    int r2; \
    printf("\n--- %s ---\n", label); \
    r1 = printf(format, ##__VA_ARGS__); \
    printf("\n[printf return] : %d\n", r1); \
    r2 = ft_printf(format, ##__VA_ARGS__); \
    printf("\n[ft_printf return] : %d\n", r2); \
    printf("[comparison] : %s\n", \
        (r1 == r2) ? "OK" : "FAIL"); \
} while (0)

int main(void)
{
    int a;
    int b;
    int c;
    char *str;
    char *empty;
    char character;

    a = 42;
    b = 0;
    c = -42;
    str = NULL;
    empty = "";
    character = 'V';

    printf("\n");
    printf("====================================\n");
    printf("       FT_PRINTF - TEST SUITE\n");
    printf("====================================\n");

    /* ================================= */
    /* CHAR */
    /* ================================= */

    TEST("CHAR SIMPLE", "%c", 'A');
    TEST("CHAR ESPACE", "[%c]", ' ');
    TEST("CHAR ZERO", "%c", '\0');
    TEST("CHAR PLUSIEURS", "%c %c %c", 'A', 'B', 'C');
    TEST("CHAR SPECIAL", "%c", '\n');

    /* ================================= */
    /* STRING */
    /* ================================= */

    TEST("STRING SIMPLE", "%s", "Velvet");
    TEST("STRING VIDE", "%s", empty);
    TEST("STRING NULL", "%s", str);
    TEST("STRING LONGUE", "%s",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");
    TEST("STRING ESPACES", "%s", "Bonjour tout le monde");
    TEST("STRING PLUSIEURS", "%s %s %s",
        "Bonjour", "Velvet", "42");

    /* ================================= */
    /* INT / INTEGER */
    /* ================================= */

    TEST("INT POSITIF", "%d", 42);
    TEST("INT NEGATIF", "%d", -42);
    TEST("INT ZERO", "%d", 0);
    TEST("INT MAX", "%d", INT_MAX);
    TEST("INT MIN", "%d", INT_MIN);
    TEST("INT PLUSIEURS", "%d %d %d", 1, -1, 0);

    TEST("INTEGER POSITIF", "%i", 123);
    TEST("INTEGER NEGATIF", "%i", -123);
    TEST("INTEGER ZERO", "%i", 0);
    TEST("INTEGER MAX", "%i", INT_MAX);
    TEST("INTEGER MIN", "%i", INT_MIN);

    /* ================================= */
    /* UNSIGNED */
    /* ================================= */

    TEST("UNSIGNED ZERO", "%u", 0u);
    TEST("UNSIGNED POSITIF", "%u", 42u);
    TEST("UNSIGNED GRAND", "%u", 2147483648u);
    TEST("UNSIGNED MAX", "%u", UINT_MAX);
    TEST("UNSIGNED PLUSIEURS", "%u %u %u",
        0u, 42u, UINT_MAX);

    /* ================================= */
    /* HEX MINUSCULE */
    /* ================================= */

    TEST("HEX ZERO", "%x", 0u);
    TEST("HEX SIMPLE", "%x", 42u);
    TEST("HEX 255", "%x", 255u);
    TEST("HEX 65535", "%x", 65535u);
    TEST("HEX GRAND", "%x", 2147483648u);
    TEST("HEX MAX", "%x", UINT_MAX);
    TEST("HEX PLUSIEURS", "%x %x %x",
        0u, 255u, UINT_MAX);

    /* ================================= */
    /* HEX MAJUSCULE */
    /* ================================= */

    TEST("HEX UPPER ZERO", "%X", 0u);
    TEST("HEX UPPER SIMPLE", "%X", 42u);
    TEST("HEX UPPER 255", "%X", 255u);
    TEST("HEX UPPER 65535", "%X", 65535u);
    TEST("HEX UPPER GRAND", "%X", 2147483648u);
    TEST("HEX UPPER MAX", "%X", UINT_MAX);

    /* ================================= */
    /* POINTER */
    /* ================================= */

    TEST("POINTER INT", "%p", (void *)&a);
    TEST("POINTER ZERO", "%p", (void *)&b);
    TEST("POINTER NEGATIF", "%p", (void *)&c);
    TEST("POINTER STRING", "%p", (void *)"Velvet");
    TEST("POINTER NULL", "%p", (void *)NULL);
    TEST("POINTER PLUSIEURS", "%p %p",
        (void *)&a, (void *)&b);

    /* ================================= */
    /* POURCENTAGE */
    /* ================================= */

    TEST("POURCENTAGE SIMPLE", "%%");
    TEST("POURCENTAGE PLUSIEURS", "%% %% %%");
    TEST("POURCENTAGE TEXTE", "100%%");
    TEST("POURCENTAGE MELANGE", "Bonjour %% Velvet");

    /* ================================= */
    /* MIX */
    /* ================================= */

    TEST("MIX SIMPLE", "%s %d %c",
        "Velvet", 18, 'V');

    TEST("MIX COMPLET", "%s %d %i %u %x %X %c %%",
        "Test", -42, 123, 100u, 255u, 255u, 'A');

    TEST("MIX LIMITES", "%d %i %u %x %X",
        INT_MIN, INT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);

    TEST("MIX POINTER", "%s %p %d",
        "Adresse", (void *)&a, 42);

    TEST("MIX NULL", "%s %p %d",
        str, (void *)NULL, 0);

    TEST("MIX LONG", "Nom: %s | Age: %d | Adresse: %p | Hex: %X",
        "Velvet", 18, (void *)&a, 255u);

    /* ================================= */
    /* FORMAT SANS CONVERSION */
    /* ================================= */

    TEST("TEXTE SIMPLE", "Bonjour");
    TEST("TEXTE VIDE", "");
    TEST("TEXTE LONG", "Ceci est une longue chaine sans conversion.");
    TEST("TEXTE AVEC ESPACES", "Bonjour tout le monde !");

    /* ================================= */
    /* FIN */
    /* ================================= */

    printf("\n");
    printf("====================================\n");
    printf("          FIN DES TESTS\n");
    printf("====================================\n");

    return (0);
}
