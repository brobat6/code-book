import os

F = open("code-book.code-snippets", "w")

def write(path : str):
    # Read .cpp file "G" and write its code snippet to F.
    # Assert it is ".cpp" beforehand!
    # Take care of "\", "\\" and "\n".
    prefix = path.split(".")[-2]
    temp = ""
    for i in prefix:
        if(i == "\\"):
            temp += "\\\\"
        else:
            temp += i
    prefix = temp
    G = open(path[:-1], "r")
    F.write(f'\t"{prefix}" : {{\n')
    F.write(f'\t\t"prefix" : "{prefix}",\n')
    F.write('\t\t"body" : [\n')
    can_start = False
    if(path == "template.cpp/"):
        can_start = True
    for line in G.readlines():
        if(line.find("using namespace std;") != -1 and not can_start):
            can_start = True
            continue
        if(can_start):
            F.write('\t\t\t"')
            ended = False
            for c in line:
                if(c == "\n"):
                    F.write('",\n')
                    ended = True
                elif(c == "\\"):
                    F.write("\\\\")
                elif(c == '"'):
                    F.write('\\"')
                else:
                    F.write(f"{c}")
            if(not ended):
                F.write('",\n')
    F.write('\t\t]\n')
    F.write('\t},\n')

def parse(path : str):
    # Parse the current path. If it is a directory, recursively call
    # parse() on contents of directory. If it is a file, check if it is ".cpp" 
    # and if it is, write() file contents. Else, ignore.
    if(path.count('.') == 0):
        # Directory
        if(len(path) == 0):
            for sub in os.listdir():
                new_path = path + sub + "/"
                parse(new_path)
        else:
            for sub in os.listdir(path):
                new_path = path + sub + "/"
                parse(new_path)    
    else:
        # File
        if(path.find(".cpp") != -1):
            # .cpp file
            write(path)

F.write("{\n")
parse("")
F.write("}\n")

F.close()
