import os
import random
from subprocess import run

def generate_unique_random_list(size=100, low=-2147483648, high=2147483647):
    return random.sample(range(low, high), size)

for i in range(7):
    print(i+1, end=' ')
    path = os.path.join(os.getcwd(), "../push_swap")

    # Ensure that the path exists
    if not os.path.exists(path):
        print(f"Error: {path} does not exist.")
        continue
    args = [str(i) for i in generate_unique_random_list(5)]
    # Using list format for command and arguments
    cmd = [path] #+ [' '.join(args)]
    res = run(cmd)
    if res.returncode != 0:
        print('failed')
        print(" ".join(args))
    else:
        print('ok')

