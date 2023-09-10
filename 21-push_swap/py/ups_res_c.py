with open("res_c.txt", 'r') as f:
    text = f.readlines()

c = 1
for i, line in enumerate(text):
    if line.startswith('-'):
        text[i-1] = f'{c}. {text[i-1]}'
        c += 1

with open("res_c.txt", 'w') as f:
    text = f.writelines(text)