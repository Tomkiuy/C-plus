#!/bin/sh
# test_output.sh : 比對 Alias、Array 的輸出
# 案例編號對應 TEST_PLAN.md 第 4.4 節
set -e
cd "$(dirname "$0")/.."
BIN=$(mktemp -d)
trap 'rm -rf "$BIN"' EXIT

g++ -Wall -Wextra -o "$BIN/Alias" Alias.cpp
g++ -Wall -Wextra -o "$BIN/Array" Array.cpp
"$BIN/Alias" > "$BIN/alias.txt"
"$BIN/Array" > "$BIN/array.txt"

check() { # 編號 檔案 要找的字串
	if grep -qF -- "$3" "$BIN/$2"; then
		echo "PASS $1"
	else
		echo "FAIL $1: 找不到「$3」"
		exit 1
	fi
}

check OUT-01 alias.txt "M 的值原來是:10"
check OUT-01 alias.txt "M 的值目前是:5"
check OUT-01 alias.txt "N 的值目前是:2"
check OUT-02 array.txt "3.2 39.8 40.5 6.4 41.2"
check OUT-03 array.txt "陣列 P 的和是: 131.1  平均值是: 26.22"
check OUT-03 array.txt "陣列 P 的最大值是: 41.2"
check OUT-04 array.txt "直接將 P 輸出的結果是: 0x"
echo "All output tests passed"
