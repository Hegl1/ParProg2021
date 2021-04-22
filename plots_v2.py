import matplotlib.pyplot as plt
import sys
import os

def plot_runtime_per_input_num(filename, plot_title, output_file_name, start_input_size, input_step_size):
    ''' Function that plots runtimes per input size.
        It is assumed that first line in output is start_input_size  and
        steps between inputs is input_step_size
    '''
    titles, curves = _parse_input(filename)
    _prorduce_input_dependend_line_plot(titles, curves, plot_title, output_file_name, start_input_size, input_step_size)

def plot_runtime_per_thread(filename, plot_title, output_file_name, delta_ref_name = None):
    ''' Function that plots runtimes per thread in a line graph.
        Also supports delta-plotting if delta_ref_name is given
        
        filename: name of the input file
        plot_title: title of the plot to construct
        output_file_name: name of the file to produce. Note that flies get saved to ./plots/output_file_name
        delta_ref_name: name to choose the reference values for the delta plotting. Must be a name that is specified in the input file.
        '''
    if delta_ref_name is None:
        _plot_runtime_per_thread(filename, plot_title, output_file_name)
    else:
        _plot_delta_runtime_per_thread(filename, plot_title, output_file_name, delta_ref_name)

def print_table(filename, delta_ref_name = None):
    ''' Function that prints a table ThreadNum vs Runtime.
        Also supoorts delta-tables if delta_ref_name is given.

        filename: name of the input file
        delta_ref_name: name to choose the reference values for the delta plotting. Must be a name that is specified in the input file.
    '''
    if delta_ref_name is None:
        titles, curves = _parse_input(filename)
    else:
        titles, curves = _construct_delta_lists(filename, delta_ref_name)
    result = _build_title_line(titles)
    result+=_build_spacer_line(len(titles))
    result+=_build_content_lines(curves)
    print('\n' + result)
    return result

def print_table_for_var_inputs(filename, start_input_size, input_step_size):
    titles, curves = _parse_input(filename)
    result = _build_title_line_for_var_input(titles)
    result+=_build_spacer_line(len(titles))
    result+=_build_content_line_for_var_input(curves, start_input_size, input_step_size)
    print('\n' + result)
    return result

def _plot_runtime_per_thread(filename, plot_title, output_file_name):
    ''' Private function that generate a runtime/thread plot.
        Multiple lines per plot are supportet.
    '''

    titles, curves =  _parse_input(filename)
    _produce_line_plot(titles, curves, plot_title, output_file_name)

def _plot_delta_runtime_per_thread(filename, plot_title, output_file_name, delta_ref_name):
    ''' Private function that generates a runtime/thread delta plot.
        Multiple lines per plot are supportet, delta_ref_name must be given
    '''

    new_titles, new_curves = _construct_delta_lists(filename, delta_ref_name)
    _produce_line_plot(new_titles, new_curves, plot_title, output_file_name)

def _prorduce_input_dependend_line_plot(title_list, curve_list, plot_title, output_file_name, start_input_size, input_step_size):
    input_size_vec = range(start_input_size, len(curve_list[0])+start_input_size, input_step_size)
    for curve in curve_list:
        plt.plot(input_size_vec, curve)
        plt.scatter(input_size_vec, curve, marker='x')
    plt.xlabel("Input size")
    plt.ylabel("Execution time [s]")
    plt.legend(title_list)
    plt.title(plot_title)
    _create_folder_for_graphics()
    plt.savefig("./plots/" + output_file_name)
    plt.clf

def _produce_line_plot(title_list, curve_list, plot_title, output_file_name):
    ''' Shared private function used to actually produce the line plot'''

    thread_vec = _construct_base_line(len(curve_list[0]))
    for curve in curve_list:
        plt.plot(thread_vec, curve)
        plt.scatter(thread_vec, curve, marker='x')
    plt.xlabel("Number of threads")
    plt.ylabel("Execution time [s]")
    plt.legend(title_list)
    plt.title(plot_title)
    _create_folder_for_graphics()
    plt.savefig("./plots/" + output_file_name)
    plt.clf()

def _create_folder_for_graphics():
    '''Private function that generates the folder ./plots if it doesnt already exist'''

    if not os.path.exists('./plots'):
        os.makedirs('./plots')

def _build_content_lines(curves):
    '''Private function that generates the content lines for table building'''

    result = ''
    for i in range(len(curves[0])):
        result+='| {i} |'.format(i=i)
        for j in range(len(curves)):
            result += ' ' + str(curves[j][i]) + ' |'
        result+='\n'
    return result

def _build_title_line(titles):
    '''Private function that generates the title line for table building'''
    result = '| Number of threads |'
    for title in titles:
        result+= ' {tit} |'.format(tit=title)
    result+='\n'
    return result

def _build_spacer_line(number_of_columns):
    '''Private function that generates the spacer line for table building'''
    result = '|'
    for _ in range(number_of_columns+1):
        result+= ' ---- |'
    result+='\n'
    return result

def _build_content_line_for_var_input(curves, input_start_size, input_step_size):
    result = ''
    for i in range(len(curves[0])):
        result+='| {inpt} |'.format(inpt = input_start_size)
        input_start_size+=input_step_size
        for j in range(len(curves)):
            result += ' ' + str(curves[j][i]) + ' |'
        result+='\n'
    return result

def _build_title_line_for_var_input(titles):
    result = '| Input size |'
    for title in titles:
        result+= ' {tit} |'.format(tit=title)
    result+='\n'
    return result


def _construct_base_line(number_of_entries):
    ''' Private function that generates a list containging the thread numbers'''
    return range(1, number_of_entries+1)

def _parse_input(filename):
    ''' Private function that parses the input of a input file if it satisfies the specified format'''
    content = _get_file_content(filename)
    curves_content = content.split('*')
    curve_titles = list()
    curves = list()
    for curve in curves_content[1:]:
        single_curve = list()
        lines = curve.split('-')
        curve_titles.append(lines[0].strip('\n'))
        for line in lines[1:]:
            appendix = line.split(':')[1].strip()
            single_curve.append(float(appendix))
        curves.append(single_curve)
    return(curve_titles, curves)
    
def _get_file_content(filename):
    ''' Private function that reads in the input file'''
    try:
        f = open(filename, 'r')
        content = f.read()
        return content
    except FileNotFoundError:
        print(f"Given file '{filename}' was not found")
        sys.exit(1)

def _construct_delta_lists(filename, delta_ref_name):
    '''Private function that constructs lists for delta calls'''
    titles, curves = _parse_input(filename)
    index = titles.index(delta_ref_name)
    ref_list = curves.pop(index)
    new_titles = list(filter(lambda x: x != delta_ref_name,titles))
    new_curves = list()
    for curve in curves:
        temp = list()
        for i in range(len(curve)):
            temp.append(ref_list[i] - curve[i])
        new_curves.append(temp)
    return(new_titles, new_curves)

if __name__ == '__main__':
   pass