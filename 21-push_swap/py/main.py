import copy
import random
import math

from itertools import permutations

import matplotlib.pyplot as plt
import numpy as np

import pandas as pd

from utils import Sorter

def mean(numbers: list[int]):
    return int(round(sum(numbers)/len(numbers), 0))

def generate_permutations_123():
    return list(list(perm) for perm in permutations((1, 2, 3)))

def generate_random_list(size: int):
    lst = []
    while len(lst) < size:
        i = random.randint(-size, size)
        if i in lst:
            continue
        lst.append(i)
    return lst


def generate_lists(list_length=5, start=-10000, end=10000):
    
    unique_numbers = random.sample(range(start, end), list_length)

    return list(unique_numbers)




try:
    results = []

    rng = 1000
    for i in range(rng):
        
        a = generate_lists(3)
        #print(a)
        print(f'Sorting list {i+1} / {rng}')
        
        sorter1 = Sorter(copy.copy(a), print=False)

        sorter1.sort()
        
        act1 = sorter1.actions
        results.append(act1)

        print(f'Sorted! Took {act1}  actions.\n')

        #if sorter1.actions > 12:
        #    print(a)
       
    
    
finally:
    print(f'min  : {min(results)} ({results.count(min(results))})')
    print(f'mean : {mean(results)} ({results.count(mean(results))})')
    print(f'max  : {max(results)} ({results.count(max(results))})')

