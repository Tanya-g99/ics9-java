---
предмет: Языки и методы программирования
название: Разработка простейшего класса на языке Java
номер: 2
тип_работы: Лабораторная работа
группа: ИУ9-22Б
автор: Гнатенко Т. А.
преподаватель: Посевин Д. П.
---

# Цели

Целью данной работы является изучение базовых возможностей
языка Java.

# Задачи

Класс арифметических прогрессий с операциями определения
принадлежности числа прогрессии и вычисления суммы n первых
членов прогрессии.

# Решение

## Исходный код

`Test.java`

```java
public class Test {
    public static void main(String[] args) {
        Series A = new Series(3, 2);
        System.out.println(A.toString());
        A.belongNumber(7);
        A.belongNumber(10);
        System.out.println("Сумма: "+A.sum(20));

        Series B = new Series(32, -15);
        System.out.println(B.toString());
        B.belongNumber(-28);
        B.belongNumber(4);
        System.out.println("Сумма: "+B.sum(9));
        }
}

```

`Series.java`

```java
public class Series {
    private double a1, d;

    public Series(double varA1, double varD){
        this.a1 = varA1;
        this.d = varD;
    }

    public void belongNumber(double c){
        if ((c - this.a1)%this.d == 0) 
            System.out.println("Число " + c + " является членом этой арифметической прогрессии");
        else System.out.println("Число " + c + " не является членом этой арифметической прогрессии");
    }

    public double sum(int n){
        return ((this.a1 * 2 + this.d * (n - 1))/2)*n;
    }

    public String toString(){
        return "Арифметическая прогрессия с a1 = " + this.a1 + " и d = "+this.d;
    }
}

```

## Пример вывода
![Вывод](pics/Series_out.png)
