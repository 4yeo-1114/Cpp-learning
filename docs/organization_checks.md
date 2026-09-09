# 整理验证记录

日期：2026-09-09。基准是用户已初步分类后的工作树，未从 Git HEAD 恢复文件，未提交或推送。

## 文件与内容

- 262 个学习文件逐一对应，整理后无丢失、覆盖或多余文件；当前清单见 [file_catalog.md](file_catalog.md)。
- 252 个源码文件（109 C、143 C++），每个新增一行顶部用途注释。逐文件核验：去掉新增第一行后，正文与原文件按原编码解码的内容完全相同，包括原有注释、字符串和换行。
- 120 个 GB18030/GBK 文件转为 UTF-8，其余保持 UTF-8；未发现 U+FFFD 替换字符或常见二次解码乱码。修复的是编码显示问题，没有猜写注释。
- 3 份伪装成 `.cpp` 的纯笔记/伪代码转为 Markdown 并保留全文，共 10 份笔记。
- 学习文件和目录路径均为 ASCII，无空格；C++ 引用、STL、bool、重载或结构体类型用法依赖 C++ 的文件保留 `.cpp`。
- 原始文件另存仓库外 `D:/codex/repo_organization_backup_20260909/`。

- 130 个旧 `.exe` 归档校验后，已按用户后续要求全部删除；历史清理记录见 [legacy_binaries.md](legacy_binaries.md)。空归档目录保留。

## 语法检查

采用本机 GCC/G++ 15.2.0（MSYS2 UCRT64），逐文件执行 `gcc -std=c17 -fsyntax-only -fmax-errors=3 <file.c>` 或 `g++ -std=c++23 -fsyntax-only -fmax-errors=3 <file.cpp>`。

对整理前正文的 UTF-8 暂存副本和最终源码使用相同目标语言比较：**252 个文件，180 个通过，72 个失败，前后通过/失败状态完全一致，无超时**。对于从 `.cpp` 改为 `.c` 且 C 检查失败的文件，另外检查原 C++ 模式；若原 C++ 模式通过则保留 `.cpp`，避免扩展名变化引入失败。

通过仅表示语法检查成功，不代表具有 `main`、链接成功、运行安全或答案正确；空练习 `algorithms/binary_search/search_matrix.cpp` 仍为空练习，仅有新增头注释。未执行输入输出样例或 MSVC 编译。

以下为原正文中的语法失败，包含多份解法共存、缺少依赖的片段及原有错误。本次只整理，不改算法和正文；需使用对应文件时再分别处理。

| 文件 | 首条诊断 |
|---|---|
| [cpp_study/stl/next_permutation.cpp](../cpp_study/stl/next_permutation.cpp) | expected '}' at end of input |
| [cpp_study/inheritance/inheritance_exercises.cpp](../cpp_study/inheritance/inheritance_exercises.cpp) | redefinition of 'int main()' |
| [cpp_study/memory/my_string.cpp](../cpp_study/memory/my_string.cpp) | cannot bind non-const lvalue reference of type 'MyString&' to an rvalue of type 'MyString' |
| [cpp_study/classes/student_records.cpp](../cpp_study/classes/student_records.cpp) | redefinition of 'class Student' |
| [cpp_study/classes/matrix.cpp](../cpp_study/classes/matrix.cpp) | redefinition of 'int main()' |
| [algorithms/array/first_missing_positive.cpp](../algorithms/array/first_missing_positive.cpp) | redefinition of 'class Solution' |
| [algorithms/array/max_subarray_v2.cpp](../algorithms/array/max_subarray_v2.cpp) | expected ';' after class definition |
| [algorithms/array/product_except_self.cpp](../algorithms/array/product_except_self.cpp) | redefinition of 'class Solution' |
| [algorithms/array/rotate.cpp](../algorithms/array/rotate.cpp) | 'len' was not declared in this scope; did you mean 'mblen'? |
| [algorithms/binary_search/rotated_search.cpp](../algorithms/binary_search/rotated_search.cpp) | redefinition of 'class Solution' |
| [algorithms/binary_search/two_array_median.cpp](../algorithms/binary_search/two_array_median.cpp) | redefinition of 'class Solution' |
| [algorithms/binary_search/search_range.cpp](../algorithms/binary_search/search_range.cpp) | redefinition of 'int find_firsttarget(std::vector<int>&, int)' |
| [algorithms/dp/equal_partition.cpp](../algorithms/dp/equal_partition.cpp) | redefinition of 'class Solution' |
| [algorithms/dp/climb_stairs.cpp](../algorithms/dp/climb_stairs.cpp) | redefinition of 'class Solution' |
| [algorithms/dp/longest_increasing_subsequence.cpp](../algorithms/dp/longest_increasing_subsequence.cpp) | redefinition of 'class Solution' |
| [algorithms/dp/longest_valid_parentheses.cpp](../algorithms/dp/longest_valid_parentheses.cpp) | redefinition of 'class Solution' |
| [algorithms/dp/perfect_squares.cpp](../algorithms/dp/perfect_squares.cpp) | redefinition of 'class Solution' |
| [algorithms/dp/trap.cpp](../algorithms/dp/trap.cpp) | redefinition of 'class Solution' |
| [algorithms/dp/word_break.cpp](../algorithms/dp/word_break.cpp) | redefinition of 'class Solution' |
| [algorithms/graph/course_schedule.cpp](../algorithms/graph/course_schedule.cpp) | redefinition of 'class Solution' |
| [algorithms/graph/island_count.cpp](../algorithms/graph/island_count.cpp) | redefinition of 'class Solution' |
| [algorithms/greedy/merge_fruits.cpp](../algorithms/greedy/merge_fruits.cpp) | redefinition of 'int main()' |
| [algorithms/sliding_window/longest_unique_substring.cpp](../algorithms/sliding_window/longest_unique_substring.cpp) | redefinition of 'class Solution' |
| [algorithms/linked_list/lru_cache.cpp](../algorithms/linked_list/lru_cache.cpp) | redefinition of 'class LRUCache' |
| [algorithms/linked_list/copy_random_list.cpp](../algorithms/linked_list/copy_random_list.cpp) | redefinition of 'class Solution' |
| [algorithms/linked_list/sort_list.cpp](../algorithms/linked_list/sort_list.cpp) | redefinition of 'class Solution' |
| [algorithms/matrix/set_zeroes.cpp](../algorithms/matrix/set_zeroes.cpp) | redefinition of 'class Solution' |
| [algorithms/matrix/spiral_order.cpp](../algorithms/matrix/spiral_order.cpp) | redefinition of 'class Solution' |
| [algorithms/tree/validate_bst.cpp](../algorithms/tree/validate_bst.cpp) | redefinition of 'class Solution' |
| [algorithms/tree/diameter.cpp](../algorithms/tree/diameter.cpp) | redefinition of 'class Solution' |
| [algorithms/tree/flatten.cpp](../algorithms/tree/flatten.cpp) | redefinition of 'class Solution' |
| [algorithms/tree/level_order.cpp](../algorithms/tree/level_order.cpp) | redefinition of 'class Solution' |
| [algorithms/tree/lowest_common_ancestor.cpp](../algorithms/tree/lowest_common_ancestor.cpp) | redefinition of 'class Solution' |
| [algorithms/tree/path_sum.cpp](../algorithms/tree/path_sum.cpp) | redefinition of 'class Solution' |
| [luogu/binary_search/cubic_roots.cpp](../luogu/binary_search/cubic_roots.cpp) | redefinition of 'int main()' |
| [luogu/binary_search/find_position.c](../luogu/binary_search/find_position.c) | redefinition of 'by' |
| [luogu/hash/difference_pairs.cpp](../luogu/hash/difference_pairs.cpp) | conflicting declaration 'LL a [1000000]' |
| [luogu/enumeration/count_rectangles.cpp](../luogu/enumeration/count_rectangles.cpp) | redefinition of 'int main()' |
| [luogu/sliding_window/longest_unique_substring.c](../luogu/sliding_window/longest_unique_substring.c) | 'maxlen' undeclared (first use in this function); did you mean 'mblen'? |
| [luogu/math/weekday.c](../luogu/math/weekday.c) | implicit declaration of function 'leap' [-Wimplicit-function-declaration] |
| [luogu/string/caesar_cipher.c](../luogu/string/caesar_cipher.c) | implicit declaration of function 'strlen' [-Wimplicit-function-declaration] |
| [luogu/string/find_word.cpp](../luogu/string/find_word.cpp) | unterminated comment |
| [luogu/string/multiline_input.cpp](../luogu/string/multiline_input.cpp) | redefinition of 'int main()' |
| [luogu/string/reverse_number.cpp](../luogu/string/reverse_number.cpp) | redefinition of 'int main()' |
| [luogu/sorting/qsort_strings.c](../luogu/sorting/qsort_strings.c) | redefinition of 'compare_string' |
| [luogu/sorting/quickselect.c](../luogu/sorting/quickselect.c) | passing argument 1 of 'swap' from incompatible pointer type [-Wincompatible-pointer-types] |
| [luogu/sorting/qsort_integers.c](../luogu/sorting/qsort_integers.c) | redefinition of 'compare_ints' |
| [luogu/greedy/job_rewards.cpp](../luogu/greedy/job_rewards.cpp) | redefinition of 'std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int> > q' |
| [luogu/greedy/floor_tiling.cpp](../luogu/greedy/floor_tiling.cpp) | redefinition of 'int d [1000010]' |
| [luogu/dp/catalan_stack_sequences.c](../luogu/dp/catalan_stack_sequences.c) | expected ']' before ';' token |
| [luogu/dp/river_crossing.c](../luogu/dp/river_crossing.c) | redefinition of 'fx' |
| [luogu/dp/order_meals.cpp](../luogu/dp/order_meals.cpp) | redefinition of 'int main()' |
| [luogu/dp/wall_tiling.cpp](../luogu/dp/wall_tiling.cpp) | redefinition of 'int main()' |
| [luogu/dp/number_count.c](../luogu/dp/number_count.c) | expected ';' before 'long' |
| [luogu/dp/order_dishes.cpp](../luogu/dp/order_dishes.cpp) | conflicting declaration 'int f [10005]' |
| [luogu/dp/triangle_min_path.c](../luogu/dp/triangle_min_path.c) | implicit declaration of function 'memset' [-Wimplicit-function-declaration] |
| [luogu/recursion/alien_decoder.cpp](../luogu/recursion/alien_decoder.cpp) | redefinition of 'std::string jieya()' |
| [data_structures/stack/alien_decoder.cpp](../data_structures/stack/alien_decoder.cpp) | redefinition of 'struct stack' |
| [data_structures/tree/practice/binary_search_tree.c](../data_structures/tree/practice/binary_search_tree.c) | 'return' with no value, in function returning non-void [-Wreturn-mismatch] |
| [data_structures/tree/practice/inorder_threaded_tree.c](../data_structures/tree/practice/inorder_threaded_tree.c) | assignment to 'char' from 'char *' makes integer from pointer without a cast [-Wint-conversion] |
| [data_structures/tree/practice/iterative_preorder_inorder.c](../data_structures/tree/practice/iterative_preorder_inorder.c) | initialization of 'StackNode *' from incompatible pointer type 'StackNode * (*)()' [-Wincompatible-pointer-types] |
| [data_structures/tree/practice/iterative_postorder.c](../data_structures/tree/practice/iterative_postorder.c) | implicit declaration of function 'malloc' [-Wimplicit-function-declaration] |
| [data_structures/tree/practice/level_order.c](../data_structures/tree/practice/level_order.c) | implicit declaration of function 'pritnf'; did you mean 'printf'? [-Wimplicit-function-declaration] |
| [data_structures/tree/practice/preorder_threaded_tree.c](../data_structures/tree/practice/preorder_threaded_tree.c) | implicit declaration of function 'createTree'; did you mean 'creatTree'? [-Wimplicit-function-declaration] |
| [data_structures/linked_list/practice/doubly_linked_list.c](../data_structures/linked_list/practice/doubly_linked_list.c) | expected ';' before ')' token |
| [data_structures/linked_list/practice/reverse_list.c](../data_structures/linked_list/practice/reverse_list.c) | unknown type name 'node' |
| [data_structures/tree/practice/postorder_threaded_tree.c](../data_structures/tree/practice/postorder_threaded_tree.c) | implicit declaration of function 'getfirst'; did you mean 'getFirst'? [-Wimplicit-function-declaration] |
| [data_structures/linked_list/practice/recursive_merge.c](../data_structures/linked_list/practice/recursive_merge.c) | 'NUll' undeclared (first use in this function) |
| [data_structures/linked_list/practice/remove_nth_from_end.c](../data_structures/linked_list/practice/remove_nth_from_end.c) | implicit declaration of function 'malloc' [-Wimplicit-function-declaration] |
| [data_structures/queue/problems/line_removal.cpp](../data_structures/queue/problems/line_removal.cpp) | redefinition of 'int main()' |
| [data_structures/queue/problems/harbor.cpp](../data_structures/queue/problems/harbor.cpp) | conflicting declaration 'typedef struct node node' |
| [data_structures/queue/problems/josephus.cpp](../data_structures/queue/problems/josephus.cpp) | redefinition of 'int main()' |
