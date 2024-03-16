#include<stdio.h>
#include<stdlib.h>

typedef struct item{
    float value, weight, density;
} Item;

void sort(Item it[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(it[j].density < it[j+1].density){
                Item temp = it[j];
                it[j] = it[j+1];
                it[j+1] = temp;
            }
        }
    }
}

Item NewItem(float v, float w){
    Item n;
    n.value = v;
    n.weight = w;
    n.density = n.value / n.weight;
    return n;
}

int greedy(Item *items, int size, float capacity, Item *Bag){
    int maxVal = 0.0;
    int capac = 0.0;
    int bag_counter = 0;
    for(int i = 0; i < size; i++){
        if(capac + items[i].weight <= capacity){
            Bag[bag_counter] = items[i];
            capac += items[i].weight;
            bag_counter++;
            maxVal += items[i].value;
        } else {
            break;
        }
    }
    return maxVal;
}

void traverse(Item it[], int size){
    for(int i = 0; i < size; i++){
        printf(" this are from the items%f\n", it[i].density);
    }
}

int main(){
    Item water = NewItem(10.0, 20.0);
    Item biscuit = NewItem(5.0, 15.0);
    Item juice = NewItem(8.0, 20.0);
    
    Item items[] = {water, juice, biscuit};
    sort(items, 3);
    traverse(items, 3);
    Item bag[3];
    int greed=greedy(items,3,40.0,bag);
    traverse(bag,3);
    return 0;
}
