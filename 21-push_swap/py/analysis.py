with open("res_c.txt", 'r') as c_file, open("res_py.txt", 'r') as py_file:
    c_res = c_file.readlines()
    py_res = py_file.readlines()
    
c_res = [line.strip().strip('\n') for line in c_res]
py_res = [line.strip().strip('\n') for line in py_res]


i = 0
for c_line, py_line in zip(c_res, py_res):
    if "pa" in c_line and c_res[i+2] != py_res[i+2]:
        print(c_line)
        print(f'C  : {c_res[i+2]}')
        print(f'PY : {py_res[i+2]}')
    i += 1


"""
i = 1
for c_cmd, py_cmd in zip(c_res, py_res):
    c_cmd = c_cmd.strip('\n')
    py_cmd = py_cmd.strip('\n')
    if c_cmd != py_cmd:
        print(f'{i}\t{c_cmd}\t{py_cmd}\tX')
    else:
        print(f'{i}\t{c_cmd}\t{py_cmd}')
    i+=1
"""
