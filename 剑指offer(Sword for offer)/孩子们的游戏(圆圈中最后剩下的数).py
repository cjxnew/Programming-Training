'''
// 每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
// HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
// 首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
// 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再
// 回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一
// 个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
// 请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
// 如果没有小朋友，请返回-1
'''
'''
// 网友的方法，用数学归纳法。
// 用数学归纳法推导出递推公式，设有n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，
// 剩下的人继续从0开始报数。令f[i]表示i个人时最后胜利者的编号，则有递推公式：
// f[1]=0;
// f[i]=(f[i-1]+m)%i; (i>1)
// 通过递推公式即可求得f[n]。
'''
def LastRemaining_Solution(self, n, m):
    # write code here
    if n == 0:
        return -1
    s = 0
    for i in range(2, n+1):
        s = (s+m) % i
    return s
    
