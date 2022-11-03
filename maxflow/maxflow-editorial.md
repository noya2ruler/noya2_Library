# 最大流 (maxflow) の解説

## 参考資料

http://hos.ac/slides/20150319_flow.pdf

## 議論が十分でないものたち

- 辺に多重集合を認める場合、記法があいまいになっている
- 辺に多重集合を認めない場合、$(u,v),(v,u)\in E$ のときの逆辺の扱いがあいまいになっている
- フローの流量に最大値が存在する
- 残余ネットワークに増加路が存在しない $\implies$ フローの流量が最大

## 最大流問題の概要

最大流問題の概要は次のとおりです。

> ネットワーク (network) $(G,u,s,t)$ が与えられます。
> - 頂点集合 $V$, 辺集合 $E\subset V\times V$ (辺集合は一般に多重集合)
> - 有向グラフ $G=(V,E)$ 
> - 容量 (capacity) $u:E\to \mathbb{R}_{\ge 0}$
> - 始点 (source) $s\in V$, 終点 (sink) $t\in V\ (s\neq t)$
> 
> $s-t$ フロー $f$ の流量 (value) $|f|$ の最大値を求めてください。
> - $s-t$ フロー $f:E\to \mathbb{R}$
>   - $\forall e\in E, 0\le f(e)\le u(e)$
>   - $\displaystyle\forall v\in V\setminus \lbrace s,t \rbrace , \sum_{e=(v,\ast)}f(e) - \sum_{e=(\ast,v)} f(e) = 0$
> - 流量 $\displaystyle |f|=\sum_{e=(s,\ast)}f(e) - \sum_{e=(\ast,s)} f(e)$

## 残余ネットワーク (residual network)

重要な概念のひとつに **残余ネットワーク** (残余グラフと呼ばれることもあります) というものがあります。ネットワーク $(G,u,s,t)$ とその上のフロー $f$ に対して残余ネットワーク $G_f$ は次のように定められます。

- 辺 $e = (u,v)$ の逆辺 $\overleftarrow{e} = (v,u)$
- 辺と逆辺の集合 $\overleftrightarrow{E}=\lbrace e,\overleftarrow{e} \mid e\in E \rbrace$
- 逆辺を張ったグラフ $\overleftrightarrow{G}=(V,\overleftrightarrow{E})$
- 残余ネットワーク $G_f=(\overleftrightarrow{G},u_f,s,t)$ 
- 容量 $u_f:\overleftrightarrow{E}\to \mathbb{R}_{\ge 0}$
    - $\forall e\in E,\ u_f(e)=u(e)-f(e)$
    - $\forall e\in E,\ u_f(\overleftarrow{e})=f(e)$

> 容量 $0$ の辺は $G_f$ から取り除くという定義もあります。特にアルゴリズムの計算量解析パートでは容量 $0$ の辺を取り除く方の定義を採用します。

### 増加路 (augmenting path)

残余ネットワーク $G_f$ の **増加路** の定義は以下で与えられます。
- $G_f$ の容量正の辺からなる $s-t$ パス

このパスに含まれる辺の容量の最小値を $\delta$ とすれば, 増加路に従ってフローを流すことで流量を $\delta$ だけ増やすことができます。増加路の存在と残余ネットワークを与えるフローの流量が最大でないことは同値です。（証明は後で書きます。hosさんのスライドは厳密な証明が行われているので参考にすると良いです。）

また、フローの流量に最大値が存在することは自明ではないです（これは主観）が、頑張ると示せます。ただし難しいです。ちゃんと理解できたら書きます。とりあえず先へ進みます。
