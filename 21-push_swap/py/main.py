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

lst = [382, 852, 804, 228, 995, 866, 543, 453, 841, 781, 706, 905, 481, 91, 924, 755, 773, 709, 120, 88, 982, 897, 275, 356, 664, 519, 334, 669, 452, 918, 583, 926, 507, 141, 81, 985, 872, 681, 645, 475, 240, 397, 702, 934, 893, 136, 476, 282, 913, 657, 420, 486, 605, 401, 74, 418, 536, 628, 446, 337, 492, 748, 692, 306, 244, 384, 528, 122, 292, 573, 667, 59, 553, 217, 646, 799, 325, 154, 798, 479, 153, 751, 277, 618, 490, 701, 133, 603, 829, 314, 589, 335, 655, 316, 984, 414, 915, 684, 440, 592]
sorter = Sorter(lst, print=True)
sorter.sort()



"""
try:
    results = []

    rng = 100
    for i in range(rng):
        
        a = generate_lists(100)
        #print(a)
        #print(f'Sorting list {i+1} / {rng}')
        
        sorter1 = Sorter(copy.copy(a), print=False)

        sorter1.sort()
        
        act1 = sorter1.actions
        results.append(act1)

        #print(f'Sorted! Took {act1}  actions.\n')

        #if sorter1.actions > 12:
        #    print(a)
       
    
    
finally:
    print(f'min  : {min(results)} ({results.count(min(results))})')
    print(f'mean : {mean(results)} ({results.count(mean(results))})')
    print(f'max  : {max(results)} ({results.count(max(results))})')

"""