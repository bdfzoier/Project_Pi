# 计算pi的值（2018学段汇报）
## 关于这次学段汇报活动的须知
### 项目论文编辑网址:
(戳这)[https://etherpad.net/p/projectpi]
### 任务分配:

**gyh:**
- [ ] 整数高精度加减乘除 **working**
- [x] 随机扔点算法的double实现及优化
- [ ] BBP高精度版优化&运行

**ltt:**
- [x] 高精度小数加减乘
- [ ] 论文实现

**xzh:**
- [ ] 高精度小数乘除 **working**
- [ ] 高精度BBP整合

**zzeh:**
- [ ] 其他算法的对比 **working**
- [ ] BBPdouble 实现
### 关于代码:
1. 使用c风格字符串，nostring
2. 禁止使用goto
3. 最终版高精度使用struct封装
4. 读入输出使用scanf,printf,或者getchar,putchar
5. 花括号风格如下:
```cpp
void func(){
	while(i<100){
		printf("%d ",&i);
		i++	
	}
}
```
6. 空格风格不限

# Links:

https://blog.csdn.net/zxy160/article/details/78470702

https://wenku.baidu.com/view/716dbac708a1284ac85043bf.html

http://www.cppfans.com/articles/basecalc/c_pi_10000.asp

https://blog.csdn.net/qin_zhangyongheng/article/details/8033942
