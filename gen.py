import sys, os.path
if(os.path.exists("in.txt")):
    sys.stdin = open("in.txt","r")
    sys.stdout = open("out.txt","w")

contest = sys.argv[1]
c_round = sys.argv[2]
file_num = int(sys.argv[3])
name = contest + ' Round #' + c_round
path = contest + '/' + name
os.mkdir(path)

f = open('template.cpp', 'r')
template = f.read()
    
def file_creation():
    file_list = []
    for i in range(0, file_num):
        x = chr(ord('A') + i)

        file_name = str(x)
        file_name = path + '/' + file_name + '.cpp'
        
        f = open(file_name, 'w')   
        f.write(template)
        file_list.append(file_name)
        f.close()

    for i in file_list:
        folder = sys.path[0] + '/' + i
        os.startfile(folder)

file_creation()