# Colorlog

<img src='image.png' width='33%'>


## Building

```shell
rm -rf build
cmake -S . -B build
cmake --build build
cat $FILE | ./build/colorlog
```

## Developing

```shell
tput reset && cmake --build build && cat test.log | ./build/colorlog
```
