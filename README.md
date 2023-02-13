# fsu
Fsu means "fast su" in Windows.
Fsu 意味着"快速的su"

# Recommand adding fsu to Environment PATH
# 建议将fsu添加到系统变量



fsu aims to realize the working mode of windows close to linux's sudo,
Solve the problem that windows needs to move the mouse or type a series of commands to elevate the privileges,
The privilege escalation of the command line software is realized by invoking UAC.
fsu 旨在实现windows接近linux的sudo的工作模式，
解决windows提升权限需要移动鼠标或者敲一大串命令的问题，
通过调用UAC的方式来实现命令行软件的权限提升。




Opens WindowsTerminal when no options are available
At the same time, the software supports passing the current working path to cmd and powershell
没有可选项时会打开WindowsTerminal
同时该软件支持了传递当前的工作路径到cmd和powershell以及WindowsTerminal

## usage:
## 使用:

fsu [command] [params]
fsu [命令] [参数]


## sample:
## 示例：

fsu wt
// Open WindowsTerminal
// 打开WindowsTerminal

fsu wt cmd
// Open cmd in WindowsTerminal, This action will open a window.
// 用windowsTerminal 打开 cmd,此操作会打开一个窗口

fsu cmd wt
// Open WindowsTerminal use cmd ,This action will open two windows,
// 用 cmd 打开 windowsTerminal,此操作会打开两个窗口

fsu calc
// Open calculator
// 打开计算器

