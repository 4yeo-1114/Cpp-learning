---
description: 查看最近的对话历史记录
---

用户想要查看之前的对话历史。请执行以下步骤：

1. 读取文件 `C:\Users\zzq\.claude\history.jsonl`
2. 解析其中每一行 JSON，提取 `display`、`timestamp` 和 `sessionId` 字段
3. 将 `timestamp`（毫秒时间戳）转换为可读日期时间
4. 按时间倒序排列，展示最近 15 条记录
5. 对每条记录，显示：序号、日期时间、对话摘要（display 字段）、sessionId
6. 在末尾提示用户：如需查看某次对话的完整内容，可以打开对应的 session 文件，路径为 `C:\Users\zzq\.claude\projects\D--C---project\<sessionId>.jsonl`

展示格式示例：
```
# 对话历史（最近 15 条）

1. [2026-06-04 14:30] /init — sessionId: abc123...
2. [2026-06-04 14:15] 你好 — sessionId: def456...
...
```

如果 history.jsonl 文件不存在或为空，请告知用户。
