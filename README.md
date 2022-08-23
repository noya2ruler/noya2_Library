# Noya2-Library

## Formal Power Series

### Numeric Theorem Transform

#### NTT.hpp

modint を include して使う. 四則演算に加え <code>modint::mod()</code>, <code>modint::inv()</code> が必要.

#### <code>void NTT\<m\>::FFT(vector\<mint\> &a)</code> 
<p> <code>a</code> の中身が $\bmod m$ 上で高速フーリエ変換される. </p>

<p><a href = "https://trap.jp/post/1386/" target = "blank"> tatyamさんの記事 </a> でFFTを理解した.</p>
<p><a href = "https://mtsaka.github.io/library/Math/convolution/ntt.hpp" target = "blank"> MtSaka's Library </a> を大きく参考にした.</p>

え〜、全然きれいにまとまる気がしないです。
