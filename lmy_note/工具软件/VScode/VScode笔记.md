1、使用VSCode和Git写笔记
解决痛点
❓ 图片的插入, 代码编辑器不像云笔记软件, 可以方便的上传图片, 且无需关心存储.
❓ 分享和演示
❓ 笔记管理, 搜索, 标签, 归档等功能

✔ 图片插入的问题, 使用VS-Picgo插件解决.
✔ 使用 vscode-reveal 插件实现演示, 使用 Marp 插件实现导出PDF
✖ 暂未解决, 也许可以在 Tree View 的位置开发一个管理笔记的 VSCode 扩展
https://blog.wzdxy.com/2019/05/note-with-vscode-and-git/

编写
建议采用 Hexo 的规范, 每篇笔记定义 Title, Tag, Data 和等信息.
这种笔记方式也是受到了 Hexo 的启发, 后续的完善也会更多的借鉴 Hexo.

---
title: 使用VSCode和Git写笔记
date: 2019-05-25 10:44:34
tags:
- VSCode
- Git
permalink: note-with-vscode-and-git
---

2、
vscode 做 markdown 笔记。
vscode 打开笔记文件夹。
用子文件夹做分类。
记得安装个 markdown-preview-echanced。
写个脚本，把笔记文件夹复制到 hexo 的_post 目录，并且对 md 文件进行一些预处理，然后就能发布。
