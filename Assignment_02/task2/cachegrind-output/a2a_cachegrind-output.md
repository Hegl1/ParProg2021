```
[cb761027@login.lcc2 Assignment2]$ cg_annotate cachegrind.out.3055 ~/PP/Assignment2/a2a.c
perl: warning: Setting locale failed.
perl: warning: Please check that your locale settings:
        LANGUAGE = (unset),
        LC_ALL = (unset),
        LANG = "C.UTF-8"
    are supported and installed on your system.
perl: warning: Falling back to the standard locale ("C").
--------------------------------------------------------------------------------
I1 cache:         32768 B, 64 B, 8-way associative
D1 cache:         32768 B, 64 B, 8-way associative
LL cache:         6291456 B, 64 B, 24-way associative
Command:          ./a2a
Data file:        cachegrind.out.3055
Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Events shown:     Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Thresholds:       0.1 100 100 100 100 100 100 100 100
Include dirs:
User annotated:   /home/cb76/cb761027/PP/Assignment2/a2a.c
Auto-annotation:  off

--------------------------------------------------------------------------------
        Ir I1mr ILmr        Dr   D1mr   DLmr      Dw   D1mw   DLmw
--------------------------------------------------------------------------------
14,312,585  696  691 6,888,837 62,552 62,243 503,734 31,142 31,115  PROGRAM TOTALS

--------------------------------------------------------------------------------
        Ir I1mr ILmr        Dr   D1mr   DLmr      Dw   D1mw   DLmw  file:function
--------------------------------------------------------------------------------
14,216,509   16   16 6,863,527 61,253 61,179 490,739 30,626 30,626  /home/cb76/cb761027/PP/Assignment2/a2a.c:main
    22,277   14   14     7,274    183    135   3,419      6      4  ???:do_lookup_x
    18,231   43   43     4,955    662    611   2,232    253    242  ???:_dl_relocate_object
    18,200   10   10     3,636    100     91   2,117      8      5  ???:_dl_lookup_symbol_x

--------------------------------------------------------------------------------
-- User-annotated source: /home/cb76/cb761027/PP/Assignment2/a2a.c
--------------------------------------------------------------------------------
        Ir I1mr ILmr        Dr   D1mr   DLmr      Dw   D1mw   DLmw

         .    .    .         .      .      .       .      .      .  #include <stdlib.h>
         .    .    .         .      .      .       .      .      .
        10    1    1         0      0      0       7      0      0  int main() {
         .    .    .         .      .      .       .      .      .
         1    0    0         0      0      0       1      0      0      size_t n = 700;
         .    .    .         .      .      .       .      .      .
        54    3    3         2      0      0       3      0      0      int32_t a[n][n];
        62    5    5         6      0      0      13      0      0      int32_t b[n][n];
        62    5    5         7      0      0      13      0      0      int32_t c[n][n];
         .    .    .         .      .      .       .      .      .
     2,805    1    1     2,102      0      0       1      0      0      for(size_t i = 0; i < n; ++i) {
 1,963,500    0    0 1,471,400      0      0     700      0      0          for(size_t j = 0; j < n; ++j) {
12,250,000    1    1 5,390,000 61,251 61,179 490,000 30,626 30,626              c[i][j] = a[i][j] * b[i][j];
         .    .    .         .      .      .       .      .      .          }
         .    .    .         .      .      .       .      .      .      }
         .    .    .         .      .      .       .      .      .
         5    0    0         3      1      0       1      0      0      c[0][0]++;
         .    .    .         .      .      .       .      .      .
         2    0    0         0      0      0       0      0      0      return EXIT_SUCCESS;
         8    0    0         7      1      0       0      0      0  }

--------------------------------------------------------------------------------
Ir I1mr ILmr  Dr D1mr DLmr Dw D1mw DLmw
--------------------------------------------------------------------------------
99    2    2 100   98   98 97   98   98  percentage of events annotated
```