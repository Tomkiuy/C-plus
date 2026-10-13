# 測試計畫

> 狀態：**已實作**（`tests/test_algorithms.cpp`、`tests/test_output.sh`）　｜　適用分支：`fix-binarysearch-readme`

## 1. 目標

- 確認 `BiSearch()`、`Bubble()`、`Exchange()` 在一般情況與邊界情況下結果正確
- 防止已修正的 `Bubble()` 陣列越界問題再次出現
- 確認 `Alias.cpp`、`Array.cpp` 的示範輸出符合預期

## 2. 範圍

| 對象 | 類型 | 測試方式 |
|---|---|---|
| `BiSearch()` | 函式模板 | 單元測試 |
| `Bubble()` | 函式模板 | 單元測試 + 記憶體檢查 |
| `Exchange()` | 函式模板 | 單元測試 |
| `Alias.cpp` | 示範程式 | 比對輸出 |
| `Array.cpp` | 示範程式 | 比對輸出 |

**不在範圍內**：`BinarySearch.cpp` 的 `main()`（使用亂數、輸出不固定）、效能測試。

## 3. 前置工作

1. ✅ 將 `BiSearch`、`Bubble`、`Exchange`、`RandI` 從 `BinarySearch.cpp` 移到 `BinarySearch.h`
2. ✅ `BinarySearch.cpp` 改為 `#include "BinarySearch.h"`，行為不變
3. ✅ 新增 `tests/test_algorithms.cpp`，使用標準 `assert`，不引入外部框架

## 4. 測試案例

### 4.1 `BiSearch()`：二分搜尋

固定測試資料：`V = {1, 3, 5, 7, 9}`，`N = 5`

| 編號 | 案例 | 輸入 | 預期回傳 |
|---|---|---|---|
| BS-01 | 找中間元素 | Key = 5 | `2` |
| BS-02 | 找第一個元素 | Key = 1 | `0` |
| BS-03 | 找最後一個元素 | Key = 9 | `4` |
| BS-04 | 小於最小值 | Key = 0 | `-1` |
| BS-05 | 介於兩元素之間 | Key = 4 | `-1` |
| BS-06 | 大於最大值 | Key = 10 | `-1` |
| BS-07 | 單一元素，找得到 | `{5}`，Key = 5 | `0` |
| BS-08 | 單一元素，找不到 | `{5}`，Key = 6 | `-1` |
| BS-09 | 空陣列 | N = 0 | `-1` |
| BS-10 | 重複值 | `{2, 2, 2}`，Key = 2 | `0`～`2` 任一位置，且 `V[回傳值] == 2` |
| BS-11 | `double` 型別 | `{1.5, 2.5, 3.5}`，Key = 2.5 | `1` |
| BS-12 | `char` 型別 | `{'a', 'c', 'e'}`，Key = 'e' | `2` |

### 4.2 `Bubble()`：氣泡排序

| 編號 | 案例 | 輸入 | 預期結果 |
|---|---|---|---|
| BB-01 | 已排序 | `{1, 2, 3, 4, 5}` | 不變 |
| BB-02 | 完全反序 | `{5, 4, 3, 2, 1}` | `{1, 2, 3, 4, 5}` |
| BB-03 | 全部相同 | `{7, 7, 7}` | 不變 |
| BB-04 | 含重複值 | `{3, 1, 3, 2, 1}` | `{1, 1, 2, 3, 3}` |
| BB-05 | 含負數 | `{0, -2, 5, -9}` | `{-9, -2, 0, 5}` |
| BB-06 | 空陣列 | N = 0 | 不崩潰 |
| BB-07 | 單一元素 | `{42}` | 不變 |
| BB-08 | 1000 個亂數 | `RandI(1000)` × 1000 | 由小到大，且與 `std::sort` 的結果完全相同 |
| BB-09 | 越界回歸測試 | 同 BB-08，以 AddressSanitizer 執行 | 無 `stack-buffer-overflow` 錯誤 |

### 4.3 `Exchange()`：交換

| 編號 | 案例 | 輸入 | 預期結果 |
|---|---|---|---|
| EX-01 | 交換 `int` | `a = 1, b = 2` | `a = 2, b = 1` |
| EX-02 | 交換 `string` | `"foo", "bar"` | `"bar", "foo"` |
| EX-03 | 與自己交換 | `Exchange(a, a)`，`a = 3` | `a = 3` |

### 4.4 示範程式輸出

| 編號 | 程式 | 檢查內容 |
|---|---|---|
| OUT-01 | `Alias` | 依序出現 `M 的值原來是:10`、`M 的值目前是:5`、`N 的值目前是:2` |
| OUT-02 | `Array` | 陣列為 `3.2 39.8 40.5 6.4 41.2` |
| OUT-03 | `Array` | 和 `131.1`、平均值 `26.22`、最大值 `41.2` |
| OUT-04 | `Array` | 最後一行以 `0x` 開頭（位址值每次不同，只檢查格式） |

## 5. 執行方式

```sh
# 單元測試（含記憶體檢查）
g++ -Wall -Wextra -fsanitize=address,undefined -g -I. \
    -o test_algorithms tests/test_algorithms.cpp && ./test_algorithms

# 示範程式輸出（OUT-01～04）
./tests/test_output.sh
```

全部通過時分別輸出 `All tests passed` 與 `All output tests passed`，結束碼為 `0`。單元測試失敗時 `assert` 會中止並顯示失敗的行號；輸出測試失敗時會顯示 `FAIL` 與案例編號。

## 6. 完成標準

- [x] 第 4 節所有案例皆通過
- [x] 在 AddressSanitizer 與 UndefinedBehaviorSanitizer 下沒有錯誤
- [x] 以 `-Wall -Wextra` 編譯沒有警告
- [ ] （選用）GitHub Actions 在每次 push 時自動執行

## 7. 風險與注意事項

| 項目 | 說明 | 處理方式 |
|---|---|---|
| 亂數不固定 | BB-08 每次的資料都不同 | 測試中固定 `srand(12345)`，讓結果可重現 |
| 重複值的回傳位置 | 二分搜尋不保證回傳第一個符合的位置 | BS-10 只檢查回傳的位置值相同，不要求特定索引 |
| 浮點數輸出 | `Array` 的平均值依賴 `cout` 的預設精度 | 比對字串 `26.22`，不比對完整浮點數 |
| 平台差異 | Sanitizer 在 MSVC 上支援有限 | 記憶體檢查以 Linux / macOS 的 g++ 或 clang++ 為準 |
