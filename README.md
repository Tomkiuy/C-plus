# C-plus

C++ 入門練習範例。

| 檔案 | 主題 | 說明 |
|---|---|---|
| `Alias.cpp` | 參考（引用） | `int& M = N;` 讓 `M` 成為 `N` 的別名，改其中一個，另一個也跟著變 |
| `Array.cpp` | 一維陣列 | 修改元素、計算總和、平均與最大值；示範直接 `cout << P` 印出的是陣列位址 |
| `BinarySearch.cpp` | 模板與搜尋 | 產生 1000 個 1–1000 的亂數，以模板 `Bubble()` 氣泡排序，再以模板 `BiSearch()` 二分搜尋 500 |

## 編譯與執行

```sh
g++ -Wall -o Alias Alias.cpp && ./Alias
g++ -Wall -o Array Array.cpp && ./Array
g++ -Wall -o BinarySearch BinarySearch.cpp && ./BinarySearch
```

`BinarySearch` 結束前會等待按下 Enter。Windows 上可用 Visual Studio 或 MinGW 的 `g++` 編譯。

## 測試

```sh
g++ -Wall -Wextra -fsanitize=address,undefined -g -I. -o test_algorithms tests/test_algorithms.cpp && ./test_algorithms
./tests/test_output.sh
```

測試案例清單見 [`TEST_PLAN.md`](TEST_PLAN.md)。
