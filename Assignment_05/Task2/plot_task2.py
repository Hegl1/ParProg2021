import importlib.util
#if you are in the need of plots_v2.py, please contact Marcel.Huber@student.uibk.ac.at
spec = importlib.util.spec_from_file_location("plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)


plot.plot_runtime_per_input_num('./outputs/plot2.txt', 'All version, Par version with 8 threads', 'var_inputs', 100, 100)
plot.print_table_for_var_inputs('./outputs/plot2.txt', 100, 100)

plot.plot_runtime_per_thread('./outputs/plot.txt', 'Par version, N = 500', 'var_threads')
plot.print_table('./outputs/plot.txt')
