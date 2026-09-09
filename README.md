# C / C++ 算法与数据结构学习仓库

收录 C 数据结构实现、C++ 算法题、洛谷/OJ 练习与 C++ 课堂作业。按来源与主题分类，保留不同版本及学习笔记。

## 目录结构

```text
.
├── data_structures/       数据结构：C 实现为主，保留 C++ 混合示例
│   ├── sequential_list/   顺序表
│   ├── linked_list/       单链表、双向链表、循环链表、多项式
│   ├── stack/             数组栈、链栈、表达式与出栈模拟
│   ├── queue/             循环队列、链队列及应用题
│   ├── tree/              二叉树、线索树、BST、AVL、哈夫曼树
│   ├── heap/              C 小根堆、C++ priority_queue
│   ├── graph/             遍历、拓扑排序、关键路径、最短路、最小生成树
│   ├── string/            KMP、朴素匹配
│   ├── matrix/            矩阵重塑
│   └── generalized_list/  广义表
├── algorithms/            原 leecode：LeetCode 风格及其他算法练习
│   ├── array/             数组
│   ├── binary_search/     二分查找
│   ├── divide_and_conquer/ 分治
│   ├── two_pointers/      双指针
│   ├── sliding_window/    滑动窗口
│   ├── dp/                动态规划与复习笔记
│   ├── greedy/            贪心
│   ├── hash/              哈希表
│   ├── linked_list/       链表与 LRU
│   ├── tree/              二叉树
│   ├── graph/             图搜索、拓扑排序
│   ├── matrix/            矩阵
│   └── sorting/           排序
├── luogu/                 洛谷及原目录中的 OJ 练习，C/C++ 混合
│   ├── binary_search/     二分查找、二分答案
│   ├── search/            搜索
│   ├── recursion/         递归及伪代码笔记
│   ├── divide_and_conquer/ 分治
│   ├── dp/                动态规划、记忆化搜索
│   ├── greedy/            贪心
│   ├── sorting/           排序
│   ├── string/            字符串
│   ├── string_matching/   KMP、BF 匹配
│   ├── hash/              映射、计数
│   ├── two_pointers/      双指针
│   ├── sliding_window/    滑动窗口
│   ├── enumeration/       枚举
│   ├── simulation/        模拟、字符画
│   ├── matrix/            矩阵
│   └── math/              日期计算
├── cpp_study/             C++ 课堂练习
│   ├── classes/           类、运算符重载、组合
│   ├── inheritance/       继承、多态、虚函数
│   ├── memory/            拷贝控制、字符串与矩阵内存
│   ├── pointers/          智能指针
│   ├── templates/         模板
│   ├── stl/               容器、迭代器、排列、格式化
│   ├── algorithms/        课堂算法练习
│   └── exams/             考试练习与速查笔记
├── build/                 编译输出目录（Git 忽略，旧 exe 已清理）
├── docs/                  文件清单、检查记录、整理计划
├── .vscode/               编辑器与 IntelliSense 配置
├── .claude/               Claude 本地指令
├── CLAUDE.md              Claude 学习助手规范
├── AGENTS.md              通用 agent 规范
└── README.md              仓库入口
```

`data_structures/` 各主题下的 `practice/` 保留原“手写”练习来源，`problems/` 保留原“题目”来源。同题多份实现保留，使用主题目录或 `_v2` 区分。

| 范围 | C | C++ | 笔记 |
|---|---:|---:|---:|
| `algorithms/` | 1 | 66 | 2 |
| `cpp_study/` | 0 | 39 | 3 |
| `data_structures/` | 56 | 9 | 2 |
| `luogu/` | 52 | 29 | 3 |

## 技术环境与编译

- C 使用 `.c`，以 C17 检查；C++ 使用 `.cpp`，以 C++23 检查。
- 所有学习文件使用 UTF-8；路径使用 ASCII 英文和下划线，避免空格及中文路径兼容问题。
- Windows VS Code 当前 IntelliSense 配置为 MSVC。MSVC 命令请在已加载开发环境的终端执行，显式加 `/utf-8`。
- C++：`cl /std:c++latest /EHsc /utf-8 path/to/file.cpp /Fe:program.exe`，或 `g++ -std=c++23 path/to/file.cpp -o program.exe`。
- C：`cl /TC /std:c17 /utf-8 path/to/file.c /Fe:program.exe`，或 `gcc -std=c17 path/to/file.c -o program.exe`；GCC 的数学函数可能需要 `-lm`。
- 无统一构建系统，按文件编译。部分文件只有 OJ 函数或 `Solution` 类，缺少 `main`；部分包含多份解法、教学片段或原有错误，不能宣称每个文件都可直接运行。
- `bits/stdc++.h`、变长数组等 GNU 特性不一定支持 MSVC；文件改名不能解决这些原有兼容问题。
- 仅检查语法可用 `gcc -std=c17 -fsyntax-only file.c` / `g++ -std=c++23 -fsyntax-only file.cpp`，这不等于链接成功或算法正确。

## 导航

- [完整文件清单与新旧路径](docs/file_catalog.md)
- [整理验证记录](docs/organization_checks.md)
- [Claude 规范](CLAUDE.md)
- [Agent 规范](AGENTS.md)
- [旧编译产物清理记录](docs/legacy_binaries.md)
