import importlib.util
#if you are in the need of plots_v2.py, please contact Marcel.Huber@student.uibk.ac.at
spec = importlib.util.spec_from_file_location("plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)


plot.plot_runtime_per_input_num('./outputs/output_all_n.dat', 'All version, Par version with 8 threads', 'var_inputs', 3, 1)
plot.print_table_for_var_inputs('./outputs/output_all_n.dat', 3, 1)

plot.plot_runtime_per_input_num('./outputs/output_all_n_modified.dat', 'All version, Par version with 8 threads, relevant data points', 'var_inputs_zoomed', 11, 1)
plot.print_table_for_var_inputs('./outputs/output_all_n_modified.dat', 11, 1)

plot.plot_runtime_per_thread('./outputs/output_threads.dat', 'Par version, N = 14', 'var_threads')
plot.print_table('./outputs/output_threads.dat')

