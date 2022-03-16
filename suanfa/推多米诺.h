#pragma once
#include "dependencies.h"
string pushDominoes(string dominoes) {
    int length = dominoes.length();
    for (int i = -1; i < length;) {
        if (dominoes[i + 1] == '.') {
            int j = i + 1;
            if (i >= 0 && dominoes[i] == 'R') {
                while (++j < length && dominoes[j] == '.');
                if (j < length) {
                    int l = i, r = j;
                    if (dominoes[j] == 'R') {
                        while (++l < j) {
                            dominoes[l] = 'R';
                        }
                    }
                    else if (dominoes[j] == 'L') {
                        while (++l < --r) {
                            dominoes[l] = 'R';
                            dominoes[r] = 'L';
                        }
                    }
                }
                else {
                    while (++i < length) {
                        dominoes[i] = 'R';
                    }
                }
                i = j;
            }
            else if (i >= 0 && dominoes[i] == 'L' || i < 0) {
                while (++j < length && dominoes[j] == '.');
                if (j < length) {
                    if (dominoes[j] == 'L') {
                        int l = i, r = j;
                        while (++l < j) {
                            dominoes[l] = 'L';
                        }
                    }
                }
                i = j;
            }
        }
        else {
            i++;
        }
    }
    return dominoes;
}
void test() {
    string dominoes = ".L.R...LR..L..";
    cout << pushDominoes(dominoes) << endl;
}