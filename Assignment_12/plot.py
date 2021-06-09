import importlib.util
spec = importlib.util.spec_from_file_location("plots_v2.py", "../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)

OUT_FILE = 'output_task1_week12.dat'

plot.plot_runtime_per_thread(OUT_FILE, "Speedup for vectorized program, inputs = 5000 100", "speedup_task1", "Reference")
plot.print_table(OUT_FILE)