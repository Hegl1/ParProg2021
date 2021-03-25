import matplotlib.pyplot as plt
import sys

def plot_all(threads, red, atomic, critical ,base):
    plt.plot(base, threads)
    plt.plot(base, red)
    plt.plot(base, atomic)
    plt.plot(base, critical)
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time [s]")
    plt.legend(['threads', 'reduced', 'atomic','critical'])
    #plt.title('Monte Carlo ser/par with 1 to 8 threads')
    plt.savefig('./plots/monte_carlo.png')
    plt.clf()


def print_table(base, col1, col2, col3, col4, title_line):
    result = title_line
    result += '| ---- | ---- | ---- | ---- | ---- |\n'
    
    for i in range(len(base)):
        result += '| '
        result += str(base[i]) + ' |'
        result += str(col1[i]) + ' |'
        result += str(col2[i]) + ' |'
        result += str(col3[i]) + ' |'
        result += str(col4[i]) + ' |'
        result += '\n'
    print(result)

def parse(in_string):
    return float(in_string.split('\n')[0].split(' ')[3])

def get_block_content(in_block):
    result = list()
    lines = in_block.split('\n')
    for line in lines[1:-1]:
        num = parse(line)
        result.append(num)
    return result
    

def readFile(filename):
    f = open(filename, "r")
    content=f.read()
    blocks = content.split('-')
    result = list()
    for block in blocks:
        result.append(get_block_content(block))
    return result

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python3 plots.py <file with formattet output data>")
    else:
        res = readFile(sys.argv[1])
        plot_all(res[0], res[1], res[2], res[3], range(1,9))
        print_table(range(1,9), res[0], res[1], res[2], res[3], '| number_of_threads | thread_version | reduced_version | atomic_version | critical_version |\n')