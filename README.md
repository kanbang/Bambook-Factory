# BambookFactory
Bambook Factory 锦书工厂

当前版本为0.9.4 (20110301) 

![Main window](https://github.com/zhanzushun/BambookFactory/blob/master/screenshot/MainWindow.jpg)
![Reader](https://github.com/zhanzushun/BambookFactory/blob/master/screenshot/Reader.jpg)

锦书工厂是盛大SNB格式的图书管理器，它可以自动检测Bambook连接状态，同步管理PC端个人书库和Bambook中的电子书，也可以导入PDF和TXT等其他格式图书。 

【主要功能】 
- PC端个人书库管理。包括：PDF导入、TXT章节剪刀、添加和删除SNB。 
- PC端个人书库与Bambook同步。 
- PC端的电子书阅读器，不需要用Bambook就可以在PC上直接看书。 

【特点】 
- 使用用多线程自动检测锦书连接状态 
- 卡通简易的操作界面，打开可立即使用，无需查看任何帮助 
- 类似真实书本的阅读界面带来良好的用户体验，可在同步之前先试读一下 
- 支持多语言切换, 在全英文操作系统中正确显示中文 
- 正确安装运行时库, 没有测出任何兼容性问题, 如UAC, 64位兼容性问题, 乱码问题, 保证程序稳定运行. 
- 集成'PDF终结者'功能, 以良好的文本格式导入PDF, 同时可导入PDF中的图片 
- 集成'TXT剪刀终结者'功能, 智能分章, 并可编辑分章 
- Txt智能分章结果不满意时, 可以放宽条件再次智能分章 

【PDF导入, 特点】 
- 图片和文字分别提取, 重排 
- 智能处理文本换行 
- 智能处理目录 
- 智能分章 
- 可编辑智能分章的结果 
- 可处理多列的PDF 
- 可按页显示图片, 先显示该页图片, 然后显示该页文本 

【TXT章节剪刀, 特点】 
- 智能分章 
- 可编辑智能分章的结果 
- 如果智能分章结果不正确, 可以选择放宽条件重新分章 
- 可以整本书只生成一章 

【更新历史】 
- 0.9.4 (20100301) 
 - 对Txt 智能分章结果不满意时, 可以放宽条件再次智能分章 
 - 也可以设置整本书为一章. 
- 0.9.32 (20100214) 
 - 修正章节编辑器的一个bug: 在Cancel的情况下会Crash 
 - 修正章节提取的一个bug: 超过一百章提取失败. 
- 0.9.31 (20110127) 
 - 集成TXT剪刀终结者, 智能导入txt文本文件 0.9.20 (20110126) 
 - 导入PDF, 增加按页分章功能 
- 0.9.10 (20110124) 
 - 集成PDF终结者功能, 现在能以良好的文本格式导入PDF了, 同时支持图片. 
- 0.9.03 (20110123) 
 - 在全英文操作系统中正确显示中文. (云梯则是乱码). 
 - 修改阅读器bug: 复杂的xml格式不能被正确读取. 
 - 根据用户反馈, 修改锦书默认目录至Documents下. 
- 0.9.02 (20110110) 
 - 修改严重bug: 安装到"Program files"目录下, 以非Admin时不能正确执行的问题. 
- 0.9.01 (20110109). 
 - 修改bug：状态栏上的进度条不显示. 
- 0.9 
 - 第一个版本
