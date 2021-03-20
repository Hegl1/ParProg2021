import matplotlib.pyplot as plt
import os
from subprocess import Popen, PIPE

COMPILER = 'gcc'
FILES = ['slow', 'medium', 'fast']
NUM_CORES = 8


def compile(file):
    for i in range(1, 4):
        os.system(
            f'{COMPILER} {file}.c -std=gnu11 -fopenmp -O{i} -o {file}_O{i}.out')


def cleanup(file):
    for i in range(1, 4):
        os.system(f'rm {file}_O{i}.out')


def compile_all():
    for f in FILES:
        compile(f)


def clean_all():
    for f in FILES:
        cleanup(f)

#returns ([NUM__THREADS],[TIME])


def execute(file_out):

    list_num_threads = list()
    list_time = list()

    for i in range(1, NUM_CORES+1):
        os.environ['OMP_NUM_THREADS'] = str(i)
        process = Popen([f'./{file_out}'], stdout=PIPE,
                        universal_newlines=True)
        (output, err) = process.communicate()
        exit_code = process.wait()
        list_num_threads.append(i)
        list_time.append(parse(output))
    return (list_num_threads, list_time)


def parse(in_string):
    return float(in_string.split(' ')[3])


def plot_all_O1(opt1, opt2, opt3, base):
    plt.plot(base, opt1)
    plt.plot(base, opt2)
    plt.plot(base, opt3)
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time [s]")
    plt.legend(['slow.c', 'medium.c', 'fast.c'])
    plt.title('slow.c, medium.c and fast.c with -O1')
    plt.savefig('./plots/all_O1.png')
    plt.clf()


def plot_all_os(opt1, opt2, opt3, base, name):
    plt.plot(base, opt1)
    plt.plot(base, opt2)
    plt.plot(base, opt3)
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time [s]")
    plt.legend(['-O1', '-O2', '-O3'])
    plt.title(f'{name} with -O1, -O2 and -O3')
    plt.savefig(f'./plots/{name}.png')
    plt.clf()


def print_table(base, col1, col2, col3, title_line):
    result = title_line
    result += '| ---- | ---- | ---- | ---- |\n'
    
    for i in range(len(base)):
        result += '| '
        result += str(base[i]) + ' |'
        result += str(col1[i]) + ' |'
        result += str(col2[i]) + ' |'
        result += str(col3[i]) + ' |'
        result += '\n'
    print(result)


compile_all()
base = list(range(1, NUM_CORES+1))
slow_o1 = execute("slow_O1.out")[1]
slow_o2 = execute("slow_O2.out")[1]
slow_o3 = execute("slow_O3.out")[1]
medium_o1 = execute("medium_O1.out")[1]
medium_o2 = execute("medium_O2.out")[1]
medium_o3 = execute("medium_O3.out")[1]
fast_o1 = execute("fast_O1.out")[1]
fast_o2 = execute("fast_O2.out")[1]
fast_o3 = execute("fast_O3.out")[1]

plot_all_O1(slow_o1, medium_o1, fast_o1, base)
plot_all_os(slow_o1, slow_o2, slow_o3, base, 'slow')
plot_all_os(medium_o1, medium_o2, medium_o3, base, 'medium')
plot_all_os(fast_o1, fast_o2, fast_o3, base, 'fast')


print_table(base, slow_o1, medium_o1, fast_o1,
            '| num_threads | slow.c | medium.c | fast.c |\n')

print_table(base, slow_o1, slow_o2, slow_o3,
            '| num_threads | slow.c -O1 | slow.c -O2 | slow.c -O3 |\n')

print_table(base, medium_o1, medium_o2, medium_o3,
            '| num_threads | medium.c -O1 | medium.c -O2 | medium.c -O3 |\n')

print_table(base, fast_o1, fast_o2, fast_o3,
            '| num_threads | fast.c -O1 | fast.c -O2 | fast.c -O3 |\n')

clean_all()
