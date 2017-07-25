/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 * Created by supercoderhawk on 2017/7/24.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int numRows) {
    if (numRows == 1)
        return s;

    char *p = s;
    int length = 0, index = 0;
    while (*p != '\0') {
        length++;
        p++;
    }

    char *zigzag = (char *) malloc(sizeof(char) * (length + 1));
    char **table = (char **) malloc(sizeof(char *) * numRows);
    int tableIndex[numRows];
    for (int i = 0; i < numRows; i++) {
        table[i] = (char *) malloc(sizeof(char) * (length/2+1));
        tableIndex[i] = 0;
    }

    index = 0;
    while (index < length) {
        for (int i = 0; i < numRows && index < length; i++)
            table[i][tableIndex[i]++] = s[index++];
        for (int i = numRows - 2; i > 0 && index < length; i--)
            table[i][tableIndex[i]++] = s[index++];
    }

    index = 0;

    for (int i = 0; i < numRows; i++) {
        strncpy(zigzag + index, table[i], tableIndex[i]);
        index += tableIndex[i];
    }
    zigzag[index] = '\0';
    return zigzag;
}

void testConvert() {
    char *p1 = "nhlvnsnklobqkfoifwsdzfgoueicotgearzqloawcbomgcwnyosztzoqdyutrbxsuzignicqkresvbgwravnzjdek";
    char *p2 = "PAHNAPLSIIGYIR";
    int res = strcmp(convert(p1, 41), p2);
    printf("%d\n", res);

    char *p21 = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
    char *p22 = "Aiosrhem,tseoihartaaeeriwgrlasasnoctaoieplnrmiaodprs,ubroohreunefnttacneedhsmwynihrieto,iheeaalwnefrdutettpntainnwrdvdr.adew,anereqcustbaeeitdcntnlocojmsuuoddis";
    int res2 = strcmp(convert(p21, 3), p22);
    printf("%d\n", res2);
}