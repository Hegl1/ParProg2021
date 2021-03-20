import matplotlib.pyplot as plt

def plot_all(opt1, opt2, base):
    plt.plot(base, opt1)
    plt.plot(base, opt2)
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time [s]")
    plt.legend(['serial', 'parallel'])
    plt.title('Monte Carlo ser/par with 1 to 8 threads')
    plt.savefig('./plots/monte_carlo.png')
    plt.clf()


def print_table(base, col1, title_line):
    result = title_line
    result += '| ---- | ---- | ---- |\n'
    
    for i in range(len(base)):
        result += '| '
        result += str(base[i]) + ' |'
        result += str(col1[i]) + ' |'
        result += '\n'
    print(result)

def parse(in_string):
    return float(in_string.split('\n')[0].split(' ')[3])

def readFile(filename):
    f = open(filename, "r")
    content=f.read()
    f.close()
    blocks = content.split('-')
    par_lines=blocks[0].split('\n')
    par = list()
    for line in par_lines[:-1]:
        num=parse(line)
        par.append(num)
    ser_lines=blocks[1].split('\n')
    ser = list()
    for line in ser_lines[1:-1]:
        num=parse(line)
        ser.append(num)
    
    return (ser, par, range(1,9))



res = readFile("output.dat")
plot_all(res[0], res[1], res[2])
print_table(res[2], res[1], "| number_of_threads | execution time of parallel version (s) |\n")
print("Execution time for serial version: ", res[0][0])
