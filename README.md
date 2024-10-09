# Fractol
## `Grade: 125/100`
最適化オプション（-O3）などである程度なめらかに動くようにし，bonusにも対応させた．


各ピクセルごとに計算をし，完成した画像を貼り付けるようなイメージ．ピクセルの限界までズームできることは検証済み
以下のようにクローンするとsubmoduleも取り込まれる．ただし、Linux環境でしか実行できないので注意．42以外の環境だとpathを通したりする必要があるかも.

```
git clone --recursive https://github.com/cimura/fractol.git
```
### マンデルブロ集合

![mandel](https://github.com/user-attachments/assets/dde54a38-f030-4da9-9c96-095929ca81c7)

---

### ジュリア集合
マウスの動きに合わせて形が変わる実装

![julia-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/42a76307-5c2e-4935-8123-6c0a844a4d92)

---

### Burning ship
bonusとして実装した

![ship](https://github.com/user-attachments/assets/0991a40e-23bc-4d5f-95ef-7c2680d919b9)

