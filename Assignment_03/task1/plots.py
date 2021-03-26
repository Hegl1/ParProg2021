import matplotlib.pyplot as plt
import sys

def plot_total_runtimes(threads, red, atomic, critical ,base):
    plt.plot(base, threads)
    plt.scatter(base, threads, marker='x')
    plt.plot(base, red)
    plt.scatter(base, red, marker='x')
    plt.plot(base, atomic)
    plt.scatter(base, atomic, marker='x')
    plt.plot(base, critical)
    plt.scatter(base, critical, marker='x')
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time [s]")
    plt.legend(['threads', 'reduced', 'atomic','critical'])
    plt.title('Runtimes of all parallel versions, 1 to 8 threads')
    plt.savefig('./plots/absolute_runtimes.png')
    plt.clf()

def plot_delta_runtimes(threads, red, atomic, critical, base):
    reddiff = [t-e for t, e in zip(threads, red)]
    atomicdiff = [t-e for t, e in zip(threads, atomic)]
    criticaldiff = [t-e for t, e in zip(threads, critical)]
    plt.plot(base, reddiff)
    plt.scatter(base, reddiff, marker='x')
    plt.plot(base, atomicdiff)
    plt.scatter(base, atomicdiff, marker='x')
    plt.plot(base, criticaldiff)
    plt.scatter(base, criticaldiff, marker='x')
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time delta")
    plt.legend(['reduced', 'atomic','critical'])
    plt.title('Relative runtimes OMP-Versions vs Thread-Version')
    plt.savefig('./plots/relative_runtimes.png')
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
        plot_total_runtimes(res[0], res[1], res[2], res[3], range(1,9))
        plot_delta_runtimes(res[0], res[1], res[2], res[3], range(1,9))
        print_table(range(1,9), res[0], res[1], res[2], res[3], '| number_of_threads | thread_version | reduced_version | atomic_version | critical_version |\n')