# AWD-loop-trojan

一个简单的用于AWD比赛中受控机发送flag和选手机接收flag的框架，由两个部分组成：

**client**

用于受控机。受控机运行`./trojan`后，程序会更改进程名从而难以被发现，并向receiver发送flag。每隔一段时间后fork新的子进程递归地进行上述操作。进程名和时间可在源代码里自定义。

**receiver**

接收flag并保存



