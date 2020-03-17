# stl2sdf

## 概要

ASCIIのSTLを[符号付き距離関数](https://en.wikipedia.org/wiki/Signed_distance_function)（Signed Distance Function : SDF）に変換します。

STLからSDFへの変換には[basilisk](http://basilisk.fr/)を使用しています。

## インストール

basiliskのインストールは以下から。

- [Basilisk - src/INSTALL](http://basilisk.fr/src/INSTALL)

PATHを通しておくと便利です。

```
cd <install_dir>/stl2sdf
echo "export STL2SDF=$PWD" >> ~/.bashrc
echo "export PATH=\$PATH:$STL2SDF" >> ~/.bashrc
```

## 実行

```
stl2sdf <stlfile_path> <output_dir> <grid_size>
```

| option       | 説明                           |
| ------------ | ------------------------------ |
| stlfile_path | STLファイルのパス              |
| output_dir   | 出力先ディレクトリ（自動生成） |
| grid_size    | 符号付き距離関数の空間分割数   |

output_dirに元のSTLファイル名から.stlを引いたもの+_sdf.csvが出力されます。

csvファイルの中身はx,y,z座標と各座標における符号付き距離関数です。オブジェクト内は負値、外は正値になります。