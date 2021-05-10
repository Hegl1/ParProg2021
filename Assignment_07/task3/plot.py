import importlib.util
spec = importlib.util.spec_from_file_location(
    "plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)

OUT_FILE = 'output_task_3_optimized.dat'

plot.plot_runtime_per_input_num(OUT_FILE, "Speedup for optimized intrinsic versions, various inputs",
                                "speedup_task3_optimized", 2048, 2048, 'Reference', 'Speedup')
plot.print_table(OUT_FILE)
