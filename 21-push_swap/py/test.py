import os
import random
from subprocess import check_output

def generate_unique_random_list(size=100, low=-2147483648, high=2147483647):
    return random.sample(range(low, high), size)



res = []
for i in range(5):
    print(i+1, end=' ')
    path = os.path.join(os.getcwd(), "../push_swap")
    print(path)
    # Ensure that the path exists
    if not os.path.exists(path):
        print(f"Error: {path} does not exist.")
        continue
    args = [str(i) for i in generate_unique_random_list(500)]
    # Using list format for command and arguments
    cmd = [path] + args
    out = check_output(cmd).decode().splitlines()
    if out[-1] != 'sorted':
        print('Failed')        
        print(" ".join(args))
    else:
        #print('OK')
        res.append(len(out)-1)
print(max(res))

