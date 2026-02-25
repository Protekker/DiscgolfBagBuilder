#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//maybe make such that pros get more flippy and noobs more overstable or just make the noob bag more flippy
// Currently stability mostly for amateuer around 900 rating

struct Disc {
    char brand[20];
    char name[20];
    char classification[20];
    char slot[20];
    int id;
    float speed;
    float glide;
    float turn;
    float fade;
};

struct Stack {
    int putterCount;
    struct Disc flippyPutter[20];
    int flippyPutterCount;
    struct Disc understablePutter[20];
    int understablePutterCount;
    struct Disc straightPutter[20];
    int straightPutterCount;
    struct Disc overstablePutter[20];
    int overstablePutterCount;
    struct Disc beefyPutter[20];
    int beefyPutterCount;

    int approachCount;
    struct Disc flippyApproach[20];
    int flippyApproachCount;
    struct Disc understableApproach[20];
    int understableApproachCount;
    struct Disc straightApproach[20];
    int straightApproachCount;
    struct Disc overstableApproach[20];
    int overstableApproachCount;
    struct Disc beefyApproach[20];
    int beefyApproachCount;

    int midrangeCount;
    struct Disc flippyMidrange[20];
    int flippyMidrangeCount;
    struct Disc understableMidrange[20];
    int understableMidrangeCount;
    struct Disc straightMidrange[20];
    int straightMidrangeCount;
    struct Disc overstableMidrange[20];
    int overstableMidrangeCount;
    struct Disc beefyMidrange[20];
    int beefyMidrangeCount;

    int fairwayCount;
    struct Disc flippyFairway[20];
    int flippyFairwayCount;
    struct Disc understableFairway[20];
    int understableFairwayCount;
    struct Disc straightFairway[20];
    int straightFairwayCount;
    struct Disc overstableFairway[20];
    int overstableFairwayCount;
    struct Disc beefyFairway[20];
    int beefyFairwayCount;

    int controlCount;
    struct Disc flippyControl[20];
    int flippyControlCount;
    struct Disc understableControl[20];
    int understableControlCount;
    struct Disc straightControl[20];
    int straightControlCount;
    struct Disc overstableControl[20];
    int overstableControlCount;
    struct Disc beefyControl[20];
    int beefyControlCount;

    int distanceCount;
    struct Disc flippyDistance[20];
    int flippyDistanceCount;
    struct Disc understableDistance[20];
    int understableDistanceCount;
    struct Disc straightDistance[20];
    int straightDistanceCount;
    struct Disc overstableDistance[20];
    int overstableDistanceCount;
    struct Disc beefyDistance[20];
    int beefyDistanceCount;

    int stackCount;
};

struct Bag {
    struct Disc discs[26];
    int count;
};

int totalDiscsCreated = 0;

struct Disc createDisc(char *brand, char *name, float speed, float glide, float turn, float fade) {
    struct Disc disc;
    strcpy(disc.brand, brand);
    strcpy(disc.name, name);
    disc.speed = speed;
    disc.glide = glide;
    disc.turn  = turn;
    disc.fade  = fade;
    disc.id = totalDiscsCreated++;
    // disc.classification = classification;
    return disc;
}

void addDisc(struct Disc disc, struct Bag *bag) {
    // if (bag->count > 26){
    //     printf("BAG FULL! Remove disc before adding any more.\n");        
    // TODO
    // }
    bag->discs[bag->count] = disc;
    // printf("%s ", bag->discs[bag->count].brand);
    // printf("%s ", bag->discs[bag->count].name);
    // printf("%.1f ", bag->discs[bag->count].speed);
    // printf("%.1f ", bag->discs[bag->count].glide);
    // printf("%.1f ", bag->discs[bag->count].turn);
    // printf("%.1f\n", bag->discs[bag->count].fade);

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

void printStack(struct Stack *stack){
    printf("=== PUTTERS ===\n");
    printf("  Flippy (%d):\n",      stack->flippyPutterCount);
    for(int i = 0; i < stack->flippyPutterCount; i++)       printDisc(stack->flippyPutter[i]);
    printf("  Understable (%d):\n", stack->understablePutterCount);
    for(int i = 0; i < stack->understablePutterCount; i++)  printDisc(stack->understablePutter[i]);
    printf("  Straight (%d):\n",    stack->straightPutterCount);
    for(int i = 0; i < stack->straightPutterCount; i++)     printDisc(stack->straightPutter[i]);
    printf("  Overstable (%d):\n",  stack->overstablePutterCount);
    for(int i = 0; i < stack->overstablePutterCount; i++)   printDisc(stack->overstablePutter[i]);
    printf("  Beefy (%d):\n",       stack->beefyPutterCount);
    for(int i = 0; i < stack->beefyPutterCount; i++)        printDisc(stack->beefyPutter[i]);

    printf("=== APPROACH ===\n");
    printf("  Flippy (%d):\n",      stack->flippyApproachCount);
    for(int i = 0; i < stack->flippyApproachCount; i++)     printDisc(stack->flippyApproach[i]);
    printf("  Understable (%d):\n", stack->understableApproachCount);
    for(int i = 0; i < stack->understableApproachCount; i++) printDisc(stack->understableApproach[i]);
    printf("  Straight (%d):\n",    stack->straightApproachCount);
    for(int i = 0; i < stack->straightApproachCount; i++)   printDisc(stack->straightApproach[i]);
    printf("  Overstable (%d):\n",  stack->overstableApproachCount);
    for(int i = 0; i < stack->overstableApproachCount; i++) printDisc(stack->overstableApproach[i]);
    printf("  Beefy (%d):\n",       stack->beefyApproachCount);
    for(int i = 0; i < stack->beefyApproachCount; i++)      printDisc(stack->beefyApproach[i]);

    printf("=== MIDRANGE ===\n");
    printf("  Flippy (%d):\n",      stack->flippyMidrangeCount);
    for(int i = 0; i < stack->flippyMidrangeCount; i++)     printDisc(stack->flippyMidrange[i]);
    printf("  Understable (%d):\n", stack->understableMidrangeCount);
    for(int i = 0; i < stack->understableMidrangeCount; i++) printDisc(stack->understableMidrange[i]);
    printf("  Straight (%d):\n",    stack->straightMidrangeCount);
    for(int i = 0; i < stack->straightMidrangeCount; i++)   printDisc(stack->straightMidrange[i]);
    printf("  Overstable (%d):\n",  stack->overstableMidrangeCount);
    for(int i = 0; i < stack->overstableMidrangeCount; i++) printDisc(stack->overstableMidrange[i]);
    printf("  Beefy (%d):\n",       stack->beefyMidrangeCount);
    for(int i = 0; i < stack->beefyMidrangeCount; i++)      printDisc(stack->beefyMidrange[i]);

    printf("=== FAIRWAY ===\n");
    printf("  Flippy (%d):\n",      stack->flippyFairwayCount);
    for(int i = 0; i < stack->flippyFairwayCount; i++)      printDisc(stack->flippyFairway[i]);
    printf("  Understable (%d):\n", stack->understableFairwayCount);
    for(int i = 0; i < stack->understableFairwayCount; i++) printDisc(stack->understableFairway[i]);
    printf("  Straight (%d):\n",    stack->straightFairwayCount);
    for(int i = 0; i < stack->straightFairwayCount; i++)    printDisc(stack->straightFairway[i]);
    printf("  Overstable (%d):\n",  stack->overstableFairwayCount);
    for(int i = 0; i < stack->overstableFairwayCount; i++)  printDisc(stack->overstableFairway[i]);
    printf("  Beefy (%d):\n",       stack->beefyFairwayCount);
    for(int i = 0; i < stack->beefyFairwayCount; i++)       printDisc(stack->beefyFairway[i]);

    printf("=== CONTROL ===\n");
    printf("  Flippy (%d):\n",      stack->flippyControlCount);
    for(int i = 0; i < stack->flippyControlCount; i++)      printDisc(stack->flippyControl[i]);
    printf("  Understable (%d):\n", stack->understableControlCount);
    for(int i = 0; i < stack->understableControlCount; i++) printDisc(stack->understableControl[i]);
    printf("  Straight (%d):\n",    stack->straightControlCount);
    for(int i = 0; i < stack->straightControlCount; i++)    printDisc(stack->straightControl[i]);
    printf("  Overstable (%d):\n",  stack->overstableControlCount);
    for(int i = 0; i < stack->overstableControlCount; i++)  printDisc(stack->overstableControl[i]);
    printf("  Beefy (%d):\n",       stack->beefyControlCount);
    for(int i = 0; i < stack->beefyControlCount; i++)       printDisc(stack->beefyControl[i]);

    printf("=== DISTANCE ===\n");
    printf("  Flippy (%d):\n",      stack->flippyDistanceCount);
    for(int i = 0; i < stack->flippyDistanceCount; i++)     printDisc(stack->flippyDistance[i]);
    printf("  Understable (%d):\n", stack->understableDistanceCount);
    for(int i = 0; i < stack->understableDistanceCount; i++) printDisc(stack->understableDistance[i]);
    printf("  Straight (%d):\n",    stack->straightDistanceCount);
    for(int i = 0; i < stack->straightDistanceCount; i++)   printDisc(stack->straightDistance[i]);
    printf("  Overstable (%d):\n",  stack->overstableDistanceCount);
    for(int i = 0; i < stack->overstableDistanceCount; i++) printDisc(stack->overstableDistance[i]);
    printf("  Beefy (%d):\n",       stack->beefyDistanceCount);
    for(int i = 0; i < stack->beefyDistanceCount; i++)      printDisc(stack->beefyDistance[i]);
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

struct Stack sortDiscs(struct Bag *bag){
    struct Stack stack = {0};
    for(int i = 0; i < bag->count; i++){
        char *cls  = bag->discs[i].classification;
        char *slot = bag->discs[i].slot;

        // Putters
        if (strcmp(cls,"Flippy") == 0 && strcmp(slot,"Putter") == 0) {
            stack.flippyPutter[stack.flippyPutterCount++] = bag->discs[i];
            stack.stackCount++;
            stack.putterCount++;
        } else if (strcmp(cls,"Understable") == 0 && strcmp(slot,"Putter") == 0) {
            stack.understablePutter[stack.understablePutterCount++] = bag->discs[i];
            stack.stackCount++;
            stack.putterCount++;
        } else if (strcmp(cls,"Straight") == 0 && strcmp(slot,"Putter") == 0) {
            stack.straightPutter[stack.straightPutterCount++] = bag->discs[i];
            stack.stackCount++;
            stack.putterCount++;
        } else if (strcmp(cls,"Overstable") == 0 && strcmp(slot,"Putter") == 0) {
            stack.overstablePutter[stack.overstablePutterCount++] = bag->discs[i];
            stack.stackCount++;
            stack.putterCount++;
        } else if (strcmp(cls,"Beefy") == 0 && strcmp(slot,"Putter") == 0) {
            stack.beefyPutter[stack.beefyPutterCount++] = bag->discs[i];
            stack.stackCount++;
            stack.putterCount++;

        // Approach
        } else if (strcmp(cls,"Flippy") == 0 && strcmp(slot,"Approach") == 0) {
            stack.flippyApproach[stack.flippyApproachCount++] = bag->discs[i];
            stack.stackCount++;
            stack.approachCount++;
        } else if (strcmp(cls,"Understable") == 0 && strcmp(slot,"Approach") == 0) {
            stack.understableApproach[stack.understableApproachCount++] = bag->discs[i];
            stack.stackCount++;
            stack.approachCount++;
        } else if (strcmp(cls,"Straight") == 0 && strcmp(slot,"Approach") == 0) {
            stack.straightApproach[stack.straightApproachCount++] = bag->discs[i];
            stack.stackCount++;
            stack.approachCount++;
        } else if (strcmp(cls,"Overstable") == 0 && strcmp(slot,"Approach") == 0) {
            stack.overstableApproach[stack.overstableApproachCount++] = bag->discs[i];
            stack.stackCount++;
            stack.approachCount++;
        } else if (strcmp(cls,"Beefy") == 0 && strcmp(slot,"Approach") == 0) {
            stack.beefyApproach[stack.beefyApproachCount++] = bag->discs[i];
            stack.stackCount++;
            stack.approachCount++;

        // Midrange
        } else if (strcmp(cls,"Flippy") == 0 && strcmp(slot,"Midrange") == 0) {
            stack.flippyMidrange[stack.flippyMidrangeCount++] = bag->discs[i];
            stack.stackCount++;
            stack.midrangeCount++;
        } else if (strcmp(cls,"Understable") == 0 && strcmp(slot,"Midrange") == 0) {
            stack.understableMidrange[stack.understableMidrangeCount++] = bag->discs[i];
            stack.stackCount++;
            stack.midrangeCount++;
        } else if (strcmp(cls,"Straight") == 0 && strcmp(slot,"Midrange") == 0) {
            stack.straightMidrange[stack.straightMidrangeCount++] = bag->discs[i];
            stack.stackCount++;
            stack.midrangeCount++;
        } else if (strcmp(cls,"Overstable") == 0 && strcmp(slot,"Midrange") == 0) {
            stack.overstableMidrange[stack.overstableMidrangeCount++] = bag->discs[i];
            stack.stackCount++;
            stack.midrangeCount++;
        } else if (strcmp(cls,"Beefy") == 0 && strcmp(slot,"Midrange") == 0) {
            stack.beefyMidrange[stack.beefyMidrangeCount++] = bag->discs[i];
            stack.stackCount++;
            stack.midrangeCount++;

        // Fairway
        } else if (strcmp(cls,"Flippy") == 0 && strcmp(slot,"Fairway") == 0) {
            stack.flippyFairway[stack.flippyFairwayCount++] = bag->discs[i];
            stack.stackCount++;
            stack.fairwayCount++;
        } else if (strcmp(cls,"Understable") == 0 && strcmp(slot,"Fairway") == 0) {
            stack.understableFairway[stack.understableFairwayCount++] = bag->discs[i];
            stack.stackCount++;
            stack.fairwayCount++;
        } else if (strcmp(cls,"Straight") == 0 && strcmp(slot,"Fairway") == 0) {
            stack.straightFairway[stack.straightFairwayCount++] = bag->discs[i];
            stack.stackCount++;
            stack.fairwayCount++;
        } else if (strcmp(cls,"Overstable") == 0 && strcmp(slot,"Fairway") == 0) {
            stack.overstableFairway[stack.overstableFairwayCount++] = bag->discs[i];
            stack.stackCount++;
            stack.fairwayCount++;
        } else if (strcmp(cls,"Beefy") == 0 && strcmp(slot,"Fairway") == 0) {
            stack.beefyFairway[stack.beefyFairwayCount++] = bag->discs[i];
            stack.stackCount++;
            stack.fairwayCount++;

        // Control
        } else if (strcmp(cls,"Flippy") == 0 && strcmp(slot,"Control") == 0) {
            stack.flippyControl[stack.flippyControlCount++] = bag->discs[i];
            stack.stackCount++;
            stack.controlCount++;
        } else if (strcmp(cls,"Understable") == 0 && strcmp(slot,"Control") == 0) {
            stack.understableControl[stack.understableControlCount++] = bag->discs[i];
            stack.stackCount++;
            stack.controlCount++;
        } else if (strcmp(cls,"Straight") == 0 && strcmp(slot,"Control") == 0) {
            stack.straightControl[stack.straightControlCount++] = bag->discs[i];
            stack.stackCount++;
            stack.controlCount++;
        } else if (strcmp(cls,"Overstable") == 0 && strcmp(slot,"Control") == 0) {
            stack.overstableControl[stack.overstableControlCount++] = bag->discs[i];
            stack.stackCount++;
            stack.controlCount++;
        } else if (strcmp(cls,"Beefy") == 0 && strcmp(slot,"Control") == 0) {
            stack.beefyControl[stack.beefyControlCount++] = bag->discs[i];
            stack.stackCount++;
            stack.controlCount++;

        // Distance
        } else if (strcmp(cls,"Flippy") == 0 && strcmp(slot,"Distance") == 0) {
            stack.flippyDistance[stack.flippyDistanceCount++] = bag->discs[i];
            stack.stackCount++;
            stack.distanceCount++;
        } else if (strcmp(cls,"Understable") == 0 && strcmp(slot,"Distance") == 0) {
            stack.understableDistance[stack.understableDistanceCount++] = bag->discs[i];
            stack.stackCount++;
            stack.distanceCount++;
        } else if (strcmp(cls,"Straight") == 0 && strcmp(slot,"Distance") == 0) {
            stack.straightDistance[stack.straightDistanceCount++] = bag->discs[i];
            stack.stackCount++;
            stack.distanceCount++;
        } else if (strcmp(cls,"Overstable") == 0 && strcmp(slot,"Distance") == 0) {
            stack.overstableDistance[stack.overstableDistanceCount++] = bag->discs[i];
            stack.stackCount++;
            stack.distanceCount++;
        } else if (strcmp(cls,"Beefy") == 0 && strcmp(slot,"Distance") == 0) {
            stack.beefyDistance[stack.beefyDistanceCount++] = bag->discs[i];
            stack.stackCount++;
            stack.distanceCount++;
        }
    }
    return stack;
}

struct Bag optimalBag(struct Stack *stack) {
    struct Bag newbag = {0};
    newbag.count = 0;
    srand(time(NULL));

    // --- PUTTERS ---
    if (stack->understablePutterCount > 0)
        addDisc(stack->understablePutter[rand() % stack->understablePutterCount], &newbag);
    if (stack->straightPutterCount > 0)
        addDisc(stack->straightPutter[rand() % stack->straightPutterCount], &newbag);
    if (stack->overstablePutterCount > 0)
        addDisc(stack->overstablePutter[rand() % stack->overstablePutterCount], &newbag);

    // --- APPROACH ---
    if (stack->understableApproachCount > 0)
        addDisc(stack->understableApproach[rand() % stack->understableApproachCount], &newbag);
    if (stack->straightApproachCount > 0)
        addDisc(stack->straightApproach[rand() % stack->straightApproachCount], &newbag);
    if (stack->overstableApproachCount > 0)
        addDisc(stack->overstableApproach[rand() % stack->overstableApproachCount], &newbag);

    // --- MIDRANGE ---
    if (stack->understableMidrangeCount > 0)
        addDisc(stack->understableMidrange[rand() % stack->understableMidrangeCount], &newbag);
    if (stack->straightMidrangeCount > 0)
        addDisc(stack->straightMidrange[rand() % stack->straightMidrangeCount], &newbag);
    if (stack->overstableMidrangeCount > 0)
        addDisc(stack->overstableMidrange[rand() % stack->overstableMidrangeCount], &newbag);

    // --- FAIRWAY ---
    if (stack->understableFairwayCount > 0)
        addDisc(stack->understableFairway[rand() % stack->understableFairwayCount], &newbag);
    if (stack->straightFairwayCount > 0)
        addDisc(stack->straightFairway[rand() % stack->straightFairwayCount], &newbag);
    if (stack->overstableFairwayCount > 0)
        addDisc(stack->overstableFairway[rand() % stack->overstableFairwayCount], &newbag);

    // --- CONTROL ---
    if (stack->understableControlCount > 0)
        addDisc(stack->understableControl[rand() % stack->understableControlCount], &newbag);
    if (stack->straightControlCount > 0)
        addDisc(stack->straightControl[rand() % stack->straightControlCount], &newbag);
    if (stack->overstableControlCount > 0)
        addDisc(stack->overstableControl[rand() % stack->overstableControlCount], &newbag);

    // --- DISTANCE ---
    if (stack->understableDistanceCount > 0)
        addDisc(stack->understableDistance[rand() % stack->understableDistanceCount], &newbag);
    if (stack->straightDistanceCount > 0)
        addDisc(stack->straightDistance[rand() % stack->straightDistanceCount], &newbag);
    if (stack->overstableDistanceCount > 0)
        addDisc(stack->overstableDistance[rand() % stack->overstableDistanceCount], &newbag);

    return newbag;
}


int main() {
    struct Disc allDiscs[] = {
    createDisc("Kastaplast", "Berg", 1, 1, 0, 2),
    createDisc("Kastaplast","Berg X",1,1,1,2),
    createDisc("Kastaplast","Berg X",1,1,1,2),
    createDisc("Axiom","Proxy x",3,3,-1,0.5),
    createDisc("Kastaplast","Reko X",3,3,0,2),
    createDisc("Discraft","Zone SS",4,4,-1,2),
    createDisc("Axiom","Tempo",4,4,0,2.5),
    createDisc("Discraft","Zone",4,3,0,3),
    createDisc("Prodigy","A2",4,2,0,4),
    createDisc("Axiom","Pyro",5,4,0,2.5),
    createDisc("Latitude 64", "Rive", 13, 5, 0, 3.5),
    createDisc("Discmania","PD",10,4,0,3),
    createDisc("Latitude 64","Pioneer",9,4,0,3),
    createDisc("Axiom","Hex",5,5,-1,1),
    createDisc("MVP","Servo",6.5,5,-1,2),
    createDisc("MVP","Reactor",5,5,-0.5,1.5),
    createDisc("MVP","Trail",10,5,-1,1),
    createDisc("Discmania","DD3",12,5,-1,3),
    createDisc("Streamline","Boost",9.5,4,0,2.5),
    createDisc("Dynamic Discs","Felon",9,3,0.5,4),
    createDisc("Discmania", "PD2", 12, 4, 0, 4),
    createDisc("Kastaplast","Guld",13,5,-0.5,3),
    createDisc("MVP","Zenith",11,5,-0.5,2),
    createDisc("MVP","Resistor",6,4,0,3.5),
    createDisc("MVP","Tesla",9,5,-1,2),
    createDisc("MVP","GOOSE Reactor",5,5,-0.5,1.5),
};


    struct Bag gripax6 = {0};
    gripax6.count = 0;
    // printf("%d\n",totalDiscsCreated);
    for (int i = 0; i<totalDiscsCreated;i++){
        addDisc(allDiscs[i],&gripax6);
    }
    // addDisc(disc1, &gripax6);
    // addDisc(disc2,&gripax6);
    // addDisc(disc3,&gripax6);
    // addDisc(disc4,&gripax6);
    // addDisc(disc5,&gripax6);
    // addDisc(disc6, &gripax6);
    // addDisc(disc7,&gripax6);
    // addDisc(disc8,&gripax6);
    // addDisc(disc9,&gripax6);
    // addDisc(disc10,&gripax6);
    // addDisc(disc11, &gripax6);
    // addDisc(disc12,&gripax6);
    // addDisc(disc13,&gripax6);
    // addDisc(disc14,&gripax6);
    // addDisc(disc15,&gripax6);
    // addDisc(disc16, &gripax6);
    // addDisc(disc17,&gripax6);
    // addDisc(disc18,&gripax6);
    // addDisc(disc19,&gripax6);
    // addDisc(disc20,&gripax6);
    // addDisc(disc21,&gripax6);
    // addDisc(disc22,&gripax6);
    // addDisc(disc23,&gripax6);
    // addDisc(disc24,&gripax6);
    // addDisc(disc25,&gripax6);
    // addDisc(disc26,&gripax6);
    //make auto disc add.
    // printf("%d\n",gripax6.count);

    sortBagBySpeedAndStability(&gripax6);
    // printBag(&gripax6);
    classifyDiscs(&gripax6);
    // strcpy(gripax6.discs[16].classification,"Understable");
    struct Stack stackofmyprettydiscs = sortDiscs(&gripax6);
    // printStack(&stackofmyprettydiscs);
    struct Bag optimalgripax6 = optimalBag(&stackofmyprettydiscs);
    printBag(&optimalgripax6);

    
}