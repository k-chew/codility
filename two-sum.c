#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

struct hashEntry {
    int key; // the integer
    int value; // its index in nums
};

struct hashMap {
    int length;
    struct hashEntry **list;
};

void insertHash(struct hashMap *map, struct hashEntry *entry) {
    assert(map);
    assert(entry);
    map->list[map->length] = entry;
    ++map->length;
    map->list = realloc(map->list, sizeof(struct hashEntry *) * (map->length + 1));
} 

bool contains(struct hashMap *map, int key, int *val) {
    assert(map);
    for (int i = 0; i < map->length; ++i) {
        if (map->list[i]->key == key) { // the integer
            *val = map->list[i]->value; // the corresponding index
            return true;
        }
    }
    return false;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // initialize return array
    *returnSize = 2;
    int *returnArray = malloc(sizeof(int) * *returnSize);
    
    // create hash map
    struct hashMap *map = malloc(sizeof(struct hashMap));
    map->length = 0;
    map->list = malloc(sizeof(struct hashEntry));
    
    // enter nums data into hash map
    for (int i = 0 ; i < numsSize; ++i) {
        // create hashEntry
        struct hashEntry *entry = malloc(sizeof(struct hashEntry));
        entry->key = nums[i];
        entry->value = i;
        insertHash(map, entry);
    }
    
    // iterate through nums and check for complement
    for (int j = 0; j < numsSize; ++j) {
        int complement = target - nums[j];
        int val = 0;
        bool lookup = contains(map, complement, &val);
        if (lookup && val != j) {
            returnArray[0] = j;
            returnArray[1] = val;
            break;
        }
    }
    
    // free allocated memory
    int i = 0;
    while (i < map->length) {
        free(map->list[i]);
        ++i;
    }
    free(map->list);
    free(map);
    
    
    return returnArray;
}
