import importlib.util
spec = importlib.util.spec_from_file_location("plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)

OUT_FILE = 'output_task_1.dat'

plot.plot_runtime_per_input_num(OUT_FILE, "Speedup for vectorized program, various inputs", "speedup_task1", 2048, 2048, 'Reference', 'Speedup')
plot.print_table_for_var_inputs(OUT_FILE, 2048, 2048)