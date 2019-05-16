#include "pch.h"
#include <iostream>
#include <ctime>


void print_koloda(int * mass) {
    for (size_t i = 0; i < 36; i++) {
        std::cout << mass[i] << "\t";
    }
    std::cout << std::endl;
}

void peremeshivanie(int * mass) {
    for (size_t i = 0; i < 100; i++) {
        std::swap(mass[rand()%36], mass[rand() % 36]);
    }
}

void rasklad(int * mass, int * mass_gamer1, int * mass_gamer2) {
    int j = 0;
    for (size_t i = 0; i < 36; i++, j++) {
        std::swap(mass_gamer1[j], mass[i]);
        i++;
        std::swap(mass_gamer2[j], mass[i]);
    }
}

void sdvig(int * mass) {
    int i = 0;
    while (mass[i + 1] != 0) {
        std::swap(mass[i], mass[i + 1]);
        i++;
    }
}

void perenos_na_pole(int * mass, int * mass_gamer1, int * mass_gamer2, int iterator) {
        std::swap(mass_gamer1[0], mass[iterator]);
        std::swap(mass_gamer2[0], mass[iterator+1]);
}

void perenos_v_kolodu_gamer(int * mass, int * mass_gamer) {
    int i = 0;
    while (mass_gamer[i] != 0) {
        i++;
    }
    int j = 0;
    while (mass[j] != 0) {
        std::swap(mass[j], mass_gamer[i]);
        i++;
        j++;
    }
}

bool flag_pobeda(int gamer1, int gamer2) {
    if (gamer1 == 0 || gamer2 == 0) {
        return true;
    }
    return false;
}

int pobeda(int gamer1, int gamer2) {
    if (gamer1 > gamer2) {
        return 1;
    }
    if (gamer1 < gamer2) {
        return 2;
    }
    return -1;
}

void run_game(int * mass, int * mass_gamer1, int * mass_gamer2) {
    int iterator = 0;
    int karta_gamer1;
    int karta_gamer2;

    while (!flag_pobeda(mass_gamer1[0], mass_gamer2[0])) {
        karta_gamer1 = mass_gamer1[0];
        karta_gamer2 = mass_gamer2[0];
        perenos_na_pole(mass, mass_gamer1, mass_gamer2, iterator);
        sdvig(mass_gamer1);
        sdvig(mass_gamer2);
        if (karta_gamer1 > karta_gamer2 && !(karta_gamer2 == 1 && karta_gamer1 == 9) || (karta_gamer1 == 1 && karta_gamer2 == 9)) {
            iterator = 0;

            perenos_v_kolodu_gamer(mass, mass_gamer1);
        } else if (karta_gamer1 < karta_gamer2 && !(karta_gamer1 == 1 && karta_gamer2 == 9) || (karta_gamer2 == 1 && karta_gamer1 == 9)) {
            iterator = 0;
            perenos_v_kolodu_gamer(mass, mass_gamer2);
        } else {
            if (!flag_pobeda(mass_gamer1[0], mass_gamer2[0])) {
            iterator += 2;
            perenos_na_pole(mass, mass_gamer1, mass_gamer2, iterator);
            sdvig(mass_gamer1);
            sdvig(mass_gamer2);
            iterator += 2;
            }
        }
    }
    if (pobeda(mass_gamer1[0], mass_gamer2[0]) == -1) {
        std::cout <<  " no win !!! " << std::endl;
        return;
    }
    std::cout << pobeda(mass_gamer1[0], mass_gamer2[0]) << "gamer win !!! " << std::endl;
}

int main() {
    srand(time(0));
    int koloda[36] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9};
    int koloda_gamer1[36] = {};
    int koloda_gamer2[36] = {};

    peremeshivanie(koloda);
    rasklad(koloda, koloda_gamer1, koloda_gamer2);

    print_koloda(koloda);
    print_koloda(koloda_gamer1);
    print_koloda(koloda_gamer2);

    run_game(koloda, koloda_gamer1, koloda_gamer2);

    print_koloda(koloda);
    print_koloda(koloda_gamer1);
    print_koloda(koloda_gamer2);

}
