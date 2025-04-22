# SSA pr3

## Завдання 1

### Текст завдання

____
### *Реалізація v1*
```

```


>$ gcc task1_time.c -o t1

>$ ./t1
____
### *Пояснення*
При виконанні екзешнику можемо очікувати задовго(час залежить від системи). 
Для 32-бітної системи time_t має максимум 2147483647 (2^31 - 1 секунд).І при виконанні великого числа ітерацій за секунду, програма може виконатись достатньо швидко. 
Для 64-бітної системи time_t може зберігати значення до 2^63 1 секунд (≈292 мільярди років). Тому можна піти іншим шляхом - взяти максимальні значення лонгів.


## Завдання 2

### Текст завдання

____
### *Реалізація pt1*
```
#include <stdio.h>
//v1
int main(){
  printf ("Hello world\n");
  return 0;
}
```


>$ gcc task2_segments.c -o t2

>$ ./t2
>Hello world

>$ size t2
>
>text data bss dec hex   filename
>
>1077 552  16 1645 0x66d  t2

____
### *Пояснення*
Базова програма виконується коректно.
____
### *Реалізація pt2*
```
//v2
int arr arr[1000];
int main()f
  printf ("hello world\n");
  return 0:
}
```


>$ gcc task2_segments.c -o t2

>$ ./t2
>Hello world

>$ size t2
>
>text data  bss   dec    hex    filename
>
>1077 552   4032  5661  0x161d    t2
____
### *Пояснення*
Бачимо, що секція .bss збільшилась, оскільки array є неініціалізованою глобальною змінною.
____
### *Реалізація pt3*
```
//v3
int arr [1000] = (5};
int main(){
  printf ("hello world\n");
  return 0;
}
```


>$ gcc task2_segments.c -o t2

>$ ./t2
>Hello world

>$ size t2
>
>text data  bss   dec    hex    filename
>
>1077 4568  16   5661   Ox161d    t2

____
### *Пояснення*
Секція .bss зменшилась, а .data збільшилась, оскільки масив тепер має початкове значення.
____

### *Реалізація pt4*
```
//v4
void local_arr_function(){
      int arr[1000];
     static int s_arr [1000] = {9};
}
int main(){
    printf ("hello world\n");
    local_arr_function();
    return 0:
}
```


>$ gcc task2_segments.c -o t2

>$ ./t2
>
>Hello world

>$ size t2
>
>text data  bss   dec    hex    filename
>
>1141 4568  16   5725  0x165d    t2

>$ gcc -g task2_segments.c -o t2
>
>$ ls -l t2
>
>-rwxr-xr-x 1 mashapresident mashapresident 13176 Apr 20 11:36 t2
>
>$ size t2
>
>text data  bss   dec    hex    filename
>
>1141 4568  16   5725  0x165d    t2

>$ gcc -03 task2_segments.c -o t2
>
>$ ls -l t2
>
>-rwxr-xr-x 1 mashapresident mashapresident 8280 Apr 20 11:41 t2
>
>$ size t2
>
>text  data  bss   dec    hex    filename
>
>1116  552   16   1684   0x694    t2

____
### *Пояснення*
arr1 буде у стеку, отже, його розмір не вплине на розмір виконуваного файлу. arr2 (оскільки він static) потрапить у .data, змінюючи його розмір.
	При спробі налагодити при компіляції за допомогою аргумента -g  - бачимо, що нічого не змінилось.Але при максимальній оптимізації (аргумент -О3) результат вже помітний - розмір файлу зменшився за рахунок агресивної оптимізації.

____

## Завдання 3

### Текст завдання
Скомпілюйте й запустіть тестову програму, щоб визначити приблизне розташування стека у вашій системі:

```
#include <stdio.h>
int main() {
  int i;
  printf("The stack top is near pin", &i);
  return 0;
}
```
____
### *Реалізація*
```
#include <stdio.h>
#include <stdlib.h>
int data = 0;
int bss; 
void increase_stack_top();
void text(){}

int main(){
    int local;
    int i; // var for stacks top tracking
    char *heap = (char *)malloc (10);
    if (!heap){
        return 1;
    }
    printf ("local →> %p\n", (void *)&local); 
    printf ("text -> %p\n",(void *)&text);
    printf ("data -> %p",  (void *)&data);
    printf ("bss -> %p\n", (void *)&bss);
    printf ("mallocs memory address -> %p\n", (void *)heap);
    printf ("stack top address -> %p\n", &i); 
    increase_stack_top();
    free (heap);
    return 0;
}
void increase_stack_top(){
    int arr [1000];
    printf ("stack top after increasing -> %p\n",&arr );
}
```


>$ gcc task3_stack.c -o t3

>$ ./t3
>local -> 0x8209468e4
>
>text -> 0x400612
>
>data -> 0x401ae4
>
>bss -> 0x401ae8
>
>mallocs memory address -> 0x2c35ee09000
>
>stack top address -> 0x82094680
>
>stack ton after increasind -› 0x820945930

## Завдання 4

### Текст завдання
Ваше завдання – дослідити стек процесу або пригадати, як це робиться. Ви
можете:
- Автоматично за допомогою утиліти gstack.
- Вручну за допомогою налагоджувача GDB.
  
Користувачі Ubuntu можуть зіткнутися з проблемою: на момент написання
(Ubuntu 18.04) gstack, схоже, не був доступний (альтернативою може бути
pstack). Якщо gstack не працює, використовуйте другий метод – через
GDB, як показано нижче.
Спочатку подивіться на стек за допомогою gstack(1). Нижче наведений
приклад стека bash (аргументом команди є PID процесу):
$ gstack 14654

#0 0x00007f359ec7ee7a in waitpid () from /lib64/libc.so.6

#1 0x000056474b4b41d9 in waitchild.isra ()

#2 0x000056474b4b595d in wait_for ()

#3 0x000056474b4a5033 in execute_command_internal ()

#4 0x000056474b4a5c22 in execute_command ()

#5 0x000056474b48f252 in reader_loop ()

#6 0x000056474b48dd32 in main ()


Розбір стека:
- Номер кадру стека відображається ліворуч перед символом #.
- Кадр #0 – це найнижчий кадр. Читайте стек знизу вверх (тобто від
main() – кадр #6 – до waitpid() – кадр #0).
- Якщо процес багатопотоковий, gstack покаже стек кожного потоку
окремо.
Аналіз стека в режимі користувача через GDB

Щоб переглянути стек процесу вручну, використовуйте GDB,
приєднавшись до процесу.
Нижче наведена невелика тестова програма на C, що виконує кілька
вкладених викликів функцій. Граф викликів виглядає так:

main() -> foo() -> bar() -> bar_is_now_closed() -> pause()

Системний виклик pause() – це приклад блокуючого виклику. Він
переводить викликаючий процес у сплячий режим, очікуючи (або
блокуючи) сигнал. У цьому випадку процес блокується, поки не отримає
будь-який сигнал.
____
### *Реалізація*
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MSG "In function %20s; &amp;localvar = %p\n"
static void bar_is_now_closed(void) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    printf("\n Now blocking on pause()...\n");
    pause();
}
static void bar(void) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    bar_is_now_closed();
}
static void foo(void) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    bar();
}
int main(int argc, char **argv) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    foo();
    exit(EXIT_SUCCESS);
}
}
```


>$ gcc task1_time.c -o t1

>$ ./t1

____
### *Реалізація v2*
```
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdint.h>
int main(){
    time_t t_max = (time_t)LONG_MAX;
    printf ("max val of time_t -> %ld \n", (long)t_max); 
    printf ("time_t size -> %lu bytes \n", sizeof (time_t)); 
    printf ("system bit rate -> bit \n", sizeof (void *)*8);
    return 0;
}
```


> $ gcc task4_gdb_testing.c -o t4

> $ ./t4

У іншому терміналі вводимо команду для відслідковування PID
>$ pgrep t4
>1605

1605 - PID, за яким ми відслідкуємо процес через gdb

> (gdb) bt
> #0 0х000000082228777а in _sigsuspend () from /lib/libc.so.7
> #1 0x00000008221f dc35 in pause () from /lib/libc.so.7
> #2 0x0000000000400686 in bar_is_now_closed ()
> #3 0x00000000004006bd in bar ()
> #4 0x00000000004006ef in foo ()
> #5 0х0000000000400728 in main ()
____

## Завдання 5

### Текст завдання
Дослідіть використання сегмента BSS для збереження великих
масивів.
____
### *Реалізація*
```
#include <stdio.h>
int large_array[1000000]; 

int main() {
    printf(".bss segment -> %lu bytes\n", sizeof(large_array));
    return 0;
}

```
> $ gcc task5_bss.c -o t5

> $ ./t5
>
>.bss segment -> 4000000 bytes

>$ size t5
>
>text  data     bss       dec        hex     filename
>
>1106  552   4000032   4001690   0x3d0f9a    t5

____
### *Пояснення*
Сегмент .bss у пам'яті зберігає неініціалізовані глобальні та статичні змінні. Він виділяє пам’ять, але не задає початкові значення. Це дозволяє ефективно зберігати великі масиви без додаткового навантаження на виконуваний файл.

У команді size буде видно, що розмір .bss збільшується відповідно до розміру large_array, але він не займає простір у сегменті .data, оскільки масив не ініціалізований.


