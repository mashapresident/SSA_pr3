
### Встановлення Docker
```
sudo apt update
sudo apt install -y docker.io
sudo systemctl enable docker
sudo systemctl start docker
sudo usermod -aG docker masha
sudo reboot -h now
```


Створюємо [Dockerfile](Dockerfile)

![-](docker_build.jpeg)

## Завдання 1 

![-](ulimit_test.jpeg)

Для запуску контейнера з-під рута, додаємо параметр --privileged

```docker run --rm -it --privileged ssa_pr3```

## Завдання 2

![-](perf_stat.jpeg)

[infinity.c](infinity.c)

```gcc -Wall infinity.c -o inf```

![-](inf_perf_stat.jpeg)

## Завдання 3
```ulimit -f 1  # ліміт 1 блок = 512 байт```

```gcc -Wall dice.c -o dice```

![-](dice_result.jpeg)

Вміст dice.log

![-](log.png)

## Завдання 4
```ulimit -t 1 # max CPU time```

```gcc -Wall lotery.c -o lotery```

![-](lotery_result.jpeg)

## Завдання 5

```echo "Test" > source.txt```

![-](echo_test.jpeg)

![-](echo_result.jpeg)

```gcc -Wall -o copy copy.c```

```./copy source.txt test_dest.txt```

![-](copy_result.jpeg)

## Завдання 6
```ulimit -s 64 # stack size```

```gcc -Wall -o stack stack.c```

Результат без лімітів

![-](stack_no_limit.jpeg)

Результат з лімітом

![-](copy_limited.jpeg)

## Завдання 7
```ulimit -u 10 ```

```gcc -Wall process.c -o pr```

![-](process_result.jpeg)
