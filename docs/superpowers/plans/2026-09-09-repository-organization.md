# Repository Organization Implementation Plan

> For agentic workers: execute the verified file mapping sequentially and review each stage before completion.

**Goal:** 按来源、主题与实际语言整理学习文件，统一英文路径及 UTF-8，保留代码逻辑并同步 agent 文档。

**Architecture:** 以整理开始时的当前工作树为基准，一对一映射所有学习文件。源码仅新增顶部简注，旧编码无损转为 UTF-8；纯笔记转 Markdown。

**Tech Stack:** C17、C++23、Python 文件核验、GCC/G++ 语法检查。

## Global Constraints

- 保留用户现有未提交移动，不从 HEAD 恢复旧目录。
- 不删除不同版本，不修改算法、输入输出、既有可读正文注释。
- 不提交或推送。

## Tasks

- [x] 扫描全仓库学习文件、文档及编辑器配置，识别 UTF-8/GB18030。
- [x] 制定逐文件新旧路径映射，见 `docs/file_catalog.md`，检查大小写不敏感的路径冲突。
- [x] 暂存 UTF-8 源码，对 C/C++ 按实际语言进行语法基线检查。
- [x] 备份原文件，逐文件写入英文路径并验证，再移除原路径；只移除空目录。
- [x] 为源码新增顶部简注，将三个纯笔记/伪代码文件改为 Markdown。
- [x] 更新 CLAUDE.md、README.md，创建 AGENTS.md 和完整目录清单。
- [x] 验证正文一致、源文件数、UTF-8、ASCII 路径、文档链接及前后编译结果，记录原有失败。

- [x] 将 130 个旧可执行文件归档到 `build/legacy/`，逐个 SHA-256 校验，移除旧空目录。

- [x] 按用户后续要求删除全部 130 个旧 `.exe`，同步更新文档。空目录清理被自动审批策略拦截，目录保留。
