import importlib.util
spec = importlib.util.spec_from_file_location("plots_v2.py", "../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)

SPEEDUP = 'output_task1_week12.dat'
VARBODS = "output_task1_week12_varnumbodies.dat"
VARTIMES = "output_task1_week12_varnumits.dat"

plot.plot_runtime_per_thread(SPEEDUP, "Speedup for parallel program, num_bodies = 5000, timesteps = 100", "speedup_task1", "Reference")
plot.print_table(SPEEDUP)
plot.plot_runtime_per_input_num(VARBODS, "Time for various numbers of bodies, timesteps = 100, 8 threads", "var_bodies", 500, 500)
plot.print_table_for_var_inputs(VARBODS, 500, 500)
plot.plot_runtime_per_input_num(VARTIMES, "Time for various timesteps, number of bodies = 1000, 8 threads", "var_times", 200, 200)
plot.print_table_for_var_inputs(VARTIMES, 200, 200)