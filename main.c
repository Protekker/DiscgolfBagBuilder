#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Disc {
    char brand[20];
    char name[20];
    float speed;
    float glide;
    float turn;
    float fade;
};

struct Bag {
    struct Disc discs[26];
    int count;
};

struct Slot {
    int puttPutter[10];
    int throwPutter[10];
    int approach[10];
    int midrange[10];
    int fairway[10];
    int control[10];
    int distance[10];
    int utility[10];
};

struct Disc createDisc(char *brand, char *name, float speed, float glide, float turn, float fade) {
    struct Disc disc;
    strcpy(disc.brand, brand);
    strcpy(disc.name, name);
    disc.speed = speed;
    disc.glide = glide;
    disc.turn  = turn;
    disc.fade  = fade;
    return disc;
}

void addDisc(struct Disc disc, struct Bag *bag) {
    // if (bag->count > 26){
    //     printf("BAG FULL! Remove disc before adding any more.\n");        
    // TODO
    // }
    bag->discs[bag->count] = disc;
    printf("%s ", bag->discs[bag->count].brand);
    printf("%s ", bag->discs[bag->count].name);
    printf("%.1f ", bag->discs[bag->count].speed);
    printf("%.1f ", bag->discs[bag->count].glide);
    printf("%.1f ", bag->discs[bag->count].turn);
    printf("%.1f\n", bag->discs[bag->count].fade);

    bag->count += 1;
}

void printDisc(struct Disc disc){
    printf("%s ", disc.brand);
    printf("%s ", disc.name);
    printf("%.1f ", disc.speed);
    printf("%.1f ", disc.glide);
    printf("%.1f ", disc.turn);
    printf("%.1f\n", disc.fade);
}

void sortBagBySpeedAndStability(struct Bag *bag) {
    for (int i = 0; i < bag->count - 1; i++) {
        for (int j = 0; j < bag->count - i - 1; j++) {
            if (bag->discs[j].speed > bag->discs[j + 1].speed) {
                struct Disc temp = bag->discs[j];
                bag->discs[j] = bag->discs[j + 1];
                bag->discs[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < bag->count - 1; i++) {
        for (int j = 0; j < bag->count - i - 1; j++) {
            if (bag->discs[j].speed == bag->discs[j + 1].speed && bag->discs[j].turn+bag->discs[j].fade > bag->discs[j+1].turn+bag->discs[j+1].fade ){
                struct Disc temp = bag->discs[j];
                bag->discs[j] = bag->discs[j + 1];
                bag->discs[j + 1] = temp;
            }
        }
    }
}

void printBag(struct Bag *bag){
    for(int i=0; i<bag->count;i++){
        printDisc(bag->discs[i]);
    }
}



int main() {
    struct Disc disc1 = createDisc("MVP", "Reactor", 5, 5, -0.5, 1.5);
    struct Disc disc2 = createDisc("MVP","Resistor",6,4,0,3.5);
    struct Disc disc3 = createDisc("Kastaplast","Berg x",1,1,1,2);
    struct Disc disc4 = createDisc("Kastaplast","Reko x",3,3,0,2);
    struct Disc disc5 = createDisc("Kastaplast","Reko",3,3,0,1);
    struct Disc disc6 = createDisc("Kastaplast","Impa",11,6,-4,1);
    struct Disc disc7 = createDisc("Innova","Eagle-L",7,4,-1,3);
    struct Disc disc8 = createDisc("Latitude 64","Pure",3,3,-1,1);
    struct Disc disc9 = createDisc("Kastaplast","Tuff",3,4,0,2);
    struct Disc disc10 = createDisc("MVP","Watt",2,5,-0.5,0.5);
    struct Bag gripax6;
    gripax6.count = 0;
    addDisc(disc1, &gripax6);
    addDisc(disc2,&gripax6);
    addDisc(disc3,&gripax6);
    addDisc(disc4,&gripax6);
    addDisc(disc5,&gripax6);
    addDisc(disc6, &gripax6);
    addDisc(disc7,&gripax6);
    addDisc(disc8,&gripax6);
    addDisc(disc9,&gripax6);
    addDisc(disc10,&gripax6);
    printf("%d\n",gripax6.count);
    sortBagBySpeedAndStability(&gripax6);
    printBag(&gripax6);
}