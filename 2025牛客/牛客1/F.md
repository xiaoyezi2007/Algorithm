# 球面公式

#### 球面三角形面积

$$
S = \alpha +\beta +\gamma -\pi
$$

在面积为1时成立，面积不为1时记得额外乘半径的平方。（通常乘这里的S叫做球面超）

![image-20250719140303931](C:/Users/Henson/AppData/Roaming/Typora/typora-user-images/image-20250719140303931.png)

#### 球面角

$$
\cos a = \cos b\cos c + \sin b\sin c\cos A
$$

$$
\cos b = \cos a\cos c + \sin a\sin c\cos B
$$

$$
\cos c = \cos a\cos b + \sin a\sin b\cos C
$$

对于球面三角形ABC，球面角ABC的对边是abc。这里a表示球面边a所对应的求心角大小（不要乘半径），其余同理。

证明：

![image-20250719141803807](C:/Users/Henson/AppData/Roaming/Typora/typora-user-images/image-20250719141803807.png)

其中最后一步转化使用了Langrange恒等式：

![image-20250719141853226](C:/Users/Henson/AppData/Roaming/Typora/typora-user-images/image-20250719141853226.png)

或者也可以用正弦：
$$
s = \frac{1}{2}\left ( a+b+c \right )  
$$

$$
\sin \left ( \frac{1}{2}A  \right ) =\sqrt{\frac{\sin \left ( s-b \right ) \sin \left (s-c  \right ) }{\sin b\sin c} } 
$$

其余角同理。

#### 球角锥

$$
V=SR/3
$$



S为球面积

#### 球面扇形面积

$$
S=2\alpha\sin^2\frac{r}{2}
$$

$\alpha$为扇形的球面角，r为扇形的球面半径所对的球心角。

证明：可以看作一个球冠截取了$\alpha /2\pi$的部分

#### 球冠面积

$$
2\pi r^2(1-cos\theta)
$$

这里$\theta$指的是北极到球冠底的夹角



#### 题解：

对于d很大，满足disST+2d>=2pir的情况，则总面积为4pir^2。

对于d很小，小于pir/2的情况，可以视作是一个半径为d的球冠，加上一段带状区域。

整个带状区域面积：4pir^2*(dis/2pir)。

上面不取的部分可以视作一个扇形，因此总面积正比于(1-sin^2(r/2)) ，正比于cosr，正比于sinr。

所以把整个带状面积乘sind/r即是中间部分的答案。

对于其他的d，必然是到S和T距离小于d，因此球两个球冠的交即可。