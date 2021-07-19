# Plots_v2.py



## Usage of plots_v2.py

Plots.py can draw n curves in a plot, where every curve contains sample points for m threads.

#### Input file for plots_v2.py

Here is an example for a valid input file: 

```
*
Kurve 1
-
time: 8.04
-
time: 4.02
-
time: 1.03
*
Kurve 2
-
time: 4.05
-
time: 2.04
-
time: 1.02
*
Kurve 3
-
time: 12.03
-
time: 4.00
-
time: 2.12
```

Here one can observe 3 curves with 3 threas each. Every curve is preceeded by a `*`.
After the *, there must be a curve title, succseeded by the list of sample points, separated by `-`.
Note that the output must be ordered, i.e. the first time corresponds to the first thread, the second time to the second and so on.
It is crucial for the script that every curve has equally many sample points.



#### Importing of plots_v2.py 

Assuming that the file structure looks like this (*used in our git*):

```
plots_v2.py
assignment_01
assignment_02
	|
	|__Task1
	|__Task2
		|
		|__own_plotscript.py
		|__input_for_plotscript.txt
```

You can import plots_v2.py in your own script like this:

```python
import importlib.util
spec = importlib.util.spec_from_file_location("plots_v2.py", "../../plots_v2.py")
plot = importlib.util.module_from_spec(spec)
spec.loader.exec_module(plot)
```

And after importing you can use it like this:

```python
plot.print_table('sample_output.txt')
plot.plot_runtime_per_thread('sample_output.txt', 'sample_title', 'test_output', 'Kurve 1')
```

#### Functions in plots_v2.py

Functions preceeded by `_`are considered private and unsafe to use outside of plots_v2.py.

For producing useful output, watch `print_table(...)` and `plot_runtime_per_thread(...)`
