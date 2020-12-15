# unit-test-sample

C言語単体テストフレームワーク(Unity)および gcc/gcov を利用して，組込みプログラムの単体テストおよびカバレッジ計測を実行するためのサンプル．

## Unity
### URL
https://www.throwtheswitch.org/unity

### Unity
https://github.com/ThrowTheSwitch/Unity.git

### CMock
https://github.com/ThrowTheSwitch/CMock.git

## gcov
以下の記事が参考になります．

https://mcuoneclipse.com/2014/12/26/code-coverage-for-embedded-target-with-eclipse-gcc-and-gcov/


##ビルド方法
example/test_1/build 直下で，make を実行．

##実行方法
athrill-run を実行．
※v850e2m 版の athrill がインストールされていることが前提．

##その他メモ

### gcov実行時の注意点
* 計測開始前に，.ctors セクションの初期化関数を実行する
* 計測終了時に，gcov_exit() を呼び出す(gcc のバージョンで異なる可能性がないか？)
* gcov_exit()でファイルI/O発生するので，athrillのシステムコールで対応する必要あり
  ※参考：ETロボコン向けのライブラリを流用することで動作確認した．
  ※https://github.com/tmori/unit-test-sample/blob/master/example/test_1/athrill-libgcc.c
  ※なお，リンク順番を間違えると，libcのシステムコールが利用されてしまうため要注意．
* libgcov.a を準備する必要あり(gcc/Makefile の inhibit_libc を falseにする)
