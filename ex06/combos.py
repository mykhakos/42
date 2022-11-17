from itertools import combinations


l = combinations(range(100), 2)
with open('f.txt', 'a', encoding='utf-8') as f:
    for i in l:
        f.write(f'{i}, ')