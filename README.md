# SSA pr3

## Завдання 1

### Текст завдання
Запустіть Docker-контейнер і поекспериментуйте з максимальним лімітом ресурсів відкритих файлів. Для цього виконайте команди у вказаному порядку:

>$ ulimit -n
>
>$ ulimit -aS | grep "open files"
>
>$ ulimit -aH | grep "open files"
>
>$ ulimit -n 3000
>
>$ ulimit -aS | grep "open files"
>
>$ ulimit -aH | grep "open files"
>
>$ ulimit -n 3001
>
>$ ulimit -n 2000
>
>$ ulimit -n
>
>$ ulimit -aS | grep "open files"
>
>$ ulimit -aH | grep "open files"
>
>$ ulimit -n 3000

Як наступне вправу, повторіть перераховані команди з root-правами.

____
### *Реалізація*
[Правильне встановлення докеру](https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository)

[Налаштування докеру](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04)

>$ docker run -it --name limit-test --ulimit nofile=3000:3000 ubuntu bash
>
>Unable to find image 'ubuntu:latest' locally
>
>latest: Pulling from library/ubuntu
>
>2726e237d1a3: Pull complete
>
>Digest: sha256:1e622c5f073b4f6bfad6632f2616c7f59ef256e96fe78bf6a595d1dc4376ac02
>
>Status: Downloaded newer image for ubuntu:latest
>
>\# ulimit -n
>
>3000
>
>\# ulimit -aS | grep "open files"
>
>open files                          (-n) 3000
>
>\# ulimit -aH | grep "open files"
>
>open files                          (-n) 3000
>
>\# ulimit -n 3000
>
>\# ulimit -aS | grep "open files"
>
>open files                          (-n) 3000
>
>\# ulimit -aH | grep "open files"
>
>open files                          (-n) 3000
>
>\# ulimit -n 3001
>
>bash: ulimit: open files: cannot modify limit: Operation not permitted
>
>\# ulimit -n 2000
>
>\# ulimit -n
>
>2000
>
>\# ulimit -aS | grep "open files"
>
>open files                          (-n) 2000
>
>\# ulimit -aH | grep "open files"
>
>open files                          (-n) 2000
>
>\# ulimit -n 3000
>
>bash: ulimit: open files: cannot modify limit: Operation not permitted
>
>\# exit
____
### *Пояснення*
Ми перевіряємо та змінюємо ліміти відкритих файлів для процесів у контейнері за допомогою команди ulimit. Це дозволяє визначити, скільки файлів або сокетів може бути відкрито одночасно.Ми змінюємо значення цих лімітів, щоб зрозуміти, як вони впливають на стабільність системи та роботу процесів.

## Завдання 2

### Текст завдання

У Docker-контейнері встановіть утиліту perf(1). Поекспериментуйте з досягненням процесом встановленого ліміту.
____
### *Реалізація*


____
### *Пояснення*
____

## Завдання 3

### Текст завдання
Напишіть програму, що імітує кидання шестигранного кубика. Імітуйте кидки, результати записуйте у файл, для якого попередньо встановлено обмеження на його максимальний розмір (max file size). Коректно обробіть ситуацію перевищення ліміту.

____
### *Реалізація*

____
## Завдання 4

### Текст завдання
Напишіть програму, що імітує лотерею, вибираючи 7 різних цілих чисел у діапазоні від 1 до 49 і ще 6 з 36. Встановіть обмеження на час ЦП (max CPU time) і генеруйте результати вибору чисел (7 із 49, 6 із 36). Обробіть ситуацію, коли ліміт ресурсу вичерпано.
____
### *Реалізація*

____

## Завдання 5

### Текст завдання
Напишіть програму для копіювання одного іменованого файлу в інший. Імена файлів передаються у вигляді аргументів.
Програма має:
- перевіряти, чи передано два аргументи, інакше виводити "Program need two arguments";
- перевіряти доступність першого файлу для читання, інакше виводити "Cannot open file .... for reading";
- перевіряти доступність другого файлу для запису, інакше виводити "Cannot open file .... for writing";
- обробляти ситуацію перевищення обмеження на розмір файлу.

____
### *Реалізація*


## Завдання 6

### Текст завдання
Напишіть програму, що демонструє використання обмеження (max stack segment size). Підказка: рекурсивна програма активно використовує стек.

____
### *Реалізація*

## Завдання по варіантах (9)

### Текст завдання
Використати ulimit -d для обмеження динамічної пам’яті процесу.
____
### *Реалізація*


