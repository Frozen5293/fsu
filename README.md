# fsu

Fsu means "fast su" in Windows.</br>
Fsu 意味着"快速的su"</br>

<b>Recommand adding fsu to Environment PATH</b></br>
<b>建议将fsu添加到环境变量</b></br>
  
fsu aims to realize the working mode of windows close to linux's sudo,</br>
Solve the problem that windows needs to move the mouse or type a series of commands to elevate the privileges,</br>
The privilege escalation of the command line software is realized by invoking UAC.</br>
fsu旨在实现windows接近linux的sudo的工作模式，</br>
解决windows提升权限需要移动鼠标或者敲一大串命令的问题，</br>
通过调用UAC的方式来实现命令行软件的权限提升。</br>




Opens WindowsTerminal when no options are available</br>
At the same time, the software supports passing the current working path to cmd and powershell</br>

没有可选项时会打开WindowsTerminal</br>
同时该软件支持了传递当前的工作路径到cmd和powershell以及WindowsTerminal</br>

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
  
 
## 已知问题
命令太长会崩溃
在wt终端中不能传递 -d -w</br>
在pwsh中 不能传递-NoExit -wd -Command</br>
在cmd中不能传递  -c -k</br>
## 解决方法
套娃
  fsu cmd cmd /c wt

