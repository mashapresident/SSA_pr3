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

```
sudo apt update
sudo apt install -y docker.io
sudo systemctl enable docker
sudo systemctl start docker
sudo usermod -aG docker masha
```

![non_privileged mode](jpeg/non_priv.jpeg)

Додамо параметр *--privileged* при запуску контейнера

![privileged mode](jpeg/privileged.jpeg)

____
### *Пояснення*
--privileged дало контейнеру більше привілеїв, як, наприклад, змінювати системні налаштування, включаючи ulimit. Тобто, ми можемо у реальному часі змінювати налаштування контейнеру.

## Завдання 2

### Текст завдання

У Docker-контейнері встановіть утиліту perf(1). Поекспериментуйте з досягненням процесом встановленого ліміту.
____
### *Реалізація*
для встановлення необхідних пакетів, маємо дізнатись версію ядра операційної системи
```
uname -r
apt update 
apt install linux-tools-$(uname -r)
```
![perf_record](jpeg/perf_record.jpeg)

*perf record* починає запис виконання подій для подальшого аналізу. *-e syscalls:sys_enter_openat* вказує, що потрібно відстежувати системний виклик openat, який використовується процесами для відкриття файлів. *-a* означає, що запис буде вестися для всіх процесів в системі (не лише для одного конкретного). *sleep 120* — просто дає можливість системі працювати протягом 120 секунд, щоб зібрати дані про виклики openat.
для

![perf_report](jpeg/perf_report.jpeg)

*perf report* допоможе зрозуміти, які процеси активно відкривають файли і як використовується файловий ввід-вивід.
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


