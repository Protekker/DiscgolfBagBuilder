#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//maybe make such that pros get more flippy and noobs more overstable or just make the noob bag more flippy
// Currently stability mostly for amateuer around 900 rating

struct Disc {
    char brand[20];
    char name[20];
    float speed;
    float glide;
    float turn;
    float fade;
    char classification[20];
    char slot[20];
};

struct Bag {
    struct Disc discs[26];
    int count;
};
/*Optimal bag

*/
// struct Slot {
//     // int puttPutter[10];
//     int throwPutter[10];
//     int approach[10];
//     int midrange[10];
//     int fairway[10];
//     int control[10];
//     int distance[10];
//     int utility[10];
// };
//turn+fade = tf
// struct FlightCharacteristic{
//     int flippy[100]; //tf<-2
//     int understable[100]; //-2<tf<-1
//     int straight[100]; //-1<tf<1
//     int overstable[100]; //1<tf<3
//     int beefy[100]; //3<tf
// };

struct Disc createDisc(char *brand, char *name, float speed, float glide, float turn, float fade) {
    struct Disc disc;
    strcpy(disc.brand, brand);
    strcpy(disc.name, name);
    disc.speed = speed;
    disc.glide = glide;
    disc.turn  = turn;
    disc.fade  = fade;
    // disc.classification = classification;
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
    printf("%.1f ", disc.fade);
    printf("%s ",disc.classification);
    printf("%s \n",disc.slot);

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

void classifyDiscs(struct Bag *bag){
    for(int i=0;i<bag->count;i++){
        int turnfade = bag->discs[i].turn+bag->discs[i].fade;
        float speed = bag->discs[i].speed;
        if (turnfade <= -3)
        {
            strcpy(bag->discs[i].classification,"Flippy");
        }
        else if (-3 < turnfade && turnfade <= -1)
        {
            strcpy(bag->discs[i].classification,"Understable");
        }
        else if (-1 < turnfade && turnfade <= 1)
        {
            strcpy(bag->discs[i].classification,"Straight");
        }
        else if (1 < turnfade && turnfade <= 3)
        {
            strcpy(bag->discs[i].classification,"Overstable");
        }
        else
        // else (3 < bag->discs[i].turn+bag->discs[i].fade)
        {
            strcpy(bag->discs[i].classification,"Beefy");
        }
        if (speed <= 3)
        {
            strcpy(bag->discs[i].slot,"Putter");
        }
        else if (3 < speed && speed < 5)
        {
            strcpy(bag->discs[i].slot,"Approach");
        }
        else if (5 <= speed && speed <= 6)
        {
            strcpy(bag->discs[i].slot,"Midrange");
        }
        else if (6 < speed && speed < 9.5)
        {
            strcpy(bag->discs[i].slot,"Fairway");
        }
        else if (9.5 <= speed && speed < 12)
        {
            strcpy(bag->discs[i].slot,"Control");
        }
        else if (12 <= speed)
        {
            strcpy(bag->discs[i].slot,"Distance");
        }
            
    }


}

struct Bag optimalBag(struct Bag *bag){
    struct Bag newbag = {0};
    // bool flippyPutter = false;
    // bool straightPutter = false;
    int puttersMax = 3;
    int approachMax = 3;
    int midrangeMax = 3;
    int fairwayMax = 3;
    int controlMax = 3;
    int distanceMax = 3;
    int maxDiscs = 18;
    
    for (int i = 0; i<bag->count;i++){

    if(strcmp(bag->discs[0].classification,"Understable") == 0 && strcmp(bag->discs[0].slot,"Putter") == 0){
        newbag.discs[0] = bag->discs[0];
        newbag.count +=1;
    }
    
    }
    return newbag;
}


int main() {
    struct Disc disc1 = createDisc("Kastaplast", "Berg", 1, 1, 0, 2);
    struct Disc disc2 = createDisc("Kastaplast","Berg X",1,1,1,2);
    struct Disc disc3 = createDisc("Kastaplast","Berg X",1,1,1,2);
    struct Disc disc4 = createDisc("Axiom","Proxy x",3,3,-1,0.5);
    struct Disc disc5 = createDisc("Kastaplast","Reko X",3,3,0,2);
    struct Disc disc6 = createDisc("Discraft","Zone SS",4,4,-1,2);
    struct Disc disc7 = createDisc("Axiom","Tempo",4,4,0,2.5);
    struct Disc disc8 = createDisc("Discraft","Zone",4,3,0,3);
    struct Disc disc9 = createDisc("Prodigy","A2",4,2,0,4);
    struct Disc disc10 = createDisc("Axiom","Pyro",5,4,0,2.5);
    struct Disc disc11 = createDisc("Latitude 64", "Rive", 13, 5, 0, 3.5);
    struct Disc disc12 = createDisc("Discmania","PD",10,4,0,3);
    struct Disc disc13 = createDisc("Latitude 64","Pioneer",9,4,0,3);
    struct Disc disc14 = createDisc("Axiom","Hex",5,5,-1,1);
    struct Disc disc15 = createDisc("MVP","Servo",6.5,5,-1,2);
    struct Disc disc16 = createDisc("MVP","Reactor",5,5,-0.5,1.5);
    struct Disc disc17 = createDisc("MVP","Trail",10,5,-1,1);
    struct Disc disc18 = createDisc("Discmania","DD3",12,5,-1,3);
    struct Disc disc19 = createDisc("Streamline","Boost",9.5,4,0,2.5);
    struct Disc disc20 = createDisc("Dynamic Discs","Felon",9,3,0.5,4);
    struct Disc disc21 = createDisc("Discmania", "PD2", 12, 4, 0, 4);
    struct Disc disc22 = createDisc("Kastaplast","Guld",13,5,-0.5,3);
    struct Disc disc23 = createDisc("MVP","Zenith",11,5,-0.5,2);
    struct Disc disc24 = createDisc("MVP","Resistor",6,4,0,3.5);
    struct Disc disc25 = createDisc("MVP","Tesla",9,5,-1,2);
    struct Bag gripax6 = {0};
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
    addDisc(disc11, &gripax6);
    addDisc(disc12,&gripax6);
    addDisc(disc13,&gripax6);
    addDisc(disc14,&gripax6);
    addDisc(disc15,&gripax6);
    addDisc(disc16, &gripax6);
    addDisc(disc17,&gripax6);
    addDisc(disc18,&gripax6);
    addDisc(disc19,&gripax6);
    addDisc(disc20,&gripax6);
    addDisc(disc21, &gripax6);
    addDisc(disc22,&gripax6);
    addDisc(disc23,&gripax6);
    addDisc(disc24,&gripax6);
    addDisc(disc25,&gripax6);
    printf("%d\n",gripax6.count);
    sortBagBySpeedAndStability(&gripax6);
    // printBag(&gripax6);
    classifyDiscs(&gripax6);
    strcpy(gripax6.discs[16].classification,"Understable");
    printBag(&gripax6);
    // struct Bag Frid = optimalBag(&gripax6);
    // printBag(&Frid);
    
}