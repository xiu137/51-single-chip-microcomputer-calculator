# 51-single-chip-microcomputer-calculator

## 单片机计算器

**按照题干要求，代码支持1位小数运算和有限的连续运算**

num1 和num2用来记录输入的两个输入的数字

当按键输入为+-*/时，根据目前正在输入的数字进行切换，如果正在输入num1，且记录运算符号并切换为输入num2，否则将之前运算的结果设置为num1并等待num2输入

输入等于号则输出运算结果