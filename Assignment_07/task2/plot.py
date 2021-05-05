import importlib.util
spec = importlib.util.spec_from_file_location("plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)

OUT_FILE = 'output_task_2.dat'
OUT_FILE_2 = 'output_task_2_double.dat'

plot.plot_runtime_per_input_num(OUT_FILE, "Speedup for OMP vectorized float", "speedup_task2_float", 2048, 2048, 'Reference', 'Speedup')
plot.plot_runtime_per_input_num(OUT_FILE_2, "Speedup for OMP vectorized double", "speedupt_task2_double", 2048,2048,'DOUBLE REFERENCE', 'Speedup')
plot.print_table_for_var_inputs(OUT_FILE, 2048, 2048)
plot.print_table_for_var_inputs(OUT_FILE_2, 2048, 2048)