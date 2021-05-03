import importlib.util
spec = importlib.util.spec_from_file_location("plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)

OUT_FILE = 'output.dat'

plot.plot_runtime_per_thread(OUT_FILE)
plot.print_table(OUT_FILE)