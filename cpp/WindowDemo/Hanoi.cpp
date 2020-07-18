/// 汉诺塔 程序编写 测试

/// ABC 三个盘， 要将 A 上的所有盘移动到C上， 问题 即将A上的所有盘借助B 移动到C上

/// 简化为 
///		1. 先将 A盘上 n-1 层移动到借助盘B上，
///		2. 将最终层 N 移动到 目标盘C上 
///		3. 将借助盘上的N-1 移动到C上
///
/// 其中最简化的问题为 n == 1 就不需要借助盘直接移动到 目标盘上

